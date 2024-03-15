#include<string>
#include<iterator>
#include <iostream>
#include<cstring>
#include<vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//int main()
//{
//	string s3 ("hiya");
//	std::cout << s3 << std::endl;
//	return 0; 
//}

//int main()
//{
//	string s1 = "hello";
//	string s2 = "world";
//	string s3 = s1 + '\n';
//	cout << s3;
//	return 0;
//}


//int main()
//{
//	string s1;
//	while (getline(cin, s1))
//	{
//		if (!s1.empty())
//			cout << s1 << endl;
//	}
//	return 0;
//}


//int main()
//{
//	string word;
//	while (cin >> word)
//	{
//		if (!word.empty())
//			cout << word << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	if (s1 == s2)
//		cout << "正确" << endl;
//	else if (s1 < s2)
//		cout << "s1 < s2" << endl;
//	else
//		cout << "s1 > s2" << endl;
//	return 0;
//}


//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	if (s1.size() == s2.size())
//		cout << "=";
//	else if (s1.size() < s2.size())
//		cout << "<";
//	else
//		cout << ">";
//	return 0;
//}


//int main()
//{
//	string s1;
//	string line;
//	while (cin >> s1)
//	{
//		line = line + s1;
//	}
//	cout << line << endl;
//	return 0;
//}


//int main()
//{
//	string s1;
//	string line;
//	while (cin >> s1)
//	{
//		line = line + s1 + " ";
//	}
//	cout << line << endl;
//	return 0;
//}


//int main()
//{
//	string s("hello world!!!");
//	for (auto &c : s)
//	{
//		c = toupper(c);
//	}
//	cout << s << endl;
//	return 0;
//}


//int main()
//{
//	string s1 = "hello world!";
//	if(!s1.empty())
//	for (auto &c : s1)
//	{
//		c = 'X';
//	}
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1 = "hello world!";
//	if(!s1.empty())
//	for (char c : s1)
//	{
//		c = 'X';
//	}
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1 = "hello world!";
//	/*int n = 0;
//	while (n != s1.size())
//		s1[n++] = 'X';
//	cout << s1 << endl;*/
//	for (int i = 0; i < s1.size(); i++)
//		s1[i] = 'X';
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1 = "hello world!my have.some,food!";
//	string s2;
//	for (auto& c : s1)
//	{
//		if (!ispunct(c))
//			s2 = s2 + c;
//		else
//			s2 = s2 + " ";
//	}
//	cout << s2 << endl;
//	return 0;
//}


//int main()
//{
//	int word;
//	vector<int>s1;
//	while (cin >> word)
//		s1.push_back(word);
//	string line;
//	vector<string>s3;
//	while (cin >> line)
//		if (!line.empty())
//			s3.push_back(line);
//	return 0;
//}


//int main()
//{
//	string s1;
//	vector<string>s2;
//	while (cin >> s1)
//		s2.push_back(s1);
//	cout << "result:" << endl;
//	for (auto &c : s2) //c是容器中的string对象
//	{
//		for(auto &mem:c) //mem是string中的char对象
//			mem = toupper(mem);
//		cout << c << endl;
//	}
//	return 0;
//}


//int main()
//{
//	vector<int>line;
//	int val;
//	while (cin >> val)
//		line.push_back(val);
//	if (line.size() == 0)
//		return -1;
//	cout << "add:" << endl;
//	for (decltype(line.size())i = 0; i < line.size(); i += 2)
//	{
//		cout << line[i] + line[i + 1] << " ";
//		if ((i + 2) % 10 == 0)
//			cout << endl;
//	}
//	if (line.size() % 2 != 0)
//		cout << line[line.size() - 1];
//	return 0;
//}


//int main()
//{
//	vector<int>line;
//	int mum = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		cin >> mum;
//		line.push_back(mum);
//	}
//	for (auto b = line.begin(); b != line.end(); b++)
//		cout << *b << " ";
//	cout << endl;
//	for (auto c = line.begin(); c != line.end(); c++)
//		*c *= 2;
//	for (auto b = line.begin(); b != line.end(); b++)
//		cout << *b << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	int line[10];
//	for (int i = 0; i < 10; i++)
//		line[i] = i;
//	for (auto c : line)
//		cout << c <<" ";
//	cout << endl;
//	int line1[10];
//	for (int i = 0; i < 10; i++)
//		line1[i] = line[i];
//	for (auto c : line1)
//		cout << c << " ";
//	cout << endl;
//	vector<int>s1;
//	for (auto c : line)
//		s1.push_back(c);
//	for (auto &c : s1)
//		cout << c << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	int str[] = { 1,2,3,4,5,6 };
//	vector<int>line(begin(str), end(str));
//	for (auto val : line)
//		cout << val << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	for (auto& c : a)
//		for (auto b : c)
//			cout << b << " ";
//	cout << endl;
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 4; j++)
//			cout << a[i][j] << " ";
//	cout << endl;
//	for (int(*p)[4] = a; p != a + 3; p++) // p指向一个有4个元素的数组的指针
//		for (int* q = *p; q != *p + 4; q++) // q是指向数组中的元素的指针
//			cout << *q << " ";
//	cout << endl;
//	return 0;
//}


