#include<stdlib.h>

//union U
//{
//	char a[13];
//	char b;  //内存对齐为13
//};
//union U
//{ 
//	char a[13];//本来是13
//    int b;  //这里就是以int作为内存对齐
//	        //内存对齐为16
//};

//命令：gcc - E hello.c - o hello.i
//作用：将hello.c预处理输出hello.i
//命令：gcc - S hello.i - o hello.o
//作用：将预处理输出文件hello.i汇编成hello.s文件
//命令：gcc - c hello.s - o hello.o
//汇编器as 将hello.s 翻译成机器语言保存在hello.o 中（二进制文本形式）
//命令：gcc - o hello hello.cpp
//结果得到hello文件，它就是一个可执行的目标文件



