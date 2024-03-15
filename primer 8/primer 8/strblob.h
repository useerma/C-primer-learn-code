#include"biao.h"
class strblobptr;
class strblob {
	friend class strblobptr;
public:
	typedef vector<string>::size_type size_type;
	strblob();  //默认构造函数
	strblob(std::initializer_list<string> il); //含有列表的构造函数
	size_type size() const { return data->size(); }  //size函数
	bool empty() const { return data->empty(); }    //是否为空
	void push_back(const string& s) { data->push_back(s); }   //添加元素
	void pop_back();   //删除元素
	string& front();   //访问头元素
	const string& front() const;   //const重载版本
	string& back();    //访问尾元素
	const string& back() const;
	strblobptr begin();
	strblobptr end();
private:
	std::shared_ptr<std::vector<string>> data;   //指向vector<string>的智能指针
	void check(size_type i, const string& msg) const;   //检查索引是否有效
};

strblob::strblob() : data(std::make_shared<vector<string>>()) {}  //创建一个空的vector，指针指向它
strblob::strblob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}  //用il来初始化vector
void strblob::check(size_type i, const string& msg) const  //检查函数
{
	if (i >= data->size())  //检查容器是否为空，
		throw std::out_of_range(msg);
}

string& strblob::front()
{
	check(0, "front on empty"); //若vector为空，抛出异常
	return data->front();
}

const string& strblob::front() const
{
	check(0, "front on empty");
	return data->front();
}

string& strblob::back()
{
	check(0, "back on empty");
	return data->back();
}

const string& strblob::back() const
{
	check(0, "back on empty");
	return data->back();
}

void strblob::pop_back()
{
	check(0, "pop on empty");
	data->pop_back();
}
#pragma once
