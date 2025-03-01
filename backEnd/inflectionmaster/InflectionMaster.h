#pragma once
#include "Origin.h"
#include "ScriptureOfWest.h"
#include "Library.h"
#include "JPGrammar.h"
#include "ENGrammar.h"


class InflectionMaster : private Origin<InflectData>, private ScriptureOfWest{
private:
    //inherited succes_count
    //inherited Data data
    //inherited sacred scripts
    //inherited Library

public:
    InflectionMaster(std::shared_ptr<Library> library) : Origin(library) {}; //copy constructor to allow converion from parent to child
	~InflectionMaster() = default;

    int start() override; //generate data to pick random word from vocabulary

    bool compare(const std::string answer) override; //compare the word with user answer

    inline void inscribe() const noexcept override;

    inline std::string harbinger() const noexcept override {
        if(data.specif_type != -1){
            return (library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::second) + " + " + library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second));
        }
        else return library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::second);
    }

    std::string divine_truth() const noexcept override { return to_string(library->getDifficulty()); }

    std::string prophecy() const noexcept; //prompt user to inflect

    inline std::string morph() const noexcept {
        if(data.specif_type != -1){
            return library->pick(data.specif_type, data.specif_index, data.specif_mean, vocabSelect::first) + ", " +library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
        }
        else return library->pick(data.obj_type, data.obj_index, data.obj_mean, vocabSelect::first);
    }

    using Origin::success_count;
    using Origin::updateLib;
    using Origin::getDifficulty;
    using ScriptureOfWest::to_string;
};
