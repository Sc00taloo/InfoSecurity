#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream f;
    f.open("C:/Users/User/Desktop/input.txt");
    ofstream f2("C:/Users/User/Desktop/output.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        cout << "File open" << endl;
        string str;
        while (!f.eof()) {
            str = "";
            f >> str;
            reverse(str.begin(), str.end());
            f2 << str << " ";
        }
    }
    cout << "Completed" << endl;
    f.close();
    f2.close();
    return 0;
}

