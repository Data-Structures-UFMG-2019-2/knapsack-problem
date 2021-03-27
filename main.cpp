#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<algorithm>

#include"./include/item.hpp"
#include"./include/knapsack-problem.hpp"

bool compare_cost_benefit(KnapsackProblem::Item* a, KnapsackProblem::Item* b){
    return a->cost_benefit() < b->cost_benefit();
}

std::stack<KnapsackProblem::Item*> read_input(std::ifstream &input, int n){
    std::vector<KnapsackProblem::Item*> item_vector;
    std::stack<KnapsackProblem::Item*> item_stack;
    int v, w;

    for(int i = 0; (i < n && input >> v >> w); i++){
        item_vector.push_back(new KnapsackProblem::Item(i, v, w));
    }

    std::sort(item_vector.begin(), item_vector.end(), compare_cost_benefit);
    // std::cout << "[";
    for(std::vector<KnapsackProblem::Item*>::iterator it = item_vector.begin(); it != item_vector.end(); ++it){
        KnapsackProblem::Item* item = *it;
        // std::cout << item->cost_benefit() << ", ";
        item_stack.push(item);
    }
    // std::cout << "\b\b]\n";

    return item_stack;
}

int main(int argc, char const *argv[]){
    if(argc < 2){
        std::cout << "Not enough arguments\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    int n, w_max;
    input >> n >> w_max;
    std::stack<KnapsackProblem::Item*> items = read_input(input, n);

    KnapsackProblem::backtracking_solve(items, w_max);
    KnapsackProblem::breach_and_bound_solve(items, w_max);

    while(!items.empty()){
        KnapsackProblem::Item* item = items.top();
        items.pop();
        delete item;
    }

    return 0;
}
