class Fraction
{
private:
	int above;         //����
	int below;         //��ĸ
	void reduction();            //Լ��
public:
	Fraction(int a1=0,int a2=1);       //���캯��
	Fraction(const Fraction &f);       //�������캯��
	Fraction add(const Fraction &f);      //���������
	Fraction sub(const Fraction &f);      //��������ȥʵ�η���
	Fraction mul(const Fraction &f);      //���������
	Fraction div(const Fraction &f);      //����������ʵ�η���
	Fraction reciprocal();       //����
	bool epual( Fraction &f);        //��������
	bool greaterThan( Fraction &f);  //��������
	bool lessThan( Fraction &f);     //С������
	void display(); 
	void input();
};