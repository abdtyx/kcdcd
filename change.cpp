#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in2("samples/data1.txt"); //txt文件与源代码要在一个文件夹内
    string filename;
    string line;
    vector<string> m1;
    int lin = 0;
    int lie;
    char c;
    int num = 0;
    while (in2.get(c))
    {
        if (c == '\n')
        {
            lin++;
        }
    }
    in2.clear();
    in2.close();
    ifstream in("samples/data1.txt");
    if (in) // 有该文件
    {
        while (in >> line) // line中不包括每行的换行符
        {
            m1.push_back(line);
            num++;
        }

        // for (int i = 0; i < m.size(); i++)
        // {
        //     cout << m[i] << endl; //把每一行的内容打印到屏幕上
        // }
    }
    else // 没有该文件
    {
        cout << "no such file" << endl;
        return -1;
    }
    lie = num / lin;
    // cout << lin << endl;
    // cout << lie << endl;
    in.clear();
    in.close();
    ofstream ot("samples/sample_handle1.txt", ios::app | ios::out); // 转化第一个文件, 没有则创建，有则在文末写入
    if (ot)
    {
        ot << lin << endl;
        ot << lie << endl;
        for (int i = 1; i < lie; i++)
        {
            ot << m1[i] << endl;
        }
        for (int i = lie, n = 1; i < lie * lin, n < lin; i = i * n, n++)
        {
            ot << m1[i] << endl;
        }
        ot << '1' << endl;
        for (int i = lie + 1; i < lie * lin; i++)
        {
            if (i % lie == 0)
            {
                continue;
            }
            ot << m1[i] << endl;
        }
    }
    else
    {
        cout << "no such file" << endl;
        return -1;
    }
    ot.clear();
    ot.close();

    // 第二个文件的读取
    ifstream in3("samples/b.txt");
    string filename3;
    string line3;
    vector<string> m3;
    int lin3 = 0;
    int lie3[100];
    char c3;
    int num3 = -1; // 记录识别符>>的位置
    int n = 0;
    while (in3.get(c3))
    {
        if (c3 == '\n')
        {
            lin3++;
            // 记录每一行的有效内容
            // lie3[lin3] = _num3;
            // _num3 = 0;
        }
        // if (c3 == '\\')
        // {
        //     _num3++;
        // }
    }
    in3.clear();
    in3.close();
    ifstream in_3("samples/b.txt");
    if (in_3) // 有该文件
    {
        while (in_3 >> line3) // line中不包括每行的换行符
        {
            // num3++;
            // if (line3 == ">>")
            // {
            //     lie3[n] = num3;
            //     n++;
            // }
            m3.push_back(line3);
        }
        // for (int i = 0; i < m3.size(); i++)
        // {
        //     cout << m3[i] << endl; //把每一行的内容打印到屏幕上
        // }
    }
    else // 没有该文件
    {
        cout << "no such file" << endl;
        return -1;
    }
    in_3.clear();
    in_3.close();
    for (int j = 0; j < m3.size(); j++)
    {
        if (m3[j] == ">>")
        {
            lie3[n] = j;
            n++;
        }
    }
    // cout << lin3 << endl;
    // for (int i = 0; i < lin3; i++)
    // {
    //     cout << lie3[i] <<endl;
    // }

    // 读取后记录
    string khfs[20];
    string cjzb[20];
    string dt[20];
    string mdt[30];
    string zf[30];
    for (int i = 0; i < lie3[1] - lie3[0] - 2; i++)
    {
        int tem;
        tem = lie3[0] + 2 + i;
        khfs[i] = m3[tem];
    }
    for (int i = 0; i < lie3[2] - lie3[1] - 2; i++)
    {
        int tem;
        tem = lie3[1] + 2 + i;
        cjzb[i] = m3[tem];
    }
    for (int i = 0; i < lie3[3] - lie3[2] - 2; i++)
    {
        int tem;
        tem = lie3[2] + 2 + i;
        dt[i] = m3[tem];
    }
    for (int i = 0; i < lie3[4] - lie3[3] - 2; i++)
    {
        int tem;
        tem = lie3[3] + 2 + i;
        mdt[i] = m3[tem];
    }
    for (int i = 0; i < lie3[5] - lie3[4] - 2; i++)
    {
        int tem;
        tem = lie3[4] + 2 + i;
        zf[i] = m3[tem];
    }

    ofstream ot3("samples/sample_handle1.txt", ios::app | ios::out); // 转化第一个文件, 没有则创建，有则在文末写入
    if (ot3)
    {
        int num_st;
        num_st = (n - 1) - 5;
        ot3 << num_st << endl;
        for (int i = 6; i < n; i++)
        {
            int tem;
            tem = lie3[i];
            ot3 << m3[tem + 2] << endl;
            ot3 << m3[tem + 3] << endl;
        }
        int num_kh;
        num_kh = lie3[1] - lie3[0] - 2;
        ot3 << num_kh << endl;
        for (int i = 0; i < num_kh; i++)
        {
            ot3 << khfs[i] << endl;
            ot3 << cjzb[i] << endl;
            int num_dt = 3;
            if (i == 0)
            {
                int num_mdt;
                num_mdt = lie3[4] - lie3[3] - 2;
                ot3 << num_dt << endl;
                for (int j = 0; j < num_dt; j++)
                {
                    int tem1;
                    tem1 = lie3[4];
                    ot3 << dt[j] << endl;
                    if (j == 0)
                    {
                        ot3 << num_mdt << endl;
                        continue;
                    }
                    ot3 << "0" << endl;
                    ot3 << m3[tem1 + num_mdt + 1 + j] << endl;
                    if (j == 1)
                    {
                        ot3 << "1" << endl;
                        for (int k = 0; k < num_st; k++)
                        {
                            int tem2;
                            tem2 = lie3[6 + k] + num_mdt + j + 3;
                            ot3 << m3[tem2] << endl;
                        }
                    }
                    if (j == 2)
                    {
                        ot3 << "3" << endl;
                        for (int k = 0; k < num_st; k++)
                        {
                            int tem3;
                            tem3 = lie3[6 + k] + num_mdt + j + 3;
                            ot3 << m3[tem3] << endl;
                        }
                    }
                }
                for (int j = 0; j < num_mdt; j++)
                {
                    ot3 << mdt[j] << endl;
                    ot3 << "0" << endl;
                    ot3 << zf[j] << endl;
                    if (j == 0)
                    {
                        ot3 << "1" << endl;
                        for (int k = 0; k < num_st; k++)
                        {
                            int tem1;
                            tem1 = lie3[6 + k] + j + 4;
                            ot3 << m3[tem1] << endl;
                        }
                    }
                    else
                    {
                        ot3 << "2" << endl;
                        for (int k = 0; k < num_st; k++)
                        {
                            int tem2;
                            tem2 = lie3[6 + k] + j + 4;
                            ot3 << m3[tem2] << endl;
                        }
                    }
                }
            }
            else if (i == 1)
            {
                ot3 << num_dt << endl;
                for (int j = 0; j < num_dt; j++)
                {
                    int tem;
                    tem = lie3[2] + num_dt + 2 + j;
                    ot3 << m3[tem] << endl;
                    ot3 << "0" << endl;
                    ot3 << zf[num_dt + num_dt - 1] << endl;
                    ot3 << j + 1 << endl;
                    for (int k = 0; k < num_st; k++)
                    {
                        int tem1;
                        tem1 = lie3[6 + k] + lie3[5] - lie3[4] - 2 + j;
                        ot3 << m3[tem1] << endl;
                    }
                }
            }
            else
            {
                ot3 << num_dt - 1 << endl;
                for (int k = 0; k < num_dt - 1; k++)
                {
                    ot3 << dt[num_dt + num_dt + k] << endl;
                    ot3 << "0" << endl;
                    ot3 << zf[num_dt + num_dt + 2 + k] << endl;
                    ot3 << k + 2 << endl;
                    for (int v = 0; v < num_st; v++)
                    {
                        int tem1;
                        tem1 = lie3[6 + v] + lie3[5] - lie3[4] + k + 2;
                        ot3 << m3[tem1] << endl;
                    }
                }
            }
        }
    }
    else
    {
        cout << "no such file" << endl;
        return -1;
    }
}