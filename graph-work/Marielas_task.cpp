//
// Created by hudson on 8.3.2016 г..
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

void delete_all_isolated_nodes(node *graph[graphElements]) {
    // first find all that do not have OUTBOUND arcs.
    map<char, int> all_with_none_out;
    for (int i = 0; i < graphElements; i++) {
        if (graph[i] == nullptr) {
            continue;
        }

        if (graph[i]->next == nullptr) {
            all_with_none_out[graph[i]->key] = 1;
            continue;
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
            map<char, int>::iterator node_found = all_with_none_out.find (temp->key);
            if (node_found == all_with_none_out.end()) {
                temp = temp->next;
                continue;
            }

            // if there is only one INCREASE
            if (node_found->second == 1) {
                node_found->second++;
                temp = temp->next;
                continue;
            }

            temp = temp->next;
        }
    }

    for(auto it = all_with_none_out.begin(); it != all_with_none_out.end(); ++it) {
        if (it->second == 1) {
            delete_node(graph, it->first);
            cout << it->first << " ";
        }
    }
}
*/
