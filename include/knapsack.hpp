#ifndef KNAPSACK_H
#define KNAPSACK_H

#include"./item.hpp"

namespace KnapsackProblem {
    class Knapsack {
        private:
            float weight = 0.0;
            float value = 0.0;
            int capacity;
        public:
            Knapsack(float weight, float value, int capacity);
            ~Knapsack();

            float get_weight();
            float get_value();
            int get_capacity();
            float best_case(Item* item);
            bool valid();
    };
}

#endif