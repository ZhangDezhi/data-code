'剪切板操作
Sub CopyString(s) 
	Set forms=WScript.CreateObject("forms.form.1") 
	Set textbox=forms.Controls.Add("forms.textbox.1").Object 
	With textbox 
		.multiline=True 
		.text=s 
		.selstart=0 
		.sellength=Len(.text) 
		.copy 
	End With 
End Sub 

'設定郵件程序名稱、用戶名、密碼"
Dim Program1,a,b 
Program = "C:\Program Files\Super Notes\SuperNotes.exe" 
Set WshShell=CreateObject("WScript.Shell") 
'運行主程序"
'Set oExec=WshShell.Exec(Program) 
WScript.Sleep 2000 
'激活窗口,并置頂,有兩種說法.
'1:前面加1
'2:後面加2
'最後發現1.有效果
'1
'WshShell.SendKeys "%{ESC}"
'WshShell.AppActivate "登錄"
'2
'WshShell.sendkeys "{enter}"
'
'wshShell.SendKeys "+{TAB}" 
'CopyString "idpbg-mlb-sw-auto@mail.foxconn.com"  '修改引號內為自己郵箱
'WshShell.SendKeys "^v" 
'WScript.Sleep 1000 
'WshShell.SendKeys "{TAB}" 
'發現密碼不能用Ctrl+V粘貼操作.必須用輸入
'b="Asdfg123.."   '修改引號內為自己密碼
'WshShell.SendKeys b 
'WScript.Sleep 200 
'WshShell.SendKeys "{ENTER}"
do 
	WScript.Sleep 30000
	WshShellv.SendKeys "^" 
loop
