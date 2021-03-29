.import paramiko
import time

def set_time(hostname):
    ssh = paramiko.SSHClient()
    # 把要连接的机器添加到known_hosts文件中
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    # 连接服务器
    ssh.connect(hostname=hostname, port=22, username='root', password='winserver')
    real_time = time.strftime("%m/%d/%Y %H:%M:%S", time.localtime()) # 获取当前时间
    cmd = f'date -s "{real_time}";hwclock -w'  # 设置时间并写入bios
    stdin, stdout, stderr = ssh.exec_command(cmd)
    result = stdout.read() or stderr.read()
    ssh.close()
    print(hostname, " : ", result.decode())

if __name__ == "__main__":
    host_list = ['192.168.205.10', '192.168.205.20', '192.168.205.30', '192.168.205.50']
    for host in host_list:
        set_time(host)