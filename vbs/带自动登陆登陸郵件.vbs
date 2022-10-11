
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
Set oExec=WshShell.Exec(Program) 
WScript.Sleep 1000 
'激活窗口,并置頂,有兩種說法.
'1:前面加1
'2:後面加2
'最後發現2.有效果
'1
WshShell.SendKeys "%{ESC}"
WshShell.AppActivate "登錄"
'2
'WshShell.sendkeys "{enter}"
'
'wshShell.SendKeys "+{TAB}" 
CopyString "idpbg-mlb-sw-auto@mail.foxconn.com"  '修改引號內為自己郵箱
WshShell.SendKeys "^v" 
WScript.Sleep 1000 
WshShell.SendKeys "{TAB}" 
'發現密碼不能用Ctrl+V粘貼操作.必須用輸入
b="Asdfg123.."   '修改引號內為自己密碼
WshShell.SendKeys b 
WScript.Sleep 200 
WshShell.SendKeys "{ENTER}"

'將該腳本設定為自動啟動.也就是拷貝到啟動項中
set fso = createobject("scripting.filesystemobject")  
set ws = createobject("wscript.shell")   
pt = ws.specialfolders("startup") & "\"   
set file = fso.getfile(wscript.scriptfullname)   
file.copy pt

'將該腳本取消自動啟動,也就是刪除啟動項中文件
'取消直接在 ?始》程序》?? 里面?除就行了
'Dim fso, fl
'Set fso = CreateObject("Scripting.FileSystemObject")
'Set tf = fso.GetFile("C:\Documents and Settings\Administrator\「?始」菜?\程序\??\文件名")
'tf.Delete 
