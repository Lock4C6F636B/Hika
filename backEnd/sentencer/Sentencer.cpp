#include "Sentencer.h"

//generate data for sentence
int Sentencer::start() {
    data.reset_specifier(); //reset specifier before using, default value -1 is very important
    buddha_sutras.clear(); //reset vector of correct answers
    buddha_sutras.push_back(std::vector<std::string>()); //VERY IMPORTANT push in empty string, whole system is working on +=
    std::random_device rd; //set rng
    std::mt19937 gen(rd());

    //HERE REWRITE TO 0,2 WHEN TE FORM IS FUNCTIONAL
    //pick template type
    std::uniform_int_distribution<uint8_t> template_dist(0, 3);  //number of template sentences, currently i have only one
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
    if(data.template_type == 0 || data.template_type == 1){
        sub_weights = { 0, 10, 0, 8, 1, 5, 0, 0, 0 };
        obj_weights = { 0, 5, 10, 1, 2, 10, 0, 0, 0 };
    }
    else if(data.template_type == 2 || data.template_type == 3){
        sub_weights = { 0, 10, 0, 8, 1, 5, 0, 0, 0 };
        obj_weights = { 0, 0, 1, 0, 0, 1, 0, 0, 0 };
        std::vector<int> specif_weights { 0, 0, 1, 0, 0, 1, 0, 0, 0 };
        do {
            data.specif_type = gen_type(specif_weights); //need to allocate weights only in this case, therefore must generate specifier type here
        } while(data.specif_type == 5 && data.obj_type != 5); //ensure that specifier cannot be verb, because expanding none verb by verb is not possible... eg. cannot specify "cute" by "run"

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
        data.specif_format = 5;
    }

    //generate format... FOR SAFETY REASONS DISALLOW SHOULD FOR NONE VERBS
    std::uniform_int_distribution<> format_dist;
    if(data.obj_type == 5){
        std::uniform_int_distribution<> format_dist(0, 4);
        data.format = format_dist(gen);
    }
    else{
        std::uniform_int_distribution<> format_dist(0, 3); //format for object
        data.format = format_dist(gen);
    }

	
	//generate particle
    std::vector<int> particle_weights = {45, 45, 10};  // は:45%, が:45%, も:10%
    std::discrete_distribution<> part(particle_weights.begin(), particle_weights.end());
    data.particle = part(gen);

    //for now accept only formal
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
    if(library->getDifficulty() < 4){
        if(data.template_type < 2){
            JPbuild_sentence_simple();
        }
        else if(data.template_type < 4){
            JPbuild_sentence_te_form();
        }
    }
    else {
        if(data.template_type < 2){
            ENbuild_sentence_simple();
        }
        else if(data.template_type < 4){
            ENbuild_sentence_te_form();
        }
    }
}

std::string Sentencer::harbinger() const noexcept{
    std::string prompt; //store prompt

    //build appropriate prompt
    if(library->getDifficulty() < 4){
        if(data.template_type < 2){
            prompt = ENbuild_prompt_simple();
        }
        else if(data.template_type < 4){
            prompt = ENbuild_prompt_te_form();
        }
    }
    else {
        if(data.template_type < 2){
            prompt = JPbuild_prompt_simple();
        }
        else if(data.template_type < 4){
            prompt = JPbuild_prompt_te_form();
        }
    }

    return prompt;
}




//sentence template builder-----------------------------------------------------------------------------------------------------------------------------------
//JAPANESE--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//build japanese prompt sentence
std::string Sentencer::JPbuild_prompt_simple() const {
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

    if(data.template_type == 1){
        prompt += "か";
    }

    return prompt;
};

//build japanese sentence answers
int Sentencer::JPbuild_sentence_simple() const {    
	//add subject
    jp_add_subject(); //add subject to sentences

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
    jp_add_object();

    //add ka, if question
    if(data.template_type == 1){
        for(std::vector<std::string> &sentence : buddha_sutras){
            sentence.push_back("か");
        }
    }

	return 0;
}


