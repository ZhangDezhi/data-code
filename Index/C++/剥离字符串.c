//剥离字符串
#include<stdio.h>
#include<string.h>
void cut(char arr[])
{
	int len;
	len = strlen(arr);
	char b[20];
	char c[20];//int c[20];
	int i,j=0,k=0;
	for(i=0;i<len;i++)
	{
			if((arr[i]>=65&&arr[i]<=91)||arr[i]>=97&&arr[i]<=123)
			{															
				b[j]=arr[i];//是字母，则赋给b数组
				j++;
			}
			else if(arr[i]>=48&&arr[i]<=57)
			{
				c[k] = arr[i];//是数字，则赋给c数组
				k++;
			}
				
	}
			b[j]='\0';
			//c[k]=
			printf("%s\t",b);
			printf("%s\t",c);
			
	//		for(i=0;i<k;i++)
	//			printf("%d",c[i]);	
}


int main()
{
		char arr[20];
		printf("输入一个字符串：");
		fgets(arr,20,stdin);
		printf("得到字符串:%s",arr);	
		printf("拆分后为：");
		cut(arr);

		return 0;
}
