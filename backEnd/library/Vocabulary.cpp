#include "Vocabulary.h"

//initiate Vocabulary and immediately read data into it
Vocabulary::Vocabulary(const std::string &filename) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    QByteArray data = file.readAll();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

    if (!result) {
        throw std::runtime_error("Failed to parse XML from file: " + filename);
    }

	auto process_items = [](const pugi::xml_node& node, std::vector<std::vector<std::string>>& words) {
		for (pugi::xml_node lesson : node.children()) { //run through lessons
			for (pugi::xml_node item : lesson.children()) { //run through items
				std::vector<std::string> meanings;
				for (pugi::xml_node meaning : item.children("meaning")) { //get here if item has additional meaning
					meanings.push_back(meaning.child_value()); //push back each meaning
				}
				if (meanings.empty()) { //if word has no additional meaning
					words.push_back({ item.child_value() });
				}
				else { //pushes back meanings
					words.push_back(meanings);
				}
			}
		}
    };

	process_items(doc.child("Vocab").child("Mixed"), mixed); 
	process_items(doc.child("Vocab").child("Noun"), noun);
	process_items(doc.child("Vocab").child("Adjective"), adjective);
	process_items(doc.child("Vocab").child("Pronoun"), pronoun);
	process_items(doc.child("Vocab").child("Number"), number);
	process_items(doc.child("Vocab").child("Verb"), verb);
	process_items(doc.child("Vocab").child("Adverb"), adverb);
	process_items(doc.child("Vocab").child("Conjunction"), conjunction);
}

Vocabulary::Vocabulary(const std::string& filename, const std::vector<bool>& lessons) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    QByteArray data = file.readAll();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

    if (!result) {
        throw std::runtime_error("Failed to parse XML from file: " + filename);
    }

	auto process_items = [&lessons](const pugi::xml_node& node, std::vector<std::vector<std::string>>& words) {
		size_t itr = 0;
		for (pugi::xml_node lesson : node.children()) { //run through lessons
			if (lessons[itr]) {
				for (pugi::xml_node item : lesson.children()) { //run through items
					std::vector<std::string> meanings;
					for (pugi::xml_node meaning : item.children("meaning")) { //get here if item has additional meaning
						meanings.push_back(meaning.child_value()); //push back each meaning
					}
					if (meanings.empty()) { //if word has no additional meaning
						words.push_back({ item.child_value() });
					}
					else { //pushes back meanings
						words.push_back(meanings);
					}
				}
			}
			itr++;
		}
	};

	process_items(doc.child("Vocab").child("Mixed"), mixed);
	process_items(doc.child("Vocab").child("Noun"), noun);
	process_items(doc.child("Vocab").child("Adjective"), adjective);
	process_items(doc.child("Vocab").child("Pronoun"), pronoun);
	process_items(doc.child("Vocab").child("Number"), number);
	process_items(doc.child("Vocab").child("Verb"), verb);
	process_items(doc.child("Vocab").child("Adverb"), adverb);
	process_items(doc.child("Vocab").child("Conjunction"), conjunction);
}

//read data into Vocabulary
int Vocabulary::read(const std::string& filename) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    QByteArray data = file.readAll();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

    if (!result) {
        throw std::runtime_error("Failed to parse XML from file: " + filename);
    }

	//make sure vectors are empty before loading in
	mixed.clear(), noun.clear(), adjective.clear(), pronoun.clear(), number.clear(), 
	verb.clear(), adverb.clear(), preposition.clear(), conjunction.clear();

	auto process_items = [](const pugi::xml_node& node, std::vector<std::vector<std::string>>& words) {
		for (pugi::xml_node lesson : node.children()) { //run through lessons
			for (pugi::xml_node item : lesson.children()) { //run through items
				std::vector<std::string> meanings;
				for (pugi::xml_node meaning : item.children("meaning")) { //get here if item has additional meaning
					meanings.push_back(meaning.child_value()); //push back each meaning
				}
				if (meanings.empty()) { //if word has no additional meaning
					words.push_back({ item.child_value() });
				}
				else { //pushes back meanings
					words.push_back(meanings);
				}
			}
		}
	};

	process_items(doc.child("Vocab").child("Mixed"), mixed);
	process_items(doc.child("Vocab").child("Noun"), noun);
	process_items(doc.child("Vocab").child("Adjective"), adjective);
	process_items(doc.child("Vocab").child("Pronoun"), pronoun);
	process_items(doc.child("Vocab").child("Number"), number);
	process_items(doc.child("Vocab").child("Verb"), verb);
	process_items(doc.child("Vocab").child("Adverb"), adverb);
	process_items(doc.child("Vocab").child("Conjunction"), conjunction);

	return 0;
}

