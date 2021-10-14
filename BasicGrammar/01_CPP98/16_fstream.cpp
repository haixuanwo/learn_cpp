
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/**
 * in.get() 获取一个字节
 * out.put(c) 写入一个字节
 * in.eof() 是否到达文件末尾
 * in.getline(buf, 200) 获取一行
 * in.tellg() 获取当前操作位置
 * in.seekg(0, ios::end) 设置当前位置
 * in.read(buf,1024); 读
 * out.write(buf,1024); 读
 */

#define FILE_NAME "test.txt"
#define BUF_SIZE 1024

int main()
{
	char buf[BUF_SIZE] = {"tanhuifang"};
	int len = strlen(buf);

	ofstream out(FILE_NAME, ios::out|ios::app);
	out.write(buf, len);
	cout<<"write:"<<buf<<endl;
	out.close();

	memset(buf, 0, sizeof(buf));
	ifstream in(FILE_NAME, ios::in);
	if (NULL == in)
	{
		cout<<"open fail"<<endl;
		return -1;
	}

	in.read(buf, len);
	cout<<"read:"<<buf<<endl;
	in.close();

	return 0;
}

