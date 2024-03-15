#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::begin;
using std::end;
using std::string;
using std::vector;

//int fact(int val)  //求阶乘
//{
//	if (val < 0)
//		return 0;
//	int ret = 1;
//	for (int i = 1; i != val+1; i++)
//		ret *= i;
//	return ret;
//}
//
//int main()
//{
//	int num;
//	cout << "enter a number:";
//	cin >> num;
//	int sum = fact(num);
//	if (sum)
//		 cout << "阶乘：" << sum << endl;
//	else
//		cerr << " No Integer" << endl;
//	return 0;
//}



//int myABS(int num) //求绝对值
//{
//	if (num < 0)
//		return (num * -1);
//	else
//		return num;
//}
//
//int main()
//{
//	int val;
//	cout << "enter a number:";
//	cin >> val;
//	cout << "绝对值：" << myABS(val) << endl;
//	return 0;
//}


//double myADD(double x1, double x2)  //静态变量的使用
//{
//	double result = x1 + x2;
//	static unsigned acout = 0;
//	acout++;
//	cout << "number of exections:" << acout << endl;
//	return result;
//}
//
//int main()
//{
//	double a, b;
//	char answer = 0;
//	do
//	{
//		cout << "enter two number:";
//		cin >> a >> b;
//		cout << endl;
//		cout << "result = " << myADD(a, b) << endl;
//		cout << "again ?" << "(enter Y or N)" << endl;
//		cin >> answer;
//	} while (answer == 'Y');
//		return 0;
//}


//unsigned myCnt() 
//{
//	static unsigned Cnt = -1;
//	Cnt++;
//	return Cnt;
//}
//
//int main()
//{
//	cout << "enter a number:";
//	int ch;
//	while (cin >> ch)
//	{
//		cout << "number of exections:" << myCnt() << endl;
//	}
//	return 0;
//}



//void swap(int* p, int* q) //指针交换值
//{
//	int temp;
//	temp = *p;
//	*p = *q;
//	*q = temp;
//}
//
//int main()
//{
//	int a = 5, b = 10;
//	int* r = &a, * s = &b;
//	cout << "No swap:" << a << " " << b << endl;
//	swap(r, s);
//	cout << "swap:" << a << " " << b << endl;
//	return 0;
//}


//void Swappointer(int*& p, int*& q) // 对int指针的引用，交换指针地址
//{
//	int* temp = p;
//	p = q;
//	q = temp;
//}
//
//int mycompare(const int val, const int* p)
//{
//	return (val > *p) ? val : *p;
//}
//
//int main()
//{
//	int a[5] = {9,8,7,6,4};
//	cout << "enter a number:";
//	int j;
//	cin >> j;
//	cout << "big number:" << mycompare(j, a) << endl;
//	cout << "数组元素：" << endl;
//	for (auto i : a)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}



//void print2( int* p, const int sz)
//{
//	int i = 0;
//	while (i != sz)
//	{
//		cout << *p++ << endl;
//		++i;
//	}
//	//for (int i = 0; i != sz; i++)
//	//	cout << *p++ << endl;
//	/*for (; *p != p[sz-1]; p++)
//		cout << *p << endl;*/
//}
//
//void print3(const int* b, const int* e)
//{
//	for (auto q = b; q != e; ++q)
//		cout << *q << endl;
//}
//
//int main()
//{
//	int j[3] = { 1,2,3 };
//	print2(j, sizeof(j) / sizeof(*j));
//	auto b = std::begin(j);
//	auto e = std::end(j);
//	print3(b, e);
//	return 0;
//}


//int main(int argc, char** argv)
//{
//	std::string str;
//	for (int i = 0; i != argc; ++i)
//		str += argv[i];
//	cout << str << endl;
//	return 0;
//}


//int iCount(std::initializer_list<int>i)
//{
//	int count = 0;
//	for (auto val : i)
//		count += val;
//	return count;
//}
//
//int main()
//{
//	cout << "sum:" << iCount({ 1,2,3,4,5 }) << endl;
//	return 0;
//}


//void print(const std::vector<int>vint, unsigned index)  //递归 
//{
//	unsigned sz = vint.size();
//	if (!vint.empty() && index < sz)
//	{
//		cout << vint[index] << endl;
//		print(vint, index + 1);
//	}
//}
//
//int main()
//{
//	std::vector<int> v = { 1,2,3,5,6,7,8,9,10 };
//	print(v, 0);
//	return 0;
//}


//typedef string arr[10]; //类型别名
//arr& func();
//
//auto func() -> string(&)[10];  //尾置返回类型
//
//string str[10];
//decltype(str)& func();  //decltype判断返回类型



void print(vector<int>vInt, unsigned index)
{
	unsigned sz = vInt.size();
    #ifndef NDEBUG
	cout << "vector number:" << sz << endl;
    #endif
	if (!vInt.empty() && index < sz)
	{
		cout << vInt[index] << endl;
		print(vInt, index + 1);
	}
}

//int main()
//{
//	vector<int> v = { 1,2,3,4,5 };
//	print(v, 0);
//	return 0;
//}




