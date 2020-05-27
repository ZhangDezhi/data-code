#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void*pv1,const void*pv2)
{
		return 	*(const int*)pv1 - *(const int*)pv2;
}

int comptr(const void*pv1,const void *pv2)
{
		const char*ps1 = *(char**)pv1;
		const char*ps2 = *(char**)pv2;
		return strcmp(ps1,ps2);
}

int main()
{
		int data[] = {78,23,19,99,65,47,2,38};
		size_t size = sizeof(data[0]);
		size_t numb = sizeof(data)/size;
		qsort(data,numb,size,compare);//从小大大排序
		size_t i;
		for(i = 0;i<numb;i++)
				printf("%d ",data[i]);
		printf("\n");
		char*cities[] = {"chongqing","guangzhou","wuhan","nanjing","jinan","tianjin"};
		size = sizeof(cities[0]);
		numb = sizeof(cities)/size;
		qsort(cities,numb,size,comptr);
		for(i = 0;i<numb;i++)
				printf("%s ",cities[i]);
				printf("\n");
		return 0;
}
