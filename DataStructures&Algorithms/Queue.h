//
// Created by Alexander P on 20/09/10.
//

#ifndef FIRST_STEPS_WITH_C___QUEUE_H
#define FIRST_STEPS_WITH_C___QUEUE_H

template<typename E>
class Queue;

template<typename E>
class QNode {
private:
    E *element = nullptr;
    QNode<E> *next;

    friend class Queue<E>;

public:
    explicit QNode(E &element) : element(&element), next(nullptr) {};

    ~QNode() {
        delete element;
    }
};

template<typename E>
class Queue {
private:
    QNode<E> *front, *rear;
    int size = 0;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    explicit Queue(E &element) : front() {}

    ~Queue(){
        while (!isEmpty())
            deQueue();
    }

    void enQueue(E &element) {
        auto *temp = new QNode<E>(element);
        // If queue is empty, then new node is front and rear both
        if (!rear) {
            front = rear = temp;
            size = 1;
            return;
        }

        // Add the new node at the end of queue and change rear
        rear->next = temp;
        rear = temp;
        size++;
    }

    void deQueue() {
        if (!front)return;

        QNode<E> *old = front;
        front = front->next;

        if (!front) rear = nullptr;

        delete old;
    }

    E &peek() {
        return *front->element;
    }

    bool isEmpty() {
        return size == 0;
    }

    int Size(){
        return size;
    }
};

//#include "Queue.h"
#include "iostream"

using namespace std;

void testQueue(){
    auto *queue=new Queue<float>;

    auto *e = new float;
    *e=9.3f;

    queue->enQueue(*e);
    queue->deQueue();
}

#endif //FIRST_STEPS_WITH_C___QUEUE_H
