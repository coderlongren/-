#include"class.h"
#include"iostream"
using namespace std;
Fraction::Fraction(int a1,int a2)
{
	above=a1;
	below=a2;
	reduction();
}
Fraction::Fraction(const Fraction &f)
{
	above=f.above;
	below=f.below;
	reduction();
}
void Fraction::reduction()
{
	
	int r, max;
	int a = below,b = above;
	if (below > above)
	{
		while (above != 0)
		{
			r = below % above;
			below = above;
			above = r;
		}
		max = below;
		above = b/max;
		below = a/max;

	}
	else 
	{
		while (below != 0)
		{
			r = above % below;
			above = below;
			below = r;
		}
		max = above;
		above = b/max;
		below = a/max;

	}
}
Fraction Fraction::add(const Fraction &f)
{
	
	int a=below*f.below;
	int b=above*f.below+f.above*below;
	return Fraction(b,a);
	
}
Fraction Fraction::sub(const Fraction &f)
{

	return Fraction(above*f.below-f.above*below,below*f.below);
}
Fraction Fraction::mul(const Fraction &f)
{
	
	return Fraction(above*f.above,below*f.below);

}
Fraction Fraction::div(const Fraction &f)
{
	
	return Fraction(above*f.below,below*f.above);
}
Fraction Fraction::reciprocal()
{
	
	int temp;
	temp=above;
	above=below;
	below=temp;
	return Fraction(above,below);

	
}
bool Fraction::epual(Fraction &f)
{
	reduction();
	f.reduction();
	if(above==f.above&&below==f.below)
		return 1;
	else return 0;
}        //等于运算
bool Fraction::greaterThan(Fraction &f)  //大于运算
{
	reduction();
	f.reduction();
	if(above* f.below-f.above*below>0)
		return 1;
	else return 0;
}
bool Fraction::lessThan( Fraction &f)   //小于运算
{
	reduction();
	f.reduction();
	if(above* f.below-f.above*below<0)
		return 1;
	else return 0;
}
void Fraction::display()
{
	cout<<above<<"/"<<below<<" "<<endl;

}	
void Fraction::input()
{
	cout<<"please input above and below:"<<endl;
	cin>>above>>below;
}
