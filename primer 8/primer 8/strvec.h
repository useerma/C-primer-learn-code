#pragma once
#include<memory>
#include<string>
#include<list>
#include <algorithm>

class strvec {
public:
	strvec() : elements(nullptr),first_free(nullptr),cap(nullptr) {} //Ĭ�ϳ�ʼ��
	strvec(std::initializer_list<std::string>);
	strvec(const strvec&); //�������캯��
	strvec& operator=(const strvec&); //������ֵ�����
	~strvec();  //��������
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; } //Ԫ������
	size_t capacity() const { return cap - elements; } //��������ɵ�Ԫ������
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserve(size_t n) { if (n > capacity()) reallocate(n); } //����n���ռ�
	void resize(size_t n); 
	void resize(size_t n, const std::string& s);
private:
	static std::allocator<std::string> alloc;
	void check_alloc() { if (size() == capacity()) reallocate(); } //����Ƿ����ڴ��ʹ��
	std::pair<std::string*, std::string* > alloc_n_copy
	(const std::string*, const std::string*); //�����ڴ棬������һ��������Χ�ڵ�Ԫ�ص����ڴ���

	void free(); //����Ԫ�ز��ͷ��ڴ�
	void reallocate(); //���·����ڴ沢��������Ԫ��
	void reallocate(size_t);
	std::string* elements; //ָ����Ԫ��
	std::string* first_free; //ָ��δ����Ԫ�صĵ�һ��λ��
	std::string* cap; //ָ�������ڴ�����β��λ��
};

void strvec::push_back(const std::string& s)
{
	check_alloc(); //����Ƿ��пռ䣬��û�������·���ռ�
	alloc.construct(first_free++, s); //��first_freeָ��λ�ù���s�ĸ���
}

std::pair<std::string*, std::string* > strvec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b); //����Χ�ڵ�Ԫ�ط����ڴ�ռ䣬���ؿ�ʼλ��
	return { data,std::uninitialized_copy(b,e,data) };
	//����һ��pair����data��uninitialized_copy�ķ���ֵ���ɣ��б��ʼ��
}

void strvec::free()
{
	if (elements) //ָ�벻Ϊ��
	{
		for (auto p = first_free; p != elements;) //�������پ�Ԫ��
			alloc.destroy(--p);
		//for_each(elements, first_free, [](std::string& s) {alloc.destroy(&s); });
		//for_each��lambda�İ汾
		alloc.deallocate(elements, cap - elements); //�����ڴ�
	}
}

strvec::strvec(const strvec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end()); //����һ��pair
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second; //����alloc_n_copy����Ŀռ�պõ��ڸ�����Ԫ�أ����cap = first_free
}

strvec::~strvec()
{
	free();
}

strvec& strvec::operator=(const strvec& rhs)
{
	//�ȱ����ٿ����������Ը�ֵ
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free(); //�ͷŵ�ǰ������ڴ�
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void strvec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1; //ȷ�������ڴ�ռ��С
	auto newdata = alloc.allocate(newcapacity); //�����ڴ�ռ䣬����ָ���������һ��λ�õ�ָ��
	auto dest = newdata; //dest����newdata���ƶ�
	auto elem = elements; //ָ�������ĵ�һ��Ԫ��
	for (size_t i = 0; i != size(); i++)
		alloc.construct(dest++, std::move(*elem++)); //ʹ���ƶ����캯������������
	free(); //�ͷž�����
	elements = newdata; //�������ݽṹ
	first_free = dest;
	cap = elements + newcapacity;
}

void strvec::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity); //�����ڴ�ռ䣬����ָ���������һ��λ�õ�ָ��
	auto dest = newdata; //dest����newdata���ƶ�
	auto elem = elements; //ָ�������ĵ�һ��Ԫ��
	for (size_t i = 0; i != size(); i++)
		alloc.construct(dest++, std::move(*elem++)); //ʹ���ƶ����캯������������
	free(); //�ͷž�����
	elements = newdata; //�������ݽṹ
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
	else if (n < size()) //�����ַ���
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
	auto newdata = alloc_n_copy(il.begin(), il.end()); //����ռ䣬����pair
	elements = newdata.first;
	first_free = cap = newdata.second;
}

