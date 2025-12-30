# C++

C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

C++ 是面向对象的编程语言，支持类和对象的概念，允许封装、继承和多态等特性。



## 标准库

标准的 C++ 由三个重要部分组成：

* 核心语言，提供了所有构件块，包括变量、数据类型和常量，等等。
* C++ 标准库，提供了大量的函数，用于操作文件、字符串等。
* 标准模板库（STL），提供了大量的方法，用于操作数据结构等。



# 基础



## 变量

[查看源码](1、基础/02_变量.cpp "变量")


变量存在的意义：方便管理内存空间

声明方式 : `数据类型 变量名 = 初始值`

```cpp
int a = 10;
```



## 常量

[查看源码](1、基础/03_常量.cpp "常量")

用于记录程序中不可更改的数据

C++定义常量的方式有三种：
1. 使用 `#define` 预处理指令定义宏常量
    * 通常在文件上方定义，表示一个常量
2. 使用 `const` 关键字定义常量
    * 通常在变量前加上 `const` 关键字，表示一个该变量为常量

```cpp
#define Day 7
const int month = 12;
```



## 关键字

[查看源码](1、基础/04_关键字.cpp "关键字")


|    asm     |      do      |        if        |   return    | typedef  |
| :--------: | :----------: | :--------------: | :---------: | :------: |
|    auto    |    double    |      inline      |    short    |  typeid  |
|    bool    | dynamic_cast |       int        |   signed    | typename |
|   break    |     else     |       long       |   sizeof    |  union   |
|    case    |     enum     |     mutable      |   statis    | unsigned |
|   catch    |   explicit   |    namespace     | static_cast |  using   |
|    char    |    export    |       new        |   struct    | virtual  |
|   class    |    extern    |     operator     |   switch    |   void   |
|   const    |    false     |     private      |  template   | volatile |
| const_cast |    float     |    protected     |    this     | wchar_t  |
|  continue  |     for      |      public      |    throw    |  while   |
|  default   |    friend    |     register     |    true     |          |
|   delete   |     goto     | reinterpret_cast |     try     |          |



## 标识符命名规则

[查看源码](1、基础/05_标识符.cpp "标识符")

标识符命名时必须遵守以下规则：

* 标识符不能是关键字
* 标识符只能由字母、数字和下划线组成
* 第一个字符必须为字母或下划线
* 标识符中字母区分大小写



# 数据类型

在创建一个变量或者常量时，必须指定相应的数据类型，否则无法给变量分配内存

需要通过数据类型来进行内存空间分配



## 整型

[查看源码](2、数据类型/01_整型.cpp "整型")

整型表示的是整数类型的数据

|数据类型|占用空间|取值范围|
|:---:|:---:|:---:|
|short|2字节|(-2^15 ~ 2^15-1)|
|int|4字节|(-2^31 ~ 2^31-1)|
|long|Win:4字节 Linux-32:4字节 Linux-64:8字节|(-2^31~ 2^31-1)|
|long long|8字节|(-2^63 ~ 2^63-1)|

 

## sizeof 关键字

[查看源码](2、数据类型/02_sizeof.cpp "sizeof")

统计数据类型所占内存大小

`sizeof(数据类型/变量)`



## 实型 (浮点型)

[查看源码](2、数据类型/03_实型.cpp "实型")

用于表示小数

* float
* double

| 数据类型 | 占用空间 |    取值范围     |
| :------: | :------: | :-------------: |
|  float   |  4字节   |   7位有效数字   |
|  double  |  8字节   | 15~16位有效数字 |

```cpp
// 默认情况下，小数被当作 double 类型处理, 需要使用 f 标识
// 通常只会输出6位有效数字
float f1 = 3.1415926f;
cout << "f = " << f1 << endl; // 3.14159

double d2 = 3.1415926;
cout << "d = " << d2 << endl; // 3.14159

// 科学计数法
float f3 = 3e2f; // 3 * 10 ^ 2
cout << "f3 = " << f3 << endl; // 300

float f4 = 3e-2f; // 3 * 0.1 ^ 2
cout << "f4 = " << f4 << endl; // 0.03
```



## 字符型

[查看源码](2、数据类型/04_字符型.cpp "字符型")

字符型用于表示单个字符

`char ch = 'a';`

只占用1个字节

字符型是将字符对应的 ASCII 编码放入内存

```cpp
char ch = 'a';
cout << "ch = " << ch << endl;

cout << "Size of char: " << sizeof(char) << " 字节" << endl;

// 错误示范
// 使用双引号会被当作字符串处理，而不是字符
// char ch = "a"

// 使用ASCII码值初始化字符变量
char ch2 = 65; // A
cout << "ch2 = " << ch2 << endl; // A

char ch3 = 97; // a
cout << "ch2 = " << ch3 << endl; // a
```



