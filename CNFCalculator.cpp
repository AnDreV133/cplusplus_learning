//
// Created by dmitr on 12.10.2023.
//

#include <stack>
#include "CNFCalculator.h"


using namespace std;

States state;

inline bool isNumber(char t) {
    return t == '0' || t == '1';
}

inline bool isVariable(char t) {
    return (t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z');
}

inline bool isOperation(char t) {
    return (t == '|' || t == '&' || t == '-' || t == '>' || t == '~');
}

inline bool isOpeningPar(char t) {
    return t == '(';
}

inline bool isClosingPar(char t) {
    return t == ')';
}

inline bool isOperationOrOpeningPar(char t) {
    return isOperation(t) || isOpeningPar(t);
}

inline bool isExcluding(char t) {
    return t == '~';
}

inline bool isConjunction(char t) {
    return t == '&';
}

inline bool isDisjunction(char t) {
    return t == '|';
}

inline bool isTokenOfCNFExpression(char t) {
    return isVariable(t) || t == '|' || t == '&' || t == '~'
           || isOpeningPar(t) || isClosingPar(t);
}

inline int getIndexOfTokenInNamesOfValues(char t, const TableOfStateOfVariable &tableOfStateValues) {
    for (int i = 0; i < tableOfStateValues.namesOfValues.size(); ++i)
        if (t == tableOfStateValues.namesOfValues[i])
            return i;
    return -1;
}

template<typename T>
void addElemByIndexWithUpdateSizeAndInitializeWithValue(
        vector<T> &array, int const index, T const elem, T const initVal) {
    if (array.size() <= index)
        array.resize((index + 1), initVal);

    array[index] = elem;
}

void addStateByIndex(vector<short> &row, int const index, short const elem) {
    addElemByIndexWithUpdateSizeAndInitializeWithValue<short>(row, index, elem, state.NOTHING);
}

bool getResultByValuesByTableOfStateOfVariableInCNF(
        const vector<bool> &values, const TableOfStateOfVariable &tableOfStateOfVariable) {
    if (values.size() != tableOfStateOfVariable.namesOfValues.size()) {
        exit(1);
    }

    for (const auto &term: tableOfStateOfVariable.matrixOfConditionValues) {
        bool isEqual = false;
        for (int i = 0; i < term.size(); ++i) {
            // Пропускаем не введённые поля
            if (term[i] == state.NOTHING)
                continue;
            // Проверяем введённые
            if (term[i] != values[i])
                isEqual = true;
            else {
                isEqual = false;
                break;
            }
        }
        // Если в одной из итераций находится нужный набор,
        // то выдаём результат
        if (isEqual)
            return false;
    }
    // Иначе выводим обратный результат
    return true;
}

void generateBodyTruthTable(vector<vector<bool>> &truthTable, int index, int size, int current[]) {
    if (index == size) { // generated a full "solution"
        truthTable.emplace_back();
        for (int i = 0; i < size; i++) {
            truthTable.back().push_back(current[i]);
        }
    } else {
        for (int i = 0; i < 2; i++) {
            current[index] = i;
            generateBodyTruthTable(truthTable, index + 1, size, current);
        }
    }
}

vector<vector<bool>> getTruthTable(const TableOfStateOfVariable &tableOfStateOfVariable) {
    vector<vector<bool>> res;

    int buf[tableOfStateOfVariable.namesOfValues.size()];
    generateBodyTruthTable(res, 0, tableOfStateOfVariable.namesOfValues.size(), buf);

    for (auto &r: res) {
        r.push_back(getResultByValuesByTableOfStateOfVariableInCNF(r, tableOfStateOfVariable));
    }

    return res;
}


//TableOfStateOfVariable getTableOfStateOfVariableByCNFFunc(const string &expression) {
//    TableOfStateOfVariable tableOfStateOfVariable;
//
//    tableOfStateOfVariable.matrixOfConditionValues.emplace_back();
//    stack<char> stackOperations;
//    for (auto const &token: expression) {
//        if (isspace(token))
//            continue;
//
//        if (!isTokenOfCNFExpression(token)) {
//            cerr << "Bad input! token - " << token << " is not a logic operation.";
//            exit(1);
//        }
//
//        if (!stackOperations.empty() && !isOpeningPar(stackOperations.top()) &&
//            (isConjunction(token) || isDisjunction(token))) {
//            cerr << "Bad input! 1 token - " << token << "";
//            exit(1);
//        }
//
//        if (!stackOperations.empty() && isOpeningPar(stackOperations.top()) &&
//            (isClosingPar(token) || isDisjunction(token)))
//            stackOperations.pop();
//
//        if ((stackOperations.empty() || isOperationOrOpeningPar(stackOperations.top())) && isVariable(token)) {
//            int indexOfToken = getIndexOfTokenInNamesOfValues(token, tableOfStateOfVariable);
//            if (indexOfToken < 0) {
//                tableOfStateOfVariable.namesOfValues.push_back(token);
//                indexOfToken = (int) tableOfStateOfVariable.namesOfValues.size() - 1;
//            }
//
//            bool isExcluded = isExcluding(stackOperations.top());
//
//            addStateByIndex(tableOfStateOfVariable.matrixOfConditionValues.back(),
//                            indexOfToken,
//                            isExcluded ? state.EXCLUDED : state.NON_EXCLUDED);
//            if (isExcluded)
//                stackOperations.pop();
//
//            stackOperations.pop();
//        }
//
//        if (isExcluding(token))
//            stackOperations.push(token);
//
//        if (isConjunction(token)) {
//            stackOperations.push(token);
//            tableOfStateOfVariable.matrixOfConditionValues.emplace_back();
//        }
//
//        if (isDisjunction(token))
//            stackOperations.push(token);
//
//        if (isOpeningPar(token))
//            stackOperations.push(token);
//    }
//
//    return tableOfStateOfVariable;
//}

TableOfStateOfVariable getTableOfStateOfVariableByCNFFunc(const string &expression) {
    TableOfStateOfVariable tableOfStateOfVariable;
    tableOfStateOfVariable.matrixOfConditionValues.emplace_back();

    bool wasExcluding = false;
    bool wasOpeningPar = false;
    bool wasDisjunction = false;
    bool wasVariable = false;
    for (auto const &token: expression) {
        if (isspace(token))
            continue;

        if (!isTokenOfCNFExpression(token)) {
            cerr << "Bad input! token - " << token << " is not a logic operation.";
            exit(1);
        }

        if (wasDisjunction && isClosingPar(token))
            exit(1);

        if (wasVariable && isOperation(token))
            wasVariable = false;

        if (isOpeningPar(token))
            wasOpeningPar = true;

        if (isClosingPar(token))
            wasOpeningPar = false;

        if (isExcluding(token))
            wasExcluding = true;

        if (isDisjunction(token))
            wasDisjunction = true;

        if (isVariable(token)) {
            int indexOfToken = getIndexOfTokenInNamesOfValues(token, tableOfStateOfVariable);
            if (indexOfToken < 0) {
                tableOfStateOfVariable.namesOfValues.push_back(token);
                indexOfToken = (int) tableOfStateOfVariable.namesOfValues.size() - 1;
            }

            addStateByIndex(tableOfStateOfVariable.matrixOfConditionValues.back(),
                            indexOfToken,
                            wasExcluding ? state.EXCLUDED : state.NON_EXCLUDED);
            if (wasExcluding)
                wasExcluding = false;

            wasDisjunction = false;
            wasVariable = true;
        }

        if (isConjunction(token)) {
            if (wasOpeningPar || wasExcluding || wasDisjunction)
                exit(1);

            tableOfStateOfVariable.matrixOfConditionValues.emplace_back();
        }
    }

    return tableOfStateOfVariable;
}

bool isFormulaInconsistent(const TableOfStateOfVariable &tableOfStateOfVariable) {
    for (const auto &res: getTruthTable(tableOfStateOfVariable)) {
        if (res.back() != 0)
            return false;
    }

    return true;

}

bool isFormulaInconsistent(const string &expression) {
    return isFormulaInconsistent(getTableOfStateOfVariableByCNFFunc(expression));
}

void outputTableOfState(const TableOfStateOfVariable &tableOfStateValues) {
    for (auto &ai: tableOfStateValues.namesOfValues)
        cout << ai << "\t";
    cout << '\n';
    for (const auto &ai: tableOfStateValues.matrixOfConditionValues) {
        for (auto &aij: ai)
            cout << aij << "\t";
        cout << '\n';
    }
}

void outputMatrix(const vector<vector<bool>> &matrix) {
    for (const auto &ai: matrix) {
        for (const auto &aij: ai)
            cout << aij << ' ';
        cout << '\n';
    }
}

void outputTruthTable(const string &expression) {
    outputTruthTable(getTableOfStateOfVariableByCNFFunc(expression));
}

void outputTruthTable(const TableOfStateOfVariable &tableOfStateOfVariable) {
    for (const auto &name: tableOfStateOfVariable.namesOfValues)
        cout << name << ' ';
    cout << "F\n";

    outputMatrix(getTruthTable(tableOfStateOfVariable));
}