#!/usr/bin/env python3
# coding:utf-8
from time import ctime
from time import sleep
import _thread

loops = [4, 2, 3, 5]


def loop(nloop, nsec, lock):    # 参数依次为：标识，睡眠时间，锁对象
    print("start loop", nloop, 'at:', ctime())
    sleep(nsec)
    print("loop", nloop, "done at:", ctime())
    lock.release()  # 释放锁


def main():
    print('start at:', ctime())
    locks = []
    nloops = range(len(loops))

    for i in nloops:
        lock = _thread.allocate_lock()  # 分配锁对象
        lock.acquire()  # 获取锁对象
        locks.append(lock)

    for i in nloops:
        _thread.start_new(loop, (i, loops[i], locks[i]))　　//派生新线程

    # 等待所有锁被释放
    for i in nloops:
        while(locks[i].locked()):
            pass
    print('all DONE at', ctime())


if __name__ == '__main__':
    main()









    #


#     _thread模块
# python的_thread模块提供了基本的线程和互斥锁支持，threading模块则提供了功能更全面的线程管理。以下讨论_thread模块
# 主要方法
# _thread.start_new_thread(function,args,kwargs=None)　　　　//派生一个新的线程，给定agrs和kwargs来执行function
# _thread.allocate_lock()　　//分配锁对象
# _thread.exit()　　//线程退出
# lock.acquire(waitflag=1, timeout=-1)　　//获取锁对象
# lock.locked()　　//如果获取了锁对象返回true，否则返回false
# lock.release()　　//释放锁
# 其他方法
# _thread.LockType()　　//锁对象类型
# _thread.get_ident()　　//获取线程标识符
# -thread.TIMEOUT_MAX　　//lock.acquire的最大时间，超时将引发OverflowError
# _thread.interrupt_main()　　//引发主线程KeyboardInterrupt错误，子线程可以用这个函数来终止主线程