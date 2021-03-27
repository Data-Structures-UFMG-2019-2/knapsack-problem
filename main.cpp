#include<iostream>
#include<fstream>
#include<stack>

#include"./include/item.hpp"

std::stack<Item*> read_input(char const* input_path){
    std::ifstream input(input_path);
    std::stack<Item*> items;

    int n, w_max;

    if(input >> n >> w_max){
        int v, w;
        for(int i = 0; (i < n && input >> v >> w); i++){
            items.push(new Item(i, v, w));
        }
    }

    return items;
}

int main(int argc, char const *argv[]){
    if(argc < 2){
        std::cout << "Not enough arguments\n";
        return 1;
    }

    std::stack<Item*> items = read_input(argv[1]);

    while(!items.empty()){
        Item* item = items.top();
        items.pop();
        delete item;
    }

    return 0;
}
