class Fraction
{
private:
	int above;         //分子
	int below;         //分母
	void reduction();            //约分
public:
	Fraction(int a1=0,int a2=1);       //构造函数
	Fraction(const Fraction &f);       //拷贝构造函数
	Fraction add(const Fraction &f);      //两分数相加
	Fraction sub(const Fraction &f);      //本分数减去实参分数
	Fraction mul(const Fraction &f);      //两分数相乘
	Fraction div(const Fraction &f);      //本分数除以实参分数
	Fraction reciprocal();       //求倒数
	bool epual( Fraction &f);        //等于运算
	bool greaterThan( Fraction &f);  //大于运算
	bool lessThan( Fraction &f);     //小于运算
	void display(); 
	void input();
};