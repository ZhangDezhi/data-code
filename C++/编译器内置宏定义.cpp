
    #include <stdio.h> 
     
    int main()
    {
    	printf("%s\n",__FILE__);
    	printf("%d\n",__LINE__);
    	printf("%s\n",__DATE__);
    	printf("%s\n",__TIME__);
    	printf("%s\n",__FUNCTION__);
    }

    /*

__DATE__ ：表示当前日期的字符串，格式为month/day/year(月/日/年).
__TIME__ ：表示当前时间，格式为hour:minute:second(时:分:秒).
__FILE__：表示正在处理的当前文件名字符串
__LINE__ ：表示正在处理的当前行号
__FUNCTION__ ：表示正在处理的函数名
__STDC__：表示编译器是否遵循ANSI C标准，若果是，它就是个非零值 

*/