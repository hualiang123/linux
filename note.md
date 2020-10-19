## 低级输入输出

### 文件描述字的打开，创建和关闭

**打开：open()**

```
int open(constchar*pathname,intflags,mode_t mode);
返回值：成功则返回文件描述符，否则返回-1
```

对于open函数来说，第三个参数仅当创建新文件时（即 使用了O_CREAT 时）才使用，用于指定文件的访问权限位



**创建：creat()**

函数原型：

int _creat(const char *filename,int pmode);



**关闭：close()**

int close(int filedes);



### 内核用于管理打开和关闭文件的数据结构：

#### 一个进程打开两个文件的内核数据结构：

![img](http://blog.chinaunix.net/attachment/201409/15/16813896_1410748872KKtI.png)

#### 两个进程打开同一个文件的内核数据结构：

![img](http://blog.chinaunix.net/attachment/201412/19/16813896_14189567160508.jpg)

**lseek()函数：**

off _t  lseek(int filedes,off_t offset,int whence)

filedes给出已打开的文件描述字，offset指明相对whence的位移字节数，whence的取值只能是SEEK_SET,SEEK_CUR,SEEK_END之一，分别指明offset是相对文件开始，当前文件位置还是文件尾的偏移。

lseek()只移动文件的当前位置，它并不引起任何I/O操作，文件新位置可以大于文件的当前大小，在这中情况下，下一次写将扩展该文件。这种情况称为在文件中生成空洞。



**dup和dup2函数：**

int dup (int old);
int dup2 (int old，int new);

dup()复制描述字old至一个新描述字，新描述字保证是当前未打开的最小编号可用描述字。dup2()复制描述字old至编号为new的描述字。如果new已经打开，它将首先被关闭。如果new等于old，dup2()返回new但不关闭它。



这两个函数调用成功返回新的文件描述字。所返回的新文件描述字与参数old给定的描述字引用同一个打开的文件，即共享同一个系统打开文件表项。

### write()

```
函数定义：ssize_t write (int fd, const void * buf, size_t count); 
```

　　函数说明：write()会把参数buf所指的内存写入count个字节到参数放到所指的文件内。

返回值：**如果顺利write()会返回实际写入的字节数。当有错误发生时则返回-1，错误代码存入errno中**。



### read()

```
函数定义：ssize_t read(int fd, void * buf, size_t count);
```

函数说明：read()会把参数fd所指的文件传送count 个字节到buf 指针所指的内存中。

返回值**：返回值为实际读取到的字节数, 如果返回0, 表示已到达文件尾或是无可读取的数据。若参数count 为0, 则read()不会有作用并返回0。**