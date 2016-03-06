#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
 * testing some github integration
 */

const int graphElements = 5;
struct node {
    char key;
    node *next;
} *graph[graphElements];

void init(node *graph[graphElements]){
    for (int i = 0; i < graphElements; ++i) {
        graph[i] = nullptr;
    }
}

/*
 * Mine function returns the node key in the array of nodes or -1 if not found
 * Also cycle trough all nodes even they are NULL.
 */
int search_for_node (node *graph[graphElements], char key){
    for (int i = 0; i < graphElements; ++i) {
        if (graph[i] != nullptr && graph[i]->key == key) {
            return i;
        }
    }

    return -1;
}

bool search_for_arc (node *graph[graphElements], char fromNode, char toNode){
    int positionFromNode = search_for_node(graph, fromNode);
    int positionToNode = search_for_node(graph, toNode);

    if (positionFromNode != -1 && positionToNode != -1) {
        node *nextNode = graph[positionFromNode];

        while (nextNode->key != toNode && nextNode->next != nullptr){
            nextNode = nextNode->next;
        }

        if (nextNode->key == toNode) {
            return true;
        }
    }

    return false;
}

void add_node (node *graph[graphElements], char key){
    int position_of_key = search_for_node(graph, key);

    if(position_of_key != -1){
        cout << endl << "Existing node!" << endl;
    }

    for (int i = 0; i < graphElements; ++i) {
        if (graph[i] == nullptr){
            graph[i] = new node;
            graph[i]->key = key;
            graph[i]->next = nullptr;
            return;
        }
    }

    cout << endl << "Overflow" << endl;
}

void add_arc (node *graph[graphElements], char fromNode, char toNode) {
    if (search_for_arc (graph, fromNode, toNode)) {
        cout << endl << "Existing arc!" << endl;
        return;
    }

    int positionFromNode = search_for_node (graph, fromNode);
    if (positionFromNode == -1) {
        add_node (graph, fromNode);
    }

    int positionToNode = search_for_node (graph, toNode);
    if (positionToNode == -1) {
        add_node (graph, toNode);
    }

    for (int i = 0; i < graphElements; ++i) {
        if (graph[i]->key == fromNode) {
            node *new_arc = new node;
            new_arc->key = toNode;
            new_arc->next = graph[i]->next;
            graph[i]->next = new_arc;
            return;
        }
    }
}

void delete_node (node *graph[graphElements], char node_to_del) {
    int position_of_node = search_for_node (graph, node_to_del);
    if (position_of_node != -1) {
        node *to_del_node, *to_del_arcs;

        while (graph[position_of_node] != nullptr) {
            to_del_arcs = graph[position_of_node];
            graph[position_of_node] = graph[position_of_node]->next;
            delete to_del_arcs;
        }

        for (int i = 0; i < graphElements; ++i) {
            if (graph[i] != nullptr) {
                to_del_node = graph[i];
                while (to_del_node->next != nullptr) {
                    to_del_arcs = to_del_node;
                    to_del_node = to_del_node->next;

                    if (to_del_node->key == node_to_del) {
                        to_del_arcs->next = to_del_node->next;
                        delete to_del_node;
                        break;
                    }
                }
            }
        }

        return;
    }

    cout << "Node, not in the graph" << endl;
}

void delete_arc (node *graph[graphElements], char node_from, char node_to) {
    if (search_for_arc (graph, node_from, node_to)) {
        int position_from_node = search_for_node (graph, node_from);
        if (position_from_node > -1) {
            node *from_node = graph[position_from_node], *to_node = graph[position_from_node];

            while (to_node->key != node_to) {
                from_node = to_node;
                to_node = to_node->next;
            }

            from_node->next = to_node->next;
            delete to_node;
            return;
        }
    }

    cout << "Arc, not in the graph" << endl;
}

void list_nodes (node *graph[graphElements]) {
    cout << endl;

    for (int i = 0; i < graphElements; i++) {
        if (graph[i] != nullptr) {
            cout << graph[i]->key << " ";
        }
    }
}

int main() {
    init(graph);

    char key_from, key_to, node_key;
    int command;

    while (true) {
        cout << endl << endl << "Main Menu" << endl;
        cout << "1 -  ADD NODE" << endl;
        cout << "2 -  ADD ARC" << endl;
        cout << "3 -  DELETE NODE" << endl;
        cout << "4 -  DELETE ARC" << endl;
        cout << "5 -  SEARCH NODE" << endl;
        cout << "6 -  SEARCH ARC" << endl;
        cout << "7 -  PRINT ALL" << endl;
        cout << "8 -  TASK EXECUTION" << endl;
        cout << "9 -  EXIT" << endl;
        cout << "\n\n Chose command (1-9): ";
        cin >> command;

        switch (command) {
            case 1:
                cout << "Enter node (char): ";
                cin >> node_key;

                add_node (graph, node_key);
                break;
            case 2:
                cout << "Enter FROM node  ";
                cin >> key_from;
                cout << " TO node ";
                cin >> key_to;

                add_arc (graph, key_from, key_to);
                break;
            case 3:
                cout << "DELETE node (char): ";
                cin >> node_key;

                delete_node (graph, node_key);
                break;
            case 4:
                cout << "DELETE arc FROM ";
                cin >> key_from;
                cout << " TO ";
                cin >> key_to;

                delete_arc (graph, key_from, key_to);
                break;
            case 5:
                cout << "Search for node ";
                cin >> node_key;

                if (search_for_node (graph, node_key) > -1) {
                    cout << "Node FOUND." << endl;
                } else {
                    cout << "Node NOT FOUND." << endl;
                }
                break;
            case 6:
                cout << "Search for arc FROM ";
                cin >> key_from;
                cout << " TO ";
                cin >> key_to;

                if (search_for_arc (graph, key_from, key_to)) {
                    cout << "Arc FOUND." << endl;
                } else {
                    cout << "Arc NOT FOUND." << endl;
                }
                break;
            case 7:
                list_nodes (graph);
                break;
            case 8:
                //TODO: MAIN WORK. ;)
                break;
            case 9:
                return 0;
            default:
                cout << "What are you doing chose from 1-9. I****.";
                break;
        }
    }
}
