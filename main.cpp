//#include <fstream>
//#include <iostream>
//#include <ctime>
//#include <iomanip>
//
//struct CalendarNote {
//    string title;
//    string description;
//    time_t date;
//};
//
//void inputCalendarNote(CalendarNote &cn) {
//    cin >> cn.title >> cn.description >> cn.date;
//}
//
//void outputCalendarNote(const CalendarNote &cn) {
//    cout << cn.title << ' ' << cn.description << ' ' << cn.date << '\n';
//}
//
//istream &operator>>(istream &in, CalendarNote &cn) {
//    in >> cn.title >> cn.description >> cn.date;
//    return in;
//}
//
//ostream &operator<<(ostream &out, const CalendarNote &cn) {
//    out << cn.title << ":\n" << cn.description << '\n' << put_time(localtime(&cn.date), "%Y.%m.%d") << '\n';
//    return out;
//}
//
//long long getSum(const string &filename) {
//    ifstream inputFile(filename);
//
//    if (!inputFile)
//        throw runtime_error("File doesn't exist");
//    else {
//        int x;
//        long long sum = 0;
//        while (inputFile >> x)
//            sum += x;
//
//        return sum;
//    }
//}
//
//long long getSumOfMaxesInRows(const string &filename) {
//    ifstream inputFile(filename);
//
//    if (!inputFile)
//        throw runtime_error("File doesn't exist");
//    else {
//        int n;
//        inputFile >> n;
//        int m;
//        inputFile >> m;
//
//        long long sum = 0;
//        for (int i = 0; i < n; ++i) {
//            int bufMax;
//            inputFile >> bufMax;
//            int buf;
//            for (int j = 1; j < m; ++j) {
//                inputFile >> buf;
//                bufMax = max(bufMax, buf);
//            }
//
//            sum += bufMax;
//        }
//
//        return sum;
//    }
//}
//
//#include <iostream>
//#include <vector>
//#include <set>
//
//int *getmem(size_t partSize) {
//    return new int[partSize];
//}
//
//vector<int *> getParts(int nParts, size_t partSize) {
//    vector<int *> VofA;
//    try {
//        for (int i = 0; i < nParts; ++i)
//            VofA.push_back(getmem(partSize));
//
//        return VofA;
//    } catch (const bad_alloc &e) {
//        clog << "free dynamic memory" << '\n';
//        for (auto arr: VofA)
//            delete[] arr;
//
//        throw;
//    }
//}
//
//void generatePermutations_recursion(set<int> &s, int n,
//                                    vector<int> &v,
//                                    ostream &out) {
//    for (auto &si: s) {
//        v.push_back(si);
//
//        if (v.size() == n) {
////            out << "{";
//            for (auto &elem: v) {
////                out << elem << ' ';
//            }
////            out << "}\n";
//        } else {
//            auto copy = s;
//            copy.erase(si);
//            generatePermutations_recursion(copy, n, v, out);
//        }
//
//        v.pop_back();
//    }
//}
//
//void generatePermutations(set<int> &s, ostream &out) {
//    vector<int> tmp;
//    generatePermutations_recursion(s, s.size(), tmp, out);
//}
//
//
//int main() {
//    for (int i = 1; i <= 15; ++i) {
//        set<int> s;
//        for (int j = 0; j < i; ++j) {
//            s.insert(j);
//        }
//        unsigned int start_time = clock(); // начальное время
//        generatePermutations(s, cout);
//        unsigned int end_time = clock(); // конечное время
//        unsigned int search_time = end_time - start_time;
//        cout << i << ' ' << search_time << '\n';
//    }
//
//    return 0;
//}
//
//void generateSubsets_recursion(const vector<int> &s, vector<int> &v, int i, ostream &out) {
//    for (int x = 0; x <= 1; x++) {
//        v[i] = x;
//
//        if (i == v.size() - 1) {
//            out << "{ ";
//            for (auto &elem: v) {
//                out << elem;
//            }
//            out << "}\n";
//        } else
//            generateSubsets_recursion(s, v, i + 1, out);
//    }
//}
//
//void generateSubsets(vector<int> &set, ostream &out) {
//    vector<int> tmp;
//    generateSubsets_recursion(set, tmp, 0, out);
//}
//
//#include <iostream>
//#include <tuple>
//#include <vector>
//#include <valarray>
//
//using namespace std;
//
//bool isFunction(vector<vector<bool>> c) {
//    long long count;
//    for (int i = 0; i < c.size(); ++i) {
//        count = 0;
//        for (int j = 0; j < c[0].size(); ++j) {
//            if (c[i][j] == 1)
//                count++;
//
//            if (count > 1)
//                break;
//        }
//
//        if (count > 1)
//            return false;
//    }
//
//    return true;
//}
//
//bool isSpecificFunction(vector<vector<bool>> c) {
//    long long count;
//    for (int i = 0; i < c.size(); ++i) {
//        count = 0;
//        for (int j = 0; j < c[0].size(); ++j) {
//            if (c[i][j] == 1)
//                count++;
//
//            if (count > 1)
//                break;
//        }
//
//        if (count != 1)
//            return false;
//    }
//
//    return true;
//}
//
//bool isSurjection(vector<vector<bool>> c) {
//    long long count;
//    for (int j = 0; j < c[0].size(); ++j) {
//        count = 0;
//        bool isOneLink = true;
//        for (int i = 0; i < c.size(); ++i) {
//            if (c[i][j] == 1) {
//                count++;
//                for (int subJ = j + 1; subJ < c[0].size(); ++subJ)
//                    if (c[i][subJ] == 1) {
//                        isOneLink = false;
//                        break;
//                    }
//            }
//
//            if (!isOneLink)
//                return false;
//        }
//
//        if (count == 0)
//            return false;
//    }
//
//    return true;
//}
//
//bool isInjection(vector<vector<bool>> c) {
//    long long count;
//    for (int j = 0; j < c[0].size(); ++j) {
//        count = 0;
//        bool isOneLink = true;
//        for (int i = 0; i < c.size(); ++i) {
//            if (c[i][j] == 1) {
//                count++;
//                for (int subJ = j + 1; subJ < c[0].size(); ++subJ)
//                    if (c[i][subJ] == 1) {
//                        isOneLink = false;
//                        break;
//                    }
//            }
//
//            if (!isOneLink || count > 1)
//                return false;
//        }
//    }
//
//    return true;
//}
//
//bool isBijection(vector<vector<bool>> c) {
//    long long count;
//    for (int j = 0; j < c[0].size(); ++j) {
//        count = 0;
//        bool isOneLink = true;
//        for (int i = 0; i < c.size(); ++i) {
//            if (c[i][j] == 1) {
//                count++;
//                for (int subJ = j + 1; subJ < c[0].size(); ++subJ)
//                    if (c[i][subJ] == 1) {
//                        isOneLink = false;
//                        break;
//                    }
//            }
//
//            if (!isOneLink || count > 1)
//                return false;
//        }
//
//        if (count == 0)
//            return false;
//    }
//
//    return true;
//}
//
//long long getIntFromBin(const char *begin, const char *end) {
//    long long term = 1;
//    long long val = 0;
//    if (*begin == '0') {
//        while (begin < end) {
//            end--;
//            if (*end == '1')
//                val += term;
//
//            term <<= 1;
//        }
//
//        return val;
//    } else {
//        while (begin < end) {
//            end--;
//            if (*end == '0')
//                val += term;
//
//            term <<= 1;
//        }
//
//        return -val - 1;
//    }
//}
//
//long long getIntFromBinInSimplePresentation(const char *begin, const char *end) {
//    int sign = (*begin == '-') ? -1 : 1;
//    if (sign < 0) begin++;
//
//    long long term = 1;
//    long long val = 0;
//    while (begin < end) {
//        end--;
//        if (*end == '1')
//            val += term;
//
//        term <<= 1;
//    }
//
//    return sign * val;
//}
//
//double getFloatFromBin(const char *begin, const char *end) {
//    int sign = (*begin == '1') ? -1 : 1;
//
//    long long shift = getIntFromBinInSimplePresentation(begin + 1, begin + 9) - 127;
//
//    double term = pow(2, shift);
//    double val = term;
//    begin += 9;
//    while (begin < end) {
//        term /= 2;
//        if (*begin == '1')
//            val += term;
//
//        begin++;
//    }
//
//    return ((double) val) * sign;
//}
//
//double getFloatFromBinInSimplePresentation(const char *begin, const char *end) {
//    int sign = (*begin == '-') ? -1 : 1;
//    if (sign < 0) begin++;
//
//    const char *splitPoint = begin;
//    while (splitPoint < end && *splitPoint != '.')
//        splitPoint++;
//
//    long long intPart = getIntFromBinInSimplePresentation(begin, splitPoint);
//
//    double term = 0.5;
//    double val = 0;
//    while (splitPoint < end) {
//        splitPoint++;
//        if (*splitPoint == '1')
//            val += term;
//
//        term /= 2;
//    }
//
//    return ((double) intPart + val) * sign;
//}
//
//

