'�Ť��O�ާ@
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

'�]�w�l��{�ǦW�١B�Τ�W�B�K�X"
Dim Program1,a,b 
Program = "C:\Program Files\Super Notes\SuperNotes.exe" 
Set WshShell=CreateObject("WScript.Shell") 
'�B��D�{��"
Set oExec=WshShell.Exec(Program) 
WScript.Sleep 1500 
'�E�����f,�}�m��,����ػ��k.
'1:�e���[1
'2:�᭱�[2
'�̫�o�{1.���ĪG
'1
WshShell.SendKeys "%{ESC}"
WshShell.AppActivate "�n��"
'2
'WshShell.sendkeys "{enter}"
'
'wshShell.SendKeys "+{TAB}" 
CopyString "idpbg-mlb-sw-auto@mail.foxconn.com"  '�ק�޸������ۤv�l�c
WshShell.SendKeys "^v" 
WScript.Sleep 1000 
WshShell.SendKeys "{TAB}" 
'�o�{�K�X�����Ctrl+V�߶K�ާ@.�����ο�J
b="Asdfg123.."   '�ק�޸������ۤv�K�X
WshShell.SendKeys b 
WScript.Sleep 200 
WshShell.SendKeys "{ENTER}"
