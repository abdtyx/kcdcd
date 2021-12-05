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

#ifndef _ROW_H
#include "../class/Row.h"
#endif

using namespace std;

typedef struct _Node {
    string name;            // 题目名
    int ind;                // 入度
    int otd;                // 出度
    vector<_Node*> to_where;   // 儿子结点
    vector<double> scores;  // scores[0]是该题总分值
    // int next;             // 是否还有儿子结点
    int _match;
} Node;

typedef pair<Node*, double> PAIR;  // pair<图root, 总分>

/**
 * @brief 该文件包含的函数
 */
void table3();
void outputTable3(Row<string> khhj, Row<double> cjzb, Row<PAIR> tm);
void dfs(Node* tm, vector<string> to_output);
void initialize(Node* n);

void table3() {
    Row<string> khhj("考核环节"); // 考核环节
    Row<double> cjzb("成绩占比"); // 成绩占比
    Row<PAIR> tm("题号和对应分值"); // 题号和对应分值，包含总分值
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
        // 开始处理考核环节树，这里因为使用了链表，所以没办法写成调用函数
        Node* root = new Node;
        initialize(root);
        PAIR _pair = make_pair(root, 0.0);
        cout << "第" << i << "个考核环节下是否有小题分级？若是则直接输入分级数，否则输入0：";
        cin >> root->otd;
        root->name = tmp_string;
        vector<Node*> upper_layer;
        int upper_layer_otd_sum = 1; // 控制循环出口，询问用户儿子结点数并求和
        int layer_ctr = 1;  // 层级数
        upper_layer.clear();
        upper_layer.push_back(root);
        if (!root->otd) {
            cout << "请输入" << root->name << "的总分值：";
            cin >> _pair.second;
            cout << "该题对应哪一个课程目标？（输入数字）";
            cin >> root->_match;
            tm._append(_pair);  // 调用_append()函数后结束
        }
        else {
            while (upper_layer_otd_sum) {
                upper_layer_otd_sum = 0;
                vector<Node*> new_upper_layer;
                new_upper_layer.clear();
                // 遍历上层结点
                for (auto j : upper_layer) {
                    // 对每个出度不为0的结点建立儿子结点
                    for (int k = 0; k < j->otd; k++) {
                        // 建立新结点，这些结点是j的儿子结点
                        Node* son_node = new Node;
                        initialize(son_node);
                        cout << "请输入第" << layer_ctr << "级小题的第" << k + 1 << "个小题名称：";
                        cin >> son_node->name;
                        cout << "该小题下一级有多少小题？";
                        cin >> son_node->otd;
                        if (son_node->otd == 0) {
                            cout << "该题对应分数是：";
                            // cin >> son_node->scores[0]; 这样会报segment fault，因为它被初始化了
                            double score0;
                            cin >> score0;
                            son_node->scores.push_back(score0);
                            _pair.second += son_node->scores[0];
                            cout << "该题对应哪一个课程目标？（输入数字）";
                            cin >> son_node->_match;
                            if (false) {
                                cout << "有多少学生？";
                                int stu_number;
                                cin >> stu_number;
                                for (int stu_i = 0; stu_i < stu_number; stu_i++) {
                                    double stu_sc;
                                    cout << "第" << stu_i + 1 << "个学生在本题获得分数是：";
                                    cin >> stu_sc;
                                    son_node->scores.push_back(stu_sc);
                                }
                            }
                        }
                        upper_layer_otd_sum += son_node->otd;
                        son_node->ind = 1;
                        j->to_where.push_back(son_node);
                        new_upper_layer.push_back(son_node);
                    }
                }
                upper_layer.clear();
                upper_layer = new_upper_layer;
                layer_ctr++;
            }
            tm._append(_pair);
        }
    }
    // 输出
    outputTable3(khhj, cjzb, tm);
}

void outputTable3(Row<string> khhj, Row<double> cjzb, Row<PAIR> tm) {
    for (int i = 0; i < khhj.size(); i++) {
        vector<string> to_output;
        to_output.push_back(khhj[i]);
        to_output.push_back(to_string(cjzb[i]));
        if (tm[i].first->otd)
            dfs(tm[i].first, to_output);
        cout << khhj[i] << '-' << cjzb[i] << '-' << "总分" << '-' << tm[i].second << endl;
    }
}

void dfs(Node* node, vector<string> to_output) {
    if (node->ind != 0) {
        to_output.push_back(node->name);
    }
    if (node->otd == 0) {
        int m = 0;
        for (auto i : to_output) {
            if (m++ == 0) {
                cout << i;
            }
            else {
                cout << '-' << i;
            }
        }
        cout << '-' << node->scores[0] << endl;
        return;
    }
    for (auto i : node->to_where) {
        dfs(i, to_output);
    }
}

void initialize(Node* n) {
    n->ind = 0;
    n->otd = 0;
    n->name.clear();
    n->scores.clear();
    n->to_where.clear();
    n->_match = 0;
}