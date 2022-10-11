//c99

#define LOG(format, ...) fprintf(stdout, format, __VA_ARGS__)
//其中，...表示参数可变，__VA_ARGS__在预处理中为实际的参数集所替换


//gcc
#define LOG(format, args...) fprintf(stdout, format, args)



//"##"的作用是对token进行连接，在上例中，format、__VA_ARGS__、args即是token，
//如果token为空，那么不进行连接，所以允许省略可变参数(__VA_ARGS__和args)，对上述变参宏做如下修改
#define LOG(format, ...)     fprintf(stdout, format, ##__VA_ARGS__)
#define LOG(format, args...) fprintf(stdout, format, ##args)

//示例
#ifdef DEBUG
#define LOG(format, ...) fprintf(stdout, ">> "format"\n", ##__VA_ARGS__)
#else
#define LOG(format, ...)
#endif