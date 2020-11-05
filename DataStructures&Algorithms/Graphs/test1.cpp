#include "/media/alexander/Backup/Documents/Projects/C++/First_Steps_With_C++/my_header"
#include <map>
#include <hashtable.h>
// #include <hash_map> // old
#include <unordered_map>
#include <grp.h>

// /media/alexander/Backup/Documents/Projects/C++/First_Steps_With_C++/my_header

using namespace std;

int mainTest()
{
    map<int, char> M;
    M.insert(pair<int, char>(8, 'a'));

    cout << endl
         << M.at(8) << endl;

    cout << M.size() << endl;

    hash<int> hashInt;
    int a = 78;
    int Hash8 = hashInt(a);
    cout << Hash8 << endl;

    hash<string> hashString;
    string s = "a";

    cout << hashString("a") << endl;
    cout << hashString(s) << endl;

    hash<char> hashChar;
    cout << hashChar('A') << endl;

    hash<int*> hashPtr; 

    return 0;
}