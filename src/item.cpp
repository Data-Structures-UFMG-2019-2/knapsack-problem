#include"../include/item.hpp"

namespace KnapsackProblem {

    Item::Item(int id, double value, double weight){
        this->id = id;
        this->value = value;
        this->weight = weight;
    }

    Item::~Item(){}

    int Item::get_id(){
        return this->id;
    }

    double Item::get_value(){
        return this->value;
    }

    double Item::get_weight(){
        return this->weight;
    }

    double Item::cost_benefit(){
        return this->value / this->weight;
    }

}
