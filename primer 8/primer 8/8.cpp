//#include"biao.h"

//istream& f(istream& in)
//{
//	int v;
//	while (in >> v || !in.eof())
//	{
//		if (in.bad())
//			throw std::runtime_error("IO error");
//		if (in.fail())
//		{
//			std::cerr << "data append error" << endl;
//			in.clear();
//			in.ignore(2, '\n');
//			continue;
//		}
//		cout << v << endl;
//	}
//	in.clear();
//	return in;
//}

//int main()
//{
//	f(cin);
//	return 0;
//}



//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		std::cerr << "No open this data" << endl;
//		return -1;
//	}
//	string line;
//	vector<string> words;
//	while (in >> line)
//	{
//		words.push_back(line);
//	}
//	in.close();
//	auto it = words.begin();
//	while (it != words.end())
//		cout << *it++ << endl;
//	return 0;
//}



//istream& f2(istream& in)
//{
//	string v;
//	while (in >> v, !in.eof())
//	{
//		if (in.bad())
//			throw std::runtime_error("IO error");
//		if (in.fail())
//		{
//			std::cerr << " data append error" << endl;
//			in.clear();
//			in.ignore(100, '\n');
//			continue;
//		}
//		cout << v << endl;
//	}
//	in.clear();
//	return in;
//}

//int main()
//{
//	std::ostringstream msg;
//	msg << "C++ primer five" << endl;
//	std::istringstream in(msg.str());
//	f2(in);
//	return 0;
//}


//struct personinfo
//{
//	string name;
//	vector<string> phones;
//};

//int main()
//{
//	string line, word;
//	vector<personinfo>people;
//	std::stringstream record;
//	while (getline(cin, line))
//	{
//		personinfo lisan;
//		record.clear();
//		record.str(line);
//		record >> lisan.name;
//		while (record >> word)
//			lisan.phones.push_back(word);
//		people.push_back(lisan);
//	}
//	for (auto a : people)
//	{
//		cout << a.name << " ";
//		for (auto begin : a.phones)
//		{
//			cout << begin << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}