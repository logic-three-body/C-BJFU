#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>

bool IsHuiWen(char* x);//判断是否是回文数
void swap(char **num1, char **num2);//传字符函数，专门修改字符
int main()
{
	using namespace std;
	int N;
	cin >> N;
	
	//char Strings[50][100];
	//char a[100];
	char**Strings = new char*[50];//动态分配
	for (int i = 0; i < 50; i++) Strings[i] = new char[100];

	char *a=new char[100];
	int counter = 0;//记录有几个回文数
	for (int i = 0,j=0; i < N; i++)
	{
		cin >> a;		

		if (IsHuiWen(a))//把回文数给二维数组
		{
			//strcpy(Strings[i], a);//注意如果写成这步，会导致数组参差不齐，有的有元素有的没有
			strcpy(Strings[j], a);//保证数组元素的连贯性
			++counter;
			j++;
			//cout << Strings[i] << endl;
		}	
	}
	//开始排序，选择排序
	char temp[50][100];
	for (int i = 0; i < counter-1; i++)
	{
		int min = i;
		for (int j = i + 1; j < counter; j++)
		{
			if (strlen(Strings[j]) < strlen(Strings[min]))
				min = j;			
		}
		swap(Strings[min],Strings[i]);		
	}

	if(counter>0){
	for (int i = 0; i < counter; i++)
		if (counter - 1 == i) cout << Strings[i];
		else cout << Strings[i] << endl;
	//cout << Strings[i] << endl;
	}

	delete[]a;
	delete[]Strings;
	return 0;
}
bool IsHuiWen(char* x)
{
	for (int i = 0; i < strlen(x) / 2; i++)
	{
		if (x[i] != x[strlen(x) - 1 - i])return false;
	}
	return true;
}
void swap(char **num1, char **num2)
{
	char *t;
	t = *num1;
	*num1 = *num2;
	*num2 = t;
}