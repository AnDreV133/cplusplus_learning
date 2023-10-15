//
// Created by dmitr on 12.10.2023.
//

#ifndef CPLUSPLUS_LEARNING_CNFCALCULATOR_H
#define CPLUSPLUS_LEARNING_CNFCALCULATOR_H

#include <vector>
#include <iostream>

using namespace std;

enum {
    DNF = 1,
    KNF = 2
};

struct States {
    short const NON_EXCLUDED = 1;    // a
    short const EXCLUDED = 0;       // ¬a
    short const NOTHING = -1;       // - переменная не присутствует в слагаемом
};

struct TableOfStateOfVariable {
    vector<char> namesOfValues; // Названия переменных
    vector<vector<short>> matrixOfConditionValues; // Матрица состояний переменных
};

struct BinFunc {
    int type; // ДНФ или КНФ
    unsigned numOfVariables; // Кол-во переменных
    vector<char> namesOfValues; // Названия переменных
    vector<vector<short>> matrixOfConditionValues; // Матрица состояний переменных
};

void setBinFunc(BinFunc &binFunc);

bool checkResult(const BinFunc &binFunc);

TableOfStateOfVariable getTableOfStateOfVariableByCNFFuncGottenFromString(const string &expression);

void outputTableOfState(const TableOfStateOfVariable& tableOfStateValues);

void generateBodyTruthTable(vector<vector<bool>> &truthTable, int index, int size, int current[]);

void outputMatrix(const vector<vector<bool>> &matrix);

vector<vector<bool>> getTruthTable(const TableOfStateOfVariable &tableOfStateOfVariable);

void outputTruthTableByTableOfState(const TableOfStateOfVariable& tableOfStateOfVariable);


#endif //CPLUSPLUS_LEARNING_CNFCALCULATOR_H
