//
// Created by hudson on 10.3.2016 г..
//

void find_snare_arc(node *graph[graphElements]) {

    vector<char> snares;
    for (int i = 0; i < graphElements; i++) {
        if (graph[i] == nullptr) {
            continue;
        }

        node *temp;
        char snare_key;

        snare_key = graph[i]->key;
        temp = graph[i]->next;

        while (temp != nullptr) {
            if (snare_key = temp->key) {
                snares.push_back(snare_key);
            }

            temp = temp->next;
        }
    }

    if (!snares.empty()) {
        cout << "Found: " << snares.size() << "snares." << endl;
        cout << "Nodes: ";
        for (int j = 0; j < snares.size(); ++j) {
            cout << snares[j] << ", ";
        }
    } else {
        cout << "Snares not found." << endl;
    }
}
