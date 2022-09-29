#include <iostream>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const int N = 30000;
const int N1 = 10000;
//1
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    ifstream f;
//    f.open("C:/Users/User/Desktop/input.txt");
//    ofstream f2("C:/Users/User/Desktop/output.txt");
//    if (!f.is_open()) {
//        cout << "Error";
//    }
//    else {
//        cout << "File open" << endl;
//        string str;
//        while (!f.eof()) {
//            str = "";
//            f >> str;
//            reverse(str.begin(), str.end());
//            f2 << str << " ";
//        }
//    }
//    cout << "Completed" << endl;
//    f.close();
//    f2.close();
//    return 0;
//}
//
//
////2
//int main() {
//    ifstream f;
//    f.open("input.txt");
//    ofstream f2("output.txt");
//    if (!f.is_open()) {
//        cout << "Error";
//    }
//    else {
//        cout << "File open" << endl;
//        int n, m, d ,c;
//        int b[N], k[N];
//
//        while (!f.eof()) {
//            f >> n;
//            f >> m;
//            f >> d;
//            f >> c;
//            for (int i = 0; i < m + 1; ++i) {
//                f >> b[i];
//                if (b[i] > n) {
//                    f2 << "NO";
//                    cout << "Completed";
//                    f.close();
//                    f2.close();
//                    exit(0);
//                }
//            }
//        }
//        for (int j = 0; j < m + 1; ++j) {
//            for (int i = 0; i < n; ++i) {
//                int l = 1;
//                l = (l + i) * d + c;
//                if (l < 13) {
//                    if (l == b[j]) {
//                        k[j] = i + 1;
//                        break;
//                    }
//                }
//                else {
//                    l = l % 13;
//                    if (l == b[j]) {
//                        k[j] = i + 1;
//                        break;
//                    }
//                }
//            }
//        }
//        f2 << "YES" << endl;
//        for (int j = 0; j < m; ++j) {
//            f2 << k[j] << " ";
//        }
//    }
//    cout << "Completed";
//    f.close();
//    f2.close();
//}


//3
//int number_pere(char * s, int n) {
//    int unique = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        bool isUnique = true;
//        for (int j = i + 1; j < n; ++j)
//        {
//            isUnique = isUnique && (s[i] != s[j]);
//        }
//        if (isUnique) ++unique;
//    }
//
//    return unique;
//}
//
//bool func(char * a, int n) {
//    int k = number_pere(a, n);
//    if (k == n) {
//        return true;
//    }
//    else
//        return false;
//}

//bool number_poch_pere(char* a, int n) {
//    char temp = a[0];
//    for (int i = 0; i < n; i++) {
//        if (a[i] > temp) {
//            for (int j = i + 1; a[j - 1] = a[j]; ++j);
//            break;
//        }
//        else temp = a[i];
//    }
//}

//int search(char* a, char prov, int n) {
//    char b[255];
//    for (int i = 0; i < n + 1; ++i) {
//        
//    }
//}

void fStrCut(const string s, string& g)
{
    int flg = 0;
    int lS = s.length();
    int lG = g.length();
    int minLen = (lS > lG) ? lG : lS;
    for (int i = minLen - 1; i > -1; --i)
    {
        string sSub = s.substr(lS - 1 - i, i + 1);
        string gSub = g.substr(0, i + 1);
        if (sSub == gSub)
        {
            flg = 1;
            g = s + g.erase(0, i + 1);
            break;
        }
    }
    if (flg == 0)
        g = s + g;
}

bool help(string s, int count, int n) {
    bool flag = true;
    int mas[26];
    while (flag && n + 1 < s.size()) {
        for (int i = 0; i < 26; ++i) {
            mas[i] = 0;
        }
        for (int i = 0 + count; i < n + 1; ++i) {
            if (s[i] >= 65) {
                mas[s[i] - 65] = mas[s[i] - 65] + 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            if (mas[i] == 0) {
                for (int j = i; j < 26; ++j) {
                    if (mas[j] != 0) {
                        flag = false;
                        break;
                    }
                }
            }
            else {
                mas[i] -= 1;
                sum += mas[i];
            }
            if (!flag) {
                break;
            }
        }
        if (sum == 1 || sum == 0) {
            count++;
            n++;
        }
        else {
            flag = false;
            break;
        }
    }
    if (flag) {
        return true;
    }
    else
        return false;
}

int main() {
    ifstream f;
    f.open("C:/Users/User/Desktop/input.txt");
    ofstream f2("C:/Users/User/Desktop/output.txt");
    if (!f.is_open()) {
        cout << "Error";
    }
    else {
        cout << "File open" << endl;
        int n = 0;
        string s1, s2;
        while (!f.eof()) {
            f >> n;
            f >> s1;
            f >> s2;
        }
        f.close();

        int count = 0;
        int i = 0;

        string all[5];
        string s3 = s1 + s2;
        string s4 = s2 + s1;
        string moi = s2;
        fStrCut(s1, s2);
        fStrCut(s1, moi);

        if (help(s3, count, n)) {
            all[i] = s3;
            ++i;
        }
        if (help(s4, count, n)) {
            all[i] = s4;
            ++i;
        }
        if (help(s2, count, n)) {
            all[i] = s2;
            ++i;
        }
        if (help(moi, count, n)) {
            all[i] = moi;
            ++i;
        }
        string prov = all[0];
        for (i = 0; i < 4; ++i) {    
            if (all[i].size() < prov.size()) {
                prov = all[i];
            }
        }
        f2 << prov;
        f2.close();
        cout << "Completed";
        //snprintf(s3, sizeof s3, "%s%s", s1, s2);
        //char prov = 'A';
        //for (int j = 0; j < n * 2; ++j) {
        //    if (s3[j] >= prov) {
        //        prov = s3[j];
        //    }
        //}

        //cout << g << endl;

    }
    return 0;
}


//4
//int main() {
//    ifstream f;
//    f.open("input.txt");
//    ofstream f2("output.txt");
//    if (!f.is_open()) {
//        cout << "Error";
//    }
//    else {
//        cout << "File open" << endl;
//        int n, a[N1], b[N1], c[N1];
//        while (!f.eof()) {
//            f >> n;
//            for (int i = 0; i < n; ++i) {
//                f >> a[i];
//                f >> b[i];
//                f >> c[i];
//            }
//        }
//        int sum = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 1 + i; j < n; ++j) {
//                int count = 0;
//                if (a[i] == a[j]) {
//                    count++;
//                }
//                if (b[i] == b[j]) {
//                    count++;
//                }
//                if (c[i] == c[j]) {
//                    count++;
//                }
//                if (count == 1) {
//                    sum++;
//                }
//            }
//        }
//        f2 << sum;
//    }
//    cout << "Completed";
//    f.close();
//    f2.close();
//}