#include "JPGrammar.h"

std::string jpgrammar::subjectify(const std::string& word, const size_t& subject_type){
	switch (subject_type) {
		case 2: {
			std::string lastChar = word.substr(word.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine if its い type

			//return word based on type i or na... and difficu
			if (lastChar == "い") {
                return word + "こと";
			}
			else {
                return word + "なこと";
			}
		}
		case 5: {
            return word + "こと";
		}
	}
}

std::string jpgrammar::format_verb(std::string& verb, const size_t& format, const bool &formal) {
    if (verb.empty() || format > 5) { return "redudant"; } //if verb is empty, exit


    //check if verb is not derivation of irregular verb
    size_t i = verb.size() - jp_const::CHAR_BYTE_SIZE; //set end as starting position
    do {
        std::string verb_part = verb.substr(i); //temporary assign the part of verb
        if(auto transformed = irregular_verbsMap.find_replace(verb_part)) {
            verb = verb.substr(0,i) + std::string(*transformed);
            break;
        }
        i -= jp_const::CHAR_BYTE_SIZE; //step by one jp char
    } while(i > 0);


	std::string lastChar = verb.substr(verb.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine bending of verb
	

    if (format == 5){ //handle case of te form
        if (auto transformed = verb_teTransformMap.find_replace(lastChar)) {
            verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
        }else goto error_handling;
        return verb;
    }
    else if(!formal && format == 2){ //informal past positive
        if (auto transformed = informal_verb_taTransformMap.find_replace(lastChar)) {
            verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
        } else goto error_handling;
        return verb;
    }
    else if (!formal && (format == 1 || format == 3)){//informal present negative and past negative
        if (auto transformed = informal_verb_naiTransformMap.find_replace(lastChar)) {
            verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
        } else goto error_handling;

        switch(format){ //determine ending here, better not to mix with formal ending
            case 1:
                return verb + "ない";
            case 3:
                return verb + "なかった";
        }
    }
    else if (!formal && format == 4){ //informal should
        if (auto transformed = informal_verb_volTransformMap.find_replace(lastChar)) {
            verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
        } else goto error_handling;
        return verb;
    }
    else {
        if (auto transformed = formal_verbTransformMap.find_replace(lastChar)) {
            verb.replace(verb.length() - jp_const::CHAR_BYTE_SIZE, jp_const::CHAR_BYTE_SIZE, *transformed);
        }
        else goto error_handling;
    }
	
	//add polite form, based on positivity or negativity of verb
    //rely on fact that wrong difficutly cannot get thus far... if it did, then this entire program is wrong and this is least of issues
    if(formal){
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
    else {
        switch (format) { //format is 0-5

        case 1:
            verb += "ない";
            break;
        case 2:
            verb += "て";
            break;
        case 3:
            verb += "なかった";
            break;
        case 4:
            verb += "よう";
            break;
        case 5:
            break;
        }
    }

	return verb;

    error_handling:
        std::cerr << "Verb ending \"" << lastChar << "\" is not recognized. Likely an error." << std::endl;
        return "redundant";
}

std::string jpgrammar::format_adj(std::string& adjective, const size_t& format, const bool &formal) { //!!!!format 4 is handled by should_adj
    if (adjective.empty() || format > 5 || format == 4) { return "redudant, note 4 is not directly supported"; } //if verb is empty, exit

	//skip all logic if format is present positive
    if (format == 0) {
        return formal ? adjective + "です" : adjective;
    }

	std::string lastChar = adjective.substr(adjective.size() - jp_const::CHAR_BYTE_SIZE); //store last character to determine if its い type

    //add sufix depending on adjective type (i or na), if desu is used, return later
    if (lastChar == "い" && !adj_except->find(adjective)) { //い type
        adjective = adjective.substr(0, adjective.size() - jp_const::CHAR_BYTE_SIZE); //separate last unicode char
        switch (format) {
        case 1: // present negative
            return formal ? adjective + "くないです" : adjective + "くない";
        case 2: // past positive
            return formal ? adjective + "かったです" : adjective + "かった";
        case 3: // past negative
            return formal ? adjective + "くなかったです" : adjective + "くなかった";
        case 5: // te form
            return adjective + "く　て";
        default:
            return "redundant";
        }
    } else { // な type
        switch (format) {
        case 1: // present negative
            return formal ? adjective + "じゃないです" : adjective + "じゃない";
        case 2: // past positive
            return formal ? adjective + "でした" : adjective + "だった";
        case 3: // past negative
            return formal ? adjective + "じゃなかったです" : adjective + "じゃなかった";
        case 5: // te form
            return adjective + "で";
        default:
            return "redundant";
        }
    }
}

std::string jpgrammar::desu(const std::string& word, const size_t& format) {
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

std::string jpgrammar::should_adj(std::string &adjective, const std::string &verb, const bool &formal) noexcept {
    adjective = format_adj(adjective, 5,formal); //te form, formallity doesnt matter, it's same here
    std::string formatted_verb = verb;
    formatted_verb = format_verb(formatted_verb,4,formal); //should form
    return adjective + formatted_verb;
}


//initialize all the exceptions
int jpgrammar::initialize() {
    if (adj_except->load(":/xml/grammar/jpgrammar/adjective_exceptions.xml") != 0) { //load irregular verbs for past tense
        std::cerr << "Failed to load adjective exceptions" << std::endl;
        return 1;
    }

    return 0;
}


bool jpgrammar::exceptions_empty() noexcept {
    if(adj_except->empty()){
        return true;
    }

    return false;
}
