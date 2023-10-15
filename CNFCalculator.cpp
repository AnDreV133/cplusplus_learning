//
// Created by dmitr on 12.10.2023.
//

#include <stack>
#include "CNFCalculator.h"


using namespace std;

States state;

// todo

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
    if (array.size() < index)
        array.resize((index + 1), initVal);

    array[index] = elem;
}

void addStateByIndex(vector<short> &row, int const index, short const elem) {
    addElemByIndexWithUpdateSizeAndInitializeWithValue<short>(row, index, elem, state.NOTHING);
}

TableOfStateOfVariable getTableOfStateOfVariableByCNFFuncGottenFromString(const string &expression) {
    TableOfStateOfVariable tableOfStateValues;

    stack<char> stackOperations;
    for (auto const &token: expression) {
        if (isspace(token))
            continue;

        if (!isTokenOfCNFExpression(token)) {
            cerr << "Bad input! token - " << token << " is not a logic operation.";
            exit(1);
        }

        if (!stackOperations.empty() && !isOpeningPar(stackOperations.top()) && (isConjunction(token) || isDisjunction(token))) {
            cerr << "Bad input! 1 token - " << token << "";
            exit(1);
        }

        if (stackOperations.empty() && )

        if (isOpeningPar(stackOperations.top()) && (isClosingPar(token) || isDisjunction(token)))
            stackOperations.pop();

        if ((stackOperations.empty() || isOperationOrOpeningPar(stackOperations.top())) && isVariable(token)) {
            int indexOfToken = getIndexOfTokenInNamesOfValues(token, tableOfStateValues);
            if (indexOfToken < 0) {
                tableOfStateValues.namesOfValues.push_back(token);
                indexOfToken = (int) tableOfStateValues.namesOfValues.size() - 1;
            }

            bool isExcluded = isExcluding(stackOperations.top());

            addStateByIndex(tableOfStateValues.matrixOfConditionValues.back(),
                            indexOfToken,
                            isExcluded ? state.EXCLUDED : state.NON_EXCLUDED);
            if (isExcluded)
                stackOperations.pop();

            stackOperations.pop();
        }

        if (isExcluding(token))
            stackOperations.push(token);

        if (isConjunction(token)) {
            stackOperations.push(token);
            tableOfStateValues.matrixOfConditionValues.emplace_back();
        }

        if (isDisjunction(token))
            stackOperations.push(token);

        if (isOpeningPar(token))
            stackOperations.push(token);
    }

    return tableOfStateValues;
}

bool checkResult(const BinFunc &binFunc) {
    // Вводим значения
    vector<int> checkedResult;
    for (auto &ai: binFunc.namesOfValues)
        cout << ai << ' ';
    cout << "set result for check\n";
    for (int i = 0; i < binFunc.namesOfValues.size(); ++i) {
        int value;
        cin >> value;
        if (value != 0 && value != 1) {
            cerr << "Input error\n";
            return false;
        }

        checkedResult.push_back(value);
    }
    // Проверяем введённые значения с матрицей
    for (int i = 0; i < binFunc.matrixOfConditionValues.size(); ++i) {
        bool isEqual = false;
        for (int j = 0; j < binFunc.numOfVariables; ++j) {
            // Пропускаем не введённые поля
            if (binFunc.matrixOfConditionValues[i][j] == -1)
                continue;
            // Проверяем введённые
            if (binFunc.type == DNF && binFunc.matrixOfConditionValues[i][j] == checkedResult[j]
                || binFunc.type == KNF && binFunc.matrixOfConditionValues[i][j] != checkedResult[j])
                isEqual = true;
            else {
                isEqual = false;
                break;
            }
        }
        // Если в одной из итераций находится нужный набор,
        // то выдаём результат
        if (isEqual)
            return binFunc.type == DNF;
    }
    // Иначе выводим обратный результат
    return binFunc.type != DNF;
}


void setBinFunc(BinFunc &binFunc) {
    // Ввод типа функции - ДНФ это или КНФ
    cout << "Change type (1 - DNF, 2 - KNF):\n";
    cin >> binFunc.type;
    // Проверка указан тип или что-то иное
    if (binFunc.type != DNF && binFunc.type != KNF) {
        cerr << "Input error\n";
        return;
    }
    // Устанавливаем кол-во переменных
    cout << "Write num of variables\n";
    cin >> binFunc.numOfVariables;
    // Инициализируем вектора
    binFunc.matrixOfConditionValues.emplace_back(binFunc.numOfVariables, -1);
    // Запускаем цикл процесса задания ф-ии
    cout << "Write '\\' to go to a new interpretation; write '0' to exit the input\n";
    int counterOfInterpretation = 0;
    while (true) {
        // Спрашиваем переменную, которую будем изменять
        char tempName;
        cout << "Write name of variable or '\\', '0'\n";
        cin >> tempName;
        // 0 - конец ввода, \ - переход к след слагаемому
        if (tempName == '0')
            break;
        else if (tempName == '\\') {
            counterOfInterpretation++;
            binFunc.matrixOfConditionValues.emplace_back(binFunc.numOfVariables, -1);
            continue;
        }
        // В цикле ищем заданную переменную, если находим,
        // инициализируем индекс, где стоит эта переменная
        int indexOfVariable = -1;
        for (int i = 0; i < binFunc.namesOfValues.size(); ++i) {
            if (tempName == binFunc.namesOfValues[i]) {
                indexOfVariable = i;
                break;
            }
        }
        // Если не нашли индекс, тогда записываем новую переменную,
        // устанавливаем индекс, проверяем на допустимое кол-во переменных
        if (indexOfVariable < 0) {
            indexOfVariable = (int) binFunc.namesOfValues.size();
            if (indexOfVariable < binFunc.numOfVariables) {
                binFunc.namesOfValues.push_back(tempName);
            } else {
                cerr << "Amount namesOfValues exceeded\n";
                return;
            }
        }
        // Определяем переменная с исключением или без
        short tempState;
        cout << "Write state of variable (0 - excluded, 1 - not excluded)\n";
        cin >> tempState;
        // Проверяем ввод
        if (tempState != 0 && tempState != 1) {
            cerr << "Input error\n";
            return;
        }
        // Записываем состояние переменной
        binFunc.matrixOfConditionValues[counterOfInterpretation][indexOfVariable] = tempState;
    }
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

//int main() {
//    BinFunc binFunc;
//    setBinFunc(binFunc);
//
//    for (auto &ai: binFunc.namesOfValues)
//        cout << ai << "\t";
//    cout << '\n';
//    for (const auto &ai: binFunc.matrixOfConditionValues) {
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