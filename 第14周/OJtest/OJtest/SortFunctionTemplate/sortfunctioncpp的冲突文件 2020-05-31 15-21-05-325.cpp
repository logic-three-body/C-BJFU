#include<iostream>
using namespace std;
const int SIZE= 5;
template<typename T>
void Swap(T& t1, T& t2)
{
	T tmp;
	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template<typename T>
void Input(T*a,int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cin >> a[i];
}
template<typename T>
void Output(T*a,int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (i == SIZE - 1)
			cout << a[i];
		else
		cout << a[i] << ", ";
	}
		
	cout << endl;
}
template<typename T>
void Sort(T*a,int SIZE)//—°‘Ò≈≈–Ú
{
	int min,j,i;
	for (i = 0; i < SIZE - 1; i++)
	{
		min = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[min], a[i]);
	}
	
}

int main()
{
	const int LEN = 5;
	int type;
	while (std::cin >> type)
	{
		switch (type)
		{
		case 0:
		{
			int a1[LEN];
			Input<int>(a1, LEN); Sort<int>(a1, LEN); Output<int>(a1, LEN);
			break;
		}
		case 1:
		{
			char a2[LEN];
			Input(a2, LEN); Sort(a2, LEN); Output(a2, LEN);
			break;
		}
		case 2:
		{
			double a3[LEN];
			Input(a3, LEN); Sort(a3, LEN); Output(a3, LEN);
			break;
		}
		}
	}

	return 0;
}