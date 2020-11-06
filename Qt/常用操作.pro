//可以在pro文件中写上标记版本号+ico图标（Qt5才支持）
VERSION  = 2020.10.17
RC_ICONS = logo.ico


//管理员运行程序，限定在MSVC编译器。
QMAKE_LFLAGS += /MANIFESTUAC:"level='requireAdministrator' uiAccess='false'" #以管理员运行
QMAKE_LFLAGS += /SUBSYSTEM:WINDOWS,"5.01" #VS2013 在XP运行

//根据操作系统位数判断加载
win32 {
    contains(DEFINES, WIN64) { DESTDIR = $${PWD}/../../bin64
    } else { DESTDIR = $${PWD}/../../bin32 }
}


//判断Qt版本及构建套件位数
#打印版本信息
message(qt version: $$QT_VERSION)
#判断当前qt版本号
QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)
#下面是表示 Qt5.5
greaterThan(QT_VER_MAJ, 4) {
greaterThan(QT_VER_MIN, 4) {
#自己根据需要做一些处理
}
}

#QT_ARCH是Qt5新增的,在Qt4上没效果
#打印当前Qt构建套件的信息
message($$QT_ARCH)
#表示arm平台构建套件
contains(QT_ARCH, arm) {}
#表示32位的构建套件
contains(QT_ARCH, i386) {}
#表示64位的构建套件
contains(QT_ARCH, x86_64) {}