
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
CopyString "脚本之家 www.jb51.net" 
msgbox "ok"