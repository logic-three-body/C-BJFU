#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v; //创建一个空的vector对象
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);  //将元素添加到v中
	for (int i = 0; i < 10; i++)
		cout << v[i] << "  ";  //输出元素
	cout << endl;
	v.pop_back();  //移除末尾的元素
	for (int i = 0; i < 9; i++) //此时元素个数为9
		cout << v[i] << "  ";  //输出元素
	cout << endl;
	vector<int>v1(12,99) ;
	for (int i = 0; i < 10; i++)
		v1.push_back(i + 1);  //将元素添加到v中
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "  ";  //输出元素
	cout << endl;
	v1.pop_back();  //移除末尾的元素
	for (int i = 0; i < v1.size(); i++) //此时元素个数为9
		cout << v1[i] << "  ";  //输出元素
	cout << endl;

	vector<int>v2{ 1,2,3 };
	for (int i = 0; i < 10; i++)
		v2.push_back(i + 1);  //将元素添加到v中
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";  //输出元素
	cout << endl;
	v2.pop_back();  //移除末尾的元素
	for (int i = 0; i < v2.size(); i++) //此时元素个数为9
		cout << v2[i] << "  ";  //输出元素
	cout << endl;

	vector<int>::iterator iter;
	for(iter=v1.begin();iter!=v1.end();iter++)
		cout << *iter << "  ";  //输出元素
	cout << endl;
	//vector<int>v2(v1);
	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << "  ";  //输出元素
	cout << endl;
	system("pause");
	return 0;
}
