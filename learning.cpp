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
