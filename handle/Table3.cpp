/********************************************************************
    created:    	2021/11/?   ??:??
    Filename:   	Table3.cpp
    author:     	NAN
*********************************************************************/
/**
 * @defgroup 课程考核环节分数详细统计表
 */

#ifndef _TABLE3_CPP 
#define _TABLE3_CPP
#endif

// 课程考核环节分数详细统计表
#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

#ifndef _MATRIX_H
#include "../class/Matrix.h"
#endif

#ifndef _ROW_H
#include "../class/Row.h"
#endif

typedef struct _Node {
    string name;
    int ind;
    int otd;
    vector<int> to_where;
    vector<double> scores;
    int _match;
} Node;

typedef pair<Node[], double> PAIR;  // pair<图, 总分>

using namespace std;

/**
 * @brief 该文件包含的函数
 */
void table3();

void table3() {
    Row<string> khhj("考核环节");
    Row<double> cjzb("成绩占比");
    Row<PAIR> tm("题号和对应分值");

}