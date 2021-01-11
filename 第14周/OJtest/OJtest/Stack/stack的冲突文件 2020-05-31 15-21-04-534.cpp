#include<iostream>
const long MAX = 999999;
using namespace std;
const int SIZE = 20;
template<class T>
class Stack
{
private:
	T    array[SIZE];        //数组，用于存放栈的元素
	int top;                //栈顶位置（数组下标）
public:
	Stack() ;                //构造函数，初始化栈
	void Push(const T &);  //元素入栈
	T Pop();                //栈顶元素出栈
	void Clear();           //将栈清空
	const T & Top() const;  //访问栈顶元素
	bool Empty() const;     //测试栈是否为空
	bool Full() const;     //测试是否栈满
	int Size();            //返回当前栈中元素个数
};

template<class T>
Stack<T>::Stack() :top(-1) {}//构造函数，初始化栈

template<class T>
void Stack<T>::Push(const T &a)//元素入栈
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
	    return array[top--];//如果多则换行 
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
	// TODO: 在此处插入 return 语句
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