//read only selected lessons into Vocabulary
int Vocabulary::read_selected(const std::string& filename, const std::vector<bool> &lessons) {
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    QByteArray data = file.readAll();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_buffer(data.data(), data.size());

    if (!result) {
        throw std::runtime_error("Failed to parse XML from file: " + filename);
    }

	//make sure vectors are empty before loading in
	mixed.clear(), noun.clear(), adjective.clear(), pronoun.clear(), number.clear(), 
	verb.clear(), adverb.clear(), preposition.clear(), conjunction.clear();

	auto process_items = [&lessons](const pugi::xml_node& node, std::vector<std::vector<std::string>>& words) {
		size_t itr = 0;
		for (pugi::xml_node lesson : node.children()) { //run through lessons
			if (lessons[itr]) {
				for (pugi::xml_node item : lesson.children()) { //run through items
					std::vector<std::string> meanings;
					for (pugi::xml_node meaning : item.children("meaning")) { //get here if item has additional meaning
						meanings.push_back(meaning.child_value()); //push back each meaning
					}
					if (meanings.empty()) { //if word has no additional meaning
						words.push_back({ item.child_value() });
					}
					else { //pushes back meanings
						words.push_back(meanings);
					}
				}
			}
			itr++;
		}
	};

	process_items(doc.child("Vocab").child("Mixed"), mixed);
	process_items(doc.child("Vocab").child("Noun"), noun);
	process_items(doc.child("Vocab").child("Adjective"), adjective);
	process_items(doc.child("Vocab").child("Pronoun"), pronoun);
	process_items(doc.child("Vocab").child("Number"), number);
	process_items(doc.child("Vocab").child("Verb"), verb);
	process_items(doc.child("Vocab").child("Adverb"), adverb);
	process_items(doc.child("Vocab").child("Conjunction"), conjunction);

	return 0;
}


//pick word in array of type on index of index
std::string Vocabulary::pick(const size_t& type, const size_t& index, const size_t& meaning) const {
	switch (type) {
		//mixed
		case 0:
			if (index >= mixed.size() || meaning >= mixed[index].size()) {
				return "index out of bounds";
			}
			return mixed[index][meaning];
		//noun
		case 1:
			if (index >= noun.size() || meaning >= noun[index].size()) {
				return "index out of bounds";
			}
			return noun[index][meaning];
		//adjective
		case 2:
			if (index >= adjective.size() || meaning >= adjective[index].size()) {
				return "index out of bounds";
			}
			return adjective[index][meaning];
		//pronoun
		case 3:
			if (index >= pronoun.size() || meaning >= pronoun[index].size()) {
				return "index out of bounds";
			}
			return pronoun[index][meaning];
		//number
		case 4:
			if (index >= number.size() || meaning >= number[index].size()) {
				return "index out of bounds";
			}
			return number[index][meaning];
		//verb
		case 5:
			if (index >= verb.size() || meaning >= verb[index].size()) {
				return "index out of bounds";
			}
			return verb[index][meaning];
		//adverb
		case 6:
			if (index >= adverb.size() || meaning >= adverb[index].size()) {
				return "index out of bounds";
			}
			return adverb[index][meaning];
		//preposition
		case 7:
			if (index >= preposition.size() || meaning >= preposition[index].size()) {
				return "index out of bounds";
			}
			return preposition[index][meaning];
		//conjunction
		case 8:
			if (index >= conjunction.size() || meaning >= conjunction[index].size()) {
				return "index out of bounds";
			}
			return conjunction[index][meaning];
		//for errors
		default:
			std::cerr << "this type of vocabulary does not exist" << std::endl;
			return "";
	}
}

