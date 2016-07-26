// #inclue <cstdlib>包含了srand() rand() exit()等用法
// 当我们调用一个函数时，会在内存中建立起一块特殊区域，称为'程序堆栈(program stack)'，这块特殊区域提供了每个函数参数的储存空间。他也提供了函数所定义的每个对象的
  // 内存空间。我们称它为local object(局部对象)／一旦函数完成，这块内存就被释放掉，从program stack被pop出来。
// int ival = 1024; 对象，类型为int
// int *pi = &ival; 指针，指向一个int对象
// int &rval = ival 引用，代表一个int对象
// 当我们以by reference方式将对象做为参数传入时，对象本身并不会复制出一份，复制的是对象的地址
// pointer 可能(也啃呢个不)指向某个实际对象。
// 当我们提领pointer时，一定要先确定其值并非0
// 至于reference，则必定会代表某个对象，所以不需要做此检查
// 为对象分配的内存，其存活时间称为储存期或范围
// 对象在程序内的存活区域称为该对象的scope
// 动态内存管理 内存系由程序的空闲内存(free store)分配而来，也称为heap memory(堆内存)
// new delete  
// 删除数组中的所有对象 必须在数组指针和delete表达式之间 int *pia = new int(24); delete [] pia; 
// 内存泄漏 memory leap
// ofstream 从内存到硬盘
// 局部静态对象 local static object
// 局部静态对象所处的内存空间，即使在不同的函数调用过程中，依然持续存在。
// push_back()函数，引入头文件vector，在vector对象尾部插入一个数据
// inline 函数，表示要求编译器在每个函数调用点上，将函数的内容展开。面对一个inline函数，编译器可将该函数的调用操作改为一份函数代码副本替代
// 模版函数function template将参数列表中指定的全部(或部分)参数的类型信息抽离了出来
  // eg:template <typename elemType> void template_func(const string &msg, vector<elemType> &vec){...}
  // 关键字typename在模版函数中是一个暂时放置类型的占位符 elemType只是一个任意名称
  // 调用： vector<int> ivec;sting msg;display( msg, ivec );
// 一般来说，在头文件中，在所有的函数声明前添加extern修饰。
  // eg: extern const vector<int>* (*elem_seq[MAX_SIZE])(int);
// 函数指针和指针函数
  // 指针函数是指带指针的函数，即本质是一个函数。函数返回类型是某一类型的指针
  // 函数指针式指向函数的指针变量，即本质是一个指针变量 int (*f)(int x)指向一个返回整型值的函数
// 如果此文件被认定为标准的或项目专属的头文件，我们便使用尖括号将文件名包住，编译器在搜索此文件时，会在某些默认的磁盘目录中寻找
// 如果此文件名被双引号包住，此文件便被认为是一个用户提供的头文件，搜素此文件时，会由要包含此文件的文件所在的磁盘目录开始寻找
// STL主要由两种组件构成：一是容器，包括vector list set map。二是 用以操作这些容器的所谓泛型算法(generic algotithm)
// vector list 顺序性容器
// map 是key/value的组合。 set仅包含key
// array是指针 ++array指向下一个元素的指针
// list也是一个容器，不同的是list的元素以一组指针相互链接：前向指针指向下一个元素，后向指针指向上一个元素
// 指针的算术运算必须首先假设多有元素都储存在连续的空间里。
// 每一个标准容器都提供一个名为begin()的函数，可返回一个iterator,指向第一个元素。end()的函数，可返回一个iterator,指向最后一个元素
  // iterator定义方式:
  // vector<string> svec;
  // vector<string>::iterator iter = svec.begin();
  //此处iter被定义为一个iterator，指向一个vector， 双冒号表示此iterator乃是位于string vector定义内的嵌套类型。
// 对于const vector 我们使用const_iterator来进行遍历操作
  // const vector<string> cs_vec;
  // vector<string>::const_iterator iter = cs_vec.begin();
// 所有容器共通操作
  // empty()会在容易无任何元素时返回true，否则返回false
  // size()返回容器内目前持有的元素个数
  // clear()删除所有元素
  // begin()返回一个iterator 指向容器的第一个元素
  // end()返回一个iterator 指向容器的最后一个元素
  // insert()将单一或某个范围内的元素插入容器内
  // erase()将容器内的单一元素或某个范围内的元素删除
