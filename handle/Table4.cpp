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

// 课程教学目标达成度分数统计表
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

void table4(vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > score_match_pair);
void dfsOutput(Node* node, string to_output);
double generateDegree(Node* root, ofstream& to_next_table);

void table4(vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > score_match_pair) {
    // 从cache读入课程目标数据
    ifstream infile;
    infile.open("cache/rows_to_table2.dat");
    // khhj.open("cache/khhj.dat");

    int num_kcmb;
    infile >> num_kcmb;
    vector<Node*> kcmbs;

    // 建立一棵树存储数据
    for (int i = 0; i < num_kcmb; i++) {

        Node* root = new Node;

        // 课程目标
        root->ind = 0;
        root->otd = score_match_pair.size();
        infile >> root->name;

        for (int j = 0; j < root->otd; j++) {
            Node* son_node = new Node;
            Node* son_son_node = new Node;

            // 考核环节
            son_node->ind = 1;
            son_node->otd = 1;
            son_node->name = score_match_pair[j].first;

            // 题目
            son_son_node->ind = 1;
            son_son_node->otd = 0;

            son_node->to_where.push_back(son_son_node);
            root->to_where.push_back(son_node);
            // delete son_node;
            // delete son_son_node;
        }

        kcmbs.push_back(root);
        // delete root;
    }

    // 根据考核环节遍历
    for (int i = 0; i < score_match_pair.size(); i++) {
        pair<string, vector<pair<vector<double>, pair<string, int> > > > tmp_pair = score_match_pair[i];
        for (auto j : tmp_pair.second) {
            // j的类型
            // pair<vector<double>, pair<string, int> >
            Node* operate_node = kcmbs[j.second.second - 1]->to_where[i]->to_where[0];
            operate_node->name += j.second.first + ' ';
            if (operate_node->scores.size()) {
                // 如果已经存在有值向量，进行向量加操作(每一个元素相加)
                for (int k = 0; k < operate_node->scores.size(); k++) {
                    operate_node->scores[k] += j.first[k];
                }
            }
            else {
                // 如果是空向量，直接拷贝过去
                operate_node->scores = j.first;
            }
        }
    }
    vector<double> dcd;
    dcd.clear();

    ofstream to_next_table;
    to_next_table.open("cache/scores_to_table5.dat", ios::out | ios::trunc);

    for (auto i : kcmbs) {
        string to_output;
        to_output.clear();
        dfsOutput(i, to_output);
        // 这两个遍历结构不同，因此只能分开
        dcd.push_back(generateDegree(i, to_next_table));
    }

    cout << endl;
    double _min = (double)0x2f2f2f2f;

    for (auto i : dcd) {
        if (i < _min) {
            _min = i;
        }
    }

    cout << "课程总达成度：" << _min << endl;

    to_next_table.close();
    infile.close();
}

void dfsOutput(Node* node, string to_output) {
    // 出口
    if (node->otd == 0) {
        // 特判该分类下没有元素的情况
        if (node->scores.size() == 0) {
            return;
        }
        to_output += node->name;
        cout << to_output;
        for (auto j : node->scores) {
            cout << " | " << j;
        }
        cout << " | " << avg(node->scores) << endl;
        return;
    }

    to_output += node->name + " | ";
    for (auto k : node->to_where) {
        dfsOutput(k, to_output);
    }
    return;
    // double generateDegree();
}

double generateDegree(Node* root, ofstream& to_next_table) {
    double zfz = 0;
    double avgfz = 0;
    for (auto a : root->to_where) {
        // 特判该分类下没有元素的情况
        if (a->to_where[0]->scores.size() == 0) {
            continue;
        }
        zfz += a->to_where[0]->scores[0];
        avgfz += avg(a->to_where[0]->scores);
    }
    to_next_table << avgfz << ' ' << zfz << endl;
    cout << "课程目标：" << root->name << "的达成度为：" << avgfz / zfz << endl;
    return avgfz / zfz;
}