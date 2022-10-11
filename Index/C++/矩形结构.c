/*定义一个点结构和一个矩形结构
定义对这两种结构的读取和打印函数
判断矩形合法性的函数
判断点是否在矩形内的函数
*/
#include<stdio.h>
#include<stdbool.h>
typedef struct tag_point{
		int x;
		int y;
}POINT;//,*LPPOINT; //定义点结构
typedef const POINT*LPCPOINT;
typedef struct tag_rect{
		/*int left;
		int right;
		int up;
		int down;*/
		POINT lt;
		POINT rb;
		
}RECT,*LPRECT;//定义矩阵结构
typedef const RECT*LPCRECT;

POINT EnterPoint(void){
	printf("输入坐标(x,y)");
	POINT pt;
	scanf("%d%d",&pt.x,&pt.y);
	return pt;
}
RECT EnterRect (void){
	printf("请输入矩形坐标\n");
	RECT rc;
	scanf("%d%d%d%d",&rc.lt.x,&rc.lt.y,&rc.rb.x,&rc.rb.y);
	return rc;
	
}
void PrintPoint(LPCPOINT pt)
{
	printf("(%d,%d)\n",pt ->x,pt->y);

}

void PrintfRect (LPCRECT rc){
printf("(%d,%d,%d,%d)\n",rc->lt.x,rc->lt.y,rc->rb.x,rc->rb.y);
}

bool ValidRect(LPCRECT rc)
{
	return rc->lt.x<rc->rb.x&&rc->lt.y<rc->rb.y;
}
 
bool IN(LPCPOINT pt,LPCRECT rc){
return rc->lt.x<pt->x&&pt->x<rc->rb.x&&rc->lt.y<pt->y&&pt->y<rc->rb.y;

}


int main()
{
	POINT pt = EnterPoint();
	RECT rc = EnterRect();	
	if(!ValidRect(&rc))
	{
			printf("feifa\n");
			return -1;
	}
	if(IN(&pt,&rc))
			printf("nei\n");
	else 
			printf("wai\n");


		return 0;
}
