#include"../include/knapsack.hpp"

namespace KnapsackProblem {

    Knapsack::Knapsack(int weight, int value, int capacity){
        this->weight = weight;
        this->value = value;
        this->capacity = capacity;
    }

    Knapsack::~Knapsack(){}

    int Knapsack::get_weight(){
        return this->weight;
    }

    int Knapsack::get_value(){
        return this->value;
    }

    int Knapsack::get_capacity(){
        return this->capacity;
    }


}