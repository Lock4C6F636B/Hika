#pragma once
#include <string>
#include <vector>
#include <iostream>

class ScriptureOfWest{
protected:
    mutable std::vector <std::string> buddha_sutras;

public:

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

    virtual inline void inscribe_sutra(const std::string& str) noexcept {
        for(auto& sutra : buddha_sutras) {
            sutra += str;
        }
    }

    ScriptureOfWest() = default;
    virtual ~ScriptureOfWest() = default;
};
