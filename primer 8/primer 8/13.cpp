//#include"biao.h"
//#include <set>

//class hasptr {
//public:
//	hasptr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {} //构造函数声明
//	hasptr(const hasptr&); //拷贝构造函数
//	hasptr& operator= (const hasptr&); //拷贝赋值运算符
//	hasptr& operator= (const string&); //赋予新string
//	string& operator* (); //解引用
//	~hasptr() { delete ps; } //析构函数
//private:
//	string* ps;
//	int i;
//};
//
//hasptr::hasptr(const hasptr& hp)  //拷贝构造函数
//{
//	ps = new string(*(hp.ps));
//	i = hp.i;
//}
//
//hasptr& hasptr::operator = (const hasptr& rhs) //拷贝复制运算符
//{
//	auto newps = new string(*(rhs.ps)); //用rhs的元素构造出新的对象，拷贝指针指向新的对象
//	delete ps;  //销毁原string
//	ps = newps; //指向新string
//	i = rhs.i;  //使用内置的int赋值
//	return *this; //返回新对象的引用
//}
//
//hasptr& hasptr::operator=(const string& rhs)
//{
//	*ps = rhs; //rhs赋给左侧对象的指针ps指向的位置
//	return *this;
//}
//
//string& hasptr::operator*()
//{
//	return *ps;
//}

//struct x {
//	x() { std::cout << "x()" << endl; } //默认构造函数
//	x(const x&) { cout << "x(const x&)" << endl; } //拷贝构造函数
//	x& operator=(const x& rhs) {  //赋值运算符=
//		cout << "赋值运算符" << endl;
//		return *this;
//	}
//	~x() { cout << "析构函数" << endl; } //析构函数
//};
//
//void f1(x)
//{}
//
//void f2(x &x)
//{}
//
//int main()
//{
//	cout << "变量" << endl;
//	x x1;
//	cout << endl;
//	cout << "非引用参数传递：" << endl;
//	f1(x1);
//	cout << endl;
//	f2(x1);
//	cout << endl;
//	cout << "动态分配：" << endl;
//	x* px = new x;
//	cout << endl;
//	cout << "添加到容器中" << endl;
//	vector<x> vx;
//	vx.push_back(x1);
//	cout << endl;
//	cout << "释放动态分配对象" << endl;
//	delete px;
//	cout << endl;
//	cout << "间接初始化和赋值" << endl;
//	x y = x1;
//	y = x1;
//	cout << endl;
//	cout << "程序结束" << endl;
//	return 0;
//}


//class numberd {
//private:
//	static int seq;
//public:
//	numberd() { mysn = seq++; }
//	numberd(numberd& n) { mysn = seq++; } //拷贝构造函数
//	int  mysn;
//};
//
//int numberd::seq = 0;
//
//void f(const numberd& s)
//{
//	cout << s.mysn << endl;
//}
//
//int main()
//{
//	numberd a, b = a, c = b;
//	f(a); f(b); f(c);
//	return 0;
//}


//class employee {
//private:
//	static int sn;
//public:
//	employee() { mysn = sn++; }
//	employee(const string& s) { name = s; mysn = sn++; } 
//	employee(employee& e) { name = e.name; mysn = sn++; } 
//	employee& operator= (employee& rhs) { name = rhs.name; return *this; }
//	const string& get_name() { return name; }
//	int get_mysn() { return mysn; }
//private:
//	string name;
//	int mysn;
//};
//
//int employee::sn = 0;
//
//void f(employee& s) 
//{
//	cout << s.get_name() << ":" << s.get_mysn() << endl;
//}
//
//int main()
//{
//	employee a("lin"), b = a, c; 
//	c = b;
//	f(a); f(b); f(c);
//	return 0;
//}


