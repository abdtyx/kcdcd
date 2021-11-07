#include <bits/stdc++.h>
using namespace std;

class Column {
    private:
        string column_name;
    public:
        // string column_name;
        vector<string> value;   // 对应列各行值，value[i]表示该列下第i行的值
        string find_value(int i) {
            return value[i];
        }
        /**
         * @brief get column name
         * @return column name
         */
        string name() {
            return this->column_name;
        }
        /**
         * @brief modify Column name
         * @param new_name
         * @return modified name
         */
        string modify_name(string s) {
            this->column_name = s;
            return this->column_name;
        }
        Column() {
            // cout << "已创建指定列";
        }
        /**
         * @brief 接受字符串，赋值给列名
         * @param 列名
         */
        Column(string s) {
            this->column_name = s;
            value.clear();
            // cout << "已创建指定列: " << s << endl;
        }
        ~Column() {
            value.clear();
            // cout << "已创建指定列";
        };
};