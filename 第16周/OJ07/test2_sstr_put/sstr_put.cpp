#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;
int main()
{
	ostringstream ostr;
	ostr.str("abc");
	//如果构造的时候设置了字符串参数,那么增长操作的时候不会从结尾开始增加,而是修改原有数据,超出的部分增长
	ostr.put('d');
	ostr.put('e');
	ostr << "fg";

	string gstr = ostr.str();
	cout << gstr;
	system("pause");
}

/*
在上例代码中，我们通过put()或者左移操作符可以不断向ostr插入单个字符或者是字符串，通过str()函数返回增长过后的完整字符串数据，但值 得注意的一点是，当构造的时候对象内已经存在字符串数据的时候，那么增长操作的时候不会从结尾开始增加,而是修改原有数据,超出的部分增长。
[ basic_stringbuf::str :
Sets or gets the text in a string buffer without changing the write position. ]

　　对于stringstream了来说，不用我多说，大家也已经知道它是用于C++风格的字符串的输入输出的。
stringstream的构造函数原形如下：

　　stringstream::stringstream(string str);
*/