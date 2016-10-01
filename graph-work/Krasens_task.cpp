//
// Created by hudson on 6.3.2016 г..
//


/*void delete_node_with_max_value (node *graph[graphElements]){
    char maxKey = graph[0]->key;
    for (int i = 0; i < graphElements; ++i) {
        if (graph[i] != nullptr) {
            if (graph[i]->key > maxKey) {
                maxKey = graph[i]->key;
            }
        }
    }

    delete_node(graph, maxKey);
}
