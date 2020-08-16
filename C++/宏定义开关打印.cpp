//
//   宏定义开关打印.cpp
//
// Created by ZhangDezhi on2020-07-31 11:02 
// Last Modified  : 2020-07-31 11:03:53
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
fdef DEBUG
#define DbgPrintf printf
#else
#define DbgPrintf /\
		/DbgPrintf
#endifi



/*
 *
 *如果DEBUG已经定义了，那么不用说，当然是用printf去代替DbgPrintf了。
下面只分析DEBUG未定义的情形，
这个宏定义实际上是将“DbgPrintf”定义成了“//DbgPrintf”，
由于续行符的作用，#define定义时不会发现注释符“//”，但是在展开到代码之后，就成了注释符“//”了，也就是说，如果你原来的代码是DbgPrintf("%d",x);，经过这个宏展开后成了//DbgPrintf("%d",x);，相当于自动在前面加了注释符“//”。要注意的是，续行符后面的“/”一定要顶格写，否则就不是“//”了。另外，这个宏只能单独一行使用，因为它将该行后面的代码都注释掉了。
 *
 */
