//
//   字符串笔记.cpp
//
// Created by ZhangDezhi on2020-08-20 15:09 
// Last Modified  : 2020-08-20 15:10:09
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
## 字符串比较

```cpp

#include <stdio.h>
#include <string.h>
 
int main ()
{
   char str1[15];
   char str2[15];
   int ret;
 
 
   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");
 
   ret = strcmp(str1, str2);
 
   if(ret < 0)
   {
      printf("str1 小于 str2");
   }
   else if(ret > 0) 
   {
      printf("str1 大于 str2");
   }
   else 
   {
      printf("str1 等于 str2");
   }
   
   return(0);
}
```j
