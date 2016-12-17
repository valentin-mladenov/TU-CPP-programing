//
// Created by hudson on 17.12.2016 г.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>

using namespace std;
/// Queue

/*
 * Node Declaration
 */
struct node
{
    int key;
    struct node *next;
    struct node *prev;
} *queue_start, *queue_end;

/*
 * Insertion at the beginning
 */
void queue_push(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->prev = nullptr;
    temp->key = value;

    if (queue_start == nullptr)
    {
        temp->next = nullptr;
        queue_start = queue_end = temp;
        return;
    }

    temp->next = queue_start;
    queue_start->prev = temp;
    queue_start = temp;
}

/*
 * Pop of element at the end
 */
int queue_pop()
{
    if (queue_end == nullptr)
    {
        return -1;
    }

    int out = queue_end->key;

    if (queue_end->prev == nullptr){
        queue_start = queue_end->prev;
    } else {
        queue_end->prev->next = nullptr;
    }
    queue_end = queue_end->prev;

    return out;
}


/// End Queue


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
        cout << "First Create the queue." << endl;
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

/*
 * Pop of element at the start
 */
int double_list_pop_end()
{
    if (dl_end == nullptr) {
        cout << "First Create the queue." << endl;
        return -1;
    }

    int out = dl_end->key;

    if (dl_end->prev == nullptr){
        dl_start = dl_end->prev;
    } else {
        dl_end->prev->next = nullptr;
    }
    dl_end = dl_end->prev;

    return out;
}

/// END Double Link List Declaration


/// START InsertionSort for Double LinkedList

/*
 * A utility function to swap two elements keys
 */
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void _insertionSort (struct dl_node *start){
    struct dl_node
            *forward,
            *backward;

    forward = start;

    while (forward->next != nullptr) {
        backward = forward;

        while (backward->prev != nullptr && backward->key < backward->prev->key) {
            swap(&(backward->key), &(backward->prev->key));

            backward = backward->prev;
        }

        forward = forward->next;
    }
}

/*
 * The main function to sort a linked list. It mainly calls _insertionSort()
 */
void insertionSort()
{
    _insertionSort(dl_start);
}

/// END InsertionSort for Double LinkedList

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
    int queue_pop;

    ss_et << "Quick sort finished in: ";
    if (elapsed_time == -1){
        ss_et << " NO DATA (should sort first). For ";
    } else {
        ss_et << (elapsed_time / 1000) << " milliseconds. For ";
    }


    ss_et << file << " with " << count << " elements." << endl;

    while(true){
        queue_pop = queue_pop();

        if (queue_pop == -1){
            break;
        }

        ss << separator << queue_pop;
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

void send_from_DL_to_Queue() {
    int key;

    //empty the DoublyLinked List and seed to the Queue
    while (dl_start != nullptr) {
        key = double_list_pop_start();
        queue_push(key);
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
        cout << "1 -  GET INTEGERS FROM FILE TO THE QUEUE AND THE DOUBLE LIST." << endl;
        cout << "2 -  USE QUICK SORT WITH TIMING" << endl;
        cout << "3 -  MOVE SORTED INTEGERS TO THE QUEUE" << endl;
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

                insertionSort();

                end_clock = std::chrono::system_clock::now();

                elapsed_seconds = end_clock - start_clock;
                elapsed_result = elapsed_seconds.count();

                elapsed_result = elapsed_result / CLOCKS_PER_SEC;

                cout << "Quick sort finished in: " << elapsed_result/1000 << " milliseconds." << endl;
                break;
            case 3:
                send_from_DL_to_Queue();
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
