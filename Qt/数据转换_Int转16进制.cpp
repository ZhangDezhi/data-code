    void Int-To-Hex( uint32_t integer )
    {
        uint8_t c;
        int     i, j, digit;
     
        for ( i = 7, j = 0; i >= 0; i--, j++ )
        {
            digit = (integer >> (i * 4)) & 0xf;
            if (digit < 10)
            {
                c = digit + 0x30;
            }
            else
            {
                c = digit + 0x37;
            }
        }
     
    //ASSIC码'0x30'是数字0，'0x37'是数字7，加上10之后是字母'A'。


-----------------------------------------------------
    //int 16禁止转换
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <iomanip>
    using namespace std;
     
    string dec2hex(int i) //将int转成16进制字符串
    {
    	stringstream ioss; //定义字符串流
    	string s_temp; //存放转化后字符
    	ioss << setiosflags(ios::uppercase) << hex << i; //以十六制(大写)形式输出
    	//ioss << resetiosflags(ios::uppercase) << hex << i; //以十六制(小写)形式输出//取消大写的设置
    	ioss >> s_temp;
    	return s_temp;
    }
     
    int main()
    {
    	int a = 2013;
    	cout << "a = 0x" << dec2hex(a) << endl;
    }
---------------------------------------------------------


    // 0x是CPP语法定义的16进制数标识，int型变量在内存中是4个字节32位的二进制数，所以无论是十进制还是十六进制，都只是int型变量的表现方式，所以楼主提到的“在C++中如何将一个10进制的int型数据转换成带0x标识负符的16进制int型数据”这个题设是错误的。楼主的问题应该改为“如何将int型变量转换为带0x标识符的16进制字符串”，其中十进制数和十六进制数都是字符串（因为你根本看不到内存中的二进制数，想要把一个int型数显示到显示器上就必须先把它转换成字符串）。如此，再来分析如何将int型变量转换为带0x标识符的16进制字符串：
                string intToHex(int n)
                {
                        string hex="0x";
                        hex += hexUnit((n & 0xF0000000)>>28);
                        hex += hexUnit((n & 0x0F000000)>>24);
                        hex += hexUnit((n & 0x00F00000)>>20);
                        hex += hexUnit((n & 0x000F0000)>>16);
                        hex += hexUnit((n & 0x0000F000)>>12);
                        hex += hexUnit((n & 0x00000F00)>>8);
                        hex += hexUnit((n & 0x000000F0)>>4);
                        hex += hexUnit((n & 0x0000000F));
     
                        return hex;
                }
                char hexUnit(unsigned char unit)
                {
                        if(0<=unit && unit<=9)
                                return unit + '0';
                        else if(10<=unit && unit <=15)
                                return unit-10 + 'A';
     
                        return '0';
                }





