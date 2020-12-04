#由于不同系统中ifconfig返回信息的格式有一定差别

## Linux
LC_ALL=C ifconfig  | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}'

## FreeBSD/OpenBSD:

LC_ALL=C ifconfig  | grep -E 'inet.[0-9]' | grep -v '127.0.0.1' | awk '{ print $2}'

## Solaris:


LC_ALL=C ifconfig -a | grep inet | grep -v '127.0.0.1' | awk '{ print $2}'
