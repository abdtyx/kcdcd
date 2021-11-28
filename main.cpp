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

using namespace std;

int main() {
    table1();
    // table3();
    table2();
    return 0;
}