#include <vector>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

void updateBetween(vector<vector<bool>> A, vector<vector<bool>> B) {
    int maxX = max(A.size(), B.size());
    int maxY = max(A[0].size(), B[0].size());

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < maxY - A[i].size(); ++j)
            A[i].push_back(false);

    for (int i = 0; i < maxX - A.size(); ++i) {
        vector<bool> temp(maxY);
        A.push_back(temp);
    }

    for (int i = 0; i < B.size(); ++i)
        for (int j = 0; j < maxY - B[i].size(); ++j)
            B[i].push_back(false);

    for (int i = 0; i < maxX - B.size(); ++i) {
        vector<bool> temp(maxY);
        B.push_back(temp);
    }
}

int updateToSquare(vector<vector<bool>> A) {
    int maxMetric = max(A.size(), A[0].size());

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < maxMetric - A[i].size(); ++j)
            A[i].push_back(false);

    for (int i = 0; i < maxMetric - A.size(); ++i) {
        vector<bool> temp(maxMetric);
        A.push_back(temp);
    }

    return maxMetric;
}

vector<vector<bool>> oper2(bool(*func)(vector<vector<bool>> &, vector<vector<bool>> &, int, int),
                           vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = func(A, B, i, j);
        }
    }

    return C;
}

vector<vector<bool>> oper1(bool(*func)(vector<vector<bool>> &, int, int), vector<vector<bool>> A) {
    int maxMetric = updateToSquare(A);

    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = func(A, i, j);
        }
    }

    return C;
}

