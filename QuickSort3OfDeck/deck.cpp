//
// Created by hudson on 3.10.2016 г..
//
#include <iostream>
#include "deck.h"

/*
 * node Declaration
 */
struct node
{
    int key;
    struct node *next;
    struct node *prev;
} *deck_start, *deck_end;

/*
 * Insertion at the back
 */
void Deck::push_back(int value)
{
    node *temp;
    temp = new(struct node);
    temp->key = value;
    temp->next = nullptr;

    if (deck_start == nullptr) {
        temp->prev = nullptr;
        deck_start = temp;
    } else {
        deck_end->next = temp;
        temp->prev = deck_end;
    }
    deck_end = temp;
}

/*
 * Insertion at the beginning
 */
void Deck::push_start(int value)
{
    if (deck_start == nullptr)
    {
        deck_push_back(value);
        return;
    }

    struct node *temp;
    temp = new(struct node);
    temp->prev = nullptr;
    temp->key = value;
    temp->next = deck_start;
    deck_start->prev = temp;
    deck_start = temp;
}

/*
 * Pop of element at the end
 */
int Deck::pop_back()
{
    if (deck_end == nullptr)
    {
        cout << "First Create the deck." << endl;
        return -1;
    }

    int out = deck_end->key;

    if (deck_end->prev == nullptr){
        deck_start = deck_end->prev;
    } else {
        deck_end->prev->next = nullptr;
    }
    deck_end = deck_end->prev;

    return out;
}

/*
 * Pop of element at the start
 */
int Deck::pop_start()
{
    if (deck_start == nullptr) {
        cout << "First Create the deck." << endl;
        return -1;
    }

    int out = deck_start->key;

    if (deck_start->next == nullptr){
        deck_end = deck_start->next;
    } else {
        deck_start->next->prev = nullptr;
    }
    deck_start = deck_start->next;

    return out;
}
