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

    std::cerr<<data<<std::endl;

    return 0;
}

//generate sentences and compare with user
bool Sentencer::compare(const std::string answer)  {
	bool correct = false; //preset user correctness to false
    inscribe(); //store prompt, build correct sentences

	//compare
	for (const std::string& sentence : compar_sent) {
        if (answer == sentence) {
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
    if (library->getDifficulty() < 4) { //call appropriatately based on difficulty
        switch(data.template_type){ //add more templates when their functions will be implemented
        default:
            JPbuild_sentence_0();
            break;
        }
    }
    else {
        switch(data.template_type){
        default:
            ENbuild_sentence_0();
            break;
        }
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

    return prompt;
}

/*
std::string Sentencer::divine_truth() const noexcept { //throw correct string to frontend
    std::string answer;
    for(size_t i = 0; i < compar_sent.size(); i++){
        answer += compar_sent[i];
        if(i < compar_sent.size() - 1){ // Changed condition to use vector size
            answer += "<br>"; // Using HTML line break
        }
    }

    return answer;
}
*/


//sentence template builder-----------------------------------------------------------------------------------------------------------------------------------
//build japanese prompt sentence
std::string Sentencer::JPbuild_prompt_0() const {
    //add subject
    std::string prompt;

    //add subject to sentence
    if ((data.sub_type == 2) || (data.sub_type == 5)) {
        prompt = jpgrammar::subjectify(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first), data.sub_type);
    } else prompt = library->pick(data.sub_type, data.sub_index, data.sub_mean,vocabSelect::first);

    std::cout<<"jp prompt start "<<library->pick(data.obj_type,data.obj_index,data.obj_mean,vocabSelect::first)<<", "<<library->pick(data.sub_type,data.sub_index,data.sub_mean,vocabSelect::first)<<std::endl;

    //add particle
    prompt += particles[data.particle];

    //add object to sentence
    switch (data.obj_type){
    case 2: {
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
    prepare_compar(); //important

	//lambda to add each meaning of word to each comparasion sentences
	auto add_word = [this](const size_t& type, const size_t& index, bool is_last) {
		std::vector<std::string> new_sentences;
		for (const auto& sentence : compar_sent) { //run through already generated
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
				new_sentences.push_back(sentence + word); //put each meaning into index
			}
		}
		compar_sent = std::move(new_sentences);
	};


	//add subject
	add_word(data.sub_type, data.sub_index,false); //add subject to strings of sentences

	//add particle
	if (data.particle == 0 || data.particle == 1) {
		std::vector<std::string> stand_in; //stand in for parsing second particle
		for (const std::string& sentence : compar_sent) { //parse second particle into stand in
			stand_in.push_back(sentence + particles[0]);
			stand_in.push_back(sentence + particles[1]);
		}
		compar_sent = std::move(stand_in);
	}
	else{
		for (std::string& sentence : compar_sent) {
			sentence += particles[data.particle];
		}
	}

	//add object
	add_word(data.obj_type, data.obj_index,true); //add subject to strings of sentences


	return 0;
}

//build english prompt sentence
std::string Sentencer::ENbuild_prompt_0() const {
	std::string prompt;
	
    //add subject to sentence
    prompt = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);
    if (data.sub_type == 5) {
        prompt = engrammar::subjectify(prompt); //transform if verb
    }

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
    prepare_compar(); //important

    //lambda to add each meaning of word to each comparasion sentences
    auto add_word = [this](const size_t& type, const size_t& index,bool is_last) {
        std::vector<std::string> new_sentences;
        for (const auto& sentence : compar_sent) { //run through already generated
            for (size_t mean = 0; mean < library->mean_size(type, index,vocabSelect::second); ++mean) { //run through available meanings
                std::string word = library->pick(type, index, mean, vocabSelect::second); //pick word from database


                if((!is_last) && type == 5){ //ensure verb is subjectified
                    std::cerr<<"subjetiying, type "<<type<<std::endl;
                    word = engrammar::ing(word);
                }
                else if(is_last && type == 5){ //ensure verb is bended
                    word = engrammar::format_verb(word,data.format,library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second));
                }

                new_sentences.push_back(sentence + word); //put each meaning into index
            }
        }
        compar_sent = std::move(new_sentences);
    };


    //add subject
    add_word(data.sub_type, data.sub_index, false); //add subject to strings of sentences
    append_str(" "); //add space

    //add to be or do
    for(auto& sentence : compar_sent){
        std::string subject = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second); //pick word from database, again... i know frustrating to allocate yet another variable
        if(data.obj_type != 5){
            sentence += engrammar::be(subject,data.format); //if not verb, add "to be"
        }
    }

    append_str(" "); //add space

    //add object
    add_word(data.obj_type, data.obj_index, true); //add subject to strings of sentences


    return 0;
}