## 转义字符

用于表示一些不能显示出来的 ASCII 字符

`\n, \\, \t`



## 字符串型

[查看源码](2、数据类型/05_字符串型.cpp "字符串型")

用于表示一串字符

**语法:**

C风格：`char 变量名[] = "值";`

C++风格：`string 变量名 = "值";`

```cpp
char str1[] = "Hello, World!";
cout << "str1 = " << str1 << endl;

#include <string>
string str2 = "Hello, C++!";
cout << "str2 = " << str2 << endl;
```



## 布尔类型

[查看源码](2、数据类型/06_布尔类型.cpp "布尔类型")

```cpp
bool flag = true;
cout << "flag = " << flag << endl; // 1

bool flag2 = false;
cout << "flag2 = " << flag2 << endl; // 0

// 1字节
cout << "Size of bool = " << sizeof(bool) << " 字节" << endl; 
```

## 数据输入

[查看源码](2、数据类型/07_数据输入.cpp "数据输入")

用于从键盘获取数据

`cin >> 变量;`

```cpp
int input1;
cout << "请输入一个整数: " << endl;
cin >> input1;
cout << "您输入的整数是: " << input1 << endl;

char input2;
cout << "请输入一个字符: " << endl;
cin >> input2;
cout << "您输入的字符是: " << input2 << endl;

string input3;
cout << "请输入一个字符串: " << endl;
cin >> input3;
cout << "您输入的字符串是: " << input3 << endl;

bool input4;
cout << "请输入一个布尔值(0或1): " << endl;
cin >> input4;
cout << "您输入的布尔值是: " << input4 << endl;
```



# 运算符

用于执行代码的运行

| 运算符类型 |                  作用                  |
| :--------: | :------------------------------------: |
| 算术运算符 |            用户处理四则运算            |
| 赋值运算符 |        用户将表达式的值赋给变量        |
| 比较运算符 | 用于表达式的比较，并返回一个真值或假值 |
| 逻辑运算符 |    用于根据表达式的值返回真值或假值    |



## 算术运算符

[查看源码](3、运算符/01_算术运算符.cpp "算术运算符")

用于处理四则运算

`+, -, *, /, %, ++, --`

```cpp
int a = 10;
int b = 20;
cout << "a = " << a << ", b = " << b << endl;

cout << "a + b = " << a + b << endl;
cout << "a - b = " << a - b << endl;
cout << "a * b = " << a * b << endl;
cout << '\n';

// int / int = int
cout << "a / b = " << a / b << endl;
cout << "(a * 1.f) / (b * 1.f)= " << (a * 1.f) / (b * 1.f) << endl;
cout << '\n';

cout << "a % b = " << a % b << endl;
cout << "b % a = " << b % a << endl;
cout << '\n';

cout << "a = " << a << ", b = " << b << endl;
cout << "a++ = " << a++ << endl;
cout << "++b = " << ++b << endl;
cout << "a-- = " << a-- << endl;
cout << "--b = " << --b << endl;
cout << "a = " << a << ", b = " << b << endl;
```



## 赋值运算符

[查看源码](3、运算符/02_赋值运算符.cpp "赋值运算符 ")

用于将表达式的值赋给变量

`+= -= *= /= %=`

```
int a = 10;
cout << "a = " << a << endl;

a = 100;
cout << "a = 100 = " << a << endl;

cout << " a += 2 = " << (a += 2) << endl;
cout << " a -= 2 = " << (a -= 2) << endl;
cout << " a *= 2 = " << (a *= 2) << endl;
cout << " a /= 2 = " << (a /= 2) << endl;
cout << " a %= 2 = " << (a %= 2) << endl;
```



## 比较运算符

[查看源码](3、运算符/03_比较运算符.cpp "比较运算符 ")

用于表达式的比较，并返回真或假

`> < >= <= == !=`

```cpp
int a = 10;
int b = 20;

cout << "a = " << a << ", b = " << b << endl;
cout << "a == b : " << (a == b) << endl; // 等于
cout << "a != b : " << (a != b) << endl; // 不等于
cout << "a > b : " << (a > b) << endl;   // 大于
cout << "a < b : " << (a < b) << endl;   // 小于
cout << "a >= b : " << (a >= b) << endl; // 大于等于
cout << "a <= b : " << (a <= b) << endl; // 小于等于
```



## 逻辑运算符

[查看源码](3、运算符/04_逻辑运算符.cpp "逻辑运算符 ")

用于根据表达式的值返回真或假

`! && ||`

```cpp
int a = 10;
int b = 20;

cout << " a = " << a << endl;
cout << " b = " << b << endl;

cout << " a != 10" << (a != 10) << endl;
cout << " !a = " << !a << endl;
cout << " !!a = " << !!a << endl;
cout << " !!!a = " << !!!a << endl;

cout << " (a < b) && (a != b) = " << ((a < b) && (a != b)) << endl;
cout << " (a > b) || (a != b) = " << ((a > b) || (a != b)) << endl;
```



