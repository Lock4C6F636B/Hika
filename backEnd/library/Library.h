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
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	loads - loads word from xml file

//---------------------------------------------------------------------------------------------------------*/

#pragma once
#include "Vocabulary.h"
#include <memory>
//this class is manager for vocabularies
enum class vocabSelect{ first,second};

class Library {
	protected:
		std::shared_ptr<Vocabulary> vocab_1;
		std::shared_ptr<Vocabulary> vocab_2;
		int difficulty;

	public:
        Library() : vocab_1(std::make_shared<Vocabulary>()),  vocab_2(std::make_shared<Vocabulary>()) {}

		Library(const int& Difficulty);

		Library(const int& Difficulty, const std::vector<bool>& lessons);

		Library(const int& Difficulty, std::shared_ptr<Vocabulary> v1, std::shared_ptr<Vocabulary> v2);

		Library(const Library& lib);

		~Library() = default;

		int load(const int& Difficulty); //initiate privates with values, entire vocabulary is initiated

		int load(const int& Difficulty, const std::vector<bool>& lessons); //initiate privates with values, only selected vocabualary is initiated

		int load(const int& Difficulty, std::shared_ptr<Vocabulary> v1, std::shared_ptr<Vocabulary> v2);

		bool empty() const;

		void clear() const noexcept;


        //communicative functions
        //picks one word from all vocabulary
        inline std::string pick(const size_t& type, const size_t& index, const size_t& meaning, const vocabSelect select) const noexcept {
            switch(select){
                case vocabSelect::first:
                    return vocab_1->pick(type,index,meaning);
                case vocabSelect::second:
                    return vocab_2->pick(type,index,meaning);
                default:
                    return "wrong pick, fool!!!";
            }
        };

        //get mixed_size
        inline size_t mixed_size(const vocabSelect select) const noexcept{
            switch(select){
                case vocabSelect::first:
                    return vocab_1->mixed_size();
                case vocabSelect::second:
                    return vocab_2->mixed_size();
                default:
                    std::cerr<<"this vocabulary doesn't exist, no mixed_size, stupid!!!"<<std::endl;
                    return 1;
            }
        }

        //get noun_size
        inline size_t noun_size(const vocabSelect select) const noexcept{
            switch(select){
            case vocabSelect::first:
                return vocab_1->noun_size();
            case vocabSelect::second:
                return vocab_2->noun_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no noun_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get adjective_size
        inline size_t adjective_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->adjective_size();
            case vocabSelect::second:
                return vocab_2->adjective_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no adjective_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get pronoun_size
        inline size_t pronoun_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->pronoun_size();
            case vocabSelect::second:
                return vocab_2->pronoun_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no pronoun_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get number_size
        inline size_t number_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->number_size();
            case vocabSelect::second:
                return vocab_2->number_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no number_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get verb_size
        inline size_t verb_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->verb_size();
            case vocabSelect::second:
                return vocab_2->verb_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no verb_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get adverb_size
        inline size_t adverb_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->adverb_size();
            case vocabSelect::second:
                return vocab_2->adverb_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no adverb_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get preposition_size
        inline size_t preposition_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->preposition_size();
            case vocabSelect::second:
                return vocab_2->preposition_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no preposition_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get conjuction_size
        inline size_t conjunction_size(const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->conjunction_size();
            case vocabSelect::second:
                return vocab_2->conjunction_size();
            default:
                std::cerr<<"this vocabulary doesn't exist, no conjuction_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get mean_size
        inline size_t mean_size(const size_t& type, const size_t& index, const vocabSelect select) const noexcept {
            switch(select){
            case vocabSelect::first:
                return vocab_1->mean_size(type,index);
            case vocabSelect::second:
                return vocab_2->mean_size(type,index);
            default:
                std::cerr<<"this vocabulary doesn't exist, no mean_size, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //get any size of any type
        size_t type_size(const size_t& type, const vocabSelect select) const noexcept{
            switch(select){
            case vocabSelect::first:
                return vocab_1->type_size(type);
            case vocabSelect::second:
                return vocab_2->type_size(type);
            default:
                std::cerr<<"this vocabulary doesn't exist, no type_size, stupid!!!"<<std::endl;
                return 1;
            }
        }


        //check if type of vocabulary is empty
        bool empty(const int &type, const vocabSelect select) const noexcept{
            switch(select){
            case vocabSelect::first:
                return vocab_1->empty(type);
            case vocabSelect::second:
                return vocab_2->empty(type);
            default:
                std::cerr<<"this vocabulary doesn't exist, nothing is empty, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //check if entire library is empty
        bool empty(const vocabSelect select) const noexcept{
            switch(select){
            case vocabSelect::first:
                return vocab_1->empty();
            case vocabSelect::second:
                return vocab_2->empty();
            default:
                std::cerr<<"this vocabulary doesn't exist, nothing is empty, stupid!!!"<<std::endl;
                return 1;
            }
        }

        //getters
        inline std::shared_ptr<Vocabulary>& getVocab_1() noexcept { return vocab_1; }
        inline std::shared_ptr<Vocabulary>& getVocab_2() noexcept { return vocab_2; }
        inline int getDifficulty() const noexcept {return difficulty;}

        //setter for difficulty
        int setDifficulty(int Difficulty) noexcept;

		//helper function-------------------------------------------------------------------------------------
        inline void showVocab_1() const { std::cout <<"adress->"<<vocab_1<<" "<< *vocab_1; };

        inline void showVocab_2() const { std::cout<<"adress->"<<vocab_2<<" "<< *vocab_2; };


		//overloaded operators--------------------------------------------------------------------------------
		Library& operator=(const Library& lib);
};
