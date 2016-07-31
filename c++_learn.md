## 变量和基本类型
* `endl`称为操作符的特殊值，写入`endl`的效果是结束当前行，并将与设备有关联的缓冲区中的内容刷到设备中。
* `::`作用域运算符
* 当我们使用一个`istream`对象作为条件时，其效果是检测流的状态，当遇到**文件描述符**或遇到一个无效输入时，`istream`对象的状态才会变成无效。
* `short`短整型 16位
* `int`整型 16位
* `long`长整型 32位
* `long long`长整型 64位
* `float` 单精度浮点数 6位有效数字
* `double` 双精度浮点数 10位有效数字
* `long double` 扩展精度浮点数 10位有效数字
* 当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数。
* 当我们赋给带符号类型一个超出它表示范围的值时，结果是**未定义的**，此时程序可能继续工作、可能崩溃、也啃呢个生成垃圾数据
* 编译器在每个字符串的结尾处添加一个空白符`\0`,因此，字符串字面值的实际长度要比它的内容多1
* `对象`是指一块能存储数据并具有某种类型的内存空间
* `C++`语言将声明和定义区分开来。`声明`使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。`定义`负责创建与名字关联的实体。
* 如果想声明一个变量而非定义它，就在变量名前添加关键字`extern`，而且不要显示地初始化变量`extern int i;`
* 任何包含了显示初始化的声明即成为定义`extern double pi = 3.13;`定义
* `c++`标识符必须由字母、数字、下划线组成，必须以字母或下划线开头
* `引用`必须初始化，否则会报错
* 定义引用时，程序把引用和它的初始值绑定在一起，而不是将初始值拷贝给引用。
* **引用即别名**
* 指针无须在定义时赋初值。在块作用域内定义的指针如果没有被初始化，也将拥有一个不确定的值。
* `建议：`初始化所有指针，如果实在不清楚指针应该指向何处，就把它初始化为nullptr或0，这样程序就能检测并知道它没有任何具体的对象了
* `vodi*`是一种特殊的指针类型，可以用于存放任意对象的地址。
* 一切对象都存在引用
* 指向指针的引用 `int *&r = p;//r是一个对指针p的引用`
* 要想存放常量对象的地址，只能使用常量的指针。
* `*const`表示常量指针
* **常量指针**`int *const p1 = &i2`不改变p1的值
* **指向常量的指针**`const int *p2 = &ci`允许改变p2的值，但是*p2的值不变
* 定义类型别名`typedof`,`typedof double wages`wages是double的同义词
* `#define`指令把一个名字设定为预处理变量
* `#ifdef`当且仅当变量已定义时为真
* `ifndef`当且仅当变量未定义时为真，一旦检查结果为真，则执行后续操作直至遇到`#endif`指令为止
## 字符串、向量和数组
* `拷贝初始化`使用等号初始化一个变量
* `直接初始化`不使用等号
* `string`中的`getline(is,s)`表示从is中读取一行赋给s，返回is
* `string`对象会自动忽略开头的空白，并从第一个真正的字符开始读起，直到遇见下一处空白为止
* `string.empty()`若为空则返回`true`，非空返回`false`
* `string`类型的相加，必须确保每个加法运算符的两侧的运算对象至少又一个是`string`
* `cctype`头文件 主要用于处理单独的字符
* `for`语句处理单独字符

        for( declaration: expression )
            statement
        //eg
        string str("some thing");
        for( auto c: str ){
            //..            
        }