bool operBool(bool(*func)(vector<vector<bool>> &, vector<vector<bool>> &, int, int),
              vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (!func(A, B, i, j))
                return false;
        }
    }

    return true;
}

bool inclusionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;
        }
    }

    return true;
}

bool equalOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }

    return true;
}

bool strictInclusionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    bool flag = false;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if (A[i][j] == 1 && B[i][j] == 0)
                return false;

            if (A[i][j] != B[i][j])
                flag = true;
        }
    }

    return flag;
}

//vector<vector<bool>> unionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
//    updateBetween(A, B);
//
//    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
//    for (int i = 0; i < A.size(); ++i) {
//        for (int j = 0; j < A[i].size(); ++j) {
//            C[i][j] = A[i][j] || B[i][j];
//        }
//    }
//
//    return C;
//}

vector<vector<bool>> intersectionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && B[i][j];
        }
    }

    return C;
}

vector<vector<bool>> difOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && !B[i][j];
        }
    }

    return C;
}

vector<vector<bool>> symDifOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[i][j] && !B[i][j] || !A[i][j] && B[i][j];
        }
    }

    return C;
}

vector<vector<bool>> additionOper(vector<vector<bool>> A) {
    int maxMetric = updateToSquare(A);

    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = !A[i][j];
        }
    }

    return C;
}

vector<vector<bool>> inversionOper(vector<vector<bool>> A) {
    int maxMetric = updateToSquare(A);

    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            C[i][j] = A[j][i];
        }
    }

    return C;
}

void inversionOper_(vector<vector<bool>> &A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            bool temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

bool reflexivityOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i) {
        if (!A[i][i])
            return false;
    }

    return true;
}

bool antiReflexivityOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i) {
        if (A[i][i])
            return false;
    }

    return true;
}

bool symmetryOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (A[i][j] != A[j][i]) {
                cout << "Not symmetry because pairs ("
                     << i + 1 << ',' << j + 1 << ") and ("
                     << j + 1 << ',' << i + 1 << ") not equal\n";
                return false;
            }

    cout << "Symmetry";
    return true;
}

