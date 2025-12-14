﻿﻿# C++

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

[查看源码](4、程序流程结构/02_switch.cpp "switch ")

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
while(num < 10) {
    cout << "num = " << num << endl;
    num++;
}
```

