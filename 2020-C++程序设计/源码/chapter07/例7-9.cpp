#include <iostream>
#include <cassert>

void *my_memcpy(void *dest, const void *src, int len)//编写memcpy函数
{
	int i;
	char *dest_cp;
	const char *src_cp;

	//内存数据拷贝时，要求目标地址和原始数据所在地址都不为nullptr
	//若某个地址为nullptr则断言失败
	assert(dest && src);

	dest_cp = (char *)dest;
	src_cp = (const char *)(src);
	for (i = 0; i < len; i++)                           //按字节完成数据拷贝
		*dest_cp++ = *src_cp++;

	return dest_cp;
}
int main()
{
	char *dest = nullptr;                              //设置dest的初值为nullptr
	//调用my_memcpy()函数，首参数为nullptr
	my_memcpy(dest, "Hello World!", 12);
	return 0;
}
