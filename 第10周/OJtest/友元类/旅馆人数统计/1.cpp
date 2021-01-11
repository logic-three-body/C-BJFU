#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Hotel
{
public:
	int static getTotal();
	void print();
	void add(string name1);
	string getName();
	static int total;
private:
	int num=0;
	string guest;
};

int Hotel::getTotal()
{
	return total;
}
void Hotel::add(string name1)
{
	++total;
	guest = name1;
	num = total;

}
void Hotel::print()
{
	cout << num << " " << guest << " " << total << endl;
}
string Hotel::getName()
{
	return guest;
}
int Hotel::total = 0;
int main() {

	Hotel h[100];

	h[0].add("Susan");

	h[1].add("Peter");

	h[2].add("John");

	h[3].add("Mary");

	h[4].add("Alice");

	string name;

	cin >> name;

	for (int i = 0; i < Hotel::getTotal(); i++)

	{

		if (h[i].getName() == name)

		{

			h[i].print();

			break;

		}

	}

	return 0;

}