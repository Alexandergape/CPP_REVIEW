#include <utility>

#include "my_header"  //here are all the most important libraries
#include "second.h"
#include "DataStructures&Algorithms/SLinkedList.cpp"
#include "vector"
#include "list"
#include "iterator"
#include "DataStructures&Algorithms/BinarySearchTree.cpp"
#include "DataStructures&Algorithms/Graphs/Graph.cpp"
#include "DataStructures&Algorithms/Stack.h"
#include "DataStructures&Algorithms/Queue.h"
#include "DataStructures&Algorithms/SortMethods.cpp"
#include "DataStructures&Algorithms/SearchMethods.h"
#include "DataStructures&Algorithms/PriorityQueue.h"
//#include "DataStructures&Algorithms/Stack.cpp"
//#include "DataStructures&Algorithms/Queue.cpp"

using namespace std;

struct num {
    num() : n(1) {}

    int n;

    void ed(int nu) {
        n = nu;
    }
};


struct truck {
private:
    string model;
    int year;
    //SLinkedList<song> songs; // just an idea
public:
    truck() : year(5), model("CHEVRON") {//the default values are 5 and CHEVRON, is the same as the next 2 lines
    }

    truck(string mod, int yeah) {
        model = std::move(mod);
        year = yeah;
    }

    ~truck() {
//        model.clear(); // // not necessary
//        year=-1; // not necessary
//        delete this; // not necessary
    }

    bool operator<(const truck &AnotherTruck) const { // overriding '<' allows to sort in a list
        return (this->model.compare(AnotherTruck.model) < 0);
    }

    bool operator==(const truck &AnotherTruck) const {
        return (this->model == AnotherTruck.model);
    }

    bool operator>(const truck &AnotherTruck) const {
        return (this->model.compare(AnotherTruck.model) > 0);
    }

    bool operator!=(const truck &AnotherTruck) const {
        return (this->model != AnotherTruck.model);
    }

    string getModel() {
        return model;
    }

    void setModel(string Model) {
        model.clear();
        this->model = std::move(Model);
    }

    int getYear() const {
        return year;
    }
};

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template<class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b) {
    return (a < b) ? a : b;
}

void menuMainly();

void menuTree();

// driver function to test various inference
int main() {
    // This call returns 3.44 of double type
//    auto a=0.0,b=0.0;
//
//    cin>>a>>b;
//    cout << findMin(4, 7) << endl;
//    cout << typeid(findMin(4, 7)).name()<<endl;
//
//    // This call returns 3 of double type
//    cout << findMin(5.4, 3) << endl;
//    cout << typeid(findMin(5.4, 3)).name()<<endl;


    string *h;
    h = new string;
    h->append("vdfv fdv");
    *h = "onewd";
//    string *a = "one";
    vector<string> *v;//{h, "help me"};
    v = new vector<string>;
//    v={h, "help me"};
    v->push_back(*h);
    v->push_back("help me");

    // when creating a new SLinkedList is recommended to initialize using new, to avoid memory problems

    auto *truck1 = new truck();
    truck1->setModel("KIMOMO");
    cout << truck1->getModel() << endl; //////////////

    cout << "\n\n";
    auto *tr = new truck;
    auto *trucks = new SLinkedList<truck>(*tr/*(new truck)*/);//trucks->add(0, *new truck());
//    trucks->add(0, *truck1);
    cout << trucks->get(0).getModel() << endl;//////////////
    truck1->setModel("fe");
    cout << truck1->getModel() << endl;//////////////
    trucks->get(0).setModel("hui");// this does not work, and dont return errors
    cout << trucks->get(0).getModel() << endl;//////////////

    trucks->add(1, *truck1);
    trucks->get(1).setModel("new m");
    cout << truck1->getModel() << endl;
    cout << trucks->get(1).getModel() << endl;
    truck1->setModel("f*ck");
    cout << truck1->getModel() << endl;
    cout << trucks->get(1).getModel() << endl;
    cout << "trucks size: " << trucks->size() << endl;
//    trucks->remove(1);
    cout << truck1->getModel() << endl;

//    trucks->add(1, *new truck());

    cout << "\n";
//    trucks->add(0, *truck1);
    cout << &truck1 << endl;
    cout << &trucks << endl;
//    cout << &(trucks->get(/*trucks->size()-*/0)) << endl;
    trucks->addLast(*truck1);

    auto *trs = new vector<truck>();
    auto *tru = new truck;
    trs->push_back(*new truck());
    trs->at(0).getModel();

    cout << "shshsh" << endl;


    cout << trucks->get(1).getModel() << endl;
    trucks->get(1).setModel("new model 2030");
    cout << trucks->get(1).getModel() << endl;
    cout << truck1->getModel() << endl;
    truck1->setModel("2050");
    cout << trucks->get(1).getModel() << endl;
    cout << truck1 << endl;
//    cout << &(trucks->get(1)) << endl;


    auto *t = new truck("idk w", 99);
    trucks->add(2, *t);

//    trucks->add(2, (truck *)(new truck("idk w", 99)));
    (trucks->get(2)).setModel("IDK What"); // this does not work, and dont return errors
//    trucks->get(2).setModel("J");
//    t->setModel("yeah hah"); // this works now ahhaha
    cout << t->getModel() << endl; // this works now too ahhaha
    cout << trucks->get(2).getModel() << endl;//////////////

    auto *ints = new SLinkedList<int>();
    int *ha = new int;
    *ha = 9;
    ints->add(0, *ha);
    cout << endl << ints->get(0) << endl;
//    ints->a

//    for(truck tr: trucks)
    cout << endl << "3##################" << endl;
    for (int j = 0; j < trucks->size(); j++)
        cout << trucks->get(j).getModel() << ", " << trucks->get(j).getYear() << endl;

    auto *tr2 = new truck("aaa", 99);

    truck1->setModel("hg");
    tr2->setModel("aa");
    if (*truck1 < *tr2)
        cout << endl << "truck1 is less than tr2..."
             << endl; // you mus use '*' to access to the value instead of the memory location
    else if (*truck1 > *tr2) cout << "truck1 is greater than tr2..." << endl;
    else cout << "truck1 is equal to tr2..." << endl;

//    register g
    trucks->get(0).getModel();

    auto *graph = new Graph<double>();
//    graph->
    //auto aut= graph->idk();

//    menuMainly();
//    menuTree();



    testStack();
    testQueue();

    QuickSort(*trs, 0, int(trs->size() - 1));
//    merge(*trs, 0, 1, 2);
    mergeSort(*trs, 0, int(trs->size() - 1));


    trs->push_back(*truck1);
    cout << endl << int(trs->size());
    cout << endl << "Founded at: " << IterativeBinarySearch(*trs, *truck1) << endl;
    cout << endl << "Founded at: " << RecursiveBinarySearch(*trs, 0, int(trs->size()), *truck1) << endl;
    cout << endl << "Founded at: " << BinarySearch(*trs, *truck1) << endl;

    mainPQ();

    return 0;
}

