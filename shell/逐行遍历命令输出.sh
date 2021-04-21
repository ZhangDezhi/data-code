for line in $(ldd $RUNHOME/lib/libinhibitctrl.so)
do  
  echo  "==> $line"
done