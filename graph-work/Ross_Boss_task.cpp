//
// Created by hudson on 20.4.2016 г..
//

/*void showAllNodesWithMoreThan2OutboundArcs (node *graph[graphElements]) {
    cout << "Nodes found: ";
    bool setNone = true;
    // first find all that have MORE than 2 arcs OUT.
    for (int i = 0; i < graphElements; i++) {
        // NO outbound arcs.
        if (graph[i] == nullptr) {
            continue;
        }

        // Only ONE outbound arc.
        if (graph[i]->next == nullptr) {
            continue;
        }

        // Only TWO outbound arc.
        if (graph[i]->next->next == nullptr) {
            continue;
        }

        // this means we find at least one NODE with 2 outbound arcs.
        setNone = false;
        cout << graph[i]->key << " ";
    }

    // print none if we does not found any.
    if (setNone) {
        cout << "NONE!" << endl;
    }
}
