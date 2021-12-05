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
    string name;            // 题目名
    int ind = 0;                // 入度
    int otd = 0;                // 出度
    vector<Node*> to_where;   // 儿子结点
    vector<double> scores;  // scores[0]是该题总分值
    // int next;             // 是否还有儿子结点
} Node;

typedef pair<Node*, double> PAIR;  // pair<图root, 总分>

using namespace std;

/**
 * @brief 该文件包含的函数
 */
void table3();
void handle_tm_tree(Row<PAIR>& tm, int i, string tmp_string);

void table3() {
    Row<string> khhj("考核环节");
    Row<double> cjzb("成绩占比");
    Row<PAIR> tm("题号和对应分值"); // 包含总分值
    cout << "请输入考核环节数：";
    int khhj_number;
    cin >> khhj_number;
    for (int i = 1; i <= khhj_number; i++) {
        string tmp_string;
        cout << "请输入第" << i << "个考核环节：";
        cin >> tmp_string;
        khhj._append(tmp_string);
        double tmp_double;
        cout << "请输入第" << i << "个考核环节的成绩占比（小数形式）：";
        cin >> tmp_double;
        cjzb._append(tmp_double);
        handle_tm_tree(tm, i, tmp_string);
    }
}

void handle_tm_tree(Row<PAIR>& tm, int i, string tmp_string) {
    Node* root;
    PAIR _pair = make_pair(root, 0.0);
    cout << "第" << i << "个考核环节下是否有小题分级？若是则直接输入分级数，否则输入0";
    cin >> root->otd;
    root->name = tmp_string;
    vector<Node*> upper_layer;
    int upper_layer_otd_sum = 1; // 控制循环出口，询问用户儿子结点数并求和
    int layer_ctr = 1;  // 层级数
    upper_layer.clear();
    upper_layer.push_back(root);
    if (!root->otd) {
        _pair.second = 0;
        tm._append(_pair);  // 调用_append()函数后结束
        return;
    }
    else {
        while (upper_layer_otd_sum) {
            upper_layer_otd_sum = 0;
            // 遍历上层结点
            for (auto j : upper_layer) {
                // 对每个出度不为0的结点建立儿子结点
                for (int k = 0; k < j->otd; k++) {
                    
                }
            }
            layer_ctr++;
        }
    }
}