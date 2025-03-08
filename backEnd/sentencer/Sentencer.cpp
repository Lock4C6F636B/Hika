#include "Sentencer.h"

//generate data for sentence
int Sentencer::start() {
    data.reset_specifier(); //reset specifier before using, default value -1 is very important
    buddha_sutras.clear(); //reset vector of correct answers
    std::random_device rd; //set rng
    std::mt19937 gen(rd());

    //HERE REWRITE TO 0,1 WHEN TE FORM IS FUNCTIONAL
    //pick template type
    std::uniform_int_distribution<uint8_t> template_dist(0, 0);  //number of template sentences, currently i have only one
    data.template_type = template_dist(gen);


	//lambda function generating types
    auto gen_type = [&gen, &library = this->library](const std::vector<int>& weights) -> size_t {
		std::discrete_distribution<int> dis(weights.begin(), weights.end());
		size_t type;
		//ensure that selected type of vocabulary is not empty
		do {
			type = dis(gen);
        } while (library->empty(type,vocabSelect::first)); //ensure that generated type is not empty
		return type;
	};


	//generate rand num for subject and object types
    std::vector<int> sub_weights; //preset, since always used
    std::vector<int> obj_weights;
    switch(data.template_type){
    case 0:
        sub_weights = { 0, 10, 0, 8, 1, 5, 0, 0, 0 };
        obj_weights = { 0, 5, 10, 1, 2, 10, 0, 0, 0 };
        break;

    case 2:
        sub_weights = { 0, 10, 0, 8, 1, 5, 0, 0, 0 };
        obj_weights = { 0, 5, 10, 1, 2, 10, 0, 0, 0 };
        std::vector<int> specif_weights { 0, 0, 1, 0, 0, 1, 0, 0, 0 };
        data.specif_type = gen_type(specif_weights); //need to allocate weights only in this case, therefore must generate specifier type here
    }

    //weights set, generate the number
    data.sub_type = gen_type(sub_weights);
    data.obj_type = gen_type(obj_weights);


	//lambda function to generate number up to size
    auto gen_num_to = [&gen](const size_t& size) -> size_t {
		if (size > 1) {
			std::uniform_int_distribution<> dist_index(0, size - 1);
			return dist_index(gen);
		}
		else return 0;
	};
	
	//generate indexes
    data.sub_index = gen_num_to(library->type_size(data.sub_type, vocabSelect::first));
    data.obj_index = gen_num_to(library->type_size(data.obj_type, vocabSelect::first));
	//generate meanings
    data.sub_mean = gen_num_to(library->mean_size(data.sub_type, data.sub_index, vocabSelect::first));
    data.obj_mean = gen_num_to(library->mean_size(data.obj_type, data.obj_index, vocabSelect::first));

    //if initialized generate index, meaning... also generate format for the specifier
    if(data.specif_type != -1){
        data.specif_index = gen_num_to(library->type_size(data.specif_type, vocabSelect::first));
        data.specif_mean = gen_num_to(library->mean_size(data.obj_type, data.specif_index, vocabSelect::first));

        //this smells funky, CHECK BACK HERE WHEN YOU HAVE MORE CLARITY
        std::uniform_int_distribution<> specif_format_dist(0, 5); //format for specifier, including te form
        data.format = specif_format_dist(gen);
    }

    //generate format
    std::uniform_int_distribution<> format_dist(0, 4); //format for object
    data.format = format_dist(gen);
	
	//generate particle
    std::vector<int> particle_weights = {45, 45, 10};  // は:45%, が:45%, も:10%
    std::discrete_distribution<> part(particle_weights.begin(), particle_weights.end());
    data.particle = part(gen);

    data.formal = 1;

    //debug, to see what data generated
    std::cerr<<data<<std::endl;

    return 0;
}

//generate sentences and compare with user
bool Sentencer::compare(const std::string answer)  {
	bool correct = false; //preset user correctness to false
    inscribe(); //store prompt, build correct sentences

	//compare
    for (size_t i = 0; i < buddha_sutras.size(); i++) {
        if (answer == string_sutra(library->getDifficulty(),i)) {
			correct = true;
		}
	}

    //logic to determine user's correctness combo
    if ((correct == true) && (prev_suc == true)) {
        suc_count++;
        return true;
    }
    else if ((correct == true) && (prev_suc == false)) {
        prev_suc = true;
        suc_count = 0;
        suc_count++;
        return true;
    }
    else if ((correct == false) && (prev_suc == false)) {
        suc_count--;
        return false;
    }
    else if ((correct == false) && (prev_suc == true)) {
        prev_suc = false;
        suc_count = 0;
        suc_count--;
        return false;
    }
}

