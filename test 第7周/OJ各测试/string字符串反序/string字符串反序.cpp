#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string *apha = new string[N];
	char*apha1 = new char[N+100]();
	//cout << apha[0]+"1" << endl;
	//cout << apha1[0]+1 << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> apha[i];
		reverse(apha[i].begin(), apha[i].end());
	}
	sort(apha,apha+N);
	for (int i = 0; i < N; i++)
	{
	reverse(apha[i].begin(), apha[i].end());
	cout << apha[i] << endl;
	}
		

}