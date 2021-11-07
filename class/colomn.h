#include <bits/stdc++.h>
using namespace std;

class Colomn {
    private:
        string colomn_name;
    public:
        // string colomn_name;
        vector<string> value;   // 对应列各行值，value[i]表示该列下第i行的值
        string find_value(int i) {
            return value[i];
        }
        string name() {
            return this->colomn_name;
        }
        string modify_name(string s) {
            this->colomn_name = s;
        }
        Colomn() {
            // cout << "已创建指定列";
        }
        /**
         * @brief 构造函数，接受字符串，赋值给列名
         * @param 列名
         */
        Colomn(string s) {
            this->colomn_name = s;
            value.clear();
            // cout << "已创建指定列: " << s << endl;
        }
        ~Colomn() {
            value.clear();
            // cout << "已创建指定列";
        };
};