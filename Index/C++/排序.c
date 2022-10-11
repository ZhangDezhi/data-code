#include<stdio.h>

void leep(int a[],int len)
{
		int i,j,k;
		for(i=0;i<len;i++)
			for(j=i+1;j<len;j++)
				if(a[i]<a[j])
				{
						k = a[i];
						a[i] = a[j];
						a[j] = k;
				}
				printf("排序后的数组为：");
		for(i=0;i<len;i++)
				printf("%d\t",a[i]);
		printf("\n");
}
int cop(int a[],int len)
{
		int i = 0,k = a[len-1];
		//for(i=1;i<len;i++)
		do
		{
			if(a[i]==a[i+1])
				{
					int j;
					for(j=i;j<len;j++)
					a[j] = a[j+1];

				}
			 else
					 i++;
		}while(a[i]!=k);
	printf("压缩后还有%d个数\n",i+1);		
}

int main()
{
		int len,i;
		printf("输入长度:");
		scanf("%d",&len);
		int arr[len];
		printf("输入元素:");		
		for(i=0;i<len;i++)
			scanf("%d",&arr[i]);
		leep(arr,len);
		cop(arr,len);
		printf("你要排大小第几的数字？\n");
		int l;
		scanf("%d",&l);
		printf("第%d大的数字为%d!\n",l,arr[l-1]);
		return 0;
}
