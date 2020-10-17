
#!/usr/bin/env python
# -!- coding: utf-8 -!-

#***************************************************
# * Author         :  ZangDezhi
# * Email          :  winzdz@hotmail.com
# * Create Time    : 2020-10-09 16:38
# Last Modified  : 2020-10-09 16:41:05
# * FileName       : pythontesxt.py
#**************************************************
import tkinter
import sys
import re

top = tkinter.Tk()
top.geometry('400x170+350+150')
top.wm_title('综合实例')

def validateText():
    val = entry1.get()
    if re.findall('^[0-9a-zA-Z_]{1,}$',str(val)):
        return True
    else:
        label3['text'] = '用户名只能包含字母、数字、下划线'
        return False

def anw_button():
    if str.upper(entry1.get()) == "1" and str.upper(entry2.get()) =='123456':
        label3['text'] = '登陆成功'
    else:
        label3['text'] = '用户名或密码错误，请重新输入！'

label1 = tkinter.Label(top,text = '用户名:',font = ('宋体','18'))
label1.grid(row = 0,column = 0)
label2 = tkinter.Label(top,text = '密码:',font = ('宋体','18'))#集合为另一种形式的字典
label2 .grid(row = 1 ,column = 0)
v = tkinter.StringVar()
entry1 = tkinter.Entry(top,font = ('宋体','18'),textvariable = v,\
                        validate = 'focusout',validatecommand = validateText)

entry1.grid(row = 0,column = 1)
entry1.focus_force()
entry2 = tkinter.Entry(top,font = ('宋体','18'),show = '*')

entry2.grid(row = 1,column = 1)
button1 = tkinter.Button(top,text = '登陆',font = ('宋体','18'),\
                         command = anw_button)
button1.grid(row = 2,column = 0,padx = 50,pady = 10)
button2 = tkinter.Button(top,text = '退出', font = ('宋体','18'),\
                         command = sys.exit)

button2.grid(row = 2,column = 1,padx = 80,pady = 10)
label3 = tkinter.Label(top,text = '信息提示区',font = ('华文新魏','16'),\
                       relief = 'ridge',width = 30)
label3.grid(row = 3,column = 0,padx = 10,pady = 10,columnspan = 2,sticky = 's')
top.mainloop()