/********************************************************************
    created:    	2022/1/5   16:59
    Filename:   	Table5.cpp
    author:     	tyx
*********************************************************************/
/**
 * @defgroup 课程目标对毕业要求指标点达成度分析
 */

#ifndef _TABLE5_CPP
#define _TABLE5_CPP
#endif

#ifndef _MATRIX_H
#include "../class/Matrix.h"
#endif

// 课程目标对毕业要求指标点达成度分析
#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

#ifndef _COLUMN_H
#include "../class/Column.h"
#endif

using namespace std;

void table5(Matrix<char> matrix);
void outputTable5(Matrix<double> matrix);

const double percent_h = 1.0;
const double percent_m = 1.0;
const double percent_l = 1.0;

void table5(Matrix<char> matrix)
{
    ifstream infile;
    infile.open("cache/scores_to_table5.dat");
    vector<pair<double, double>> scores; // pair<avg, total>

    for (int i = 0; i < matrix.rows.size(); i++)
    {
        // 把文件内容取出存到分值里面
        pair<double, double> tmp;
        infile >> tmp.first >> tmp.second;
        scores.push_back(tmp);
    }

    Matrix<double> m;
    m.rows = matrix.rows;
    m.rows.push_back("总计");

    for (int i = 0; i < matrix.columns.size(); i++)
    {
        Column<double> c(matrix.columns[i].name());
        double dcd = 0;

        // 第一次算分母
        double numerator = 0, denominator = 0;
        vector<char> val = matrix.columns[i].value;
        for (int j = 0; j < val.size(); j++)
        {
            switch (val[j])
            {
            case 'H':
                denominator += scores[j].second * percent_h;
                break;
            case 'M':
                denominator += scores[j].second * percent_m;
                break;
            case 'L':
                denominator += scores[j].second * percent_l;
                break;
            default:
                denominator += 0;
                break;
            }
        }

        // 第二次得出结果
        for (int j = 0; j < val.size(); j++)
        {
            double unit_dcd = 0;
            switch (val[j])
            {
            case 'H':
                unit_dcd = scores[j].first * percent_h / denominator;
                break;
            case 'M':
                unit_dcd = scores[j].first * percent_m / denominator;
                break;
            case 'L':
                unit_dcd = scores[j].first * percent_l / denominator;
                break;
            default:
                unit_dcd = 0;
                break;
            }
            dcd += unit_dcd;
            c.value.push_back(unit_dcd);
        }
        c.value.push_back(dcd);
        m.columns.push_back(c);
    }

    outputTable5(m);
}

void outputTable5(Matrix<double> matrix)
{
    ofstream outfile;
    outfile.open("cache/new_table5.dat", ios::out | ios::trunc);
    if (!outfile)
    {
        cout << "table5未能成功写入！" << endl;
        return;
    }
    outfile << "     课程目标对毕业要求指标点达成度分析表" << endl;
    outfile << '\t';
    for (auto i : matrix.columns)
    {
        outfile << i.name() << '\t';
    }
    outfile << endl;
    for (int j = 0; j < matrix.rows.size(); j++)
    {
        outfile << matrix.rows[j] << '\t';
        for (auto i : matrix.columns)
        {
            outfile << fixed << setprecision(2) << i.value[j] << '\t';
        }
        outfile << endl;
    }
    outfile.close();
    outfile.clear();
    return;
}