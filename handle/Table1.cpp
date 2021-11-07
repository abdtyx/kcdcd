// 课程目标与毕业要求指标点对应关系
#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

bool debug = false;

bool getRelation(Matrix<char>& a);
void outputTable1(Matrix<char>& a);
void inputInRows(Matrix<char>& a, int row_count, int column_count);
void inputInColumns(Matrix<char>& a, int row_count, int column_count);

/**
 * @brief 获取课程目标与毕业要求指标点对应关系并存储
 */
void table1() {
    // value为char型
    Matrix<char> matrix;
    bool is_get = getRelation(matrix);
    if (debug) {
        if (is_get) {
            cout << "Successfully get!";
        }
        else {
            cout << "Fail to get!";
        }
    }
    return;
}

/**
 * @brief 读入数据存储给matrix
 */
bool getRelation(Matrix<char>& a) {
    int row_count, column_count;   // row_count表示行数，column_count表示列数
    // 该数据读入cout用于黑窗口测试，测试完成后注释掉
    cout << "请输入课程目标数" << endl;
    cin >> row_count;
    cout << "请输入指标数" << endl;
    cin >> column_count;
    for (int i = 0; i < column_count; i++) {
        // 每个列是一个Column类
        string name;
        cin >> name;
        Column<char> tmp(name);
        a.columns.push_back(tmp);
    }
    for (int j = 0; j < row_count; j++) {
        // 每个行是一个string
        string name;
        cin >> name;
        a.rows.push_back(name);
    }
    cout << "您希望按行输入还是按列输入？按行输入请键入1，按列输入请键入2";
    int flag;
    cin >> flag;
    switch (flag) {
        case 1:
            inputInRows(a, row_count, column_count);
            break;
        case 2:
            inputInColumns(a, row_count, column_count);
            break;
        default:
            return false;
            break;
    }
    return true;
}

void inputInRows(Matrix<char>& a, int row_count, int column_count) {
    cout << "*********请按行输入对应值*********" << endl;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            cout << "课程目标：" << a.rows[i] << "\t" 
                << "指标点：" << a.columns[j].name() << "\t" 
                << "对应的值是（高用H，中用M，低用L，空值用N）：";
            char temp;
            cin >> temp;
            a.columns[j].value.push_back(temp);
        }
    }
    return;
}

void inputInColumns(Matrix<char>& a, int row_count, int column_count) {
    cout << "*********请按行输入对应值*********" << endl;
    for (int i = 0; i < column_count; i++) {
        for (int j = 0; j < row_count; j++) {
            cout << "课程目标：" << a.rows[j] << "\t"
                << "指标点：" << a.columns[i].name() << "\t"
                << "对应的值是（高用H，中用M，低用L，空值用N）：";
            char temp;
            cin >> temp;
            a.columns[i].value.push_back(temp);
        }
    }
    return;
}

void outputTable1(Matrix<char>& a) {
    return;
}