* `string::size_type`类型，也就是无符号类型
* `vector`对象之间的拷贝，一定要类型相同
* 要想列表初始化`vector`对象，花括号里的值必须与元素类型相同

        // v1有一个元素，其值为10
        vector<int> v1{10};
        // v2有10个默认初始化的值
        vector<string> v2{10};
        // v3有10个值为"hi"的值
        vect(or<string> v3{10,"hi"};
* `push_back()`给`vector`对象尾部增加元素
* 如果循环体内部包含有向`vector`对象添加元素的语句，则不能使用范围`for`循环(范围`for`循环内不应该改变其所遍历序列的大小)
* 所有标准库容器和字符类型都可以使用迭代器
* `begin`成员负责返回指向第一个元素的迭代器
* `end`成员负责返回指向最后一个元素的迭代器
* 标准容器迭代器的运算符

    * `*iter`返回迭代器iter所指元素的引用
    * `iter->mem`解引用iter并获取该元素的名为mem的成员函数等价于`(*iter).mem`
    * `++iter`/`--iter`令`iter`指示容器中的下一个元素/上一个元素
    
* 不能将数组的内容拷贝给其他数组作为其初始值，也不能用数组为其他数组赋值
* 默认情况下，类型修饰符从右向左依次绑定
        
        //从右向左，首先定义的是一个大到位10的数组，名字是ptrs，然后知道数组中存放的是指向int的指针
        int *ptrs[10];
        //parray指向一个含有10个整数的数组,从内到外观察
        int (*parray)[10] = &arr;
        //arrRef引用一个含有10个整数的数组
        int (&arrRef)[10] = arr;
* 在使用数组下标的时候，通常将其定义为`size_t`类型，`size_t`是一种机器相关的无符号类型，它被设计的足够大以便能表示内存中任意对象的大小，头文件为`stddef.h`
* 标准库函数`begin`和`end`，`begin`函数返回指向数组首元素的指针，`end`函数返回指向数组尾元素下一位置的指针，头文件为`iterator`

        int ia[] = {0,1,2,3,4};
        int *beg = begin(ia); //指向ia首元素的指针
        int *last = end(ia); //end函数指向ia尾元素下一位置的指针
* 两个指针相减的结果的类型是一种名为`ptrdiff_t`的标准库类型，和`size_t`一样
* `char *const cp`和`const char *p`,前者是cp不变，指向字符的指针常数，const指针，后者是定义一个指向字符常数的指针，cp可变，字符不可变。
* m%(-n)等价于m%n,(-m)%n等于-(m%n)
* `垂悬else`当`if`分支多于`else`分支，c++会规定else与离它最近的未匹配的if匹配，从而消除程序的二义性。解决方法为花括号
* `pair`模版类型，`pair<string, int>`的成员有`first`和`second`两个，对应两个参数。也可以是`pair<int, string>`,头文件为`string`
* `throw表达式`，异常检测部分使用`throw`表达式来表示它遇到了无法处理的问题。我们说`throw`引发了异常
* `try语句块`异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个`catch子句`结束。
* 标准异常的头文件`exception`、`stdexcept`、`new`、`type_info`,(c++ primer 176页)
* **函数的返回类型**不能是数组类型或函数类型，但是可以是指向数组或函数的指针
* `自动对象`只存在于块执行期间的对象
* `局部静态对象`在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁，在此期间忌食对象所在的函数结束执行也不会对它有影响

        size_t count_calls () {
            static size_t ctr = 0;
            return ++ctr;
        }
     
        int main() {
            for (size_t i = 0; i < 10; ++i) {
                cout << count_calls() << endl;
            }
            return 0;
        }
* 当形参是引用类型时，我们说它对应的实参被`引用传递`或者函数被`传引用调用`
* 当实参的值被拷贝给形参时，形参和实参是两个独立的对象，我们说这样的实参被`值传递`或者说函数被`传值调用`
* 当用实参初始化形参时会忽略掉顶层`const`
* 不能用指向`const int`对象的指针初始化`int *`

        void reset(int *p){ // ...}
        int i = 42;
        const int ci = i;
        reset(&ci); //错误
* 尽量使用常量引用,把函数不会改变的形参定义成常量引用
* 易犯错误

        string:size_type find_char(string &s,string::size_type &occurs);
        //下面会报错
        find_char('hello world',ctr);//只能作用域string对象
        //改成
        string:size_type find_char(const         string &s,string::size_type &occurs);
   
* 当我们为函数传递一个数组时，实际上传递的是指向数组首元素的指针
* 指针引用了`begin()`和`end()`标准库函数，表示头指针和尾指针
* 二维数组作为参数，`void print(int (*matrix)[10])`等价于`void print(int matrix[][10])`
* 如果函数的实参数量未知但是全部实参的类型都相同，我们可以使用`initializer_list`类型的形参，定义在头文件`initializer_list`中

        //sum({1,2,3,4})
        int sum ( initializer_list<int> lis ) {
            int s = 0;
            for (auto beg = lis.begin(), end = lis.end(); beg != end; beg++) {
                s += *beg;
            }
            return s;
        }
* 因为数组不能被拷贝，所以函数不能返回数组，所以函数一般返回数组的指针或引用
* 如果我们想定义一个返回数组指针的函数，则数组的维度必须跟在函数名字之后。然而，函数的形参列表也跟在函数名字后面且形参列表应该先于数组的维度`Type (*function(params_list))[dimension]`
* 解析 `int (*func(int i))[10]` 

    * func(int i) 表示调用func函数时需要一个int类型的实参
    * (*func(int i))意味着我们可以对函数调用的结果执行解引用操作
    * (*func(int i))[10]表示解引用func的调用将得到一个大小是10的数组
    * int (*func(int i))[10]数组为类型为整型
* 如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载函数
* 不允许两个函数除了返回类型外其他所有的要素都相同
* `const_cast`可以进行强制类型转换
* `重载与作用域`，如果我们在内层作用域中声明名字，他将隐藏外层作用域中声明的同名实体。在c++中，名字查找发生在类型检查之前。
* 默认实参，一旦某个形参被赋予了默认值，它**后面**的所有形参都必须有默认值`string screex(int ht = 24, int wid = 80);`使用默认实参调用函数时，只能省略尾部的实参，所以一般将经常使用默认值的形参出现在后面
* 在给定的作用域中一个形参只能被赋予一次默认实参
* 内联函数可避免函数调用的开销，将函数指定为内联函数(inline)，通常就是将它在每个调用点上"内联地"展开
* 把内联函数和`constexpr`函数放在头文件内
* `char`可以类型提升为`int`
* 当我们把函数名作为一个值使用时，该函数自动地转换成指针

        bool lengthCompare( const string &, const string & );
        bool (*pf)(const string &,const string &);
        //使用函数指针
        pf = lengthCompare;
        //pf = & lengthCompare;
        //直接使用指向函数的指针调用该函数
        bool b1 = pf('hello','world');
        //bool b2 = (*pf)('hello','world');
        //bool b3 = lengthCompare('hello','world');
* 返回指向函数的指针

        using F = int (int*,int);//F是函数类型，不是指针
        using PF = int(*)(int *,int);//PF是指针类型
        PF f1(int);//正确：PF是指向函数的指针，f1是返回指针函数的指针
        F *f1(int)
        //等价于
        int (*f1(int))(int*,int);
        //分析
        //f1有形参列表，f1是个函数
        //f1前面有* f1返回的是一个指针
        //指针的类型本身也有形参列表，因此指针指向函数，该函数的返回类型是int
        
## 类
* 类的基本思想是**数据抽象**和**封装**。数据抽象是一种依赖于**接口**和**实现**分离的编程技术。封装实现了类的接口和实现的分离。封装后的类隐藏了它的实现细节，也就是说，类的用户只能使用接口而无法访问实现部分。

        struct Sales_data
        {
            string isbn() const { return bookNo;};
            Sales_data& combine ( const Sales_data& );
            double avg_price () const;
            string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
        };

* 引入const成员函数`string isbn() const {return bookNo}`,`const`的作用就是修改隐式this指针的类型，默认情况下，this的类型是指向类类型非常亮版本的常量指针。意味着我们不能把this绑定到一个常量对象上去，这一情况使得我们不能在一个常量对象上调用普通的成员函数。若在函数体内不会改变this所指的对象，所以把this设置为指向常量的指针有助于 提高函数的灵活性。
* 在类的外部定义成员函数，需要使用作用域运算符

        double Sales_data::avg_price() const {
            //...
        }
* 定义一个返回`this`对象的函数

        Sales_data& Sales_data::combine(const Sales_data &rhs) {
            units_sold += rhs.units_sold;
            revenue += rhs.revenue;
            return *this;
        }
* 一般来说，如果非成员函数是类接口的组成部分，则这些函数的声明应该与类在同一个头文件内。
* 类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做`构造函数`.构造函数的任务是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数。
* `构造函数`的名字和类名相同。没有返回类型，可以重载，不能被声明称const，因为当我们创建一个const对象时，直到构造函数完成初始化过程，对象才能真正取得其"常量"属性，因此，构造函数在const对象的构造过程中可以向其写值。
* 只有当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数
* 定义构造函数

        struct Sales_data
        {
            //新增的构造函数
            Sales_data() = default; //默认构造函数
            Sales_data(const string &s): bookNo(s) { }
            Sales_data(const string &s, unsigned n, double p ): bookNo(s), units_sold(n), revenue(p*n) { }
            Sales_data(std::istream &);//类的外部定义构造函数
            //之已有的其他成员
            string isbn() const { return bookNo;};
            Sales_data& combine ( const Sales_data& );
            double avg_price () const;
            string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
        };
        Sales_data::Sales_data(std::istream &is){
            read( is, *this );
        }
* 使用`class`和`struct`定义类唯一的区别就是默认的访问权限
* 封装是从接口上实现的分离。它隐藏了一个类型的实现细节，封装是通过实现一个类的私有部分的执行
* 类可以允许其他类或者函数访问它的非公有成员，方法是令其它类或者函数成为它的`友元`,如果类想把一个函数作为它的友元，只需要增加一条以`friend`关键字开始的函数声明语句即可

        class Sales_data {
        // 为Sales_data的非成员函数所做的友元声明
        friend Sales_data add(const Sales_data &, const Sales_data &);
        friend std::istream &read(std::istream &is, Sales_data &item);
        friend std::ostream &print(std::ostream &os, const Sales_data &item);
        public:
            Sales_data() = default;
            Sales_data(const std::string &s):bookNo(s) { }
            Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
            Sales_data(std::istream &is) { read(is, *this); }
            std::string isbn() const { return bookNo; };
            Sales_data& combine(const Sales_data&);
        private:
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
        };
* 一般来说，最好在类定义开始或结束前的位置集中声明友元
* `vector<Screen> screens{Screen(24,80,' ')};`
* 非常量版本的函数对于常量对象是不可用的，所以我们只能在一个常量对象上调用const成员函数
* 在非常量对象上调用常量版本或非常量版本，但显然此时非常量版本是一个更好的匹配
* 每个类定义了唯一的类型，对于两个类来说，即使它们的成员完全一样，这两个类也是两个不同的类型
* 隐式内联函数是指函数定义在类的内部，显式外联函数是指要用关键字`inline`并且函数声明在类的内部，定义在类的外部
* 如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非公有成员在内的所有成员。

        class Screen {
            friend class Window_mgr;
            //Window_mgr可以访问Screen类内的成员函数
        }      
* 友元关系不具有传递性，每个类负责控制自己的友元类或友元函数
* 令成员函数作为友元

        class Screen {
            friend void Window_mgr::clear();
            //要明确指出是哪个类
        }
        // 按照如下方式设计程序
        //先定义Window_mgr类，其中声明clear啊函数，但是不能定义它
        //接下来定义Screen，包括对clear的友元声明
        //最后定义clear,此时它才可以使用Screen的成员
* 一般来说，内层作用域可以重新定义外层作用域中的名字，即使该名字已经在内层作用域中使用过。但是，如果成员使用了外层作用域中的某个名字，而该名字代表一种类型，则类不能在之后重新定义该名字。

        typedof double Money;
        class Account {
        public:
            Money balance() { return bal; } //外层
        private:
            typedif double Money; //错误：不能重新定义Money
        }
* 静态数据成员必须在类的外部定义和初始化每个静态成员，类似于全局变量，静态数据成员定义在任何函数之外，因此一旦他被定义，就将一直存在于程序的整个生命周期中
* 静态成员和指针成员可以是不完全类型

        
        class Bar {
        public:
            //...
        private:
            static Bar mem1; //true:静态成员可以是不完全类型
            Bar *mem2; //true:指针成员可以是不完全类型
            Bae mem3;//false:数据成员必须是完全类型
        }
* 静态成员可以做默认实参
* `static double rate = 6.8;`

    **错误**`static constexpr double rate 6.8;`
## IO类
* `iostream`定义了用于读写流的基本类型，`fstream`定义了读写明明文件的类型，`sstream`定义了读写内存`string`对象的类型

    |    头文件     |       类型     |      类型     |
    | ------------ | ------------- | ------------  |
    | iostream     | istream       | wistream      |
    | iostream     | ostream       | wostream      |    
    | iostream     | ostream       | wostream      |
    | fstream      | ifstream      | wifstream     |
    | fstream      | ofstream      | wofstream     |
    | fstream      | fstream       | wfstream      |
    | sstream      | isstream      | wistringstream|
    | sstream      | osstream      | wostringstream|
    | sstream      | stringstream  | stringstream  |
* IO对象无拷贝或赋值，因此我们不能将形参或返回类型设置为流类型。进行IO操作的函数通常以引用方式传递和返回流。读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的
* `strm::badbit` 用来指出流已崩溃，`strm::failbit`用来指出一个IO操作失败了，`strm::eofbit`用来指出流到达了文件结束,`strm::goodbit`用来指出流未处于错误状态，`s.eof()`若流s的eofbit置位，则返回true,`s.fail()`若流s的failbit或badbit置位，返回true，`s.good()`处于有效状态返回true,`s.clear()`将流s中的所有条件状态位复位，将流的状态设置成有效，`s.clear(flags)` ,根据给定的flags标识位，将流s中对应条件状态位复位。`s..setstate(flags)`根据给定的flags标识位，将流s中对应条件状态位置位，`s.rdstate()`返回流s的当前条件状态
* `endl`完成换行并刷新缓冲区的工作，`flush`刷新缓冲区，但不输出任何额外的字符，`ends`向缓冲区插入一个空字符，然后刷新缓冲区，如果想在每次输出操作后都刷新缓冲区，可以使用`unitbuf`操纵符，告诉流接下来的每次写操作之后都进行一次flush操作，`nounitbuf`操作符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制
* 
操作          | 说明 
------------ | -------------
fstream fstrm | 创建一个未绑定的文件流，fstream是头文件fstream定义的一个类型  
fstream fstrm(s)|创建一个fstream，并打开名为s的文件，s可以是string类型，可以是一个指向c风格字符串的指针，默认的文件模式mode依赖于fstream的类型
fstream fstrm(s,mode) | 与前一个构造函数类似，但按指定mode打开文件
fstrm.open(s) | 打开名为s的文件，并将文件雨fstrm绑定，返回void
fstrm.close()| 关闭fstrm绑定的文件，返回void
fstrm.is_open()| 返回bool，指出域fstrm绑定的文件时否成功打开并且尚未关闭
## 顺序容器
* `vector`可变大小数组，支持快速随机访问。在尾部之外的位置插入和删除元素可能很慢
* `deque`双端队列。支持快速随机访问。在头尾位置插入删除速度很快
* `list`双向链表。只支持双向顺序访问。在list中任何位置进行插入和删除操作速度都很快
* `forward_list`单向链表。只支持单向顺序访问。在链表任何位置今日难过插入删除操作都很快速
* `array`固定大小数组。支持快速随机访问。不能添加或删除元素
* `string`与vector相似的容器，但专门用于保存字符。随机访问快，在尾部插入删除速度快
* 较旧的编译器可能需要在两个尖括号之间键入空格。`vector<vector<string> > lines;`
* 迭代器范围是左闭合区间[begin,end)表示范围自begin开始，于end之前结束，迭代器begin和end必须指向相同的容器。
* `const_iterator`表示不变的迭代器
* `begin`和`end`有多个版本:带r的版本返回反向迭代器，以c开头的版本则返回const迭代器
* 标准库array具有固定大小，当定义一个`array`时，除了指定元素类型，还需要指定容器大小`array<int,42>` `array<string,10>`
* 标准库array与内置数组不一样，我们不能对内置数组类型进行拷贝或对象赋值操作，但是对于标准库`array`是可以的

        int digs[10] = {0,1,2,3,4,5,6,7,8,9};
        int cpy[10] = digs; //error
        array<int,10> digits = {0,1,2,3,4,5,6,7,8,9};
        array<int,10> copy = digits;
* c={a,b,c...} 将c1种元素替换为初始化列表中元素的拷贝(array不适用)
* `assign`操作不适用于关联容器和`array`
* `seq.assign(b,e)`将seq中的元素替换为迭代器b和e所表示的范围中的元素
* `seq.assign(il)`将seq中的元素替换为初始化列表li中的元素
* `seq.assign(n,t)`将seq中的元素替换为n个值为t的元素
* `swap`操作交换两个相同类型容器的内容
* 成员函数`size`返回容器中元素的数目，`empty`当size为0时返回true，`max_size`返回一个大于或等于该类型容器所能容纳的最大元素的值。`forward_list`支持`max_size`和`empty`但不支持`size`
* `forward_list`有自己专门的`insert`和`emplace`操作，不支持`push_back`和`emplace_front`
* `vector`和`string`不支持`push_front`和`emplace_back`
* `c.insert(p,t)`在迭代器p指向的元素之前创建一个值为t的元素
* `c.insert(p,n,t)`在迭代器p指向的元素之前创建n个值为t的元素
* `c.insert(p,b,e)`将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前
* `c.insert(p,li)`il是一个花括号包围的元素值列表，将这些给定值插入到迭代器p指向的元素之前
* `emplace_front`、`emplace`和`emplace_back`调用他们的时候则是将参数传递给元素类型的构造函数

        c.emplace_front('asdsad',25,13.99);
        //c.push_front('asdsad',25,13.99);//error
* 如果我们希望确保下标是合法的，可以使用at成员函数，at成员函数类似下标运算符，如果下标越界，at会抛出一个out_of_range异常
* `c.pop_back()`删除c中尾元素
* `c.pop_front()`删除c中首元素
* `c.erase(p)`删除迭代器p所指定的元素，返回一个指向被删元素之后元素的迭代器，若p指向尾元素，则返回尾后迭代器。
* `c.erase(b,e)`删除迭代器b和e所指定范围内的元素。返回一个指向最后一个被元素之后元素的迭代器，若e本就是尾后迭代器，则函数也返回尾后迭代器
* `c.clear()`删除c中的所有元素。
* 特殊的`forward_list`操作

    * `lst.before_begin() lst.cbefore_begin()`返回指向链表首元素之前不存在的元素的迭代器。此迭代器不能解引用，cbefore_begin()返回一个const_iterator
    * `lst.insert_after(p,t)``lst.insert_after(p,n,t)``lst.insert_after(p,b,e)``lst.insert_after(p,li)`
    * `emplace_after(p,args)`使用args在p指定的位置之后创建一个元素。返回一个指向这个新元素的迭代器
    * `list.erase_after(p)` `list.erase_after(b,e)`删除p指向的位置之后的元素，或删除从b之后直到（不包含）e之间的元素。返回一个指向被删元素之后元素的迭代器，若不存在这样的元素，则返回尾后迭代器
* 我们可以用`resize`来增大或缩小容器
* `c.resize(n)`调整c的大小为n个元素，若n<c.size(),则多出的元素被丢弃，若必须添加新元素，对新元素进行值的初始化
* `c.resize(n,t)`调整c的大小为n个元素，任何新添加的元素都初始化为值t
* 如果在一个循环中插入/删除deque、string或vector中的元素，不要缓存end返回的迭代器。
* **容器操作啃呢个使迭代器失效**
* 在向容器添加元素后：

    * 如果容器时vector或string，且存储空间被重新分配，则指向容器的迭代器、指针和引用都会失效。如果存储空间为重新分配，指向插入位置之前的元素的迭代器指针和引用都有效，但插入之后元素的迭代器指针和引用将会失效
    * 对与deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效。如果在首尾添加，迭代器失效，其他不会。
    * 对于list和forward_list 迭代器、指针和引用都有效
* 在向容器删除元素后：

    * 对于list和forward_list 迭代器、指针和引用都有效
    * 对于vector和string，指向被删元素之前的迭代器、指针和引用有效
    * 对于deque，若果在首尾之外任何位置删除元素，迭代器、指针和引用都失效。如果是在尾部删除元素，则尾部迭代器失效，其它都不会，如果是在首部删除元素，不受影响。
* `shrink_to_fit`只适用于vector string deque
* `capacity`和`reserve`只适用于vector和string
* `c.shrink_to_fit()`请将capacity减小为与size相同大小
* `c.capacity()`不重新分配内存空间的话，c可以保存多少元素
* `c.reserve(n)`分配至少能容纳n个元素的内存空间
## 泛型算法
* 大多数算法都定义在头文件`algorithm`中，标准库还在头文件`numeric`中定义了一组数值泛型算法
* 一般情况下，这些算法并不直接操作容器，而是遍历由两个迭代器指定的一个元素范围来进行操作
* `find(b,e,val)`如果没有在迭代器b和e范围之内没有找到val,则返回e，若找到，则返回给定值的元素的迭代器
* `accumulate`定义在头文件`numeric`中，`accumulate(b,e,init)`第三个是和的初始值，求和函数
* 如果我们传递了一个字符串字面值，用于保存和的对象的类型将是`const char*`，`string`有+号运算符，但是`const char*`没有
* `equal(r1.begin(),r1.end(),r2.begin())`用于确定连个序列是否保存相同的值，非常重要的假设是它假定第二个序列至少与第一个序列一样长
* `fill(b,e,val)`将val赋予给输入序列中的每个元素
* `fill_n(dest,n,val)`将给定值赋予迭代器指向的元素开始的指定个元素，但是从dest开始的序列至少包含n个元素
* `back_inserter`位于头文件`iterator`中，返回一个与该容器绑定的插入迭代器

        auto it = back_inserter(vec);
        *it = 42; //在vec尾部插入一个元素
* 拷贝算法(`copy`)接收三个迭代器，前两个表示范围，后一个表示目的序列的起始位置
* `unique`算法重排输入序列，将相邻的重复项消除，并返回一个指向不重复范围末尾的迭代器
* 保持相同长度的单词按字典序排列，可以使用`stable_sort`算法
* `lambda表达式`的形式：`[capture list](parameter list)-> return type {function body}`capture list是一个lambda所在函数中定义的局部变量的列表，通常为空
* `find_if(b,e,f)`第三个参数必须是一个一元谓词
* 当我们混合使用隐式捕获和显示捕获时，捕获列表中的第一个元素必须是一个&或=。此符号指定了默认捕获方式为引用或值。
* **标准库bind函数**它定义在头文件functional中，可以将bind函数看作一个通用的函数适配器，他接受一个可调用对象，生成一个新的可调用对象来"适应"原对象的参数列表`auto newCallable = bind(callable,arg_list)`,newCallable本身时一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。arg_list中的参数可能包含形如_n的名字，其中n是一个整数，这些参数是"占位符"，表示newCallable的参数，它们占据了传递给newCallable的参数的位置。数值n表示生成的可调用对象中参数的位置:_1为newCallable的第一个参数，_2为第二个参数。
        
        //此bind调用生成一个可调用对象，将check_size的第二个参数绑定到sz的值
        auto check6 = bind(check_size,_1,6)
* using namespace std::placeholders;
* 如果我们希望传递给bind一个对象而不拷贝它，就必须使用标准库`ref`函数

        for_each(w.begin(),w.end(),bind(print,ref(os),_1,' '));
      
* 标准库还有一个`cref`的函数，生成一个保存const的引用类，都存在于头文件`functional`中

## 关联容器
* `multimap`表示关键字可重复出现的map，`multiset`表示关键字可重复出现的set，`unordered_map`无序map,`unordered_set`无序的set，`unordered_multimap`无序的关键字可以重复出现的map，`unordered_multiset`无序的关键字可以重复出现的set

## 重载运算与类型转换
* 不能被重载的运算符:`::`、`.*`、`.`、`?:`
* `data1+data2` 等价于 `operator+(data1,data2)`
* `data1 += data2`等价于`data1.operator+=(data2)`
* 通常情况下，不应该重载逗号、取地址、逻辑与和逻辑或运算符
* 重载的运算符是具有特殊名字的函数:它们的名字有关键字operator和其后要定义的运算符号共同组成。和其他函数一样，重载的运算符也包含返回类型，参数列表以及函数体
* 对称性运算符必须定义成非成员函数，改变对象的状态的运算符定义为成员函数,`= [] ->`必须是成员函数
## 动态内存
* 除了静态内存和栈内存，每个程序还拥有一个内存池，这部分内存被称作自由空间(free store)或堆(heap)
* 两种智能指针，存在与头文件`memory`中

    * `shared_ptr`允许多个指针指向同一个对象
    * `unique_ptr`则“独占”所指向的对象
    