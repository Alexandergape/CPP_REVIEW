//
// Created by Alexander P on 20/08/11.
//

#include "iostream"
#include "vector"

using namespace std;

template<typename E>
struct SLinkedList;

template<typename E>
struct SNode {
public:
    SNode(E &e, SNode<E> *Next) {
        element = &e;
        next = Next;
    }

    ~SNode() {
        delete element;
//        delete this; // error: doing this will delete the next element
    }

    void setElement(E &newElement) {
        E *old = element;
        element = &newElement;
        delete old;
    }

private:
    E *element;
    SNode<E> *next = nullptr;

    friend struct SLinkedList<E>;
};

template<typename E>
struct SLinkedList {
public:
    SLinkedList() : head(nullptr), tail(nullptr) {} //constructor

    explicit SLinkedList(const vector<E> &v) { //constructor
        int pos = 0;
        for (auto i: v) {
            this->add(pos, i);
            pos++;
        }
    }

    explicit SLinkedList(E &e) { // constructor
        this->add(0, e);
    }

    ~SLinkedList() {
        while (!isEmpty()) removeFront();
        Size = 0;
        delete this;
    }

    bool isEmpty() const { return size() == 0; }// const means that this method wont change the object

    void addLast(E &e) {
        auto *newest = new SNode<E>(e, nullptr);
        if (isEmpty()) head = newest;
        else
            tail->next = newest;
        tail = newest;
        Size++;
    }

    void removeFront() {
        if (isEmpty()) return;
        SNode<E> *old = head;
        head = old->next;
        delete old;
        Size--;
        if (Size == 0) tail = nullptr;
    }

    E &get(int pos) const {
        return *getNode(pos).element;
    }

//    virtual int search(const string name){return 0;};
    int search(const E &e) { // not well implemented
        if (isEmpty()) return -1;
        SNode<E> *headCopy = head;
        int pos = -1;
        while (headCopy != nullptr) {
            if (headCopy->element == e) {
                pos++;
                break;
            }
            pos++;
            headCopy = headCopy->next;
        }
        return pos;
    }

    int update(int pos, E &newVal) {
        if (pos < 0 || pos >= Size) return 1; // error

        getNode(pos).setElement(newVal);
        return 0; // succes
    }


    int remove(int pos) {
        if (pos < 0 || pos >= Size) return 1;

        SNode<E> *old = &getNode(pos);
        if (pos == 0)
            head = head->next;
        else if (pos < Size - 1)
            getNode(pos - 1).next = &getNode(pos + 1);
        else {
            getNode(pos - 1).next = nullptr;
            tail = &getNode(pos - 1);
        }
        delete old;
        Size--;
        if (Size == 0) tail = nullptr;
        return 0; //SUCCESS
    }

    int add(int pos, E &e) {
        if (pos < 0 || pos > Size) return 1; // error: position not valid

        SNode<E> *newest;
        if (pos == 0)head = new SNode<E>(e, head);
        else if (pos <= Size - 1) {
            newest = new SNode<E>(e, &getNode(pos));
            getNode(pos - 1).next = newest;
        } else {
            newest = new SNode<E>(e, nullptr);
            tail->next = newest;
            tail = newest;
        }

        if (Size == 0)
            tail = head;
        Size++;
        return 0;
    }

    int size() const { return Size; }

private:
    int Size = 0;
    SNode<E> *head;
    SNode<E> *tail;

    SNode<E> &getNode(int pos) const {
        SNode<E> *copyHead = head;
        while (pos > 0) {
            copyHead = copyHead->next;
            pos--;
        }
        return *copyHead;
    }
};

//template<typename E>
//void menuList(/*SLinkedList<E> *myList*/) {
//    int opt;
//    auto *myList=new SLinkedList<string>;
//    auto *str=new string;
//
//    do {
//        str->clear();
//        cout << "\n1. Create" << endl;
//        cout << "2. Read" << endl;
//        cout << "3. Update" << endl;
//        cout << "4. Delete" << endl;
//        cout << "0. EXIT" << endl;
//        cout << "Enter your option: ";
//
//        fflush(stdin);
//        cin >> opt;
//
//        int pos;
//        switch (opt) {
//            case 1:
//                cout << "Enter the position & the object" << endl;
//                cin >> pos;
//                fflush(stdin);
//                getline(cin, *str);
//                myList->add(pos, str);
//                break;
//            case 2:
//                cout << "All the elements in the list are: " << endl;
//                pos = 0;
//                while (pos < myList->size())
//                    cout << myList->get(pos++) << ", ";
//                break;
//            case 3:
//                cout << "Enter the position & the new object" << endl;
//                cin >> pos;
//                fflush(stdin);
//                getline(cin, *str);
//                myList->update(pos, str);
//                break;
//            case 4:
//                cout << "Enter the position of the object to delete" << endl;
//                cin >> pos;
//                myList->remove(pos);
//                break;
//            default:
//                cout << "\nBad Option!";
//        }
//    } while (opt != 0);
//}
