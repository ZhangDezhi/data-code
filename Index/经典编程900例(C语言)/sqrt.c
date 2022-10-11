 #include <stdio.h>
int main (void){
	float a;
	float x;//为所求结果
	int i =100;//控制循环次数
	printf("请输入要开方的数:");
	scanf("%f",&a);
	x = a/2;
	while(i--){
		x = (x+a/x)/2;
	}
	printf("开放结果为:%f \n",x);

	return 0;
}