//get number of meanings for word in vector of type on index
size_t Vocabulary::mean_size(const size_t& type, const size_t& index) const {
	switch (type) {
	case 0:
		return mixed[index].size();
	case 1:
		return noun[index].size();
	case 2:
		return adjective[index].size();
	case 3:
		return pronoun[index].size();
	case 4:
		return number[index].size();
	case 5:
		return verb[index].size();
	case 6:
		return adverb[index].size();
	case 7:
		return preposition[index].size();
	case 8:
		return conjunction[index].size();
	default:
		std::cerr << "this type doesnt exist, so i cant number of meanings here"<<std::endl;
		return 0;
	}
}

//get number of meanings for word in vector of type on index
size_t Vocabulary::type_size(const size_t& type) const {
	switch (type) {
	case 0:
		return this->mixed_size();
	case 1:
		return this->noun_size();
	case 2:
		return this->adjective_size();
	case 3:
		return this->pronoun_size();
	case 4:
		return this->number_size();
	case 5:
		return this->verb_size();
	case 6:
		return this->adverb_size();
	case 7:
		return this->preposition_size();
	case 8:
		return this->conjunction_size();
	default:
		std::cerr << "Not a valid vocabulary type" << std::endl;
		return 1;
	}
}

//check selected types are empty
bool Vocabulary::empty(const int& type) const noexcept {
	switch (type) {
		case 0: return mixed.empty();
		case 1: return noun.empty();
		case 2: return adjective.empty();
		case 3: return pronoun.empty();
		case 4: return number.empty();
		case 5: return verb.empty();
		case 6: return adverb.empty();
		case 7: return preposition.empty();
		case 8: return conjunction.empty();
		default: return false; //pressume it's not clear if there is problem, so it can be reloaded
	}
};

//check if all types are empty
bool Vocabulary::empty() const noexcept {
	for (size_t i = 0; i < 9; i++) {
		if (!empty(i)) { return false; }
	}
	return true;
};

//clear entire vocabulary
void Vocabulary::clear() noexcept {
	mixed.clear();
	noun.clear();
	adjective.clear();
	pronoun.clear();
	number.clear();
	verb.clear();
	adverb.clear();
	preposition.clear();
	conjunction.clear();
}


//----------------------------------------------------------------------------------------
//helper functions
void Vocabulary::show_mixed() const{
	for (auto item : mixed){
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout <<" " << std::endl;
	}
}

void Vocabulary::show_noun() const{
	for (auto item : noun) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_adjective() const{
	for (auto item : adjective) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_pronoun() const{
	for (auto item : pronoun) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_number() const{
	for (auto item : number) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_verb() const{
	for (auto item : verb) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_adverb() const{
	for (auto item : adverb) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_preposition() const{
	for (auto item : preposition) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}

void Vocabulary::show_conjunction() const{
	for (auto item : conjunction) {
		for (std::string meaning : item) {
			std::cout << meaning << ", ";
		}	std::cout << " " << std::endl;
	}
}


std::ostream& operator<<(std::ostream& output, const Vocabulary vocab){ //prints entire object
	for (auto item : vocab.mixed) { //print mixed
		for (std::string meaning : item) {
			output << meaning << ",";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.noun) { //print noun
		for (std::string meaning : item) {
			output << meaning << ",";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.adjective) { //print adjective
		for (std::string meaning : item) {
			output << meaning << ",";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.pronoun) { //print pronoun
		for (std::string meaning : item) {
			output << meaning << ",";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.number) { //print number
		for (std::string meaning : item) {
			output << meaning << ",";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;
	
	for (auto item : vocab.verb) { //print verb
		for (std::string meaning : item) {
			output << meaning << ", ";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.adverb) { //print adverb
		for (std::string meaning : item) {
			output << meaning << ", ";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.preposition) { //print preposition
		for (std::string meaning : item) {
			output << meaning << ", ";
		} output << "" << std::endl;
	}

	std::cout << "\n" << std::endl;

	for (auto item : vocab.conjunction) { //print conjunction
		for (std::string meaning : item) {
			output << meaning << ", ";
		} output << " " << std::endl;
	}

	return output;
}
