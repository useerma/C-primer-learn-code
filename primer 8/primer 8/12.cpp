//#define _CRT_SECURE_NO_WARNINGS
//#include"strblob.h"
//#include<cstring>
//#include<memory>
//#include <set>

//int main()
//{
//	strblob b1;
//	{
//		strblob b2 = { "an","on","in" };
//		b1 = b2;
//		b2.push_back("body");
//		cout << b2.size();
//	}
//	cout << b1.size() << endl;
//	cout << b1.front() << " " << b1.back() << endl;
//	const strblob b3 = b1;
//	cout << b3.front() << " " << b3.back() << endl;
//	return 0;
//}



//vector<int>* newvec(void)
//{
//	return new (std::nothrow) vector<int>();
//}
//
//void read(vector<int>* pv)
//{
//	int v;
//	while (cin >> v)
//		pv->push_back(v);
//}
//
//void print(vector<int>* pv)
//{
//	for (const auto& v : *pv)
//		cout << v << " ";
//	cout << endl;
//}
//
//int main()
//{
//	vector<int>* pv = newvec();
//	if (!pv)
//	{
//		cout << "no space" << endl;
//		return -1;
//	}
//	read(pv);
//	print(pv);
//	delete pv;
//	pv = nullptr;
//	return 0;
//}


//struct destination{};
//struct connection{};
//
//connection connect(destination* pd)
//{
//	cout << "open connect" << endl;
//	return connection();
//}
//
//void disconnect(connection c)
//{
//	cout << "close connect" << endl;
//}
//
//void f(destination& d)
//{
//	cout << "gular connect" << endl;
//	connection c = connect(&d);
//	//发生异常，未调用disconnect关闭连接
//	cout << endl;
//}
//
//void end_connection(connection* p)
//{
//	disconnect(*p);
//}
//
//void f1(destination& d)
//{
//	cout << "shared_ptr" << endl;
//	connection c = connect(&d);
//	std::shared_ptr<connection> p(&c, end_connection);
//	//发生异常，未关闭连接
//	cout << endl;
//}
//
//void f2(destination& d)
//{
//	cout << "shared_ptr" << endl;
//	connection c = connect(&d);
//	std::shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); });
//	//发生异常
//	cout << endl;
//}
//int main()
//{
//	destination d;
//	f(d);
//	f1(d);
//	f2(d);
//	return 0;
//}


//class strblobptr {
//	friend bool eq(const strblobptr&, const strblobptr&);  //比较相等
//public:
//	strblobptr() : curr(0) {}
//	strblobptr(strblob& a,size_t sz = 0) : wptr(a.data),curr(sz) {}
//	string& deref() const;  //解引用
//	strblobptr& incr();   //递增
//	strblobptr& decr();   //递减
//private:
//	size_t curr;  //数组中的位置
//	std::shared_ptr<vector<string>> check(size_t, const string&) const; //检查curr是否在数组中，返回一个shared_ptr
//	std::weak_ptr<vector<string>> wptr;  //保存一个weak_ptr
//};
//
//inline std::shared_ptr<vector<string>> strblobptr::check(size_t i, const string& msg) const
//{
//	auto ret = wptr.lock(); //返回shared_ptr
//	if (!ret)
//		throw std::runtime_error("unbound ptr");
//	if (i >= ret->size())
//		throw std::out_of_range(msg);
//	return ret; //返回指向vector的shared_ptr
//}
//
//inline string& strblobptr::deref() const    
//{
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];   //解引用指针，得到vector
//}
//
//
//inline strblobptr& strblobptr::incr()
//{
//	check(curr, "increment past end");
//	++curr;     //推进位置
//	return *this;   //返回对象的引用
//}
//
//inline strblobptr& strblobptr::decr()
//{
//	--curr;
//	check(-1, "decrement past begin");
//	return *this;
//}
//
//inline strblobptr strblob::begin()  //begin函数
//{
//	return strblobptr(*this);  //把strblob的shared_ptr传递给strblobptr的构造函数
//}
//
//inline strblobptr strblob::end()   //end函数
//{
//	auto ret = strblobptr(*this, data->size());  //跟begin一样，但多个大小参数
//	return ret;
//}
//
//inline bool eq(const strblobptr& ls, const strblobptr& rs)  //比较
//{
//	auto l = ls.wptr.lock(), r = rs.wptr.lock();   //shared_ptr指针
//	if (l == r)   //底层vector相等
//		return (!r || ls.curr == rs.curr);  //指针为空或指向相同元素，则相等
//	else
//		return false;
//}
//
//
//inline bool neq(const strblobptr& ls, const strblobptr& rs)
//{
//	return !eq(ls, rs);
//}
//int main()
//{
//	strblob b1;
//	{
//		strblob b2 = { "a","an","the" };
//		b1 = b2;
//		b2.push_back("hello");
//		cout << b2.size() << endl;
//	}
//	cout << b1.size() << endl;
//	const strblob b3 = b1;
//	cout << b3.front() << " " << b3.back() << endl;
//	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
//		cout << it.deref() << endl;
//	return 0;
//}


//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		cout << "no open the file" << endl;
//		return -1;
//	}
//	strblob b;
//	string s;
//	while (getline(in, s))
//		b.push_back(s);
//	for (auto it = b.begin(); neq(it, b.end()); it.incr())
//		cout << it.deref() << endl;
//	return 0;
//}


//int main()
//{
//	const char* c1 = "hello";
//	const char* c2 = "world";
//	char* r = new char[strlen(c1) + strlen(c2) + 1];
//	strcpy(r, c1);
//	strcat(r, c2);
//	cout << r << endl;
//	
//	string s1 = "hello";
//	string s2 = "world";
//	strcpy(r, (s1 + s2).c_str());
//	cout << r << endl;
//	delete[] r;
//	return 0;
//}


