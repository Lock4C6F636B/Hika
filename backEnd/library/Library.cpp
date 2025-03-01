#include "Library.h"

//load entirity of xml files
Library::Library(const int& Difficulty){
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to romanji
		case 1:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml");
			break;
		//case for en to hiragana
		case 2:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml");
			break;
		//case for en to fully fledged jp
		case 3:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml");
			break;
		//case for romanji to en
		case 4:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		//case for hiragana to en
		case 5:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		//case for fully fledged jp to en
		case 6:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		default:
			std::cerr << "this difficulty doesnt exist" << std::endl;
            break;
	}
}

//load only selected parts of xml files
Library::Library(const int& Difficulty, const std::vector<bool>& lessons) {
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to romanji
		case 1:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml",lessons);
			break;
		//case for en to hiragana
		case 2:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml",lessons);
			break;
		//case for en to fully fledged jp
		case 3:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml",lessons);
			break;
		//case for romanji to en
		case 4:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
			break;
		//case for hiragana to en
		case 5:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
			break;
		//case for fully fledged jp to en
		case 6:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml",lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml",lessons);
			break;
		default:
			std::cerr << "this difficulty doesnt exist" << std::endl;
			break;
	}
}

//initialize vocab_1 and vocab_2 by coping pointer from already exisiting vocabularies
Library::Library(const int& Difficulty, std::shared_ptr<Vocabulary> v1, std::shared_ptr<Vocabulary> v2)
    : difficulty(Difficulty), vocab_1(v1), vocab_2(v2) {
}

//initialize Library with another library
Library::Library(const Library& lib)
    : Library(lib.difficulty, lib.vocab_1, lib.vocab_2) {
}

//to load vocabulary later
int Library::load(const int& Difficulty) {
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to romanji
		case 1:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml");
			break;
		//case for en to hiragana
		case 2:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml");
			break;
		//case for en to fully fledged jp
		case 3:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml");
			break;
		//case for romanji to en
		case 4:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		//case for hiragana to en
		case 5:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		//case for fully fledged jp to en
		case 6:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml");
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml");
			break;
		default:
			std::cerr << "this difficulty doesnt exist" << std::endl;
			return 1;
	}

	return 0;
}

int Library::load(const int& Difficulty, const std::vector<bool>& lessons){
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to romanji
		case 1:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml", lessons);
			break;
		//case for en to hiragana
		case 2:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml", lessons);
			break;
		//case for en to fully fledged jp
		case 3:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml", lessons);
			break;
		//case for romanji to en
		case 4:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/ro_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
			break;
		//case for hiragana to en
		case 5:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jp_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
			break;
		//case for fully fledged jp to en
		case 6:
            vocab_1 = std::make_shared<Vocabulary>(":/xml/vocabulary/jpf_vocabulary.xml", lessons);
            vocab_2 = std::make_shared<Vocabulary>(":/xml/vocabulary/en_vocabulary.xml", lessons);
			break;
		default:
			std::cerr << "this difficulty doesnt exist" << std::endl;
			return 1;
	}

	return 0;
}

int Library::load(const int& Difficulty, std::shared_ptr<Vocabulary> v1, std::shared_ptr<Vocabulary> v2){
	difficulty = Difficulty; vocab_1 = v1; vocab_2 = v2;
	return 0;
}

//return empty if even one of them is empty
bool Library::empty() const {
	if (!vocab_1 || !vocab_2){ //check for nullptr
		return true;
	}

    return (vocab_1->empty() || vocab_2->empty()); //pointer is initiated, but memory is empty
}

//clear content of both vocabularies
void Library::clear() const noexcept {
	vocab_1->clear();
	vocab_2->clear();
}

//setter for difficulty
int Library::setDifficulty(int Difficulty) noexcept {
    return (difficulty = Difficulty, 0);
}

//overloaded operator
Library& Library::operator=(const Library& lib) {
	if (this != &lib) {
		difficulty = lib.difficulty;
		vocab_1 = lib.vocab_1;
		vocab_2 = lib.vocab_2;
	}
	return *this;
}
