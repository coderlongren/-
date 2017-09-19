#include "string.h"
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include "class.h"
void list();
int main()
{
	int tenum = 0, lanum = 0, i, j;
	teacher te[10];
	lab la[10];
	for (; ; )
	{
		int i;
		list();
		cout<<"input the number: \n";
		cin>>i;

		if (i == 1)//增加一位教师 记录
		{
			cin>>te[tenum];
			tenum++;
			cout<<"teacher num   "<<tenum<<endl;
		}

		if (i == 2)//增加一位工人 记录
		{
			cin>>la[lanum];
			lanum++;
			cout<<"lab num    :  "<<lanum<<endl;
		}

		if (i == 3)//显示所有职工信息
		{
			for (j = 0; j < lanum; j++)
			{
				cout<<la[j];
			}
			for (j = 0; j < tenum; j++)
			{
				cout<<te[j];
			}
		}

		if (i == 4)//计算教师平均年龄
		{
			int aver,sum = 0;
			for (j = 0; j < tenum; j++)
			{
				sum += te[j].reye();
			}
			aver = sum/tenum;
			cout<<"教师平均年龄为 ："<<aver<<endl;
		}

		if (i == 5)//计算工人 平均年龄
		{
			int aver,sum = 0;
			for (j = 0; j <  lanum; j++)
			{
				sum += la[j].reye();
			}
			aver = sum/tenum;
			cout<<"工人平均年龄为 ："<<aver<<endl;	
		}

		if (i == 6)//删除一个教师
		{
			cout<<"input the name of delete teacher \n";
			char name[15];
			int count;
			cin>>name;
			for (j = 0; j< tenum; j++)
			{
				if (te[j].name == name)
				{
					count = j;
					break;
				}
			}
			for (i = count - 1; i < tenum - 1; i++)
				{
					te[j] = te[j + 2];
				}
			tenum--;
			cout<<"deletion has done \n";

		}

		if (i == 7)//删除一个 工人
		{
			cout<<"input the name of the delete lab \n";
			char name[20];
			int count;
			cin>>name;
			for (j = 0; j< tenum; j++)
			{
				if (strcmp(name,la[j].name) == 0)
				{
					count = j;
					break;
				}
			}
			for (i = count - 1; i < tenum - 1; i++)
				{
					la[j] = la[j + 2];
				}
			lanum--;
			cout<<"deletion has done \n";
		}
		if (i == 8)//按姓名检索信息
		{
			cout<<"input the name of search \n";
			char name[15];
			cin>>name;
			for (i = 0; i < tenum; i++)
			{
				if (strcmp(name,te[i].name) == 0)
				{
					cout<<te[i];
					break;
				}
			}
			for (i = 0; i< lanum; i++)
			{
				if (name == la[i].name)
				{
					cout<<la[i];
					break;
				}
			}
		}
		if (i == 0)//退出
		{
			break;
		}
	}
	ofstream outfile("E:\\ worker.txt",ios::out);
	for (i = 0; i< lanum; i++)
	{
		outfile<<la[i].num<<" "<<la[i].name<<" "<<la[i].sex<<" "<<"birthtime:"<<la[i].birthtime.year<<"/"<<la[i].birthtime.month<<"/"<<la[i].birthtime.day
			<<" "<<"worketime:"<<la[i].worktime.year<<"/"<<la[i].birthtime.month<<"/"<<la[i].birthtime.day<<" wage:"<<la[i].wage<<" year:"<<la[i].year<<endl;
	}
	for (i = 0; i < tenum; i++)
	{
		outfile<<te[i].num<<" "<<te[i].name<<" "<<te[i].sex<<" "<<"birthtime:"<<te[i].birthtime.year<<"/"<<te[i].birthtime.month<<"/"<<te[i].birthtime.day
			<<" "<<"worktime:"<<te[i].worktime.year<<"/"<<te[i].birthtime.month<<"/"<<te[i].birthtime.day<<" wage:"<<te[i].wage<<" year:"<<te[i].year<<endl;
	}
	outfile.close();
	
	return 0;
}


