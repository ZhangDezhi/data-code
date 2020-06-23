//获得指定字符在字符串中的位置

QString str = "AT+LOC+LOCATION: 115.850441,33.004833";
QString s = "LOC";
str.indexOf(s); //3
str.indexOf(s, 6); //7

QString str = "AT+LOC+LOCATION";
QString s = "O";
str.lastIndexOf(s); //13


//截取指定位置字符串

QString str = "AT+LOC+LOCATION: 115.850441,33.004833";
QString s = str.mid(6); //"+LOCATION: 115.850441,33.004833"  
QString s = str.mid(6, 9); //"+LOCATION"


//分割字符串
QString str = "AT+LOC+LOCATION";
QStringList list = str.split("+");
for(int i = 0; i < list.count(); i++)
{
    qDebug() << list.at(i);
}

//输出
"AT"
"LOC"
"LOCATION"


//字符串以特订字符串开始
QString url = "https://www.baidu.com";
if(url.startsWith("https") && url.endsWith("com")) //true
//等价于
if(url.left(5) == "https" && url.right(3) == "com") //true


//是否包涵字符串
QString str = "AT+LOC+LOCATION: 115.850441,33.004833";
if(str.contains("LOC", Qt::CaseSensitive)) //true