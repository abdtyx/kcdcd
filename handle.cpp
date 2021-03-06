/********************************************************************
    created:    	2021/11/28   15:01
    Filename:   	main.cpp
    author:     	tyx
*********************************************************************/

#ifndef _MAIN_CPP
#define _MAIN_CPP
#endif

#ifndef debug
#define debug false
#endif

#include "./include/stdc++.h"

#ifndef _TABLE1_CPP
#include "./handle/Table1.cpp"
#endif

#ifndef _TABLE2_CPP
#include "./handle/Table2.cpp"
#endif

#ifndef _TABLE3_CPP
#include "./handle/Table3.cpp"
#endif

#ifndef _TABLE4_CPP
#include "./handle/Table4.cpp"
#endif

#ifndef _TABLE5_CPP
#include "./handle/Table5.cpp"
#endif

#ifndef _MATRIX_H
#include "./class/Matrix.h"
#endif

using namespace std;

int main() {
    Matrix<char> tmp = table1();
    vector<pair<string, vector<pair<vector<double>, pair<string, int> > > > > temp = table3();
    table2(temp);
    table4(temp);
    table5(tmp);
    return 0;
}