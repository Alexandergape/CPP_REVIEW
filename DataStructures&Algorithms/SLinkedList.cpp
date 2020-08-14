//
// Created by Alexander P on 20/08/11.
//

#include "iostream"

using namespace std;

template<typename E>
class SLinkedList;

template<typename E>
class SNode {
public:
    SNode(const E &e, SNode<E> *n) {
        element = e;
        next = n;
    }

    E getElement() {
        return element;
    }

    SNode<E> getNext() {
        return next;
    }

    void setNext(SNode<E> *n) {
        next = n;
    }

private:
    E element;
    SNode<E> *next;

    friend class SLinkedList<E>;
};

template<typename E>
class SLinkedList {
public:
    SLinkedList() : head(NULL) {
        head = NULL;
        tail = NULL;
    } // constructor;

    ~SLinkedList() {
        while (!isEmpty()) removeFront();
        Size = 0;
    }

    bool isEmpty() const { return head == NULL; }// const means that this method wont change the object

    const E &front() const { return head->elem; }

    void addLast(const E &e) {
        SNode<E> *N = new SNode<E>(e, NULL);
        if (isEmpty()) head = N;
        else
            tail->setNext(N);
        tail = N;
        Size++;
    }

    void removeFront() {
        SNode<E> *old = head;
        head = old->next;
        delete old;
        Size--;
        if (Size == 0)tail = NULL;
    }

    E get(int pos) {
        return getNode(pos)->element;
    }

    int search(const E &e) {
        if (isEmpty()) return -1;
        SNode<E> *headCopy = head;
        int pos = -1;
        while (headCopy != NULL) {
            if (headCopy->element == e) {
                pos++;
                break;
            }
            pos++;
            headCopy = headCopy->next;
        }
        return pos;
    }

    int update(int pos, const E &newVal) {
        if (pos < 0 || pos >= Size) return 1;
        getNode(pos)->element = newVal;
        return 0;
    }

    int remove(int pos) {
        if (pos < 0 || pos >= Size) return 1;
        if (pos == 0)
            head = head->next;
        else if (pos < Size - 1) {
            SNode<E> *aux = getNode(pos - 1);
            aux->setNext(getNode(pos + 1));
        } else
            getNode(Size - 1)->setNext(NULL);
        Size--;
        if (Size == 0)tail = NULL;
        return 0; //SUCCESS
    }

    int add(int pos, const E &e) {
        if (pos < 0 || pos > Size) return 1;
        if (pos == 0)head = new SNode<E>(e, head);
        else if (pos < Size - 1) {
            SNode<E> *neu = new SNode<E>(e, getNode(pos));
            getNode(pos - 1)->setNext(neu);
            neu->setNext(getNode(pos + 1));
        } else {
            SNode<E> *aux = new SNode<E>(e, NULL);
            tail->setNext(aux);
            tail = aux;
        }
        if (Size == 0)tail = head;
        Size++;
        return 0;
    }

    int size() const { return Size; }

private:
    int Size = 0;
    SNode<E> *head;
    SNode<E> *tail;

    SNode<E> *getNode(int pos) {
        if (pos < 0 || pos >= Size) return NULL;

        SNode<E> *copyHead = head;
        while (pos > 0) {
            copyHead = copyHead->next;
            pos--;
        }
        return copyHead;
    }
};

template<typename E>
void menu(SLinkedList<E> &myList) {
    int opt;
    string str;

    do {
        str.clear();
        opt=0;
        cout << "\n1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "0. EXIT" << endl;
        cout << "Enter your option: ";

        fflush(stdin);
        cin >> opt;

        int pos;
        switch (opt) {
            case 1:
                cout << "Enter the position & the object" << endl;
                cin >> pos;
                fflush(stdin);
                getline(cin, str);
                myList.add(pos, str);
                break;
            case 2:
                cout << "All the elements in the list are: " << endl;
                pos = 0;
                while (pos < myList.size())
                    cout << myList.get(pos++)<<", ";
                break;
            case 3:
                cout << "Enter the position & the new object" << endl;
                cin >> pos;
                fflush(stdin);
                getline(cin, str);
                myList.update(pos, str);
                break;
            case 4:
                cout << "Enter the position of the object to delete" << endl;
                cin >> pos;
                myList.remove(pos);
                break;
        }
    } while (opt != 0);
}

int main() {
    SLinkedList<string> str;
//    str.addLast("AHHH ...");
    cout << "HELP";
    menu(str);
//    str.search()
}
