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

    double Knapsack::best_case(Item* item){
        return ((double)(this->capacity - this->weight) * item->cost_benefit()) + (double)(this->value);
    }

    bool Knapsack::valid(){
        return this->weight <= this->capacity;
    }

}