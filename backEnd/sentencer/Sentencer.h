/*---------------------------------------------------------------------------------------------------------
	This is sentence maker for HiKa
-----------------------------------------------------------------------------------------------------------

	this is class that handles sentence practice.
	it randomly generates data for sentence.
	then it constructs prompt sentence, favoring japanese rules,
	therefore not all englishtense are accounted for.
	It then constructs multiple sentences in oppossing language.
	For example one word in english might have multiple meanings in japanese and opposite.
	Therefore it's imperative to generate sentences including all meanings and
	then it compares user input with each of these sentences
	format in data determines tense and negativity of word... 
	for example format == 1 is present simple negative form (starting from 0)

	NOTE: 
	inherting from library is set to private, so i can sort it to private/public explicitely
	not huge fan of protected layer.
	Transforming words is job of grammar namespaces
-----------------------------------------------------------------------------------------------------------

	difficulty 1 - from english to romanji
	difficulty 2 - from english to hiragana only japanese
	difficulty 3 - from english to full japanese

	difficulty 4 - from romanji only to english
	difficulty 5 - from hiragana only japanese to english
	difficulty 6 - from full japanese to english


	data.format == 0 //present positive
	data.format == 1 //present negative
	data.format == 2 //past positive
	data.format == 3 //past negative
	data.format == 4 //present positive
	data.format == 5 //te form
-----------------------------------------------------------------------------------------------------------

	needs to be done: in overhaul, need to finish grammar namespaces first
-----------------------------------------------------------------------------------------------------------

	functions
	start - generates data into Data data and calls build_prompt by difficulty
	compare - compares user input with all sentences of opposite vocabulary generated in compar_sent
	calls build_sentence by difficulty
	JPbuild_prompt - builds prompt sentence in japanese
	JPbuild_sentence - builds sentences to compare with user input in japanese
	ENbuild_prompt - builds prompt sentence in english
	ENbuild_sentence - builds sentences to compare with user input english
	success - gives different messages based on multiple successes in row

-----------------------------------------------------------------------------------------------------------

    templates available
    0.x is y
    1.is x y?
    2.x is z's y
    3.is x z's y
//---------------------------------------------------------------------------------------------------------*/


#pragma once
#include "Origin.h"
#include "ScriptureOfWest.h"
#include "JPGrammar.h"
#include "ENGrammar.h"



class Sentencer: private Origin<SentencerData>,private ScriptureOfWest{
	private:
        //inherited succes_count
        //inherited SentencerData data
        //inherited sacred scripts
        //inherited Library

        static constexpr std::string particles[3] = { "は","が","も" };

	public:
        Sentencer(std::shared_ptr<Library> library) : Origin(library) {};

        ~Sentencer() = default;

        int start() override; //generate data to pick random word from vocabulary

        bool compare(const std::string answer) override; //compare the word with user answwer

        std::string harbinger() const noexcept override; //throw prompt to frontend

        inline void inscribe() const noexcept override; //make correct answer

		//build_prompt japanese
        std::string JPbuild_prompt_simple() const;
        std::string JPbuild_prompt_te_form() const;

        //build comparassion sentences in japanese
        int JPbuild_sentence_simple() const;
        int JPbuild_sentence_te_form() const;

		//build_prompt in english
        std::string ENbuild_prompt_simple() const;
        std::string ENbuild_prompt_te_form() const;
	
		//build comparassion sentences in english
        int ENbuild_sentence_simple() const;
        int ENbuild_sentence_te_form() const;


        using Origin::success_count;
        using Origin::updateLib;
        using Origin::getDifficulty;
        using ScriptureOfWest::string_sutra;


        //helper functions
        void jp_add_subject() const noexcept;
        void jp_add_specifier() const noexcept;
        void jp_add_object() const noexcept;
        void en_add_subject() const noexcept;
        void en_add_specifier(const bool is_question, const bool is_negative) const noexcept;
        void en_add_object(const bool using_specifier, const bool is_question, const bool is_negative) const noexcept;
};
