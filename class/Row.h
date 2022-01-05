/********************************************************************
    created:    	2021/11/28   19:34
    Filerow_name:   	Row.h
    author:     	tyx
*********************************************************************/

#ifndef _ROW_H
#define _ROW_H
#endif

#include "../include/stdc++.h"

#ifndef debug
#define debug false
#endif

using namespace std;

template <class T>
class Row {
    private:
        string row_name;    // 行名
        vector<T> value;    // 行中各元素值
    public:
        /**
         * @brief 改名
         * 给类改名
         * @param s 要改成的名字
         * @return string 更改后的名字
         */
        string modify_name(string s) {
            this->row_name = s;
            return this->row_name;
        }
        /**
         * @brief Construct a new Row object
         * 构造名称为s的行
         * @param s 行名
         */
        Row(string s) {
            this->row_name = s;
            if (debug)
                cout << "Row:" << s << "已创建" << endl;
        }
        /**
         * @brief Construct a new Row object
         * 默认构造函数，没有参数
         */
        Row() {
            if (debug)
                cout << "Row已创建" << endl;
        }
        /**
         * @brief Destroy the Row object
         * 默认析构函数
         */
        ~Row() {
            if (debug)
                cout << "Row:" << row_name << "已销毁" << endl;
        }
        /**
         * @brief 追加
         * 往行中添加元素（放在向量最后）
         * @param t 要添加的元素
         * @return int 成功删除为1，否则为0
         */
        int _append(T t) {
            int flag = value.size();
            value.push_back(t);
            if (value.size() == flag + 1)
                return 1;
            else
                return 0;
        }
        /**
         * @brief 删除
         * 把行中最后一个元素删除
         * @return int 成功删除为1，否则为0
         */
        int _delete() {
            if (!value.size()) {
                return 0;
            }
            else {
                int flag = value.size();
                value.pop_back();
                if (value.size() == flag - 1)
                    return 1;
                else 
                    return 0;
            }
        }
        /**
         * @brief 行名
         * 获取行名
         * @return string 行名
         */
        string name() {
            return this->row_name;
        }
        /**
         * @brief 向量规模
         * 获取向量内元素个数
         * @return int 向量内元素个数
         */
        int size() {
            return value.size();
        }
        /**
         * @brief 索引
         * 重载索引运算符，因为向量被封装不能直接用索引查
         * @param index 索引值
         * @return T 索引在向量中对应值
         */
        T operator[](int index) {
            return value[index];
        }
};