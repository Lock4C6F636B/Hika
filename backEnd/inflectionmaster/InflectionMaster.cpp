#include "InflectionMaster.h"

int InflectionMaster::start() {
    data.reset_specifier(); //reset specifier before using, default value -1 is very important
    buddha_sutras.clear();
    std::random_device rd; //set rng
    std::mt19937 gen(rd());

    //probability for having a specifier (e.g. 30% chance)
    std::bernoulli_distribution use_specifier(0.2);
    bool should_use_specifier = use_specifier(gen);

	//initialize weighted random number generator for type 
	std::vector<int> weights = { 0, 0, 1, 0, 0, 1, 0, 0, 0 }; //define weights (adjust these as desired)
	std::discrete_distribution<int> dis(weights.begin(), weights.end()); //create a discrete distribution based on weights

	//ensure that selected type of vocabulary is not empty
	do {
		data.obj_type = dis(gen);
        if(should_use_specifier){ //ensure if verb is not specifier of adjective object, that wouldnt make sense
            data.specif_type = dis(gen);
        }
    } while (library->empty(data.obj_type, vocabSelect::second) || (should_use_specifier && library->empty(data.specif_type, vocabSelect::second)) || (data.specif_type == 5 && data.obj_type != 5));


	//lambda function to generate number up to size
    auto gen_num_to = [&gen](const size_t& size) -> size_t {
		if (size > 1) {
			std::uniform_int_distribution<> dist_index(0, size - 1);
			return dist_index(gen);
		}
		else return 0;
	};

    data.obj_index = gen_num_to(library->type_size(data.obj_type,vocabSelect::second)); //generate index
    data.obj_mean = gen_num_to(library->mean_size(data.obj_type, data.obj_index,vocabSelect::second)); //generate meaning
    if(should_use_specifier){
        data.specif_index = gen_num_to(library->type_size(data.specif_type,vocabSelect::second)); //generate index
        data.specif_mean = gen_num_to(library->mean_size(data.specif_type, data.specif_index,vocabSelect::second)); //generate meaning
    }


    //generate format
    std::uniform_int_distribution<> format_dist(0, 4); // 0-5 for verbs (including te form)
    data.format = format_dist(gen);
    if(should_use_specifier){
        data.specif_format = 5; //if specifier is in use it must be te form... other formats don't specify object
    }


    //generate person, important for english
    //or generate forrmal for japanese... both cannot coexist anyway, not in this subprogram
    if(library->getDifficulty() > 3){
        std::bernoulli_distribution third_p_dist(0.7);  // 70% chance for true
        data.third_p = third_p_dist(gen);
    } else {
        std::bernoulli_distribution formal_dist(0.6);  // 60% chance for formal speech
        data.formal = formal_dist(gen);
    }

    std::cerr<<"exitting start"<<std::endl;

    std::cout<<data<<std::endl;

    return 0;
}

bool InflectionMaster::compare(const std::string answer)  {
    std::cerr<<"entering comapre<<"<<std::endl;
    //get true answer
    inscribe();
    std::string correct_inflection = divine_truth();

    //comparasion (first part of statment) +logic to determine user's correctness combo
    if ((answer == correct_inflection) && (prev_suc == true)) {
        suc_count++;
        return true;
    }
    else if ((answer == correct_inflection) && (prev_suc == false)) {
        prev_suc = true;
        suc_count = 0;
        suc_count++;
        return true;
    }
    else if ((answer != correct_inflection) && (prev_suc == false)) {
        suc_count--;
        return false;
    }
    else if ((answer != correct_inflection) && (prev_suc == true)) {
        prev_suc = false;
        suc_count = 0;
        suc_count--;
        return false;
    }

    std::cerr<<"entering comapre<<"<<std::endl;
}


