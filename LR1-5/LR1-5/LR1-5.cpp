#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int N = 30000;
const int N1 = 10000;
//1
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


//2
int main() {
    ifstream f;
    f.open("input.txt");
    ofstream f2("output.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        cout << "File open" << endl;
        int n, m, d ,c;
        int b[N], k[N];

        while (!f.eof()) {
            f >> n;
            f >> m;
            f >> d;
            f >> c;
            for (int i = 0; i < m + 1; ++i) {
                f >> b[i];
                if (b[i] > n) {
                    f2 << "NO";
                    cout << "Completed";
                    f.close();
                    f2.close();
                    exit(0);
                }
            }
        }
        for (int j = 0; j < m + 1; ++j) {
            for (int i = 0; i < n; ++i) {
                int l = 1;
                l = (l + i) * d + c;
                if (l < 13) {
                    if (l == b[j]) {
                        k[j] = i + 1;
                        break;
                    }
                }
                else {
                    l = l % 13;
                    if (l == b[j]) {
                        k[j] = i + 1;
                        break;
                    }
                }
            }
        }
        f2 << "YES" << endl;
        for (int j = 0; j < m; ++j) {
            f2 << k[j] << " ";
        }
    }
    cout << "Completed";
    f.close();
    f2.close();
}


//3
int main() {
    ifstream f;
    f.open("C:/Users/User/Desktop/input.txt");
    ofstream f2("C:/Users/User/Desktop/output.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        cout << "File open" << endl;
        int n;
        string s1, s2;
        while (!f.eof()) {
            f >> n;
            f >> s1;
            f >> s2;
        }

    }
    cout << "Completed";
    f.close();
    f2.close();
}


//4
int main() {
    ifstream f;
    f.open("input.txt");
    ofstream f2("output.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        cout << "File open" << endl;
        int n, a[N1], b[N1], c[N1];
        while (!f.eof()) {
            f >> n;
            for (int i = 0; i < n; ++i) {
                f >> a[i];
                f >> b[i];
                f >> c[i];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1 + i; j < n; ++j) {
                int count = 0;
                if (a[i] == a[j]) {
                    count++;
                }
                if (b[i] == b[j]) {
                    count++;
                }
                if (c[i] == c[j]) {
                    count++;
                }
                if (count == 1) {
                    sum++;
                }
            }
        }
        f2 << sum;
    }
    cout << "Completed";
    f.close();
    f2.close();
}