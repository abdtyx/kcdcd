/********************************************************************
    created:    	2021/11/28   19:34
    Filename:   	Row.h
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
        string name;
        vector<T> value;
    public:
        string modify_name(string s) {
            this->name = s;
            return this->name;
        }
        Row(string s) {
            this->name = s;
            if (debug)
                cout << "Row:" << s << "已创建" << endl;
        }
        Row() {
            if (debug)
                cout << "Row已创建" << endl;
        }
        ~Row() {
            if (debug)
                cout << "Row:" << name << "已销毁" << endl;
        }
        int _append(T t) {
            int flag = value.size();
            value.push_back(t);
            if (value.size() == flag + 1)
                return 1;
            else
                return 0;
        }
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
        T operator[](int index) {
            return value[index];
        }
};