/********************************************************************
    created:    	2021/12/19   15:28
    Filename:   	Table4.cpp
    author:     	tyx
*********************************************************************/
/**
 * @defgroup 课程教学目标达成度分数统计表
 */

#ifndef _TABLE4_CPP 
#define _TABLE4_CPP
#endif

#ifndef _STUDENT_H
#include "../class/Student.h"
#endif

// 课程考核环节分数详细统计表
#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

#ifndef _ROW_H
#include "../class/Row.h"
#endif

using namespace std;

#ifndef _TABLE3_CPP
typedef struct _Node {
    string name;                // 题目名
    int ind;                    // 入度
    int otd;                    // 出度
    vector<_Node*> to_where;    // 儿子结点地址
    vector<double> scores;      // scores[0]是该题总分值
    // int next;                // 是否还有儿子结点
    int _match;                 // 对应哪一个课程目标
} Node;

typedef pair<Node*, vector<double> > PAIR;  // pair<图root, 总分>
#endif

void table4(Row<string> khhj, Row<double> cjzb, Row<PAIR> tm, vector<Student> student) {
    
}