//#include"biao.h"

//int main()
//{
//	std::map<string, size_t> words_count;
//	string word;
//	while (cin >> word)
//		++words_count[word];
//	for (const auto& w : words_count)
//		cout << w.first << " " << w.second << endl;
//	return 0;
//}


//string& trans(string& s)
//{
//	for (int p = 0; p < s.size(); p++)
//	{
//		if (s[p] >= 'A' && s[p] <= 'Z')
//			s[p] -= ('A' - 'a');
//		else if (s[p] == ',' || s[p] == '.')
//			s.erase(p, 1);
//	}
//	return s;
//}
//
//
//int main()
//{
//	std::map<string, size_t> words_count;
//	string word;
//	while (cin >> word)
//		++words_count[trans(word)];
//	for (const auto& w : words_count)
//		cout << w.first << " " << w.second << endl;
//	return 0;
//}


//void add_family(std::map<string, vector<string>>& familes, const string& family)
//{
//	if (familes.find(family) == familes.end())
//		familes[family] = vector<string>();  //创建空vector
//}
//
//void add_child(std::map<string, vector<string>>& familes, const string& family, const string& child)
//{
//	familes[family].push_back(child);
//}
//int main()
//{
//	std::map<string, vector<string>> fcount;
//	add_family(fcount, "林");
//	add_child(fcount, "林","林鱼勋");
//	add_child(fcount, "林", "林聪");
//	add_family(fcount, "周");
//	for (auto c : fcount)
//	{
//		cout << c.first << " ";
//		for (auto f : c.second)
//			cout << f << " ";
//		cout << endl;
//	}
//	return 0;
//}


//string &trans(string& s)
//{
//	for (int p = 0; p < s.size(); p++)
//	{
//		if (s[p] >= 'A' && s[p] <= 'Z')
//			s[p] -= ('A' - 'a');
//		else if (s[p] == ',' || s[p] == '.')
//			s.erase(p, 1);
//	}
//	return s;
//}
//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		cout << "open of false!" << endl;
//		exit(1);
//	}
//	std::map<string, list<int>> word_line;
//	string line;
//	string word;
//	int lineno = 0;
//	while (getline(in, line))
//	{
//		lineno++;
//		std::istringstream l_in(line);
//		while (l_in >> word)
//		{
//			trans(word);
//			word_line[word].push_back(lineno);
//		}
//	}
//	for (const auto& w : word_line)
//	{
//		cout << w.first << "行：";
//		for (const auto& i : w.second)
//			cout << i << " ";
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	vector<std::pair<string, int>> data;
//	string s;
//	int v;
//	while (in >> s && in >> v)
//		data.push_back(pair<string, int>(s, v));
//	//data.push_back({s,v});
//	//data.push_back(make_pair(s,v));
//	for (const auto& d : data)
//		cout << d.first << " " << d.second << endl;
//	return 0;
//}



//void add_family(std::map<string, vector<pair<string, string>>>& families, const string& family)
//{
//	families[family];
//}
//
//void add_child(std::map<string, vector<pair<string, string>>>& families, const string& family, const string& child, const string& birth)
//{
//	families[family].push_back({ child,birth });  //pair与关联容器结合使用
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		cout << "NO open" << endl;
//		exit(1);
//	}
//	std::map<string, size_t> word_count;
//	string word;
//	while (in >> word)
//	{
//		auto ret = word_count.insert({ word,1 });
//		if (!ret.second)
//			++ret.first->second;
//		// ++word_count,insert({word,0}).first->second;
//	}
//	for (const auto& w : word_count)
//		cout << w.first << " " << w.second << endl;
//	return 0;
//}


//void remove_author(std::multimap<string, string>& books, const string& author)
//{
//	auto pos = books.equal_range(author);
//	if (pos.first == pos.second)
//		cout << "no author:" << author << endl;
//	else
//		books.erase(pos.first, pos.second);
//}
//
//void print_books(std::multimap<string, string>& books)
//{
//	cout << "present booksname:" << endl;
//	for (auto& book : books)
//		cout << book.first << " " << book.second << endl;
//	cout << endl;
//}
//
//int main()
//{
//	std::multimap<string, string> books;
//	books.insert({ "yuxunlin","菜狗是如何炼成" });
//	books.insert({ "金庸","天龙八部" });
//	print_books(books);
//	remove_author(books, "zhangsan");
//	remove_author(books, "金庸");
//	print_books(books);
//	return 0;
//}


//std::map<string, string> buildmap(std::ifstream& map_file) //将转换规则从文件写入map中
//{
//	std::map<string, string> trans_map; //创建map
//	string key;  //临时保存key
//	string value;  //替换的内容
//	while (map_file >> key && getline(map_file, value))  //读取第一个单词进入key中，剩余内容存入value
//		if (value.size() > 1) //检查是否有转换规则
//			trans_map[key] = value.substr(1); //跳过key与规则之间的空格，并存入value
//		else
//			throw std::runtime_error("no rule for " + key);  //若无规则，则抛出异常
//	return trans_map; //返回转换规则map
//}
//
//const string& transform(const string& s, const std::map<string, string>& m)  //单词转换
//{
//	auto map_it = m.find(s); //在转换规则map寻找s
//	if (map_it != m.cend())  
//		return map_it->second;  //存在则使用替换短语
//	else
//		return s; 
//}
//void word_transform(std::ifstream& map_file, std::ifstream& input)
//{
//	auto trans_map = buildmap(map_file);  //建立并保存转换规则map
//	string text;   //临时保存读取数据
//	while (getline(input, text))   //读取一行输出
//	{
//		std::istringstream stream(text);  //string流，用于读取每个单词
//		string word;  //临时保存读取单词数据
//		bool firstword = true;  //用于控制是否打印空格
//		while (stream >> word) 
//		{
//			if (firstword)
//				firstword = false;  //修改状态
//			else
//				cout << " "; //打印空格
//			cout << transform(word, trans_map); //转换
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	std::ifstream in("file.txt");
//	std::ifstream in2("input.txt");
//	word_transform(in, in2);
//	return 0;
//}
