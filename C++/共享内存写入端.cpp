//
//   memwrite.cpp
//
// Created by ZhangDezhi on2021-07-02 15:10 
// Last Modified  : 2021-07-02 15:21:14
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
//共享内存写端代码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
#define BUFSZ 512
 
int main(int argc, char *argv[])
{
	int shmid;
	int ret;
	key_t key;
	char *shmadd;
	
	//创建key值
	key = ftok("../", 2015); 
	if(key == -1)
	{
		perror("ftok");
	}
	
	//创建共享内存
	shmid = shmget(key, BUFSZ, IPC_CREAT|0666);	
	if(shmid < 0) 
	{ 
		perror("shmget"); 
		exit(-1); 
	}
	
	//映射
	shmadd = (char*) shmat(shmid, NULL, 0);
	if(shmadd < 0)
	{
		perror("shmat");
		_exit(-1);
	}
	
	//拷贝数据至共享内存区
	printf("copy data to shared-memory\n");
	bzero(shmadd, BUFSZ); // 共享内存清空
	strcpy(shmadd, "how are you, mike\n");
	
	return 0;
}
