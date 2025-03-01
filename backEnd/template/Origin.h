#pragma once
#include <iostream>
#include "Library.h"

struct Data {
    size_t obj_type;
    size_t obj_index;
    size_t obj_mean;

    Data() : obj_type(0), obj_index(0), obj_mean(0){};

    Data(size_t obj_type, size_t obj_index, size_t obj_mean)
        : obj_type(obj_type), obj_index(obj_index), obj_mean(obj_mean){};

	~Data() = default;

    friend std::ostream& operator<<(std::ostream& output, const Data& data);
};


struct InflectData :  public Data {
    size_t specif_type;
    size_t specif_index;
    size_t specif_mean;
    size_t format, specif_format;
    bool third_p, formal;


    InflectData() : specif_type(-1), specif_index(-1), specif_mean(-1), specif_format(-1) {};

    InflectData(size_t object_type, size_t object_index, size_t object_mean, size_t format, bool third_p, bool formal, size_t specifier_type = -1, size_t specifier_index = -1, size_t specifer_mean = -1, size_t specifier_format = -1)
        : Data(object_type, object_index, object_mean),
        specif_type(specifier_type), specif_index(specifier_index), specif_mean(specifer_mean), specif_format(specifier_format) {};

    InflectData(Data data): Data(data), specif_type(-1), specif_index(-1), specif_mean(-1), specif_format(-1) {};

    ~InflectData() = default;

    // Reset specifier values to default
    inline void reset_specifier() noexcept {
        specif_type = -1;
        specif_index = -1;
        specif_mean = -1;
        specif_format = -1;
    }

    friend std::ostream& operator<<(std::ostream& output, const InflectData& data);
};

//encapsulation for data that generates sentence
struct SentencerData : public Data {
    size_t sub_type, specif_type;
    size_t sub_index, specif_index;
    size_t sub_mean, specif_mean;
    size_t format, specif_format;
    size_t particle;
    bool formal;
    uint8_t template_type;

    SentencerData() : specif_type(-1), specif_index(-1), specif_mean(-1), specif_format(-1) {}

    SentencerData(size_t subject_type, size_t object_type, size_t subject_index, size_t object_index,
                  size_t subject_mean, size_t object_mean, size_t format_val, size_t particle_val, bool formal, uint8_t template_type,size_t specifier_type = -1, size_t specifier_index = -1 , size_t specifier_meaning = -1, size_t specifier_format = -1)
        : Data(object_type, object_index, object_mean),
        specif_type(specifier_type), specif_index(specifier_index), specif_mean(specifier_meaning), specif_format(specifier_format) {}

    SentencerData(Data data): Data(data), specif_type(-1), specif_index(-1), specif_mean(-1), specif_format(-1){}

    // Reset specifier values to default
    inline void reset_specifier() noexcept {
        specif_type = -1;
        specif_index = -1;
        specif_mean = -1;
        specif_format = -1;
    }

    friend std::ostream& operator<<(std::ostream& output, const SentencerData& data);  //
};


template<typename DataStruct>
class Origin {
protected:
	//encapsulation for data that generates sentence
    DataStruct data;
    std::shared_ptr<Library> library; //shared database of vocabulary

	//track success in row
	int suc_count = 0;
	bool prev_suc = false;

public:
    Origin(std::shared_ptr<Library> lib) : library(lib){};
	Origin() = default;
	~Origin() = default;

    virtual int start() = 0; //generate data to pick random word from vocabulary

    virtual bool compare(const std::string answer) = 0; //compare the word with user input

    //obviously function to ouput backend prompt
    virtual std::string harbinger() const noexcept = 0; //output first vocab to backend

    virtual std::string divine_truth() const noexcept = 0; //output second part to backend

    int success_count() const noexcept { return suc_count; }

    inline void updateLib(const std::shared_ptr<Library> libraro) noexcept { library = libraro;}
    inline int getDifficulty() const noexcept {return library->getDifficulty();}
};


/// Base Data operator
inline std::ostream& operator<<(std::ostream& output, const Data& data) {
    output << "Data{"
           << "obj_type:" << data.obj_type
           << " obj_index:" << data.obj_index
           << " obj_mean:" << data.obj_mean
           << "}";
    return output;
}

// InflectData operator
inline std::ostream& operator<<(std::ostream& output, const InflectData& data) {
    output << static_cast<const Data&>(data)  // Print base class data first
           << " InflectData{"
           << "specif_type:" << data.specif_type
           << " specif_index:" << data.specif_index
           << " specif_mean:" << data.specif_mean
           << " format:" << data.format
           << " specif_format:" << data.specif_format
           << " third_p:" << std::boolalpha << data.third_p
           << " formal:" << data.formal
           << "}";
    return output;
}

// SentencerData operator
inline std::ostream& operator<<(std::ostream& output, const SentencerData& data) {
    output << static_cast<const Data&>(data)  // Print base class data first
           << " SentencerData{"
           << "sub_type:" << data.sub_type
           << " sub_index:" << data.sub_index
           << " sub_mean:" << data.sub_mean
           << " specif_type:" << data.specif_type
           << " specif_index:" << data.specif_index
           << " specif_mean:" << data.specif_mean
           << " format:" << data.format
           << " specif_format:" << data.specif_format
           << " particle:" << data.particle
           << " formal:" << std::boolalpha << data.formal
           << " template_type:" << static_cast<int>(data.template_type)
           << "}";
    return output;
}
