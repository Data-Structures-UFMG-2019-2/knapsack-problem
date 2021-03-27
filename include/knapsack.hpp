#ifndef KNAPSACK_H
#define KNAPSACK_H

namespace KnapsackProblem {
    class Knapsack {
        private:
            int weight = 0;
            int value = 0;
            int capacity;
        public:
            Knapsack(int weight, int value, int capacity);
            ~Knapsack();

            int get_weight();
            int get_value();
            int get_capacity();
    };
}

#endif