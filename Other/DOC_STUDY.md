> from: <https://www.studycpp.cn>
>
> **本笔记为阅读文档学习，仅为知识补充与扩展**

---

# 一、基础知识

---

## 变量初始化和赋值

### 初始化

C++中有6种变量初始化方法

```cpp
int a;         // 默认初始化
int b = 5;     // 拷贝初始化 将右值拷贝到左侧变量中
int c( 6 );    // 直接初始化 用于更有效的初始化复杂对象

// 列表初始化 (C++11引进) 
// 列表初始化的检查更严格，不允许缩小转换范围
int d { 7 };   // 直接列表初始化
int e = { 8 }; // 拷贝列表初始化
int f {};      // 值列表初始化

int width { 4.5 }; // error
int width = 4.5;   // 4
```

> 列表初始化又称为**统一初始化**
>
> 在引入列表初始化前，某些类型的初始化需要使用拷贝初始化，而其他类型的初始化则需要使用直接初始化。引入列表初始化是为了提供在大多数情况下都有效的更一致的初始化语法。

# 二、函数

函数是一个可重用的语句序列，旨在完成特定工作

## 命名空间

# 十二、复合类型

## 引用

引用是对现有对象的别名。定义引用后，对引用的任何操作都将应用于被引用的对象。



### 值类别

在C++中值分为左值(lvalue)和值(rvalue)

左值计算为可识别对象或函数的表达式（实体）

```C++
int main()
{
    int x { 5 };
    int y { x }; // x 是左值表达式

    return 0;
}
```



右值为非左值的表达式，右值表达式计算为一个值。

右值是不可识别的，并且仅存在于它们的表达式的范围内。

```C++
int return5()
{
    return 5;
}

int main()
{
    int x{ 5 }; // 5 是右值表达式
    const double d{ 1.2 }; // 1.2 是右值表达式

    int y { x }; // x 是可修改的左值表达式
    const double e { d }; // d 是不可修改的左值表达式
    int z { return5() }; // return5() 是右值表达式 expression (因为它的结果是按值返回)

    int w { x + 1 }; // x + 1 是右值表达式
    int q { static_cast<int>(d) }; // static_cast的结果是右值表达式

    return 0;
}
```



### 左值引用

`数据类型 & 标识符 = 变量名;`

引用是对象的别名。定义引用后，对引用的任何操作都将应用于被引用的对象。

可以使用引用来读取或修改被引用的对象。

* 所有左值引用必须在定义时初始化
* 左值引用必须绑定到可修改的左值
* 在大多数情况下，引用的类型必须与被引用的类型匹配
* 引用无法重置/更改为另一个对象



使用 `&` 获取引用



使用左值引用变量

```cpp
#include <iostream>

int main()
{
    int x { 5 };    // x 是普通的int类型变量
    int& ref { x }; // ref 是int类型的左值引用变量，充当变量x的别名

    std::cout << x << '\n';  // 打印 x (5)
    std::cout << ref << '\n'; // 打印 x 通过 ref (5)

    return 0;
}
```

通过左值引用修改值

```C++
#include <iostream>

int main()
{
    int x { 5 }; // 普通int变量
    int& ref { x }; // ref 现在是 x 的别名

    std::cout << x << ref << '\n'; // 打印 55

    x = 6; // x 现在值是 6

    std::cout << x << ref << '\n'; // 打印 66

    ref = 7; // 对引用的对象（x）现在值是 7

    std::cout << x << ref << '\n'; // 打印 77

    return 0;
}
```



### const的左值引用

常量左值只能被常量左值引用所引用



```C++
int main()
{
    const int x { 5 };    // x 是不可修改的左值
    const int& ref { x }; // okay: ref 可以引用到x
	
    // 常量左值引用也无法被修改
    // ref = 10; error
    
    return 0;
}
```

常量左值引用可以引用可修改的对象，当常量左值引用依然无法被修改

### 作为函数参数使用

一般如下函数：

```cpp
int add(int x, int y) 
{
    return x + y;
}
```

该函数在传参时使用的是指传参，会将传入的实参拷贝至形参。

如果但参数为复杂对象时，会造成很大的使用成本。



#### 使用引用传参

使用引用传参将会传入实参地址，而不会拷贝新的实参

~~~cpp
#include <iostream>
#include <string>

void printValue(std::string& y) // 类型更改为 std::string&
{
    std::cout << y << '\n';
} // 变量y这里被销毁

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x 现在按引用传递给参数 y (代价小)

    return 0;
}
~~~



通过引用也可以在函数中修改该实参的值

非引用：

```C++
#include <iostream>

void addOne(int y) // y 是 x 的拷贝
{
    ++y; // 修改的是 x 的拷贝, 而不是 x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x 未被修改

    return 0;
}
```

~~~cmd
value = 5
value = 5
~~~



使用引用：

```C++
#include <iostream>

void addOne(int& y) // y 被绑定到原始的 x
{
    ++y; // 修改的实际是 x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x 被修改了

    return 0;
}
```

~~~cmd
value = 5
value = 6
~~~



#### 使用常量引用传参

```C++
#include <iostream>

void printValue(const int& y) // y 是常量引用
{
    std::cout << y << '\n';
    y--; // error
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x 是可修改的左值

    const int z { 5 };
    printValue(z); // ok: z 是不可修改的左值

    printValue(5); // ok: 5 是右值

    return 0;
}
```



## 指针

`数据类型 * 标识符 = &变量名;`

使用 `&` 进行取地址

使用 `*` 进行解引用获取该地址存储的值

