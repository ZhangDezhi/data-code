unzip xx.zip > /dev/null 2>&1

unzip xx.zip > /dev/null
前半部分是将标准输出重定向到空设备，

后面的2>&1就将标准错误输出重定向到标准输出，这样最终也是到空设备。

#打印命令


set -v   

或者 

#!/bin/bash -v  

set -x 
#!/bin/bash -x  


bash -v  script.sh  
bash -x script.sh  