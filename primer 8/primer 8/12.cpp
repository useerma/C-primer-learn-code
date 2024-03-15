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
//	//�����쳣��δ����disconnect�ر�����
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
//	//�����쳣��δ�ر�����
//	cout << endl;
//}
//
//void f2(destination& d)
//{
//	cout << "shared_ptr" << endl;
//	connection c = connect(&d);
//	std::shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); });
//	//�����쳣
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
//	friend bool eq(const strblobptr&, const strblobptr&);  //�Ƚ����
//public:
//	strblobptr() : curr(0) {}
//	strblobptr(strblob& a,size_t sz = 0) : wptr(a.data),curr(sz) {}
//	string& deref() const;  //������
//	strblobptr& incr();   //����
//	strblobptr& decr();   //�ݼ�
//private:
//	size_t curr;  //�����е�λ��
//	std::shared_ptr<vector<string>> check(size_t, const string&) const; //���curr�Ƿ��������У�����һ��shared_ptr
//	std::weak_ptr<vector<string>> wptr;  //����һ��weak_ptr
//};
//
//inline std::shared_ptr<vector<string>> strblobptr::check(size_t i, const string& msg) const
//{
//	auto ret = wptr.lock(); //����shared_ptr
//	if (!ret)
//		throw std::runtime_error("unbound ptr");
//	if (i >= ret->size())
//		throw std::out_of_range(msg);
//	return ret; //����ָ��vector��shared_ptr
//}
//
//inline string& strblobptr::deref() const    
//{
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];   //������ָ�룬�õ�vector
//}
//
//
//inline strblobptr& strblobptr::incr()
//{
//	check(curr, "increment past end");
//	++curr;     //�ƽ�λ��
//	return *this;   //���ض��������
//}
//
//inline strblobptr& strblobptr::decr()
//{
//	--curr;
//	check(-1, "decrement past begin");
//	return *this;
//}
//
//inline strblobptr strblob::begin()  //begin����
//{
//	return strblobptr(*this);  //��strblob��shared_ptr���ݸ�strblobptr�Ĺ��캯��
//}
//
//inline strblobptr strblob::end()   //end����
//{
//	auto ret = strblobptr(*this, data->size());  //��beginһ�����������С����
//	return ret;
//}
//
//inline bool eq(const strblobptr& ls, const strblobptr& rs)  //�Ƚ�
//{
//	auto l = ls.wptr.lock(), r = rs.wptr.lock();   //shared_ptrָ��
//	if (l == r)   //�ײ�vector���
//		return (!r || ls.curr == rs.curr);  //ָ��Ϊ�ջ�ָ����ͬԪ�أ������
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
//	auto const p = alloc.allocate(20); //�����ڴ�
//	string s;
//	string* q = p;  //q�����ƶ�
//	while (cin >> s && q != p + 20) 
//		alloc.construct(q++, s);  //��s����ʼ��q
//	const size_t size = q - p;  //��ȡ�˶����ڴ�
//	for (size_t i = 0; i < size; i++)   //���±�������
//		cout << p[i] << " " << endl;
//	while (q != p)  //ɾ���ѹ����string
//		alloc.destroy(--q);
//	alloc.deallocate(p, 20);  //�ͷ��ڴ�
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

//class queryresult; //δ���壬��ʹ�õ���������
//class textquery  //���������ļ�
//{
//public:
//	using line_no = std::vector<std::string>::size_type; //���ͱ���
//	textquery(std::ifstream&); //���캯��������һ���ļ���Ϊ����
//	queryresult query(const std::string&) const; //
//private:
//	std::shared_ptr<std::vector<string>> file; //�����ļ�
//	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; //�ò��ҵĵ������ؼ��֣������кŵ�set��ֵ
//};
//
//textquery::textquery(std::ifstream& is) : file(new vector<string>)
//{
//	string text;
//	while (getline(is, text))
//	{
//		file->push_back(text); //����ÿһ�У�file��ָ�룬�������
//		int n = file->size() - 1;  //��ǰ�к�
//		std::istringstream line(text); //�ֽ�ɵ�������
//		string word;
//		while(line >> word) 
//		{
//			auto& line = wm[word]; //line��wm[word]�󶨣�line������ָ��
//			if (!line)  //�����ʲ���wm�У�����һ����ָ��
//				line.reset(new std::set<line_no>); //ָ��ָ���´�����set
//			line->insert(n); //���кŲ���set��
//
//		}
//	}
//}
//
//class queryresult {
//	friend std::ostream& printis(std::ostream&, const queryresult&); //��Ԫ����
//public:
//	queryresult(std::string s,std::shared_ptr<std::set<textquery::line_no>> p,std::shared_ptr<std::vector<std::string>> f):  //���캯��
//		sought(s), lines(p),file(f) {}
//private:
//	std::string sought;  //���ҵĵ���
//	std::shared_ptr<std::set<textquery::line_no>> lines;  //ָ�򱣴浥�ʳ��ֵ��кŵ�set
//	std::shared_ptr<std::vector<std::string>> file;  //ָ�򱣴��ļ���vector
//};
//
//queryresult textquery::query(const string& sought) const  //���ҵ���
//{
//	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>); //��set
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//		return queryresult(sought, nodata, file); //δ�ҵ�
//	else
//		return queryresult(sought, loc->second, file);
//}
//
//string make_plural(size_t ctr, const string& word, const string& ending)
//{     //make_plural���ݴ�С�Ƿ����1����ӡtime��times
//	return (ctr > 1) ? word + ending : word;
//}
//std::ostream& printis(std::ostream& os, const queryresult& qr)
//{   
//	os << qr.sought << "occurs" << qr.lines->size() << " " << make_plural(qr.lines->size(),"time","s") << endl;
//	for (auto num : *qr.lines)
//		os << "\tline" << num + 1 << " " << *(qr.file->begin() + num) << endl;
//	return os;
//}
//void runque(std::ifstream& in)  //������
//{
//	textquery tq(in);
//	while(true)
//	{
//		cout << "enter word or quit:";  //������ҵ��ʻ��˳�ָ��
//		string s;
//		if (!(cin >> s) || s == "quit") break; // �˳�ָ��
//		printis(cout, tq.query(s)) << endl; //��ӡ�ҰѲ�������tq.query
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
