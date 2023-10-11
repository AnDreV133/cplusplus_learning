//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//
//    while (t--) {
//        string s;
//        cin >> s;
//
//        long long prevCount = 1;
//        long long count;
//        vector<char> maxChar;
//        int flag = 1;
//        for (auto &c1: s) {
//            count = 0;
//            for (auto &c2: s) {
//                if (c1 == c2) {
//                    count++;
//                }
//            }
//
//            if (count > prevCount) {
//                maxChar.push_back(c1);
//                prevCount = count;
//            }
//
//
//        }
//
////        cout << maxChar;
//        int mini = s.length();
//        for (auto l: maxChar) {
//            long long maxlen = 0;
//            count = 0;
//            for (auto &c: s) {
//                if (c == l) {
//                    count = 0;
//                } else {
//                    count++;
//                }
//
//                if (count > maxlen) {
//                    maxlen = count;
//                }
//            }
//
//            int i = 0;
//            while ((1 << i) <= maxlen) {
//                i++;
//            }
//
//            if (i < mini)
//                mini = i;
//        }
//
//        if (mini == s.length()) {
//            long long maxlen = 0;
//            count = 0;
//            for (auto &c: s) {
//                if (c == s[1]) {
//                    count = 0;
//                } else {
//                    count++;
//                }
//
//                if (count > maxlen) {
//                    maxlen = count;
//                }
//            }
//
//            int i = 0;
//            while ((1 << i) <= maxlen - 2) {
//                i++;
//            }
//
//            if (i < mini)
//                mini = i;
//        }
//
//        if (not (s.length() == 2 and s[0] != s[1]))
//            cout << mini << '\n';
//        else
//            cout << 1 << '\n';
//    }
//
//    return 0;
//}