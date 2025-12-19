FROM: 朝夕教育

# 文件结构

**Headers**：首文件（头文件），描述一个类，一个文件元素清单；

**Sources**：源文件（主文件），主要的代码；



## #include

文件包含命令

#include 是C语言预处理命令的一种，用来引入对应的头文件

* 预处理：在编译时决定，而不是执行时

* `#include <>`: 先在系统路径中查找引入的文件，找不到再在自定义目录中查找

* `#include ""`: 先在自定义目录中查找引入的文件，找不到再到系统路径中查找

## 重复引用

有如下代码结构：

```cpp
// class1.cpp
class Clazz1 {};

// class2.cpp
#include "class1.cpp"

class Clazz2 {};

// main.cpp
#include "class1.cpp"
#include "class2.cpp"
```

在 `main.cpp` 中发生了重复引用

`main.cpp` 引用了 `class1.cpp` `class2.cpp`，`class2.cpp` 引用了 `class1.cpp`，而 `main.cpp` 又通过引用 `class2.cpp` 间接应用了 `class1.cpp` 导致了重复引用



## #ifdef-define-endif 与 #pragma once

用于防止同一个文件在编译时被重复包含和编译，引起多重定义的问题

* `ifndef`: if not defined
* `ifdef`: if defined
* `define`: 定义
* `endif`: 结束

```cpp
// class1.cpp
#ifndef _Clazz1_Public
#define _Clazz1_Public

class Clazz1 {};

#endif

// class2.cpp
#ifndef _Clazz2_Public
#define _Clazz2_Public
#include "class1.cpp"

class Clazz2 {};

#endif

// main.cpp
#include "class1.cpp"
#include "class2.cpp"
```



* `#pragma once`

```cpp
// class1.cpp
#pragma once

class Clazz1 {};

// class2.cpp
#pragma once

class Clazz2 {};

// main.cpp
#include "class1.cpp"
#include "class2.cpp"
```



# 数据类型

C++是强类型语言

数据类型决定了变量怎么在内存中存储与解析



## 内存和数据类型的关系

![image-20251218220143203](.assets/image-20251218220143203.png)



## 基础类型

`sizeof`: 获取类型所占字节数

`numeric_limits<TYPE>`: 通过`TYPE`泛型获取对应类型的最大最小值

```cpp
sizeof(int) // 4

numeric_limits<int>::max; // 2147483647
numeric_limits<int>::min; // -2147483648
```



## 枚举

用于声明一些固定长度的数据

**枚举默认初始值**

```cpp
enum color
{
  RED, GREEN, BLUE  
};

cout << RED << endl; // 0 输出枚举定义时的下标顺序
cout << GREEN << endl; // 1
```



**枚举手动初始化**

```cpp
enum color
{
  RED = 1, GREEN = 2, BLUE  
};

cout << RED << endl; // 1
cout << GREEN << endl; // 2
```

```cpp
// 枚举可以用于类型声明
color car = RED;

// 也可用于类型赋值与赋值后计算
int num = RED;
num++;
// 但无法单独进行计算
RED++; // 错误

// 只能使用枚举中定义的值
color car = YELLOW; // 错误  枚举没有定义YELLOW
// 自定义一个枚举变量
color color1 = color(1);

// 循环遍历枚举
for (color e : {RED, GREEN, BLUE}) 
{
    cout << e << endl;
}
```



## 字符和字符串

字符串实际是使用 `null` 字符 `\0` 终止的一维字符数组，字符数组的末尾会存储一个空字符

```cpp
// C 的使用方式
char ch[7] = {'A', 'B', 'C', 'D', 'E', 'F', '\0'};
cout << ch << endl; // ABCDEF

// C++ 的使用方式
char str1[] = "runoob";
char str2[] = "google";
char str3[];

strcpy(str3, str1); // 将 str1 复制到 str3
strcat(str1, str2); // 将 str1 和 str2 拼接
strlen(str1); // 计算字符串长度

// 使用 C++ 的字符串类型
#include <string>
string str1 = "runoob";


```

## 日期和时间

`ctime` 库

```cpp
#include <ctime>
// 获取 1970-1-1 至今的秒数
time_t now = time(0);
// 转为字符串
char* dt = ctime(&now); // 获取本地日期和时间

// 转为 tm 结构 时区日期时间
tm* gmtm = gmtime(&now);
dt = asctime(gmtm); // UTC 时间

// 转为 localtime
tm* ltm = localtime(&now);

// 可以拆解成不同的时间维度
ltm->tm_year; // 年
ltm->tm_mon;  // 月
ltm->tm_day;  // 日
ltm->tm_hour; // 时
ltm->tm_min;  // 分
ltm->tm_sec;  // 秒
```

## 常量

定义一个不可修改的值

常量：`const 数据类型 常量名 = 常量值`

宏常量：`#define 常量名 常量值`
