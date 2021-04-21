#!/bin/sh

get_str()
{
	return "string"
}

get_str
echo $?

# ./test.sh: line 5: return: string: numeric argument required 255
#可以看到已经提示要求return 整数类型，真实返回值是255。


#解决办法：



#!/bin/sh

get_str()
{
	echo "string"
}

echo `get_str` #写法一
echo $(get_str) #写法二



return  返回的是状态码，函数结束 return不返回函数返回值 可以在前面用 echo 返回函数返回值，return 返回指定函数退出状态码

echo  返回的是函数返回值，函数退出状态码是函数最后一条命令的退出状态码 