```cpp
int x{ 5 };
std::cout << x << '\n';  // 打印变量 x 的值
std::cout << &x << '\n'; // 打印变量 x 的地址
std::cout << *(&x) << '\n'; // 打印变量x的存储地址内的值
```

### 指针初始化

* 如果指针在初始化时未指定一个地址，则会变为野指针
* 如果进行空值初始化则指向 nullptr

~~~cpp
int x{ 5 };

int* ptr;        // 未初始化的指针 (包含一个垃圾地址)
int* ptr2{};     // 空指针
int* ptr3{ &x }; // 指向变量 x 地址的指针
~~~

### 指针赋值

* 改变指针所指向的对象，为指针赋值一个新的地址
* 改变指针执行对象的值，使用解引用为所指对象赋值

```C++
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr 初始化指向 x

    std::cout << *ptr << '\n'; // 打印ptr指向的值 (x)

    int y{ 6 };
    ptr = &y; // // 将ptr 指向 y

    std::cout << *ptr << '\n'; // 打印ptr指向的值 (y)

    return 0;
}
```

### 指针和引用

1. 引用必须初始化，指针不需要初始化。
2. 引用不是一个单独的对象，指针是。
3. 无法重新设置引用（更改为引用其他内容），指针可以更改它们所指向的内容。
4. 引用必须始终绑定到对象，指针可以指向空。
5. 引用是“安全的”（除了悬空引用之外），指针本身就是危险的。

### 悬空指针

悬空指针是保存了不再有效的对象地址的指针

对悬空指针进行解引用会导致未定义的行为

### 指针与常量

#### 常量指针

可以用于指向常量，并且无法修改指向的地址中的值，但可以修改指向的地址

```C++
int main()
{
    int x{ 5 }; // non-const
    const int* ptr { &x }; // ptr 指向 "const int"

    *ptr = 6;  // 不被允许: ptr 指向 "const int" ，所以不能通过ptr修改指向的对象
    x = 6; // ok: x是非const，所以仍然可以通过 x 这个标识符来修改实际的对象

    return 0;
}
```

#### 指针常量

表示该指针为常量不可修改其指向的地址，但可以修改其指向的值

```C++
int main()
{
    int x{ 5 };
    int y{ 6 };

    int* const ptr { &x }; // okay: const指针ptr被初始化为 x 的地址
    ptr = &y; // 错误: 初始化完成后，指针常量不能修改

    return 0;
}
```

#### 指向常量的指针常量

该指针既不可以修改指向的地址也不可用修改指向的值

```C++
int main()
{
    int value { 5 };
    const int* const ptr { &value }; // const指针，指向const对象

    return 0;
}
```

### 作为函数参数使用

在传参时非指针需要使用`&`获取指针

```cpp
#include <iostream>
#include <string>

void printByAddress(const std::string* ptr) // 函数参数是 str 的地址
{
    std::cout << *ptr << '\n'; // 通过解引用指针打印
}

int main()
{
    std::string str{ "Hello, world!" };
    
    printByAddress(&str); // 通过地址传递str，不会制作副本

    return 0;
}
```

#### 在函数中修改传入指针的地址

当向函数传递地址时，该地址将赋值到指针形参中

```C++
#include <iostream>

// ptr被赋值但未被使用，[[maybe_unused]]让编译器不要告警
void nullify([[maybe_unused]] int* ptr2) 
{
    ptr2 = nullptr; // 将ptr指向空指针
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr 指向 x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
```

因为是复制传递，所以实际无法修改 ptr 指向的地址

```cpp
ptr is non-null
ptr is non-null
```

需要使用引用的方式传递指针才能修改指针的指向

```C++
#include <iostream>

void nullify(int*& refptr) // refptr 现在是指针的引用
{
    refptr = nullptr; // 传入的指针，指向nullptr
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr 指向 x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
```

```C++
ptr is non-null
ptr is null
```

## 引用或指针作为函数返回值

在函数返回时也会向传参一样就行拷贝返回，如果返回类型为对象的话成本会很高

将引用或指针作为返回可以避免这种情况

```cpp
std::string returnByValue(); // 返回值是 std::string 的拷贝 (昂贵)
std::string&       returnByReference(); // 返回一个已经存在的 std::string 的引用 (代价低)
const std::string& returnByReferenceToConst(); // 返回一个已经存在的 std::string 的const引用 (代价低)
```

### 使用引用

```C++
#include <iostream>
#include <string>

const std::string& getProgramName() // 返回一个 const 引用
{
    static const std::string s_programName { "Calculator" }; // 静态存储期, 程序结束后才会销毁

    return s_programName;
}

int main()
{
    std::cout << "This program is named " << getProgramName();

    return 0;
}
```

当使用引用作为返回值时，需要确保返回的被引用对象的生命周期要长于该函数

以下函数中，`programName` 的声明周期是函数结束就销毁，但返回该对象的引用时，因为其被销毁了所以该引用也变为了悬空引用

```C++
#include <iostream>
#include <string>

const std::string& getProgramName()
{
    const std::string programName { "Calculator" }; // 现在是一个普通的局部变量, 函数结束后销毁

    return programName;
}

int main()
{
    std::cout << "This program is named " << getProgramName(); // 未定义的行为

    return 0;
}
```

### 生命周期扩展不能跨函数边界

```C++
#include <iostream>

const int& returnByConstReference()
{
    return 5; // 返回临时对象的const引用
}

int main()
{
    const int& ref { returnByConstReference() };

    std::cout << ref; // 未定义的行为
    return 0;
}
```

在上述函数中，5为字面量，而该函数需要返回 `const int&`，所以在返回时会创建并返回对5的引用对象，但5是一个函数内的局部变量，在函数执行后销毁了，所以 ref 会是悬空引用
