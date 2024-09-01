/*
程序员：Helen Shek
编程时间：2024.9.1
*/

/*
通讯录排序 
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，
按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式
给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，
“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。

输出格式:
按照年龄从大到小输出朋友的信息，格式同输出。
*/

#include <stdio.h> 
#include <string.h>

struct Contact{
	char name[20];
	int birthday;
	char number[50];
};
 
int main  ()
{
	int n;
	scanf ("%d",&n);
	struct Contact friends[n];
	int i,j;
	for (i = 0;i < n;i++){
		scanf ("%s %d %s", friends[i].name, &friends[i].birthday, friends[i].number);	
	}
	
	struct Contact temp,*p,*q,*m[n];  
	//使用指针对结构体变量的顺序进行交换，数组m用于存放地址 
	for (i = 0;i < n;i++)  //冒泡排序 
	{
		for (j = i;j < n;j++)
		{
			p = &friends[i];  //指针变量p、q分别指向结构体变量friends[i]、friends[j] 
			q = &friends[j];
			if (friends[i].birthday > friends[j].birthday )  //friends[j]年龄更大 
			{  //将指针变量所指的的结构体变量进行互换 
				temp = *p;
				*p = *q;
				*q = temp;
			}
		}
		m[i] = p;  //每一次冒泡排序结束后都把年龄最大的朋友所在的结构体变量的地址存入数组m中 
	}  //即m[0]存放的是年龄最大的朋友的信息，m[1]存放的是第二大的朋友的信息 
	
	for (i = 0;i < n;i++)
	{  //按顺序输出数组m中存放的指针所对应的结构体变量的内容 
		printf ("%s ", m[i]->name);
		printf ("%d ", m[i]->birthday);
		if (i != n-1)
		{
			printf ("%s\n", m[i]->number); 
		}
		else printf ("%s", m[i]->number);  //末尾的字符串不需要换行
	}
	return 0;
}