bool antiSymmetryOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (A[i][j] == A[j][i])
                return false;

    return true;
}

bool transitivityOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            for (int k = 0; k < A.size(); ++k)
                if (A[i][k] && A[k][j] && !A[i][j]) {
                    cout << "Not transitivity because for pairs ("
                         << i + 1 << ',' << k + 1 << ") and (" << k + 1 << ',' << j + 1
                         << ") not pair (" << i + 1 << ',' << j + 1 << ") \n";
                    return false;
                }

    cout << "Transitivity\n";
    return true;
}

bool antiTransitivityOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            for (int k = 0; k < A.size(); ++k)
                if (A[i][k] && A[k][j] && A[i][j])
                    return false;

    return true;
}

bool fullyOper(vector<vector<bool>> A) {
    updateToSquare(A);

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A.size(); ++j)
            if (!(A[i][j] && !A[j][i] || !A[i][j] && A[j][i]))
                return false;

    return true;
}

bool toleranceOper(vector<vector<bool>> A) {
    return reflexivityOper(A) && symmetryOper(A);
}

bool equalityOper(vector<vector<bool>> A) {
    return reflexivityOper(A) && symmetryOper(A) && transitivityOper(A);
}

bool orderOper(vector<vector<bool>> A) {
    return antiSymmetryOper(A) && transitivityOper(A);
}

bool looseOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && reflexivityOper(A);
}


bool strictOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && antiReflexivityOper(A);
}

bool linearOrderOper(vector<vector<bool>> A) {
    return orderOper(A) && fullyOper(A);
}


bool nonStrictLinearOrderOper(vector<vector<bool>> A) {
    return looseOrderOper(A) && fullyOper(A);
}

bool strictLinearOrderOper(vector<vector<bool>> A) {
    return strictOrderOper(A) && fullyOper(A);
}


vector<vector<bool>> compositionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    int maxMetric1 = updateToSquare(A);
    int maxMetric2 = updateToSquare(B);

    int maxMetric = max(maxMetric1, maxMetric2);
    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));

    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            for (int k = 0; k < maxMetric; ++k)
                C[i][j] = C[i][j] || A[i][k] && A[k][j];

    return C;
}

void printRelation(vector<vector<bool>> A) {
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j)
            cout << A[i][j] << ' ';

        cout << '\n';
    }

    cout << '\n';
}

vector<vector<bool>> getRelationByCondition(bool (*func)(int, int), int departureAreaSize, int arrivalAreaSize) {
    vector<vector<bool>> res(departureAreaSize, vector<bool>(arrivalAreaSize));

    for (int x = 1; x <= departureAreaSize; ++x) {
        for (int y = 1; y <= arrivalAreaSize; ++y) {
            res[x - 1][y - 1] = func(x, y);
        }
    }

    return res;
}

bool conditionA(int x, int y) {
    return x < 11 && y < 11 && x % 2 == 0 && y > x;
}

bool conditionB(int x, int y) {
    return x < 11 && y < 11 && ((x - y == 1) || (x + y == 11));
}

bool conditionC(int x, int y) {
    int subSet1[] = {2, 5, 8, 9, 10};
    int subSet2[] = {1, 3, 5, 10};
    for (int i = 0; i < 5; ++i)
        if (x == subSet1[i])
            for (int j = 0; j < 4; ++j)
                if (y == subSet2[j])
                    return x < 11 && y < 11;

    return false;
}

bool conditionSub(int x, int y) {
    return x < 11 && y < 11
           && (
                   (x == 2 && y == 1) ||
                   (x == 1 && y == 4)
           );
}

void printCoord(vector<vector<bool>> A) {
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (A[i][j]) {
                cout << '(' << j + 1 << ',' << i + 1 << ") ";
            }
        }
    }

    cout << '\n';
}

