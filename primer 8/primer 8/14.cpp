//#include"biao.h"
//#include <functional>
//
//class ifelsethen {
//public:
//	ifelsethen(int i1,int i2,int i3) : ival1(i1),ival2(i2),ival3(i3){}
//	int operator()(int i1, int i2, int i3)
//	{
//		return i1 ? i2 : i3;
//	}
//private:
//	int ival1, ival2, ival3;
//};
//
//class readstring {
//public:
//	readstring(istream& is = cin) : is(is) {}
//	std::string operator()()
//	{
//		string line;
//		if (!getline(is, line))
//		{
//			line = " ";
//		}
//		return line;
//	}
//private:
//	std::istream & is;
//};
//
//void testread()
//{
//	readstring rs; //使用函数对象读取数据
//	vector<string> vec; 
//	while (true)
//	{
//		string line = rs();
//		if (!line.empty())
//		{
//			vec.push_back(line);
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//class strlens {
//public:
//	strlens(int len) : len(len) {}
//	bool operator()(const string& str)
//	{
//		return str.length() == len;
//	}
//private:
//	int len;
//};
//
//void readstr(std::istream& is, vector<string>& vec)
//{
//	string word;
//	while (is >> word)
//		vec.push_back(word);
//}
//
//int main()
//{
//	vector<string> vec;
//	readstr(cin, vec);
//	const int minlen = 1;
//	const int maxlen = 10;
//	for (int i = minlen; i <= maxlen; i++)
//	{
//		strlens slenis(i);
//		cout << "len: " << i <<" " << std::count_if(vec.begin(), vec.end(), slenis) << endl;
//	}
//	return 0;
//}
//
//
//bool divideall(vector<int>& ivec, int dividend)
//{
//	//bind1st和bind2st都是把二元函数转化为一元函数，固定的是第一参数或是第二个参数
//	return count_if(ivec.begin(), ivec.end(), std::bind1st(std::modulus<int>(), dividend)) == 0;
//}