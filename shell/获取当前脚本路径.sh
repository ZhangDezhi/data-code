cat shell/a.sh
#!/bin/bash
echo '$0: '$0
echo "pwd: "`pwd`
echo "============================="
echo "scriptPath1: "$(cd `dirname $0`; pwd)
echo "scriptPath2: "$(pwd)
echo "scriptPath3: "$(dirname $(readlink -f $0))
echo "scriptPath4: "$(cd $(dirname ${BASH_SOURCE:-$0});pwd)
echo -n "scriptPath5: " && dirname $(readlink -f ${BASH_SOURCE[0]})
Jun@VAIO 192.168.1.216 23:53:17 ~ >
bash shell/a.sh
$0: shell/a.sh
pwd: /home/Jun
=============================
scriptPath1: /home/Jun/shell
scriptPath2: /home/Jun
scriptPath3: /home/Jun/shell
scriptPath4: /home/Jun/shell
scriptPath5: /home/Jun/shell
Jun@VAIO 192.168.1.216 23:54:54 ~ >




        dirname $0，取得当前执行的脚本文件的父目录

        cd `dirname $0`，进入这个目录(切换当前工作目录)

        pwd，显示当前工作目录(cd执行后的)


current_path=$(cd "$(dirname $0)";pwd)
current_path=$(
cd $(dirname $0)
pwd
)
#------------------------------------------------
#current_path=$(cd "$(dirname "${BASH_SOURCE[0]}" )" && pwd)
current_path=$(cd $(dirname "${BASH_SOURCE[0]}") && pwd)

#------------------------------------------------
current_path=$(
cd $(dirname "${BASH_SOURCE[0]}")
pwd
)

