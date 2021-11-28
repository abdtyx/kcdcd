/********************************************************************
    created:    	2021/11/?   ??:??
    Filename:   	Table2.cpp
    author:     	zyd
*********************************************************************/
/**
 * @defgroup 课程目标在各考核方式中所占的比重
 */

#ifndef _TABLE2_CPP
#define _TABLE2_CPP
#endif

// 课程目标在各考核方式中所占的比重
#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

#ifndef _MATRIX_H
#include "../class/Matrix.h"
#endif

using namespace std;

// #include "Table3.cpp"

/**
 * @brief 该文件包含的函数
 */
bool getRelation(Matrix<double> &a, Matrix<double> &b);
void outputTable2(Matrix<double> &a, int row_count, int column_count);
void carryTable2(Matrix<double> &a, Matrix<double> &b);
void table2();

/**
 * @brief 获取课程目标在各考核方式中所占的比重并存储
 */
void table2()
{
    // value为double型
    Matrix<double> matrix2;
    // 此 Table2 在Table3.cpp中
    bool is_get = getRelation(matrix2, Table2);
    if (debug)
    {
        if (is_get)
        {
            cout << "Successfully get!" << endl;
        }
        else
        {
            cout << "Fail to get!" << endl;
        }
    }
    return;
}

/**
 * @brief 读入数据存储给matrix
 * @param 表格变量
 * @return 是否成功获取，是则返回true，否则返回false
 */
bool getRelation(Matrix<double> &a)
{
    int row_count, column_count; // row_count表示行数，column_count表示列数
    // 该数据读入cout用于黑窗口测试，测试完成后注释掉
    cout << "请输入课程目标数：";
    cin >> row_count;
    cout << "请输入考核环节数：";
    cin >> column_count;
    for (int i = 0; i < column_count; i++)
    {
        // 每个列是一个Column类,为double型
        cout << "请输入第" << i + 1 << "个考核环节名称：";
        string name;
        cin >> name;
        Column<double> tmp(name);
        a.columns.push_back(tmp);
    }
    for (int j = 0; j < row_count; j++)
    {
        // 每个行是一个string
        cout << "请输入第" << j + 1 << "个课程目标名称：";
        string name;
        cin >> name;
        a.rows.push_back(name);
    }
    // 以下是接受数据储存
    carryTable2(a, Table2);

    // 调试输出
    if (debug)
        outputTable2(a, row_count, column_count);
    return true;
}

void outputTable2(Matrix<double> &a, int row_count, int column_count)
{
    // 重载运算符()使用方法如下
    // T val = a("str1", "str2");
    cout << '\t';
    for (auto i : a.columns)
    {
        cout << i.name() << '\t';
    }
    cout << endl;
    for (int j = 0; j < row_count; j++)
    {
        cout << a.rows[j] << '\t';
        for (auto i : a.columns)
        {
            cout << i.value[j] << '\t';
        }
        cout << endl;
    }
    return;
}

void carryTable2(Matrix<double> &a, Matrix<double> &b)
{
    a = b;
}