/*---------------------------------------------------------------------------------------------------------
	This is alphabet controler for HiKa
-----------------------------------------------------------------------------------------------------------

	this is class that handles alphabet practice. 
	it randomly generates number and picks one letter from alphabet_1.
	then it asks for input, which compares to same letter from alphabet_2

	NOTE: even though compared are only two at time, the third is important for 3th difficulty.
-----------------------------------------------------------------------------------------------------------
	
	difficulty 1 - for practicing writting hiragana alphabet
	difficulty 2 - for practicing writting katakana
	difficulty 3 - for practicing both hiragana and katakana.
	Class randomly switches between hiragana and katakana during practice
-----------------------------------------------------------------------------------------------------------

	needs to be done:
-----------------------------------------------------------------------------------------------------------

	functions
	load - initiates private variables

	compare - core function of class. does all of it, picking word, asking for input, comparing
	(i've thought it would be better to handle all at once instead of splitting into more function,
	because the function is supposed to be called pretty much always...
	so i dont want to clog stack with more and simpler function
	
	success - gives different messages based on multiple successes in row
//---------------------------------------------------------------------------------------------------------*/


#pragma once
#include "Alphabet.h"
#include <iostream>
#include <random>


class AlpGame {
private:
	Alphabet alph_1;
	Alphabet alph_2a; 
	Alphabet alph_2b;
	int difficulty; //determines difficulty
	size_t index; //unfortunately ALpGame is too different to use something more complex

	//track success
	int suc_count = 0;
	bool prev_suc = false; 
	

public:

	AlpGame() = default;

	AlpGame(const int &Difficulty);

	AlpGame(const int& Difficulty, const std::vector<bool>& type);

	int load(const int &Difficulty); //initiate privates with values

	int load(const int& Difficulty, const std::vector<bool>& type);

	int start(std::string& input); //start of program

	int compare(std::string &input, const std::string& letter); //compare

	void success() const; //print out success

	inline void clear() noexcept { alph_1.clear(),alph_2a.clear(),alph_2b.clear(); }

	inline bool empty() const noexcept { return (alph_1.empty() && alph_2a.empty() && alph_2b.empty()) ? true : false; }//check if empty

	//helper functions------------------------------------------------------------------------------------------
	inline void showAlp1() const { std::cout << alph_1; };
	inline void showAlp2a() const { std::cout << alph_2a; };
	inline void showAlp2b() const { std::cout << alph_2b; };
};