//
// Created by hudson on 3.10.2016 г..
//

#include "double_list.h"

using namespace std;

/*
 * dl_node Declaration
 */
struct dl_node
{
    int key;
    struct dl_node *next;
    struct dl_node *prev;
} *dl_start;

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

/*
 * Create Double Link List
 */
void push_back(int value)
{
    struct dl_node *s, *temp;
    temp = new(struct dl_node);
    temp->key = value;
    temp->next = nullptr;
    if (dl_start == nullptr)
    {
        temp->prev = nullptr;
        dl_start = temp;
    }
    else
    {
        s = dl_start;
        while (s->next != nullptr)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
    cout << "Element Inserted" << endl;
}

/*
 * Insertion at the beginning
 */
void add_before_dl_start(int value)
{
    if (dl_start == nullptr)
    {
        push_back(value);
        return;
    }
    struct dl_node *temp;
    temp = new(struct dl_node);
    temp->prev = nullptr;
    temp->key = value;
    temp->next = dl_start;
    dl_start->prev = temp;
    dl_start = temp;

    cout << "Element Inserted" << endl;
}

/*
 * Insertion of element at a particular position
 */
void add_after(int value, int key)
{
    if (dl_start == nullptr)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct dl_node *tmp, *q;
    q = dl_start;
    tmp = new(struct dl_node);
    tmp->key = value;

    while (q->next != nullptr)
    {
        if (q->key == key)
        {
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
            return;
        }
        q = q->next;
    }

    q->next = tmp;
    tmp->next = nullptr;
    tmp->prev = q;
    cout << "Element Inserted" << endl;
}

/*
 * Pop of element at the start
 */
int pop_start()
{
    if (dl_start == nullptr) {
        cout << "First Create the deck." << endl;
        return;
    }

    int out = dl_start->key;
    start = start->next;

    return out;
}

/*
 * Find the last node of the Double Linked List
 */
struct dl_node *find_last_node()
{

    if (dl_start == nullptr)
    {
        cout << "First Create the list." << endl;
        return;
    }

    struct dl_node *result;

    result = dl_start;

    while (result->next != nullptr) {
        result = result->next;
    }

    return result;
}

/*
 * A utility function to swap two elements keys
 */
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
 * Returns the start node.
 */
struct dl_node *get_start(){
    return dl_start;
}

/*
 * Considers last element as pivot, places the pivot element at its
 * correct position in sorted array, and places all smaller (smaller than
 * pivot) to left of pivot and all greater elements to right of pivot
 */
dl_node* partition(dl_node *start, dl_node *end)
{
    // set pivot as end element
    int x  = end->key;

    // similar to i = start - 1 for array implementation
    dl_node *i = start->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (dl_node *j = start; j != end; j = j->next)
    {
        if (j->key <= x)
        {
            // Similar to i++ for array
            i = (i == nullptr) ? start : i->next;

            swap(&(i->key), &(j->key));
        }
    }
    i = (i == nullptr)? start : i->next; // Similar to i++ cycle trough the list
    swap(&(i->key), &(end->key));
    return i;
}

/*
 * A recursive implementation of quick sort for linked list
 */
void _quickSort(struct dl_node* start, struct dl_node *end)
{
    if (end != nullptr && start != end && start != end->next)
    {
        struct dl_node *p = partition(start, end);
        _quickSort(start, p->prev);
        _quickSort(p->next, end);
    }
}

// The main function to sort a linked list. It mainly calls _quickSort()
void quickSort()
{
    struct dl_node *end = find_last_node();

    _quickSort(start, end);
}
