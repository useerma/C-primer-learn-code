//#include"biao.h";

//using T = vector<int>::const_iterator;
//bool finder(vector<int>::const_iterator b, vector<int>::const_iterator e, int val)
//{
//	while (b != e)
//	{
//		if (*b++ == val)
//			return true;
//	}
//	return false;
//}
//
//T finder2(T begin, T end, int val)
//{
//	while (begin != end)
//	{
//		if (*begin == val)
//			return begin;
//		begin++;
//	}
//	cout << "NO FIND" << endl;
//	return end;
//}
//int main()
//{
//	std::list<std::deque<int>> lister;
//	vector<int> arr{ 1,2,3,4,5,6 };
//	auto begin = arr.begin();
//	auto end = arr.end();
//	cout << finder(begin, end, 1) << endl;
//	cout << *finder2(begin, end, 3) << endl;
//	return 0;
//}


//int main()
//{
//	std::list<int> arr = { 1,2,3,4,5,6 };
//	vector<double> arr2 = { 2,4,6,8,10,12 };
//	vector<double> words(arr.begin(), arr.end());
//	for (auto a : words)
//		cout << a << endl;
//	return 0;
//}


//int main()
//{
//	list<char*> tlist{'h'};
//	vector<string> svec;
//	svec.assign(tlist.begin(), tlist.end());
//	return 0;
//}


//bool equal(vector<int>& v, list<int>l)
//{
//	if (v.size() != l.size())
//		return false;
//	auto vbegin = v.begin();
//	auto vend = v.end();
//	auto lbegin = l.begin();
//	for (; vbegin != vend; vbegin++, lbegin++)
//		if (*vbegin != *lbegin)
//			return false;
//	return true;
//}
//
//int main()
//{
//	list<int> slit = { 1,2,3,4,5,6,7 };
//	vector<int> arr = { 1,2,3,4,5,6,7 };
//	cout << equal(arr, slit) << endl;
//	return 0;
//}


//void dequers(std::deque<string>& a, string word)
//{
//	a.push_back(word);
//}
//
//int main()
//{
//	std::deque<string> arr;
//	string word;
//	while (cin >> word)
//		dequers(arr, word);
//	auto begin = arr.begin();
//	while (begin != arr.end())
//		cout << *begin++ << " ";
//	cout << endl;
//	return 0;
//}


//void different(list<int> lists, deque<int>& even, deque<int>& odd)
//{
//	for (auto lister : lists)
//	{
//		if (lister % 2)
//			odd.push_back(lister);
//		else
//			even.push_back(lister);
//	}
//	auto begin = even.begin();
//	auto begin2 = odd.begin();
//	while (begin != even.end())
//		cout << *begin++ << " ";
//	cout << endl;
//	while (begin2 != odd.end())
//		cout << *begin2++ << " ";
//	cout << endl;
//}
//
//int main()
//{
//	list<int> ilists = { 1,2,3,4,5,6,7,8,9,10 };
//	std::deque<int> even;
//	std::deque<int> odd;
//	different(ilists, even, odd);
//	return 0;
//}



//int main()
//{
//	vector<int> vset = { 1,1,2,1 };
//	int val = 1;
//	vector<int>::iterator iter = vset.begin();
//	int size = vset.size(), new_ele = 0;
//	while (iter != (vset.begin() + size / 2 + new_ele))
//	{
//		if (*iter == val)
//		{
//			iter = vset.insert(iter, 2 * val);
//			new_ele++;
//			iter += 2;
//		}
//		else
//			iter++;
//	}
//	for (iter = vset.begin(); iter != vset.end(); iter++)
//		cout << *iter << " ";
//	cout << endl;
//	return 0;
//}



//int main()
//{
//	vector<int> vec;
//	cout << vec.at(0) << endl;
//	cout << vec[0] << endl;
//	cout << vec.front() << endl;
//	cout << *vec.begin() << endl;
//	return 0;
//}


//int main()
//{
//	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
//	vector<int> vec;
//	list<int> slist;
//	for (auto ao : ia)
//		vec.push_back(ao);
//	slist.insert(slist.begin(), vec.begin(), vec.end());
//	auto vbegin = vec.begin();
//	auto lbegin = slist.begin();
//	while (vbegin != vec.end())
//	{
//		if (*vbegin % 2)
//		{
//			vbegin++;
//			lbegin = slist.erase(lbegin);
//	    }
//		else
//		{
//			vbegin = vec.erase(vbegin);
//			lbegin++;
//		}
//	}
//	for (auto ve : vec)
//		cout << ve << " ";
//	cout << endl;
//	for (auto li : slist)
//		cout << li << " ";
//	cout << endl;
//	return 0;
//}



