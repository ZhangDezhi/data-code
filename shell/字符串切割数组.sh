#!/bin/bash
 

#Shell 脚本中有个变量叫 IFS(Internal Field Seprator) ，内部域分隔符




#方法一:使用IFS
string="hello,shell,split,test"  
 
#对IFS变量 进行替换处理
OLD_IFS="$IFS"
IFS=","
array=($string)
IFS="$OLD_IFS"
 
for var in ${array[@]}
do
   echo $var
done


#方法二:使用tr
#!/bin/bash
 
string="hello,shell,split,test"  
array=(`echo $string | tr ',' ' '` )  
 
for var in ${array[@]}
do
   echo $var
done 