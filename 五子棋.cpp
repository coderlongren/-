#include <iostream> 

#include <stdlib.h> 

using namespace std; 

class fivegame 

{ 
	char m,n; 

	int h,l; 

	char z; 

	char list[20][20]; 

public: 

	int kk; 

	int init(); 

	int enterchar(char q); 

	int print(); 

	int pk(); 

	int ifwin(); 

	bool ison; 

	bool test(); 

	char list1[5]; 

	int puout();  

};  

int fivegame::puout() 

{ 
	cout<<" 这 是 个 五 字 棋 游 戏 "<<endl; 

	cout<<" 制作--elva6401-- "<<endl; 

	cout<<" (注:行列都要用大写字母)"<<endl; 

	return 0; 

} 

 bool fivegame::test() 

{ 

	int i; 

	for (i=0;i<=4;i++) 

	{
		if (list1[i]!=z) 

			return false;
	} 

	return true; 

} 

  

  

int fivegame::init() 

{ 
	int i,j,m=0; 

	for (i=0;i<=9;i++) 
		cout<<i<<" "; 

	for (i=65;i<=75;i++) 
		cout<<static_cast<char>(i)<<" "; 

	cout<<0<<endl; 

	for (j=0;j<=8;j++) 

	{
		m=m+1; cout<<m<<" "; 

		for (i=0;i<=19;i++) 

		{ 
			list[j][i]=' '; 
			cout<<list[j][i]<<" ";
		} 

		cout<<m<<endl;
	} 

		m=64; 

	for (j=9;j<=19;j++) 

	{ 
		m=m+1; 
		cout<<static_cast<char>(m)<<" "; 

		for (i=0;i<=19;i++) 

		{ 
			list[j][i]=' '; 
			cout<<list[j][i]<<" ";
		} 

		cout<<static_cast<char>(m)<<endl;
	} 

		for (i=0;i<=9;i++) 
			cout<<i<<" "; 

		for (i=65;i<=75;i++) 
			cout<<static_cast<char>(i)<<" "; 

	cout<<0<<endl; 

	return 0; 

} 

int fivegame::enterchar(char q) 

{ 
	char a,b; 

	cout<<"现在轮到 "<<q<<" 下."<<endl; 

	cout<<"请输入要下的行号和列号."<<endl; 

	cin>>a>>b; 

	z=q;
	m=a;
	n=b; 

	return 0; 

} 

int fivegame::print() //////////////////////////////////////////////////////////////////////////////////////////////////////////

{ 
	if (static_cast<int>(m)>60) 
		h=static_cast<int>(m)-56; 

	else 
		h=static_cast<int>(m)-49; 

	if (static_cast<int>(n)>60)
		l=static_cast<int>(n)-56;

	else 
		l=static_cast<int>(n)-49; 

	int i,j,m=0; 

	if (list[h][l]!=' ') 

	{ 
		kk=0; 

		for (i=0;i<=9;i++)
			cout<<i<<" "; 

		for (i=65;i<=75;i++) 
			cout<<static_cast<char>(i)<<" "; 

		cout<<0<<endl; 

		for (j=0;j<=8;j++) 

		{ 
			m=m+1; cout<<m<<" "; 

			for (i=0;i<=19;i++) 

			cout<<list[j][i]<<" "; 

			cout<<m<<endl;
		} 

			m=64; 

		for (j=9;j<=19;j++) 

		{ 
			m=m+1; cout<<static_cast<char>(m)<<" "; 

			for (i=0;i<=19;i++) 

			cout<<list[j][i]<<" "; 

			cout<<static_cast<char>(m)<<endl;
		} 

			for (i=0;i<=9;i++) 
				cout<<i<<" "; 

			for (i=65;i<=75;i++)
				cout<<static_cast<char>(i)<<" "; 

			cout<<0<<endl; 

			return 0;
	} 

	else 

	list[h][l]=z; 

	for (i=0;i<=9;i++)
		cout<<i<<" "; 

	for (i=65;i<=75;i++)
		cout<<static_cast<char>(i)<<" "; 

	cout<<0<<endl; 

	for (j=0;j<=8;j++) 

	{
		m=m+1; cout<<m<<" "; 

		for (i=0;i<=19;i++) 

		cout<<list[j][i]<<" "; 

		cout<<m<<endl;
	} 

	m=64; 

	for (j=9;j<=19;j++) 

	{ 
		m=m+1; 
		cout<<static_cast<char>(m)<<" "; 

		for (i=0;i<=19;i++) 

		cout<<list[j][i]<<" "; 

		cout<<static_cast<char>(m)<<endl;
	} 

	for (i=0;i<=9;i++) 
		cout<<i<<" "; 

	for (i=65;i<=75;i++)
		cout<<static_cast<char>(i)<<" "; 
	
	cout<<0<<endl; 

	return 0; 

} 

