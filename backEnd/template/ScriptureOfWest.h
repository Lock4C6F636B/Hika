#pragma once
#include <string>
#include <vector>
#include <iostream>

class ScriptureOfWest{
protected:
    mutable std::vector <std::vector<std::string>> buddha_sutras;

public:
    ScriptureOfWest(){buddha_sutras.reserve(0);}

    virtual ~ScriptureOfWest() = default;

    virtual void inscribe() const noexcept = 0;

    virtual inline std::string string_sutra(const size_t difficulty) const noexcept{
        std::cout<<"entering to string"<<std::endl;
        std::string string_sutras;

        // Check if vector is empty first
        if(buddha_sutras.empty()) {
            return string_sutras;
        }

        if(difficulty < 4) {
            // Japanese style - no spaces
            for(const std::vector<std::string> &sentence : buddha_sutras){
                for(const std::string &word : sentence) {
                    string_sutras += word;
                }
                string_sutras += "<br>";
            }
        } else {
            // English style - with spaces between words except last
            for(size_t itr = 0; itr < buddha_sutras.size(); itr++){
                for(size_t i = 0; i < buddha_sutras[itr].size(); i++) {
                    if(i > 0) {  // Add space before each word except the first
                        string_sutras += " ";
                    }
                    string_sutras += buddha_sutras[itr][i];
                }
                string_sutras += "<br>";
            }
        }

        return string_sutras;
    }


    virtual inline std::string string_sutra(const size_t difficulty, const size_t &index) const noexcept{
        std::string string_sutras;

        // Check if vector is empty first
        if(buddha_sutras.empty() || (index >= buddha_sutras.size())) {
            return string_sutras;
        }

        if(difficulty < 4) {
            // Japanese style - no spaces
            for(const std::string &word : buddha_sutras[index]) {
                string_sutras += word;
            }
        } else {
            // English style - with spaces between words except last
            for(size_t i = 0; i < buddha_sutras[index].size(); i++) {
                if(i > 0) {  // Add space before each word except the first
                    string_sutras += " ";
                }
                string_sutras += buddha_sutras[index][i];
            }
        }

        return string_sutras;
    }
};
