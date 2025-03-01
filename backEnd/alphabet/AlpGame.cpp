#include "AlpGame.h"

AlpGame::AlpGame(const int &Difficulty) { //initiate difficulty and alphabets (alph_1, alph_2a, alph_2b)
	difficulty = Difficulty;
	switch (difficulty) {
	//case for en to hiragana
	case 1:
		alph_1.read("en_alphabet.xml");
		alph_2a.read("hi_alphabet.xml");
		break;
	//case for en to katakana
	case 2:
		alph_1.read("en_alphabet.xml");
		alph_2b.read("ka_alphabet.xml");
		break;
	//case for en to fully fledged jp
	case 3:
		alph_1.read("en_alphabet.xml");
		alph_2a.read("hi_alphabet.xml");
		alph_2b.read("ka_alphabet.xml");
		break;

	default:
		std::cerr << "this difficulty doesnt exist" << std::endl;
		break;
	}
}

AlpGame::AlpGame(const int& Difficulty, const std::vector<bool>& type) { //initiate difficulty and alphabets (alph_1, alph_2a, alph_2b)
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to hiragana
	case 1:
		alph_1.read_selected("en_alphabet.xml",type);
		alph_2a.read_selected("hi_alphabet.xml",type);
		break;
		//case for en to katakana
	case 2:
		alph_1.read_selected("en_alphabet.xml",type);
		alph_2b.read_selected("ka_alphabet.xml",type);
		break;
		//case for en to fully fledged jp
	case 3:
		alph_1.read_selected("en_alphabet.xml",type);
		alph_2a.read_selected("hi_alphabet.xml",type);
		alph_2b.read_selected("ka_alphabet.xml",type);
		break;

	default:
		std::cerr << "this difficulty doesnt exist" << std::endl;
		break;
	}
}

int AlpGame::load(const int &Difficulty) { //initiate difficulty and alphabets (alph_1, alph_2a, alph_2b)
	difficulty = Difficulty;
	switch (difficulty) {
	//case for en to hiragana
	case 1:
		alph_1.read("en_alphabet.xml");
		alph_2a.read("hi_alphabet.xml");
		break;
	//case for en to katakana
	case 2:
		alph_1.read("en_alphabet.xml");
		alph_2b.read("ka_alphabet.xml");
		break;
	//case for en to fully fledged jp
	case 3:
		alph_1.read("en_alphabet.xml");
		alph_2a.read("hi_alphabet.xml");
		alph_2b.read("ka_alphabet.xml");
		break;

	default:
		std::cerr << "this difficulty doesnt exist" << std::endl;
		break;
	}

	return 0;
}

int AlpGame::load(const int& Difficulty, const std::vector<bool>& type) { //initiate difficulty and alphabets (alph_1, alph_2a, alph_2b)
	difficulty = Difficulty;
	switch (difficulty) {
		//case for en to hiragana
	case 1:
		alph_1.read_selected("en_alphabet.xml", type);
		alph_2a.read_selected("hi_alphabet.xml", type);
		break;
		//case for en to katakana
	case 2:
		alph_1.read_selected("en_alphabet.xml", type);
		alph_2b.read_selected("ka_alphabet.xml", type);
		break;
		//case for en to fully fledged jp
	case 3:
		alph_1.read_selected("en_alphabet.xml", type);
		alph_2a.read_selected("hi_alphabet.xml", type);
		alph_2b.read_selected("ka_alphabet.xml", type);
		break;

	default:
		std::cerr << "this difficulty doesnt exist" << std::endl;
		break;
	}

	return 0;
}


int AlpGame::start(std::string& input) {
	//generate index
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist_num(0, alph_1.size() - 1);
	index = dist_num(gen);

	
	std::string letter; //here is result stored 

	//actually pick letter for
	switch (difficulty) {
	case 1:
		std::cout << "write " << alph_1.pick(index) << " in hiragana: "; //show desired word
		letter = alph_2a.pick(index); //assigns item from correct opposite alphabet
		break;

	case 2:
		std::cout << "write " << alph_1.pick(index) << " in kataka: "; //assigns item from correct alphabet
		letter = alph_2b.pick(index); //assigns item from correct opposite alphabet
		break;

	case 3:
		std::uniform_int_distribution<> distr(0, 1);
		int type = distr(gen);
		if (type == 0) {
			std::cout << "write " << alph_1.pick(index) << " in hiragana: "; //assigns item from correct alphabet
			letter = alph_2a.pick(index); //assigns item from correct opposite alphabet
		}
		else if (type == 1) {
			std::cout << "write " << alph_1.pick(index) << " in kataka: "; //assigns item from correct alphabet
			letter = alph_2b.pick(index); //assigns item from correct opposite alphabet
		}
		break;
	}


	return compare(input, letter);
}

int AlpGame::compare(std::string &input, const std::string &letter){
	std::getline(std::cin, input);

	//if statment to check correctness
	if ((input == letter) && (prev_suc == true)) {
		suc_count++;
		success();
	}
	else if ((input == letter) && (prev_suc == false)) {
		prev_suc = true;
		suc_count = 0;
		suc_count++;
		success();
	}
	else if ((input != letter) && (prev_suc == false)) {
		suc_count--;
		success();
		std::cout << ", correct word is " << letter << std::endl;
	}
	else if ((input != letter) && (prev_suc == true)) {
		prev_suc = false;
		suc_count = 0;
		suc_count--;
		success();
		std::cout << ", correct word is " << letter << std::endl;
	}
		
		return 0;
}


//------------------------------------------------------------------------------------------------


//gives response based on comparassion
void AlpGame::success() const {
	if (suc_count == 1) {
		std::cout << "correct" << std::endl;
	}
	else if ((suc_count >= 2) && (suc_count < 4)) {
		std::cout << "that's indeed correct" << std::endl;
	}
	else if ((suc_count >= 4) && (suc_count < 8)) {
		std::cout << "still correct" << std::endl;
	}
	else if ((suc_count >= 8) && (suc_count < 16)) {
		std::cout << "how very glib" << std::endl;
	}
	else if ((suc_count >= 16) && (suc_count < 32)) {
		std::cout << "your parents must be proud" << std::endl;
	}
	else if (suc_count >= 32) {
		std::cout << "a score to kill for" << std::endl;
	}
	else if ((suc_count < 1) && (suc_count > -2)) {
		std::cout << "poor performance";
	}
	else if ((suc_count <= -2) && (suc_count > -4)) {
		std::cout << "horrible, really...";
	}
	else if (suc_count <= -4) {
		std::cout << "now, that's just pathetic...";
	}
}