#include "WordBringer.h"

//generate data to pick random word from vocabulary
int WordBringer::start() {
    //initialize weighted random number generator for type
	std::random_device rd;
	std::mt19937 gen(rd());
    std::vector<int> weights = { 4, 8, 6, 3, 2, 7, 3, 2, 1 }; //define weights for subject(adjust these as desired)
	std::discrete_distribution<int> dis(weights.begin(), weights.end()); //create a discrete distribution based on weights

	//ensure that selected type of vocabulary is not empty
    do {
        data.obj_type = dis(gen);
    } while (library->empty(data.obj_type, vocabSelect::first));


	//lambda function to generate number up to size
    auto gen_num_to = [&gen](const size_t& size) -> size_t {
		if (size > 1) {
			std::uniform_int_distribution<> dist_num(0, size - 1);
            return dist_num(gen);
		}
		else return 0;
	};


    data.obj_index = gen_num_to(library->type_size(data.obj_type,vocabSelect::first)); //generate index
    data.obj_mean = gen_num_to(library->mean_size(data.obj_type, data.obj_index, vocabSelect::first)); //generate meaning

    return 0;
}

//compare the word with user input
bool WordBringer::compare(const std::string answer) {
	bool correct = false; //preset user correctness to false

	//compare
    for (size_t i = 0; i < library->mean_size(data.obj_type, data.obj_index,vocabSelect::second); i++) { //compare user input with each meaning of the word
        if (answer == library->pick(data.obj_type, data.obj_index, i, vocabSelect::second)) {
			correct = true;
			break;
		};
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


std::string WordBringer::divine_truth() const noexcept {
    std::string answer;
    for (size_t i = 0; i < library->mean_size(data.obj_type, data.obj_index, vocabSelect::second); i++) {
        answer += library->pick(data.obj_type,data.obj_index,i, vocabSelect::second);
        if(i < (library->mean_size(data.obj_type, data.obj_index, vocabSelect::second)-1)){
            answer += " or ";
        }
    }

    return answer;
}