//class strblobptr;
//class strblob {
//	friend class strblobptr;
//public:
//	typedef vector<string>::size_type size_type;
//	strblob();  //默认构造函数
//	strblob(std::initializer_list<string> il);
//	strblob(vector<string>* p);
//	strblob(strblob& s);   //拷贝构造函数
//	strblob& operator= (strblob& rhs); //拷贝赋值运算符
//	size_type size() const { return data->size(); }
//	bool empty() const { return data->empty(); }
//	void push_back(const string& t) { data->push_back(t); }
//	void pop_back();
//	string& front();
//	const string& front() const;
//	string& back();
//	const string& back() const;
//	strblobptr begin();
//	strblobptr end();
//	strblobptr begin() const;
//	strblobptr end() const;
//private:
//	std::shared_ptr<std::vector<std::string>> data;
//	void check(size_type, const std::string& msg) const;
//};
//
//
//class hasptr {
//public:
//	hasptr(const string& s = string()) : ps(new string(s)),i(0),use(new size_t(1)) {}
//	hasptr(const hasptr& p) : ps(p.ps), i(p.i), use(p.use) { ++*use; } //拷贝构造函数
//	hasptr& operator=(const hasptr&);  //拷贝赋值运算符
//	hasptr& operator=(const string&);  //赋予新string
//	string& operator*();  //解引用
//	~hasptr(); //析构函数
//	void swap(hasptr& lhs, hasptr& rhs); //swap函数
//	bool operator<(const hasptr&) const; //小于号运算符
//private:
//	string* ps;
//	int i;
//	size_t* use;
//};
//
//bool hasptr::operator<(const hasptr& ou) const
//{
//	return *ps < *(ou.ps);
//}
//
//inline void hasptr::swap(hasptr& lhs, hasptr& rhs) //交换函数，交换指针
//{
//	using std::swap;
//	swap(lhs.ps, rhs.ps);
//	swap(lhs.i, rhs.i);
//}
//
//hasptr::~hasptr()
//{
//	if (--*use == 0)  //运算符优先级相等，从右往左
//	{ //先递减完，若为0则释放
//		delete ps;
//		delete use;
//	}
//}
//
//hasptr& hasptr::operator=(const hasptr& rhs)
//{
//	++*rhs.use; //先递增右侧，防止函数自赋值
//	if (--*use == 0) //检查左侧对象的计数
//	{
//		delete ps;
//		delete use;
//	}
//	ps = rhs.ps; //数据拷贝到左侧对象
//	i = rhs.i;
//	use = rhs.use;
//	return *this; //返回本对象
//}
//
//hasptr& hasptr::operator=(const string& rhs)
//{
//	*ps = rhs;  //直接拷贝
//	return *this;
//}
//
//string& hasptr::operator*()
//{
//	return *ps;
//}

//int main()
//{
//	hasptr h("hello world");
//	hasptr h2 = h;
//	h = "hi world";
//	cout << *h << endl;
//	cout << *h2 << endl;
//	return 0;
//}

//class bintree {
//public:
//	bintree(treenode* t = nullptr) : root(t) {}
//	bintree(const bintree& bst) : root(bst.root) { root->copytree(); }
//	~bintree()
//	{
//		if (!root->release())
//			delete root;
//	}
//private:
//	treenode* root;
//};
//class treenode {
//public:
//	treenode() : value(" "),count(1),left(nullptr),right(nullptr){} //默认构造函数
//	bool copytree(void); //拷贝函数声明
//	treenode(const treenode& tn) : value(tn.value), count(1), left(tn.left), right(tn.right) //拷贝构造函数
//	{
//		if (left) //
//			left->copytree();
//		if (right)
//			right->copytree();
//	}
//	int release(void) //析构函数
//	{
//		if (left)
//		{
//			if (!left->copytree())
//				delete left;
//		}
//		if (right)
//		{
//			if (!right->copytree())
//				delete right;
//		}
//		count--;
//		return count;
//	}
//	~treenode()
//	{
//		if (count)
//			release();
//	}
//private:
//	std::string value;
//	int count;
//	treenode* left;
//	treenode* right;
//};
//
//bool treenode::copytree()
//{
//	if (left)
//		left->copytree();
//	if (right)
//		right->copytree();
//	count++;
//	return true;
//}



//class message {
//	friend class folder;
//public:
//	explicit message(const std::string &str = " "):text(str) {} //folders被隐式初始化为空集合
//	message(const message&);  //拷贝构造函数
//	message(message&&); //移动构造函数
//	message& operator=(const message&);  //拷贝赋值运算符
//	/*message& operator=(message&& rhs);*/ //移动赋值运算符
//	~message();  //析构函数
//	void move_folders(message*); //移动赋值运算符的更新folder
//	void save(folder&);  
//	void remove(folder&);
//	void swap(message&, message&);
//	void addfldr(folder* f) { folders.insert(f); } //将给定的folder添加到该message中
//private:
//	std::string text;  //消息文本
//	std::set<folder*> folders;  //message中的保存folder的指针的set
//	void add_to_folders(const message&);  //将message添加到指向参数的folder中
//	void remove_folders();  //从folders中的每个folder中删除message
//};
//
//class folder {
//public:
//	friend string& operator*(const std::set<string>&); //友元声明
//	folder() : msgs() {} //默认构造函数
//	folder(const folder& f) : msgs(f.msgs) { add_to_messages(f); } //拷贝构造函数
//	~folder() { remove_messages(); } //析构函数
//	folder& operator=(const folder&); //拷贝赋值运算符
//	void addmsg(message* m) { msgs.insert(m); } //插入文本m
//	void remmsg(message* m) { msgs.erase(m); }
//	void print(); //打印数据
//private:
//	std::set< message* > msgs; //保存folder中所有文本的指针集
//	void add_to_messages(const folder& f); //将该folder添加到所有的message中的set
//	void remove_messages(); //删除版本
//};
//
//void folder::print() //打印函数
//{
//	for (auto f : msgs)
//		std::cout << f->text << endl;
//}
//
//string& operator*(const std::set<string>&f) //介意用运算符重载
//{
//	return *f;
//}
//
//void folder::add_to_messages(const folder& f)
//{
//	for (auto msg : f.msgs) //将该folder添加到所有的message中
//		msg->addfldr(this);
//}
//
//void folder::remove_messages()
//{
//	while (!msgs.empty())  //将该folder从它所有的message中删除（析构）
//		(*msgs.begin())->remove(*this); //先执行begin函数再解引用
//}
//
//folder& folder::operator=(const folder& f)
//{ //先删除再拷贝
//	remove_messages(); //从每个message中删除该folder
//	msgs = f.msgs;   //拷贝
//	add_to_messages(f); //将该folder添加到每个message
//	return *this;
//}
//
//message::message(message&& m) : text(std::move(m.text)) //text直接作为右值引用赋给text
//{ //set通过move_folders函数进行移动
//	move_folders(&m); //&不是解引用符，是取地址符 
//}

