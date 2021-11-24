#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

    class column{
		public:
			string column_name;
			vector<float> value;

	};//定义考核方式类
    class chart{
		public:
			vector<column> line;
			vector<string> row;
			int v[2]{};//以上为基本组分定义

			int loc[2]{-1,-1};//数据坐标

            void requi(string marker1,string marker2){    //marker储存查找时的课标名称
                int *p1 = &loc[0],*p2 = &loc[1]; 
				for(int s = 0;s < v[0];s++)
					if(row[s] == marker1){
					*p1 = s;
					break;}
				for(int s = 0;s < v[1];s++)
					if(line[s].column_name == marker2){
					*p2 = s;
					break;}

				if(loc[0] != -1 && loc[1] != -1){
				    cout << line[loc[1]].value[loc[0]] << endl;
				    loc[0] = -1;loc[1] = -1;}
				else
					cout << "元素不存在，请确认字符是否输入错误\n";

				return;              //以上为表格功能：查询
			           };
			void print(){
				cout << "课程目标  ";
				for(int r = 0;r < v[1];r++){
					cout << line[r].column_name << "  ";
					if(r == v[1]-1)
						cout << endl;
				}

				for(int h = 0;h < v[0];h++)
				{
					cout << row[h] << "  ";
					for(int w = 0;w < v[1];w++)
				    {
					    cout << line[w].value[h] << "  ";
						if(w == v[1]-1)
					    cout << endl;
                    }
				}
				cout << "完成打印\n";
				return;//以上为表格功能：打印表格
			}
			};//定义本表格
int main(){
	 chart item;
	 column method;//声明表格内列，便于之后存储数据
	 string pre;
	 int mubio,kaohe;//用户输入课程目标个数和考核方式数目

	 cout << "请依次输入课程目标数量和具体名称\n";//仅为控制输入储存的数据模拟
	                                         //之后将输入替换为赋值
	 cin >> mubio;
	 item.v[0] = mubio;
	 for(int q = 0;q < mubio;q++){
		 cin >> pre;
		 item.row.push_back(pre);
	 }

	 cout << "请依次输入考核方式数量和具体名称\n";

	 cin >> kaohe;
	 item.v[1] = kaohe;
     for(int q = 0;q < kaohe;q++){
		 cin >> pre;
		 method.column_name = pre;
		 item.line.push_back(method);
	 }

	 pre = "yes";

	 while(pre[0] == 'y' || pre[0] == 'Y'){ //解决输入错误问题
	 cout << "请确认输入无误（yes/no）\n";

	 cin >> pre;
	 if(pre[0] == 'y' || pre[0] == 'Y')
		 break;

	 if(pre[0] == 'n' || pre[0] == 'N'){
		 cout << "需修改课程目标（x）数量还是考核方式（y）？\n";
		 cin >> pre;
		 while(pre != "x" && pre != "y")
		 {
			 cout << "输入错误，请重新输入\n";
		     cin >> pre;
		 }
		 if(pre == "x")              //考虑两种修改方式：清空重来和修改特定元素
		 {
			 cout << "需清空后重新输入吗(yes/no)？\n";
			 cin >> pre;
             if(pre[0] == 'y' || pre[0] == 'Y')
				 {
					 item.row.clear();
					 cout << "请依次输入课程目标数量和具体名称\n";//清空row，重新输入
					 cin >> mubio;
					 for(int q = 0;q < mubio;q++){
						 cin >> pre;
						 item.row.push_back(pre);
					 }
				 }
			 else
			     {
					 cout << "请依次输入需要修改元素的位次（第几个？）和需被替换的信息\n";
					 cin >> mubio >> pre;
					 item.row[mubio] = pre;//对应元素将被替换
				 }
		 }
		 else if(pre == "y")
		 {
			 cout << "需把所有考核方式清空后重新输入吗(yes/no)?\n";
			 cin >> pre;
			 if(pre[0] == 'y' || pre[0] == 'Y')
			 {
				 cout << "请依次输入考核方式数量和具体名称\n";//同上，相当于重新输入
				 item.line.clear();
				 cin >> kaohe;
				 for(int q = 0;q < kaohe;q++){
                     cin >> pre;
					 method.column_name = pre;
					 item.line.push_back(method);
				 }
			 }
			 else
			 {
				 cout << "需修改第几个考核方式？请依次输入位次和需被替换的信息\n";//同上
				 cin >> kaohe >> pre;
				 item.line[kaohe-1].column_name = pre;
			 }

		 }
		 cout << "修改完成\n";
		 pre = "yes";//pre赋值，维持循环进行
		 }}

		 float baifen;//输入数据后方便检查表格数据的检索查找功能，之后替换为数据赋值
		 cout << "输入数据\n";
		 for(int j = 0;j < item.v[1];j++)
			 for(int h = 0;h < item.v[0];h++){
			     cin >> baifen;
				 item.line[j].value.push_back(baifen);
			 }
		 cout << "完成输入\n";

		 item.print();//调用表格功能：打印表格

		 string pre1,pre2;
		 cout << "需要查找哪个数据？请依次输入对应课程目标名称和考核方式名称\n";
		 cin >> pre1 >> pre2;
		 item.requi(pre1,pre2);

		 char jud = 'a';//用于控制程序进行，根据用户输入，程序继续或程序退出
		 while(jud != 'q'){
		 cout << "若需再次打印表格，请输入：print（p）\n";
		 cout << "若需再次查找数据，请输入：inquire（i）\n";
		 cout << "若想退出程序，请输入：quit（q）\n";
		 cin >> jud;
		 if(jud == 'p')
			 item.print();
		 else if(jud == 'i'){
			 cout << "需要查找哪个数据？请依次输入对应课程目标名称和考核方式名称\n";
             cin >> pre1 >> pre2;
		     item.requi(pre1,pre2);}//调用表格功能：查找元素
		 }
		 if(jud == 'q')
			 cout << "感谢使用，再见 :)\n";
return 0;
}






