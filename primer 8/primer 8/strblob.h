#include"biao.h"
class strblobptr;
class strblob {
	friend class strblobptr;
public:
	typedef vector<string>::size_type size_type;
	strblob();  //Ĭ�Ϲ��캯��
	strblob(std::initializer_list<string> il); //�����б�Ĺ��캯��
	size_type size() const { return data->size(); }  //size����
	bool empty() const { return data->empty(); }    //�Ƿ�Ϊ��
	void push_back(const string& s) { data->push_back(s); }   //���Ԫ��
	void pop_back();   //ɾ��Ԫ��
	string& front();   //����ͷԪ��
	const string& front() const;   //const���ذ汾
	string& back();    //����βԪ��
	const string& back() const;
	strblobptr begin();
	strblobptr end();
private:
	std::shared_ptr<std::vector<string>> data;   //ָ��vector<string>������ָ��
	void check(size_type i, const string& msg) const;   //��������Ƿ���Ч
};

strblob::strblob() : data(std::make_shared<vector<string>>()) {}  //����һ���յ�vector��ָ��ָ����
strblob::strblob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}  //��il����ʼ��vector
void strblob::check(size_type i, const string& msg) const  //��麯��
{
	if (i >= data->size())  //��������Ƿ�Ϊ�գ�
		throw std::out_of_range(msg);
}

string& strblob::front()
{
	check(0, "front on empty"); //��vectorΪ�գ��׳��쳣
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