std::string Sentencer::JPbuild_prompt_te_form() const{
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
    auto format_word = [&library = this->library](const size_t &type, const size_t &index, const size_t &mean, const size_t &format, const bool &formal) -> std::string {
        switch (type){
        case 2: {
            std::cout<<"i see adjective"<<std::endl;
            std::string adjective = library->pick(type, index, mean,vocabSelect::first);
            return jpgrammar::format_adj(adjective,format,formal);
        }
        case 5: {
            std::string verb = library->pick(type, index, mean,vocabSelect::first);
            return jpgrammar::format_verb(verb,format, formal);
        }
        default: {
            std::string word = library->pick(type, index, mean,vocabSelect::first);
            return jpgrammar::desu(word,format);
        }
        }
    };


    prompt+= format_word(data.specif_type,data.specif_index,data.specif_mean,data.specif_format,data.formal); //add formated specifier
    prompt+= format_word(data.obj_type,data.obj_index,data.obj_mean,data.format,data.formal); //add formated object


    if(data.template_type == 3){
        prompt += "か";
    }

    return prompt;
}

int Sentencer::JPbuild_sentence_te_form() const {
    //add subject
    jp_add_subject();

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


    jp_add_specifier(); //add specifier to all sentences
    jp_add_object(); //add object to all sentences

    //add ka, if question
    if(data.template_type == 3){
        for(std::vector<std::string> &sentence : buddha_sutras){
            sentence.push_back("か");
        }
    }

    return 0;
}

//ENGLISH--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//build english prompt sentence
std::string Sentencer::ENbuild_prompt_simple() const {
    std::string prompt;

    //for template 1 (question), do or be needs to be first
    if(data.template_type == 1){
        if(data.obj_type != 5){
            prompt += engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first),data.format);
        }
        else{
            prompt += engrammar::dot(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first),data.format);
        }
        prompt += " "; //add space after
    }

    //add subject to sentence
    if (data.sub_type == 5) {
        std::string subject = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);
        prompt += engrammar::subjectify(subject); //transform if verb
    }else prompt += library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);

    prompt += " "; //add space

    //add to be
    if (data.template_type == 0 && data.obj_type != 5){ //noun+verb dont have "to be", neither does question
        prompt += engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first), data.format); //up to this point prompt is containing only subject.. hence prompt can be taken as argument for be that requires subject
        prompt += " "; //add space
    }


    //add object
    if (data.template_type == 0 && data.obj_type == 5) { //format only if not question
        std::string verb = library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
        verb = engrammar::format_verb(verb, data.format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first)); //format verb into correct form
		prompt += verb; //add to sentence
	}
    else prompt += library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first); //add to sentence without formatting
	

	switch (data.particle) {
		case 2:
			prompt += " too";
    }

    if(data.template_type == 1){
        prompt += "?";
    }


    //debug prompt;
    std::cerr<<prompt<<std::endl;

	return prompt;
};

//build english sentence answers
int Sentencer::ENbuild_sentence_simple() const {
    //do or to be for question... technically speaking only template_types 0-1 should get here, but better to desribe it as general odd == question
    if(data.template_type%2 != 0){
        for(std::vector<std::string> &sentence : buddha_sutras){
            if(data.obj_type == 5){
                sentence.push_back(engrammar::dot(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format));
            }else sentence.push_back(engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format));
        }

    }


    //add subject
    en_add_subject(); //add subject to sentences

    //add object
    en_add_object(false, data.template_type%2 == 0? false : true, data.format%2 ==  0? false : true); //every odd template is always qustion. format up to 4 follows pattern odd == negative, even == positive


    if (data.particle == 2) {
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("too");
        }
    }


    //swap position so first is do/be, followed by subject
    if(data.template_type == 1){
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("?"); //also add question mark for proper punctiation
        }
    }


    return 0;
}


