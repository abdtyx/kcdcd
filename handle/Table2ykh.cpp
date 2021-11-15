#include<iostream>
#include<vector>
#include<string>
using namespace std;

    class column{
		public:
			string column_name;
			vector<string> value;

			int func1()
	};//定义考核方式类
    class chart{
		public:
			vector<column> line;
			vector<string> row;//基本组分定义

			int loc[2]{};//坐标

            void func2(string marker,){    //marker储存查找时的课标名称
                int *p1 = &loc[0],*p2 = &loc[1]; 
				for(int s = 0;marker != row[s];s++)
					*p1 = s+1;

			};
			string output{

			};
	};//定义本表格
int main(){
	 chart item;
	 string pre;
	 int point;//用户输入课程目标个数

	 cout << "请输入课程目标数量和具体名称\n";//仅为控制输入储存的数据模拟
	                                         //之后将输入替换为赋值
	 cin >> point;

	 for(int i = 0;i < point;i++)
	 {
		 cin >> pre;
		 item.row.push_back(pre);
     }

     


	 for(int i = 0;i < point;i++)
	 cout << item.row[i] << endl;
     


}

