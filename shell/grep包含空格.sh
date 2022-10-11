*   soft 	 nofile 630000
*	 hard   nofile 654300

grep   -E  '^\*[[:space:]]+soft[[:space:]]+nofile|^\*[[:space:]]+hard[[:space:]]+nofile'  /etc/security/limits.conf
sed -n 's/\*[[:space:]]\+soft[[:space:]]\+nofile.*/\* soft nofile 654350/p;s/\*[[:space:]]\+hard[[:space:]]\+nofile.*/\* hard nofile 654350/p' /etc/security/limits.conf
