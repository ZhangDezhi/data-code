#include<stdio.h>
void  large_first(int a[],int len)
{
		int i,j,k = 0;
		for(i = 0;i<len;i++)
				for(j = i+1;j<len;j++)
						if(a[i]<a[j])
						{
								k = a[i];
								a[i] = a[j];
								a[j] = k;
						}
		printf("从大到小排序为:\n");
		for(i = 0;i<len;i++)
				printf("%d\t",a[i]);
		printf("\n");
	//oto loop1;
}

void min_first(int a[],int len)
{
		int i,j,k = 0;
		for(i=0;i<len;i++)
				for(j = i+1;j<len;j++)
						if(a[i]>a[j])
						{
								k = a[i];
								a[i] = a[j];
								a[j] = k;
						}
	 printf("从小到大排序为:\n");
	 for(i = 0;i<len;i++)
			 printf("%d\t",a[i]);
	printf("\n");
	//goto loop1;
}



int main()
{
		int len,i,j;
		printf("输入数组大小:");
		scanf("%d",&len);
		printf("输入数组元素：");
		int a[len];
		for(i = 0;i<len;i++)
			scanf("%d",&a[i]);
loop1:	printf("选择您需要的排序方式：\n1:从大到小\n2:从小到大\n3:退出\n");
loop:	scanf("%d",&j);
		switch(j)
		{
				case 1:large_first(a,len);goto loop1;break;
				case 2:min_first(a,len);goto loop1;break;
				case 3:return 0;
				default:printf("输入错误，请重新输入:");goto loop;
		}

		return 0;
}
