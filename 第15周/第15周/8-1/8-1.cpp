#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v; //����һ���յ�vector����
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);  //��Ԫ����ӵ�v��
	for (int i = 0; i < 10; i++)
		cout << v[i] << "  ";  //���Ԫ��
	cout << endl;
	v.pop_back();  //�Ƴ�ĩβ��Ԫ��
	for (int i = 0; i < 9; i++) //��ʱԪ�ظ���Ϊ9
		cout << v[i] << "  ";  //���Ԫ��
	cout << endl;
	vector<int>v1(12,99) ;
	for (int i = 0; i < 10; i++)
		v1.push_back(i + 1);  //��Ԫ����ӵ�v��
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "  ";  //���Ԫ��
	cout << endl;
	v1.pop_back();  //�Ƴ�ĩβ��Ԫ��
	for (int i = 0; i < v1.size(); i++) //��ʱԪ�ظ���Ϊ9
		cout << v1[i] << "  ";  //���Ԫ��
	cout << endl;

	vector<int>v2{ 1,2,3 };
	for (int i = 0; i < 10; i++)
		v2.push_back(i + 1);  //��Ԫ����ӵ�v��
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";  //���Ԫ��
	cout << endl;
	v2.pop_back();  //�Ƴ�ĩβ��Ԫ��
	for (int i = 0; i < v2.size(); i++) //��ʱԪ�ظ���Ϊ9
		cout << v2[i] << "  ";  //���Ԫ��
	cout << endl;

	vector<int>::iterator iter;
	for(iter=v1.begin();iter!=v1.end();iter++)
		cout << *iter << "  ";  //���Ԫ��
	cout << endl;
	//vector<int>v2(v1);
	for (iter = v2.begin(); iter != v2.end(); iter++)
		cout << *iter << "  ";  //���Ԫ��
	cout << endl;
	system("pause");
	return 0;
}
