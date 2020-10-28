//
// Created by Alexander P on 20/09/10.
//

#ifndef FIRST_STEPS_WITH_C___STACK_H
#define FIRST_STEPS_WITH_C___STACK_H

template<typename E>
class Stack;

template<typename E>
class SNode {
private:
    friend class Stack<E>;

    E *element = nullptr;
    SNode<E> *next;

public:
    explicit SNode(E &element) : element(&element), next(nullptr) {}

    ~SNode() {
        delete element;
    }
};

template<typename E>
class Stack {
private:
    SNode<E> *top, *bottom;
    int size;

public:
    Stack() : top(nullptr), bottom(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(E &element) {
        auto *temp = new SNode<E>(element);

        if (!top) {
            top = bottom = temp;
            size = 1;
            return;
        }

        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (!top) return;

        SNode<E> *old = top;
        top = top->next;

        if (!top) bottom = nullptr;
        delete old;
        size--;
    }

    E &Top() {
        return *top->element;
    }

    bool isEmpty() {
        return size == 0;
    }

    int Size() {
        return size;
    }
};

//#include "Stack.h"
#include "iostream"

using namespace std;

void testStack() {
    auto *stack = new Stack<float>;

    auto *e = new float;
    *e = 9.3F;

    stack->push(*e);
    cout << endl << stack->Top() << endl;

    stack->pop();

}

#endif //FIRST_STEPS_WITH_C___STACK_H
