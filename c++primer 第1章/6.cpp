#include<iterator>
#include <iostream>
#include<vector>
#include "2.cpp"

using namespace std;

//void reset(int& i)
//{
//	i = 0;
//}
//int main()
//{
//	int num = 10;
//	cout << num << endl;
//	reset(num);
//	cout << num << endl;
//	return 0;
//}



//void myswap(int& i, int& j)
//{
//	int temp = i;
//	i = j;
//	j = temp;
//}
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//	cout << a << ' ' << b << endl;
//	myswap(a, b);
//	cout << a << ' ' << b << endl;
//}



//bool hasupper(const string& str)
//{
//	for (auto c : str)
//		if (isupper(c))
//			return true;
//	return false;
//}
//
//void changtolower(string& s)
//{
//	for (auto c : s)
//		c = tolower(c);
//}
//
//int main()
//{
//	cout << "enter a sentense!" << endl;
//	string str;
//	cin >> str;
//	if (hasupper(str))
//	{
//		changtolower(str);
//		cout << str << endl;
//	}
//	else
//		cout << "this sentense no have supper word" << endl;
//	return 0;
//


//int arr(int , int );
//vector<decltype(arr)*>vf; //以指向函数的指针为元素的vector对象
//
//
//int func1(int a, int b)
//{
//	return a + b;
//}
//
//int func2(int a, int b)
//{
//	return a - b;
//}
//
//int func3(int a, int b)
//{
//	return a * b;
//}
//
//int func4(int a, int b)
//{
//	return a / b;
//}
//void compete(int a, int b, int (*p)(int, int))
//{
//	cout << p(a, b) << endl;
//}
//int main()
//{
//	int i = 10, j = 5;
//	decltype(func1)* p1 = &func1, * p2 = &func2, * p3 = &func3, * p4 = &func4;
//	vector<decltype(func1)*>vF = { p1,p2,p3,p4 }; //列表初始化
//	for (auto p : vF)
//	{
//		compete(i, j, p);
//	}
//	return 0;
//}



//int main()
//{
//	Sales_data total;
//	if (cin >> total)
//	{
//		Sales_data trans;
//		while (cin >> trans)
//		{
//			if (total.isbn() == trans.isbn())
//				total += trans;
//			else
//			{
//				cout << total << endl;
//				total = trans;
//			}
//		}
//		cout << total << endl;
//	}
//	else
//	{
//		cerr << "No data？" << endl;
//		return -1;
//	}
//	return 0;
//}


class Person
{
private:
	string strName;
	string straddress;
public:
	string getName() const { return strName; }
	string getaddress() const { return straddress; }  //常量成员函数
};

Sales_data add(const Sales_data& left, const Sales_data& right)
{
	Sales_data sum = left;
	sum.combine(right);
	return sum;
}

std::istream& read(std::istream& is, Sales_data& item)
{
	is >> item.bookNO >> item.units_sold >> item.revenue;
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.bookNO << " " << item.revenue << " " << item.units_sold;
	return os;
}
