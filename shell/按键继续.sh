//������������󣬳������״̬1�˳���������ӽ�ֻ����Y��N��YES��NO�������ִ�Сд��

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


//��ʾ����ȷ�ϣ����������˳�������//���������������룩

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