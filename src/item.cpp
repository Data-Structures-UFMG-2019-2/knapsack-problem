#include"../include/item.hpp"

namespace KnapsackProblem {

    Item::Item(int id, float value, float weight){
        this->id = id;
        this->value = value;
        this->weight = weight;
    }

    Item::~Item(){}

    int Item::get_id(){
        return this->id;
    }

    float Item::get_value(){
        return this->value;
    }

    float Item::get_weight(){
        return this->weight;
    }

    float Item::cost_benefit(){
        return this->value / this->weight;
    }

}
