#include "ENGrammar.h"


std::string engrammar::subjectify(std::string& word) { //subjectify words into nouns, not be done
    return ing(word);
}

std::string engrammar::format_verb(std::string& verb, const size_t& format, const std::string& subject){
	if (verb.empty() || format > 5) { return "redacted"; } //if verb is empty, exit

	switch(format){
		case 0:
			if (subject != "I" && subject != "you" && subject != "we" && subject != "they") {
				return s(verb); //format for third person
            } else return verb;
		case 1:
            verb = dot(subject, format) + " " + verb; //do + verb
			return verb;
		case 2:
			verb = v_past(verb, 1);
			return verb;
		case 3: 
            verb = dot(subject, format) + " " + verb; //do + verb
			return verb;
		case 4:
            verb = "should " + verb;
			return verb;
		default:
			return "redacted";
	}
}

//transform verb into third person present tense
std::string engrammar::s(const std::string& verb) {
    if (auto exception = third_person_v->find_and_replace(verb, 1)) { //handles exceptions
		return std::string(*exception); // Convert string_view to string
	}

	// Check if the word ends with the current ending
    if (auto transformed = sTransformMap.find_replace_ending(verb)) {
        std::cout<<"found the ending"<<std::endl;
		return *transformed + "s";
	}

	return verb + "s"; //return for one syllable long
}

//transform verb into past simple
std::string engrammar::v_past(std::string& verb, const uint8_t &tense) {
    if (tense < 1 || tense > 2) {
		std::cerr << "wrong tense for past"<<std::endl;
		return "redacted";
	}
	
    if (auto exception = irregular_verbs->find_and_replace(verb, tense)) { //handles exceptions
        return std::string(*exception); // Convert string_view to string
	}

	if (doublepast(verb)) { //for cases vowel, consotant
		return verb + "ed";
	}

	// Check if the word ends with the current ending
    if (auto transformed = pastTransformMap.find_replace_ending(verb)) {
		return *transformed + "ed";
	}

	return verb + "ed"; //return for one syllable long
}


std::string engrammar::ly(std::string &adjective){
    if (auto exception = ly_adjectives->find_and_replace(adjective, 1)) { //handles exceptions
        return std::string(*exception); // Convert string_view to string
    }

    // Check if the word ends with the current ending
    if (auto transformed = lyTransformMap.find_replace_ending(adjective)) {
        return *transformed;
    }

    return adjective+"ly";
}

//transform word into ing form
std::string engrammar::ing(std::string& word) {
    if (auto exception = ing_verbs->find_and_replace(word, 1)) { //handles exceptions
		return std::string(*exception); // Convert string_view to string
	}

	// Check if the word ends with the current ending
    if (auto transformed = ingTransformMap.find_replace_ending(word)) {
		return *transformed + "ing";
	}

	//transform word, if one syllable long
	if (shorty(word)) {

		return word + "ing";
	}

	return word + "ing"; //return for one syllable long
};

//detect and transform one syllable word
bool engrammar::shorty(std::string& word) {
	uint8_t count = 0;

	//count vowels in word
	for (char letter : word) {
		for (char vowel : vowels) {
            if (letter == vowel) { //&& (is_prev_vow == true)
				count++; //is_prev_vow = true; //register as vowel for next loop
			}
		}
	}

	//check if last char is vowel
	for (char vowel : vowels) {
		if (vowel == word.back()) {
			return true;
		}
	}

	if (count <= 1) { //adjust for one syllable long word
		word = std::string(word) + word.back();
		return true;
	}
	else return false;
}

bool engrammar::doublepast(std::string &verb) {
    if(verb.size() < 3){ return false;}

    std::string lastChar = (std::string)verb.substr(verb.size() - 3); //store last two characters to determine bending of verb

	auto vowel_on_index = [&lastChar](size_t &&index) -> bool {
		for (char vowel : vowels) {
			if (vowel == lastChar[index]) {
				return true;
			}
		}
		return false;
	};

	
    bool consonant_l = vowel_on_index(0);
    bool vowel_m = vowel_on_index(1);
    bool consonant_r = vowel_on_index(3);

    if (!consonant_r && vowel_m && !consonant_l) {
		if (verb.back() != 'y' && verb.back() != 'w' && verb.back() != 'x') {
			verb += verb.back();
		}
		return true; //was modified
	}
	else return false; //wasnt modified

}

