//
// Created by hudson on 3.10.2016 г..
//

#ifndef QUICKSORT3OFDECK_DECK_H
#define QUICKSORT3OFDECK_DECK_H

/*
 Class Declaration
 */
class deck
{
public:
    void push_start(int value);
    void push_back(int value);
    int pop_back(int value);
    int pop_start(int value);
    deck()
    {
        struct node *start = nullptr;
        struct node *end = nullptr;
    }
};

#endif //QUICKSORT3OFDECK_DECK_H