# 程序流程结构

顺序结构、选择结构、循环结构

* 顺序结构：按顺序执行，不发生跳转
* 选择结构：根据条件是否满足，有选择的执行相应代码
* 循环结构：依据条件是否满足，循环多次执行相应代码



## 选择结构

### if

[查看源码](4、程序流程结构/01_if.cpp "选择结构 ")

执行满足条件的语句

if语句有三种形式

* 单行格式
* 多行格式
* 多条件格式

单行：

```cpp
if (条件) { 满足条件的执行语句 }

// 单行形式 if
int input;
cout << "请输入一个整数";
cin >> input;

if (input >= 10)
{
	cout << "输入的整数大于等于10" << endl;
}
```

多行：

```cpp
if (条件) { 满足条件的执行语句 } else { 不满足条件的执行语句2 }

// 多行形式 if...else
cout << "请输入一个整数";
cin >> input;

if (input >= 10)
{
	cout << "输入的整数大于等于10" << endl;
} 
else
{
	cout << "输入的整数小于10" << endl;
}
```

多条件：

```cpp
if (条件1) { 满足条件1的执行语句 } else if (条件2) { 满足条件2的执行语句 } else { 不满足条件的执行语句 }

// 多条件形式 if...else if... else
cout << "请输入一个整数";
cin >> input;

if (input > 10)
{
	cout << "输入的整数大于10" << endl;
}
else if (input == 10)
{
	cout << "输入的整数等于10" << endl;
}
else
{
	cout << "输入的整数小于10" << endl;
}
```



### 三目运算符

[查看源码](4、程序流程结构/02_三目运算符.cpp "三目运算符 ")

`表达式1 ? 表达式2 ? 表达式3`

```cpp
cout << "三目运算符示例：" << endl;
cout << "10 > 2 ? '是' : '否' 的结果是： " << (10 > 2 ? "是" : "否") << endl;

// 在 C++ 中如果三目运算符返回的是变量，可以继续复制
int a = 100;
int b = 10;
cout << "初始值 a = " << a << ", b = " << b << endl;
(a > b ? a : b) = 20; // 将较大值赋给 c
cout << "(a > b ? a : b) = 20, a = " << a << endl;
```



### switch

[查看源码](4、程序流程结构/03_switch.cpp "switch ")

执行多条件分支语句

```cpp
switch (表达式)
{
    case 结果1 : 执行语句1;break;
    case 结果2: 执行语句2;break;
    
        ...
     
	default: 执行语句;
}

int a;
cout << "请输入一个整数（1-5）：";
cin >> a;
switch (a)
{
	case 1:
		cout << "你输入的是数字 1" << endl;
		break;
	case 2:
		cout << "你输入的是数字 2" << endl;
		break;
	case 3: 
		cout << "你输入的是数字 3" << endl;
		break;
	case 4:
		cout << "你输入的是数字 4" << endl;
		break;
	case 5:
		cout << "你输入的是数字 5" << endl;
		break;
	default:
		cout << "你输入的数字不在范围内" << endl;
		break;
}
```



## 循环结构

### while

满足循环条件，执行循环语句

`while(循环条件) {循环语句}`

```cpp
int num = 0;
while(num < 10) 
{
    cout << "num = " << num << endl;
    num++;
}
```



### do...while

满足循环条件，执行循环语句

`do {循环语句} while(循环条件) `

```cpp
int num = 0;
do 
{
    cout << "num = " << num << endl;
    num++;
}
while(num < 10)
```



### for

满足循环条件，执行循环语句

`for (起始表达式;条件表达式;末尾循环体) {循环语句;}`

```cpp
for (int num = 10; num < 10; num++) 
{
    cout << "num = " << num << endl;
}
```



## 跳转语句

### break

用于跳出选择结构或循环结构

```cpp
for (int num = 10; num < 10; num++) 
{
    cout << "num = " << num << endl;
    if (num == 5) 
    {
        break;
    }
}
```



### continue

在循环语句中跳过本次循环，进行下一次循环

```cpp
for (int num = 10; num < 10; num++) 
{
    cout << "num = " << num << endl;
	if (num == 5) 
    {
        continue;
    }
}
```



### goto

无条件跳转语句

**尽量不要使用 goto，以免造成程序流程混乱**

```cpp
cout << "1 --" << endl;
cout << "2 --" << endl;

goto FLAG;

cout << "3 --" << endl;
cout << "4 --" << endl;

FLAG:

cout << "5 --" << endl;
cout << "6 --" << endl;

```



# 数组

一个存放了相同类型的数据元素

在传递时数组的数据类型自动转换为指针类型



