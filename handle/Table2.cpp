/********************************************************************
    created:    	2021/11/?   ??:??
    Filename:   	Table2.cpp
    author:     	tyx
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

#ifndef _ROW_H
#include "../class/Row.h"
#endif

#ifndef _MATRIX_H
#include "../class/Matrix.h"
#endif

// #ifndef _COLUMN_H
// #include "../class/Column.h"
// #endif

using namespace std;

/**
 * @brief 该文件包含的函数
 */

void table2(vector<pair<string, vector<pair<vector<double>, pair<string, int>>>>> score_match_pair);
void outputTable2(Matrix<double> &a, int row_count);

void table2(vector<pair<string, vector<pair<vector<double>, pair<string, int>>>>> score_match_pair)
{
    Matrix<double> tb2;
    ifstream infile;
    // ofstream outfile;
    infile.open("cache/rows_to_table2.dat");
    // outfile.open("cache/khhj.dat");
    int row_count;
    infile >> row_count;
    // outfile << score_match_pair.size() << endl;
    for (int i = 0; i < row_count; i++)
    {
        string tmp;
        infile >> tmp;
        tb2.rows.push_back(tmp);
    }
    for (int i = 0; i < score_match_pair.size(); i++)
    {
        // pair<string, vector<pair<double, int> > > tmp_pair;
        Column<double> tmp(score_match_pair[i].first);
        // outfile << score_match_pair[i].first << endl;
        for (int j = 0; j < row_count; j++)
        {
            tmp.value.push_back(0.0);
        }
        tb2.columns.push_back(tmp);
    }
    for (int i = 0; i < score_match_pair.size(); i++)
    {
        for (auto j : score_match_pair[i].second)
        {
            tb2.columns[i].value[j.second.second - 1] += j.first[0];
        }
    }
    outputTable2(tb2, row_count);
    infile.close();
    return;
}

/**
 * @brief 输出表格
 * 输出完整的表格数据，表格可视化
 * @param matrix 表格变量
 * @param row_count 行数
 */
void outputTable2(Matrix<double> &a, int row_count)
{
    // 重载运算符()使用方法如下
    // T val = a("str1", "str2");
    ofstream outfile;
    outfile.open("cache/new_table2.dat", ios::out | ios::trunc);
    if (!outfile)
    {
        cout << "未能写入文件！写入Table2出错" << endl;
        return;
    }
    outfile << "        课程目标在各考核中所占的比例" << endl;
    outfile << '\t';
    for (auto i : a.columns)
    {
        outfile << i.name() << '\t';
    }
    outfile << endl;
    for (int j = 0; j < row_count; j++)
    {
        outfile << a.rows[j] << '\t';
        for (auto i : a.columns)
        {
            outfile << i.value[j] << '\t';
        }
        outfile << endl;
    }
    return;
}
