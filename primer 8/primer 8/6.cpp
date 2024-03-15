#include<iostream>
#include<fstream>
#include<sstream>
#include<stdexcept>
#include <vector>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::endl;

//int main()
//{
//	auto old_state = cin.rdstate();
//	cin.clear();
//	cin.setstate(old_state);
//	return 0;
//}


//istream& arr(istream& is)
//{
//	int a;
//	while (is >> a && !is.eof())
//	{
//		if (is.bad())
//			throw std::runtime_error("error");
//		if (is.fail())
//	    {
//			std::cerr << "error!" << std::endl;
//		    is.clear();
//		    is.ignore(100, '\n');   //舍去前100个字符，空格也包含在内
//		    continue;
//	     }
//		cout << a << std::endl;
//	}
//		is.clear();
//		return is;
//}
//	
//
//int main()
//{
//	arr(cin);
//	return 0;
//}


//std::vector<string> count;
//void reader(std::ifstream& in)
//{
//	if (in)
//	{
//		string line;
//		while (getline(in, line))
//			count.push_back(line);
//	}
//	else
//	{
//		std::cerr << "No open!" << std::endl;
//		return;
//	}
//	in.close();
//}
//
//int main()
//{
//	std::ifstream on("arr.txt");
//	reader(on);
//	std::vector<string>::const_iterator it = count.begin();
//	while (it != count.end())
//		cout << *it++ << std::endl;
//	return 0;
//}


//istream& func(istream& in)
//{
//	string v;
//	while (in >> v, !in.eof())
//	{
//		if (in.bad())
//			throw std::runtime_error("error");
//		if (in.fail())
//		{
//			std::cerr << "error" << endl;
//			in.clear();
//			in.ignore(100, '\n');
//			continue;
//		}
//		cout << v << endl;
//	}
//	in.clear();
//	return in;
//}
//
//int main()
//{
//	std::ostringstream msg;
//	msg << "C++ primer happy" << endl;
//	std::istringstream in(msg.str());
//	func(in);
//	return 0;
//}



//struct person
//{
//	string name;
//	std::vector<string>phones;
//};
//
//string format(const string& s) { return s; }
//
//bool valid(const string& s) { return true; }
//
//int main()
//{
//	string line, word;
//	std::vector<person>people;
//	std::istringstream record;
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		std::cerr << "error" << endl;
//		return -1;
//	}
//	while (getline(in, line))
//	{
//		person info;
//		record.clear();
//		record.str(line);
//		record >> info.name;
//		while (record >> word)
//			info.phones.push_back(word);
//		people.push_back(info);
//	}
//	std::ostringstream os;
//	for (const auto& entry : people)
//	{
//		std::ostringstream formatted, badnums;
//		for (const auto& nums : entry.phones)
//		{
//			if (!valid(nums))
//			{
//				badnums << " " << nums;
//			}
//			else
//			{
//				formatted << " " << format(nums);
//			}
//		}
//		if (badnums.str().empty())
//			os << entry.name << " " << formatted.str() << endl;
//		else
//			std::cerr << "input error:" << entry.name << " number:" << badnums.str() << endl;
//	}
//	cout << os.str() << endl;
//	return 0;
//}
