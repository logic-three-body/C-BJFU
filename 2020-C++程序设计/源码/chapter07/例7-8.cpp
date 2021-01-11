#include <iostream>
#include <stdexcept>
using namespace std;

int set_age(int age)
{
	if (age <= 0)//若年龄值不符合实际情况，则抛出invalid_argument异常类对象
		throw invalid_argument("The age should be greater than 0!");
	return age;
}

int main()
{
	int age;
	try{
		age = set_age(0);
	}
	catch (exception &e)
	{
		cout << "Exception:" << e.what() << endl;
	}
	system("pause");
	return 0;
}