////    printCoord(A);
////    printCoord(B);
////    printCoord(C);
//
////    printRelation(A);
//
////    vector<vector<bool>> A = {
////            {0, 1, 0, 1},
////            {1, 0, 0, 1},
////            {1, 0, 1, 0}
////    };
////
////    vector<vector<bool>> B = {
////            {0, 1, 0, 1},
////            {1, 0, 0, 1},
////            {1, 0, 1, 0}
////    };
////
////    printRelation(A);
////    printRelation(B);
////    printf(inclusionOper(A, B) ? "true\n" : "false\n");
////    printf(equalOper(A, B) ? "true\n" : "false\n");
////    printf(strictInclusionOper(A, B) ? "true\n" : "false\n");
////    printf("\n");
//
////    printRelation(intersectionOper(inversionOper(A), B));
////    printRelation(difOper(additionOper(A), C));
////    printRelation(unionOper(intersectionOper(inversionOper(A), B), difOper(additionOper(A), C)));
//
////    cout << toleranceOper(A) << ' ' << equalityOper(A) << ' ' << orderOper(A) << '\n';
////    cout << toleranceOper(B) << ' ' << equalityOper(B) << ' ' << orderOper(B) << '\n';
////    cout << toleranceOper(C) << ' ' << equalityOper(C) << ' ' << orderOper(C) << '\n';
//
////    printRelation(inversionOper(A));
////
////    printRelation(unionOper(A, B));
////    printRelation(intersectionOper(A, B));
////    printRelation(difOper(A, B));
////    printRelation(symDifOper(A, B));
////    printRelation(compositionOper(A, B));
//
//
////    char s1[] = "-101010";
////    cout << getIntFromBinInSimplePresentation(s1, s1 + 7) << '\n';
////
////    char s2[] = "101010.011010111000010101";
////    cout << getFloatFromBinInSimplePresentation(s2, s2 + 25) << '\n';
////
////    char s3[] = "00000000000000000000000000101010";
////    cout << getIntFromBin(s3, s3 + 32) << '\n';
////
////    char s3_[] = "11111111111111111111111111010110";
////    cout << getIntFromBin(s3_, s3_ + 32) << '\n';
////
////    char s4[] = "01000010001010011010111000010101";
////    cout << getFloatFromBin(s4, s4 + 32) << '\n';
//
//
//
////    vector<vector<bool>> c = {
////            {0, 0, 0, 1},
////            {0, 0, 1, 0},
////            {0, 1, 0, 0},
////            {1, 0, 0, 0}
////    };
////
////    cout << isFunction(c) << endl;
////    cout << isSpecificFunction(c) << endl;
////    cout << isSurjection(c) << endl;
////    cout << isInjection(c) << endl;
////    cout << isBijection(c) << endl;
//
//    return 0;
//}

