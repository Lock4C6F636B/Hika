/*---------------------------------------------------------------------------------------------------------
	This is class that holds exception words.
	ordered [0] = infinite
			[i>0] = correct form for output
	Constructor specifically reserves 0 items for memory to ensure it would not take memory if not used.
	Employed in namespace, which will always initialized object at start of program,
	but Exceptions are practically only for Sentencer... therefore take as least of memory 
	when not running Sentencer
-----------------------------------------------------------------------------------------------------------
	It's basically vector of array, array designed around 2 or 3 items
	It reads from xml file into the vector verbs.
-----------------------------------------------------------------------------------------------------------*/


#pragma once
#include "pugixml.hpp"
#include <vector>
#include <array>
#include <optional>
#include <iostream>
#include <QFile>
#include <QString>


template<size_t N>
class Exceptions {
	private:
        std::vector<std::array<std::string, N>> words; //one verb per array slot, N forms
        bool is_initialized = false;
        std::string filename;  // Store filename for lazy initialization

	public:
		//so the class is never initialized with content
		//Exceptions();
        inline Exceptions() { words.reserve(0); }

        inline Exceptions(const std::string& filename){
            QFile file(QString::fromStdString(":/xml/exceptions/" + filename));
            if (!file.open(QIODevice::ReadOnly)) {
                std::cerr << "Failed to open file from resources: " << filename << std::endl;
            }

            QByteArray data = file.readAll();

            pugi::xml_document doc;
            pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

            if (!result) {
                std::cerr << "Failed to parse XML from buffer: " << filename << std::endl;
            }

            words.clear(); // Clear existing verbs, if any

            //parse irregular verbs into vector
            for (pugi::xml_node item : doc.child("Exceptions").children("item")) {
                std::array<std::string, N> verb_forms;
                size_t i = 0;
                for (pugi::xml_node form : item.children()) {
                    if (i < N) {
                        verb_forms[i++] = form.text().as_string();
                    }
                }
                words.push_back(verb_forms);
            }
        }


		//actually loads in irregular verbs
        int load(const std::string& filename) {
            QFile file(QString::fromStdString(filename));
            if (!file.open(QIODevice::ReadOnly)) {
                std::cerr <<filename<< ", open failed: " << file.errorString().toStdString() << std::endl;
                return 1;
            }

            QByteArray data = file.readAll();

            pugi::xml_document doc;
            pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

            if (!result) {
                std::cerr << "Failed to parse XML from buffer: " << filename << std::endl;
                return 1;
            }

            words.clear(); // Clear existing verbs, if any

			//parse irregular verbs into vector
			for (pugi::xml_node item : doc.child("Exceptions").children("item")) {
				std::array<std::string, N> verb_forms;
				size_t i = 0;
				for (pugi::xml_node form : item.children()) {
					if (i < N) {
						verb_forms[i++] = form.text().as_string();
					}
				}
                words.push_back(verb_forms);
			}

			return 0; // Success
		}
	
	
		//check if all types are empty
		inline bool empty() const {
            return words.empty();
		}
	
		//clear all the verbs
		inline void clear() noexcept {
            words.clear();
            words.reserve(0);
		}
	
        inline size_t size() const { return words.size(); }
	
        std::optional<std::string_view> find_and_replace(const std::string_view& word, const size_t& index) const {
            if (index > N) {//handle reaching out of bounds
				std::cerr << "subscript out of range"; return std::nullopt;
			}

            for (const auto& word_forms : words) { //search through first tense
                if (word_forms[0] == word) {
                    return word_forms[index]; //if found return desired tense of index
				}
			}
			return std::nullopt;
		}


        bool find(const std::string_view& word) const noexcept{
            for(const auto& word_forms : words) {  // word_forms is an array
                if(word == word_forms[0]) {  // Check first element of array
                    return true;
                }
            }
            return false;
        }


		// just to see if loaded properly
		friend std::ostream& operator<<(std::ostream& output, const Exceptions<N>& exceptions) {
            for (const auto& arr : exceptions.words) {
				for (size_t i = 0; i < N; i++) {
					output << arr[i] << "\t";
				}
				output << "\n";
			}
			return output;
		}
};


