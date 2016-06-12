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

/*请在主函数中：
1）通过键盘输入两个分数a和b；
2）比较a和b大小，按照从大到小的顺序对其进行输出（调用函数epual（）、greaterThan（）、lessThan（）比较大小）；
3）构造4个对象p1,p2,p3,p4，初值均为0.。计算a和 b的和、差、乘积、商，存放到p1~p4中，并分别对p1~p4进行输出；
4）计算前一个分数的倒数c，并将结果拷贝到另一个对象d中，分别输出c和d。
*/
