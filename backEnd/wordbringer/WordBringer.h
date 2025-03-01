/*---------------------------------------------------------------------------------------------------------
	This is vocabulary controler for HiKa
-----------------------------------------------------------------------------------------------------------

	this is class that handles vocabulary practice.
	it randomly generates two numbers,one specifing type of vocabulary to be picked 
	(mixed, noun, adjectives, etc), other specifying index within type.
	Finally it compares it to word of same type and index
	as second vocabulary

	NOTE: inherting from library is set to private, so i can sort it to private/public explicitely
	not huge fan of protected layer
-----------------------------------------------------------------------------------------------------------

	difficulty 1 - from english to romanji
	difficulty 2 - from english to hiragana only japanese
	difficulty 3 - from english to full japanese

	difficulty 4 - from romanji only to english
	difficulty 5 - from hiragana only japanese to english
	difficulty 6 - from full japanese to english
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	start - generates data to pick word and prompts user with the word
	compare - compares user input with every meaning of word of same type and index in opposite vocabulary
	success - gives different messages based on multiple successes in row
//---------------------------------------------------------------------------------------------------------*/


#pragma once
#include "Library.h"
#include "Origin.h"


class WordBringer : private Origin<Data>{
private:
    //inherited succes_count
    //inherited Data data
    //inherited Library

public:
    WordBringer(std::shared_ptr<Library> library) : Origin(library) {};

	~WordBringer() = default;

    int start() override; //generate data to pick random word from vocabulary

    bool compare(const std::string answer) override; //compare the word with user answwer

    inline std::string harbinger() const noexcept override {
        return library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
    }

    std::string divine_truth() const noexcept override;

    using Origin::success_count;
    using Origin::updateLib;
};
