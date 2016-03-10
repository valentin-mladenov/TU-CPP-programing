
#include <iostream>
#include <cstdlib>
#include <vector>

#define N 10

using namespace std;

struct link {
    char key;
    link *next;
} *g[N];

void _init() {
    for (int i = 0; i < N; i++)
        g[i] = NULL;
}

void print() {
    link *p;

    for (int i = 0; i < N; i++) {
        if (g[i]) {
            p = g[i];
            while (p) {
                cout << p->key;
                p = p->next;
            }
            cout << endl;
        }
    }
}

void check_max(char key, link *addr, int *br) {
    bool flag = true;
    link *p;

    for (int i = 0; i < N; i++)
        if (g[i]) {
            p = g[i];
            while (p) {
                if (key == p->key && addr != p) {
                    flag = false;
                    break;
                }
                p = p->next;
            }
        }
    cout << endl;

    if (flag == true) {
        *br += 1;
        cout << key << "\n e tarsenia vrah." << endl;
    }
}

/**
 * Created by hudson on 6.3.2016 г..
 */
void print_max() {
    vector<char> nodeKeys;
    int currentMaxArcs = 0;
    link *temp;

    for (int i = 0; i < N; i++)
        int arcs = 0;
        if (g[i] != nullptr) {
            temp = g[i];

            while (temp != nullptr) {
                arcs++;
                temp = temp->next;
            }

            if (currentMaxArcs < arcs) {
                currentMaxArcs = arcs;
                nodeKeys.clear();
                nodeKeys.push_back(g[i]->key);
                continue;
            }

            if(currentMaxArcs == arcs){
                nodeKeys.push_back(g[i]->key);
            }
        }

    if (currentMaxArcs > 0){
        cout << endl << " Broiat na namerenite varhove s izhodqshti dygi e: " << nodeKeys.size() << endl;

        cout << "Nodes: ";
        for (int j = 0; j < nodeKeys.size(); ++j) {
            cout << nodeKeys[j] << ", ";
        }
    } else {
        cout << endl << " Niama takiva varhove!" << endl;
    }
}

int search_node(char key) {
    for (int i = 0; i < N; i++)
        if (g[i] && g[i]->key == key)
            return 1;

    return 0;
}

int search_arc(char front, char end) {
    if (search_node(front) && search_node(end)) {
        int i = 0;

        while (g[i] && g[i]->key != front)
            i++;
        link *p = g[i]->next;
        if (p) {
            while (p->key != end && p->next)
                p = p->next;
            if (p->key == end)
                return 1;
        }
    }

    return 0;
}

void add_node(char key) {
    if (search_node(key))
        cout << " Existing node" << endl;
    else {
        int i = 0;

        while (g[i] && i < N) i++;
        if (g[i] == NULL) {
            g[i] = new link;
            g[i]->key = key;
            g[i]->next = NULL;
        } else
            cout << "\n overflow";
    }
}

void add_arc(char front, char end) {
    if (search_arc(front, end))
        cout << "\nexisting arc";
    else {
        if (!search_node(front))
            add_node(front);
        if (!search_node(end))
            add_node(end);
        int i = 0;
        while ((g[i] == NULL || g[i]->key != front) && i < N)
            i++;
        link *p = new link;
        p->key = end;
        p->next = g[i]->next;
        g[i]->next = p;
    }
}

const char menu[] = "\n"                \
                "Menu\n"                \
                "1. Add node.\n"        \
                "2. Add arc.\n"         \
                "3. Print all.\n"       \
                "4. Print max.\n"       \
                "5. End.\n"             \
                "\n\tChoice: ";

int main() {
    char key, end;
    int choice;

    _init();

    for (; ;) {
        cout << menu;
        cin >> choice;

        system("cls");

        switch (choice) {
            case 1:
                cout << "\n Node:";
                cin >> key;
                add_node(key);
                break;
            case 2:
                cout << "\n First node:";
                cin >> key;
                cout << "\n Second node:";
                cin >> end;
                add_arc(key, end);
                break;
            case 3:
                print();
                break;
            case 4:
                print_max();
                break;
            case 5:
                return 0;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
    }
}
