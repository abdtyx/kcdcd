#include<iostream>
#include<vector>
#include<string>
using namespace std;

    class column{
		public:
			string column_name;
			vector<float> value;

	};//定义考核方式类
    class chart{
		public:
			vector<column> line;
			vector<string> row;//以上为基本组分定义

			int loc[2]{};//数据坐标

            void requi(string marker1,string marker2){    //marker储存查找时的课标名称
                int *p1 = &loc[0],*p2 = &loc[1]; 
				for(int s = 0;marker1 != row[s-1] || s == -1;s++)
					*p1 = s;
				for(int s = 0;marker2 != line[s-1].column_name || s == -1;s++)
					*p2 = s;

				cout << line[loc[1]].value[loc[0]] << endl;
				return;//以上为表格功能：查询
			           };
			void print(){
				cout << "课程目标  ";
				for(int r = 0;r < 3;r++){
					cout << line[r].column_name << "  ";
					if(r == 2)
						cout << endl;
				}

				for(int w = 0;w < 3;w++)
				{
					cout << row[w] << "  " << line[0].value[0];
                }
				return;//以上为表格功能：打印表格
			}
			};//定义本表格
int main(){
	 chart item;
	 column method;//声明表格内列，便于之后存储数据
	 string pre;
	 int mubio,kaohe;//用户输入课程目标个数和考核方式数目

	 cout << "请输入课程目标数量和具体名称\n";//仅为控制输入储存的数据模拟
	                                         //之后将输入替换为赋值
	 cin >> mubio;
	 for(int q = 0;q < mubio;q++){
		 cin >> pre;
		 item.row.push_back(pre);
	 }

	 cout << "请输入考核方式数量和具体名称\n";

	 cin >> kaohe;
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
					 cout << "请输入课程目标数量和具体名称\n";
					 cin >> mubio;
					 for(int q = 0;q < mubio;q++){
						 cin >> pre;
						 item.row.push_back(pre);
					 }
				 }
			 else
			     {
					 cout << "请输入需要修改元素的位次（第几个？）和需被替换的信息\n";
					 cin >> mubio >> pre;
					 item.row[mubio] = pre;
				 }
		 }
		 else if(pre == "y")
		 {
			 cout << "需把所有考核方式清空后重新输入吗(yes/no)?\n";
			 cin >> pre;
			 if(pre[0] == 'y' || pre[0] == 'Y')
			 {
				 cout << "请输入考核方式数量和具体名称\n";
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
				 cout << "需修改第几个考核方式？请输入位次和需被替换的信息\n";
				 cin >> kaohe >> pre;
				 item.line[kaohe-1].column_name = pre;
			 }

		 }
		 cout << "修改完成\n";
		 pre = "yes";
		 }}

		 float baifen;//输入数据后方便检查表格数据的检索查找功能，之后替换为数据赋值
		 cout << "输入数据\n";
		 for(int j = 0;j < 3;j++)
			 for(int h = 0;h < 3;h++){
			     cin >> baifen;
				 item.line[0].value.push_back(baifen);
			 }
		 cout << "完成输入\n";

		 item.print();

		 string pre1,pre2;
		 cout << "需要查找哪个数据？请输入对应课程目标名称和考核方式名称\n";
		 cin >> pre1 >> pre2;
		 item.requi(pre1,pre2);//调用表格的查找元素函数
return 0;
}






