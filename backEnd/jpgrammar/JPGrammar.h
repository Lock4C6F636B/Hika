/*---------------------------------------------------------------------------------------------------------
	Japanese grammar for HiKa
-----------------------------------------------------------------------------------------------------------

	this is grammar namespace with functions to transform words by japanese rule.
	Handles grammar of individual word, not entire sentences

	NOTE:
	contains map for proper word bending...yes, thats expression i use
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	subjectify - adds koto to adjectives and verbs, making the sentence subject
	format_verb - handles bending of verbs
	format_adj - handles bending of adjectives

//---------------------------------------------------------------------------------------------------------*/


#pragma once
#include <iostream>
#include <array>
#include "TransformMap.h"


namespace jp_const {
	constexpr size_t CHAR_BYTE_SIZE = 3;  // Size of a Japanese character in UTF-8
}

namespace jpgrammar {
	// Maps for transformations of verbs
	constexpr TransformMap<std::string_view, std::string_view, 8> verbTransformMap = {
	   {"う", "い"},
	   {"く", "き"},
	   {"ぐ", "ぎ"},
	   {"す", "し"},
	   {"つ", "ち"},
	   {"ぬ", "に"},
	   {"む", "み"},
	   {"る", ""}
	};
	

	// Te form of verb transformation map
	constexpr TransformMap<std::string_view, std::string_view, 9> verb_teTransformMap = {
		{"う", "って"},
		{"く", "いて"},
		{"ぐ", "いで"},
		{"す", "して"},
		{"つ", "って"},
		{"ぬ", "んで"},
		{"む", "んで"},
		{"ぶ", "んで"},
		{"る", "て"}
	};


    //irregular verbs map
    constexpr TransformMap<std::string_view,std::string_view,6> irregular_verbsMap = {
        {"する", "しる"},
        {"くる", "きる"},
        {"いく", "いる"},
        {"suru", "shiru"},
        {"kuru", "kiru"},
        {"iku","iru"}
    };

	//function that format subject
	//------------------------------------------------------------------------------------------------------------------
	std::string subjectify(const std::string& word, const size_t& difficulty, const size_t& subject_type);

	std::string format_verb(std::string& verb, const size_t& difficulty, const size_t& format);

	std::string format_adj(std::string& adjective, const size_t& difficulty, const size_t& format);

	std::string desu(const std::string& word, const size_t& difficulty, const size_t& format);

}