void InflectionMaster::inscribe() const noexcept {
    std::cerr << "divine_truth called at " << std::time(nullptr) << std::endl;  // Add timestamp
     auto bend_it = [this](std::string word, const size_t &type, const size_t &format) -> std::string {
        //determine which formatting to use and use it
        if (library->getDifficulty() < 4) {
            if (type == 2) {
                word = (format == 4) ?
                             jpgrammar::should_adj(word, std::string("なる"), data.formal) :
                             jpgrammar::format_adj(word,format, data.formal);
            }
            else if (type == 5) {
                word = jpgrammar::format_verb(word, format, data.formal);
            }
        }
        else if (library->getDifficulty()< 7) {
            if (type == 2){
                if(format == 4){
                    word = engrammar::be("you",format) + word;
                }
                else if(data.specif_format == 5 && data.obj_type == 5){
                    word = engrammar::ly(word); //need to add space, object will be following
                }
                else {
                    word = data.third_p ? engrammar::be("he",format) + word : engrammar::be("you",format) + word;
                }
            }
            else if (type == 5){
                word = data.third_p ? engrammar::format_verb(word,format,"he") : engrammar::format_verb(word,format,"you");
            }
        }

        std::cout<<word<<" correct inflection"<<std::endl;
        return word;
    };


    if(library->getDifficulty() < 4){
        if(data.specif_type != -1){buddha_sutras.push_back(bend_it(library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::second),data.specif_type,data.specif_format));} //inflect specfier
        buddha_sutras.push_back(bend_it(library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second),data.obj_type,data.format)); //inflect specifier, if it is initialized)
    }
    else{
        //if specificier is used then formatting is actually need to be done mostly on specifier
        if(data.specif_type != -1){
            buddha_sutras.push_back(bend_it(library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::second),data.specif_type,data.format)); //format first word by overall format

            if(data.specif_type != 2 || data.obj_type != 5){ buddha_sutras.push_back("and");} //if not ly add "and"

            if(data.obj_type == 5 && (data.format == 0 || data.format == 2)){ //if second word is verb and does not use to be or do, format second one
                buddha_sutras.push_back(bend_it(library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second),data.obj_type,data.format));
            } else buddha_sutras.push_back(library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second));

        } else buddha_sutras.push_back(bend_it(library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second),data.obj_type,data.format)); //inflect specifier, if it is initialized)
    }


    std::cerr<<"leving truth, "<<to_string(library->getDifficulty())<<std::endl; //debug, show correct answer
}


std::string InflectionMaster::prophecy() const noexcept{
    std::string prompt;
    if (library->getDifficulty() < 4) { //for japanese inflections
        if(data.specif_format != -1){
            prompt += "te form + ";
        }
        switch(data.format) {
        case 0:
            prompt += "As it exists now (です/ます)";
            break;
        case 1:
            prompt += "The absence of being (ません)";
            break;
        case 2:
            prompt += "Memory of what was (ました)";
            break;
        case 3:
            prompt += "Echo of what never was (ませんでした)";
            break;
        case 4:
            prompt += "Path yet to be taken (ましょう)";
            break;
        case 5:
            prompt += "Bridge between actions (て/で)";
            break;
        }

        if(data.formal){prompt += " (formal)";
        } else prompt += " informal";
    }

    else if (library->getDifficulty() < 7) { //for english inflections
        if(data.specif_format != -1){
            prompt += "and + ";
        }
        switch(data.format) {
        case 0:
            if(!data.third_p){
                prompt += "State of being (first person) (です/ます)";
            } else prompt+= "State of being (third person) (です/ます)";
            break;
        case 1:
            if(!data.third_p){
                return "State of denial (first person) (ません)";
            } else return "State of denial (third person) (ません)";
            break;
        case 2:
            prompt += "Echo of yesterday";
            break;
        case 3:
            prompt += "Yesterday's denial";
            break;
        case 4:
            prompt += "Tomorrow's possibility";
            break;
        case 5:
            prompt += "Connecting thread";
            break;
        }
    }

    return prompt;
}
