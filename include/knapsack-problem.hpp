#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include<stack>

#include"./item.hpp"

namespace KnapsackProblem {
    
    float backtracking_solve(std::stack<Item*> items, int w_max);
    float breach_and_bound_solve(std::stack<Item*> items, int w_max);

};


#endif