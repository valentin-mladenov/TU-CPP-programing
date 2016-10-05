//
// Created by hudson on 3.10.2016 г..
//

#include "deck.h"

using namespace std;

/*
 * node Declaration
 */
struct node
{
    int key;
    struct node *next;
    struct node *prev;
} *start, *end;

/*
 * Insertion at the back
 */
void deck::push_back(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->key = value;
    temp->next = nullptr;

    if (start == nullptr) {
        temp->prev = nullptr;
        start = temp;
    } else {
        end->next = temp;
        temp->prev = end;
    }
    end = temp;

    cout << "Element Inserted" << endl;
}

/*
 * Insertion at the beginning
 */
void deck::push_start(int value)
{
    if (start == nullptr)
    {
        deck::push_back(value);
        return;
    }

    struct node *temp;
    temp = new(struct node);
    temp->prev = nullptr;
    temp->key = value;
    temp->next = start;
    start->prev = temp;
    start = temp;

    cout << "Element Inserted" << endl;
}

/*
 * Pop of element at the end
 */
void deck::pop_back(int value)
{
    if (end == nullptr)
    {
        cout << "First Create the deck." << endl;
        return;
    }

    int out = end->key;

    if (end->prev == nullptr){
        start = end->prev;
    } else {
        end->prev->next = nullptr;
    }
    end = end->prev;

    return out;
}

/*
 * Pop of element at the start
 */
int deck::pop_start()
{
    if (start == nullptr) {
        cout << "First Create the deck." << endl;
        return;
    }

    int out = start->key;

    if (start->next == nullptr){
        end = start->next;
    } else {
        start->next->prev = nullptr;
    }
    start = start->next;

    return out;
}
