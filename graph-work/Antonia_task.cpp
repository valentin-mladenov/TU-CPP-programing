//
// Created by hudson on 6.3.2016 г..
//

/*
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int graphElements = 5;
struct node {
    char key;
    node *next;
} *graph[graphElements];

void two_arc_out_and_none_in (node *graph[graphElements]) {
    // first find all that have ONlY two arc OUT.
    map<char, int> all_with_two_out;
    for (int i = 0; i < graphElements; i++) {
        if (graph[i] == nullptr) {
            continue;
        }

        if (graph[i]->next == nullptr) {
            continue;
        }

        if (graph[i]->next->next == nullptr) {
            continue;
        }

        if (graph[i]->next->next->next == nullptr) {
            //all_with_one_out[i] = graph[i]->key;
            all_with_two_out[graph[i]->key] = 1;
        }
    }

    // now lets check how many have incoming arcs.
    for (int i = 0; i < graphElements; i++) {
        node *temp;
        if (graph[i] == nullptr){
            continue;
        }
        temp = graph[i]->next;

        while (temp != nullptr) {
            map<char, int>::iterator node_found = all_with_two_out.find (temp->key);
            if (node_found == all_with_two_out.end()) {
                temp = temp->next;
                continue;
            }

            // if it is equal to 1 then that is the first ocurance
            if (node_found->second <= 1) {
                node_found->second++;
                temp = temp->next;
                continue;
            }

            // if we have second occurance the node data is deleted.
            all_with_two_out.erase(node_found);
            temp = temp->next;
        }
    }

    // finaly print it all
    for(auto it = all_with_two_out.begin(); it != all_with_two_out.end(); ++it) {
        cout << it->first << " ";
    }
}
*/
