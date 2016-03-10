//
// Created by hudson on 6.3.2016 г..
//

void one_arc_in_and_one_out (node *graph[graphElements]) {
    // first find all that have ONlY one arc OUT.
    map<char, int> all_with_one_out;
    for (int i = 0; i < graphElements; i++) {
        if (graph[i] == nullptr) {
            continue;
        }

        if (graph[i]->next == nullptr) {
            continue;
        }

        if (graph[i]->next->next == nullptr) {
            //all_with_one_out[i] = graph[i]->key;
            all_with_one_out[graph[i]->key] = 1;
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
            map<char, int>::iterator node_found = all_with_one_out.find (temp->key);
            if (node_found == all_with_one_out.end()) {
                temp = temp->next;
                continue;
            }

            // increase on FIRST occurance
            if (node_found->second <= 2) {
                node_found->second++;
                temp = temp->next;
                continue;
            }

            // delete on SECOND occurance
            all_with_one_out.erase(node_found);
            temp = temp->next;
        }
    }

    // print the remaining noes
    for(auto it = all_with_one_out.begin(); it != all_with_one_out.end(); ++it) {
        // print only that have IN and OUT.
        if (it->second == 2) {
            cout << it->first << " ";
        }
    }
}