## 一维数组

`数据类型 数组名[数组长度]`

`数据类型 数组名[数组长度] = {值1, 值2 ...}`

`数据类型 数组名[] = {值1, 值2 ...}`

```cpp
int a[10] = {1, 2, 3, 4, 5}
```



## 二维数组

```cpp
int a[10][10] = 
{
    {1, 2, 3...}, 
    {1, 2, 3...}, 
    {1, 2, 3...} 
    ...
}
```



# 函数

将代码封装



## 定义

```cpp
返回值类型 函数名 (参数列表)
{
    语句;
	return 返回值;    
}
```



## 值传递

函数调用时，实参将值传入形参

如果形参发生改变不会影响实参

```cpp
int a = 10;
change(a);
void change(int num) 
{
    num = 20;
}

cout << "a = " << a << endl; // 10
```



## 函数声明

告诉编译器函数的名称以及如何调用函数

```cpp
// 声明
int max(int a, int b);

// 定义
int max(int a, int b) 
{
    return a > b ? a : b;
}

```



## 函数的分文件编写

[查看源码](6、函数/swap.h "swap.h")

1. `.h` 头文件中进行函数声明
2. `.cpp` 源文件中进行函数的定义



swap.h

```cpp
#pragma once
#include <iostream>
using namespace std;

// 函数声明
void swap(int a, int b);
```



swap.cpp

```cpp
#include "swap.h"

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "交换后：a = " << a << ", b = " << b << endl;
}

int main()
{
	swap(10, 20);
}

```



## 默认参数

可以为函数形参赋予默认值

`返回值类型 函数名 (参数=默认值) {}`

```cpp
int func(int a, int b=10, int c=20) 
{
    return a + b + c;
}

func(10, 20);

func(10, 20, 30);
```

函数声明时有默认值后，实现不能再添加默认值

> 声明和实现只能有一个存在默认值

```cpp
int func(int a, int b=10);

int func(int a, int b=10) {} // error

int func(int a, int b) {}    // ok
```

## 占位参数

`返回值类型 函数名 (数据类型)`

在形参中写明数据类型，但无形参名称即可占位

```cpp
int func(int a, int);

func(10); // error
func(10, 1) // ok

int func(int a, int = 10);

func(10); // ok
```

## 函数重载

* 同一作用域
* 函数名称相同
* 函数参数类型不同/个数不同/顺序不同

使用引用重载

```cpp
int func(int& a);
int func(const int& a);

int a = 10;
func(a); // func(int& a)

func(10); // func(const int& a)
```

默认值重载

```cpp
int func(int a);
int func(int a, int b = 10);

func(10); // error
```



# 指针

可以通过指针间接访问内存

## 指针的定义和使用

[查看源码](7、指针/01_指针的定义和使用.cpp "指针的定义与使用")

使用 `*` 声明一个指针，使用`&`获取一个变量的地址

使用 `&` 获取一个变量的地址

`数据类型* 变量名1 = &变量名2; `

使用解引用获取指针的值：`*变量名1`



```cpp
int a = 10;
//数据类型* 指针变量名 = &变量名;
int* p= &a;

cout << "a的值为: a = " << a << endl;
cout << "a的地址为: &a = " << &a << endl;
cout << "p指向的地址为: p = " << p << endl;
// *p  表示解引用指针变量p, 获取p指向地址存储的值
cout << "p解引用的值为: *p = " << *p << endl;
cout << "p的地址为: &p = " << &p << endl;

cout << "=========================" << endl;

*p = 1000;
cout << "*p = 1000; 之后" << endl;
cout << "a的值为: a = " << a << endl;
cout << "a的地址为: &a = " << &a << endl;
cout << "p指向的地址为: p = " << p << endl;
cout << "p解引用的值为: *p = " << *p << endl;
cout << "p的地址为: &p = " << &p << endl;

```



## 指针所占的内存空间

在 32位 操作系统下占用4个字节空间

在 64位 操作系统下占用8个字节空间





## 空指针和野指针

空指针和野指针都指非我们申请的内存空间

**空指针：**指针变量执行内存中编号为0的空间

用于初始化指针变量

```cpp
int* p = NULL;
// ERROR 不允许访问 nullptr
cout << *p << endl;
```



**野指针：**指针变量指向非法的内存空间

```cpp
// 未声明使用后0x1100内存空间
int* p = (int*)0x1100;
// ERROR 报错 读取访问权限错误
cout << *p << endl;

```



## const 修饰指针

* const 修饰指针 -- 常量指针
  * 指针的指向可以修改，指向的值不可修改
* const 修饰常量 -- 指针常量
  * 指针的指向不可修改，指向的值可以修改
* const 即修饰指针又修饰常量

