//
// Created by hudson on 18.4.2016 г..
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

void nodesWithMaxInboundArcs (node *graph[graphElements]) {
    vector<char> nodesWithMaxInboundArcs;
    int maxCounter = 0;

    for (int i = 0; i < graphElements; ++i) {
        int counter = 0;
        char inboundKey = graph[i]->key;

        for (int j = 0; j < graphElements; ++j) {
            if (i==j){
                continue;
            }
            char outboundKey = graph[j]->key;

            bool arcFound = search_for_arc(graph, outboundKey, inboundKey);

            // search_for_arc will return either true or false
            if (arcFound) {
                counter++;
            }

            delete outboundKey, arcFound;
        }


        if (counter > maxCounter) {
            maxCounter = counter;
            nodesWithMaxInboundArcs.clear();
            nodesWithMaxInboundArcs.push_back(inboundKey);

        } else if (counter == maxCounter) {
            nodesWithMaxInboundArcs.push_back(inboundKey);

        }

        delete inboundKey, counter;
    }

    ostringstream stringStream;
    if(nodesWithMaxInboundArcs.empty()){
        cout << "No nodes with max amount of inbound arcs in the graph" << endl;
    } else {

        // Convert all but the last element to avoid a trailing ","
        copy(nodesWithMaxInboundArcs.begin(), nodesWithMaxInboundArcs.end() - 1, ostream_iterator<char>(stringStream, ","));

        // Now add the last element with no delimiter
        stringStream << nodesWithMaxInboundArcs.back();

        cout << "Arcs: " << stringStream.str() << " are with max amount of " << maxCounter << " inbound arcs." << endl;
    }

    delete nodesWithMaxInboundArcs, stringStream, maxCounter;
}
