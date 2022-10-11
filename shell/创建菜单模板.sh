#!/bin/sh
#Shell菜单演示
function menu ()
{
 cat << EOF
----------------------------------------
|***************菜单主页***************|
----------------------------------------
`echo -e "\033[35m 1)电子设备\033[0m"`
`echo -e "\033[35m 2)车辆信息\033[0m"`
`echo -e "\033[35m 3)主菜单\033[0m"`
`echo -e "\033[35m 4)退出\033[0m"`
EOF
read -p "请输入对应产品的数字：" num1
case $num1 in
 1)
  echo "Welcome to ELE主页!!"
  eleproduct_menu
  ;;
 2)
  echo "Welcome to CAR主页!!"
  car_menu
  ;;
 3)
  clear
  menu
  ;;
 4)
  exit 0
esac
}
 
function eleproduct_menu ()
{
 cat << EOF
----------------------------------------
|***************ELE主页****************|
----------------------------------------
`echo -e "\033[35m 1)苹果\033[0m"`
`echo -e "\033[35m 2)魅族\033[0m"`
`echo -e "\033[35m 3)小米\033[0m"`
`echo -e "\033[35m 4)返回主菜单\033[0m"`
EOF
read -p "请输入对应产品的数字：" num2
case $num2 in
 1)
  echo "the is iphone X ￥8888!!"
  eleproduct_menu
  ;;
 2)
  echo "the is meizu pro6 ￥2600!!"
  eleproduct_menu
  ;;
 3)
  echo "the is xiaomi MXA2 ￥4290!!"
  eleproduct_menu
  ;;
 4)
  clear
  menu
  ;;
 *)
  echo "the is fail!!"
  eleproduct_menu
esac
}
 
function car_menu ()
{
 cat << EOF
----------------------------------------
|***************CAR主页****************|
----------------------------------------
`echo -e "\033[35m 1)大众\033[0m"`
`echo -e "\033[35m 2)宝马\033[0m"`
`echo -e "\033[35m 3)梅赛德斯奔驰\033[0m"`
`echo -e "\033[35m 4)返回主菜单\033[0m"`
EOF
read -p "请输入对应产品的数字：" num3
case $num3 in
 1)
  echo "the is dazon ￥120000!!"
  car_menu
  ;;
 2)
  echo "the is BMW ￥230000!!"
  car_menu
  ;;
 3)
  echo "the is bench ￥460000!!"
  car_menu
  ;;
 4)
  clear
  menu
  ;;
 *)
  echo "the is fail!!"
  car_menu
esac
}
menu