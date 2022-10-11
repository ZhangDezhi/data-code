
#使用 # 号截取右边字符
${string#*chars}


    url="http://c.biancheng.net/index.html"
    echo ${url#*:}
    echo ${url#*p:}
    echo ${url#*ttp:}
    #//c.biancheng.net/index.html
    
    url="http://c.biancheng.net/index.html"
    echo ${url#http://}
    #c.biancheng.net/index.html

${string##*chars}

    #!/bin/bash
    url="http://c.biancheng.net/index.html"
    echo ${url#*/}    #结果为 /c.biancheng.net/index.html
    echo ${url##*/}   #结果为 index.html
    str="---aa+++aa@@@"
    echo ${str#*aa}   #结果为 +++aa@@@
    echo ${str##*aa}  #结果为 @@@


    # 使用 % 截取左边字符
${string%chars*}
    #!/bin/bash
    url="http://c.biancheng.net/index.html"
    echo ${url%/*}  #结果为 http://c.biancheng.net
    echo ${url%%/*}  #结果为 http:
    str="---aa+++aa@@@"
    echo ${str%aa*}  #结果为 ---aa+++
    echo ${str%%aa*}  #结果为 ---





${string: start :length} 	从 string 字符串的左边第 start 个字符开始，向右截取 length 个字符。
${string: start} 	从 string 字符串的左边第 start 个字符开始截取，直到最后。
${string: 0-start :length} 	从 string 字符串的右边第 start 个字符开始，向右截取 length 个字符。
${string: 0-start} 	从 string 字符串的右边第 start 个字符开始截取，直到最后。
${string#*chars} 	从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
${string##*chars} 	从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
${string%*chars} 	从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。
${string%%*chars} 	从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。