//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//enum {
//    DNF = 1,
//    KNF = 2
//};
//
//struct BinFunc {
//    int type; // ДНФ или КНФ
//    unsigned numOfVariables; // Кол-во переменных
//    vector<char> names; // Названия переменных
//    vector<vector<short>> values; // Матрица состояний переменных
//};
//
//void setBinFunc(BinFunc &binFunc) {
//    // Ввод типа функции - ДНФ это или КНФ
//    cout << "Change type (1 - DNF, 2 - KNF):\n";
//    cin >> binFunc.type;
//    // Проверка указан тип или что-то иное
//    if (binFunc.type != DNF && binFunc.type != KNF) {
//        cerr << "Input error\n";
//        return;
//    }
//    // Устанавливаем кол-во переменных
//    cout << "Write num of variables\n";
//    cin >> binFunc.numOfVariables;
//    // Инициализируем вектора
//    binFunc.names = vector<char>();
//    binFunc.values = vector<vector<short>>(
//            1 << binFunc.numOfVariables,
//            vector<short>(binFunc.numOfVariables, -1)
//    );
//    // Запускаем цикл процесса задания ф-ии
//    cout << "Write '\\' to go to a new interpretation; write '0' to exit the input\n";
//    int counterOfInterpretation = 0;
//    while (true) {
//        // Спрашиваем переменную, которую будем изменять
//        char tempName;
//        cout << "Write name of variable or '\\', '0'\n";
//        cin >> tempName;
//        // 0 - конец ввода, \ - переход к след слагаемому
//        if (tempName == '0')
//            break;
//        else if (tempName == '\\') {
//            counterOfInterpretation++;
//            continue;
//        }
//        // В цикле ищем заданную переменную, если находим,
//        // инициализируем индекс, где стоит эта переменная
//        int indexOfVariable = -1;
//        for (int i = 0; i < binFunc.names.size(); ++i) {
//            if (tempName == binFunc.names[i]) {
//                indexOfVariable = i;
//                break;
//            }
//        }
//        // Если не нашли индекс, тогда записываем новую переменную,
//        // устанавливаем индекс, проверяем на допустимое кол-во переменных
//        if (indexOfVariable < 0) {
//            indexOfVariable = (int) binFunc.names.size();
//            if (indexOfVariable < binFunc.numOfVariables) {
//                binFunc.names.push_back(tempName);
//            } else {
//                cerr << "Amount names exceeded\n";
//                return;
//            }
//        }
//        // Определяем переменная с исключением или без
//        short tempState;
//        cout << "Write state of variable (0 - excluded, 1 - not excluded)\n";
//        cin >> tempState;
//        // Проверяем ввод
//        if (tempState != 0 && tempState != 1) {
//            cerr << "Input error\n";
//            return;
//        }
//        // Записываем состояние переменной
//        binFunc.values[counterOfInterpretation][indexOfVariable] = tempState;
//    }
//}
//
//bool checkResult(const BinFunc &binFunc) {
//    // Вводим значения
//    vector<int> checkedResult;
//    for (auto &ai: binFunc.names)
//        cout << ai << ' ';
//    cout << "set result for check\n";
//    for (int i = 0; i < binFunc.names.size(); ++i) {
//        int value;
//        cin >> value;
//        if (value != 0 && value != 1) {
//            cerr << "Input error\n";
//            return false;
//        }
//
//        checkedResult.push_back(value);
//    }
//    // Проверяем введённые значения с матрицей
//    for (int i = 0; i < binFunc.values.size(); ++i) {
//        bool isEqual = false;
//        for (int j = 0; j < binFunc.numOfVariables; ++j) {
//            // Пропускаем не введённые поля
//            if (binFunc.values[i][j] == -1)
//                continue;
//            // Проверяем введённые
//            if (binFunc.type == DNF && binFunc.values[i][j] == checkedResult[j]
//                || binFunc.type == KNF && binFunc.values[i][j] != checkedResult[j])
//                isEqual = true;
//            else {
//                isEqual = false;
//                break;
//            }
//        }
//        // Если в одной из итераций находится нужный набор,
//        // то выдаём результат
//        if (isEqual)
//            return binFunc.type == DNF;
//    }
//    // Иначе выводим обратный результат
//    return binFunc.type != DNF;
//}
//
//int main() {
//    BinFunc binFunc;
//    setBinFunc(binFunc);
//
//    for (auto &ai: binFunc.names)
//        cout << ai << "\t";
//    cout << '\n';
//    for (const auto &ai: binFunc.values) {
//        cout << '\n';
//        for (auto &aij: ai)
//            cout << aij << "\t";
//    }
//    cout << '\n';
//
//    while (true) {
//        cout << checkResult(binFunc) << '\n';
//    }
//
//    return 0;
//}

size_t numOfExecutions = 0;

vector<vector<bool>> unionOper(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);

    vector<vector<bool>> C(A.size(), vector<bool>(A[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            numOfExecutions++;
            C[i][j] = A[i][j] || B[i][j];
        }
    }

    return C;
}

vector<vector<bool>> compositionOperInj(vector<vector<bool>> A, vector<vector<bool>> B) {
    updateBetween(A, B);
    int maxMetric1 = updateToSquare(A);
    int maxMetric2 = updateToSquare(B);

    int maxMetric = max(maxMetric1, maxMetric2);
    vector<vector<bool>> C(maxMetric, vector<bool>(maxMetric));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            for (int k = 0; k < maxMetric; ++k) {
                numOfExecutions++;
                if (!C[i][j])
                    C[i][j] = A[i][k] && B[k][j];
                else
                    break;
            }
    return C;
}

vector<vector<bool>> getTransitiveClosureInj(vector<vector<bool>> &matrix) {
    numOfExecutions = 0;
    vector<vector<bool>> result = matrix;
    vector<vector<bool>> subMatrixForPow = matrix;

    for (int i = 1; i < matrix.size(); ++i) {
        subMatrixForPow = compositionOperInj(matrix, subMatrixForPow);
        result = unionOper(result, subMatrixForPow);
    }

    return result;
}

