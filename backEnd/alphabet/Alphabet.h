/*---------------------------------------------------------------------------------------------------------
	This is alphabet for HiKa
-----------------------------------------------------------------------------------------------------------
	this is type for alphabet, that contains all hiragana and katakana,
	It reads from xml file (en_vocabulary.xml,hi_alphabet.xml,ka_alphabet.xml) into string vectors.

	NOTE: the xmls files must be identical, equally long and same item on same position.
	for example, can't happen that "me" is going to be on same position as "も"　or "ミ".
	"me" must be on same position as "め" and "メ"
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	read - reads everything from xml file into alphabet vector.
	read_selected - reads in only selected types, for example 
	if someone wants to practice only alphabet of m type (ma, mi, mu, me, mo)
	pick - picks letter on index
//---------------------------------------------------------------------------------------------------------*/

#pragma once
#include <vector>
#include <iostream>
#include "pugixml.hpp"

class Alphabet {
private:
	std::vector<std::string> alphabet;

public:

	Alphabet() = default;

	Alphabet(const std::string& filename);

	~Alphabet() = default;


	int read(const std::string& filename); //read into alphabet vector
	int read_selected(const std::string& filename, const std::vector<bool> &type); //read only selected into alphabet vector


	inline std::string pick(const size_t& index) const { return alphabet[index]; }; //randomly picks one word from all vocabulary

	inline bool empty() const noexcept{ return (alphabet.empty()?true:false); }//check if empty

	inline void clear() noexcept { alphabet.clear(); }

	//helper functions--------------------------------------------------------------------------------------------------
	inline size_t size() const { return alphabet.size(); }
	
	// print out function
	friend std::ostream& operator<<(std::ostream& output, const Alphabet alph);

};