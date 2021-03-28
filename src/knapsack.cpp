#include"../include/knapsack.hpp"

namespace KnapsackProblem {

    Knapsack::Knapsack(float weight, float value, int capacity){
        this->weight = weight;
        this->value = value;
        this->capacity = capacity;
    }

    Knapsack::~Knapsack(){}

    float Knapsack::get_weight(){
        return this->weight;
    }

    float Knapsack::get_value(){
        return this->value;
    }

    int Knapsack::get_capacity(){
        return this->capacity;
    }

    float Knapsack::best_case(Item* item){
        return ((this->capacity - this->weight) * item->cost_benefit()) + this->value;
    }

    bool Knapsack::valid(){
        return this->weight <= this->capacity;
    }

}