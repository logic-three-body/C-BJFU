#include "图书商品类.h"
#include<iostream>
#include<string>
using namespace std;
int main()

{

	Item_base book("0-001-0001-1", 10.0);

	Bulk_Item bulk1("0-001-0001-1", 10.0, 5, 0.1);

	Bulk_Item bulk2("0-001-0001-1", 10.0, 10, 0.2);

	int num;

	while (cin >> num)

	{

		cout << bulk1.get_ISBN() << "\t" << num << "\t";

		Item_base * p;

		if (num >= 10) p = &bulk2;

		else if (num >= 5) p = &bulk1;

		else p = &book;

		cout << p->net_price(num) << "\n";

	}

	return 0;
}

