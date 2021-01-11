#include<iostream>
#include<string>
using namespace std;
class Sales_data {

	//����������š�����������

	friend istream & operator>>(istream&, Sales_data &);

	//���������š�����������;���

	friend ostream & operator<<(ostream &, const Sales_data &);

	friend bool operator==(const Sales_data &, const Sales_data &);

	friend bool operator!=(const Sales_data &, const Sales_data &);

	// for "+", assume that both objects refer to the same book

	friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:

	Sales_data() : units_sold(0), revenue(0.0) {}

	Sales_data(const string & s, unsigned n, double r) : bookNo(s), units_sold(n), revenue(r) {}

	string get_bookNo() const;

	// for "+=", assume that both objects refer to the same book

	Sales_data & operator+=(const Sales_data &);

private:

	double avg_price() const;  //���ۣ����������������

	string bookNo;        //���

	unsigned units_sold; //����

	double revenue;      //����

};

istream & operator>>(istream &is, Sales_data &st)//��ţ�����������
{
	// TODO: �ڴ˴����� return ���
	is >> st.bookNo >> st.units_sold >> st.revenue;
	return is;
}

ostream & operator<<(ostream &os, const Sales_data &st)
{
	// TODO: �ڴ˴����� return ���
	os << st.bookNo<<" " << st.units_sold << " " << st.revenue<<" " << st.avg_price();
	return os;
}

bool operator==(const Sales_data &st1, const Sales_data &st2)
{

	return st1.revenue==st2.revenue;
}

bool operator!=(const Sales_data &st1, const Sales_data &st2)
{
	return !(st1.revenue == st2.revenue);
}

Sales_data operator+(const Sales_data &A, const Sales_data &B)
{

	return Sales_data(A.bookNo,A.units_sold+B.units_sold,A.revenue+B.revenue);
}

string Sales_data::get_bookNo() const
{
	return bookNo;
}

Sales_data & Sales_data::operator+=(const Sales_data &B)
{
	// TODO: �ڴ˴����� return ���

		//return Sales_data(bookNo, units_sold + B.units_sold, revenue + B.revenue);
	units_sold += B.units_sold;
	revenue += B.revenue;
		return *this;
	
}

double Sales_data::avg_price() const
{

	return revenue/units_sold;
}

int main()
{

	Sales_data item1, item2;

	while (cin >> item1 >> item2) {

		cout << item1 << "\n" << item2 << "\n";

		if (item1 == item2)

			cout << item1.get_bookNo() << " equals " << item2.get_bookNo() << "\n";

		if (item1 != item2)

			cout << item1.get_bookNo() << " doesn't equal " << item2.get_bookNo() << "\n";

		cout << (item1 + item2) << "\n";

		item1 += item2;

		cout << item1 << "\n";

	}

	return 0;
}


