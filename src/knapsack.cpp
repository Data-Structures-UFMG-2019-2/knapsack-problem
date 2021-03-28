#include"../include/knapsack.hpp"

namespace KnapsackProblem {

    Knapsack::Knapsack(double weight, double value, int capacity){
        this->weight = weight;
        this->value = value;
        this->capacity = capacity;
    }

    Knapsack::~Knapsack(){}

    double Knapsack::get_weight(){
        return this->weight;
    }

    double Knapsack::get_value(){
        return this->value;
    }

    int Knapsack::get_capacity(){
        return this->capacity;
    }

    double Knapsack::best_case(Item* item){
        return ((this->capacity - this->weight) * item->cost_benefit()) + this->value;
    }

    bool Knapsack::valid(){
        return this->weight <= this->capacity;
    }

}