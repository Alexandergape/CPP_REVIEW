//
// Created by Alexander P on 20/09/03.
//

#include "BinarySearchTree.h"
#include "iostream"
#include "vector"

using namespace std;

template<typename E>
class BinarySearchTree;

template<typename E>
class Node {
private:
    friend class BinarySearchTree<E>;

    E *element;
    Node<E> *parent;
    Node<E> *left;
    Node<E> *right;
public:
    Node(E &e, Node<E> *Parent, Node<E> *Left, Node<E> *Right) {
        element = &e;
        parent = Parent;
        left = Left;
        right = Right;
    }

    Node() : element(nullptr), parent(nullptr), left(nullptr), right(nullptr) {}

    ~Node() = default;

    E &getElement() const {
        return *element;
    }

    void setElement(E &Element) {
        auto *old = &Element;
        this->element = &Element;
        delete old;
    }
};

template<typename E>
class BinarySearchTree {
protected:
    Node<E> &createNode(E &e, Node<E> *Parent, Node<E> *Left, Node<E> *Right) {
        return *new Node<E>(e, Parent, Left, Right);
    }

    Node<E> *root = nullptr;
private:
    int Size = 0;

    int numChildren(const Node<E> &node) const {
        int n = 0;
        if (node.left != nullptr)n++;
        if (node.right)n++;
        return n;
    }

    bool isInternal(const Node<E> &node) const {
        return (numChildren(node) > 0);
    }

    bool isExternal(const Node<E> &node) const {
        return (numChildren(node) == 0);
    }

public:
    BinarySearchTree() = default;

    ~BinarySearchTree() = default;

    int size() const {
        return Size;
    }

    bool isEmpty() const {
        return Size == 0;
    }

    void addRoot(E &e) {
        root = &createNode(e, nullptr, nullptr, nullptr);
    }

    void addLeft(Node<E> &parent, E &e) {
        if (parent.left) return;
        Node<E> *child = &createNode(e, parent, nullptr, nullptr);
        parent.left = &child;
        Size++;
    }

    void addRight(Node<E> &parent, E &e) {
        if (parent.right) return;
        Node<E> *child = &createNode(e, parent, nullptr, nullptr);
        parent.right = &child;
        Size++;
    }

private:

    Node<E> *getSuccesor(Node<E> &node) const {
        auto *Succesor = node.right;
        while (Succesor) {
            if (!Succesor->left) return Succesor;
            Succesor = Succesor->left;
        }
        return Succesor;
    }

    Node<E> *getPredecessor(const Node<E> &node) const {
        if (!node.left) return nullptr;
        auto *Predecessor = node.left;
        while (Predecessor) {
            if (Predecessor->right)
                Predecessor = Predecessor->right;
        }
        return Predecessor;
    }

    void remove(Node<E> &node) {
        int nChildren = numChildren(node);
        Node<E> *child;

        if (nChildren == 2) {
            child = getSuccesor(node); // in this case is sure at lest a child exists
            remove(*child);
            child->parent = node.parent;
            child->left = node.left;
            child->right = node.right;

            if (child->left) // if(child->left) is the same as: if(child->left!=nullptr)
                child->left->parent = child;
            if (child->right)
                child->right->parent = child;

            if (&node == root)
                root = child;
            else {
                if (&node == node.parent->right)
                    node.parent->right = child;
                else node.parent->left = child;
            }
        } else {
            child = (node.left ? node.left : node.right); // if(node.left) is the same as: if(node.left!=nullptr)

            if (child) child->parent = node.parent;

            if (&node == root) root = child;
            else {
                if (&node == node.parent->left)
                    node.parent->left = child;
                else node.parent->right = child;
            }
        }
    }

public:

    Node<E> *search(E &element) const {
        if (!root) {
            cout << "Tree is empty..." << endl;
            return nullptr;
        }

        Node<E> *aux = root;
        while (aux != nullptr) {
            if (*aux->element == element) return aux;
            else if (*aux->element < element && aux->right)
                aux = aux->right;
            else if (aux->left)
                aux = aux->left;
            else {
                cout << "Not found..." << endl;
                return nullptr;
            }
        }
        return nullptr;
    }

    void remove(E &element) {
        auto *old = search(element);
        if (old) {
            remove(*old);
            Size--;
            delete old->element;
        }
    }

    void update(E &oldValue, E &newValue) {
        auto *node = search(oldValue);
        if (!node) return;
        remove(oldValue);
        add(newValue);
//        node->setElement(newValue);
    }

    void add(E &element) {
        if (!root) {
            this->addRoot(element);
            Size = 1;
            return;
        }
        Node<E> *parent = root;
        while (parent) {
            if (*parent->element < element) {
                if (parent->right)
                    parent = parent->right;
                else {
                    parent->right = new Node<E>(element, parent, nullptr, nullptr);
                    break;
                }
            } else if (*parent->element > element) {
                if (parent->left)
                    parent = parent->left;
                else {
                    parent->left = new Node<E>(element, parent, nullptr, nullptr);
                    break;
                }
            } else {
                cout << "\n\tThis element already exists" << endl;
                return;
            }
        }
        Size++;
    }

    vector<Node<E>> children(Node<E> &node) {
//        auto children=new vector<E>();
        vector<E> children;
        if (node.left) children.push_back(node.left);
        if (node.right) children.push_back(node.right);
        return children;
    }

    vector<E> breathFirst() const {
        vector<Node<E>> nodes;
        vector<E> elements;
        if (!this->root)return nullptr;
        nodes.push_back(root);
        Node<E> *node;

        while (nodes.size() > 0) {
            node = nodes.erase(nodes.begin());
            elements.push_back(node->element);
            for (Node<E> &child: children(node))
                nodes.push_back(child);
        }
        return elements;
    }

    int getLevel(const Node<E> &node, int level) const { // when calling this method level must be zero (0)
        if (node == root) return level;
        return getLevel(node.parent, level + 1);
    }

    vector<E> &inOrder() const {
        auto elements = new vector<E>;
        if (!root) return *elements;

        auto *nodes = new vector<Node<E> *>;
        inOrder(*root, *nodes);
        for (Node<E> *node : *nodes)
            elements->push_back(node->getElement());
        return *elements;
    }

private:

    void inOrder(Node<E> &parent, vector<Node<E> *> &nodes) const {
        if (parent.left)
            inOrder(*parent.left, nodes);
        nodes.push_back(&parent);
        if (parent.right)
            inOrder(*parent.right, nodes);
    }

public:

    vector<E> postOrder() const {
        vector<E> elements;
        if (!root) return elements;

        postOrder(root, elements);
        return elements;
    }

private:

    void postOrder(Node<E> node, vector<E> elements) const {
        for (Node<E> child : children(node))
            postOrder(child, elements);
        elements.push_back(node.element); // for postOrder, we add position p after exploring subtrees
    }

public:

    vector<E> preOrder() const {
        vector<E> elements;
        if (!root) return elements;

        preOrder(root, elements);
        return elements;
    }

private:
    void preOrder(Node<E> node, vector<E> elements) const {
        elements.push_back(node.element);
        for (Node<E> child : children(node))
            preOrder(child, elements);
    }

};