//指针运算
#include<stdio.h>
int main()
{
		int *p = NULL;
/*		printf("p = %p\t%d\n",p,p);//p = (nil)	p = 0
		printf("%d\n",p+1);//结果为4，移动一个int的字节
		p++;
		printf("%d\n",p);//4
		p -= 1;
		printf("%d\n",p);//0
*/

		int arr[5]={10,20,30,40,50};
		int *p1 = &arr[0];
		int *p2 = &arr[1];
		if(p1<p2)
				printf("arr[0]地址低于arr[1]的地址\n");
		printf("p1=%p,p2=%p\n",p1,p2);
		printf("p1 = %p,p2 = %p,p2 - p1 = %p\n",p1,p2,p2-p1);//结果为1
//		p1 + p2;//错误指针不能相加
		printf("%d\n",*p1++);//*p1++ 10;++*p1 11;*++p  20
		printf("%d\n",p);//20
		printf("%d\n",(*p1)++);//20
		printf("%d,%d\n",arr[0],arr[1]);//10,21
		return 0;
}										