std::string Sentencer::ENbuild_prompt_te_form() const {
    std::string prompt;

    //for template 3 (question), do or be needs to be first
    if(data.template_type == 3){
        if(data.obj_type != 5){
            prompt += engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first),data.format);
        }
        else{
            prompt += engrammar::dot(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first),data.format);
        }
        prompt += " "; //add space after
    }

    //add subject to sentence
    if (data.sub_type == 5) {
        std::string subject = library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);
        prompt += engrammar::subjectify(subject); //transform if verb
    }else prompt += library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first);
    prompt += " "; //add space


    if(data.template_type == 2){
        if(data.obj_type == 5 && data.specif_type == 5){
            //add subject
            std::string verb = library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first);
            verb = engrammar::format_verb(verb, data.format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first)); //format verb specifier
            prompt += verb; //add to sentence

            prompt += " and "; //add conjugation

            //add object, need to keep infinite if specifier already has did in front
            verb = library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
            prompt += (data.obj_type%2 == 0)? engrammar::format_verb(verb, data.format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first)) : verb; //if did is not at front, format
        }
        else if(data.specif_type == 2 && data.obj_type == 5){
            std::string verb = library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
            verb = engrammar::format_verb(verb, data.format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first)); //format verb specifier
            prompt += verb; //add to sentence
            prompt += " "; //add space

            //add specifier as adverb... note, sounds best as last
            prompt += engrammar::ly(library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first));
        }
        else{
            prompt += engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::first), data.format);
            prompt += " ";
            prompt += library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first);
            prompt += " and ";
            prompt += library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
        }
    }
    else{ //question, do/be is at front of sentence already
        if(data.specif_type == 2 && data.obj_type == 5){
            std::string verb = library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
            prompt += verb; //add object
            prompt += " ";

            prompt += engrammar::ly(library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first)); //add specifier as adverb
        }
        else{
            std::string word = library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first);
            prompt += word; //add object
            prompt += " and "; //add conjugation
            prompt += library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first); //add specifier
        }
    }


    switch (data.particle) {
    case 2:
        prompt += " too";
    }

    if(data.template_type == 3){
        prompt += "?";
    }


    //debug prompt;
    std::cerr<<prompt<<std::endl;

    return prompt;
}

int Sentencer::ENbuild_sentence_te_form() const{
    //do or to be for question... technically speaking only template_types 0-1 should get here, but better to desribe it as general odd == question
    if(data.template_type%2 != 0){
        for(std::vector<std::string> &sentence : buddha_sutras){
            if(data.obj_type == 5){
                sentence.push_back(engrammar::dot(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format));
            }else sentence.push_back(engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format));
        }

    }


    //add subject
    en_add_subject(); //add subject to sentences

    //add specifier
    en_add_specifier(data.template_type%2 == 0? false : true, data.format%2 ==  0? false : true);

    //add object
    en_add_object(true, data.template_type%2 == 0? false : true, data.format%2 ==  0? false : true); //every odd template is always qustion. format up to 4 follows pattern odd == negative, even == positive


    if (data.particle == 2) {
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("too");
        }
    }


    //swap position adverb and verb. so ly word as behind to sound more naturally
    if(data.template_type == 1){
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("?"); //also add question mark for proper punctiation
        }
    }

    //swap position so first is do/be, followed by subject
    if(data.template_type == 1){
        for (auto& sentence : buddha_sutras) {
            sentence.push_back("?"); //also add question mark for proper punctiation
        }
    }


    return 0;
}




//helper functions-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Sentencer::jp_add_subject() const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.sub_type, data.sub_index,vocabSelect::second); ++mean) { //run through available meanings
            std::string subject = library->pick(data.sub_type, data.sub_index, mean, vocabSelect::second); //pick word from database
            if (data.sub_type == 5) { subject = jpgrammar::subjectify(subject, data.sub_type); //verbs need to be subjetified
            }

            std::vector<std::string> new_sentence = sentence;
            new_sentence.push_back(subject);//put each meaning into index
            new_sentences.push_back(new_sentence);
        }
    }
    buddha_sutras = std::move(new_sentences);
}

void Sentencer::jp_add_specifier() const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.specif_type, data.specif_index,vocabSelect::second); ++mean) { //run through available meanings
            std::string specifier = library->pick(data.specif_type, data.specif_index, mean, vocabSelect::second); //pick word from database

            switch (data.specif_type) {
            case 2:
                specifier= jpgrammar::format_adj(specifier, data.specif_format, data.formal);
                break;
            case 5:
                specifier = jpgrammar::format_verb(specifier, data.specif_format, data.formal);
                break;
            }


            std::vector<std::string> new_sentence = sentence;
            new_sentence.push_back(specifier);//put each meaning into index
            new_sentences.push_back(new_sentence);
        }
    }
    buddha_sutras = std::move(new_sentences);
}

