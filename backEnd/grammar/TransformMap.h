/*---------------------------------------------------------------------------------------------------------
	This is simple wrapper for array<std::pair<typename first, typename secon>,size_t N>
-----------------------------------------------------------------------------------------------------------
	It inherits everything from array and adds function to find first of pair and return second
-----------------------------------------------------------------------------------------------------------*/

#pragma once
#include <string>
#include <array>
#include <optional>
#include <algorithm>

template<typename First, typename Second, std::size_t N>
class TransformMap : std::array<std::pair<First, Second>, N> {
public:
	// Inherit constructors from std::array
	using std::array<std::pair<First, Second>, N>::array;

	// Default constructor
	constexpr TransformMap() = default;

	// Constructor from std::array
	constexpr TransformMap(const std::array<std::pair<First, Second>, N>& arr)
		: std::array<std::pair<First, Second>, N>(arr) {}

	// Initializer list constructor
    constexpr TransformMap(std::initializer_list<std::pair<First, Second>> init) {
        std::copy_n(init.begin(), std::min(init.size(), N), this->begin());
    }


	// Find first of pair and return second
	constexpr std::optional<Second> find_replace(const First& string) const {
		for (const auto& [first, second] : *this) {
			if (string == first) {
				return second;
			}
		}
		return std::nullopt;
	}

	std::optional<std::string> find_replace_ending(const std::string& word) const {
		for (const auto& [ending, replacement] : *this) {
			if (word.length() >= ending.length() && word.compare(word.length() - ending.length(), std::string::npos, ending) == 0) {
				return std::string(word.substr(0, word.length() - ending.length())) + std::string(replacement);
			}
		}
		return std::nullopt;
	}


    std::optional<std::string> find_replace_ending_with_size(const std::string& word) const {
        for (const auto& [ending, replacement] : *this) {
            if (word.length() >= ending.length() && word.compare(word.length() - ending.length(), std::string::npos, ending) == 0) {
                return std::string(replacement);
            }
        }
        return std::nullopt;
    }
};
