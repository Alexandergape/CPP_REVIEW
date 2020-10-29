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
    //     auto *a = new Graph<int>;
    //     delete a;
    //     int *n = new int;
    //     *n = 9;
    //     cout << *n;
    //     //    a->addNode(n);
    //     auto *vec = new vector<int>;
    //     vec->push_back(*n);
    //     cout << vec->at(0) << endl;
    //     vec->at(0)++;
    //     cout << vec->at(0) << endl;
    //     cout << *n << endl;

    // Graph<int> intes;
    Graph<string> graph; // problem when creating
    // SLinkedList<string> jfn; // problem when creating
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
         << graph.getVertex(1).getElement() << endl;

    for (Vertex<string> *V : graph.getAllVertices())
        cout << V->getElement() << '\t';

    // graph.getVertex()
    graph.getVertex(0).addEdge(graph.getVertex(1), 48);
    cout << graph.getVertex(0).getEdge(0).getLength() << endl;

    cout << "F" << endl;
    // for (Edge<string> *edge : graph.getVertex(0).getEdges())
    // {
    //     cout << edge->getDestination().getElement() << '\t';
    //     cout << edge->getLength() << '\n';
    // }
    // for (Edge<string> *edge : graph.getVertex(1).getEdges())
    // {
    //     cout << edge->getDestination().getElement() << '\t';
    //     cout << edge->getLength() << '\n';
    // }
    // cout << endl;
    graph.getVertex(1).addEdge(graph.getVertex(1), 81);
    // for (Edge<string> *edge : graph.getVertex(1).getEdges())
    // {
    //     cout << edge->getDestination().getElement() << '\t';
    //     cout << edge->getLength() << '\n';
    // }

    graph.getVertex(2).addEdge(graph.getVertex(0), 10);

    // graph.pretty();
    // cout << "\n remove edge\n";
    // graph.getVertex(0).getEdges().clear();
    // cout << graph.getVertex(0).getEdges().size() << endl;
    // cout << graph.getVertex(0).getEdges().at(0) << endl;
    // for(Edge<string> *edge : graph.getVertex(0).getEdges())
    // {
    //     cout << edge->getDestination().getElement() << '\t';
    //     cout << edge->getLength() << '\n';
    // }
    graph.pretty();

    // graph.deleteVertex(*graph.getVertex(0).getElement());
    // graph.deleteVertex(*graph.getVertex(1).getElement());
    // string iop= "ff";
    // cout << "\nafter delete vertez A\n";
    graph.getVertex(0).getElement() = "J";
    // graph.getVertex(0).getEdge(0).getLength()=999.2;
    graph.getVertex(0).addEdge(graph.getVertex(2), 8216);

    graph.pretty();

    // for (Vertex<string> *V : graph.getAllVertices())
    //     cout << V->getElement() << '\t';
    string s = "A";
    cout << "\nSearch result:" << graph.searchVertex(s);                                // error: returns -1
    cout << "\nSearch result:" << graph.searchVertex(graph.getVertex(0).getElement()); // success: returns 0
    // graph->getVertex(0)->getEdges();

    // Edge<string> edg;// you must not do it, there's no reason


    // Vertex<string> vert; // to avoid copys of the object, this graph implementation just works with dinamic allocated objects
    auto *verte=new Vertex<string>(*new string("M"));
    auto *ver = new Vertex<string>(*(new string("new one")));

    ver->addEdge(graph.getVertex(0), 1873);

    graph.addVertex(*verte);
    graph.addVertex(*ver);

    cout << "\nAdded new edges: \n";
    graph.pretty();
    // graph.getVertex(2).deleteEdge(graph.getVertex(0), 8216);
    graph.deleteVertex(graph.getVertex(1).getElement());
    graph.pretty();

    cout << "\nGRAPH" << endl;

    int **matrix = graph.getAdjMatrix();
    if (matrix)
        for (int i = 0; i < graph.Size(); i++)
        {
            for (int j = 0; j < graph.Size(); j++)
                cout << matrix[i][j] << '\t';
            cout << endl;
        }

    for(int i=0; i<graph.Size(); i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
