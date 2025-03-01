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
#include "Exceptions.h"


namespace jp_const {
	constexpr size_t CHAR_BYTE_SIZE = 3;  // Size of a Japanese character in UTF-8
}

namespace jpgrammar {
    inline std::unique_ptr<Exceptions<1>> adj_except = std::make_unique<Exceptions<1>>();

	// Maps for transformations of verbs
    constexpr TransformMap<std::string_view, std::string_view, 8> formal_verbTransformMap = {
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

    constexpr TransformMap<std::string_view, std::string_view, 9> informal_verb_taTransformMap = {
        {"う", "った"},
        {"く", "いた"},
        {"ぐ", "いだ"},
        {"す", "した"},
        {"つ", "った"},
        {"ぬ", "んだ"},
        {"む", "んだ"},
        {"ぶ", "んだ"},
        {"る", "った"}
    };

    constexpr TransformMap<std::string_view, std::string_view, 8> informal_verb_naiTransformMap = {
        {"う", "わ"},
        {"く", "か"},
        {"ぐ", "が"},
        {"す", "さ"},
        {"つ", "た"},
        {"ぬ", "な"},
        {"む", "ま"},
        {"る", ""}
    };

    // For volitional form
    constexpr TransformMap<std::string_view, std::string_view, 9> informal_verb_volTransformMap = {
        {"う", "おう"},
        {"く", "こう"},
        {"ぐ", "ごう"},
        {"す", "そう"},
        {"つ", "とう"},
        {"ぬ", "のう"},
        {"む", "もう"},
        {"ぶ", "ぼう"},
        {"る", "ろう"}
    };


    //irregular verbs map
    constexpr TransformMap<std::string_view,std::string_view,6> irregular_verbsMap = {
        {"する", "しる"},
        {"くる", "きる"},
        {"いく", "いる"},
    };

    //functions that format subject
	//------------------------------------------------------------------------------------------------------------------
    std::string subjectify(const std::string& word, const size_t& subject_type);

    std::string format_verb(std::string& verb, const size_t& format, const bool &formal);

    std::string format_adj(std::string& adjective, const size_t& format, const bool &formal);

    std::string desu(const std::string& word, const size_t& format);

    std::string should_adj(std::string &adjective, const std::string &verb, const bool &formal) noexcept;


    //for exceptions, currently for only for adj_except, which affects only hiragana difficulty
    //------------------------------------------------------------------------------------------------------------------
    int initialize(); //will initialize and load all exception... larger

    bool exceptions_empty() noexcept;
}
