
目前我知道的方法有四种
1.awk 'END {print}'
 
2.sed -n '$p'
 
3.sed '$!N;$!D'
 
4.awk '{b=a"\n"$0;a=$0}END{print b}'
