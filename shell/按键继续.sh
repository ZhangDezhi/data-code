//如果你给输入错误，程序会以状态1退出。这个例子将只接受Y或N或YES或NO（不区分大小写）

#!//bin/bash

read -r -p "Are You Sure? [Y/n] " input

case $input in
    [yY][eE][sS]|[yY])
		echo "Yes"
		;;

    [nN][oO]|[nN])
		echo "No"
       	;;

    *)
		echo "Invalid input..."
		exit 1
		;;
esac


//提示进行确认（输入正常退出，输入//错误则需重新输入）

#!/bin/bash

while true
do
	read -r -p "Are You Sure? [Y/n] " input

	case $input in
	    [yY][eE][sS]|[yY])
			echo "Yes"
			exit 1
			;;

	    [nN][oO]|[nN])
			echo "No"
			exit 1	       	
			;;

	    *)
			echo "Invalid input..."
			;;
	esac
done