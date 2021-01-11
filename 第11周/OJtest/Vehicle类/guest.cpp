#define _CRT_SECURE_NO_WARNINGS //put in first line
#include<iostream>
#include<cstring>
#include"car.h"
using namespace std;
int main()

{

	Vehicle *p;

	char type;

	char name[110], color[110];

	int pas;

	double cap;

	while (cin >> type)

	{

		cin >> name >> color;

		if (type == 'C')

		{

			cin >> pas;

			Car car(name, color, pas);

			p = &car;

			p->display();

		}

		else if (type == 'T')

		{

			cin >> cap;

			Truck truck(name, color, cap);

			p = &truck;

			p->display();

		}

	}

	return 0;


}