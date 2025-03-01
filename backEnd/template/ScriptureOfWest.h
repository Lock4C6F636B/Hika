#pragma once
#include <string>
#include <vector>
#include <iostream>

class ScriptureOfWest{
protected:
    mutable std::vector <std::string> buddha_sutras;

public:

    virtual void inscribe() const noexcept = 0;

    virtual inline std::string to_string(const size_t difficulty) const noexcept{
        std::cout<<"entering to string"<<std::endl;
        std::string string_sutras;

        // Check if vector is empty first
        if(buddha_sutras.empty()) {
            return string_sutras;
        }

        if(difficulty < 4) {
            // Japanese style - no spaces
            for(const auto& word : buddha_sutras) {
                string_sutras += word;
            }
        } else {
            // English style - with spaces between words except last
            for(size_t i = 0; i < buddha_sutras.size(); ++i) {
                if(i > 0) {  // Add space before each word except the first
                    string_sutras += " ";
                }
                string_sutras += buddha_sutras[i];
            }
        }

        return string_sutras;
    }

    virtual inline std::string pick(size_t index){
        return buddha_sutras[index];
    }

    virtual inline void push_back(std::string_view word) { // Push to back (vector's push_back)
        buddha_sutras.push_back(std::string(word));
    }

    virtual inline void insert(size_t index, std::string_view word) { // Insert at specific index
        buddha_sutras.insert(buddha_sutras.begin() + index, std::string(word));
    }

   virtual inline void replace(size_t index, std::string_view word) { // Using [] - no bounds checking, faster
        buddha_sutras[index] = std::string(word);
    }

    virtual inline void replace_safe(size_t index, std::string_view word) { // Using at() - with bounds checking, safer
        buddha_sutras.at(index) = std::string(word);
    }

    // Add other necessary methods
    virtual inline bool empty() const noexcept {
        return buddha_sutras.empty();
    }

    virtual inline void clear() noexcept {
        buddha_sutras.clear();
    }

    virtual inline void prepare_sutra() noexcept {
        buddha_sutras.clear();
        buddha_sutras.push_back("");
    }

    virtual inline void inscribe_sutra(const std::string& str) noexcept {
        for(auto& sutra : buddha_sutras) {
            sutra += str;
        }
    }

    virtual inline size_t size() const noexcept {
        return buddha_sutras.size();
    }

    ScriptureOfWest() = default;
    virtual ~ScriptureOfWest() = default;
};
