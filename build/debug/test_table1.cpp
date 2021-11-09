#include "D:\DevelopingFiles\kcdcd\handle\Table1.cpp"
using namespace std;

int main() {
    // system("chcp 65001");
    // 关同步加速
    // 该写法会关闭ios中所有输入输出流与stdio的同步
    // 写cin.sync_with_stdio(false);只会关闭cin对象与stdio的同步
    ios::sync_with_stdio(false);
    // cin.imbue(locale("chs"));
    // cout.imbue(locale("chs"));
    table1();
    return 0;
}