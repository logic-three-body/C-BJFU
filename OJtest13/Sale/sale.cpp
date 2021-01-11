#include<iostream>
#include<string>
using namespace std;
class Sales_data {

	//依次输入书号、销量和收入

	friend istream & operator>>(istream&, Sales_data &);

	//依次输出书号、销量、收入和均价

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

	double avg_price() const;  //均价，等于收入除以销量

	string bookNo;        //书号

	unsigned units_sold; //销量

	double revenue;      //收入

};

istream & operator>>(istream &is, Sales_data &st)//书号，销量，收入
{
	// TODO: 在此处插入 return 语句
	is >> st.bookNo >> st.units_sold >> st.revenue;
	return is;
}

ostream & operator<<(ostream &os, const Sales_data &st)
{
	// TODO: 在此处插入 return 语句
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
	// TODO: 在此处插入 return 语句

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


