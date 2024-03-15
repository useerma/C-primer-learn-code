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
//		familes[family] = vector<string>();  //������vector
//}
//
//void add_child(std::map<string, vector<string>>& familes, const string& family, const string& child)
//{
//	familes[family].push_back(child);
//}
//int main()
//{
//	std::map<string, vector<string>> fcount;
//	add_family(fcount, "��");
//	add_child(fcount, "��","����ѫ");
//	add_child(fcount, "��", "�ִ�");
//	add_family(fcount, "��");
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
//		cout << w.first << "�У�";
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
//	families[family].push_back({ child,birth });  //pair������������ʹ��
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
//	books.insert({ "yuxunlin","�˹����������" });
//	books.insert({ "��ӹ","�����˲�" });
//	print_books(books);
//	remove_author(books, "zhangsan");
//	remove_author(books, "��ӹ");
//	print_books(books);
//	return 0;
//}


//std::map<string, string> buildmap(std::ifstream& map_file) //��ת��������ļ�д��map��
//{
//	std::map<string, string> trans_map; //����map
//	string key;  //��ʱ����key
//	string value;  //�滻������
//	while (map_file >> key && getline(map_file, value))  //��ȡ��һ�����ʽ���key�У�ʣ�����ݴ���value
//		if (value.size() > 1) //����Ƿ���ת������
//			trans_map[key] = value.substr(1); //����key�����֮��Ŀո񣬲�����value
//		else
//			throw std::runtime_error("no rule for " + key);  //���޹������׳��쳣
//	return trans_map; //����ת������map
//}
//
//const string& transform(const string& s, const std::map<string, string>& m)  //����ת��
//{
//	auto map_it = m.find(s); //��ת������mapѰ��s
//	if (map_it != m.cend())  
//		return map_it->second;  //������ʹ���滻����
//	else
//		return s; 
//}
//void word_transform(std::ifstream& map_file, std::ifstream& input)
//{
//	auto trans_map = buildmap(map_file);  //����������ת������map
//	string text;   //��ʱ�����ȡ����
//	while (getline(input, text))   //��ȡһ�����
//	{
//		std::istringstream stream(text);  //string�������ڶ�ȡÿ������
//		string word;  //��ʱ�����ȡ��������
//		bool firstword = true;  //���ڿ����Ƿ��ӡ�ո�
//		while (stream >> word) 
//		{
//			if (firstword)
//				firstword = false;  //�޸�״̬
//			else
//				cout << " "; //��ӡ�ո�
//			cout << transform(word, trans_map); //ת��
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
