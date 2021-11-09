#include <bits/stdc++.h>
#ifndef debug
#define debug false
#endif
#include "D:\DevelopingFiles\kcdcd\class\Column.h"
using namespace std;

// bool debug = false;

// 由于Column虚化为模板，因此Matrix同样虚化为模板
template <class T>
class Matrix {
	public:
		vector<Column<T> > columns;	// 许多列，每一列有一个列名，使用方法1：传字符串给构造函数；2：调用modify_name()
		vector<string> rows;	//vector<string> 型的变量
		/**
		 * @brief 重载运算符，直接返回行列对应值
		 * @param 行名
		 * @param 列名
		 * @return 该行该列对应的值
		 */
		T operator() (string r_name, string c_name) {
			int i = 0;
			for (; i < rows.size(); i++) {
				if (rows[i] == r_name)
					break;
			}
			for (int j = 0; j < columns.size(); j++) {
				if (columns[j].name() == c_name) {
					return columns[j].find_value(i);
				}
			}
		}
		Matrix() {
			rows.clear();
			columns.clear();
			if (debug)
				cout << "表格已创建" << endl;
		}
		~Matrix() {
			rows.clear();
			columns.clear();
			if (debug)
				cout << "表格已销毁" << endl;
		}
};
