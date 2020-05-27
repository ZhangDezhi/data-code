#include<stdio.h>
int main()
{
		int i;
		float a[5],tmp;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个学生的成绩：",i+1);
				scanf("%f",&a[i]);
		}
		int j;
		for(i=0;i<5;i++)//冒泡法将大的数依次放在上面
				for(j=i+1;j<5;j++)
					{
						if(a[i]<a[j])
						{
								tmp=a[i];
								a[i]=a[j];
								a[j]=tmp;
						}
					}
		for(i=0;i<5;i++)
				printf("%.2f\n",a[i]);

		return 0;
}
