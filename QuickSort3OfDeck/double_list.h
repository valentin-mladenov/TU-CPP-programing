//
// Created by hudson on 3.10.2016 г..
//

#ifndef QUICKSORT3OFDECK_DOUBLE_LIST_H
#define QUICKSORT3OFDECK_DOUBLE_LIST_H

/*
 Class Declaration
 */
class double_list
{
public:
    struct dl_node;
    void push_back(int value);
    void add_before_start(int value);
    void add_after(int value, int position);
    int pop_start();
    struct dl_node *find_last_node();
    void swap(int *a, int *b);
    struct dl_node *get_start();
    void quickSort();
    double_list()
    {
        struct dl_node *dl_start = nullptr;
    }
};

#endif //QUICKSORT3OFDECK_DOUBLE_LIST_H
