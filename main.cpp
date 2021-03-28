#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<chrono>

#include"./include/item.hpp"
#include"./include/knapsack-problem.hpp"

#define OUTPUT_PATH "./output/result.csv"

bool compare_cost_benefit(KnapsackProblem::Item* a, KnapsackProblem::Item* b){
    return a->cost_benefit() < b->cost_benefit();
}

std::string test_name(char const* path){
    std::string path_str(path);
    size_t slice_index = path_str.find_last_of("/");
    if (slice_index == std::string::npos){
        return path_str;
    }
    else{
        return path_str.substr(slice_index + 1, path_str.length() - (slice_index + 1));
    }
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

    std::ofstream output(OUTPUT_PATH);
    output << "Teste; Aluno; Backtracking; Breach and bound; Solução";

    for(int i = 1; i < argc; i++){
        std::ifstream input(argv[i]);
        if(!input.is_open()) continue;
        int n, w_max, backtracking_time, bnb_time;
        float backtracking_solution, bnb_solution;
        input >> n >> w_max;
        std::stack<KnapsackProblem::Item*> items = read_input(input, n);
        input.close();

        auto backtracking_start_time = std::chrono::high_resolution_clock::now();
        backtracking_solution = KnapsackProblem::backtracking_solve(items, w_max);
        auto backtracking_end_time = std::chrono::high_resolution_clock::now();
        backtracking_time = std::chrono::duration_cast<std::chrono::microseconds>(backtracking_end_time - backtracking_start_time).count();
        
        auto bnb_start_time = std::chrono::high_resolution_clock::now();
        bnb_solution = KnapsackProblem::breach_and_bound_solve(items, w_max);
        auto bnb_end_time = std::chrono::high_resolution_clock::now();
        bnb_time = std::chrono::duration_cast<std::chrono::microseconds>(bnb_end_time - bnb_start_time).count();

        if(backtracking_solution == bnb_solution){
            std::cout << i << ": reached optimal value " << bnb_solution << "\n";
            output << "\n\"" << test_name(argv[i]) << "\"; \"Luiz Philippe Pereira\"; " << backtracking_time << "; " << bnb_time << "; " << bnb_solution;
        }
        else{
            std::cout << i << ": error => solutions do not agree\n";
        }

        while(!items.empty()){
            KnapsackProblem::Item* item = items.top();
            items.pop();
            delete item;
        }
    }

    output.close();

    return 0;
}
