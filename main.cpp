//#include <iostream>
//#include "bitset"
//#include "my_header"

#include "my_header"  //here are all the most important libraries
#include "second.h"

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

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

// driver function to test various inference
/*int main()
{
    // This call returns 3.44 of double type
    auto a=0.0,b=0.0;

    cin>>a>>b;
    cout << findMin(4, 7) << endl;
    cout << typeid(findMin(4, 7)).name()<<endl;

    // This call returns 3 of double type
    cout << findMin(5.4, 3) << endl;
    cout << typeid(findMin(5.4, 3)).name()<<endl;

    return 0;
}*/
