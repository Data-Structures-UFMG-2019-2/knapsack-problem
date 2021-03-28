#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include<stack>

#include"./item.hpp"

namespace KnapsackProblem {
    
    double backtracking_solve(std::stack<Item*> items, int w_max);
    double breach_and_bound_solve(std::stack<Item*> items, int w_max);

};


#endif