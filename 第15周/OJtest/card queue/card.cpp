#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n;//num of card
	cin >> n;
	queue<int>q;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	int num = n;
	while (num > 1)
	{
		
		cout << q.front() << " ";
		q.pop();//�ӵ���һ���� 		
		num--;//�Ƶ����� ��1 
		
		  //���µĵ�һ���Ʒŵ����
		int first_now = q.front();
		q.pop();
		q.push(first_now);
	}

	cout << q.front() << endl;
	return 0;
}