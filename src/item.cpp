#include"../include/item.hpp"

namespace KnapsackProblem {

    Item::Item(int id, int value, int weight){
        this->id = id;
        this->value = value;
        this->weight = weight;
    }

    Item::~Item(){}

    int Item::get_id(){
        return this->id;
    }

    int Item::get_value(){
        return this->value;
    }

    int Item::get_weight(){
        return this->weight;
    }

    double Item::cost_benefit(){
        return (double)((double)this->value/(double)this->weight);
    }

}
