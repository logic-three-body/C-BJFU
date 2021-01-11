#include<iostream>
using namespace std;
template<class T, int SIZE = 20>
class Stack
{
private:
	T array[SIZE]; //���飬���ڴ��ջ��Ԫ��
	int top; //ջ��λ�ã������±꣩
public:
	Stack() :top(-1) {}
	//���캯������ʼ��ջ
	void Push(const T & x) //Ԫ����ջ
	{

		top++;
		array[top] = x;
		// cout<<"push top=="<<top<<endl;

	}
	T Pop() //ջ��Ԫ�س�ջ
	{
		// cout<<"pop top=="<<top<<endl;
		if (Empty())
			exit(0);
		return array[top--];//���˻���

	}
	void Clear() //��ջ���
	{
		while (!Empty())
			top--;

	}
	const T & Top() const //����ջ��Ԫ��
	{
		if (Empty())
			exit(0);
		return array[top];
	}
	bool Empty() const //����ջ�Ƿ�Ϊ��
	{
		if (-1 ==top )
			return 1;
		else
			return 0;
	}
	bool Full() const //�����Ƿ�ջ��
	{
		if (SIZE - 1 == top)
			return 1;
		else
			return 0;
	}
	int Size() //���ص�ǰջ��Ԫ�ظ���
	{
		return (top + 1);

	}
};

int main()
{
	Stack<int, 10> intStack;

	int n;
	cin >> n; //n<=10
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		intStack.Push(temp);
	}

	for (int i = 0; i < n; i++)
	{
		cout << intStack.Top() << " ";
		intStack.Pop();
	}
	cout << endl;

	if (intStack.Empty())
		cout << "Now, intStack is Empty." << endl;

	Stack<string, 5> stringStack;
	stringStack.Push("One");
	stringStack.Push("Two");
	stringStack.Push("Three");
	stringStack.Push("Four");
	stringStack.Push("Five");
	cout << "There are " << stringStack.Size() << " elements in stringStack." << endl;
	stringStack.Clear();
	if (stringStack.Empty())
		cout << "Now, there are no elements in stringStack" << endl;

	return 0;
}