vector<vector<bool>> getTransitiveClosureByWarshellAlgorithmInj(vector<vector<bool>> &matrix) {
    numOfExecutions = 0;
    vector<vector<bool>> result = matrix;

    for (int z = 0; z < result.size(); ++z)
        for (int x = 0; x < result.size(); ++x)
            for (int y = 0; y < result.size(); ++y) {
                numOfExecutions++;
                result[x][y] = result[x][y] || result[x][z] && result[z][y];
            }

    return result;
}

vector<vector<bool>> generateRelationByRandom(int powerOfSet, int amountPair) {
    if (amountPair > pow(2, powerOfSet)) {
        cerr << "amount pair bigger than power of set";
        return {};
    }

    vector<vector<bool>> result = vector<vector<bool>>(powerOfSet, vector<bool>(powerOfSet));
    srand(time(nullptr));

    int i = 0;
    while (i < amountPair) {
        int x = rand() % powerOfSet;
        int y = rand() % powerOfSet;

        if (!result[x][y])
            result[x][y] = true;
        else
            continue;

        i++;
    }

    return result;
}

size_t getFuncN2Div4(size_t n) {
    return (size_t) pow(n, 2) / 4;
}

size_t getFuncN2Div2(size_t n) {
    return (size_t) pow(n, 2) / 2;
}

size_t getFuncN2Mult2Div3(size_t n) {
    return (size_t) pow(n, 2) * 2 / 3;
}

size_t getFuncN2(size_t n) {
    return (size_t) pow(n, 2);
}

void gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(ofstream& outpustStream, int powerOfSet, int amountPair,
                                                                    vector<vector<bool>> (*operation)(vector<vector<bool>>&)) {
    size_t minNumOfExecutions = ULONG_LONG_MAX;
    size_t maxNumOfExecutions = 0;
    for (int i = 0; i < 1000; ++i) {
        vector<vector<bool>> generatedRelation
                = generateRelationByRandom(powerOfSet, amountPair);

        operation(generatedRelation);

        minNumOfExecutions = min(numOfExecutions, minNumOfExecutions);
        maxNumOfExecutions = max(numOfExecutions, maxNumOfExecutions);
    }

    outpustStream << "N = " << powerOfSet << "; "
           << "amount pair = " << amountPair << "; "
           << "min k = " << minNumOfExecutions << "; "
           << "max k = " << maxNumOfExecutions << ".\n";
}

int main() {
//    vector<vector<bool>> A = {
//            {0, 1, 0, 0, 0},
//            {0, 0, 1, 0, 0},
//            {0, 0, 0, 0, 0},
//            {0, 1, 0, 1, 0},
//            {1, 0, 1, 0, 0}
//    };
//
//    printRelation(A);
//    printRelation(getTransitiveClosureInj(A));
//    printRelation(getTransitiveClosureByWarshellAlgorithmInj(A));

//    vector<vector<bool>> B = generateRelationByRandom(5, 4);
//    printRelation(B);

    ofstream fileStream("../testTransitiveClosure.txt");

    if (!fileStream.is_open()) {
        cerr << "File not open";
        exit(1);
    }

    for (int n = 5; n <= 15; n += 5) {
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n,  1, getTransitiveClosureInj);
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n,  1, getTransitiveClosureByWarshellAlgorithmInj);

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div4(n), getTransitiveClosureInj);
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div4(n), getTransitiveClosureByWarshellAlgorithmInj);

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Mult2Div3(n), getTransitiveClosureInj);
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Mult2Div3(n), getTransitiveClosureByWarshellAlgorithmInj);

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div2(n), getTransitiveClosureInj);
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2Div2(n), getTransitiveClosureByWarshellAlgorithmInj);

        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2(n), getTransitiveClosureInj);
        gettingMinNMaxNumOfExecutionsOn1000ExperimentWithWriteToStream(
                fileStream, n, (int) getFuncN2(n), getTransitiveClosureByWarshellAlgorithmInj);
    }

    fileStream.close();

    return 0;
}