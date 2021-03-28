#ifndef KNAPSACK_H
#define KNAPSACK_H

#include"./item.hpp"

namespace KnapsackProblem {
    class Knapsack {
        private:
            double weight = 0.0;
            double value = 0.0;
            int capacity;
        public:
            Knapsack(double weight, double value, int capacity);
            ~Knapsack();

            double get_weight();
            double get_value();
            int get_capacity();
            double best_case(Item* item);
            bool valid();
    };
}

#endif