//void message::move_folders(message* m)
//{
//	folders = std::move(m->folders); //使用set的移动赋值运算符
//	for (auto f : folders) //对每个folder进行删除旧对象指针，添加新对象指针
//	{
//		f->remmsg(m);
//		f->addmsg(this);
//	}
//	m->folders.clear(); //确保m中无数据
//}
//message& message::operator=(message&& rhs) noexcept
//{
//	if (this != &rhs) //检查自赋值  &符号是取地址符
//	{
//		remove_folders(); //删除folder中的message
//		text = std::move(rhs.text); //移动赋值运算符
//		move_folders(&rhs); //重置folders指向本message
//	}
//	return *this;
//}

//void message::save(folder& f)
//{
//	folders.insert(&f); //将给定的folder添加到folders列表中
//	f.addmsg(this);   //将本message添加到f的集合中
//}
//
//void message::remove(folder& f)
//{
//	folders.erase(&f); //将给定的folder从folders列表中删除
//	f.remmsg(this);  //将本message从f中删除
//}
//
//void message::add_to_folders(const message& m)
//{
//	for (auto f : m.folders) //对每个包含m的folder插入新的message
//		f->addmsg(this);
//}
//
//message::message(const message& m) : text(m.text), folders(m.folders) //拷贝构造函数
//{
//	add_to_folders(m); //将本message添加到指向原m的folder中
//}
//
//void message::remove_folders()
//{
//	for (auto f : folders)  //对folders中每个指针指向的folder中删除本message
//		f->remmsg(this);
//}
//
//message::~message() //析构函数 内置参数会被编译器自动地调用内置类型析构函数销毁
//{
//	remove_folders();
//}
//
//message& message::operator=(const message& rhs)  //拷贝赋值运算符
//{
//	remove_folders(); //删除掉左侧对象在所有folder中的存放位置
//	text = rhs.text;  //从左侧对象拷贝text内容
//	folders = rhs.folders;  //拷贝指针列表folders
//	add_to_folders(rhs);  //将本message添加到那些folder中
//	return *this; //返回左侧对象
//}
//
//void message::swap(message& lhs, message& rhs)
//{
//	//先删除左右对象在各自的folder的指针，然后交换数据结构，接着通过set将容器添加到folder中
//	using std::swap;
//	for (auto f : lhs.folders)
//		f->remmsg(&lhs); //使用引用，避免发生拷贝构造
//	for (auto f : rhs.folders)
//		f->remmsg(&rhs);
//	swap(lhs.folders, rhs.folders); //交换folder指针set
//	swap(lhs.text, rhs.text);  //交换文本
//	for (auto f : lhs.folders)
//		f->addmsg(&lhs);
//	for (auto f : rhs.folders)
//		f->addmsg(&rhs);
//}

//int main()
//{
//	folder f,f1,f3;
//	message m("hello world");
//	message m1("gudanxinshi");
//	message m3("c++ primer");
//	m.save(f);
//	m.save(f1);
//	m3.save(f);
//	m1 = m;
//	f.print();
//	f.remmsg(&m);
//	f.print();
//	return 0;
//}


//class foo {
//public:
//	foo sorted()&&;  //用于右值
//	foo sorted() const&;  //用于任何类型
//private:
//	vector<int> data;
//};
//
//foo foo::sorted()&&
//{
//	cout << "right" << endl;
//	std::sort(data.begin(), data.end()); //对象为右值，无其他对象调用，可直接排序
//	return *this;
//}
//
//foo foo::sorted() const&
//{
//	cout << "left" << endl;
//	foo ret(*this); //拷贝本对象
//	return ret.sorted(); //对副本进行排序
//	// return foo(*this).sorted(); foo(*this)返回的右值，调用右值引用版本
//}

