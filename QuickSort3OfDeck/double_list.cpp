//
// Created by hudson on 3.10.2016 г..
//

#include "double_list.h"

/*
 * Node Declaration
 */
struct node
{
    int key;
    struct node *next;
    struct node *prev;
}*start;

/*
 Class Declaration
 */
class double_list
{
public:
    void create_list(int value);
    void add_before_start(int value);
    void add_after(int value, int position);
//    void delete_element(int value);
//    void search_element(int value);
//    void display_dlist();
//    void count();
//    void reverse();
    double_list()
    {
        start = nullptr;
    }
};

/*
 * Create Double Link List
 */
void double_list::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node);
    temp->key = value;
    temp->next = nullptr;
    if (start == nullptr)
    {
        temp->prev = nullptr;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != nullptr)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

/*
 * Insertion at the beginning
 */
void double_list::add_before_start(int value)
{
    if (start == nullptr)
    {
        cout << "First Create the list." << endl;
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
 * Insertion of element at a particular position
 */
void double_list::add_after(int value, int pos)
{
    if (start == nullptr)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == nullptr)
        {
            cout<<"There are less than ";
            cout << pos << " elements." << endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->key = value;
    if (q->next == nullptr)
    {
        q->next = tmp;
        tmp->next = nullptr;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout << "Element Inserted" << endl;
}
