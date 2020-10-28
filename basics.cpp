//
// Created by Alexander P on 20/05/17.
//
#include <algorithm>
#include "my_header"
#include "lambdaFunction.cpp"
//#include "Shape.h"
//#include "Circle.h"

using namespace std;


//a better way to make the classes
class Shape{
public:
    virtual double Area() = 0;
//    virtual double Perimeter() = 0;
};

class Circle : public Shape{
protected:
    double width;
public:
    Circle(double width){
        this->width = width;
    }
    double Area() override {
        return 3.141592654 * pow((width/2),2 );
    }
//    double Perimeter() override {}
};

int add(int, int  = 0){
    return 0;
}

//################################################
struct shape{
    double width, heigth;
    shape(double width = 1, double heigth = 1){
        this->width = width;
        this->heigth = heigth;
    }

    virtual double Area(){// so it can be overrided
        return width*heigth;
    }
private:
    int id;
};

struct circle: shape{
    circle(double width){
        this->width = width;
    }
    double Area() override{
        return 3.141592654 * pow((width/2), 2);
    };
};
//################################################

class Box{
public:
    double length, width, breath;
    string boxString;
    Box(){
        length = 1;width = 1;breath = 1;
    }
    Box(double length, double width, double breadth){
        this->length = length;
        this->width = width;this->breath = breadth;
    }
    Box& operator ++ (){
        length++;
        width++;
        breath++;
        return *this;
    }
    operator const char*(){
        ostringstream boxStream;
        boxStream << "Box: " << length<<','<<width<<','<<breath<<endl;
        boxString = boxStream.str();
        return boxString.c_str();
    }
    Box operator + (const Box& box2){
        Box boxSum;
//        boxSum.length += box2.length;
//        boxSum.width += box2.width;
//        boxSum.breath += box2.breath;
        boxSum.length = length + box2.length;
        boxSum.width =  width + box2.width;
        boxSum.breath = breath + box2.breath;
        return boxSum;
    }
    bool operator == (const Box& box2){
        return ((length==box2.length)&&(width==box2.width)&&(breath==box2.breath));
    }
};
//################################################

void ShowArea(Shape& shape){
    cout << "Area: " << shape.Area() << endl;
}


// i order to make this run change 'M' to 'm' in the next line
int MainBasics(/*int argc, char **argv*/) {
    string s1 = "I'm a string...\n";
    cout << s1;

    //convert from string to int: stoi
    //convert from string to float: stof
//    int n1 = stoi(s1);
//    cout << endl<< n1;

    int age = 0;
    cout << "\nEnter your age: ";
//    cin >> age;
    bool canIVote = (age >= 18) ? true : false;
    cout.setf(
            ios::boolalpha);  // without this, at the moment you print out canIVote, it gives 0/1 instead of false/true
    cout << "Can you vote?: " << canIVote << endl;

    int arr1[5] = {4, 7, 8, 9, 4};

    //vectors
    vector<int> vNums(2);
    vNums[0] = 1;
    vNums[1] = 5;
    cout << vNums[0] << endl;
    vNums.push_back(3);  // add an element at the end
//    cout << vNums. << endl;
    for (auto i: vNums) { // in this case auto = int
        cout << i << ' ';
//        cout << typeid(i).name();
    }

    cout << '\n' << endl;
    int i = 1;
    while (i <= 20) {
        if ((i % 2) == 0) {
            i++;
            continue; // if this 'if' is true, when reach this line, the next executed line will return from while
        }
        if (i == 15) break;
        cout << i << ' ';
        i++;
    }
//################################################
//################################################
    // use of stringstream
    vector<string> words;
    stringstream ss("Some random words ...");
    string word;
    while (getline(ss, word, ' '))// this means the same as the next while loop
        words.push_back(word);

    ss.clear();

    while (ss >> word) // reads automatically a word for each founded space in ss
        words.push_back(word);

    cout << endl;
    for (auto w: words)  // this means the same as the next for loop
        cout << w << '/';

    cout << endl;
    for (const auto &w: words)
        cout << w << '/';


//    ss.clear();

    stringstream sstream;
    sstream << 100 << '\n' << 200 << '\t' << 5; // instead of '\n' or '\t' cold be ' '

    int foo,bar;
    string m;
    sstream >> foo >> bar >> m;

    cout << endl;
    cout << "foo: " << foo << '\n';
    cout << "bar: " << bar << '\n';
    cout << "m: " << m << '\n';

    //################################################
//################################################
//more uses of strings

    string string1 = "You're a string ...n";
    cout << "1st: " << string1[0] << endl;
    cout << "last: " << string1.back() << endl;
    string string2 = string1;
    string string3(string2, 4);// copy since the first 4 chars
    cout << string3 << endl;
    string string4 = string1 + " and I'm not";//combine 2 strings
    string4.append("!");

    cout << "Old string: " << string4 << endl;
    string4.erase(16, string4.size()-1);//14 is from where, and (string4.size()-1) is the quantity
    cout << "New string: " << string4 << endl;

    if (string4.find("string") != string::npos)//npos means the last position of the string, and helps to check if the string exists
        cout<<"String index: "<<string4.find("string")<<endl;

    cout << string4.substr(6,6) << endl;

    string2 = to_string(8+9);

    int arr[5] = {8, 5, 9, 6, 4};
    for(int i1: arr)
        cout << i1 << ' ';

    cout << endl << add(4) << endl;

//################################################
//################################################
    //exceptions
    int n1 = 10, n2 = 0;
    try {
        if (n2 == 0)
            throw "Division by 0!";//error message
        else cout<< n1 << '/' << n2 << '=' << n1/n2;
    }catch (const char* excep){
//        cout << typeid(excep).name();
        cout << "Error: "<< excep<< endl;
    }

//################################################
//################################################
    //using objects (classes)

//    Shape square(10);//you cannot create an object from an abstract class
//    Circle circle(10);
//    ShowArea(circle);


//################################################
//################################################
    //structs , more used to create new data types, cause classes are a little more complex

    shape forma(10, 10);
    cout <<"Square: "<< forma.Area() << endl;
    circle circulo(5);
    cout <<"Square: "<< circulo.Area() << endl;


//################################################
//################################################
//operator overrating
    Box box(10, 10, 10);
    ++box;
    cout << box << endl;
    Box box2(5, 5, 5);
    cout << "Box1 + Box2 = " << (box+box2) << endl;
    cout << endl << box.operator const char *() << endl;
    cout << "Box1 == Box2 = " << (box==box2) << endl;

    //################################################
//################################################
// lambda functions

    vector<int> vecVals = GenerateRandVect(10, 1, 50);
    for(auto val: vecVals)
        cout << val << ", ";

    cout<<endl;
    sort(vecVals.begin(), vecVals.end(), [](int x, int y){ return x < y;});

    for(auto val: vecVals)
        cout << val << ", ";

    cout << endl << *(vecVals.begin()) << endl; // vector.begin() is a pointer to the first value of a vector
    cout << endl << *(vecVals.end()-1) << endl;

    int liste[9]={4, 8, 5, 3, 6, 4};
    for(auto li : liste)
        cout<<li<<' ';

    cout<<'\n';
    for (auto li=0; liste[li]!=0; ++li )
        cout<<liste[li]<<' ';
    return 0;
}
