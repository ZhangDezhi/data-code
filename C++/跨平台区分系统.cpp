/*编译器*/
//GCC
#ifdef  __GNUC__
#if __GNUC__ >= 3 // GCC3.0以上

//Visual C++
#ifdef  _MSC_VER（非VC编译器很多地方也有定义）
#if _MSC_VER >=1000 // VC++4.0以上
#if _MSC_VER >=1100 // VC++5.0以上
#if _MSC_VER >=1200 // VC++6.0以上
#if _MSC_VER >=1300 // VC2003以上
#if _MSC_VER >=1400 // VC2005以上
Borland  C++
#ifdef  __BORLANDC__
/*UNIX*/
//UNIX
#ifdef  __unix
//or
#ifdef  __unix__

//Linux 
#ifdef  __linux
//or
#ifdef  __linux__

//FreeBSD 
#ifdef  __FreeBSD__

//NetBSD 
#ifdef  __NetBSD__

//Windows
//32bit
#ifdef  _WIN32（或者WIN32）
//64bit
#ifdef  _WIN64
//GUI  App
#ifdef  _WINDOWS 
//CUI  App
#ifdef  _CONSOLE
/*Windows的Ver … WINVER*/
//※ PC机Windows（95/98/Me/NT/2000/XP/Vista）和Windows CE都定义了
#if (WINVER >= 0x030a) // Windows 3.1以上
#if (WINVER >= 0x0400) // Windows 95/NT 4.0以上
#if (WINVER >= 0x0410) // Windows 98以上
#if (WINVER >= 0x0500) // Windows Me/2000以上
#if (WINVER >= 0x0501) // Windows XP以上
#if (WINVER >= 0x0600) // Windows Vista以上

//Windows 95/98/Me的Ver … _WIN32_WINDOWS
//MFC App、PC机上（Windows CE没有定义）
#ifdef  _WIN32_WINDOWS
#if (_WIN32_WINDOWS >= 0x0400) // Windows 95以上
#if (_WIN32_WINDOWS >= 0x0410) // Windows 98以上
#if (_WIN32_WINDOWS >= 0x0500) // Windows Me以上
Windows NT 的Ver … _WIN32_WINNT
#if (_WIN32_WINNT  >= 0x0500) // Windows 2000以上
#if (_WIN32_WINNT  >= 0x0501) // Windows XP以上
#if (_WIN32_WINNT  >= 0x0600) // Windows Vista以上
Windows CE（PocketPC ）
#ifdef  _WIN32_WCE
//Windows CE … WINCEOSVER
//Windows CE
//WCE_IF
Int ernet Explorer的Ver … _WIN32_IE 
/*Cygwin*/
//Cygwin
#ifdef  __CYGWIN__
//32bit版Cygwin（现在好像还没有64bit版）
#ifdef  __CYGWIN32__

//MinGW（-mno-cygwin指定）
#ifdef  __MINGW32__

//Qt
//在<QtGlobal>中，定义了各个系统的宏定义

#include<QObject>

#ifdef Q_OS_WIN
#include <winsock2.h>
#endif

#include <mysql.h>

//-----------------
#ifdef Q_OS_WIN

#endif

#ifdef Q_OS_LINUX
            QString command = QString("chmod +rw /****************************");
            QProcess proc;
            proc.execute(command);
#endif


/*
Q_OS_AIX
Defined on AIX.
Q_OS_ANDROID
Defined on Android.
Q_OS_BSD4
Defined on Any BSD 4.4 system.
Q_OS_BSDI
Defined on BSD/OS.
Q_OS_CYGWIN
Defined on Cygwin.
Q_OS_DARWIN
Defined on Darwin-based operating systems such as macOS, iOS, watchOS, and tvOS.
Q_OS_DGUX
Defined on DG/UX.
Q_OS_DYNIX
Defined on DYNIX/ptx.
Q_OS_FREEBSD
Defined on FreeBSD.
Q_OS_HPUX
Defined on HP-UX.
Q_OS_HURD
Defined on GNU Hurd.
Q_OS_IOS
Defined on iOS.
Q_OS_IRIX
Defined on SGI Irix.
Q_OS_LINUX
Defined on Linux.
Q_OS_LYNX
Defined on LynxOS.
Q_OS_MAC
Deprecated synonym for Q_OS_DARWIN. Do not use.
Q_OS_MACOS
Defined on macOS.
Q_OS_NETBSD
Defined on NetBSD.
Q_OS_OPENBSD
Defined on OpenBSD.
Q_OS_OSF
Defined on HP Tru64 UNIX.
Q_OS_OSX
Deprecated synonym for Q_OS_MACOS. Do not use.
Q_OS_QNX
Defined on QNX Neutrino.
Q_OS_RELIANT
Defined on Reliant UNIX.
Q_OS_SCO
Defined on SCO OpenServer 5.
Q_OS_SOLARIS
Defined on Sun Solaris.
Q_OS_TVOS
Defined on tvOS.
Q_OS_ULTRIX
Defined on DEC Ultrix.
Q_OS_UNIX
Defined on Any UNIX BSD/SYSV system.
Q_OS_UNIXWARE
Defined on UnixWare 7, Open UNIX 8.
Q_OS_WATCHOS
Defined on watchOS.
Q_OS_WIN32
Defined on 32-bit and 64-bit versions of Windows.
Q_OS_WIN64
Defined on 64-bit versions of Windows.
Q_OS_WIN
Defined on all supported versions of Windows. That is, if Q_OS_WIN32, Q_OS_WIN64, or Q_OS_WINRT is defined.
Q_OS_WINPHONE
Defined on Windows Phone 8.
Q_OS_WINRT
Defined for Windows Runtime (Windows Store apps) on Windows 8, Windows RT, and Windows Phone 8.
 
*/

