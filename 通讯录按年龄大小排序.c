/*
����Ա��ʯ��Դ
���ʱ�䣺2024.9.1
*/

/*
ͨѶ¼���� 
����n�����ѵ���Ϣ���������������ա��绰���룬����Ҫ���д����
��������Ӵ�С��˳���������ͨѶ¼����Ŀ��֤�����˵����վ�����ͬ��

�����ʽ:
�����һ�и���������n��<10�������n�У�ÿ�а��ա����� ���� �绰���롱�ĸ�ʽ
����һλ���ѵ���Ϣ�����С��������ǳ��Ȳ�����10��Ӣ����ĸ��ɵ��ַ�����
�����ա���yyyymmdd��ʽ�����ڣ����绰���롱�ǲ�����17λ�����ּ�+��-��ɵ��ַ�����

�����ʽ:
��������Ӵ�С������ѵ���Ϣ����ʽͬ�����
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
	//ʹ��ָ��Խṹ�������˳����н���������m���ڴ�ŵ�ַ 
	for (i = 0;i < n;i++)  //ð������ 
	{
		for (j = i;j < n;j++)
		{
			p = &friends[i];  //ָ�����p��q�ֱ�ָ��ṹ�����friends[i]��friends[j] 
			q = &friends[j];
			if (friends[i].birthday > friends[j].birthday )  //friends[j]������� 
			{  //��ָ�������ָ�ĵĽṹ��������л��� 
				temp = *p;
				*p = *q;
				*q = temp;
			}
		}
		m[i] = p;  //ÿһ��ð����������󶼰����������������ڵĽṹ������ĵ�ַ��������m�� 
	}  //��m[0]��ŵ��������������ѵ���Ϣ��m[1]��ŵ��ǵڶ�������ѵ���Ϣ 
	
	for (i = 0;i < n;i++)
	{  //��˳���������m�д�ŵ�ָ������Ӧ�Ľṹ����������� 
		printf ("%s ", m[i]->name);
		printf ("%d ", m[i]->birthday);
		if (i != n-1)
		{
			printf ("%s\n", m[i]->number); 
		}
		else printf ("%s", m[i]->number);  //ĩβ���ַ�������Ҫ����
	}
	return 0;
}
