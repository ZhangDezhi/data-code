#!/usr/bin/sh


#����һ
#ͨ�� set �����λ�ò�����ģ������

# ��������
set 'word 1' word2 word3

# �������ĵ�һ��Ԫ��
echo $1

# �������ĵڶ���Ԫ��
echo $2

# �������ĵ�����Ԫ��
echo $3

# ������������Ԫ��
echo $*
echo $@

# ������������һ��Ԫ��
set -- "$@" word4
echo $4

# �鿴����Ԫ�صĸ���
echo $#

# ��������Ԫ��
for i in do "$@"; do
  echo "$i"
done

# ��������ɾ��һ��Ԫ��
shift
echo $@

# ɾ�����������Ԫ��
set x; shif


#������
#ʹ�� eval ����ģ������


�������鲢��������Ԫ�أ�

#!/bin/sh
eval a1=word1
eval a2=word2
eval a3=word3
for i in 1 2 3; do
  eval echo "The $i element of array is: \$a$i"
done


�����û������һ�仰���������鲢��������Ԫ�أ�

#!/bin/sh
echo "Enter the sentence:"
read str
n=0
for word in $str; do
  n=`expr $n + 1`
  eval a$n="$word"
  eval echo "The $n element of array is: \$a$n"
done