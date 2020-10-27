//
// Created by Alexander P on 20/09/03.
//

#include "iostream"
#include "BinarySearchTree.h"

using namespace std;

void menuTree();

int min() {
    auto *tree = new BinarySearchTree<int>;

//    tree->addRoot()
    menuTree();
    return 0;
}

//void menuTree() {
//    auto *nums = new BinarySearchTree<int>;
//
//    int opt, pos, *e = new int;
//    do {
//        cout << "1. Create" << endl;
//        cout << "2. Read" << endl;
//        cout << "3. Update" << endl;
//        cout << "4. Delete" << endl;
//        cout << "5. Search" << endl;
//        cout << "0. Exit" << endl;
//
//        cout << "Your option: ";
//        fflush(stdin);
//        cin >> opt;
//        switch (opt) {
//            case 1:
//                fflush(stdin);
//                cin >> pos;
//                e = new int;
//                fflush(stdin);
//                cin >> *e;
//                nums->add(*e);
//                break;
//            case 2:
//                cout << "All elements listed: " << endl;
//                for (int i: nums->inOrder())
//                    cout << i << ", " << endl;
//                break;
//            case 3: {
//                break;
//            }
//            case 4: {
//                break;
//            }
//        }
//    } while (opt != 0);
//}