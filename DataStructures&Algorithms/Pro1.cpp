//
// Created by Alexander P on 20/08/11.
//

//#include "my_header"
#include "SLinkedList.h"

using namespace std;

struct song {
private:
    string name;
    string genre;
    int nWords;
    friend struct artist;
public:
};

struct playlist{
    SLinkedList<song> songs;
};

struct artist {
private:
    string name;
    SLinkedList<song> *songs;
};

template<typename E>
void menuPro1(SLinkedList<E> *myList) {
    int opt;
    string str;
    do {
        str.clear();
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
                myList->add(pos, str);
                break;
            case 2:
                cout << "All the elements in the list are: " << endl;
                pos = 0;
                while (pos < myList->size())
                    cout << myList->get(pos++) << ", ";
                break;
            case 3:
                cout << "Enter the position & the new object" << endl;
                cin >> pos;
                fflush(stdin);
                getline(cin, str);
                myList->update(pos, str);
                break;
            case 4:
                cout << "Enter the position of the object to delete" << endl;
                cin >> pos;
                myList->remove(pos);
                break;
            default:
                cout << "\nBad Option!";
        }
    } while (opt != 0);
}

