#include"../include/knapsack.hpp"
#include<vector>

Knapsack::Knapsack(std::vector<Item*> items, int weight, int value){
    this->items = items;
    this->weight = weight;
    this->value = value;
}

Knapsack::Knapsack(){}

Knapsack::~Knapsack(){}