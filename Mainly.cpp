//#include <iostream>
//#include "bitset"
//#include "my_header"

#include <utility>

#include "my_header"  //here are all the most important libraries
#include "second.h"
#include "DataStructures&Algorithms/SLinkedList.cpp"
#include "vector"

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

struct num{
    num(){n=1;}
    int n;
    void ed(int nu){
        n=nu;
    }
};


struct truck {
private:
    string model;
    int year;
    //SLinkedList<song> songs; // just an idea
public:
    truck() : year(5), model("CHEVRON") {//the default values are 5 and CHEVRON, is the same as the next 2 lines
//        model="CHEVRON";
//        year=5;
    }

    truck(string mod, int yeah) {
        model = std::move(mod);
        year = yeah;
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


//int n=9;
//SLinkedList<int> b;

//    vector<string> st{"ahh df"};
//    SLinkedList<string> a=new SLinkedList<string>(st);
    string a = "one";
    vector<string> v{a, "help me"};

    // when creating a new SLinkedList is recommended to initialize using new, to avoid memory problems

    auto *c = new SLinkedList<string>(a);// a is not stored in c, idk why
    c->add(0, a);
    cout << c->get(0) << endl;

    auto *n = new SLinkedList<string>(v);
    cout << n->get(0) << endl;
    cout << n->get(1) << endl;

    vector<int> in{8, 4};
    in.push_back(9);
    auto *o = new SLinkedList<int>(in); //working fine

    cout << o->get(0) << endl;//////////////
    cout << o->size() << endl;//////////////
    o->update(1, 98);
    cout << o->get(1) << endl;//////////////


//    auto nu=new SLinkedList<num>;
//    num *u=new num;
//    nu->add(0, *(new num));
//    cout<<endl<<nu->get(0)n<<endl;
//    nu->get(0).ed(9);
//    cout<<endl<<nu->get(0).n<<endl;



    SLinkedList m(v); // not sure if this is the correct way to initialize
    cout << m.get(0) << endl;

    auto ah = new SLinkedList<int>;// not sure if this is the correct way to initialize
    ah->add(0, 89);
    cout << ah->get(0) << endl;

    auto *noi = new SLinkedList<float>;
    noi->add(0, 9.9);
    cout << noi->get(0) << endl;
//    return 0;

    auto *truck1 = new truck;
    truck1->setModel("KIMOMO");
    cout << truck1->getModel() << endl; //////////////

    auto *trucks = new SLinkedList<truck>(*(new truck));
//    trucks->add(0, *truck1);
    cout << trucks->get(0).getModel() << endl;//////////////
    truck1->setModel("fe");
    cout << truck1->getModel() << endl;//////////////
    trucks->get(0).setModel("hui");// this does not work, and dont return errors
    cout << trucks->get(0).getModel() << endl;//////////////

    trucks->update(0, *(new truck("fe", trucks->get(0).getYear())));
    cout << trucks->get(0).getModel() << endl;//////////////

    trucks->add(1, *(new truck/*("idk k", 99)*/));
    cout << trucks->get(1).getModel() << endl;//////////////
    cout << trucks->get(1).getYear() << endl;//////////////

    cout << trucks->size() - 1 << endl;

    trucks->add(2, *(new truck("idk w", 99)));
    (trucks->get(2)).setModel("IDK What"); // this does not work, and dont return errors
    trucks->get(2).setModel("J");
    cout << trucks->get(2).getModel() << endl;//////////////
//    cout << trucks->size();//////////////
//    trucks->remove()
    return 0;
}

//int main(){
//    auto *str=new SLinkedList<string>;
//    str->addLast("AHHH ...");
//    cout << "HELP";
//    menu(str);
//}
