#include<stdio.h>

int add(int a,int b){
		return a+b;
}

int sub(int a,int b){
		return a-b;
}

int mul(int a,int b){
		return a*b;
}

int div(int a,int b){
		return a/b;
}

int mod(int a,int b){
		return a%b;
}

int cal(int a,int b,int (*pfunc) (int ,int)){
		return pfunc(a,b);
}//一个cal函数可以计算＋，－，＊，／，％
int main()
{
		int (*pfunc) (int ,int ) = add;
		printf("%d\n",pfunc(10,20));
		pfunc  = sub;
		printf("%d\n",pfunc(20,10));
		
		printf("%d\n",cal(100,30,add));
		printf("%d\n",cal(100,30,sub));
		printf("%d\n",cal(100,30,mul));
		printf("%d\n",cal(100,30,div));
		printf("%d\n",cal(100,30,mod));

		return 0;
}
