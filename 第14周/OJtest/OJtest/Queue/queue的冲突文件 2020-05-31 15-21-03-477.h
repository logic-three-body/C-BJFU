#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_
#endif // !QUEUE_H_
#include<iostream>
using namespace std;


template <typename T> class MyQueue;//ǰ������
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

	friend class MyQueue<T>;//��Ԫ��    
	//ͨ����Ԫ��������<<�����ģ�庯����Ҫд��<<���<Type>
	friend ostream & operator<<  (ostream & os, const MyQueue<T> & q)
	{
		os << "< ";
		os << q.Display();
		os << " >";
	}
};

template <typename T>
class MyQueue
{
public:
	MyQueue() : head(0), tail(0) {} // Empty MyQueue

	MyQueue(const MyQueue &Q) //�������캯��
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
		QueueItem<T>*p = new QueueItem<T>(t);//����һ������

		if (!Empty())//�ڲ������β����ʱ����Ҫ�ж϶����Ƿ�Ϊ�յģ�
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;//��βָ���ָ����һ��Ԫ�ص�ָ��ָ�����ɵ�����
			tail = p;//��βָ���ƶ������һ��������ȥ
		}
	}

	void Pop() // remove element from head of MyQueue
	{
		if (0 == head)
		{
			return;
		}
		QueueItem<T>*p = head;//���浱ǰָ���ֵ
		head = head->next;//��ͷָ��ָ����һ��Ԫ��
		delete p;//ɾ��
	}
	bool Empty() const { return head == 0; }
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
			cout << endl;
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