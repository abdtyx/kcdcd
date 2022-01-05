/********************************************************************
    created:    	2021/11/?   ??:??
    Filename:   	Table3.cpp
    author:     	tyx
*********************************************************************/
/**
 * @defgroup 课程考核环节分数详细统计表
 */

#ifndef _TABLE3_CPP 
#define _TABLE3_CPP
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

/**
 * @brief 该文件包含的函数
 */

vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > table3();
void outputTable3(Row<string> khhj, Row<double> cjzb, Row<PAIR> tm);
void dfs(Node* tm, vector<string> to_output);
void dfs(Node* node, vector<pair<vector<double>, pair<string, int> > >& tmp_pair_second);
void initialize(Node* n);
vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > generate_score_match_pair(Row<PAIR> tm);

/**
 * @brief 程序核心
 * 处理表课程考核环节分数详细统计表的核心函数
 */
vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > table3() {
    vector<Student> student = getStudent();     // 获取学生信息
    Row<string> khhj("考核环节");               // 考核环节
    Row<double> cjzb("成绩占比");               // 成绩占比
    Row<PAIR> tm("题号和对应分值");             // 题号和对应分值，包含总分值
    cout << "请输入考核环节数：";
    int khhj_number;    // 考核环节数
    cin >> khhj_number;
    for (int i = 1; i <= khhj_number; i++) {
        string tmp_string;  // 考核环节名
        cout << "请输入第" << i << "个考核环节：";
        cin >> tmp_string;
        khhj._append(tmp_string);
        double tmp_double;  // 成绩占比
        cout << "请输入第" << i << "个考核环节的成绩占比（小数形式）：";
        cin >> tmp_double;
        cjzb._append(tmp_double);
        // 开始处理考核环节树，这里因为使用了链表，所以没办法写成调用函数
        Node* root = new Node;  // 考核环节树根节点
        initialize(root);
        vector<double> tmp_vec;
        tmp_vec.push_back(0.0);
        PAIR _pair = make_pair(root, tmp_vec);
        cout << "第" << i << "个考核环节下是否有小题分级？若是则直接输入分级数，否则输入0：";
        cin >> root->otd;
        root->name = tmp_string;    // 根节点被命名为考核环节名
        vector<Node*> upper_layer;  // 为了省时，用upper_layer存储上层结点地址，避免每次遍历考核环节树
        int upper_layer_otd_sum = 1; // 控制循环出口，询问用户儿子结点数并求和
        int layer_ctr = 1;  // 层级数
        upper_layer.clear();
        upper_layer.push_back(root);
        if (!root->otd) {
            // 假如第一级就是叶子结点，该树为平凡图
            cout << "请输入" << root->name << "的总分值：";
            cin >> _pair.second[0];
            _pair.first->scores.push_back(_pair.second[0]);
            cout << "该题对应哪一个课程目标？（输入数字）";
            cin >> root->_match;
            tm._append(_pair);  // 调用_append()函数后结束
        }
        else {
            // 建立考核环节树
            while (upper_layer_otd_sum) {
                upper_layer_otd_sum = 0;    // 该级出度统计，用来控制循环出口
                vector<Node*> new_upper_layer;  // 新上层结点地址向量
                new_upper_layer.clear();
                // 遍历上层结点
                for (auto j : upper_layer) {
                    // 对每个出度不为0的结点建立儿子结点
                    for (int k = 0; k < j->otd; k++) {
                        // 建立新结点，这些结点是j的儿子结点
                        Node* son_node = new Node;  // 初始化儿子结点
                        initialize(son_node);       // 不放心，再初始化一遍
                        cout << "请输入第" << layer_ctr << "级小题的第" << k + 1 << "个小题名称：";
                        cin >> son_node->name;
                        cout << "该小题下一级有多少小题？";
                        cin >> son_node->otd;
                        if (son_node->otd == 0) {
                            cout << "该题对应分数是：";
                            // cin >> son_node->scores[0]; 这样会报segment fault，因为它被初始化了，需使用push_back()
                            double score0;
                            cin >> score0;
                            son_node->scores.push_back(score0);
                            _pair.second[0] += son_node->scores[0];
                            cout << "该题对应哪一个课程目标？（输入数字）";
                            cin >> son_node->_match;
                            // 以下语句暂时不使用
                            if (false) {
                                // cout << "有多少学生？";
                                // int stu_number;
                                // cin >> stu_number;
                                for (int stu_i = 0; stu_i < student.size(); stu_i++) {
                                    double stu_sc;
                                    cout << "第" << stu_i + 1 << "个学生在本题获得分数是：";
                                    cin >> stu_sc;
                                    son_node->scores.push_back(stu_sc);
                                }
                            }
                        }
                        upper_layer_otd_sum += son_node->otd;   // 统计出度和
                        son_node->ind = 1;                      // 默认入度为1
                        j->to_where.push_back(son_node);        // 让上层结点j知道它的儿子结点在哪
                        new_upper_layer.push_back(son_node);    // 维护新上层结点upper_layer
                        delete son_node;
                    }
                }
                upper_layer.clear();
                upper_layer = new_upper_layer;  // 上层结点往下推一层
                layer_ctr++;                    // 层数
            }
            tm._append(_pair);                  // 第i级考核环节树建立完成
        }
        delete root;
    }
    // 输出
    if (true)
        outputTable3(khhj, cjzb, tm);
    vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > only_use_once = generate_score_match_pair(tm);
    // 程序最后要调用数据生成课程教学目标达成度分数统计表
    // 待定
    // 生成课程教学目标达成度分数统计表完成
    return only_use_once;   // 该参数传给表2用
}

