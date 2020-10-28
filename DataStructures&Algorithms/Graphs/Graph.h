//
// Created by Alexander P on 20/08/30.
//

#ifndef FIRST_STEPS_WITH_C___GRAPH_H
#define FIRST_STEPS_WITH_C___GRAPH_H

#include "iostream"
#include "vector"
#include "iterator"

using namespace std;

template <typename E>
struct Vertex;

template <typename E>
struct Edge
{
public:
    double getLength() const
    {
        return length;
    }

    void setLength(double Length)
    {
        length = Length;
    }

    Vertex<E> &getDestination() const
    {
        return *destination;
    }

    void setDestination(Vertex<E> &Destination)
    {
        destination = &Destination;
    }

private:
    friend struct Vertex<E>;

    double length;
    Vertex<E> *destination;

    // Edge() : length(-1.), destination(nullptr) {}

    Edge(double Length, Vertex<E> &to) : length(Length), destination(&to) {}

    ~Edge() = default; // as length isn't a pointer it doesn't need to be deleted, otherwise destination
                       // is pointer but it is just that, not the object that it points to. So it's OK
};

template <typename E>
struct Graph;

template <typename E>
struct Vertex
{
public:
    Vertex(E &e) : element(&e) {}

    // Vertex(): element(nullptr) {} // better prevent to implement this, to avoid run-time errors

    ~Vertex()
    {
        delete element;
        if (!edges.empty())
            edges.clear(); // It's not necessary to delete the objects that the pointers on edges point to.
                           // Because these are Vertices and don't need to be deleted.
    }

    void deleteEdge(E &to, double length) // check later
    {
        for (Edge<E> edge : this->edges)
            if ((edge.length == length) && /*(from == edge.origin || */ /*from == edge.destination) && */ (to == edge.destination /* || to == edge.origin*/))
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
        return *edges.at(pos);
    }

    vector<Edge<E> *> &getEdges()
    {
        return edges;
    }

    void setEdge(Vertex<E> &to, double Length, int pos)
    {
        Edge<E> *edge = &edges->at(pos);
        edge->length = Length;
        edge->destination = &to;
    }

    void setEdges(vector<Edge<E>> &Edges)
    {
        this->edges = &Edges;
    }

    void addEdge(Vertex<E> &to, double Length)
    {
        edges.push_back(new Edge<E>(Length, to));
        if (to.element != this->element) // if is not a loop
            to.edges.push_back(new Edge<E>(Length, *this));
    }

private:
    friend struct Graph<E>;
    E *element;
    vector<Edge<E> *> edges;
};

template <typename E>
struct Graph
{
public:
    Graph(vector<Vertex<E>> &vertices) : vertices(&vertices), size(vertices.size()) {}

    Graph() : size(0){};

    ~Graph()
    {
        // for (Vertex<E> *vertex : vertices)
        //     // for(Edge<E> *e: vertex->getEdges())
        //     // vertex->getEdges().erase(vertex->getEdges().begin(), vertex->getEdges().end());
        //     delete vertex->getEdges()

        for (int i = 0; i < vertices.size(); i++)
            delete vertices[i];

        // while(size){
        //     delete vertices.at(size-1);
        //     // vertices.erase(vertices.begin());
        //     size--;
        // }

        vertices.clear();
        size = 0;

        // vertices.clear();

        // for (Vertex<E> *vertex : vertices)
        //     delete vertex;
        // vertices.clear();

        // for (Vertex<E> *Vertex : vertices)
        //     deleteVertex(*Vertex->element);
        //        while (!isEmpty())
        //            remove(vertices);
        // size = 0;
        // delete this; // NEVER MAKE THIS, this will produce: Segmentation Fault (core dumped)
    }

    bool deleteVertex(E &e /*Vertex<E> &vertex*/)
    {
        int pos = searchVertex(e);

        if (pos != -1)
        {
            delVertexAt(pos);
            return true;
        }
        return false;
    }

    void delVertexAt(int pos)
    {
        Vertex<E> *vertex = vertices.at(pos);
        int edgePos = 0;
        for (Vertex<E> *V : vertices)
        {
            edgePos = 0;
            for (Edge<E> *e : V->edges)
            {
                if (*e->getDestination().getElement() == *vertex->element)
                    V->edges.erase(V->edges.begin() + edgePos);
                edgePos++;
            }
        }
        // delete e;

        vertex->edges.clear();
        // for (Edge<E> *e : vertex.edges)
        //     delete e;
        // vertex.deleteEdge(e);
        vertices.erase(vertices.begin() + pos);
        delete vertex; // not sure
        size--;
        // for (Edge<E> *edge : Vertex.edges)
        //     Vertex.deleteEdge();
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int Size() const
    {
        return size;
    }

    int searchVertex(E &element)
    {
        int pos = 0;
        for (Vertex<E> *V : vertices)
        {
            if (V->getElement() == element)
                return pos;
            pos++;
        }
        return -1;
    }

    void addVertex(Vertex<E> &vertex)
    {
        vertices.push_back(&vertex);
        size++;
    }

    void addVertex(E &element)
    {
        vertices.push_back(new Vertex<E>(element));
        size++;
    }

    void setVertex(E &element, int pos)
    {
        vertices->at(pos) = element;
    }

    Vertex<E> &getVertex(int pos)
    {
        return *vertices.at(pos);
    }

    vector<Vertex<E> *> getAllVertices()
    {
        return vertices;
    }

    void pretty()
    {
        cout << "VERTEX"
             << "\t\t[ASOCIATED VERTEX ; LENGTH]" << endl;
        for (Vertex<E> *V : vertices)
        {
            cout << *V->element << "\t:\t";
            for (Edge<E> *edge : V->edges)
                cout << "[" << edge->getDestination().getElement() << " ; " << edge->getLength() << "], ";
            cout << endl;
        }
        cout << endl;
    }

    int **getAdjMatrix()
    {
        if (!size)
            return nullptr;

        int **matrix = new int *[size];
        for (int i = 0; i < size; i++)
            matrix[i] = new int;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix[i][j] = 0;

        int cont, i = 0, j;
        for (Vertex<E> *vertex1 : vertices)
        // for(Vertex<E> *vertex1=vertices.begin(); vertex1!=vertices.end(); vertex1++)
        {
            j = 0;
            for (Vertex<E> *vertex2 : vertices)
            {
                cont = 0;
                for (Edge<E> *edge : vertex1->getEdges())
                    if (edge->getDestination().getElement() == vertex2->getElement())
                        cont++;
                matrix[i][j] = cont;
                j++;
            }
            i++;
        }
        return completeMatrix(matrix);
    }

private:
    int size;
    vector<Vertex<E> *> vertices;

    int **completeMatrix(int **matrix)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; i < i; j++)
                matrix[i][j] = matrix[j][i];
        }
        return matrix;
    }
};

#endif //FIRST_STEPS_WITH_C___GRAPH_H
