//
// Created by hudso on 4.10.2016 г..
//

#include "double_list.h"
#include "quick_sort_3.h"

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */

//It uses Dutch National Flag Algorithm
void partition3DuchNationalFlag(dl_node* start, dl_node* end, dl_node* &i, dl_node* &j)
{
    // To handle 2 elements
    if (start->next == end)
    {
        if (end->key < start->key)
            swap(&end->key, &start->key);
        i = start;
        j = end;
        return;
    }

    dl_node* mid = start;
    int pivot = end->key;
    while (mid->next != end)
    {
        if (mid->key < pivot)
            swap(&start->next->key, &mid->next->key);
        else if (mid->key == pivot)
            mid == mid->next;
        else if (mid->key > pivot)
            swap(&mid->key, &end->prev->key);
    }

    //update i and j
    i = start->prev;
    j = mid; //or high-1
}

//void partition3(int a[], int l, int r, int &i, int &j)
void partition3(dl_node* start, dl_node* end, dl_node* &i, dl_node* &j)
{
    i = start->prev, j = end;
    dl_node* p = start->prev,;
    dl_node* q = end;
    int v = end->key;

    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        if (i == nullptr){
            i = start;
        }
        while (i->key < v) {
            i = i->next;
        }

        // From right, find the first element smaller than or
        // equal to v
        j = j->prev;
        while (v < j->key) {
            if (j->prev == start) {
                break;
            }
            j = j->prev;
        }
        // If i and j cross, then we are done
        if (i->key >= v && j->key <= v) break;

        // Swap, so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}

// 3-way partition based quick sort
void _quickSort3(dl_node* start, dl_node* end)
{
    if (start == nullptr) return;
    if (start == end) return;

    dl_node* i;
    dl_node* j;

    // Note that i and j are passed as reference
    partition3(start, end, i, j);

    // Recur
    _quickSort3(start, i);
    _quickSort3(j, end);
}

// The main function to sort a linked list. It mainly calls _quickSort()
void quickSort3()
{
    _quickSort3(dl_start, dl_end);
}
