//
// Created by hudson on 18.4.2016 г..
//


void deleteNodeWithMaxExitArcs (node *graph[graphElements]){
    char maxExitArcsKey;
    int maxCounter = 0;

    for (int i = 0; i < graphElements; ++i) {
        if (graph[i] != nullptr) {
            node *count_node = graph[i];
            int counter = 0;

            while (count_node->next != NULL) {
                counter++;
                count_node = count_node->next;
            }

            if (counter > maxCounter){
                maxCounter = counter;
                maxExitArcsKey = graph[i]->key;
            }

            delete count_node, counter;
        }
    }

    if (maxExitArcsKey != NULL) {
        delete_node(graph, maxExitArcsKey);
    }

    delete maxExitArcsKey, maxCounter;
}
