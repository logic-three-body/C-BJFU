#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>

bool IsHuiWen(char* x);//�ж��Ƿ��ǻ�����
void swap(char **num1, char **num2);//���ַ�������ר���޸��ַ�
int main()
{
	using namespace std;
	int N;
	cin >> N;

	//char Strings[50][100];
	//char a[100];
	char**Strings = new char*[N];//��̬����
	for (int i = 0; i < N; i++) Strings[i] = new char[100];

	char *a = new char[100];
	int counter = 0;//��¼�м���������
	for (int i = 0, j = 0; i < N; i++)
	{
		cin >> a;

		if (IsHuiWen(a))//�ѻ���������ά����
		{
			//strcpy(Strings[i], a);//ע�����д���ⲽ���ᵼ������β�룬�е���Ԫ���е�û��
			strcpy(Strings[j], a);//��֤����Ԫ�ص�������
			++counter;
			j++;
			//cout << Strings[i] << endl;
		}
	}
	//��ʼ����ð������
	char temp[50][100];
	for (int i = 0; i < counter - 1; i++)
	{
		
		for (int j = counter-1; j>i; j--)
		{
			if (strlen(Strings[j]) < strlen(Strings[j-1]))
				swap(Strings[j], Strings[j-1]);
		}
		
		
	}

	if (counter > 0) {
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