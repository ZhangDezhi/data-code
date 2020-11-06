//GCC编译器
#ifdef __GNUC__
#if __GNUC__ >= 3 // GCC3.0以上

//MSVC编译器
#ifdef _MSC_VER
#if _MSC_VER >=1000 // VC++4.0以上
#if _MSC_VER >=1100 // VC++5.0以上
#if _MSC_VER >=1200 // VC++6.0以上
#if _MSC_VER >=1300 // VC2003以上
#if _MSC_VER >=1400 // VC2005以上
#if _MSC_VER >=1500 // VC2008以上
#if _MSC_VER >=1600 // VC2010以上
#if _MSC_VER >=1700 // VC2012以上
#if _MSC_VER >=1800 // VC2013以上
#if _MSC_VER >=1900 // VC2015以上

//Borland C++
#ifdef __BORLANDC__

//Cygwin
#ifdef __CYGWIN__
#ifdef __CYGWIN32__

//mingw
#ifdef __MINGW32__

//windows
#ifdef _WIN32    //32bit
#ifdef _WIN64    //64bit
#ifdef _WINDOWS     //图形界面程序
#ifdef _CONSOLE     //控制台程序
//Windows（95/98/Me/NT/2000/XP/Vista）和Windows CE都定义了
#if (WINVER >= 0x030a)     // Windows 3.1以上
#if (WINVER >= 0x0400)     // Windows 95/NT4.0以上
#if (WINVER >= 0x0410)     // Windows 98以上
#if (WINVER >= 0x0500)     // Windows Me/2000以上
#if (WINVER >= 0x0501)     // Windows XP以上
#if (WINVER >= 0x0600)     // Windows Vista以上
//_WIN32_WINNT 内核版本
#if (_WIN32_WINNT >= 0x0500) // Windows 2000以上
#if (_WIN32_WINNT >= 0x0501) // Windows XP以上
#if (_WIN32_WINNT >= 0x0600) // Windows Vista以上
