#include<iostream>
#include<string>
using namespace std;
class CheckedPtr

{

public:

	CheckedPtr(int * b, int * e) : beg(b), end(e), curr(b) {  }

	CheckedPtr & operator ++(); // prefix ++

	CheckedPtr & operator --(); // prefix --

	CheckedPtr   operator ++(int); // postfix ++

	CheckedPtr   operator --(int); // postfix --

	int * GetBeg();

	int * GetEnd();

	int * GetCurr();

private:

	int * beg;  // pointer to beginning of the array

	int * end;  // one past the end of the array

	int * curr; // current position within the array

};

CheckedPtr & CheckedPtr::operator++()
{
	// TODO: 在此处插入 return 语句
	++curr;
	return *this;
}

CheckedPtr & CheckedPtr::operator--()
{
	// TODO: 在此处插入 return 语句
	--curr;
	return *this;
}

CheckedPtr CheckedPtr::operator++(int)
{
	CheckedPtr tmp(*this);
	++*this;//调用已经实现的前置++
	return tmp;
}

CheckedPtr CheckedPtr::operator--(int)
{
	CheckedPtr tmp(*this);
	--*this;//调用已经实现的前置++
	return tmp;
}

int * CheckedPtr::GetBeg()
{
	return beg;
}

int * CheckedPtr::GetEnd()
{
	return end;
}

int * CheckedPtr::GetCurr()
{
	return curr;
}

int main() {

	int n;

	cin >> n;

	int * array = new int[n];

	for (int i = 0; i < n; i++)

		cin >> array[i];

	CheckedPtr cp(array, array + n);

	for (; cp.GetCurr() < cp.GetEnd(); cp++)

		cout << *cp.GetCurr() << " ";

	cout << endl;

	for (--cp; cp.GetCurr() > cp.GetBeg(); cp--)

		cout << *cp.GetCurr() << " ";

	cout << *cp.GetCurr() << endl;

	delete[] array;

	return 0;

}