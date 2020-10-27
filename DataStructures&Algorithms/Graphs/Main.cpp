//
// Created by Alexander P on 20/09/02.
//

#include "Graph.h"
#include "/media/alexander/Backup/Documents/Projects/C++/First_Steps_With_C++/my_header"
// #include "R:\Documents\Projects\C++\First_Steps_With_C++\my_header"
// #include "/media/alexander/Backup/Documents/Projects/C++/First_Steps_With_C++/DataStructures&Algorithms/SLinkedList.cpp"
//#include "R:/Documents/Projects/C++/First_Steps_With_C++/DataStructures&Algorithms/SLinkedList.cpp"
// /media/alexander/Backup/Documents/Projects/C++/First_Steps_With_C++/my_header
using namespace std;

void add(int *&n)
{
    cout << endl
         << *n << endl;
}

int mainMain()
{
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
    cout << endl
         << li->front() << endl;
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

    // auto *graph = new Graph<string>();
    // cout << 435;
    // vector<string> b; //cout << 435;

    Graph<int> intes;
    Graph<string> graph; // problem when creating
    SLinkedList<string> jfn; // problem when creating
    // BinarySearchTree<int> fdg;
    // list<int> dv;
    // Stack<string> que;
    // Queue<string> sta;

    // auto *str = new string();
    // str->append("A");
    graph.addVertex(*(new string("A")));
    graph.addVertex(*(new string("B")));
    graph.addVertex(*(new string("C")));

    cout << endl
         << graph.getVertex(1)->getElement() << endl;

    for (Vertex<string> *V : graph.getAllVertices())
        cout << V->getElement() << '\t';

    graph.getVertex(0)->addEdge(*graph.getVertex(1), 48);
    cout << graph.getVertex(0)->getEdge(0).getLength() << endl;

    cout << "F" << endl;
    for (Edge<string> *edge : graph.getVertex(0)->getEdges())
    {
        cout << edge->getDestination().getElement() << '\t';
        cout << edge->getLength() << '\n';
    }
    for (Edge<string> *edge : graph.getVertex(1)->getEdges())
    {
        cout << edge->getDestination().getElement() << '\t';
        cout << edge->getLength() << '\n';
    }

    // graph->getVertex(0)->getEdges();

    cout << "\nGRAPH" << endl;

    int **matrix = graph.getAdjMatrix();
    if (matrix)
        for (int i = 0; i < graph.Size(); i++)
        {
            for (int j = 0; j < graph.Size(); j++)
                cout << matrix[i][j] << '\t';
            cout << endl;
        }

    return 0;
}
