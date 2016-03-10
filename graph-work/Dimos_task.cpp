
#include <iostream>

using namespace std;

const int n = 8;

int m[n] = {0};


struct link {
    char key;
    link *next;
} *gr[n]; //grafa ima zadadeni n elementa


void init(link *gr[n]) {
    for (int i = 0; i < n; i++)
        gr[i] = NULL;
}

//Proverka na varhove
int search_node(link *gr[n], char c) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (gr[i] && gr[i]->key == c) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// proverka, tarsi dali ima ednakvi dagi
int search_arc(link *gr[n], char c1, char c2) {
    int flag = 0;
    if (search_node(gr, c1) && search_node(gr, c2)) {
        int i = 0;
        while (gr[i] == NULL || gr[i]->key != c1) i++;
        link *p = gr[i];
        while (p->key != c2 && p->next != NULL) p = p->next;
        if (p->key == c2) flag = 1;
    }
    return flag;
}

// dobaviane na vrah - node
bool add_node(link *gr[n], char c) {
    if (search_node(gr, c)) {
        return false;
    }

    int j = 0;
    //
    while (gr[j] && (j < n)) j++;

    if (gr[j] == NULL && j < n) {
        gr[j] = new link;
        gr[j]->key = c;
        gr[j]->next = NULL;
        return true;
    }
    else {
        return false;
    }

}

// dobavia daga - arc
bool add_arc(link *gr[n], char c1, char c2) {
    int i = 0;
    link *p;
    if (search_arc(gr, c1, c2)) {
        cout << "\n Takuv graf sushtestvuva";
        return false;
    }

    // tarsi varhovete, v sluchai, che gi niama si sazdava - dobavia
    if (!(search_node(gr, c1))) {
        if (!add_node(gr, c1)) {
            return false;
        }
    }

    if (!(search_node(gr, c2))) {
        if (!add_node(gr, c2)) {
            return false;
        }
    }

    //
    while (gr[i] == NULL || gr[i]->key != c1) i++;

    // suzdava daga
    p = new link;
    p->key = c2;
    p->next = gr[i]->next;
    gr[i]->next = p;

    return true;
}

// show me graf
int list_node(link *gr[n]) {
    int graphElements(0);

    for (int i = 0; i < n; i++)
        if (gr[i]) {
            graphElements++;

            link *p = gr[i];
            while (p) {
                cout << p->key << "\t";
                p = p->next;
            }
            cout << endl;
        }

    return graphElements;

}

// da pokaje varhove s poveche ot dve izhodiashti dagi
int countNodesWithMoreThanTwoOutgoingArrows(link *gr[n]) {
    int countNodesWithMoreThanTwoArrows(0);

    vector<char> moreThanTwoArrows;


    for (int i = 0; i < n; i++) {
        if (gr[i]) // dali varha sushtestvuva
        {
            link *p = gr[i];
            int tempOutgoingNodes = 0;
            while (p->next) {
                tempOutgoingNodes++; // broqt se strelkite
                p = p->next;
            }

            if (tempOutgoingNodes >= 2) {
                moreThanTwoArrows.push_back(gr[i]->key);
            }
        }
    }

    // second loop to find incoming arcs, if found the node is deleted
    for (int i = 0; i < n; i++) {
        if (gr[i]) // dali varha sushtestvuva
        {
            link *p = gr[i];
            while (p->next) {
                int toErase = -1;
                for (int j = 0; j < moreThanTwoArrows.size(); j++) {
                    if (p->key == moreThanTwoArrows[j]) {
                        toErase = j; // save index to delete
                        break;
                    }
                }

                // deletion must be done outside loop
                if (toErase != -1){
                    moreThanTwoArrows.erase(moreThanTwoArrows.begin() + toErase);
                }

                p = p->next;
            }
        }
    }

    for (int i = 0; i < moreThanTwoArrows.size(); i++) {
        cout << "Node \'" << moreThanTwoArrows[i] << "\' has more than 2 outgoing arrows.\n";
    }

    return countNodesWithMoreThanTwoArrows;
}

void main() {
    char c, k;
    int m;
    do {
        cout << "\n\n  Menu\n\n";
        cout << "1 -  Initsiirane na grafa\n";
        cout << "2 -  Dobavia vrah\n";
        cout << "3 -  Dobavia daga\n";
        cout << "4 -  Tursi vrah\n";
        cout << "5 -  Tursi daga\n";
        cout << "6 -  Broi varhove s poveche ot 2 izhodiashti dagi\n";
        cout << "7 -  Izvejda vsichko\n";
        cout << "8 -  The End";
        cout << "\n\nVuvedi (1-8):";
        cin >> m;
        switch (m) {
            case (1) : {
                system("CLS");
                cout << "\n\tGrafut e nuliran";
                init(gr);
                break;
            }
            case (2) : {
                system("CLS");
                cout << "\n\tDobavq se vruh kum grafa ...\n\n";

                cout << "Vuvedi vruh (char): ";
                cin >> c;
                if (add_node(gr, c)) {
                    cout << "\n\tVarhut e dobaven.";
                }
                else {
                    cout << "\n\tVarhut ne e dobaven !!!";
                }
                break;
            }
            case (3) : {
                system("CLS");
                cout << "\n\tDobavq se duga kum vurha ...\n";

                cout << "\nVuvedi parvia graf (char) :";
                cin >> c;
                cout << "\nVuvedi vtoria graf (char):";
                cin >> k;
                if (add_arc(gr, c, k)) {
                    cout << "\n\tDagata \'" << c << "\' -----> \'" << k << "\' e dobaven kum grafa !";
                }
                else {
                    cout << "\n\tDagata \'" << c << "\' -----> \'" << k << "\'ne e dobaven kum grafa !";
                }
                break;
            }
            case (4) : {
                system("CLS");
                cout << "\n\tTarsi vrah vav grafa ...\n";

                cout << "\nVavedi varha za tarsene (char): ";
                cin >> k;
                if (search_node(gr, k))
                    cout << "\n\tIma go!";
                else
                    cout << "\n\tNiama go!";
                break;
            }
            case (5) : {
                system("CLS");
                cout << "\n\tTursi daga vuv vurha ...\n";

                cout << "\nVuvedi vrah (char):";
                cin >> c;
                cout << "\nVuvedi drugiq vruh (char):";
                cin >> k;
                if (search_arc(gr, c, k))
                    cout << "\nIma q!";
                else
                    cout << "\nNqma q!";
                break;
            }

            case (6) : {
                system("CLS");
                cout << "\n\Tarsiat se varhove s poveche ot 2 izhodiashti dagi ...\n";

                int countNodes = countNodesWithMoreThanTwoOutgoingArrows(gr);
                if (countNodes == 0) {
                    cout << "\nNqma takiva !!!\n";
                }
                else {
                    cout << "\n\nIma  " << countNodes << " varhove s poveche ot 2 izhodiashti dagi.\n";
                }

                break;
            }
            case (7) : {
                system("CLS");
                cout << "\n\tPokazvat se elementite na grafa ...\n";

                int countElements = list_node(gr);

                if (countElements == 0) {
                    cout << "\n\tGrafut e prazen !!!";
                }
                break;
            }
            default: {
                system("CLS");
                cout << "\n\tVuvedi izbor (1 to 8) ...";
            }

        }
    } while (m != 8);
    cout << "\n";
}
