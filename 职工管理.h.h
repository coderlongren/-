#include <iostream.h>
#include <string.h>
class time
{
public:
	time(int a = 1997,int b = 0, int c = 0):year(a),month(b),day(c){}
	int year;
	int month;
	int day;
};
class worker//职工编号、姓名、性别、工资、出生时间、参加工作时间和年龄
{
public:
	void setyear();
	void display();
	char name[15];
	char num[20];
	char sex[10];;
	int wage;
	time birthtime;
	time worktime;
	int year;
};

class lab:public worker
{
public:
	void display();
	void set();
	friend istream& operator >>(istream& ,lab&);
	friend ostream& operator <<(ostream& ,lab&);
	int reye()
	{
		return year;
	}

};

class teacher:public worker
{
public:
	void display();
	void set();
	friend istream& operator >>(istream& ,teacher&);
	friend ostream& operator <<(ostream& ,teacher&);
	int reye()
	{
		return year;
	}

};