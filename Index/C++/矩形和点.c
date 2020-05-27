#include<stdio.h>
#include<stdbool.h>

typedef struct tag_point {  //点结构，定义两个整形成员表示x，y坐标
		int x;
		int y;
}POINT;// * LPPOINT;
typedef const POINT*LPPOINT;//定义指针指向POINT

typedef struct tag_rect{	//矩形，左上角的点和右下角的点
		POINT lt;
		POINT rb;
}RECT;// *LPRECT;
typedef const RECT*LPRECT;	//指向成员RECT的指针

POINT EnterPoint(void)
{
		printf("输入点坐标:(x,y)\n");
		POINT pt;
		scanf("%d%d",&pt.x,&pt.y);
		return pt;
}

RECT EnterRect(void)
{
		printf("输入矩阵坐标:()()\n");
		RECT rt;
		scanf("%d%d%d%d",&rt.lt.x,&rt.lt.y,&rt.rb.x,&rt.rb.y);
		return rt;
}

void PrintPoint(LPPOINT pt)
{
	printf("(%d,%d)\n",pt->x,pt->y);
}

void PrintRect(LPRECT rt)
{
		printf("(%d,%d)-(%d,%d)\n",rt->lt.x,rt->lt.y,rt->rb.x,rt->rb.y);
}

bool VaRect(LPRECT rt)
{
		return rt->lt.x<rt->rb.x&&rt->lt.y<rt->rb.y;	//只有左上角的x，y坐标都小于右下角的x，y坐标，矩形合法

}

bool IsIn(LPPOINT pt,LPRECT rt)
{
		return pt->x>=rt->lt.x&&pt->y>=rt->lt.y&&pt->x<=rt->rb.x&&pt->y<=rt->rb.y;//点坐标在矩形内
}


int main()
{
		POINT pt = EnterPoint();
		RECT rt = EnterRect();
		PrintPoint(&pt);//取地址
		PrintRect(&rt);
		printf("%s\n",VaRect(&rt)?"是正规矩形！":"是非法矩形！");
		if(VaRect(&rt))
				printf("%s\n",IsIn(&pt,&rt)?"点在矩形内！":"点在矩形外！");
									
		return 0;
}
