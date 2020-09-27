# 有很多的工具可以实现在gnome环境下发送弹窗，这里介绍三种:

# 1.zenity 会在桌面显示一个gtk＋风格的弹窗
# 2.notify-send 在系统托盘区显示消息（与pidgin和evolution的提醒一样）
# 3.xmessage 会在桌面显示一个 x windows 风格的弹窗(测试无效)



#1. 弹出对话框
#> zenity其实是GNOME项目为命令行程序以及Shell脚本程序提供的一套对话框交互工具，功能其实非常非常的强大

zenity --info --text "要发送的消息"


#2. 弹出消息
#> -t指定过期时间。
#>  要求编码为 utf-8
notify-send ["标题"] "信息"


#2.2  当前用户提示
DISPLAY=:0 nohup notify-send "Hello" "World"


#3. xmessage
#> 
# -center       ----消息屏幕中间
# -nearmouse    ----消息在鼠标所在处
# -timeout secs  ---自动关闭，单位为秒
xmessage -center "messages.."