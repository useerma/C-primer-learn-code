//#include"biao.h"

//int main()
//{
//	vector<int> arr;
//	int val;
//	while (cin >> val )
//		arr.push_back(val);
//	cout << "number:" << count(arr.begin(), arr.end(), 6) << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> arr = { 1,2,3,4,5,6 };
//	cout << std::accumulate(arr.cbegin(), arr.cend(), 0) << endl;
//	std::fill_n(arr.begin(), arr.size(), 0);
//	for (auto a : arr)
//		cout << a << " ";
//	cout << endl;
//	return 0;
//}


//inline void out_print(const vector<string> arr)
//{
//	for (auto er : arr)
//		cout << er << " ";
//	cout << endl;
//}
//
//void elimDups(vector<string> words)
//{
//	out_print(words);
//	sort(words.begin(), words.end());
//	out_print(words);
//	auto end_unique = std::unique(words.begin(), words.end());
//	out_print(words);
//	words.erase(end_unique, words.end());
//	out_print(words);
//}
//
//int main()
//{
//	vector<string>str;
//	string word;
//	while (cin >> word)
//		str.push_back(word);
//	elimDups(str);
//	return 0;
//}


//void out_words(vector<string>& words)
//{
//	for (auto iter = words.begin(); iter != words.end(); iter++)
//		cout << *iter << " ";
//	cout << endl;
//}
//
//bool isshorter(const string& s1, const string& s2)
//{
//	return s1.size() < s2.size();
//}

//void elimdups(vector<string>& words)
//{
//	out_words(words);
//	sort(words.begin(), words.end());
//	out_words(words);
//	auto end_unique = unique(words.begin(), words.end());
//	out_words(words);
//	words.erase(end_unique, words.end());
//	out_words(words);
//	stable_sort(words.begin(), words.end(), isshorter);
//	out_words(words);
//}

//void add(int a)
//{
//	auto sum = [a](int b) {return a + b; };
//	cout << sum(1) << endl;  
//}
//
//int main()
//{
//	auto f = [](const int a, const int b)->int {return a + b; };
//	return 0;
//}


//void biggies(vector<string>& words, vector<string>::size_type sz)
//{
//	out_words(words);
//	auto c = count_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz; });
//	cout << c << endl;
//}
//
//
//void lumt(void)
//{
//	int i = 5;
//	auto f = [i]() mutable -> bool {if (i > 0) { i++; return false; } else { return true; }};
//	for (int g = 0; g < i; g++)
//		cout << f() << " ";
//	cout << endl;
//}

//int main()
//{
//	vector<int> arr1 = { 1,1,2,3,3,4,5,5,68,87 };
//	list<int> arr2;
//	std::unique_copy(arr1.begin(), arr1.end(), back_inserter(arr2));
//	for (auto a : arr2)
//		cout << a << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
//	vector<int> arr1;
//	vector<int> arr2;
//	list<int> arr3;
//	for (auto a : arr)
//		cout << a << " ";
//	cout << endl;
//	std::copy(arr.begin(), arr.end(), inserter(arr1, arr1.begin()));
//	for (auto b : arr1)
//		cout << b << " ";
//	cout << endl;
//	std::copy(arr.begin(), arr.end(), back_inserter(arr2));
//	for (auto c : arr2)
//		cout << c << " ";
//	cout << endl;
//	std::copy(arr.begin(), arr.end(), front_inserter(arr3));
//	for (auto d : arr3)
//		cout << d << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	std::istream_iterator<string> inter(in);
//	std::istream_iterator<string> eof;
//	vector<string> words;
//	while (inter != eof)
//		words.push_back(*inter++);
//	for (auto er : words)
//		cout << er << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	std::istream_iterator<int> inter(cin);
//	std::istream_iterator<int> eof;
//	vector<int> arr;
//	while (inter != eof)
//		arr.push_back(*inter++);
//	sort(arr.begin(), arr.end());
//	std::ostream_iterator<int> out_iter(cout, " ");
//	copy(arr.begin(), arr.end(), out_iter);
//	cout << endl;
//	unique_copy(arr.begin(), arr.end(), out_iter);
//	return 0;
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	std::ofstream out1("out1.txt");
//	std::ofstream out2("out2.txt");
//	std::istream_iterator<int> inter(in);
//	std::istream_iterator<int> eof;
//	std::ostream_iterator<int> out_iter(out1, " ");
//	std::ostream_iterator<int> out_inter(out2, "\n");
//	while (inter != eof)
//	{
//		if (*inter % 2)
//			*out_iter++ = *inter;
//		else
//			*out_inter++ = *inter;
//		inter++;
//	}
//	return 0;
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	vector<int> arr;
//	int n;
//	while (in >> n)
//		arr.push_back(n);
//	for (auto iter = arr.crbegin(); iter != arr.crend(); iter++)
//		cout << *iter << " ";
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	list<int> li = { 0,1,2,3,4,0,5,6,8 };
//	auto last = find(li.rbegin(), li.rend(),0);
//	last++;
//	int p = 1;
//	for (auto iter = li.begin(); iter != last.base(); iter++, p++) //计算链表头到最后的0的距离
//		;
//	if (p >= li.size())
//		cout << "NO 0" << endl;
//	else
//		cout << p << endl;
//	return 0;
//}


//int main()
//{
//	std::ostream_iterator<int> out_iter(cout, " ");
//	vector<int> arr = { 0,1,2,3,4,5,6,7,8,9 };
//	list<int> li;
//	vector<int>::reverse_iterator re(arr.begin() + 2);
//	vector<int>::reverse_iterator rb(arr.begin() + 7);;
//	copy(rb, re, back_inserter(li));
//	copy(li.begin(), li.end(), out_iter);
//	cout << endl;
//	return 0;
//}