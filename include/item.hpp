#ifndef ITEM_H
#define ITEM_H

namespace KnapsackProblem {
    class Item {
        private:
            int id;
            float value;
            float weight;

        public:
            Item(int id, float vaule, float weight);
            ~Item();
            int get_id();
            float get_value();
            float get_weight();
            float cost_benefit();
    };
}

#endif