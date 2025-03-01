#include "HiKa.h"

//initiate the program
int HiKa::start() {
	std::cout << "choose program:\n"
		<< "1. Alphabet (practice writting hiragana and katakana)\n"
		<< "2. Word Bringer (practice memorising words)\n"
		<< "3. Inflection Master (practice bending words)\n"
		<< "4. Sentencer (practice translating senteces)\n"
		<< "5. Exit" << std::endl;

	//choose program according to mode
	while (mode != 5) {
		std::cin >> mode;

		//run modes
		switch (mode) {
		case 1:
			alphabet();
			break;

		case 2:
			wordbringer();
			break;
		case 3:
			inflection();
			break;

		case 4:
			sentenceru();
			break;

		default:
			std::cerr << mode << " is not a mode" << std::endl;
			return start();
		}
	}
	

	return 0;
}

//handles run of alphabet subprogram
int HiKa::alphabet() {
	while (!alpha_game || alpha_game->empty()) { //will ensure that library is not empty
		init_alphabet();
	}

	
	do {
		alpha_game->start(input); //runs the alphabet game
	} while ((input != "end") && (input != "End"));

	return 0;
}

//handles run of wordbringer subprogram
int HiKa::wordbringer() {
	while (!library || library->empty()) { //will ensure that library is not empty
		init_library();
	}


	

	do {
        word_bringer->start(); //runs the alphabet game
	} while ((input != "end") && (input != "End"));

	return 0;
}

//handles run of inflectionmaster subprogram
int HiKa::inflection() {
	while (!library || library->empty()) { //will ensure that library is not empty
		init_library();
	}

	if (!inflection_master) {
		inflection_master = std::make_unique<InflectionMaster>(*library);//initiate from library
	}


	do {
		inflection_master->start(input); //runs the alphabet game
	} while ((input != "end") && (input != "End"));

	return 0;
}

//handles run of sentencer subprogram
int HiKa::sentenceru() {
	while (!library || library->empty()) { //will ensure that library is not empty
		init_library();
	}

	if (!sentencer) {
		sentencer = std::make_unique<Sentencer>(*library);//initiate from library
	}


	do {
		sentencer->start(input); //runs the alphabet game
	} while ((input != "end") && (input != "End"));
	
	return 0;
}

//initiate library
int HiKa::init_library() {
	constexpr size_t lesson_count = 20;

	int difficulty; //sets difficulty of vocabulary
	std::cout << "choose difficulty\n"
		<< "1. english to romanji\n"
		<< "2. english to hiragana japanese\n"
		<< "3. english to full japanese\n"
		<< "4. romanji to english\n"
		<< "5. hiragana japanese to english\n"
		<< "6. full japanese to english" << std::endl;
	std::cin >> difficulty;

	if ((difficulty < 1) || (difficulty > 6)) {
		std::cout << "failed to load library" << std::endl;
		return 1;
	}

	bool is_selected = false; //preset to load entire xml files
	std::cout << "would you like to practice only sections? [y/n]" << std::endl;
	std::cin >> input;
	while (input != "0" && input != "1" && input != "y" && input != "n" && input != "Y" && input != "N") {
		std::cout << "wrong input, try again" << std::endl;
		std::cin >> input;
	}

	//to load only selected
	if (input == "1" || input == "y" || input == "Y") {
		is_selected = true;
	}

	std::cin.ignore(); //for flushing of input stream


	//initiate library or clear and load new content
	if (!library) {
		library = std::make_unique<Library>();
	}
	else {
		library->clear(); // Assuming Library has a clear() method
	}
	

	//load Library
	if (is_selected == true) {
		std::cout << "choose lesson you want to practice" << std::endl;
		//bool lesson;

		sections.clear();
		//preset all lessons to false (so by default none will load)
		for (size_t i = 0; i < lesson_count; i++) { //vocabulary currently has only 20 lessons
			sections.push_back(false);
		}


		//stand in, selected manually... will be done with signals and events in gui version... probably
		//will i see this in end code, murder is iminent
		sections[14] = true;
		
		library->load(difficulty, sections); //initiate word_bringer with only words from selected lessons 

	}
	else  library->load(difficulty); //initiate word_bringer to load entire vocabulary


	return 0;
}

int HiKa::init_alphabet() {
	constexpr size_t type_count = 11;
	std::cout << "initiating alp" << std::endl;
	int difficulty; //sets difficulty of alphabet
	std::cout << "choose difficulty\n"
		<< "1. english to hiragana\n"
		<< "2. english to katakana\n"
		<< "3. english to mix" << std::endl;
	std::cin >> difficulty;

	if ((difficulty < 1) || (difficulty > 3)) {
		std::cout << "failed to load alphabet" << std::endl;
		return 1;
	}

	bool is_selected = false; //preset to load entire xml files
	std::cout << "would you like to practice only sections? [y/n]" << std::endl;
	std::cin >> input;
	while (input != "0" && input != "1" && input != "y" && input != "n" && input != "Y" && input != "N") {
		std::cout << "wrong input, try again" << std::endl;
		std::cin >> input;
	}

	//to load only selected
	if (input == "1" || input == "y" || input == "Y") {
		is_selected = true;
	}

	std::cin.ignore(); //for flushing of input stream


	//initiate library or clear and load new content
	if (!alpha_game) {
		alpha_game = std::make_unique<AlpGame>();
	}
	else {
		alpha_game->clear(); // Assuming Library has a clear() method
	}


	//load Library
	if (is_selected == true) {
		std::cout << "choose lesson you want to practice" << std::endl;
		//bool lesson;

		sections.clear();
		//preset all lessons to false (so by default none will load)
		for (size_t i = 0; i < type_count; i++) { //vocabulary currently has only 20 lessons
			sections.push_back(false);
		}

		//stand in, selected manually... will be done with signals and events in gui version... probably
		//will i see this in end code, murder is iminent
		sections[0] = true;
	
		alpha_game->load(difficulty, sections); //initiate word_bringer with only words from selected lessons 

	}
	else alpha_game->load(difficulty); //initiate word_bringer to load entire vocabulary


	return 0;
}

//helper functions
const void HiKa::show_alpha() const{ 
	alpha_game->showAlp1(); 
	alpha_game->showAlp2a();
	alpha_game->showAlp2b();
}


const void HiKa::show_vocab() const {
	library->showVocab_1();
	library->showVocab_2();
}

void HiKa::show_selected() const {
	for (auto section : sections) {
		std::cout << section << " ";
	}
	
	std::cout << "" << std::endl;
}
