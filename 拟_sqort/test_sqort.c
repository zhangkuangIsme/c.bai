#include<stdio.h>
#include<string.h>
struct str
{
	char name[30];
	int age;
} stu[3] = {{"zhangsan",18},{"lisi",20},{"wangwu",22}};
int cmpt_name(const void* e1, const void* e2)
{
	return strcmp(((struct str*)e1)->name , ((struct str*)e2)->name);
}
int cmpt_age(const void* e1, const void* e2)
{
	return ((struct str*)e1)->age - ((struct str*)e2)->age;
}
int cmpt(const void* e1, const void* e2)
{
	if (*(int*)e1 - *(int*)e2 > 0)
		return 1;
	else
		return 0;
	
}
void jh(char* buff1,char* buff2 ,int width)
{
	int i = 0;
	for (i = 0;i < width;i++)
	{
		char tmp = *buff1;
		*buff1 = *buff2;
		*buff2 = tmp;
		buff1++;
		buff2++;
	}
}
void my_sqort(void* base, int sz, int width,int cmpt(const void* e1, const void* e2))
{
	int i = 0, j = 0;
	for (i = 0;i < sz - 1;i++)
	{
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmpt((char*)base + j * width, (char*)base + (j + 1) * width  ) > 0)
			{
				jh((char*)base + width * j, (char*)base + width * (j + 1), width);
			}
		}
	}
}
void test1()
{
	int arr[3] = {3,1,5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	for (int i = 0;i < sz;i++)
	{
		printf("%d ",arr[i]);
	}
}
void test2()
{
	struct str stu[3] = { {"zhangsan",18},{"lisi",20},{"wangwu",22} };
	int sz = sizeof(stu) / sizeof(stu[0]);
	my_sqort(stu, sz, sizeof(stu[0]), cmpt_age);
	for (int i = 0;i < sz;i++)
	{
		printf("%s %d",stu[i].name,stu[i].age);
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}