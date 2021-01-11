/*
File:		image_c.c
Purpose:	一个C语言读简单图像属性的示例
*/

/* 防止VS报C语言函数不安全警告导致链接失败，必须放在最前面 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#pragma pack(2)	/* 字节对齐指令，在使用结构体读取文件时起作用 */

/* 基本数据类型的别名*/
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef long LONG;

int main()
{
	/* 添加BMP图片相关结构体声明
	…………
	请回顾结构体使用方法，参考实验指导书自行补充 */
	
	int width;				/* 图像的宽 */
	int height;				/* 图像的高 */
	unsigned int n_pixels;	/* 图像总像素数 */

	/* 要访问的原始图像 */
	char bmp_image[] = "d:\\bjfu_gray.bmp";
	printf("读入文件为：%s\n", bmp_image);

	/* 打开图像文件 */
	FILE *fp = fopen(bmp_image, "rb");
	if (fp == 0)	/*若打开失败*/
	{
		printf("文件 %s 打开失败\n", bmp_image);
		return -1;
	}

	/* 读取文件头到BITMAPFILEHEADER结构体中 */
	/* 例如：fread(&bmfh, sizeof(BITMAPFILEHEADER), 1, fp); */

	/* 读取信息头到BITMAPINFOHEADER结构体中 */
	/* 例如：fread(&bmih, sizeof(BITMAPINFOHEADER), 1, fp); */
	
	/* 读取完毕，关闭原始文件 */
	fclose(fp);

	/* 从信息头结构体获取图像基本信息：图像宽、高、每像素所占位数等信息 */
	width = bmih.biWidth;
	height = bmih.biHeight;
	n_pixels = width * height;

	/* 屏幕输出所需信息*/
	/* printf... */
	
	/* 正常结束返回0 */
	return 0;
}