/**
 * @brief 输出
 * 输出表3内容的函数
 * @param khhj 考核环节
 * @param cjzb 成绩占比
 * @param tm 题号和对应分值
 */
void outputTable3(Row<string> khhj, Row<double> cjzb, Row<PAIR> tm) {
    for (int i = 0; i < khhj.size(); i++) {
        vector<string> to_output;
        to_output.push_back(khhj[i]);
        to_output.push_back(to_string(cjzb[i]));
        if (tm[i].first->otd)
            dfs(tm[i].first, to_output);
        cout << khhj[i] << '-' << cjzb[i] << '-' << "总分" << '-' << tm[i].second[0];
        cout << "\t学生分数（按序号排列）：";
        for (int j = 1; j < tm[i].second.size(); j++) {
            if (j == 1)
                cout << tm[i].second[j];
            else 
                cout << '-' << tm[i].second[j];
        }
        cout << endl;
    }
}

/**
 * @brief dfs
 * 深度优先搜索考核环节结构树
 * @param node 根节点
 * @param to_output 将要输出的字符串向量
 */
void dfs(Node* node, vector<string> to_output) {
    if (node->ind != 0) {
        to_output.push_back(node->name);    // 除初始节点外，每经过一个结点，将该结点名称加入to_output
    }
    if (node->otd == 0) {
        // dfs出口
        int m = 0;  // 区分第一次输出和后续输出
        for (auto i : to_output) {
            if (m++ == 0) {
                cout << i;
            }
            else {
                cout << '-' << i;
            }
        }
        cout << '-' << node->scores[0]; // 最后输出叶子结点的分数
        cout << "\t学生分数（按序号排列）：";
        for (int j = 1; j < node->scores.size(); j++) {
            if (j == 1)
                cout << node->scores[j];
            else
                cout << '-' << node->scores[j];
        }
        cout << endl;
        return;
    }
    for (auto i : node->to_where) {
        // 没有到达叶子结点，继续往下dfs
        dfs(i, to_output);
    }
}

/**
 * @brief 初始化Node
 * 手动初始化考核环节结构树结点
 * @param n 需要初始化的结点地址
 */
void initialize(Node* n) {
    n->ind = 0;
    n->otd = 0;
    n->name.clear();
    n->scores.clear();
    n->to_where.clear();
    n->_match = 0;
}

vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > generate_score_match_pair(Row<PAIR> tm) {
    vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > score_match_pair;
    for (int i = 0; i < tm.size(); i++) {
        pair<string, vector<pair<vector<double>, pair<string, int> > > > tmp_pair;
        Node* _root = tm[i].first;
        tmp_pair.first = _root->name;
        dfs(_root, tmp_pair.second);
        score_match_pair.push_back(tmp_pair);
    }
    return score_match_pair;
}

void dfs(Node* node, vector<pair<vector<double>, pair<string, int> > >& tmp_pair_second) {
    if (node->otd == 0) {
        tmp_pair_second.push_back(make_pair(node->scores, make_pair(node->name, node->_match)));
        return;
    }
    for (auto z : node->to_where) {
        dfs(z, tmp_pair_second);
    }
}