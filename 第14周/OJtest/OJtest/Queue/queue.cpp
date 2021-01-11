#include<iostream>
using namespace std;


template <typename T> class MyQueue;//前置声明
template <typename T> std::ostream & operator<<(std::ostream &, const MyQueue<T> &);

template <typename T>
class QueueItem
{
public:
	QueueItem(const T & t) :item(t), next(0)
	{}
private:
	T item; //value stored in this element
	QueueItem *next; // pointer to next element in the MyQueue

	friend class MyQueue<T>;//友元类    
	//通过友元函数重载<<运算符模板函数，要写上<<后的<Type>
	template<class T>
	friend ostream & operator<< <T>  (ostream & os, const MyQueue<T> & q)
	{
		os << "< ";
		q.Display();
		os << ">";
		return os;
	}


};

template <typename T>
class MyQueue
{
public:
	MyQueue() : head(0), tail(0) {} // Empty MyQueue

	MyQueue(const MyQueue &Q) //拷贝构造函数
		:head(0), tail(0)
	{
		CopyElements(Q);
	};

	~MyQueue() { Destroy(); }

	MyQueue & operator=(const MyQueue &q)
	{
		for (QueueItem<T>*p = q.head; p; p = p->next)
		{
			Push(p->item);
		}
		return *this;
	}

	// return element from head of MyQueue
	T & Front() { return head->item; }
	const T & Front() const { return head->item; }
	void Push(const T &t) //add element to back of MyQueue
	{
		QueueItem<T>*p = new QueueItem<T>(t);//构造一个对象

		if (!Empty())//在插入队列尾部的时候需要判断队列是否为空的！
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;//将尾指针的指向下一个元素的指针指向生成的数据
			tail = p;//将尾指针移动到最后一个数据上去
		}
	}

	void Pop() // remove element from head of MyQueue
	{
		if (0 == head)
		{
			return;
		}
		QueueItem<T>*p = head;//保存当前指针的值
		head = head->next;//将头指针指向下一个元素
		delete p;//删除
	}
	bool Empty() const { return head != NULL; }
	void Display() const
	{
		if (!head)
		{
			cout << "NULL" << endl;
		}
		else
		{

			for (QueueItem<T>*p = head; p; p = p->next)
			{
				cout << p->item << " ";
			}
			//cout << endl;
		}

	}
private:
	QueueItem<T> *head;
	QueueItem<T> *tail;
	void Destroy() //delete all the elements
	{
		while (!Empty())
		{
			Pop();
		}
	}
	void CopyElements(const MyQueue &orig)
	{
		
		for (QueueItem<T> *pt = orig.head; pt; pt = pt->next)
			Push(pt->item);

	}


};
int main()
{
	MyQueue<int> qi;
	qi.Push(1);
	qi.Push(2);
	qi.Push(3);
	qi.Push(4);
	qi.Push(5);
	qi.Pop();
	qi.Display();
	cout << "\n";
	cout << qi;
	cout << endl;

	MyQueue<int> qi2(qi);
	qi2.Display();
	cout << endl;

	MyQueue<int> qi3;
	qi3 = qi;
	cout << qi3;

	return 0;
}
