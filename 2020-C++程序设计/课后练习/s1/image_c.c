/*
File:		image_c.c
Purpose:	һ��C���Զ���ͼ�����Ե�ʾ��
*/

/* ��ֹVS��C���Ժ�������ȫ���浼������ʧ�ܣ����������ǰ�� */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#pragma pack(2)	/* �ֽڶ���ָ���ʹ�ýṹ���ȡ�ļ�ʱ������ */

/* �����������͵ı���*/
typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef long LONG;

int main()
{
	/* ���BMPͼƬ��ؽṹ������
	��������
	��ع˽ṹ��ʹ�÷������ο�ʵ��ָ�������в��� */
	
	int width;				/* ͼ��Ŀ� */
	int height;				/* ͼ��ĸ� */
	unsigned int n_pixels;	/* ͼ���������� */

	/* Ҫ���ʵ�ԭʼͼ�� */
	char bmp_image[] = "d:\\bjfu_gray.bmp";
	printf("�����ļ�Ϊ��%s\n", bmp_image);

	/* ��ͼ���ļ� */
	FILE *fp = fopen(bmp_image, "rb");
	if (fp == 0)	/*����ʧ��*/
	{
		printf("�ļ� %s ��ʧ��\n", bmp_image);
		return -1;
	}

	/* ��ȡ�ļ�ͷ��BITMAPFILEHEADER�ṹ���� */
	/* ���磺fread(&bmfh, sizeof(BITMAPFILEHEADER), 1, fp); */

	/* ��ȡ��Ϣͷ��BITMAPINFOHEADER�ṹ���� */
	/* ���磺fread(&bmih, sizeof(BITMAPINFOHEADER), 1, fp); */
	
	/* ��ȡ��ϣ��ر�ԭʼ�ļ� */
	fclose(fp);

	/* ����Ϣͷ�ṹ���ȡͼ�������Ϣ��ͼ����ߡ�ÿ������ռλ������Ϣ */
	width = bmih.biWidth;
	height = bmih.biHeight;
	n_pixels = width * height;

	/* ��Ļ���������Ϣ*/
	/* printf... */
	
	/* ������������0 */
	return 0;
}