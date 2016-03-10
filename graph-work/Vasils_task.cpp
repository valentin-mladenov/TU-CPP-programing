//
// Created by hudson on 10.3.2016 г..
//

void graph_ranking(node *graph[graphElements]) {
    int ranking[graphElements];

    for(int i = 0; i < graphElements; i++) {
        ranking[i]=0;
    }

    for(int i = 0; i < graphElements; i++) {
        for(int s = 0; s < graphElements; s++) {
            if(search_for_arc(graph, graph[i]->key, graph[s]->key)) {
                ranking[i] = ranking[i] + 1;
            }
        }
    }

    for(int i = 0; i < graphElements; i++) {
        cout << ranking[i] << endl;
    }
}
