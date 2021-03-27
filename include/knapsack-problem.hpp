#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include<stack>

#include"./item.hpp"

namespace KnapsackProblem {
    
    void backtracking(std::stack<Item*> items, int w_max);
    void breach_and_bound(std::stack<Item*> items, int w_max);

};


#endif