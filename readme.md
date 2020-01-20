# SKL脚本小工具语言

## 前言
进过将近一个月的时间的学习和工作，终于做出了一个可运行的样子。
虽然很浅陋，但是这丝毫不影响对于脚本的探究和学习。

## 如何安装
- 下载源码
- 安装需要在Unix环境下,bison,flex软件都必须要有
- 编译:`root@machine:code_source_path/build.sh`没有错误即编译成功
- 编译结果
- code_source_path/objs/目录下为编译过程文件
- code_source_path/bin/skl为可执行程序

## 执行
`root@machine:code_source_path/bin/skl scripts/index.skl`
```
(string) haha1
(double) 8.999000
(string) haha2
(string) haha1
(integer) 1
(string) haha2
(string) haha1
(integer) 1
(string) haha2
(string) haha1
(integer) 1
(string) haha2
(double) 3.100000
(integer) 7
(double) 10.999000
(integer) 2
(bool) false
(bool) false
(bool) true
(string) \n
(string) haha1
(integer) 1
(string) haha2
(string) haha1
(integer) 1
(string) haha2
(double) 3.100000
(integer) -1
(double) 10.999000
(integer) 2
(bool) false
(bool) false
(bool) true
```

## 说明
SKL现在还很弱小，基本执行不了业务，但是它已经可以分析和运行特定的语法了。
后续我会继续努力，实现更多的特性。



