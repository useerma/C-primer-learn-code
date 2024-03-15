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
	date() = default; //Ĭ�Ϲ��캯��
	date(string& ds);
	
	//��Ա��������
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
	for (i = 0; i < 12; i++) //�·ݼ�д���
	{
		for (j = 0; j < month_abbr[i].size(); j++) //ÿ���ַ����·ݼ�дƥ��
			if (ds[j] != month_abbr[i][j])
				break;
		if (j == month_abbr[i].size()) //ds�����Ǽ�ƣ�Ҳ������ȫ��
			break;
	}
	if (i == 12) //���е����û�ҵ����·���
		throw std::invalid_argument("���ǺϷ��·���");
	if (ds[j] == ' ') //�հ׷������
	{
		end_of_month = j + 1;  //�ƶ�������
		return i + 1;  //i��0��ʼ��Ҫ+1
	}

	for (; j < month_name[i].size(); j++) //�Ӽ��β����ʼ���ȫ��
		if (ds[j] != month_name[i][j])
			break;

	if (j == month_name[i].size() && ds[j] == ' ')
	{
		end_of_month = j + 1;
		return i + 1;
	}

	throw std::invalid_argument("���ǺϷ��·���");
}

inline int get_day(string& ds, int month, int& p)
{
	size_t q; 
	int day = stoi(ds.substr(p), &q); //������·ݵ���ĸ��ʣ�µ�ת����int
	if (day < 1 || day > days[month])
		throw std::invalid_argument("���ǺϷ�����ֵ");
	p += q;  //��ʼλ�ø���
	return day;
}

inline int get_year(string& ds, int& p)
{
	size_t q;
	int year = stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("�Ƿ���β����");
		return year;
}

date::date(string& ds)
{
	int p;
	size_t q;
	if ((p = ds.find_first_of("0123456789")) == string::npos)
		throw std::invalid_argument("û�����֣��Ƿ�����");
	if (p > 0)
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("�Ƿ������");
		p++;
		year = get_year(ds, p);
	}
	else
	{
		month = stoi(ds, &q);
		p = q;
		if (month < 1 || month > 12)
			throw std::invalid_argument("���ǺϷ��·�ֵ");
		if (ds[p++] != '/')
			throw std::invalid_argument("�Ƿ������");
		day = get_day(ds, month, p);
		if (ds[p++] != '/')
			throw std::invalid_argument("�Ƿ������");
		year = get_year(ds, p);
	}
}

ostream& operator << (ostream& out, const date& d)
{
	out << d.y() << "��" << d.m() << "��" << d.d() << "��" << endl;
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