```cpp
int a = 10;
int b = 20;

// const 修饰 int* p1 指针
const int* p1 = &a;
p1 = &b; // √
*p1 = 20; // X

// const 修饰 p2 常量
int* const p2 = &a;
p2 = &b; // X
*p2 = 20; // √

// const 修饰 int* p3 指针，const 修饰 p3 常量
const int* const p3 = &a;
p3 = &b; // X
*p3 = 20; // X

```



## 指针和数组

利用指针访问数组中的元素

```cpp
int arr[10] = { 1, 2, 3, 4, 5 };

// 获取数组首地址
int* p1 = arr;
cout << "*p1 = "<< *p1 << '\n'; // 1

// 获取数组第二个值
// int 类型的指针 +1 时就会直接偏移 sizeof(int) 大小的字节
p1++; // p1 所指向的地址 偏移 sizeof(int)
cout << "*p1 = " << *p1 << '\n'; // 2

// 获取数组的第三个元素的地址
int* p2 = &arr[2];
cout << "*p2 = " << *p2 << '\n'; // 3
```



## 指针和函数

指针作为函数参数时，会传入实参地址

```cpp
int a = 10;
int b = 20;

void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


swap(&a, &b);
// a = 20, b = 10
```



# 结构体

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型



## 定义和使用

[查看源码](8、结构体/01_结构体的定义和使用.cpp "结构体的定义与使用")

`struce 结构体名 { 结构体成员列表 };`

通过结构体创建变量的方式有三种：

* struct 结构体名 变量名
* struct 结构体名 变量名 = {成员1, 成员2};
* 定义结构体时顺便创建变量

```cpp
struct student 
{
    string name;
    int age;
    int scode;
};
```

```cpp
// 定义结构体
struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
} stu3; // 创建方式三：定义结构体的同时创建变量 s3

// 创建方式一：
struct Student stu1;
// struct 可省略
// Student stu1;
stu1.name = "张三";
stu1.age = 20;
stu1.score = 90;

cout << "Name: " << stu1.name << ", Age: " << stu1.age << ", Score: " << stu1.score << '\n';

// 创建方式二：
Student stu2 = {"李四", 25, 95};
cout << "Name: " << stu2.name << ", Age: " << stu2.age << ", Score: " << stu2.score << '\n';

// 在定义结构体的同时创建变量
stu3.name = "王五";
stu3.age = 22;
stu3.score = 88;
cout << "Name: " << stu3.name << ", Age: " << stu3.age << ", Score: " << stu3.score << '\n';
```



## 结构体数组

[查看源码](8、结构体/02_结构体数组.cpp "结构体数组")

将自定义的结构体放入数组中维护

`struct 结构体名 数组名[元素个数] = {{}, {}, {}, ...}`

```cpp
// 定义结构体
struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
};

// 创建结构体数组
Student stuArr[3] = 
{
    {"张三", 25, 95},
    {"李四", 25, 95},
    {"王五", 25, 95}
};

// 访问并修改结构体数组中的元素
stuArr[2].name = "赵六";
stuArr[2].age = 20;

// 遍历结构体
for (int i = 0; i < 3; i++)
{
    cout << "name: " << stuArr[i].name << ", 年龄: " << stuArr[i].age << ", 分数: " << stuArr[i].score << endl;
}

```



## 结构体指针

通过指针访问结构体中的成员

* 利用操作符 `->` 或 `*` 解引用可以通过结构体指针访问结构体属性

```cpp
struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
};

Student stu1 = { "张三", 20, 60 };

// 将指针指向结构体变量
Student* stuPtr = &stu1;

// 通过指针访问结构体成员
// 方式一：使用解引用操作符 *
cout << "Name: " << (*stuPtr).name << " Age: " << (*stuPtr).age << " Score: " << (*stuPtr).score << endl;
// 方式二：使用箭头操作符 ->
cout << "Name: " << stuPtr->name << " Age: " << stuPtr->age << " Score: " << stuPtr->score << endl;
```



## 结构体嵌套

结构体的成员也可以是一个结构体

```cpp
struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
};

struct Teacher 
{
	// 成员列表
	string name;
	int age;
	Student stu;
};

Teacher t1;
t1.name = "张三";
t1.age = 20;
t1.stu.name = "李四";
t1.stu.age = 10;
t1.stu.score = 100;
```



## 结构体做为函数参数

结构体也可以作为参数传入函数

```cpp
struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
};

Student stu;
stu.name = "李四";
stu.age = 10;
stu.score = 100;
printStudent(stu, &stu)

void printStudent(Student stu1, Student* stu2) 
{
 	stu1.age = 20;
    // 该形参的值被修改，但实参未修改
    cout << "Name: " << stu1.name << " Age: " << stu1.age << " Score: " << stu1.score << endl;
    
    stu2->age = 20;
    // 该形参的值被修改，实参也被修改
    cout << "Name: " << stu2->name << " Age: " << stu2->age << " Score: " << stu2->score << endl;
}
```



