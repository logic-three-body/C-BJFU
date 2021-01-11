#include<iostream>
const long MAX = 999999;
using namespace std;
const int SIZE = 20;
template<class T>
class Stack
{
private:
	T    array[SIZE];        //���飬���ڴ��ջ��Ԫ��
	int top;                //ջ��λ�ã������±꣩
public:
	Stack() ;                //���캯������ʼ��ջ
	void Push(const T &);  //Ԫ����ջ
	T Pop();                //ջ��Ԫ�س�ջ
	void Clear();           //��ջ���
	const T & Top() const;  //����ջ��Ԫ��
	bool Empty() const;     //����ջ�Ƿ�Ϊ��
	bool Full() const;     //�����Ƿ�ջ��
	int Size();            //���ص�ǰջ��Ԫ�ظ���
};

template<class T>
Stack<T>::Stack() :top(-1) {}//���캯������ʼ��ջ

template<class T>
void Stack<T>::Push(const T &a)//Ԫ����ջ
{
	      top++;
	      array[top] = a;
}

template<class T>
T Stack<T>::Pop()
{
	  //    cout<<"pop top=="<<top<<endl;
	     if (empty())//stack is empty
		          exit(0);
	    return array[top--];//��������� 
}

template<class T>
void Stack<T>::Clear()
{
	      while (!empty())
		       top--;
}

template<class T>
const T & Stack<T>::Top() const
{
	// TODO: �ڴ˴����� return ���
	      if (empty())
		          exit(0);
	      return array[top];
}

template<class T>
bool Stack<T>::Empty() const
{
	     if (top == -1)
		          return 1;
	      else
		          return 0;
}

template<class T>
bool Stack<T>::Full() const
{
	      if (SIZE - 1 == top)
		          return 1;
	      else
		         return 0;
}

template<class T>
int Stack<T>::Size()
{
	return top + 1;
}





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
		cout << "Now, intStack is empty." << endl;

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