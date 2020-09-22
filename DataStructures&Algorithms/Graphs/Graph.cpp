//
// Created by Alexander P on 20/08/30.
//

#include "Graph.h"
#include "iostream"
#include "vector"
#include "list"
#include "iterator"
//#include "R:\Documents\Projects\C++\First_Steps_With_C++\DataStructures&Algorithms\SLinkedList.cpp"

using namespace std;

template<typename E>
struct Vertex;

template<typename E>
struct Edge {
public:
    Edge() : length(-1.), origin(nullptr), destination(nullptr) {}

    Edge(double Length, Vertex<E> &from, Vertex<E> &to) : length(Length), origin(&from), destination(&to) {}

    ~Edge() = default; // not sure if it has to be defined

//    void deleteEdge(Edge<E> edge) {}

    [[nodiscard]] double getLength() const {
        return length;
    }

    void setLength(double Length) {
        this->length = Length;
    }

    E *getDestination() const {
        return destination;
    }

    void setDestination(Vertex<E> &Destination) {
        this->destination = &Destination;
    }

    E *getOrigin() const {
        return origin;
    }

    void setOrigin(Vertex<E> &Origin) {
        this->Origin = &Origin;
    }

private:
    friend struct Vertex<E>;
    double length;
    Vertex<E> *destination;
    Vertex<E> *origin;
};

template<typename E>
struct Graph;

template<typename E>
struct Vertex {
public:
    Vertex(E &e, list<Edge<E>> &edges) : element(&e), edges(&edges) {}

    Vertex(E & e): element(&e){}

    Vertex() : element(nullptr), edges(nullptr) {}

    ~Vertex() = default;

    void deleteEdge(E & from, E & to, double length) {
        for (Edge<E> edge: this->edges)
            if ((edge.length == length) && (from==edge.origin || from==edge.destination) && (to==edge.destination || to==edge.origin)) {
                delete edge;
                break;
            }
    }

    E & getElement() const {
        return * element;
    }

    void setElement(E &Element) {
        this->element = &Element;
    }

    Edge<E> * getEdge(int pos){
        return * edges->at(pos);
    }

    list<Edge<E>> & getEdges() const {
        return *edges;
    }

    void setEdge(Vertex<E> &from, Vertex<E> &to, double Length, int pos){
        Edge<E> *edge=&edges->at(pos);
        edge->length=Length;
        edge->origin=&from;
        edge->destination=&to;
    }

    void setEdges(list<Edge<E>> &Edges) {
        this->edges = &Edges;
    }

    void addEdge(Vertex<E> &from, Vertex<E> &to, double Length) {
        if (from == nullptr) from = this; // if no origin is passed, it´s assumed to be this
        if (to == nullptr) to = this; // if no origin is passed, it´s assumed to be this
        edges->push_back(*new Edge<E>(Length, *from, *to));
    }

private:
    friend struct Graph<E>;
    E *element;
    vector<Edge<E>> *edges;
};

template<typename E>
struct Graph {
public:
    explicit Graph(list<Vertex<E>> &vertices) : vertices(&vertices), size(vertices.size()) {}

    Graph() = default;

    ~Graph() {
//        list<Vertex<E>>::iterator;
        for (Vertex<E> Vertex: vertices)
            deleteVertex(*Vertex);
//        while (!isEmpty())
//            remove(vertices);
        size = 0;
        delete this;
    }

    void deleteVertex(Vertex<E> &Vertex) {
        for (Edge<E> edge: Vertex.edges)
            Vertex.deleteEdge();
    }

    void deleteEdge(float Length){
//        for(int i=0; i < vertices->size(); i++)
//            if
    }

    bool isEmpty() const {
        return size == 0;
    }

    int numvertices() const {
        return size;
    }

    int searchVertex(E *&element) {
        auto iterator = vertices->begin();
        for (int i = 0; i < vertices->size(); i++) {
            if (iterator == element)
                return i; // success!
            ++iterator;
        }
        return -1; // not found!
    }

    void addVertex(E *&element) {
        if(vertices->size()==0)
            vertices=new vector<Vertex<E>>;
//        vertices->push_back(*(new Vertex<E>(element)));
        auto *n=new Vertex<E>;
        vertices->push_back(*element);
//        list<Vertex<E>> *d;
//        d=new list<Vertex<E>>;
//        d->push_back()

//        size++;
    }

    void setVertex(E *&element, int pos) {
        vertices->at(pos) = element;
    }

    Vertex<E> *getVertex(int pos) {
        vertices->at(pos);
    }

    int ** getAdjMatrix(){
        int **matrix=*new int[vertices->size()];
        for(int i=0;i<vertices->size();i++)
            matrix[i]=new int;

        // for(Vertex<E> *vertex=vertices->begin(); vertex!=vertices->end(); vertex++)
        //     for(Edge<E> *edge=vertex->edges->begin(); edge!=vertex->edges->end(); edge++)
        //         matrix[i][j]=1;

//        for(Vertex<E> *vertex: vertices)
//            for(Edge<E> *edge: vertex)
//                if(edge->origin)
//                    matrix[]
//            for(Vertex<E> *v2: vertices)
//                if()
        return matrix;
    }

private:
    int size = 0;
    vector<Vertex<E>> *vertices;
    vector<vector<int>> AdjMatrix;
};
