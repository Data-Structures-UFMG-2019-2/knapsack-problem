#include<stack>
#include<vector>
#include<iostream>

#include"../include/knapsack-problem.hpp"
#include"../include/knapsack.hpp"

namespace KnapsackProblem {

    Knapsack* backtrack(Knapsack* knapsack, std::stack<Item*> items, int w_max){
        Knapsack* wout_knapsack = new Knapsack(knapsack->get_weight(), knapsack->get_value(), w_max);
        if(items.empty()){
            return wout_knapsack;
        }

        Item* next_item = items.top();
        items.pop();
        int with_weight = (knapsack->get_weight() + next_item->get_weight());
        int with_value = (knapsack->get_value() + next_item->get_value());
        Knapsack* with_knapsack = new Knapsack(with_weight, with_value, w_max);
        delete knapsack;
        

        if(with_knapsack->get_weight() <= w_max){
            Knapsack* with_result = backtrack(with_knapsack, items, w_max);
            Knapsack* wout_result = backtrack(wout_knapsack, items, w_max);

            if(with_result->get_value() > wout_result->get_value()){
                delete wout_result;
                return with_result;
            }
            else{
                delete with_result;
                return wout_result;
            }
        }
        else{
            Knapsack* result = backtrack(wout_knapsack, items, w_max);
            delete with_knapsack;
            return result;
        }
    }
    
    void backtracking(std::stack<Item*> items, int w_max){
        Knapsack* result = backtrack(new Knapsack(0, 0, w_max), items, w_max);
        std::cout << "Reached optimal value " << result->get_value() << " with weight " << result->get_weight() << "\n";
        delete result; 
    }

    // void breach_and_bound(std::stack<Item*> items){

    // }


};