## 结构体中 const 的使用场景

使用 const 限定成员，以防止误操作

```cpp
struct Student
{
	string name;
	int age;
    // 使用 const 修饰成员表示为常量, 不可修改
	const int score;
};

Student stu;
stu.name = "李四";
stu.age = 10;
stu.score = 100;
printStudent(&stu)

void printStudent(const Student* stu1) 
{
    // Error stu1 为 const 修饰参数，不可修改
    // stu1->age = 20;
    
    cout << "Name: " << stu1->name << " Age: " << stu1->age << " Score: " << stu1->score << endl;
}
```



# 类和对象

面向对象三大特性：封装、继承、多态

## 封装

* 将属性和行为作为一个整体
* 将属性和行为加以权限控制

访问权限：

`public protected private`



### struct和class区别

默认的访问权限不同

* struct 默认为公共
* class 默认权限为私有



## 对象初始化和清理

### 构造函数和析构函数

* 构造函数：主要作用于成员初始化
* 析构函数：主要作用于对象销毁前的操作 



构造函数：`类型(){}`

析构函数：`~类名(){}`



### 构造函数的分类和调用

按参数：有参构造和无参构造

按类型：普通构造和拷贝构造



按调用方式：

* 括号法
* 显示法
* 隐式转换法



```cpp
class Person
{
    public:
    	Person() {} // 无参构造
    
    	Person(int a) {} // 有参构造
    
    	Person(const Person &p) {} // 拷贝构造         	
}

int main() 
{
	// 括号法
    Person p1; // 调用默认构造函数
    Person p2(10); // 调用有参构造
    Person p3(p2); // 调用拷贝构造
    
    Person p1(); // error 编译器为认为该语句为函数声明
    
    // 显示法
    Person p1;
    Pserson p2 = Pserson(10);
    Pserson p3 = Person(p2);
    
 	// 隐式转换法
    Person p1 = 10;
    Person p2 = p1;
}
```




## 深拷贝和浅拷贝

在拷贝构造函数中，默认使用的是浅拷贝，只会将属性的值拷贝到新的类中，而如果类中包含了指针类型的属性的话，浅拷贝只会将该指针的地址赋值给新的类中。

```cpp
class Student 
{
    private:
    	string name;
    	int* score;

    public:
	    ~Student()
        {
        	if(score != NULL) 
            {
                delete score;
                score = NULL;
            }    
        }
};


int main() 
{
    Student stu1;
	stu1.name = "123";
	stu1.score = new int(90);

	Student stu2(stu1);
	// stu1 和 stu2 的作用域在 main 函数中，当 main 函数结束时会调用析构函数销毁
    // 由于 Student 中的 score 为指针，并且是浅拷贝将 stu1 中的 score 地址复制给
    // 了 stu2 的 score，所以这两个 score 指向同一个地址，当 stu1 的析构函数被调
    // 用时， delete score 清空那这块堆地址，而 stu2 的析构函数又再一次使用了 
    // delete score, 导致程序崩溃, 使用深拷贝避免该问题
    return 0;
}
```

深拷贝的拷贝构造函数

```cpp
class Student 
{
    private:
    	string name;
    	int* score;

    public:
    	Student(const Student& stu) 
        {
            name = stu.name;
            score = new (*stu.score)
        }
    
	    ~Student()
        {
        	if(score != NULL) 
            {
                delete score;
                score = NULL;
            }    
        }
};
```



## 初始化列表

`构造函数(): 属性1(值1),属性2(值2)...{}`

```cpp
class Person 
{
    public:
    	int a;
    	int b;
    	int c;
    
    	Person(int x, int y) 
        {
            a = x;
            b = y;
            c = 20
        }
    
    	Person(int x): a(10), b(x) 
        {
        	c = x;    
        }
};

int main()
{
    Person p(10, 20);
    Person p(10);
}
```

## 静态成员

成员变量：

* 所有对象都共享同一份数据
* 编译阶段就分配内存
* 类内声明，类外初始化操作

```cpp
class Student
{
    public:
    	// 类内声明
    	static int m_A;
};

// 类外初始化
int Student::m_A = 10;

int main()
{
    // 访问方式
    Student s1;
    s1.m_A;
    
    Student::m_A;
}
```

成员函数：

* 所有对象共享同一个函数
* 静态成员函数只能访问静态成员变量

```cpp
class Student
{
public:
    static void say()
	{
		std::cout << m_A;
	}
};

// 类外初始化
int Student::m_A = 10;

int main()
{
    // 访问方式
	Student::say();
}
```



## 对象模型和this指针

### 成员变量和成员函数分开存储

