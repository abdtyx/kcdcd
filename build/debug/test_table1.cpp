#ifndef debug
#define debug false
#endif
#include "../../handle/Table1.cpp"
using namespace std;

int main() {
    // system("cls");
    // system("chcp 65001");
    // system("cls");
    // 关同步加速
    // 该写法会关闭ios中所有输入输出流与stdio的同步
    // 写cin.sync_with_stdio(false);只会关闭cin对象与stdio的同步
    ios::sync_with_stdio(false);
    // cin.imbue(locale("chs"));
    // cout.imbue(locale("chs"));
    // ifstream infile;
    // infile.open("../../samples/sample_table1.txt", ios::in);
    // if (!infile)
    // {
    //     cout << "未能成功打开表格一！" << endl;
    //     return 0;
    // }
    table1();
    return 0;
}