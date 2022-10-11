//编译器支持由ISO C99和ISO C ++ 14标准指定的这些预定义的宏。



    __cplusplus当翻译单元编译为C ++时，将其定义为整数文字值。否则，未定义。

    __DATE__当前源文件的编译日期。日期是Mmm dd yyyy形式的恒定长度字符串文字。月份名称Mmm与C运行时库库asctime函数生成的日期中的缩写月份名称相同。日期dd的第一个字符是一个空格，如果该值小于10.此宏始终被定义。 类型为char*

    __FILE__当前源文件的名称。__FILE__扩展为字符串文字。要确保显示文件的完整路径，请使用/ FC（诊断中源代码文件的完整路径）。始终定义此宏。类型为char*

    __LINE__定义为当前源文件中的整数行号。可以通过使用指令来更改__LINE__宏的值#line。始终定义此宏。类型为int

    __STDC__仅当编译为C并且指定了/ Za编译器选项时，才将其定义为1 。否则，未定义。

    __STDC_HOSTED__如果实现是托管实现，则将其定义为1 ，支持整个所需的标准库。否则定义为0。

    __STDCPP_THREADS__当且仅当程序可以有多个执行线程并且编译为C ++时，将其定义为1。否则，未定义。

    __TIME__翻译预处理翻译单位的时间。的时间是一个字符串文字形式的HH：MM：SS，与由C运行时库返回的时间asctime功能。始终定义此宏。类型为char*

