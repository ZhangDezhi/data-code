#include<stdio.h>
//#include"conio.h"
#include<string.h>
struct user{
		char name[20];
		char passwd[20];
}User={"0","0"};
char putin()
{
		FILE*fp = fopen("massage.txt","a+");
		if(!fp)
		{
				perror("fopen");
				return -1;
		}
loop:	printf("name:\n");
		scanf("%s",&User.name);
	//	scanf("%*[^\n]");
	//	scanf("%*c");
		char read[20]={0};
		//while(fgets(read,strlen(User.name),fp)!=NULL)
		//while(fscanf(fp,"%s",read)!=0)
		while(fread(read,sizeof(User.name),1,fp))
		{								
		//	printf("%s",read);
			if(strcmp(read,User.name)!=0)
			{
					fseek(fp,sizeof(User.passwd),SEEK_CUR);
			//		printf("已运行!\n");
				//	fread(read,sizeof(User.name),1,fp);
				//	printf("%s\n",read);
			}
			
			
			else
				{	
					printf("已存在，请重新输入:\n");
					rewind(fp);
					goto loop;
				}
		}
		fwrite(User.name,sizeof(User.name),1,fp);
		//fprintf(fp,"\n");
		printf("passwd:\n");
		scanf("%s",User.passwd);
		fwrite(User.passwd,sizeof(User.passwd),1,fp);
		//fprintf(fp,"\n");
		printf("注册成功！\n");
		fclose(fp);
		return 	main();
}

char load()
{
		int i = 0;
		FILE*fp = fopen("massage.txt","r");
		if(!fp)
		{
				perror("fopen");
				return -1;
		}
		rewind(fp);
		char read[20],pwd[20];//读出的用户名和密码
loop1:	printf("load name:\n");
		scanf("%s",User.name);
		printf("passwd:\n");
	/*	
		for(i=0;i<6;i++)
		{
				pwd[i]=getch();
				printf("*");
		}
		*/
		scanf("%s",User.passwd);
		while(fread(read,sizeof(User.name),1,fp)&&fread(pwd,sizeof(User.passwd),1,fp))
		{
			//	printf("%s,%s",read,pwd);
				while(strcmp(read,User.name)!=0||strcmp(pwd,User.passwd)!=0)
				{
						fread(read,sizeof(User.name),1,fp);
					if(	!fread(pwd,sizeof(User.passwd),1,fp))
							break;
					//	printf("%s",read);
					//	printf("%s",pwd);
				};
				if(strcmp(read,User.name)==0&&strcmp(pwd,User.passwd)==0)
				{
						printf("登录成功！");
						return main();
				}
				else
				
				{
						printf("用户名或密码错误，请重新输入：\n");
						i++;
						rewind(fp);
						goto loop1;
						if(i>3)
						{
								printf("输入次数已超过3次，不能继续输入！\n");
								return main();
						}
				}
				
		}

		fclose(fp);
		return main();

}
int main()
{
		printf("-----------------\n");
		printf("    学生信息     \n");
		printf(" 1.登录          \n");
		printf(" 2.注册          \n");
		printf(" 3.退出          \n");
		printf("-----------------\n");
		printf("您需要的操作：?\n");
		int choice;
loop:	scanf("%d",&choice);
		if(choice<1||choice >3)
		{
				printf("没有那个选项，请重新输入：");
				goto loop;
		}
		switch (choice)
		{
				case 1:load();break;

				case 2:putin();break;

				case 3:return 0;

				default:break;
		}
		return 0;
}
