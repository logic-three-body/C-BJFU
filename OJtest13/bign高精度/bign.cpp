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
	bign operator = (const char * num);//重载运算符=
	bign(const char * num);//支持初始化操作
	bign operator = (int num);
	bign(int num) ;
	string str() const;    //利用string类把字符串数组转换为字符串，方便用<<,>>输出
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

bign::bign()//构造函数
{
	memset(s, 0, sizeof(s));
	len = 1;
}

bign bign::operator = (const char * num)//重载运算符=
{
	len = strlen(num);
	for (int i = 0; i < len; i++)//把数字存储为逆序数组
		s[i] = num[len - i - 1] - '0';
	return *this;
}

bign::bign(const char * num) { *this = num; }//支持初始化操作

bign bign::operator = (int num)
{
	char s[MAX];
	sprintf(s, "%d", num);//把num输出到字符串s中
	*this = s;
	return *this;
}

bign::bign(int num) { *this = num; }

string bign::str() const     //利用string类把字符串数组转换为字符串，方便用<<,>>输出
{
	string tmp = "";
	for (int i = 0; i < len; i++)
		tmp = (char)(s[i] + '0') + tmp;
	if (tmp == "")	tmp = "0";
	return tmp;
}

bign bign::operator + (const bign& b) const//定义加法
{
	bign c;
	c.len = 0;
	for (int i = 0, g = 0; g || i < max(len, b.len); i++)//要两个数的位数都计算一便
	{
		int x = g;//g为其余数
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

void bign::clean()//把0排除，得到真实的len
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
		int x = s[i] - g;//减去借1
		if (i < b.len)	x -= b.s[i];//上减下
		if (x >= 0)		g = 0;
		else
		{
			g = 1;//x<0说明需要向前借1
			x += 10;//将x变为正
		}
		c.s[c.len++] = x;
	}
	c.clean();//x可能为0
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
	for (int i = len - 1; i >= 0; i--)//从高位开始减
	{
		f = f * 10;//升位
		f.s[0] = s[i];//补低位
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
	c.len = len + b.len;//结果的位数最大为两个因子位数之和
	for (int i = 0; i < len; i++)
		for (int j = 0; j < b.len; j++)
			c.s[i + j] += s[i] * b.s[j];//对应位置的积的和，累加起来就是结果
	for (int i = 0; i < c.len - 1; i++)
	{
		c.s[i + 1] += c.s[i] / 10;//进位的值
		c.s[i] %= 10;//余数位
	}
	c.clean();
	return c;
}

bign bign::operator *= (const bign& b)
{
	*this = *this * b;
	return *this;
}
//重载比较运算符
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




//重载<<,>>，支持直接输出bign对象
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
