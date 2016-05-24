#include <stdio.h> 
#include <conio.h>
#include <string.h>
int main() 
{ 
	 
	char passord[] = "rensailong";
	char m[sizeof(passord)];
	printf("%d %d ",sizeof(passord),sizeof(m));
	int i;
	for(i = 0; i < sizeof(passord) - 1; i++)
	{
		m[i] = getch();
		printf("*");
	}
	m[i] = '\0';
	if(strcmp(passord,m) == 0)
		printf("passord is right \n");
	else printf(" passord is wrong \n");
	
   
  return 0;
}
/*
#include <stdio.h> 
int main() 
{ 
char str1[20], str2[20];
 gets(str1); 
printf("%s\n",str1); 
   gets(str2);  
printf("%s\n",str2);
  return 0; 
}*/