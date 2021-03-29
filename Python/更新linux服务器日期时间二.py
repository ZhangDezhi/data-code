import paramiko
import time
import requests


def get_time():
    re = requests.get('https://www.baidu.com')
    get_time = re.headers['date']                                   # 从百度返回的文件头获取时间
    real_time = time.strptime(get_time[5:25], "%d %b %Y %H:%M:%S")  # 获取当前时间
    local_time = time.localtime(time.mktime(real_time) + 8*3600)    # 转北京时间
    real_time = time.strftime("%m/%d/%Y %H:%M:%S", local_time)      # 转换时间格式
    return real_time

def set_time(hostname, ssh):
    ssh.connect(hostname=hostname, port=22, username='root', password='winserver')
    real_time = get_time()                      # 从网络获取获取当前时间
    cmd = f'date -s "{real_time}";hwclock -w'   # 设置时间并写入bios
    stdin, stdout, stderr = ssh.exec_command(cmd)
    result = stdout.read() or stderr.read()
    ssh.close()
    print(hostname, " : ", result.decode())

if __name__ == "__main__":
    ssh = paramiko.SSHClient()
    # 把要连接的机器添加到known_hosts文件中
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    # 连接服务器
    host_list = ['192.168.205.50']
    for host in host_list:
        set_time(host, ssh)