类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上

 ```cpp
 clss Student 
 {
 	int m_A; // 非静态成员变量 属于类的对象上
     static int m_B; // 静态成员变量 不属于类的对象上
     
     void func {}; // 非静态成员函数 不属于类的对象上
     
     static void func2{}; // 静态成员函数 不属于类的对象上
 };
 ```



### this指针

this 指向被调用的成员函数所属的对象

* 当形参和成员变量同名时，可以用 this 指针区分
* 在类的非静态成员函数中返回对象本身可使用 return *this

```cpp
class Student 
{
public:
    int age;
    Person (int age) {
        this->age = age;
    }   
    
    Student& build(Student& stu){
        this->age += stu.age;
        return *this;
    }
};


```

### 空指针访问成员函数

```cpp
class Person
{
public:
    int age;
	void say(){}
    void say2(){
        age++;
    }
    void say3(){
        if (this == NULL) 
        {
            return;
        }
        age++;
    }
}

int main()
{
    Person* p = NULL;
    p->say(); // ok
    p->say2(); // error 访问到了成员属性
    p->say3(); // ok
}
```



### const 成员函数

**常函数：**

* 常函数内不可以修改成员属性
* 成员属性声明时使用 mutable 修饰后可在常函数修改

`函数返回值 函数名() const {}`

使用 const 实际上修饰的是 this 指针

**常对象：**

* 常对象只能调用常函数

在对象前加上 const 修饰

`const 类名 标识符;`

```cpp
class Person
{
public:
    int a;
    mutable int b;
    void say()
    {
        a = 10; // ok
        // this = Person* const this;
        this->a = 10; // ok
        b = 20; // ok
    }
    
    void say2() const
    {
        a = 10; // error
        // this = const Person* const this;
        this->a = 10; // error
        b = 20; // ok
        this->b = 20; // ok
    }
};

int main()
{
	Person p1;
	p1.a = 10; // ok

	const Person p2 { .a = 1, .b = 2 };
	p2.a = 10; // error
	p2.b = 10; // ok
	p2.say(); // error
	p2.say2(); // ok
	return 0;
}
```

## 友元

在程序中，有些私有属性想让类外的一些特殊函数和类进行访问就可以使用友元

`friend`

* 全局函数做友元
* 类做友元
* 成员函数做友元

```cpp
class Person
{
	// 声明全局函数为友元
	friend void fun(Person* p);
    // 声明函数为友元
	friend class Student;
    // 声明成员函数为友元
    friend void Student::fun(Person* p);
    
private:
	int age;    
};

class Student
{
    void fun(Person* p);    
};
// 类外定义函数
Student::fun(Person* p) 
{
    p->age;
}


void fun(Person* p) 
{
    p->age;
}
```



## 运算符重载

对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型

### 加号	

通过重载 `operator+` 进行实现

```cpp
class Person
{
public:
	int age;
	Person();

	Person(int age) : age(age)
	{
	}
	
    // 成员函数重载
	Person operator+(const Person& p) const
	{
		Person temp;
		temp.age = this->age + p.age;
		return temp;
	}
};

// 全局函数重载
Person operator+(const Person& p1, const Person& p2)
{
	return p1.age + p2.age;
}

int main()
{
	Person p1(10);
	Person p2(20);
	Person p3 = p1.operator+(p2);
	Person p4 = p1 + p2;
	Person p5 = operator+(p1, p2);
	Person p6 = p1 + p2;
}

```

### 左移

通过重载 `operator<<` 进行实现

`<<` 必须用全局函数重载 

在成员函数中重载的使用 `Person << cout`

在全局函数中重载的使用 `cout << Person`

```cpp
#include<iostream>

class Person
{
    // 通过友元让全局函数访问私有属性
	friend std::ostream& operator<<(std::ostream& cout, const Person& p);
    
public:
	int age;
	Person();

	Person(int age) : age(age), score(50) {}

private:
	int score;
};


std::ostream& operator<<(std::ostream& cout, const Person& p)
{
	cout << "age:" << p.age << "score:" << p.score;
	return cout;
}

int main()
{
	Person p1(10);
	Person p2(20);
	std::cout << p1 << p2;
}

```

### 递增

前置

`operator++()` `operator--()`

后置

`operator++(int)` `operator--(int)`



### 赋值

编译器默认添加到类中

`operator=`


### 关系运算符

`operator==` `operator!=`  `operator>` `operator<`

## 

### 函数调用运算符

仿函数

`operator()`

```cpp
class Student
{
public:
    int* age;
    Student(int age) 
    {
        this->age = age
    }
    void operator()(string text);
};

void Student::operator=(string text)
{
	std::cout << text << endl;
}

int main()
{
    Student stu;
    stu("Hello");
}

```



## 继承

`class 类名 : 继承方式 父类`

继承方式：

* 公共继承
* 保护继承
* 私有继承

