#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include <vector>
#include<list>
#include<deque>
#include<iterator>
#include <stack>
#include<forward_list>
#include<numeric>
#include<algorithm>
#include<map>
#include<utility>
#include<memory>
#include<initializer_list>
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::endl; 
using std::vector;
using std::list;
using std::deque;
using std::pair;

class date
{
public:
	friend ostream& operator << (ostream&, const date&);
	date() = default; //默认构造函数
	date(string& ds);
	
	//成员函数声明
	unsigned y() const { return year; }
	unsigned m() const { return month; }
	unsigned d() const { return day; }

private:
	unsigned year, month, day;
};

const string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
const string month_abbr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec" };
const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

inline int get_month(string& ds, int& end_of_month)
{
	int i, j;
	for (i = 0; i < 12; i++) //月份简写检查
	{
		for (j = 0; j < month_abbr[i].size(); j++) //每个字符与月份简写匹配
			if (ds[j] != month_abbr[i][j])
				break;
		if (j == month_abbr[i].size()) //ds可能是简称，也可能是全称
			break;
	}
	if (i == 12) //运行到最后，没找到该月份名
		throw std::invalid_argument("不是合法月份名");
	if (ds[j] == ' ') //空白符，简称
	{
		end_of_month = j + 1;  //移动到日期
		return i + 1;  //i从0开始，要+1
	}

	for (; j < month_name[i].size(); j++) //从简称尾部开始检查全称
		if (ds[j] != month_name[i][j])
			break;

	if (j == month_name[i].size() && ds[j] == ' ')
	{
		end_of_month = j + 1;
		return i + 1;
	}

	throw std::invalid_argument("不是合法月份名");
}

inline int get_day(string& ds, int month, int& p)
{
	size_t q; 
	int day = stoi(ds.substr(p), &q); //处理掉月份的字母，剩下的转化成int
	if (day < 1 || day > days[month])
		throw std::invalid_argument("不是合法日期值");
	p += q;  //开始位置更新
	return day;
}

inline int get_year(string& ds, int& p)
{
	size_t q;
	int year = stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("非法结尾内容");
		return year;
}

date::date(string& ds)
{
	int p;
	size_t q;
	if ((p = ds.find_first_of("0123456789")) == string::npos)
		throw std::invalid_argument("没有数字，非法日期");
	if (p > 0)
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("非法间隔符");
		p++;
		year = get_year(ds, p);
	}
	else
	{
		month = stoi(ds, &q);
		p = q;
		if (month < 1 || month > 12)
			throw std::invalid_argument("不是合法月份值");
		if (ds[p++] != '/')
			throw std::invalid_argument("非法间隔符");
		day = get_day(ds, month, p);
		if (ds[p++] != '/')
			throw std::invalid_argument("非法间隔符");
		year = get_year(ds, p);
	}
}

ostream& operator << (ostream& out, const date& d)
{
	out << d.y() << "年" << d.m() << "月" << d.d() << "日" << endl;
	return out;
}

#endif  // DATE_H_INCLUDED


class Person
{
private:
	string strname;
	string straddress;
	friend std::istream& read(std::istream& is, Person& per);

public:
	Person() = default;
	Person(const string& name, const string& add)
	{
		strname = name;
		straddress = add;
	}
	Person(std::istream &is) {is >> *this;}
public:
	string getname() const { return strname; }
	string getaddress() const { return straddress; }
	std::istream& read(std::istream& is, Person& per)
	{
		is >> per.strname >> per.straddress;
		return is;
	}
	std::ostream& print(std::ostream& os, Person& per)
	{
		os << per.getname() << " " << per.getaddress();
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Person& p) {
		is >> p.strname >> p.straddress;
		return is;
	}
};


class Window_mgr
{
public:
	void clear();
};

class Screen
{
	friend void Window_mgr::clear();
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;
	Screen(unsigned ht, unsigned wd) :height(ht), width(wd),contents(ht*wd,' '){ }
	Screen(unsigned ht, unsigned wd, char c): height(ht),width(wd),contents(ht * wd,c){ }
public:
	Screen& move(unsigned r, unsigned c)
	{
		cursor = r * width + c;
		return *this;
	}
	Screen& set(char ch)
	{
		contents[cursor] = ch;
		return* this;
	}
	Screen& set(unsigned r, unsigned c, char ch2)
	{
		contents[r * width + c] = ch2;
		return *this;
	}
	Screen& display()
	{
		cout << contents;
		return *this;
	}
};

void Window_mgr::clear()
{
	Screen myScreen(10, 20, 'X');
	cout << myScreen.contents << endl;
	myScreen.contents = " ";
	cout << myScreen.contents << endl;
}