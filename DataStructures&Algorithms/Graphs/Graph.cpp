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

template <typename E>
struct Vertex;

template <typename E>
struct Edge
{
public:
    Edge() : length(-1.), /*origin(nullptr),*/ destination(nullptr) {}

    Edge(double Length, Vertex<E> &to) : length(Length), destination(&to) {}

    ~Edge() = default; // not sure if it has to be defined

    //    void deleteEdge(Edge<E> edge) {}

    [[nodiscard]] double getLength() const
    {
        return length;
    }

    void setLength(double Length)
    {
        this->length = Length;
    }

    E *getDestination() const
    {
        return destination;
    }

    void setDestination(Vertex<E> &Destination)
    {
        this->destination = &Destination;
    }

    // E *getOrigin() const
    // {
    //     return origin;
    // }

    // void setOrigin(Vertex<E> &Origin)
    // {
    //     this->Origin = &Origin;
    // }

private:
    friend struct Vertex<E>;
    double length;
    Vertex<E> *destination;
    // Vertex<E> *origin;
};

template <typename E>
struct Graph;

template <typename E>
struct Vertex
{
public:
    Vertex(E &e, list<Edge<E>> &edges) : element(&e), edges(&edges) {}

    Vertex(E &e) : element(&e), edges(nullptr) {}

    Vertex() : element(nullptr), edges(nullptr) {}

    ~Vertex() = default;

    void deleteEdge(E &from, E &to, double length)
    {
        for (Edge<E> edge : this->edges)
            if ((edge.length == length) && /*(from == edge.origin || *//*from == edge.destination) && */(to == edge.destination/* || to == edge.origin*/))
            {
                delete edge;
                break;
            }
    }

    E &getElement() const
    {
        return *element;
    }

    void setElement(E &Element)
    {
        this->element = &Element;
    }

    Edge<E> &getEdge(int pos)
    {
        return edges->at(pos);
    }

    vector<Edge<E>> &getEdges() const
    {
        return *edges;
    }

    void setEdge(/*Vertex<E> &from, */Vertex<E> &to, double Length, int pos)
    {
        Edge<E> *edge = &edges->at(pos);
        edge->length = Length;
        // edge->origin = &from;
        edge->destination = &to;
    }

    void setEdges(vector<Edge<E>> &Edges)
    {
        this->edges = &Edges;
    }

    void addEdge(/*Vertex<E> &from, */ Vertex<E> &to, double Length)
    {
        if (!edges)
            edges = new vector<Edge<E>>;
        if (!to.edges)
            to.edges = new vector<Edge<E>>;
        // if (from == nullptr)
        //     from = this; // if no origin is passed, it´s assumed to be this
        // if (to == nullptr)
        //     to = this; // if no origin is passed, it´s assumed to be this
        auto *edge = new Edge<E>(Length, to);
        edges->push_back(*edge);
        to.edges->push_back(*edge);
    }

private:
    friend struct Graph<E>;
    E *element;
    vector<Edge<E>> *edges;
};

template <typename E>
struct Graph
{
public:
    explicit Graph(vector<Vertex<E>> &vertices) : vertices(&vertices), size(vertices.size()) {}

    Graph(vector<Vertex<E>> Vertices, vector<Edge<E>> Edges) /* : vertices(&vertices), edges(&Edges), size(vertices->size()) */ {}

    Graph() : vertices(nullptr) /*, edges(nullptr), size(0) */ {}

    ~Graph()
    {
        //        list<Vertex<E>>::iterator;
        for (Vertex<E> Vertex : vertices)
            deleteVertex(*Vertex);
        //        while (!isEmpty())
        //            remove(vertices);
        size = 0;
        delete this;
    }

    void deleteVertex(Vertex<E> &Vertex)
    {
        for (Edge<E> edge : Vertex.edges)
            Vertex.deleteEdge();
    }

    void deleteEdge(float Length)
    {
        //        for(int i=0; i < vertices->size(); i++)
        //            if
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int numvertices() const
    {
        return size;
    }

    int searchVertex(E &element)
    {
        auto iterator = vertices->begin();
        for (int i = 0; i < vertices->size(); i++)
        {
            if (iterator == element)
                return i; // success!
            ++iterator;
        }
        return -1; // not found!
    }

    void addVertex(E &element)
    {
        if (!vertices)
            vertices = new vector<Vertex<E>>;
        //        vertices->push_back(*(new Vertex<E>(element)));
        auto *e = new Vertex<E>(element);
        vertices->push_back(*e);
        //        list<Vertex<E>> *d;
        //        d=new list<Vertex<E>>;
        //        d->push_back()

        size++;
    }

    void setVertex(E &element, int pos)
    {
        vertices->at(pos) = element;
    }

    Vertex<E> *getVertex(int pos)
    {
        vertices->at(pos);
    }

    vector<Vertex<E>> *getAllVertices()
    {
        if (!size)
            return nullptr;
        auto *request = new vector<Vertex<E>>;
        for (int i = 0; i < size; i++)
            request->push_back(*getVertex(i));
        return request;
    }

    int **getAdjMatrix()
    {
        int **matrix = *new int[vertices->size()];
        for (int i = 0; i < vertices->size(); i++)
            matrix[i] = new int;

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
    int size;
    vector<Vertex<E>> *vertices;
    // vector<Edge<E>, Edge<E>> *edges;
    vector<vector<int>> AdjMatrix;
};
