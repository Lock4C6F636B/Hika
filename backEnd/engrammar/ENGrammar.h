/*---------------------------------------------------------------------------------------------------------
	English grammar for HiKa
-----------------------------------------------------------------------------------------------------------

	this is grammar namespace with functions to transform words by english rule.
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
#include "TransformMap.h"
#include "Exceptions.h"
//#include "JPGrammar.h"
#include <memory>

namespace engrammar {
    inline std::unique_ptr<Exceptions<3>> irregular_verbs = std::make_unique<Exceptions<3>>();
    inline std::unique_ptr<Exceptions<2>> third_person_v = std::make_unique<Exceptions<2>>();
    inline std::unique_ptr<Exceptions<2>> ing_verbs = std::make_unique<Exceptions<2>>();

	constexpr TransformMap<std::string_view, std::string_view, 4> ingTransformMap = {
	{"ie", "y"},
	{"ee", "ee"},
	{"e", ""},
	{"c", "ck"}
	};

	constexpr TransformMap<std::string_view, std::string_view, 4> pastTransformMap = { //transformation map for past simple      
	{"e", ""},
	{"y", "i"},
	{"c", "ck"}
	};

    constexpr TransformMap<std::string_view, std::string_view, 9> sTransformMap = { //transformation map for ing form
    {"y", "ie"},
	{"o", "oe"},
	{"x", "xe"},
	{"s", "se"},
	{"z", "ze"},
    {"f", "ve"},
    {"fe", "ve"},
    {"ch", "che"},
    {"sh", "she"},
	};

	static constexpr std::array<const char, 5> vowels = { 'a','e','i','o','u'}; //list of vowels

	
	std::string subjectify(std::string& word);
	
    std::string format_verb(std::string& verb, const size_t& format, const std::string& subject);

	//transform verb into third person present tense
	std::string s(const std::string& verb);

	//transform verb into past simple
	std::string v_past(std::string& verb, const uint8_t& tense);

	//tranform word to ing form
	std::string ing(std::string& word);

	//detect and transform one syllable word
	bool shorty(std::string& word);

	bool doublepast(std::string& verb);

	//return form of to be
    const std::string be(const std::string& subject, const size_t& format);

	//return forms of do and dont
    const std::string dot(const std::string& subject, const size_t& format);

    int initialize(const std::string& filename, const unsigned short& exception_size); //will load only specific exception

	int initialize(); //will initialize and load all exception... larger

    bool exceptions_empty() noexcept;
}