// list指针包含三个字段 value back指针(指向前一个元素) front指针(指向下一个元素)
// deque 顺序性容器 对于最前端元素的插入和删除操作，效率更高，末端元素亦同
// 定义顺序性容器对象的五种方式
  // 产生新的容器
    // list<string> slist
    // vector<int> ivec
  // 产生特定大小的容器
    // list<int> ilist(1024)
    // vector<int> ivec(29)
  // 产生特定大小的容器并指定初值
    // list<string> slist(16,"hello")
  // 通过一对iterator产生容器。这对iterator用来标示一整组做为初值的元素的范围
    // int ia[8] = {1,2,3,4,5,6,7,8};
    // vector<int> ivec(ia, ia+8);
  // 根据某个容器产生出新容器，复制原容器内的元素，做为新容器的初值
    // list<string> slist;
    // list<string> slist2(slist);
// push_back() pop_back() 在容器末尾进行插入删除操作
// list deque 提供了 push_front() pop_front()
// 在容器中读取首末端的值 front() back()
// iterator.insert(iterator position,elemType value) 将value插入到position之前，会返回一个iterator，指向被插入的元素
// void insert(iterator position,int count, elemType value)可在position之前插入count个元素，这些元素的值都和value相同
// void insert(iterator1 postion,iterator2 first,iterator2 last)可在position之前插入[first,last)所标示的各个元素
// iterator insert(iterator position) 可在position之前插入元素。元素的初值为其所属类型的默认值
// iterator erase(iterator position) 可删除position所指的元素
// iterator erase(iterator first, iterator last)可删除[first,last)范围内的元素
// 注意的是：list不直接iterator的便宜运算 即slist.erase(it1,it1+num_tries)
// 泛型算法 头文件#include<algorithm>
// find(first,last,elem)用于搜索无序集合中是否存在某值，用iterator[first,last)标出。
// binary_search(first,last,elem)用于有序集合的搜索，搜索到了返回true，未搜索到返回false
// count() 返回数值相符的元素数目
// search() 比对某个容器内是否存在某个子序列，返回成功则指向序列起始处
//  函数指针 bool (*pred)(int,int) pred 为函数，*pred为函数的内存地址
// #include <map> map<string,int> words;
// map对象有一个名为first的member 对应于key，有一个名为second的member 对英语value
// map查询法是利用map的find()函数， 返回一个iterator,反之返回一个end()
// map的count()函数，count()会返回某特定项在map内的个数
// 所有成员函数都必须在class主体内进行声明，至于是否要同时进行定义，可自由决定，如果要在class主体内定义，这个member function会自动地视为inline函数。
// 要在class主体之外定义member function,必须使用特殊的语法，目的在于分辨该函数究竟属于哪一个class。如果希望该函数为inline，应该在最前面指定关键字inline
  //inline bool Stack::empty() {
  //    return _stack.empty();
  //}
  //
  //bool Stack::pop( string &elem ) {
  //    //...
  //}
  // class名称之后的两个冒号即所谓的class scope resolution 类作用域解析运算符
// class定义及其inline member function 通常都会被放在与class同名的头文件中。
// 构造函数constructor的函数名称必须与class名称相同，语法规定：
  // constructor 不应指定返回类型，不用返回任何值
  // 可以被重载
// 成员初始化列表
  // Triangular::Triangular(int len, int bp) : _name("Triangular"){ //... }
// 析构函数 destructor 是用户自定义的一个class member,一旦某个class提供有destructor，当其obj结束生命时，便会自动调用destructor处理善后，Destructor主要用来释放在constructor或对象生命周期中分配的资源
// Destructor 严格规定
  // class名称前再加上'~'前缀，它绝对不会有返回值，也没有任何参数。由于参数裂变为空，绝不可能被重载(overloaded)
    //class Matrix {
    //public:
    //    Matrix( int row, int col ) : _row( row ), _col( col ) {
    //        _pmat = new double[ row * col ];
    //    }
    //    ~Matrix() {
    //        delete [] _pmat;
    //    }
    //private:
    //    int  _row, _col;
    //    double* _pmat;
    //};
// 当我们在设计class时，必须问自己，在此class之上进行的"成员逐一初始化"的行为模式是否适当，肯定则不需要copy constructor,否定则需要copy constructor
// 面向对象编程风格的三个独特概念是：继承、多态、动态绑定
