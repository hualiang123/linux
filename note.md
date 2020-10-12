程序开始读写一个文件的内容之前，需要打开文件，UNIX系统有两种机制用于描述程序与文件的这种连接：一种称为**文件描述字**，另一种称为**流**。因此，系统中关于I/O的函数也分为两大类：一类针对文件描述字操作，另一种针对流操作。

文件描述字表示为int类型的对象，而流表示为指向类型为FILE结构的指针。

文件描述字函数多数时系统调用，它们提供底层基本的输入输出操作接口。



### gcc常用参数：

   2.1 -v / --version   //查看编译器版本
   2.2 -I  //指定头文件的路劲
   2.3 -c  //将汇编文件生成二进制文件
   2.4 -o  //指定生成文件的名字
   2.5 -d  //gdb调试的时候需要加的参数
   2.6 -D  //编译的时候指定宏 
   2.7 -Wall //添加警告信息
   2.8 -g  //调试的时候会保留代码的文字信息，便于调试



### sizeof和strlen()的区别：

一、定bai义不同

sizeof是运算符，du在头文件中typedef为unsigned int，其值在编译时即计zhi算好了，参数可以是数组、dao指针、类型、对象、函数等。

2、它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。具体而言，当参数分别如下时，sizeof返回的值表示的含义如下：数组——编译时分配的数组空间大小；**指针——存储该指针所用的空间大小（存储该指针的地址的长度，是长整型，应该为4）**。

二、语法不同

1、strlen是函数，要在运行时才能计算。参数必须是字符型指针。当数组名作为参数传入时，实际上数组就退化成指针了。

2、它的功能是：**返回字符串的长度**。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。

### fgets函数：

fgets函数功能为从指定的流中读取[数据](https://baike.baidu.com/item/数据/33305)，每次读取一行。其原型为：char *fgets(char *str, int n, FILE *stream);从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。

### fwrite函数：

#### 描述

C 库函数 **size_t fwrite(const void \*ptr, size_t size, size_t nmemb, FILE \*stream)** 把 **ptr** 所指向的数组中的数据写入到给定流 **stream** 中。

#### 声明

下面是 fwrite() 函数的声明。

```
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
```

#### 参数

- **ptr** -- 这是指向要被写入的元素数组的指针。
- **size** -- 这是要被写入的每个元素的大小，以字节为单位。
- **nmemb** -- 这是元素的个数，每个元素的大小为 size 字节。
- **stream** -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。

#### 返回值

如果成功，该函数返回一个 size_t 对象，表示元素的总数，该对象是一个整型数据类型。如果该数字与 nmemb 参数不同，则会显示一个错误。

### fprintf函数：

##### fprintf是C/C++中的一个格式化库函数，位于头文件<cstdio>中，其作用是格式化输出到一个流文件中；函数原型为int fprintf( FILE *stream, const char *format, [ argument ]...)，fprintf()函数根据指定的格式(format)，向输出流(stream)写入数据(argument)。

### fdopen函数：

fdopen取一个[现存](https://baike.baidu.com/item/现存/2357952)的文件描述符（我们可能从 open，dup，dup2，fcntl，pipe，socket，socketpair或accept函数得到此文件描述符），并使一个标准的I / O流与该描述符相结合。

eg：FILE *fp;
        int fd;
        fd=open("./test1.txt",O_RDWR);
        fp=fdopen(fd,"w+");

### fputs函数：

#### 函数作用

C语言库函数，把字符串写入到指定的流( stream) 中，但不包括空字符。

#### 函数原型

int fputs(const char *str, FILE *stream);

返回值：该函数返回一个非负值，如果发生错误则返回 EOF(-1)。

（1）str：这是一个数组，包含了要写入的以空字符终止的字符序列。

（2）stream：指向 FILE 对象的指针，该 FILE 对象标识了要被写入字符串的流



### freopen函数：

函数，以指定模式重新指定到另一个文件。模式用于指定新文件的访问方式。

eg：freopen("./test1.txt","r",fp);