void menuTree() {
    auto *nums = new BinarySearchTree<int>;

    int opt, pos, *e1, *e2 = new int;
    do {
        cout << endl << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Search" << endl;
        cout << "0. Exit" << endl;

        cout << "Your option: ";
        fflush(stdin);
        cin >> opt;
        switch (opt) {
            case 1:
                e1 = new int;
                fflush(stdin);
                cin >> *e1;
                nums->add(*e1);
                break;
            case 2: {
                cout << "All elements listed: " << endl;
                auto elements = nums->inOrder();
                if (!elements.empty())
                    for (int i: elements)
                        cout << i << ", ";
            }
                break;
            case 3: {
                e1 = new int;
                fflush(stdin);
                cin >> *e1;
                fflush(stdin);
                cin >> *e2;
                nums->update(*e2, *e1);
                break;
            }
            case 4:
                fflush(stdin);
                cin >> *e2;
                nums->remove(*e2);
                break;
            case 5:
                fflush(stdin);
                cin >> *e2;
                if (nums->search(*e2))
                    cout << nums->search(*e2)->getElement() << endl;
//                else cout << "Not found..." << endl;
                break;
        }
    } while (opt != 0);
    delete e2;
    delete nums;
}

void menuMainly() {
//    auto *list1 = new SLinkedList<Integer>;
    auto *nums = new SLinkedList<int>;

//    auto *trs = new SLinkedList<truck>;
    int opt, pos, *e = new int;
    do {
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Search" << endl;
        cout << "0. Exit" << endl;

        cout << "Your option: ";
        fflush(stdin);
        cin >> opt;
//        getline(cin, new int);
        switch (opt) {
            case 1:
                fflush(stdin);
                cin >> pos;
                e = new int;
                fflush(stdin);
                cin >> *e;
                nums->add(pos, *e);
                break;
            case 2:
                cout << "All elements listed: " << endl;
                for (int i = 0; i < nums->size(); i++)
                    cout << nums->get(i) << endl;
                break;
            case 3: {
                fflush(stdin);
                cin >> pos;
                e = new int;
                fflush(stdin);
                cin >> *e;
                nums->update(pos, *e);
                break;
            }
            case 4: {
                fflush(stdin);
                cin >> pos;
                nums->remove(
                        pos); // for just int values the value is not deleted, until you do manually: delete nums->get(pos); // so it does not have
                break;
            }
        }
    } while (opt != 0);
}
