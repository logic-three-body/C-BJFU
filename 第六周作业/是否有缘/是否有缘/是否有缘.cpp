#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>
bool IsPrime(int a,int b);//�ж�����
int main()
{
	using namespace std;
	int a, b;
	
	while ((cin>>a>>b)) {
	if (IsPrime(a, b)) cout << "Yes" << endl;
	else cout << "No" << endl;
	

	}

	//if (IsPrime(a, b)) cout << "Yes" << endl;
	//else cout << "No" << endl;

}


bool IsPrime(int a, int b)
{
	int temp = 0;
	while (b > 0) {
		temp = a % b;
		a = b;
		b = temp;//��=0˵��������֮����ڱ�����ϵ
	}
	if (a == 1) return true;
	else return false;
}