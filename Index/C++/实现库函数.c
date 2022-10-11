//实现库函数
#include<stdio.h>
#include<string.h>
void Strcpy(char str1[],char str2[])
{
		int i = 0;
		do
		{
				str1[i] = str2[i];//将str2的内容赋值给str1
				i++;
		}while(str2[i]!='\0');
		str1[i] = '\0';//为字符串为加终结符'\0'
}

int  Strcmp(char str1[],char str2[])
{
	int len1,len2;
	len1=strlen(str1);//str1长度
	len2=strlen(str2);//str2长度
	if(len1!=len2)
	{
			if(len1>len2)//如果str1比str2长，返回正数1
					return 1;
			else//否则，返回－1
					return -1;
	}
	else
	{
			int i,j=0,m=0,n=0;
			for(i=0;i<len1;i++)
			{
					if(str1[i]==str2[i])
							j++;
					else
					{
							m += str1[i];
							n += str2[i];
					}
			}
			if(j==len1)//||m==n)//如果str1全部字符和str2一样，返回0
					return 0;
			else if(m>n)//如果str1大于str2，返回1
					return 1;
			else //否则，返回－1
					return -1;

	}




}
void Strcat(char str1[20],char  str2[20])
{
	int len1,len2;
	len1=strlen(str1);//数组长度len1
	len2=strlen(str2);//sizeof(str2)/sizeof(str2[0])这个公式求得是容量，而且在这个函数中只是求出指针的长度，为4
	int i;
	for(i=0;i<len2;i++)
			str1[i+len1] = str2[i];//将str2的内放到str1的后面
	str1[len1+len2] = '\0';
}



int main()
{
		char str1[20];
		char str2[20];
		printf("输入str1：");
		scanf("%s",str1);
		scanf("%*[^\n]");
		scanf("%*c");
		printf("输入str2：");
		scanf("%s",str2);
		scanf("%*[^\n]");
		scanf("%*c");
		printf("比较%d\n",Strcmp(str1,str2));
		Strcat(str1,str2);
		printf("将str2粘贴到str1后tr1=%s\n",str1);
		printf("比较%d\n",Strcmp(str1,str2));
		Strcpy(str1,str2);
		printf("将str2拷贝到str1后，str1=%s\n",str1);
		printf("比较%d\n",Strcmp(str1,str2));
		
		return 0;
}
