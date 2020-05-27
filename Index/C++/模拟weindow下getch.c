//模拟windows下的getch（）
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<sys/ioctl.h>
int getch()
{
		struct termios old;
		ioctl(STDIN_FILENO,TCGETS,&old);
		struct termios new = old;
		new.c_lflag &= ~(ECHO|ICANON);
		ioctl(STDIN_FILENO,TCSETS,&new);
		int c = getchar();
		ioctl(STDIN_FILENO,TCSETS,&old);
		return c;


}


int main()
{
		for(;;){
	//	int c = getchar();
		int c  = getch();
		printf("<%02X,%c>\n",c,c);
}
		return 0;
}
