**孤儿进程和僵尸进程：**

孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作。

僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。

**ps命令**：

**ps（Process Status）[命令](https://www.linuxcool.com/)是[linux](https://www.linuxprobe.com/)中最常见的[命令](https://www.linuxcool.com/)之一，它用来列出当前系统运行中的进程的状态信息。**

命令格式

```
ps命令基本格式为:
ps [options]
```

**常用选项**

| **选项**  | **含义**                                       |
| --------- | ---------------------------------------------- |
| -A        | 列出所有的进程                                 |
| -w        | 显示加宽，可以显示较多的信息                   |
| -a        | 显示现行终端机下的所有进程，包括其他用户的进程 |
| -u        | 以用户为主的进程状态                           |
| -x        | 通常与a这个参数一起使用，可列出较完整信息      |
| -r        | 只显示正在运行的进程                           |
| -h        | 不显示标题                                     |
| -e        | 显示所有进程，环境变量                         |
| -f        | 全格式                                         |
| -l        | 长格式                                         |
| --help    | 显示帮助信息                                   |
| --version | 显示版本信息                                   |

**常用选项组合：**

  1）**ps -ef** #用标准的格式显示进程

  2）**ps -aux** #用BSD的格式来显示

**4、ps -ef和ps -aux格式详解**

  1）ps -ef 标准格式

```bash
[root@vms001 /]# ps -ef|head -3
UID         PID   PPID  C STIME TTY          TIME CMD
root          1      0  0 6月04 ?       00:00:09 /usr/lib/systemd/systemd --switched-root --system --deserialize 24
root          2      0  0 6月04 ?       00:00:00 [kthreadd]
```

  2）ps -aux BSD格式

```bash
[root@vms001 /]# ps -aux|head -3
USER        PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root          1  0.0  0.2  60592  7936 ?        Ss   6月04   0:09 /usr/lib/systemd/systemd --switched-root --system --deserialize 24
root          2  0.0  0.0      0     0 ?        S    6月04   0:00 [kthreadd]
```



