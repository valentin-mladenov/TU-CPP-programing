//
// Created by hudson on 3.10.2016 г..
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>

using namespace std;


/// Deck

/*
 * Node Declaration
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
void deck_push_back(int value)
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
void deck_push_start(int value)
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
int deck_pop_back()
{
    if (deck_end == nullptr)
    {
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
int deck_pop_start()
{
    if (deck_start == nullptr) {
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


/// End Deck


/// Double Link List Declaration

/*
 * dl_node Declaration
 */
struct dl_node
{
    int key;
    struct dl_node *next;
    struct dl_node *prev;
} *dl_start,*dl_end;

/*
 * Create Double Link List
 */
void double_list_push_back(int value)
{
    struct dl_node *temp;
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
        dl_end->next = temp;
        temp->prev = dl_end;
    }
    dl_end = temp;
}

/*
 * Insertion at the beginning
 */
void add_before_dl_start(int value)
{
    if (dl_start == nullptr)
    {
        double_list_push_back(value);
        return;
    }
    struct dl_node *temp;
    temp = new(struct dl_node);
    temp->prev = nullptr;
    temp->key = value;
    temp->next = dl_start;
    dl_start->prev = temp;
    dl_start = temp;

    //cout << "Element Inserted" << endl;
}

/*
 * Insertion of element at a particular position
 */
void double_list_add_after(int value, int key)
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
int double_list_pop_start()
{
    if (dl_start == nullptr) {
        cout << "First Create the deck." << endl;
        return -1;
    }

    int out = dl_start->key;

    if (dl_start->next == nullptr){
        dl_end = dl_start->next;
    } else {
        dl_start->next->prev = nullptr;
    }
    dl_start = dl_start->next;

    return out;
}


/// END Double Link List Declaration


/// QuickSort for Double LinkedList

/*
 * A utility function to swap two elements keys
 */
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
 * Considers last element as pivot, places the pivot element at its
 * correct position in sorted array, and places all smaller (smaller than
 * pivot) to left of pivot and all greater elements to right of pivot
 */
dl_node *partition(dl_node *start, dl_node *end)
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
void _quickSort(struct dl_node* start, struct dl_node* end)
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
    _quickSort(dl_start, dl_end);
}

/// END QuickSort for Double LinkedList

/*
 * Load integers from files
 */
void load(string file, string count)
{
    ifstream data;
    string integers;

    data.open("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\QuickSort3OfDeck\\data\\" + file + "_" + count + ".csv");
    while (data.is_open() && !data.eof()) {
        getline (data, integers, '\n');

        if (integers == "") continue;

        stringstream ss(integers);
        string token;

        while(getline(ss, token, ',')) {
            int key = atoi(token.c_str());

            double_list_push_back(key);
        }
    }
    data.close();

    cout << "DONE!";
}

void save_to_file(string file, string count, double elapsed_time){
    stringstream ss, ss_et;
    ofstream data;
    char separator;
    int deck_pop;

    ss_et << "Quick sort finished in: ";
    if (elapsed_time == -1){
        ss_et << " NO DATA (should sort first). For ";
    } else {
        ss_et << (elapsed_time / 1000) << " milliseconds. For ";
    }


    ss_et << file << " with " << count << " elements." << endl;

    while(true){
        deck_pop = deck_pop_start();

        if (deck_pop == -1){
            break;
        }

        ss << separator << deck_pop;
        separator = ',';
    }

    //writhing the sorted Deck
    data.open("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\QuickSort3OfDeck\\sorted\\" + file + "_" + count + "_quickSort.csv");
    data << ss.str();
    data.close();

    //Appending the calculated time for this operation
    data.open("C:\\Users\\hudso\\OneDrive\\Documents\\GitHub\\TU-CPP-programing\\QuickSort3OfDeck\\times\\times_" + file + ".txt", ios_base::app);
    data << ss_et.str();
    data.close();

    cout << "DONE";
}

void send_from_DL_to_Deck() {
    int key;

    //empty the DoublyLinked List and seed to the Deck
    while (dl_start != nullptr) {
        key = double_list_pop_start();
        deck_push_back(key);
    }
    cout << "DONE";
}


int main() {
    int command;
    string fileName, fileCount;
    std::chrono::time_point<std::chrono::system_clock> start_clock, end_clock;
    std::chrono::duration<double, nano> elapsed_seconds;
    double elapsed_result = -1;

    while (true) {
        cout << endl << endl << "   Main Menu" << endl;
        cout << "1 -  GET INTEGERS FROM FILE TO THE DECK AND THE DOUBLE LIST." << endl;
        cout << "2 -  USE QUICK SORT WITH TIMING" << endl;
        cout << "3 -  MOVE SORTED INTEGERS TO THE DECK" << endl;
        cout << "4 -  WRITHE THE RESULT." << endl;
        cout << "5 -  EXIT" << endl;
        cout << "\n\n Chose command (1, 2, 3, 4 or 5): ";
        cin >> command;

        // clear console
        if (system("CLS")) system("clear");

        switch (command) {
            case 1:
                cout << "Type of integer arrays are: Random (rand), Sorted (sort), Reversed (rev), few unique (uniq).\n Type one the strings in (***)." << endl;
                cin >> fileName;

                if (fileName == "rand" || fileName == "uniq") {
                    cout << "Available files with integers. 1000, 5000, 10000, 50000, 100000, 500000. Type one of those digits." << endl;
                } else if (fileName == "rev" || fileName == "sort") {
                    cout << "Available files with integers. 1000, 5000, 10000, 20000, 30000. Type one of those digits." << endl;
                }
                cin >> fileCount;

                load(fileName, fileCount);
                break;
            case 2:
                start_clock = std::chrono::system_clock::now();

                quickSort();

                end_clock = std::chrono::system_clock::now();

                elapsed_seconds = end_clock - start_clock;
                elapsed_result = elapsed_seconds.count();

                elapsed_result = elapsed_result / CLOCKS_PER_SEC;

                cout << "Quick sort finished in: " << elapsed_result/1000 << " milliseconds." << endl;
                break;
            case 3:
                send_from_DL_to_Deck();
                break;
            case 4:
                save_to_file(fileName, fileCount, elapsed_result);
                break;
            case 5:
                return 0;
            default:
                cout << "What are you doing chose from 1, 2, 3, 4, or 5. I****.";
                break;
        }
    }
}
