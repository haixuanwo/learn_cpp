/**
	1、函数参数执行的顺序是从右向左，所以会先处理最右端的参数,然后依次向左处理

	2、对于i++和++i是先加与后加的区别，但是在参数处理上则对应。
	（1）如果是i++那么表示符合从右向左处理的前提下，当即处理该参数。
	（2）如果是++i，那么表示只是执行++i运算并不将结果作为参数结果,将参数位置压入堆栈
	（3）只有当所有参数从右向左处理完毕之后，从堆栈弹出所有因为延后操作语句而没有填入最终结果的参数位置，将最终执行的结果i，作为相应的参数值，填入进去。

	3、如果实参是个表达式的话，会直接将表达式的值作为参数值
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int func(int a, int b, int c)
{
	printf("a[%d] b[%d] c[%d]\n", a, b, c);
}

int func1(int a)
{
	printf("a[%d]\n", a);
}

int func2(int a, int b)
{
	printf("a[%d] b[%d]\n", a, b);
}

int main(int argc, char *argv[])
{
	int a = 10;
	int b = 20;
	//func(++a, a+b, --a);

	func(--a, ++a + ++b, ++a); //
	return 0;
}

