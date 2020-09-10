//
// Created by Alexander P on 20/09/02.
//

#include "Main.h"
#include "Graph.cpp"
//#include "R:/Documents/Projects/C++/First_Steps_With_C++/DataStructures&Algorithms/SLinkedList.cpp"

using namespace std;

void add(int *&n) {
    cout << endl << *n << endl;
}

int mainMain() {
    auto *a = new Graph<int>;
    int *n = new int;
    *n = 9;
    cout << *n;
//    a->addNode(n);
    auto *vec = new vector<int>;
    vec->push_back(*n);
    cout << vec->at(0) << endl;
    vec->at(0)++;
    cout << vec->at(0) << endl;
    cout << *n << endl;

    auto *li = new list<int>;
    li->push_back(*n);
    li->front()++;
    cout << endl << li->front() << endl;
    cout << *n << endl;

//    auto *list1=new SLinkedList<int>;
//    list1->add(0, n);
//    int *p=list1->get(0);
//    (*p)++;
//    list1->update(0, p);
//    cout << *list1->get(0)<< endl;
//    cout << *p << endl;
//    cout << *n << endl;

//    cout<<a->getNode(0)<< endl;
//    add(n);
    return 0;
}
