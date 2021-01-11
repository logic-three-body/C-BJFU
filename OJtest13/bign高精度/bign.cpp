#define _CRT_SECURE_NO_WARNINGS //put in first line
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000;
class bign
{
private:
	int len, s[MAX];
public:
	bign();
	bign operator = (const char * num);//���������=
	bign(const char * num);//֧�ֳ�ʼ������
	bign operator = (int num);
	bign(int num) ;
	string str() const;    //����string����ַ�������ת��Ϊ�ַ�����������<<,>>���
	bign operator + (const bign& b) const;
	bign operator += (const bign& b);
	void clean();
	bign operator - (const bign& b) const;
	bign operator -= (const bign& b);
	bign operator / (const bign& b) const;
	bign operator /= (const bign &b);
	bign operator % (const bign &b) const;
	bign operator %= (const bign &b);
	bign operator * (const bign& b) const;
	bign operator *= (const bign& b);
	bool operator < (const bign& b) const;
	bool operator >(const bign& b) const;
	bool operator == (const bign& b) const;
	bool operator != (const bign& b) const;
	bool operator <= (const bign& b) const;
	bool operator >= (const bign& b) const;
};

bign::bign()//���캯��
{
	memset(s, 0, sizeof(s));
	len = 1;
}

bign bign::operator = (const char * num)//���������=
{
	len = strlen(num);
	for (int i = 0; i < len; i++)//�����ִ洢Ϊ��������
		s[i] = num[len - i - 1] - '0';
	return *this;
}

bign::bign(const char * num) { *this = num; }//֧�ֳ�ʼ������

bign bign::operator = (int num)
{
	char s[MAX];
	sprintf(s, "%d", num);//��num������ַ���s��
	*this = s;
	return *this;
}

bign::bign(int num) { *this = num; }

string bign::str() const     //����string����ַ�������ת��Ϊ�ַ�����������<<,>>���
{
	string tmp = "";
	for (int i = 0; i < len; i++)
		tmp = (char)(s[i] + '0') + tmp;
	if (tmp == "")	tmp = "0";
	return tmp;
}

bign bign::operator + (const bign& b) const//����ӷ�
{
	bign c;
	c.len = 0;
	for (int i = 0, g = 0; g || i < max(len, b.len); i++)//Ҫ��������λ��������һ��
	{
		int x = g;//gΪ������
		if (i < len)	x += s[i];
		if (i < b.len)	x += b.s[i];
		c.s[c.len++] = x % 10;
		g = x / 10;
	}
	return c;
}

bign bign::operator += (const bign& b)
{
	*this = *this + b;
	return *this;
}

void bign::clean()//��0�ų����õ���ʵ��len
{
	while (len > 1 && !s[len - 1])
		len--;
}

bign bign::operator - (const bign& b) const
{
	bign c;
	c.len = 0;
	for (int i = 0, g = 0; i < len; i++)
	{
		int x = s[i] - g;//��ȥ��1
		if (i < b.len)	x -= b.s[i];//�ϼ���
		if (x >= 0)		g = 0;
		else
		{
			g = 1;//x<0˵����Ҫ��ǰ��1
			x += 10;//��x��Ϊ��
		}
		c.s[c.len++] = x;
	}
	c.clean();//x����Ϊ0
	return c;
}

bign bign::operator -= (const bign& b)
{
	*this = *this - b;
	return *this;
}

bign bign::operator / (const bign& b) const
{
	bign c, f;
	for (int i = len - 1; i >= 0; i--)//�Ӹ�λ��ʼ��
	{
		f = f * 10;//��λ
		f.s[0] = s[i];//����λ
		while (f >= b)
		{
			f -= b;
			c.s[i]++;
		}
	}
	c.len = len;
	c.clean();
	return c;
}

bign bign::operator /= (const bign &b)
{
	*this = *this / b;
	return *this;
}

bign bign::operator % (const bign &b) const
{
	bign r = *this / b;
	r = *this - r * b;
	return r;
}

bign bign::operator %= (const bign &b)
{
	*this = *this % b;
	return *this;
}

bign bign::operator * (const bign& b) const
{
	bign c;
	c.len = len + b.len;//�����λ�����Ϊ��������λ��֮��
	for (int i = 0; i < len; i++)
		for (int j = 0; j < b.len; j++)
			c.s[i + j] += s[i] * b.s[j];//��Ӧλ�õĻ��ĺͣ��ۼ��������ǽ��
	for (int i = 0; i < c.len - 1; i++)
	{
		c.s[i + 1] += c.s[i] / 10;//��λ��ֵ
		c.s[i] %= 10;//����λ
	}
	c.clean();
	return c;
}

bign bign::operator *= (const bign& b)
{
	*this = *this * b;
	return *this;
}
//���رȽ������
bool bign::operator < (const bign& b) const
{
	if (len != b.len)
		return len < b.len;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != b.s[i])
			return s[i] < b.s[i];
	return false;
}

bool bign::operator >(const bign& b) const
{
	return b < *this;
}

bool bign::operator == (const bign& b) const
{
	return !(b < *this) && !(b > *this);
}

bool bign::operator != (const bign& b) const
{
	return b < *this || b > *this;
}

bool bign::operator <= (const bign& b) const
{
	return !(b < *this);
}

bool bign::operator >= (const bign& b) const
{
	return !(b > *this);
}




//����<<,>>��֧��ֱ�����bign����
istream& operator >> (istream &in, bign& x)//
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x)
{
	out << x.str();
	return out;
}

int main() {

	bign a, b, c;

	a = "123456789123456789987654321999999999999999999999999";

	cin >> b;

	c = 12345;

	cout << (a + b) << endl;

	cout << (a - b) << endl;

	cout << (a * b) << endl;

	cout << (a / b) << endl;

	cout << (a < b) << endl;

	cout << (a > c) << endl;

	a += b;

	cout << a << endl;

	cout << (a <= b) << endl;

	cout << (a >= c) << endl;

	a += c;

	cout << a << endl;

	cout << (a == b) << endl;

	cout << (a != c) << endl;

	return 0;

}
