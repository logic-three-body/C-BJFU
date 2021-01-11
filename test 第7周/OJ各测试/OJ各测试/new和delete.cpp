#include<iostream>
int main()
{
	using namespace std;
	int *interge = new int(100);
	//cout << *interge << endl;
	int *interge2 = new int(10);
	//cout << *interge2 << endl;
	int *interge3 = new int[3]();
	cin >> interge3[0]>> interge3[1] >> interge3[2];
	cout << *interge << endl;
	cout << *interge2 << endl;
	cout << interge3[0] << "," << interge3[1] << "," << interge3[2];
	//cout << interge3 << endl;
	return 0;
}