void Sentencer::inscribe() const noexcept {
    //build sentences
    switch(data.template_type){ //add more templates when their functions will be implemented
    case 0:
        if(library->getDifficulty() < 4){
            JPbuild_sentence_0();
        } else ENbuild_sentence_0();
        return;
    //case 1:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_1();
    //    } else ENbuild_sentence_1();
    //    return;
    //case 2:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_2();
    //    } else ENbuild_sentence_2();
    //    return;
    //case 3:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_3();
    //    } else ENbuild_sentence_3();
    //    return;
    //case 4:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_4();
    //    } else ENbuild_sentence_4();
    //    return;
    //case 5:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_5();
    //    } else ENbuild_sentence_5();
    //    return;
    //case 6:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_6();
    //    } else ENbuild_sentence_6();
    //    return;
    //case 7:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_7();
    //    } else ENbuild_sentence_7();
    //    return;
    //case 8:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_8();
    //    } else ENbuild_sentence_8();
    //    return;
    //case 9:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_9();
    //    } else ENbuild_sentence_9();
    //    return;
    //case 10:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_10();
    //    } else ENbuild_sentence_10();
    //    return;
    //case 11:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_11();
    //    } else ENbuild_sentence_11();
    //    return;
    //case 12:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_12();
    //    } else ENbuild_sentence_12();
    //    return;
    //case 13:
    //    if(library->getDifficulty() < 4){
    //        JPbuild_sentence_13();
    //    } else ENbuild_sentence_13();
    //    return;
    }
}

std::string Sentencer::harbinger() const noexcept{
    std::string prompt; //store prompt
    //build sentences
    if (library->getDifficulty() < 4) { //call appropriatately based on difficulty
        prompt = ENbuild_prompt_0();
    }
    else {
        prompt = JPbuild_prompt_0();
    }

    switch(data.template_type){
    case 0:
        if(library->getDifficulty() < 4){
            prompt = ENbuild_prompt_0();
        } else prompt = JPbuild_prompt_0();
        break;
    //case 1:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_1();
    //    } else prompt = JPbuild_prompt_1();
    //    break;
    //case 2:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_2();
    //    } else prompt = JPbuild_prompt_2();
    //    break;
    //case 3:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_3();
    //    } else prompt = JPbuild_prompt_3();
    //    break;
    //case 4:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_4();
    //    } else prompt = JPbuild_prompt_4();
    //    break;
    //case 5:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_5();
    //    } else prompt = JPbuild_prompt_5();
    //    break;
    //case 6:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_6();
    //    } else prompt = JPbuild_prompt_6();
    //    break;
    //case 7:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_7();
    //    } else prompt = JPbuild_prompt_7();
    //    break;
    //case 8:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_8();
    //    } else prompt = JPbuild_prompt_8();
    //    break;
    //case 9:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_9();
    //    } else prompt = JPbuild_prompt_9();
    //    break;
    //case 10:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_10();
    //    } else prompt = JPbuild_prompt_10();
    //    break;
    //case 11:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_11();
    //    } else prompt = JPbuild_prompt_11();
    //    break;
    //case 12:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_12();
    //    } else prompt = JPbuild_prompt_12();
    //    break;
    //case 13:
    //    if(library->getDifficulty() < 4){
    //        prompt = ENbuild_prompt_13();
    //    } else prompt = JPbuild_prompt_13();
    //    break;
    }

    return prompt;
}




//sentence template builder-----------------------------------------------------------------------------------------------------------------------------------
//JAPANESE--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//build japanese prompt sentence
std::string Sentencer::JPbuild_prompt_0() const {
    std::string prompt;

    //add subject to sentence
    if ((data.sub_type == 2) || (data.sub_type == 5)) {
        prompt = jpgrammar::subjectify(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first), data.sub_type);
    } else prompt = library->pick(data.sub_type, data.sub_index, data.sub_mean,vocabSelect::first);

    //debug
    std::cout<<"jp prompt start "<<library->pick(data.obj_type,data.obj_index,data.obj_mean,vocabSelect::first)<<", "<<library->pick(data.sub_type,data.sub_index,data.sub_mean,vocabSelect::first)<<std::endl;

    //add particle
    prompt += particles[data.particle];

    //add object to sentence
    switch (data.obj_type){
    case 2: {
        std::cout<<"i see adjective"<<std::endl;
        std::string adjective = library->pick(data.obj_type, data.obj_index, data.obj_mean,vocabSelect::first);
        prompt += jpgrammar::format_adj(adjective,data.format,data.formal);
        break;
    }
    case 5: {
        std::string verb = library->pick(data.obj_type, data.obj_index, data.obj_mean,vocabSelect::first);
        prompt += jpgrammar::format_verb(verb,data.format, data.formal);
        break;
    }
    default: {
        std::string word = library->pick(data.obj_type, data.obj_index, data.obj_mean,vocabSelect::first);
        prompt += jpgrammar::desu(word,data.format);
        break;
    }
    }

    return prompt;
};


