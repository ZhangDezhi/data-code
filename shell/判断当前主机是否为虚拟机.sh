# 参考: https://blog.csdn.net/gatieme/article/details/50962554




## Windows (CMD)
#> 如果System Model：后面含有Virutal就是虚拟机，其他都是物理机
 ## CMD
 $ Systeminfo | findstr /i "System Model"

#powershell
$  get-wmiobject win32_computersystem | fl model 