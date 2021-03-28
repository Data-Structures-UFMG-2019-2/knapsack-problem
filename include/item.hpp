#ifndef ITEM_H
#define ITEM_H

namespace KnapsackProblem {
    class Item {
        private:
            int id;
            double value;
            double weight;

        public:
            Item(int id, double vaule, double weight);
            ~Item();
            int get_id();
            double get_value();
            double get_weight();
            double cost_benefit();
    };
}

#endif