/*int a,b;int*pa=&a,*pb=&b;
构造函数，使pa指向b，pb指向a
*/
#include<stdio.h>
void change(int **pa,int**pb)
{
		int*c;
		c = *pa;
		*pa = *pb;
		*pb = c;
}


int main()
{
		int a = 10,b = 20;
		int *pa =&a,*pb = &b;
		printf("pa = %p,pb = %p\n",pa,pb);
		change(&pa,&pb);
		printf("交换后pa = %p,pb = %p\n",pa,pb);
		return 0;
}
