#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int array[] = {1,3,4,6,2,5,9,8,7};
	int i, j,temp; 
	cout<<"排序之前的数组 \n";
	for (i = 0; i < sizeof(array)/4; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	for (j = 1; j < sizeof(array)/4; j++)
	{
		temp = array[j];
		for (i = j - 1; i >= 0 && array[i] > temp; i--)
		{
			array[i + 1] = array[i];
		}
		array[i + 1] = temp;
	}
	cout<<"直接排序之后的数组\n";
	for (i = 0; i < sizeof(array)/4; i++)
	{
		cout<<array[i]<<" ";
	}

	return 0;
}