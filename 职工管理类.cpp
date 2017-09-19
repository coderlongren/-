#include <iostream.h>
#include "class.h"
#include <string.h>
void list()
{
	cout<<"**********************************************************************************\n";
	cout<<"**********************************************************************************\n";
	cout<<"**********************************************************************************\n";
	cout<<"****************   1 ---  增加一位教师记录                   *********************\n";
	cout<<"****************   2 ---  增加一位工人记录                   *********************\n";
	cout<<"****************   3 ---  显示所有职工记录                   *********************\n";
	cout<<"****************   4 ---  计算教师平均年龄                   *********************\n";
	cout<<"****************   5 ---  计算工人平均年龄                   *********************\n";
	cout<<"****************   6 ---  删除一个教师                       *********************\n";
	cout<<"****************   7 ---  删除一个工人                       *********************\n";
	cout<<"****************   8 ---  按姓名检索所有信息                 *********************\n";
	cout<<"****************   0 ---  结束程序运行                       *********************\n";
	cout<<"**********************************************************************************\n";
	cout<<"**********************************************************************************\n";
	cout<<"**********************************************************************************\n";
}

void lab::set()
{
	cout<<"num : \n";
	
	cin>>num;
	cout<<"name : \n";
	cin>>name;
	cout<<"sex : \n";
	cin>>sex;
	cout<<"birthyear : \n";
	cin>>birthtime.year;
	cout<<"birthmonth \n";
	cin>>birthtime.month;
	cout<<"birthday : \n";
	cin>>birthtime.day;
	cout<<"workyear \n";
	cin>>worktime.year;
	cout<<"workmonth : \n";
	cin>>worktime.month;
	cout<<"workday : \n";
	cin>>worktime.day;
	cout<<"wage \n";
	cin>>wage;
	setyear();
}

void worker::setyear()
{
	year = worktime.year - birthtime.year;
}

void worker::display()
{
	cout<<"num :"<<num<<endl;
	cout<<"name :"<<name<<endl;
	cout<<"sex :"<<sex<<endl;
	cout<<"birthtime :"<<birthtime.year<<"/"<<birthtime.month<<"/"<<birthtime.day<<endl;
	cout<<"worktime :"<<worktime.year<<"/"<<worktime.month<<"/"<<worktime.day<<endl;
	cout<<"wage :"<<wage<<endl;
	setyear();
	cout<<"year :"<<year<<endl;
}

void lab::display()
{
	cout<<"this is a lab \n";
	worker::display();
}

void teacher::display()
{
	cout<<"this is a teacher: \n";
	worker::display();
}

istream& operator >>(istream &input, lab &m)//  lab >>重载
{
	cout<<"num : \n";
	input>>m.num;
	cout<<"name : \n";
	input>>m.name;
	cout<<"sex : \n";
	input>>m.sex;
	cout<<"birthyear : \n";
	input>>m.birthtime.year;
	cout<<"birthmonth \n";
	input>>m.birthtime.month;
	cout<<"birthday : \n";
	input>>m.birthtime.day;
	cout<<"workyear \n";
	input>>m.worktime.year;
	cout<<"workmonth : \n";
	input>>m.worktime.month;
	cout<<"workday : \n";
	input>>m.worktime.day;
	cout<<"wage \n";
	input>>m.wage;
	m.setyear();
	return input;
}
void teacher::set()
{
	cout<<"num : \n";
	cin>>num;
	cout<<"name : \n";
	cin>>name;
	cout<<"sex : \n";
	cin>>sex;
	cout<<"birthyear : \n";
	cin>>birthtime.year;
	cout<<"birthmonth \n";
	cin>>birthtime.month;
	cout<<"birthday : \n";
	cin>>birthtime.day;
	cout<<"workyear \n";
	cin>>worktime.year;
	cout<<"workmonth : \n";
	cin>>worktime.month;
	cout<<"workday : \n";
	cin>>worktime.day;
	cout<<"wage \n";
	cin>>wage;
	setyear();
}

istream& operator >>(istream &input,teacher &m)
{
	cout<<"num : \n";
	input>>m.num;
	cout<<"name : \n";
	input>>m.name;
	cout<<"sex : \n";
	input>>m.sex;
	cout<<"birthyear : \n";
	input>>m.birthtime.year;
	cout<<"birthmonth \n";
	input>>m.birthtime.month;
	cout<<"birthday : \n";
	input>>m.birthtime.day;
	cout<<"workyear \n";
	input>>m.worktime.year;
	cout<<"workmonth : \n";
	input>>m.worktime.month;
	cout<<"workday : \n";
	input>>m.worktime.day;
	cout<<"wage \n";
	input>>m.wage;
	m.setyear();
	return input;
}

ostream& operator << (ostream &output,teacher &m)
{
	cout<<"this is a teacher \n";
	output<<"num :"<<m.num<<endl;
	output<<"name :"<<m.name<<endl;
	output<<"sex :"<<m.sex<<endl;
	output<<"birthtime :"<<m.birthtime.year<<"/"<<m.birthtime.month<<"/"<<m.birthtime.day<<endl;
	output<<"worktime :"<<m.worktime.year<<"/"<<m.worktime.month<<"/"<<m.worktime.day<<endl;
	output<<"wage :"<<m.wage<<endl;
	m.setyear();
	output<<"year :"<<m.year<<endl;
	return output;
}

ostream& operator << (ostream &output,lab &m)
{
	cout<<"this is a lab \n";
	output<<"num :"<<m.num<<endl;
	output<<"name :"<<m.name<<endl;
	output<<"sex :"<<m.sex<<endl;
	output<<"birthtime :"<<m.birthtime.year<<"/"<<m.birthtime.month<<"/"<<m.birthtime.day<<endl;
	output<<"worktime :"<<m.worktime.year<<"/"<<m.worktime.month<<"/"<<m.worktime.day<<endl;
	output<<"wage :"<<m.wage<<endl;
	m.setyear();
	output<<"year :"<<m.year<<endl;
	return output;
}

