#include "JPGrammar.h"

std::string jpgrammar::subjectify(const std::string& word, const size_t& difficulty, const size_t& subject_type){
	switch (subject_type) {
		case 2: {
			std::string lastChar = word.substr(word.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine if its い type

			//return word based on type i or na... and difficu
			if (lastChar == "い") {
				if (difficulty == 1 || difficulty == 4) {
					return word + " koto";
				}
				else return word + "こと";
			}
			else {
				if (difficulty == 1 || difficulty == 4) {
					return word + " na koto";
				}
				else return word + "なこと";
			}
		}
		case 5: {
			if (difficulty == 1 || difficulty == 4) {
				return word + " koto";
			}
			else return word + "こと";
		}
	}
}

std::string jpgrammar::format_verb(std::string& verb, const size_t& difficulty, const size_t& format) {
	if (verb.empty() || format > 5) { return "redudant"; } //if verb is empty, exit


    //check if verb is not derivation of irregular verb
    const size_t step = (difficulty == 1 || difficulty == 4 ? 1 : jp_const::CHAR_BYTE_SIZE); //need to set step indepentedly for romanji (ascii) and japanese unicode
    size_t i = verb.size() - step; //set end as starting position
    do {
        std::string verb_part = verb.substr(i); //temporary assign the part of verb
        if(auto transformed = irregular_verbsMap.find_replace(verb_part)) {
            verb = verb.substr(0,i) + std::string(*transformed);
            break;
        }
        i -= step;
    } while(i > 0);



	std::string lastChar = verb.substr(verb.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine bending of verb
	
	//handle case of te form
	if (format == 5) {
		if (auto transformed = verb_teTransformMap.find_replace(lastChar)) {
			verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
			return verb;
		}
		else {
			std::cerr << "Verb ending \"" << lastChar << "\" is not recognized. Likely an error." << std::endl;
			return "redundant";
		}
	}

	if (auto transformed = verbTransformMap.find_replace(lastChar)) {
		verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
	}
	else {
		std::cerr << "Verb ending \"" << lastChar << "\" is not recognized. Likely an error." << std::endl;
		return "redundant";
	}

	
	//add polite form, based on positivity or negativity of verb
    if (difficulty == 1 || difficulty == 4) { //difficutly is 1-6
		switch (format) { //format is 0-5
		case 0:
			verb += "masu";
			break;
		case 1:
			verb += "masen";
			break;
		case 2:
			verb += "mashita";
			break;
		case 3:
			verb += "masen deshita";
			break;
		case 4:
			verb += "mashou";
			break;
		}
	}
	else { //rely on fact that wrong difficutly cannot get thus far... if it did, then this entire program is wrong and this is least of issues
		switch (format) { //format is 0-5
		case 0:
			verb += "ます";
			break;
		case 1:
			verb += "ません";
			break;
		case 2:
			verb += "ました";
			break;
		case 3:
			verb += "ませんでした";
			break;
		case 4:
			verb += "ましょう";
			break;
		case 5:
			break;
		}
	}

	return verb;
}

std::string jpgrammar::format_adj(std::string& adjective, const size_t& difficulty, const size_t& format) {
	if (adjective.empty() || format > 4) { return "redudant"; } //if verb is empty, exit

	//skip all logic if format is present positive
	if (format == 0) {
		if (difficulty == 1) { return adjective + "desu"; }
		else return adjective + "です";
	}

	std::string lastChar = adjective.substr(adjective.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine if its い type

	//add sufix depending on adjective type (i or na)
    if (difficulty == 1 || difficulty == 4) {
		if (lastChar == "い") { //い type
			adjective = adjective.substr(0, adjective.size() - jp_const::CHAR_BYTE_SIZE); //separate last unicode char
			switch (format) {
			case 1: //present negative
				return adjective + "kunai desu";
			case 2: //past positive
				return adjective + "katta desu";
			case 3: //past negative
				return adjective + "kunakatta desu";
			case 4: //te form
				return adjective + "kute";
			}
		}
		else {
			switch (format) { //な type
			case 1: //present negative
				return adjective + "janai desu";
			case 2: //past positive
				return adjective + " deshita";
			case 3: //past negative
				return adjective + "janakatta desu";
			case 4: //te form
				return adjective + "de";
			}
		}
	}
	else { //rely on fact that wrong difficutly cannot get thus far... if it did, then this entire program is wrong and this is least of issues
		if (lastChar == "い") { //い type
			adjective = adjective.substr(0, adjective.size() - jp_const::CHAR_BYTE_SIZE); //separate last unicode char
			switch (format) {
			case 1: //present negative
				return adjective + "くないです";
			case 2: //past positive
				return adjective + "かったです";
			case 3: //past negative
				return adjective + "くなかったです";
			case 4: //te form
				return adjective + "くて";
			}
		}
		else {
			switch (format) { //な type
			case 1: //present negative
				return adjective + "じゃないです";
			case 2: //past positive
				return adjective + "でした";
			case 3: //past negative
				return adjective + "じゃなかったです";
			case 4: //te form
				return adjective + "で";
			}
		}
	}
}

std::string jpgrammar::desu(const std::string& word, const size_t& difficulty, const size_t& format) {
    if (difficulty == 1 || difficulty == 4) {
		switch (format) {
		case 0:
			return word + "desu";
		case 1:
			return word + "janai desu";
		case 2:
			return word + "deshita";
		case 3:
			return word + "janakatta desu";
		}
	}
    else {
		switch (format) {
		case 0:
			return word + "です";
		case 1:
			return word + "じゃないです";
		case 2:
			return word + "でした";
		case 3:
			return word + "じゃなかったです";
		}
	}
}