//build japanese sentence answers
int Sentencer::JPbuild_sentence_0() const {
    buddha_sutras.push_back(std::vector<std::string>()); //important to do

	//lambda to add each meaning of word to each comparasion sentences
    auto add_word = [this](const size_t &type, const size_t& index, bool is_last) {
        std::vector<std::vector<std::string>> new_sentences;
        for (const auto &sentence : buddha_sutras) { //run through already generated
            for (size_t mean = 0; mean < library->mean_size(type, index,vocabSelect::second); ++mean) { //run through available meanings
                std::string word = library->pick(type, index, mean, vocabSelect::second); //pick word from database
				if (is_last) { //object of sentence need formatting
					switch (type) {
						case 2:
                            word = jpgrammar::format_adj(word, data.format, data.formal);
							break;
						case 5:
                            word = jpgrammar::format_verb(word, data.format, data.formal);
							break;
						default:
                            word = jpgrammar::desu(word, data.format);
							break;
					}
				}
				else { //standard case
                    if (type == 5) { word = jpgrammar::subjectify(word, data.sub_type); //adjectives and verbs need to be subjetified
					}
				}
                std::vector<std::string> new_sentence = sentence;
                new_sentence.push_back(word);//put each meaning into index
                new_sentences.push_back(new_sentence);
			}
		}
        buddha_sutras = std::move(new_sentences);
	};


	//add subject
	add_word(data.sub_type, data.sub_index,false); //add subject to strings of sentences


	//add particle
    if (data.particle == 0 || data.particle == 1) {
        std::vector<std::vector<std::string>> with_particle;

        for (const auto& sentence : buddha_sutras) {
            //store copy with は
            {
                std::vector<std::string> new_sentence = sentence;
                new_sentence.push_back(particles[0]);
                with_particle.push_back(new_sentence);
            }

            //store copy with が
            {
                std::vector<std::string> new_sentence = sentence;
                new_sentence.push_back(particles[1]);
                with_particle.push_back(new_sentence);
            }
        }

        buddha_sutras = std::move(with_particle);
    } else {
        // Add the specified particle to all sentences
        for (auto& sentence : buddha_sutras) {
            sentence.push_back(particles[data.particle]);
        }
    }


	//add object
	add_word(data.obj_type, data.obj_index,true); //add subject to strings of sentences


	return 0;
}




//ENGLISH--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//build english prompt sentence
std::string Sentencer::ENbuild_prompt_0() const {
	std::string prompt;
	
    //add subject to sentence
    prompt = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);
    if (data.sub_type == 5) {
        prompt = engrammar::subjectify(prompt); //transform if verb
    }

    prompt += " "; //add space

    //add to be
    if (data.obj_type != 5){ //noun+verb dont have "to be"
        prompt += engrammar::be(prompt, data.format); //up to this point prompt is containing only subject.. hence prompt can be taken as argument for be that requires subject
	}
	
	prompt += " "; //add space 

    //add objectordBringer
	if (data.obj_type == 5) {
        std::string subject = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first); //for formatting of do, be
        std::string verb = library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
        verb = engrammar::format_verb(verb, data.format, subject); //format verb into correct form
		prompt += verb; //add to sentence
	}
    else prompt += library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first); //add to sentence without formatting
	

	switch (data.particle) {
		case 2:
			prompt += " too";
	}

	return prompt;
};


//build english sentence answers
int Sentencer::ENbuild_sentence_0() const{
    buddha_sutras.push_back(std::vector<std::string>()); //important to do

    //lambda to add each meaning of word to each comparasion sentences
    auto add_word = [this](const size_t& type, const size_t& index,bool is_last) {
        std::vector<std::vector<std::string>> new_sentences;
        for (const auto &sentence : buddha_sutras) { //run through already generated
            for (size_t mean = 0; mean < library->mean_size(type, index,vocabSelect::second); ++mean) { //run through available meanings
                std::string word = library->pick(type, index, mean, vocabSelect::second); //pick word from database
                if((!is_last) && type == 5){ //ensure verb is subjectified
                    word = engrammar::ing(word);
                }
                else if(is_last && type == 5){ //ensure verb is bended
                    word = engrammar::format_verb(word,data.format,library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second));
                }

                std::vector<std::string> new_sentence = sentence;
                new_sentence.push_back(word);//put each meaning into index
                new_sentences.push_back(new_sentence); //put each meaning into index
            }
        }
        buddha_sutras = std::move(new_sentences);
    };


    //add subject
    add_word(data.sub_type, data.sub_index, false); //add subject to strings of sentences

    //add to be or do
    for(auto& sentence : buddha_sutras){
        if(data.obj_type != 5){
            sentence.push_back(engrammar::be(buddha_sutras[0][data.sub_mean],data.format)); //if not verb, add "to be"
        }
    }

    //add object
    add_word(data.obj_type, data.obj_index, true); //add subject to strings of sentences


    if (data.particle == 2) {
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("too");
        }
    }

    return 0;
}