//int main()
//{
//	std::forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9,10 };
//	auto prev = flst.before_begin();
//	auto curr = flst.begin();
//	while (curr != flst.end())
//	{
//		if (*curr % 2)
//		{
//			curr = flst.erase_after(prev);
//		}
//		else
//		{
//			prev = curr++;
//		}
//	}
//	for (auto flster : flst)
//		cout << flster << " ";
//	cout << endl;
//	return 0;
//}



//void findinsert(std::forward_list<string> &arr, const string str1, const string str2)
//{
//	auto lbegin = arr.begin();
//	while (lbegin != arr.end())
//	{
//		if (*lbegin == str1)
//		{
//			arr.insert_after(lbegin, str2);
//			cout << "str2 inserted on str1" << endl;
//			return;
//		}
//		lbegin++;
//	}
//	auto lend = arr.end();
//	arr.insert_after(++lend, str2);
//	cout << "NO finded str1" << endl;
//	return;
//}
//
//string initalize(const vector<char> vec)
//{
//	static string s(vec.data(), vec.size());
//	return s;
//}
//
//void replacer(string &s, const string &oldval,const string &newval)
//{
//	auto len = oldval.size();
//	if (!len || !s.size()) 
//	{
//		cout << "error!" << endl;
//		return;
//	}
//	auto sbegin = s.begin();
//	while (sbegin <= s.end() - len) //末尾少于oldval长度的部分不用检查
//	{
//		auto iter1 = sbegin; //代替sbegin在s中遍历 
//		auto iter2 = oldval.begin();
//		while (iter2 != oldval.end() && *iter1 == *iter2)
//		{
//			iter1++;
//			iter2++;
//		}
//		if (iter2 == oldval.end()) //oldval耗尽
//		{
//			sbegin = s.erase(sbegin, iter1);  //一对迭代器删除
//			if (newval.size())
//			{
//				iter2 = newval.end();  //由后向前插入
//				do
//				{
//					iter2--;
//					sbegin = s.insert(sbegin, *iter2);
//				} while (iter2 > newval.begin());
//			}
//			sbegin += newval.size();
//		}
//		else
//		{
//			sbegin++;
//		}
//	}
//}
//
//
//void replace_string(string& s, const string& oldval, const string& newval)
//{
//	int p = 0;
//	while ((p = s.find(oldval, p)) != string::npos) //npos表示字符串中没有匹配位置，返回-1
//	{
//		s.replace(p, oldval.size(), newval);
//		p += newval.size();
//	}
//}
//
//void name_string(string& name, const string& prefix, const string& suffix)
//{
//	name.insert(name.begin(), 1, ' ');
//	name.insert(name.begin(), prefix.begin(), prefix.end());
//	name.append(" ");
//	name.append(suffix.begin(), suffix.end());
//}
//
//void name_string1(string& name, const string& prefix, const string& suffix)
//{
//	name.insert(name.begin(), prefix.begin(), prefix.end());
//	name.insert(name.end(), ' ');
//	name.insert(name.end(), suffix.begin(), suffix.end());
//}
//
//int main()
//{
//	string s = "tho thru thon";
//	string name = "James Bond";
//	//replacer(s, "thru", "through");
//	cout << s << endl;
//	replacer(s, "tho", "though");
//	cout << s << endl;
//	name_string(name, "Mr.", "II");
//	cout << name << endl;
//	return 0;
//}



//void find_char(string& s, const string& chars)
//{
//	string::size_type pos = 0;
//	while ((pos = s.find_first_of(chars, pos)) != string::npos)
//	{
//		cout << "pos:" << pos << endl;
//		cout << "chars:" << s[pos] << endl;
//		pos++;
//	}
//}



//void find_longest_word(std::ifstream& in)
//{
//	string s, longest_word;
//	int max_length = 0;
//	while (getline(in,s))
//	{
//		if (s.find_first_of("bdfghjklpqty") != string::npos)
//			continue;
//		cout << s << " ";
//		if (max_length < s.size())
//		{
//			max_length = s.size();
//			longest_word = s;
//		}
//	}
//}
//
//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		std::cerr << "No opened!" << endl;
//		return -1;
//	}
//	find_longest_word(in);
//	return 0;
//}



//int main()
//{
//	vector<string> vs = { "123","+456","-789" };
//	int sum = 0;
//	for (auto iter = vs.begin(); iter != vs.end(); iter++)
//		sum += stoi(*iter);
//	cout << sum << endl;
//	return 0;
//}



//int main()
//{
//	string dates[] = { "Jan 1,2024","February 1 2014","3,1,2014","3 10 2014 "};
//	try
//	{
//		for (auto ds : dates)
//		{
//			date d1(ds);
//			cout << d1;
//		}
//	}
//	catch (std::invalid_argument e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


