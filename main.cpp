#include<iostream>
#include<fstream>
#include<stack>

#include"./include/item.hpp"
#include"./include/knapsack-problem.hpp"

std::stack<KnapsackProblem::Item*> read_input(std::ifstream &input, int n){
    std::stack<KnapsackProblem::Item*> items;
    int v, w;

    for(int i = 0; (i < n && input >> v >> w); i++){
        items.push(new KnapsackProblem::Item(i, v, w));
    }

    return items;
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

    KnapsackProblem::backtracking(items, w_max);

    while(!items.empty()){
        KnapsackProblem::Item* item = items.top();
        items.pop();
        delete item;
    }

    return 0;
}
