#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-08 09:10
# Last Modified  : 2021-06-08 09:11:14
# This is a Script.
#------------------------------------------
# 参考: https://www.cnblogs.com/ElegantSmile/p/11144879.html

echo -e "\e[1;33;41m test content \e[0m"


#1. \e 转义起始符，定义一个转义序列， 可以使用 \033代替
#2. [ 表示开始定义颜色
#3. 1表示高亮，33表示字体颜色为黄色，45表示背景色为红色
#4. “test content” 属于文字内容
#5. m 转义终止符，表示颜色定义完毕
#6. 再次使用 \e[ ，表示再次开启颜色定义，0表示使用默认的颜色，m表示颜色定义结束，所以 \e[0m 的作用是恢复之前的配色方案



#一、字体颜色
#字体颜色：30——37
#默认=0，黑色=30，红色=31，绿色=32，黄色=33，蓝色=34，紫色=35，天蓝色=36，白色=3


echo -e "\e[30m test content黑 \e[0m"
echo -e "\e[31m test content红 \e[0m"
echo -e "\e[32m test content绿 \e[0m"
echo -e "\e[33m test content黄 \e[0m"
echo -e "\e[34m test content蓝 \e[0m"
echo -e "\e[35m test content紫 \e[0m"
echo -e "\e[36m test content天蓝 \e[0m"
echo -e "\e[37m test content白 \e[0m"


#二、字背景颜色
#字背景颜色：40——47
#默认=0，黑色=40，红色=41，绿色=42，黄色=43，蓝色=44，紫色=45，天蓝色=46，白色=47



echo -e "\e[40m test content黑 \e[0m"
echo -e "\e[41m test content红 \e[0m"
echo -e "\e[42m test content绿 \e[0m"
echo -e "\e[43m test content黄 \e[0m"
echo -e "\e[44m test content蓝 \e[0m"
echo -e "\e[45m test content紫 \e[0m"
echo -e "\e[46m test content天蓝 \e[0m"
echo -e "\e[47m test content白 \e[0m"



#三、黑底彩色
#黑底彩色：90——97
#黑=90 深红=91 绿=92 黄色=93 蓝色=94 紫色=95 深绿=96 白色=97

echo -e "\e[90m test content黑 \e[0m"
echo -e "\e[91m test content红 \e[0m"
echo -e "\e[92m test content绿 \e[0m"
echo -e "\e[93m test content黄 \e[0m"
echo -e "\e[94m test content蓝 \e[0m"
echo -e "\e[95m test content紫 \e[0m"
echo -e "\e[96m test content天蓝 \e[0m"
echo -e "\e[97m test content白 \e[0m"



四、字体控制选项:
\033[0m 关闭所有属性
\033[1m  设置高亮度
\033[4m  下划线
\033[5m  闪烁
\033[7m  反显，撞色显示，显示为白色黑底，或者显示为黑底白字
\033[8m  消影，字符颜色将会与背景颜色相同
\033[nA 光标上移n行
\033[nB 光标下移n行
\033[nC 光标右移n行
\033[nD 光标左移n行
\033[y;xH 设置光标位置
\033[2J 清屏
\033[K 清除从光标到行尾的内容
\033[s 保存光标位置
\033[u 恢复光标位置
\033[?25l 隐藏光标
\033[?25h 显示光标



















