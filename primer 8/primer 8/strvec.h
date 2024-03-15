#pragma once
#include<memory>
#include<string>
#include<list>
#include <algorithm>

class strvec {
public:
	strvec() : elements(nullptr),first_free(nullptr),cap(nullptr) {} //默认初始化
	strvec(std::initializer_list<std::string>);
	strvec(const strvec&); //拷贝构造函数
	strvec& operator=(const strvec&); //拷贝赋值运算符
	~strvec();  //析构函数
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; } //元素数量
	size_t capacity() const { return cap - elements; } //最大能容纳的元素数量
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserve(size_t n) { if (n > capacity()) reallocate(n); } //申请n个空间
	void resize(size_t n); 
	void resize(size_t n, const std::string& s);
private:
	static std::allocator<std::string> alloc;
	void check_alloc() { if (size() == capacity()) reallocate(); } //检查是否有内存可使用
	std::pair<std::string*, std::string* > alloc_n_copy
	(const std::string*, const std::string*); //分配内存，并拷贝一个给定范围内的元素到新内存中

	void free(); //销毁元素并释放内存
	void reallocate(); //重新分配内存并拷贝已有元素
	void reallocate(size_t);
	std::string* elements; //指向首元素
	std::string* first_free; //指向未分配元素的第一个位置
	std::string* cap; //指向整个内存最后的尾后位置
};

void strvec::push_back(const std::string& s)
{
	check_alloc(); //检查是否有空间，若没有则重新分配空间
	alloc.construct(first_free++, s); //在first_free指向位置构造s的副本
}

std::pair<std::string*, std::string* > strvec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b); //给范围内的元素分配内存空间，返回开始位置
	return { data,std::uninitialized_copy(b,e,data) };
	//返回一个pair，由data和uninitialized_copy的返回值构成，列表初始化
}

void strvec::free()
{
	if (elements) //指针不为空
	{
		for (auto p = first_free; p != elements;) //逆序销毁旧元素
			alloc.destroy(--p);
		//for_each(elements, first_free, [](std::string& s) {alloc.destroy(&s); });
		//for_each和lambda的版本
		alloc.deallocate(elements, cap - elements); //回收内存
	}
}

strvec::strvec(const strvec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end()); //返回一个pair
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second; //由于alloc_n_copy分配的空间刚好等于给定的元素，因此cap = first_free
}

strvec::~strvec()
{
	free();
}

strvec& strvec::operator=(const strvec& rhs)
{
	//先保存再拷贝，避免自赋值
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free(); //释放当前对象的内存
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void strvec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1; //确定分配内存空间大小
	auto newdata = alloc.allocate(newcapacity); //分配内存空间，返回指向新数组第一个位置的指针
	auto dest = newdata; //dest代替newdata来移动
	auto elem = elements; //指向旧数组的第一个元素
	for (size_t i = 0; i != size(); i++)
		alloc.construct(dest++, std::move(*elem++)); //使用移动构造函数构造新数组
	free(); //释放旧数组
	elements = newdata; //更新数据结构
	first_free = dest;
	cap = elements + newcapacity;
}

void strvec::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity); //分配内存空间，返回指向新数组第一个位置的指针
	auto dest = newdata; //dest代替newdata来移动
	auto elem = elements; //指向旧数组的第一个元素
	for (size_t i = 0; i != size(); i++)
		alloc.construct(dest++, std::move(*elem++)); //使用移动构造函数构造新数组
	free(); //释放旧数组
	elements = newdata; //更新数据结构
	first_free = dest;
	cap = elements + newcapacity;
}

inline void strvec::resize(size_t n)
{
	if (n > size())
	{
		while (size() < n)
			push_back("");
	}
	else if (n < size()) //销毁字符串
	{
		while (size() > n)
			alloc.destroy(--first_free);
	}
}

inline void strvec::resize(size_t n, const std::string& s)
{
	if (n > size())
	{
		while (size() < n)
			push_back(s);
	}
}

inline strvec::strvec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end()); //分配空间，返回pair
	elements = newdata.first;
	first_free = cap = newdata.second;
}

