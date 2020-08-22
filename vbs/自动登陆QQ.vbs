'定义QQ程序路径、帐名、密码 
Dim Program1,a,b 
Program1= "C:\Program Files\Super Notes\SuperNotes.exe" 
Set WshShell=createobject("wscript.shell") 
'运行QQ主程序 
Set oExec=WshShell.Exec(Program1) 
WScript.Sleep 1000 
'激活QQ窗口 
WshShell.AppActivate "QQ2010" 
wshShell.SendKeys "+{TAB}" 
'输入帐号 
a="QQ帐号" 
WshShell.SendKeys a 
WScript.Sleep 200 
WshShell.SendKeys "{TAB}" 
'输入密码 
b="你的密码" 
WshShell.SendKeys b 
WScript.Sleep 200 
WshShell.SendKeys "{ENTER}" 