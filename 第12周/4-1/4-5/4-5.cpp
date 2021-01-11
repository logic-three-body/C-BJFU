#include <iostream>
using namespace std;
class Student
{
private:
	int id;
	double score;
public:
	friend ostream& operator<< (ostream& os, const Student& st);
	friend istream& operator>> (istream& is, Student& st);
	//���ع�ϵ�����
	friend bool operator== (const Student& st1, const Student& st2);
	friend bool operator!= (const Student& st1, const Student& st2);
	friend bool operator> (const Student& st1, const Student& st2);
	friend bool operator< (const Student& st1, const Student& st2);
};

ostream& operator<< (ostream& os, const Student& st)
{
	os << "id:" << st.id << ", score:" << st.score;
	return os;
}

istream& operator>> (istream& is, Student& st)
{
	is >> st.id >> st.score;
	return is;
}

bool operator== (const Student& st1, const Student& st2)
{
	return st1.score == st2.score; //����==�����
}
bool operator!= (const Student& st1, const Student& st2)
{
	return !(st1.score == st2.score); //����!=�����
}

bool operator> (const Student& st1, const Student& st2)
{
	return st1.score > st2.score; //����>�����
}

bool operator< (const Student& st1, const Student& st2)
{
	return st1.score < st2.score; //����<�����
}

int main()
{
	Student st1, st2;
	cout << "����������ѧ����id��źͳɼ���" << endl;
	cin >> st1 >> st2;
	cout << "�Ƚ�����ѧ���ĳɼ���" << endl;
	if (st1 > st2)
		cout << "��һ��ѧ���ɼ��ϸߣ�" << st1 << endl;
	else if (st1 < st2)
		cout << "�ڶ���ѧ���ɼ��ϸߣ�" << st2 << endl;
	else
		cout << "����ѧ���ɼ���ͬ��" << st2 << endl;

	system("pause");
	return 0;
}
