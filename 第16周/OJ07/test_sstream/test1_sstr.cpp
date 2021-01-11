#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	istringstream istr;
	istr.str("1 56.7");
	//上述两个过程可以简单写成 istringstream istr("1 56.7");
	cout << istr.str() << endl;
	int a;
	float b;
	istr >> a;
	cout << a << endl;
	istr >> b;
	cout << b << endl;
	return 0;
}

/*上例中，构造字符串流的时候，空格会成为字符串参数的内部分界，例子中对a,b对象的输入"赋值"操作证明了这一点，字符串的空格成为了整型数据与浮点型数据的分解点，利用分界获取的方法我们事实上完成了字符串到整型对象与浮点型对象的拆分转换过程。

　　str()成员函数的使用可以让istringstream对象返回一个string字符串（例如本例中的输出操作(cout<<istr.str();）。

　　ostringstream同样是由一个string对象构造而来，ostringstream类向一个string插入字符。
ostringstream的构造函数原形如下：
ostringstream::ostringstream(string str);

*/