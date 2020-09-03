//#include <iostream>
//#include "bitset"
//#include "my_header"

#include <utility>

#include "my_header"  //here are all the most important libraries
#include "second.h"
#include "DataStructures&Algorithms/SLinkedList.cpp"
#include "vector"
#include "list"
#include "iterator"

//typedef long long ll;
//
//int main(int argc, char **argv){
//    ios_base::sync_with_stdio(0);

//    string str = "My string\n";
//    cout<<str;
//
//    print(str);
//    imprime();
//    int* p_scalar = new int(5);
//    cout<<'\n'<<&p_scalar;
//    cout<<'\n'<<*p_scalar;
//    cout<<'\n'<<p_scalar;

//    cout<<
//}

using namespace std;

struct num {
    num() { n = 1; }

    int n;

    void ed(int nu) {
        n = nu;
    }
};


struct truck{
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

    ~truck(){
        model.clear();
        year=-1;
        delete this;
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

    //    auto *noi = new SLinkedList<float>;
    //    auto *nine = new float;
    //    *nine = 9.9;
    //    float i = 9;
    //    float *o;cout << "you " ;
    //    noi->add(0, *o); cout << " are " ;
    //    cout << &noi->get(0) << endl; cout << " here " ;

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

    //    cout << &trucks->get(trucks->size()-1) << endl;
    //    trucks->addLast(*truck1);
    //    cout << &trucks->get(trucks->size()-1) << endl;
    //    cout << trucks->size() << endl;

    auto *trs = new vector<truck>();
    auto *tru=new truck;
    trs->push_back(*new truck());
    trs->at(0).getModel();
//    trs->push_back(*trucks->get(1));

//    trs->push_back(*(new truck()));
//    cout << truck1->getModel() << endl;
//    cout << trs->at(0).getModel() << endl;
//    cout << trs->at(1).getModel() << endl;
//    truck1->setModel("3030");
//    cout << truck1->getModel() << endl;
//    cout << trs->at(0).getModel() << endl;
//    trs->at(0).setModel("3040");
//    cout << truck1->getModel() << endl;
//    cout << trs->at(0).getModel() << endl;
//    cout << trs->size() << endl;


    cout << "shshsh" << endl;


    cout << trucks->get(1).getModel() << endl;
    trucks->get(1).setModel("new model 2030");
    cout << trucks->get(1).getModel() << endl;
    cout << truck1->getModel() << endl;
    truck1->setModel("2050");
    cout << trucks->get(1).getModel() << endl;
    cout << truck1 << endl;
//    cout << &(trucks->get(1)) << endl;


//    trucks->update(0, *(new truck("fe", trucks->get(0).getYear())));
//    cout << trucks->get(0).getModel() << endl;//////////////
//
//    trucks->add(1, *(new truck/*("idk k", 99)*/));
//    cout << trucks->get(1).getModel() << endl;//////////////
//    cout << trucks->get(1).getYear() << endl;//////////////
//
//    cout << trucks->size() - 1 << endl;
//

    auto *t = new truck("idk w", 99);
    trucks->add(2, *t);

//    trucks->add(2, (truck *)(new truck("idk w", 99)));
    (trucks->get(2)).setModel("IDK What"); // this does not work, and dont return errors
//    trucks->get(2).setModel("J");
//    t->setModel("yeah hah"); // this works now ahhaha
    cout << t->getModel() << endl; // this works now too ahhaha
    cout << trucks->get(2).getModel() << endl;//////////////


//    cout << trucks->size();//////////////
//    trucks->remove()

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

    menuMainly();
    return 0;
}

//int mainMainly(){
//    auto *str=new SLinkedList<string>;
////    str->addLast("AHHH ...");
//    cout << "HELP";
//    menuMainly();
//}

struct Integer {
private:
    int *number;
public:
    explicit Integer(int &n) : number(&n) {}

    void set(int &n) {
        number = &n;
    }

    int *getVal() {
        return number;
    }
};

void menuMainly() {
    auto *list1 = new SLinkedList<Integer>;
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
//                list1->add(pos, *(new Integer(*e)));
                nums->add(pos, *e);
                break;
            case 2:
                cout << "All elements listed: " << endl;
//                for (int i = 0; i < list1->size(); i++)
//                    cout << &list1 << ", " << list1->get(i) << ", " << list1->get(i)->getVal() << ", "
//                         << *list1->get(i)->getVal() << endl;
//                cout << nums->size() << endl;
                for(int i=0; i< nums->size();i++)
                    cout /*<< &nums << ", " << &nums->get(i) << ", " */<< nums->get(i) << endl;
                break;
            case 3:{
                fflush(stdin);
                cin >> pos;
                e = new int;
                fflush(stdin);
                cin >> *e;
//                int *old=nums->get(pos);
//                list1->get(pos)->set(*e);
                nums->update(pos, *e);
//                cout << "old value: " << *old << ", " << old << endl;
                break;}
            case 4:{
                fflush(stdin);
                cin >> pos;
//                int *old, *old2;
//                old=nums->get(pos);
//                list1->remove(pos);
//                nums->removeFront();
                nums->remove(pos); // for just int values the value is not deleted, until you do manually: delete nums->get(pos); // so it does not have
//                delete nums->get(pos);
//                cout << "old value: " << *old << ", " << old << endl;
//                old2=old;
//                delete old;
//                cout << "old value: " << *old << ", " << old << endl;
//                cout << "old2 value: " << *old2 << ", " << old2 << endl;
                break;}
        }
    } while (opt != 0);
}
