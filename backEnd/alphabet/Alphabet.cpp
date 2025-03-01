#include "Alphabet.h"

//initiate Alphabet and immediately read data into it
Alphabet::Alphabet(const std::string& filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.c_str()); //open xml file

	if (!result) { // handle file opening error
		return;
	}

	for (pugi::xml_node alpha : doc.child("Alphabet").children()) { //run through alphabet
		for (pugi::xml_node type : alpha.children()) { //run through types in alphabet
			alphabet.push_back(type.child_value()); //push individual items into vector
		}
	}
}

//read data into Alphabet
int Alphabet::read(const std::string& filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.c_str()); //open xml file

	if (!result) { //handle file opening error
		return 1;
	}

	alphabet.clear(); //clear alphabet

	for (pugi::xml_node alpha : doc.child("Alphabet").children()) { //run through alphabet
		for (pugi::xml_node type : alpha.children()) { //run through types in alphabet
			alphabet.push_back(type.child_value()); //push individual items into vector
		}
	}

	return 0;
}

//read only selected types into Alphabet
int Alphabet::read_selected(const std::string& filename, const std::vector<bool> &type) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.c_str()); //open xml file
	

	if (!result) { //handle file opening error
		return 1;
	}

	alphabet.clear(); //clear alphabet

	size_t itr = 0;
	for (pugi::xml_node alpha : doc.child("Alphabet").children()) { //run through alphabet
		//run through only selected types in alphabet
		if (type[itr] == true) {
			for (pugi::xml_node type : alpha.children()) {
				alphabet.push_back(type.child_value()); //push individual items into vector
			}
		}
		itr++;
	}

	return 0;
}

//print out
std::ostream& operator<<(std::ostream& output, const Alphabet alph){
	for (std::string item : alph.alphabet) { //run through vector of alphabet
		std::cout << item << ",";
	}

	return output;
};