//int main()
//{
//	char c;
//	char* r = new char[10];
//	int l = 0;
//	while (cin.get(c))
//	{
//		if (isspace(c))
//			break;
//		r[l++] = c;
//		if (l == 10)
//		{
//			cout << "reach key" << endl;
//			break;
//		}
//	}
//	r[l] = 0;
//	cout << r << endl;
//	return 0;
//}


//int main()
//{
//	std::allocator<string> alloc;
//	auto const p = alloc.allocate(20); //分配内存
//	string s;
//	string* q = p;  //q用来移动
//	while (cin >> s && q != p + 20) 
//		alloc.construct(q++, s);  //用s来初始化q
//	const size_t size = q - p;  //读取了多少内存
//	for (size_t i = 0; i < size; i++)   //用下标来访问
//		cout << p[i] << " " << endl;
//	while (q != p)  //删除已构造的string
//		alloc.destroy(--q);
//	alloc.deallocate(p, 20);  //释放内存
//	return 0;
//}


//vector<string> file;
//std::map<string, std::set<vector<string>::size_type>> wm;
//string cleanup(const string& word)
//{
//	string ret;
//	for (auto it = word.begin(); it != word.end(); ++it)
//	{
//		if (!ispunct(*it))
//			ret += tolower(*it);
//	}
//	return ret;
//}
//
//void input_text(std::ifstream& is)
//{
//	string text;
//	while (getline(is, text))
//	{
//		file.push_back(text);
//		int n = file.size() + 1;
//		std::istringstream line(text);
//		string word;
//		while (line >> word)
//			wm[cleanup(word)].insert(n);
//	}
//}
//
//ostream& query_print(const string& sought, ostream& os)
//{
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//	{
//		os << sought << " append zero time" << endl;
//	}
//	else
//	{
//		auto lines = loc->second;
//		os << sought << " append " << lines.size() << " times" << endl;
//		for (auto num : lines)
//			os << "\t" << num + 1 << " hang " << *(file.begin() + num) << endl;
//	}
//	return os;
//}
//void runqueries(std::ifstream& in)
//{
//	input_text(in);
//	while (true)
//	{
//		cout << "enter word or quit:";
//		string s;
//		if (!(cin >> s) || s == "quit") break;
//		query_print(s, cout) << endl;
//	}
//}
//
//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		std::cerr << "no open file" << endl;
//		return EXIT_FAILURE;
//	}
//	runqueries(in);
//	return 0;
//}

//class queryresult; //未定义，但使用到，先声明
//class textquery  //保存输入文件
//{
//public:
//	using line_no = std::vector<std::string>::size_type; //类型别名
//	textquery(std::ifstream&); //构造函数，接受一个文件流为参数
//	queryresult query(const std::string&) const; //
//private:
//	std::shared_ptr<std::vector<string>> file; //输入文件
//	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; //用查找的单词做关键字，保存行号的set做值
//};
//
//textquery::textquery(std::ifstream& is) : file(new vector<string>)
//{
//	string text;
//	while (getline(is, text))
//	{
//		file->push_back(text); //保存每一行，file是指针，需解引用
//		int n = file->size() - 1;  //当前行号
//		std::istringstream line(text); //分解成单个单词
//		string word;
//		while(line >> word) 
//		{
//			auto& line = wm[word]; //line与wm[word]绑定，line是智能指针
//			if (!line)  //若单词不在wm中，返回一个空指针
//				line.reset(new std::set<line_no>); //指针指向新创建的set
//			line->insert(n); //将行号插入set中
//
//		}
//	}
//}
//
//class queryresult {
//	friend std::ostream& printis(std::ostream&, const queryresult&); //友元声明
//public:
//	queryresult(std::string s,std::shared_ptr<std::set<textquery::line_no>> p,std::shared_ptr<std::vector<std::string>> f):  //构造函数
//		sought(s), lines(p),file(f) {}
//private:
//	std::string sought;  //查找的单词
//	std::shared_ptr<std::set<textquery::line_no>> lines;  //指向保存单词出现的行号的set
//	std::shared_ptr<std::vector<std::string>> file;  //指向保存文件的vector
//};
//
//queryresult textquery::query(const string& sought) const  //查找单词
//{
//	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>); //空set
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//		return queryresult(sought, nodata, file); //未找到
//	else
//		return queryresult(sought, loc->second, file);
//}
//
//string make_plural(size_t ctr, const string& word, const string& ending)
//{     //make_plural根据大小是否等于1来打印time或times
//	return (ctr > 1) ? word + ending : word;
//}
//std::ostream& printis(std::ostream& os, const queryresult& qr)
//{   
//	os << qr.sought << "occurs" << qr.lines->size() << " " << make_plural(qr.lines->size(),"time","s") << endl;
//	for (auto num : *qr.lines)
//		os << "\tline" << num + 1 << " " << *(qr.file->begin() + num) << endl;
//	return os;
//}
//void runque(std::ifstream& in)  //主函数
//{
//	textquery tq(in);
//	while(true)
//	{
//		cout << "enter word or quit:";  //输入查找单词或退出指令
//		string s;
//		if (!(cin >> s) || s == "quit") break; // 退出指令
//		printis(cout, tq.query(s)) << endl; //打印且把参数传入tq.query
//	}
//}
//
//int main()
//{
//	std::ifstream in("arr.txt");
//	if (!in)
//	{
//		std::cerr << "no input file" << endl;
//		return -1;
//	}
//	runque(in);
//	return 0;
//}
