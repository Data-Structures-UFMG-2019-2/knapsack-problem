#ifndef KNAPSACK_H
#define KNAPSACK_H

#include<vector>

#include"./item.hpp"

class Knapsack {
    private:
        std::vector<Item*> items;
        int weight = 0;
        int value = 0;
    public:
        Knapsack(std::vector<Item*> items, int weight, int value);
        Knapsack();
        ~Knapsack();
};

#endif