#include<iostream>
#include"class.h"
using namespace std;

int main()
{
	Fraction a, b;
	a.input();
	b.input();
	if (a.epual(b))
	{
		cout<<"a=b\n";
	}
	if (a.greaterThan(b))
	{
		cout<<"a>b"<<endl;
	}
	if (a.lessThan(b))
	{
		cout<<"a<b\n";
	}
	Fraction p1, p2, p3, p4;
	p1 = a.add(b);
	p2 = a.sub(b);
	p3 = a.mul(b);
	p4 = a.div(b);
	p1.display();
	p2.display();
	p3.display();
	p4.display();
	Fraction c;
	c = p4.reciprocal();
	Fraction d(c);
	c.display();
	d.display();
	return 0;
}

/*�����������У�
1��ͨ������������������a��b��
2���Ƚ�a��b��С�����մӴ�С��˳����������������ú���epual������greaterThan������lessThan�����Ƚϴ�С����
3������4������p1,p2,p3,p4����ֵ��Ϊ0.������a�� b�ĺ͡���˻����̣���ŵ�p1~p4�У����ֱ��p1~p4���������
4������ǰһ�������ĵ���c�����������������һ������d�У��ֱ����c��d��
*/