![image-20251226161844302](./.assets/image-20251226161844302-1766737129362-1.png)

### 构造与析构顺序

父类构造 -> 子类构造

子类析构 -> 父类析构



### 同名成员的处理

使用作用域

`子类.父类::父类成员属性`

`子类.父类::父类函数()`

> 如果子类中出现与父类同名的函数，那么父类的所有同名的函数都会被隐藏，不会被重载



### 同名静态成员的处理

`子类::父类::父类静态成员属性`

`子类::父类::父类静态函数()`



### 多继承

`class 子类 : 继承方式 父类1, 继承方式 父类2`

实际开发不建议使用



### 菱形继承与虚继承

假设有一个父类 `Base`，其中有成员属性 `int x`

其下有两个不同的子类 `ABase1` `ABase2`

这两个子类又被子类 `BBase` 继承

这种关系称为菱形继承，`BBase` 同时有了 `ABase1` 和 `ABase2` 的共同父类 `Base` 的成员属性 `x`，在使用时出现了二义性，并且`BBase`有了两份 `x`，易造成资源浪费。

**使用虚继承解决**

`class ABase1 : virtual public Base` 

`class ABase2 : virtual public Base`

`class BBase : public ABase1, public ABase2`

这样在实际的继承中，`BBase` 就只有一份`x`了



## 多态

* 静态多态：函数重载、运算符重载
  * 编译阶段确定函数地址
* 动态多态：派生类和虚函数
  * 运行阶段确定函数地址

动态多态使用

父类的指针或引用指向子类对象，并且进行函数重写



```cpp
class Animal
{
public:
    void speak() {}
    virtual void speak2() {}
};

class Cat : public Animal
{
public:
    void speak() {}
    void speak2() {}
};

void doSpeak(Animal& a)
{
    a.speak(); // Animal speak  在编译时地址就被绑定为 Animal 的函数
    a.speak2(); // Cat speak    在运行时才会进行地址绑定为实参类型的函数
}

int main()
{
    Cat cat;
    doSpeak(cat);
}
```



### 纯虚函数与抽象类

纯虚函数 `virtual 返回值类型 函数名 (参数列表) = 0;`

当一个类中有纯虚函数时，这个类就是抽象类

* 抽象类无法实例化
* 抽象类的子类必须重写父类中的纯虚函数

```cpp
class Base
{
public:
    virtual void func() = 0;
};
```



### 虚析构和纯虚析构

在多态使用时，父类指针指向子类才有多态，但父类指针在释放时无法调用子类的析构函数

解决方法：父类中使用虚析构或纯虚析构，让子类重写该函数



**纯虚析构需要声明和实现**

使用类外实现纯虚析构



# 文件操作

文件操作流 `<fstream>`

* 文本文件
* 二进制文件



* ofstream： 写操作
* ifstream：读操作
* fstream：读写操作



## 文本文件

### 写

`ofstream`

文件打开方式

* ios::in：读
* ios::out：写
* ios::ate：初始位置在文件尾部
* ios::app：追加
* ios::trunc：文件存在则删除再创建
* ios::binary：二进制方式

**使用完毕使用`close()`关闭流**

```cpp
#include <fstream>

int main ()
{
    ofstream ofs;
    // 读取文件
    ofs.open("文件路径", ios::in | ios::out); // 读写方式打开文件
    ofs << "Something" << endl;
    
    ofs.close();
}
```



### 读

`ifstream`

文件读取方式

* 使用 `>>` 输出
* `ifs.getline(buf, sizeof(buf))`
* 使用公共函数`getline(ifstream, string)`
* `ifs.get()` 读取一个字符

**使用完毕使用`close()`关闭流**

```cpp
#include <fstream>

int main ()
{
    ifstream ifs;
    // 读取文件
    ifs.open("文件路径", ios::in);
    
    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }
    
    char buf[1024] = {0};
 	// 第一种读取方式
    while (ifs >> buf) 
    {
        cout << buf << endl;
    }
    
    // 第二种读取方式
    while (ifs.getline(buf, sizeof(buf))) 
    {
        cout << buf << endl;
    }
    
    // 第三种
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }
    
    // 第四种
    char c;
    while ( (c = ifs.get()) != EOF )
    {
        cout << c << endl;
    }
    
    ifs.close();
}
```



## 二进制文件

以 `ios::binary` 打开文件



### 写入对象

```cpp
#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
    char name[64];
    int age;
};

int main()
{
    ofstream ofs;

    ofs.open("person.txt", ios::out | ios::binary);
    Person p = {.name = "张三", .age = 18 };
      ofs.write( (const char*)&p, sizeof(p));

    ofs.close();
}
```



# 模板

`template <typename T>`

声明一个范型

## 模板函数

```cpp
template <typename T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}
```

