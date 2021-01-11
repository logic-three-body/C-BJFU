#pragma once
#ifndef  BOOK_H_
#define  BOOK_H_
#endif // ! BOOK_H_
#include<iostream>
#include<string>
using namespace std;
class Item_base //δ���۵�ͼ����Ʒ

{

protected:

	string ISBN; //ͼ�����к�

	double price; //����

public:

	Item_base(const string & book_ISBN = "", double sales_price = 0.0);

	string get_ISBN() const;

	virtual double net_price(int) const; //���ع���ָ��������ͼ����ܼ�

	virtual ~Item_base();

};
Item_base::Item_base(const string & book_ISBN , double sales_price ):ISBN(book_ISBN),price(sales_price)
{

}

inline string Item_base::get_ISBN() const
{
	return ISBN;
}

inline double Item_base::net_price(int n) const
{
	return n*price;
}

inline Item_base::~Item_base()
{
}


class Bulk_Item : public Item_base //���ݹ�����������

{

public:

	Bulk_Item(const string & book_ISBN = "", double sales_price = 0.0, int min_qty = 0, double discount = 0.0);

	double net_price(int) const; //���ظ��ݹ����������ۺ���ܼ�

private:

	int _min_qty; // ������������Դ���Ӧ���ۿ�

	double _discount; //�ۿ�

};

Bulk_Item::Bulk_Item(const string & book_ISBN, double sales_price, int min_qty, double discount):_min_qty(min_qty),_discount(discount),
Item_base(book_ISBN,sales_price)
{

}

inline double Bulk_Item::net_price(int n) const
{
	return n*price*(1-_discount);
}
