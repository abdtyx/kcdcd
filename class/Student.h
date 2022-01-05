/********************************************************************
    created:    	2021/12/17   23:22
    Filerow_name:   	Student.h
    author:     	tyx
*********************************************************************/

#ifndef _STUDENT_H
#define _STUDENT_H
#endif

#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

using namespace std;

class Student {
    private:
        int _init_;
    public:
        int num;
        string name;
        string id;
        Student() {
            num = 0;
            if (debug) {
                cout << "默认学生已创建" << endl;
            }
        };
        Student(int i) {
            num = i;
            if (debug) {
                cout << "第" << i << "个学生已创建" << endl;
            }
        }
        Student(int num, string name, string id) {
            this->num = num;
            this->name = name;
            this->id = id;
            if (debug) {
                cout << "学生" << name << "已创建" << endl;
            }
        };
        ~Student() {
            if (debug) {
                cout << "学生" << name << "已删除" << endl;
            }
        };
        friend istream& operator>>(istream& input, Student& stu) {
            input >> stu.name >> stu.id;
            return input;
        };
        friend ostream& operator<<(ostream& output, Student& stu) {
            output << stu.num << ' ' << stu.name << ' ' << stu.id << endl;
            return output;
        }
};

/**
 * @brief StudentAPI
 * Student类支持的API
 */

vector<Student> getStudent();
double avg(vector<double> scores);

/**
 * @brief 获取学生
 * @return vector<Student>
 */
vector<Student> getStudent() {
    int num_student;
    cout << "请输入学生数量：";
    cin >> num_student;
    vector<Student> student;
    for (int i = 0; i < num_student; i++) {
        cout << "请按照 [姓名 学号](略去中括号) 的顺序输入第" << i + 1 << "个学生信息：";
        Student tmp(i + 1);
        cin >> tmp;
        student.push_back(tmp);
    }
    return student;
}

/**
 * @brief 本题平均分
 * @param vector<double> 分数向量
 * @return double average
 */
double avg(vector<double> scores) {
    int upr = scores.size() - 1;
    double sum = 0;
    for (int i = 0; i < upr; i++) {
        sum += scores[i + 1];
    }
    return sum / (double)upr;
}