import tkinter
import time
import pyautogui
import webbrowser
import xlrd
 
class APP:
    def __init__(self,master):
        frame = tkinter.Frame(master,height=300,bd=2,width=245)
        frame.pack()
 
        self.button1 = tkinter.Button(frame,text="stop",fg="red",command=frame.quit,height=2,bd=2,width=8)
        self.button1.place(x=25,y=50)
 
        self.button2 = tkinter.Button(frame,text="start",fg="green",command=self.ScanBlog,height=2,bd=2,width=8)
        self.button2.place(x=95,y=50)
 
        self.label1 = tkinter.Label(frame,text="please enter refresh excel:",bg="yellow",height=2,bd=2,width=24)
        self.label1.place(x=25,y=120)
            
        self.label2 = tkinter.Label(frame,text="please enter refresh times:",bg="green",height=2,bd=2,width=24)
        self.label2.place(x=25,y=210)
 
        self.label3 = tkinter.Label(frame,text="Refresh Web Pages",height=3,bd=3,width=24)
        self.label3.place(x=25,y=0)
 
        self.entry1 = tkinter.Entry(frame,width=20,bd=2)
        self.entry1.place(x=25,y=170)
 
        self.entry2 = tkinter.Entry(frame,width=20,bd=2)
        self.entry2.place(x=25,y=260)
        
    def ScanBlog(self):
        file_name = self.entry1.get()
        distance = int(self.entry2.get())
        sleep_t = 1
        sheet_name = 'url'
 
        excel_file = xlrd.open_workbook(file_name)
        sheet1 = excel_file.sheet_by_name(sheet_name)
 
        while distance > 0:
            for i in range(0,49,1):
                row_value = sheet1.cell(i,1).value
                webbrowser.open(row_value)
                time.sleep(sleep_t)
                pyautogui.hotkey('ctrl','w')
            distance = distance - 1
 
root = tkinter.Tk()
app = APP(root)
root.mainloop()
root.destroy()