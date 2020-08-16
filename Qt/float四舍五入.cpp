//float 四舍五入
//方法一
QString::asprintf("%.2f", 123.12545)  = “123.13”//格式化，自动四舍五入
//方法二
float value = 1.237;  
int ret = (int)(value + 0.5f);//加 0.5 向下取整