int fivegame::ifwin() 

{ 
	int i,j,q=0,k=0; 

	for(i=0;i<=19;i++) 

	{ 
		q=0,k=0;  

		while (q<=15) 

		{ 
			for (j=q;j<=q+4;j++) 

			list1[j-k]=list[i][j]; 

			if (fivegame::test()) 

			{
				ison=true;
				return true;
			} 

			else 

			q++;
			k++;
		} 

} 

for(i=0;i<=19;i++) 

{
	q=0,k=0;  

	while (q<=15) 

	{ 
		for (j=q;j<=q+4;j++) 

		list1[j-k]=list[j][i]; 

		if (fivegame::test()) 

		{
			ison=true;
			return true;
		} 

		else 

		q++;
		k++;
	} 

} 

  

  

 for (i=0;i<=15;i++) 

 { 
	 q=0,k=0;  

	while (q<=15) 

	{ 

	 for (j=q;j<=q+4;j++) 

	 list1[j-k]=list[i+j-k][j]; 

	 if (fivegame::test()) 

	{
		ison=true;
		return true;
	 } 

	else 

	q++;
	 k++;
	} 

}  

for(i=18;i>=4;i--) 

{ 
	q=0,k=0;  

	while (q<=15) 

	{ 

	for (j=q;j<=q+4;j++) 

	list1[j-k]=list[i-j+k][19-j]; 

	if (fivegame::test()) 

	{
		ison=true;
		return true;
	} 

	else 

	q++;k++;
	} 

}  

for (i=0;i<=15;i++) 

 {
	 q=0,k=0;  

	while (q<=15) 

	{ 

		for (j=q;j<=q+4;j++) 

		list1[j-k]=list[i+j-k][19-j]; 

		if (fivegame::test()) 

		{
			ison=true;
			return true;
		} 

		else 

		q++;
		k++;
	} 

}  

for(i=18;i>=4;i--) 

{ 
	q=0,k=0;  

	while (q<=15) 

	{ 

		for (j=q;j<=q+4;j++) 

		list1[j-k]=list[i-j+k][19-j]; 

		 if (fivegame::test()) 

		{
			ison=true;
			return true;
		 } 

		else 

		q++;
		 k++;
	} 

}  

  

for(i=18;i>=4;i--) 

{ 
	q=0,k=0;  

while (q<=15) 

{ 

 for (j=q;j<=q+4;j++) 

 list1[j-k]=list[i-j+k][j]; 

 if (fivegame::test()) 

{
	ison=true;
	return true;
 } 

else 

q++;
 k++;
} 

}  

 return 0; 

} 

int fivegame::pk() 

{ 
	cout<<m<<" "<<n<<" "<<z <<endl; 

	cout<<static_cast<int>(m)<<static_cast<int>(n)<<endl; 

	return 0; 
} 

int main() 

{ 

	 int abc; 

  

	char y='a'; 

	fivegame game; 

	game.puout(); 

	game.ison=false; 

	game.init(); 

	while(game.ison==false) 

	{ 

		game.kk=1; 

		game.enterchar(y); 

		system("cls"); 

		game.puout(); 

		game.print(); 

		game.ifwin(); 

	if (game.kk==1) 

	{ 

		if (y=='a')
			y='b'; 

		else 
			y='a'; 

	 } 

	 } 

	if (y=='a') 
		y='b'; 

	else
		y='a'; 

	cout<<y<<" 赢了 !"<<endl; 

	cin>>abc; 

	return 0; 

}
