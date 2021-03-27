#ifndef ITEM_H
#define ITEM_H

class Item {
    private:
        int id;
        int value;
        int weight;

    public:
        Item(int id, int vaule, int weight);
        ~Item();
        int get_id();
        int get_value();
        int get_weight();
};

#endif