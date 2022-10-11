
#define _LANGBEGIN  
#define _LANGEND  




char * net_information::get_err_type(int n)
{
	char *err_type[] =	{	_LANGBEGIN"不在网上"_LANGEND,
							_LANGBEGIN"本机停机"_LANGEND,			//1
							_LANGBEGIN"本机无权"_LANGEND,
							_LANGBEGIN"发送出错"_LANGEND,			//3
							_LANGBEGIN"接收出错"_LANGEND,
							_LANGBEGIN"内存出错"_LANGEND,			//5
							_LANGBEGIN"连接失败"_LANGEND,
							_LANGBEGIN"通信处理机停机"_LANGEND,	//7
							_LANGBEGIN"服务器停机"_LANGEND,		//9
							NULL
						};
	n = abs(n);
	int nn = sizeof(err_type)/sizeof(char *);
	if((n>nn)||(n<=0)) return _LANGTR("未知错误类型");
	return _LANGTR(err_type[n-1]);
}
