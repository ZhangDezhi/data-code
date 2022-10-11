#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-10-22 13:33
# Last Modified  : 2021-10-22 13:34:41
# This is a Script.
#------------------------------------------

#删除某行
sed '1d' test             #删除第一行 
sed '$d' test             #删除最后一行
sed '1,2d' test           #删除第一行到第二行
sed '2,$d' test           #删除第二行到最后一行
sed -i '/ruby/d' test     #在原文件中删除ruby所在的行


#显示某行
sed -n '1p' test          #显示第一行 
sed -n '$p' test          #显示最后一行
sed -n '1,2p'test         #显示第一行到第二行
sed -n '2,$p'test         #显示第二行到最后一行
sed -n '/ruby/d' test     #显示删除ruby所在行后的内容

#使用模式进行查询
sed -n '/ruby/p' test1    #查询包括关键字ruby所在所有行
sed -n '/\$/p' test1      #查询包括关键字$所在所有行，使用反斜线\屏蔽特殊含义

#增加一行或多行字符串
sed '1a drink tea' test1              #第一行后增加字符串"drink tea"
sed '1,3a drink tea' test1            #第一行到第三行后增加字符串"drink tea"
sed '1a drink tea\nor coffee' test1   #第一行后增加多行，使用换行符\n


#代替一行或多行
sed '1c Hi' test1           #第一行代替为Hi
sed '1,2c Hi' test1         #第一行到第二行代替为Hi


#替换一行中的某部分
#格式：sed 's/要替换的字符串/新的字符串/g'（要替换的字符串可以用正则表达式）
sed 's/ruby/bird/g'    #替换ruby为bird
sed 's/ruby//g'  test1 #替换ruby为空

#插入
sed -i '$a bye' test1     #在文件test1中最后一行直接输入"bye"
sed -i '1i\aaa' test1     #在文件test1中第一行前插入一行"aaa"


sed -i '1i添加的内容' filename # 在第一行前添加字符串 
sed -i '$i添加的内容' filename # 在最后一行行前添加字符串 
sed -i '$a添加的内容' filename # 在最后一行行后添加字符串
