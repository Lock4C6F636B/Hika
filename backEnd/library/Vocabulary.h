/*---------------------------------------------------------------------------------------------------------
	This is vocabulary database holder for HiKa
-----------------------------------------------------------------------------------------------------------
	this is that that stores and oversees all vocabulary (vocab_1 & vocab_2)
	It reads from xml file (en_vocabulary.xml,ro_vocabulary.xml,jp_vocabulary.xml) into string vectors.
	From this this class both Sentencer and WordBringer inherits
	contains vocabulary as smart pointers, ensuring database has no copies

	NOTE: the xmls files must be identical, equally long and same item on same position.
	for example, can't happen that "Nihon" is going to be on same position as "sweet".
	"Nihon" must be on same position as "Japan"
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	read - reads everything from xml file into vectors.
	read_selected - reads only selected lessons from xml file into vectos
	pick - picks string of index in vector of type 
	(mixed - 0, noun - 1, adjective - 2, noun - 3, number - 4, verb - 5, adverb - 6, conjunctions - 8
//---------------------------------------------------------------------------------------------------------*/


#pragma once
#include <vector>
#include <iostream>
#include "pugixml.hpp"
#include <random>
#include <QBitArray>
#include <QFile>

class Vocabulary {
private:
	//vector for each type of vocabulary, will add verbs, numbers later
	std::vector<std::vector<std::string>> mixed;
	std::vector<std::vector<std::string>> noun;
	std::vector<std::vector<std::string>> adjective;
	std::vector<std::vector<std::string>> pronoun;
	std::vector<std::vector<std::string>> number;
	std::vector<std::vector<std::string>> verb;
	std::vector<std::vector<std::string>> adverb;
	std::vector<std::vector<std::string>> preposition;
	std::vector<std::vector<std::string>> conjunction;


public:

	Vocabulary() = default;

	Vocabulary(const std::string& filename);

	Vocabulary(const std::string& filename, const std::vector<bool>& lessons);

	~Vocabulary() = default;


	int read(const std::string& filename); //read into vectors from xml file (en_vocabulary.xml,ro_vocabulary.xml,jp_vocabulary.xml)
	int read_selected(const std::string& filename, const std::vector<bool>& lessons); //reads in vectors only selected sections


	std::string pick(const size_t& type, const size_t& index, const size_t& meaning) const; //picks one word from all vocabulary

	bool empty(const int &type) const noexcept; //check if selected type is empty

	bool empty() const noexcept; //check if all types are empty

	void clear() noexcept; //clear all vectors (all types)

	//helper functions--------------------------------------------------------------------------------------------------
	inline size_t mixed_size() const {return mixed.size();}

	inline size_t noun_size() const {return noun.size();}

	inline size_t adjective_size() const {return adjective.size();}

	inline size_t pronoun_size() const {return pronoun.size();}
	
	inline size_t number_size() const { return number.size(); }

	inline size_t verb_size() const { return verb.size(); }

	inline size_t adverb_size() const {return adverb.size();}

	inline size_t preposition_size() const { return preposition.size(); }

	inline size_t conjunction_size() const {return conjunction.size();}

	size_t mean_size(const size_t& type, const size_t& index) const; //get number of meanings for word in vector of type on index

	size_t type_size(const size_t& type) const; //get number of meanings for word in vector of type on index

	// print out functions
	void show_mixed() const;

	void show_noun() const;

	void show_adjective() const;

	void show_pronoun() const;

	void show_number() const;

	void show_verb() const;

	void show_adverb() const;

	void show_preposition() const;

	void show_conjunction() const;

	friend std::ostream& operator<<(std::ostream& output, const Vocabulary vocab);
};
