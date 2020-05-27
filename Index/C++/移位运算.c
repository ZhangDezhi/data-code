#include<stdio.h>
int main()
{
								int r;
								int x = 12345678;
							r = 	x>>24 & 0xFF;
								printf("%#X",r);
							r = 	x>>16 & 0xFF;
								printf("%X",r);
							r = x>>8 & 0xFF;
								printf("%X",r);
							r = x & 0xFF;
								printf("%X",r);






								return 0;
}
