var=echo
echo "echo 1 1 1" | awk '$1 ~ /'$var'/{print $1,$2}'