void Sentencer::jp_add_object() const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.obj_type, data.obj_index,vocabSelect::second); ++mean) { //run through available meanings
            std::string object = library->pick(data.obj_type, data.obj_index, mean, vocabSelect::second); //pick word from database

            switch (data.obj_type) {
            case 2:
                object = jpgrammar::format_adj(object, data.format, data.formal);
                break;
            case 5:
                object = jpgrammar::format_verb(object, data.format, data.formal);
                break;
            default:
                object = jpgrammar::desu(object, data.format);
                break;
            }

            std::vector<std::string> new_sentence = sentence;
            new_sentence.push_back(object);//put each meaning into index
            new_sentences.push_back(new_sentence);
        }
    }
    buddha_sutras = std::move(new_sentences);
}


void Sentencer::en_add_subject() const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.sub_type, data.sub_index,vocabSelect::second); ++mean) { //run through available meanings
            std::string subject = library->pick(data.sub_type, data.sub_index, mean, vocabSelect::second); //pick word from database
            if(data.sub_type == 5){ //ensure verb is subjectified
                subject = engrammar::ing(subject);
            }

            std::vector<std::string> new_sentence = sentence; //stand in where new words are generated to not mess looping of original
            new_sentence.push_back(subject);//put each meaning into index
            new_sentences.push_back(new_sentence); //put each meaning into index
        }
    }
    buddha_sutras = std::move(new_sentences);
}

void Sentencer::en_add_specifier(const bool is_question, const bool is_negative) const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.specif_type, data.specif_index,vocabSelect::second); ++mean) { //run through available meanings
            std::vector<std::string> new_sentence = sentence; //stand in where new words are generated to not mess looping of original
            std::string specifier = library->pick(data.specif_type, data.specif_index, mean, vocabSelect::second); //pick word from database

            if(data.specif_type == 2 && data.obj_type == 5){
                specifier = engrammar::ly(specifier);
                new_sentence.push_back(specifier);
            }else{
                if((!is_question || !is_negative) && data.specif_type == 5){ //format verb
                    specifier = engrammar::format_verb(specifier, data.specif_format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second));
                }
                else if(data.specif_type != 5 && !is_question){
                    new_sentence.push_back(engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format)); //add to be if not question or verb
                }

                new_sentence.push_back(specifier);
                new_sentence.push_back("and");
            }

            new_sentences.push_back(new_sentence); //put each meaning into index
        }
    }
    buddha_sutras = std::move(new_sentences);
}

void Sentencer::en_add_object(const bool using_specifier, const bool is_question, const bool is_negative) const noexcept{
    std::vector<std::vector<std::string>> new_sentences;
    for (const auto &sentence : buddha_sutras) { //run through already generated
        for (size_t mean = 0; mean < library->mean_size(data.obj_type, data.obj_index,vocabSelect::second); ++mean) { //run through available meanings
            std::vector<std::string> new_sentence = sentence; //stand in where new words are generated to not mess looping of original
            std::string object = library->pick(data.obj_type, data.obj_index, mean, vocabSelect::second); //pick word from database

            //sorted by what i think is most probable to ensure more likely cases will be resolved quicker
            if(data.obj_type == 5 && (!is_negative || (!using_specifier && !is_question))){ //format verb
                 object = engrammar::format_verb(object, data.specif_format, library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second));
            }
            else if(data.obj_type != 5 && (!using_specifier && !is_question)){ //if it is none-negative question
                new_sentence.push_back(engrammar::be(library->pick(data.sub_type, data.sub_index, data.sub_mean, vocabSelect::second), data.format)); //add to be if not question or verb
            }

            new_sentence.push_back(object);
            new_sentences.push_back(new_sentence); //put each meaning into index
        }
    }

    buddha_sutras = std::move(new_sentences);
}

