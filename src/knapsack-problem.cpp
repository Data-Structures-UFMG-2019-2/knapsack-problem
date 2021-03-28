#include<stack>
#include<vector>
#include<iostream>
#include<queue>

#include"../include/knapsack-problem.hpp"
#include"../include/knapsack.hpp"

namespace KnapsackProblem {

    Knapsack* backtracking(Knapsack* knapsack, std::stack<Item*> items, int w_max){
        Knapsack* wout_knapsack = new Knapsack(knapsack->get_weight(), knapsack->get_value(), w_max);
        if(items.empty()){
            delete knapsack;
            return wout_knapsack;
        }

        Item* next_item = items.top();
        items.pop();
        float with_weight = knapsack->get_weight() + next_item->get_weight();
        float with_value = knapsack->get_value() + next_item->get_value();
        Knapsack* with_knapsack = new Knapsack(with_weight, with_value, w_max);
        delete knapsack;

        if(with_knapsack->get_weight() <= w_max){
            Knapsack* with_result = backtracking(with_knapsack, items, w_max);
            Knapsack* wout_result = backtracking(wout_knapsack, items, w_max);

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
            Knapsack* result = backtracking(wout_knapsack, items, w_max);
            delete with_knapsack;
            return result;
        }
    }

    Knapsack* breach_and_bound(Knapsack* knapsack, std::stack<Item*> items, int w_max, float best_value){
        if(items.empty()){
            return knapsack;
        }

        Knapsack* best_result = knapsack;
        Knapsack* wout_knapsack = new Knapsack(knapsack->get_weight(), knapsack->get_value(), w_max);
        Item* next_item = items.top();
        items.pop();
        float with_weight = (knapsack->get_weight() + next_item->get_weight());
        float with_value = (knapsack->get_value() + next_item->get_value());
        Knapsack* with_knapsack = new Knapsack(with_weight, with_value, w_max);

        if(items.empty()){
            if(wout_knapsack->get_value() > with_knapsack->get_value() || with_knapsack->get_weight() > w_max){
                delete knapsack;
                delete with_knapsack;
                return wout_knapsack;
            }
            else {
                delete knapsack;
                delete wout_knapsack;
                return with_knapsack;
            }
        }

        std::queue<Knapsack*> queue;
        if(with_knapsack->best_case(items.top()) > wout_knapsack->best_case(items.top())){
            if(with_knapsack->valid()) {
                queue.push(with_knapsack);
            }
            else {
                delete with_knapsack;
            }
            if(wout_knapsack->valid()) {
                queue.push(wout_knapsack);
            }
            else{
                delete wout_knapsack;
            }
        }
        else{
            if(wout_knapsack->valid()) {
                queue.push(wout_knapsack);
            }
            else{
                delete wout_knapsack;
            }
            if(with_knapsack->valid()) {
                queue.push(with_knapsack);
            }
            else {
                delete with_knapsack;
            }
        }

        while(!queue.empty()){
            Knapsack* next_knapsack = queue.front();
            queue.pop();
            if(next_knapsack->best_case(items.top()) > best_value){
                Knapsack* result = breach_and_bound(next_knapsack, items, w_max, best_value);
                if(result->get_value() > best_value){
                    best_value = result->get_value();
                    delete best_result;
                    best_result = result;
                }
                else{
                    delete result;
                }
            }
            else {
                delete next_knapsack;
            }
        }

        return best_result;
    }
    
    float backtracking_solve(std::stack<Item*> items, int w_max){
        Knapsack* result = backtracking(new Knapsack(0.0, 0.0, w_max), items, w_max);
        // std::cout << "Reached optimal value " << result->get_value() << " with weight " << result->get_weight() << "\n";
        float solution = result->get_value();
        delete result;
        return solution;
    }

    float breach_and_bound_solve(std::stack<Item*> items, int w_max){
        Knapsack* result = new Knapsack(0.0, 0.0, w_max);
        result = breach_and_bound(result, items, w_max, 0.0);
        // std::cout << "Reached optimal value " << result->get_value() << " with weight " << result->get_weight() << "\n";
        float solution = result->get_value();
        delete result;
        return solution;
    }


};