//return form of to be
const std::string engrammar::be(const std::string& subject, const size_t& format) {
	if (subject == "I") {
		switch (format) {
		case 0:
            return "am";
		case 1:
            return "am not";
		case 2:
            return "was";
		case 3:
            return "wasn't";
		case 4:
            return "should be";
		}
	}
	else if(subject == "you" || subject == "we" || subject == "they") {
		switch (format) {
		case 0:
            return "are";
		case 1:
            return "aren't";
		case 2:
            return "were";
		case 3:
            return "weren't";
		case 4:
            return "should be";
		}
	}
	else {
		switch (format) {
		case 0:
            return "is";
		case 1:
            return "isn't";
		case 2:
            return "was";
		case 3:
            return "wasn't";
		case 4:
            return "should be";
		}
	}
}

//return form of do and dont
const std::string engrammar::dot(const std::string& subject, const size_t& format) {
	switch (format) {
	case 0:
        return (subject == "I" || subject == "you" || subject == "we" || subject == "they") ? "do " : "does";
	case 1:
        return (subject == "I" || subject == "you" || subject == "we" || subject == "they") ? "don't　 " : "　doesn't";
	case 2:
        return "　did　";
	case 3:
        return "didn't";
	default:
		std::cerr << "not supported format"<<std::endl;
        return " redundant "; // Added default case
	}
}

//initialize specific exceptions
int engrammar::initialize(const std::string& filename, const unsigned short &exception_type) {
    switch (exception_type) { //load Exceptions by number
	case 0:
		if (irregular_verbs->load(filename) != 0) { //load irregular verbs for past tense
            std::cerr << "Failed to load irregular verbs exceptions" << std::endl;
			return 1;
        }
        break;
	case 1:
		if (third_person_v->load(filename) != 0) { //load irregular verbs for present tense third person
            std::cerr << "Failed to load third person exceptions" << std::endl;
			return 1;
        }
        break;
	case 2:
		if (ing_verbs->load(filename) != 0) { //load irregular verbs for past tense
            std::cerr << "Failed to load ing exceptions" << std::endl;
			return 1;
        }
        break;
    case 3:
        if (ly_adjectives->load(filename) != 0) { //load irregular verbs for past tense
            std::cerr << "Failed to load ly adjectives exceptions" << std::endl;
            return 1;
        }
        break;
	}

	return 0;
}

//initialize all the exceptions
int engrammar::initialize() {
    if (irregular_verbs->load(":/xml/grammar/engrammar/irregular_verbs.xml") != 0) { //load irregular verbs for past tense
        std::cerr << "Failed to load irregular verbs exceptions" << std::endl;
		return 1;
	}

    if (third_person_v->load(":/xml/grammar/engrammar/s.xml") != 0) { //load irregular verbs for present tense third person
        std::cerr << "Failed to load third person  exceptions" << std::endl;
		return 1;
	}

    if (ing_verbs->load(":/xml/grammar/engrammar/ing.xml") != 0) { //load irregular verbs for past tense
		std::cerr << "Failed to load ing exceptions" << std::endl;
		return 1;
	}

    if (ly_adjectives->load(":/xml/grammar/engrammar/ly.xml") != 0) { //load irregular verbs for past tense
        std::cerr << "Failed to load ly adjectives exceptions" << std::endl;
        return 1;
    }

	return 0;
}


bool engrammar::exceptions_empty(const unsigned short &specific_exceptions) noexcept {
    switch(specific_exceptions){
        case 0: return irregular_verbs->empty();
        case 1: return third_person_v->empty();
        case 2: return ing_verbs->empty();
        case 3: return ly_adjectives->empty();
    }
}


bool engrammar::exceptions_empty() noexcept {
    if(irregular_verbs->empty()){
        return true;
    }

    if(third_person_v->empty()){
        return true;
    }

    if(ing_verbs->empty()){
        return true;
    }

    if(ly_adjectives->empty()){
        return true;
    }

    return false;
}
