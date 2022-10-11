print ("His name is %s"%("Aviad")) #打印字符串
print ("He is %d years old"%(25)) #打印整数
print ("His height is %f m"%(1.83))
print ("His height is %.2f m"%(1.83))
print ("Name:%10s Age:%8d Height:%8.2f"%("Aviad",25,1.83))
print ("Name:%-10s Age:%-8d Height:%-8.2f"%("Aviad",25,1.83))

#  格式符为真实值预留位置，并控制显示的格式。格式符可以包含有一个类型码，用以控制显示的类型，如下:

# %s    字符串 (采用str()的显示)
# %r    字符串 (采用repr()的显示)
# %c    单个字符
# %b    二进制整数
# %d    十进制整数
# %i    十进制整数
# %o   八进制整数
# %x    十六进制整数
# %e    指数 (基底写为e)
# %E    指数 (基底写为E)
# %f    浮点数
# %F    浮点数，与上相同
# %g    指数(e)或浮点数 (根据显示长度)
# %G    指数(E)或浮点数 (根据显示长度)
# # %%    字符"%"