
1. 创建代码

```cpp
$ vim Demo.cpp
```

```cpp

#include <QApplication>
#include <QWidget>
 
int main(int argc, char *argv[])
{
  QApplication app(argc, argv); //初始化

  QWidget w;
  w.show();

  app.exec(); //主事件循环

  return 0;

}

```

2. 生成pro文件
``` bash
$ qmake -project #生成pro文件
```

3. 添加图形模块(pro文件)
```pro
QT += widgets

```
