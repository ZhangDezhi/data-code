#include <QtCore/QTextStream>

#include <QtCore/QFile>
#include <QtCore/QIODevice>

QString sFilePath = "C:\\test.txt";
 
QFile file(sFilePath);
//方式：Append为追加，WriteOnly，ReadOnly
if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {  
	QMessageBox::critical(NULL, "提示", "无法创建文件");
	return -1;  
}  
QTextStream out(&file);  
out<<"要写入内容"<<endl;  
out.flush();  
file.close();   //注意写入方式的选择，注意写完后的关闭操作！



//方法二

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	QFile file("test.txt");
	//---参数：QFile::Truncate表示的是 将原文件内容清空，
	//--以WriteOnly方式打开文件，如果在工程文件下没有该txt文件，那么程序将创建该文件，若存在，则将原文件内容清空，
	if (file.open(QFile::WriteOnly | QFile :: Truncate))		
	{
		//---创建 QTextStream流操作对象， 使与QFile对象file绑定。
		QTextStream out(&file); 
		//----设置输出格式为: 居中，这里格式还可以设置为：right/left。 占10个字符；
		out << "socre:" << qSetFieldWidth(10) << center << 90 << endl;
	}
	else
	{
		qDebug() << "open file failed";
	}
	file.close();		//---关闭文件~~~~~~
 
	//-----输出提示信息
	qDebug() << "\1   writing data  succesful   \1" << endl;
	
	return a.exec();
}
