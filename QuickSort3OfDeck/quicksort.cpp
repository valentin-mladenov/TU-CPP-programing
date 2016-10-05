//
// Created by hudson on 4.10.2016 г..
//

#include "quicksort.h"
#include "double_list.h"

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
void quickSort(double_list *doubleList)
{
    struct dl_node *end = doubleList->find_last_node(),
                   *start = doubleList->get_start();

    _quickSort(start, end);
}
