//#include"biao.h"
//#include <set>

//class hasptr {
//public:
//	hasptr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {} //���캯������
//	hasptr(const hasptr&); //�������캯��
//	hasptr& operator= (const hasptr&); //������ֵ�����
//	hasptr& operator= (const string&); //������string
//	string& operator* (); //������
//	~hasptr() { delete ps; } //��������
//private:
//	string* ps;
//	int i;
//};
//
//hasptr::hasptr(const hasptr& hp)  //�������캯��
//{
//	ps = new string(*(hp.ps));
//	i = hp.i;
//}
//
//hasptr& hasptr::operator = (const hasptr& rhs) //�������������
//{
//	auto newps = new string(*(rhs.ps)); //��rhs��Ԫ�ع�����µĶ��󣬿���ָ��ָ���µĶ���
//	delete ps;  //����ԭstring
//	ps = newps; //ָ����string
//	i = rhs.i;  //ʹ�����õ�int��ֵ
//	return *this; //�����¶��������
//}
//
//hasptr& hasptr::operator=(const string& rhs)
//{
//	*ps = rhs; //rhs�����������ָ��psָ���λ��
//	return *this;
//}
//
//string& hasptr::operator*()
//{
//	return *ps;
//}

//struct x {
//	x() { std::cout << "x()" << endl; } //Ĭ�Ϲ��캯��
//	x(const x&) { cout << "x(const x&)" << endl; } //�������캯��
//	x& operator=(const x& rhs) {  //��ֵ�����=
//		cout << "��ֵ�����" << endl;
//		return *this;
//	}
//	~x() { cout << "��������" << endl; } //��������
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
//	cout << "����" << endl;
//	x x1;
//	cout << endl;
//	cout << "�����ò������ݣ�" << endl;
//	f1(x1);
//	cout << endl;
//	f2(x1);
//	cout << endl;
//	cout << "��̬���䣺" << endl;
//	x* px = new x;
//	cout << endl;
//	cout << "��ӵ�������" << endl;
//	vector<x> vx;
//	vx.push_back(x1);
//	cout << endl;
//	cout << "�ͷŶ�̬�������" << endl;
//	delete px;
//	cout << endl;
//	cout << "��ӳ�ʼ���͸�ֵ" << endl;
//	x y = x1;
//	y = x1;
//	cout << endl;
//	cout << "�������" << endl;
//	return 0;
//}


//class numberd {
//private:
//	static int seq;
//public:
//	numberd() { mysn = seq++; }
//	numberd(numberd& n) { mysn = seq++; } //�������캯��
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
//	strblob();  //Ĭ�Ϲ��캯��
//	strblob(std::initializer_list<string> il);
//	strblob(vector<string>* p);
//	strblob(strblob& s);   //�������캯��
//	strblob& operator= (strblob& rhs); //������ֵ�����
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
//	hasptr(const hasptr& p) : ps(p.ps), i(p.i), use(p.use) { ++*use; } //�������캯��
//	hasptr& operator=(const hasptr&);  //������ֵ�����
//	hasptr& operator=(const string&);  //������string
//	string& operator*();  //������
//	~hasptr(); //��������
//	void swap(hasptr& lhs, hasptr& rhs); //swap����
//	bool operator<(const hasptr&) const; //С�ں������
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
//inline void hasptr::swap(hasptr& lhs, hasptr& rhs) //��������������ָ��
//{
//	using std::swap;
//	swap(lhs.ps, rhs.ps);
//	swap(lhs.i, rhs.i);
//}
//
//hasptr::~hasptr()
//{
//	if (--*use == 0)  //��������ȼ���ȣ���������
//	{ //�ȵݼ��꣬��Ϊ0���ͷ�
//		delete ps;
//		delete use;
//	}
//}
//
//hasptr& hasptr::operator=(const hasptr& rhs)
//{
//	++*rhs.use; //�ȵ����Ҳ࣬��ֹ�����Ը�ֵ
//	if (--*use == 0) //���������ļ���
//	{
//		delete ps;
//		delete use;
//	}
//	ps = rhs.ps; //���ݿ�����������
//	i = rhs.i;
//	use = rhs.use;
//	return *this; //���ر�����
//}
//
//hasptr& hasptr::operator=(const string& rhs)
//{
//	*ps = rhs;  //ֱ�ӿ���
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
//	treenode() : value(" "),count(1),left(nullptr),right(nullptr){} //Ĭ�Ϲ��캯��
//	bool copytree(void); //������������
//	treenode(const treenode& tn) : value(tn.value), count(1), left(tn.left), right(tn.right) //�������캯��
//	{
//		if (left) //
//			left->copytree();
//		if (right)
//			right->copytree();
//	}
//	int release(void) //��������
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
//	explicit message(const std::string &str = " "):text(str) {} //folders����ʽ��ʼ��Ϊ�ռ���
//	message(const message&);  //�������캯��
//	message(message&&); //�ƶ����캯��
//	message& operator=(const message&);  //������ֵ�����
//	/*message& operator=(message&& rhs);*/ //�ƶ���ֵ�����
//	~message();  //��������
//	void move_folders(message*); //�ƶ���ֵ������ĸ���folder
//	void save(folder&);  
//	void remove(folder&);
//	void swap(message&, message&);
//	void addfldr(folder* f) { folders.insert(f); } //��������folder��ӵ���message��
//private:
//	std::string text;  //��Ϣ�ı�
//	std::set<folder*> folders;  //message�еı���folder��ָ���set
//	void add_to_folders(const message&);  //��message��ӵ�ָ�������folder��
//	void remove_folders();  //��folders�е�ÿ��folder��ɾ��message
//};
//
//class folder {
//public:
//	friend string& operator*(const std::set<string>&); //��Ԫ����
//	folder() : msgs() {} //Ĭ�Ϲ��캯��
//	folder(const folder& f) : msgs(f.msgs) { add_to_messages(f); } //�������캯��
//	~folder() { remove_messages(); } //��������
//	folder& operator=(const folder&); //������ֵ�����
//	void addmsg(message* m) { msgs.insert(m); } //�����ı�m
//	void remmsg(message* m) { msgs.erase(m); }
//	void print(); //��ӡ����
//private:
//	std::set< message* > msgs; //����folder�������ı���ָ�뼯
//	void add_to_messages(const folder& f); //����folder��ӵ����е�message�е�set
//	void remove_messages(); //ɾ���汾
//};
//
//void folder::print() //��ӡ����
//{
//	for (auto f : msgs)
//		std::cout << f->text << endl;
//}
//
//string& operator*(const std::set<string>&f) //���������������
//{
//	return *f;
//}
//
//void folder::add_to_messages(const folder& f)
//{
//	for (auto msg : f.msgs) //����folder��ӵ����е�message��
//		msg->addfldr(this);
//}
//
//void folder::remove_messages()
//{
//	while (!msgs.empty())  //����folder�������е�message��ɾ����������
//		(*msgs.begin())->remove(*this); //��ִ��begin�����ٽ�����
//}
//
//folder& folder::operator=(const folder& f)
//{ //��ɾ���ٿ���
//	remove_messages(); //��ÿ��message��ɾ����folder
//	msgs = f.msgs;   //����
//	add_to_messages(f); //����folder��ӵ�ÿ��message
//	return *this;
//}
//
//message::message(message&& m) : text(std::move(m.text)) //textֱ����Ϊ��ֵ���ø���text
//{ //setͨ��move_folders���������ƶ�
//	move_folders(&m); //&���ǽ����÷�����ȡ��ַ�� 
//}

//void message::move_folders(message* m)
//{
//	folders = std::move(m->folders); //ʹ��set���ƶ���ֵ�����
//	for (auto f : folders) //��ÿ��folder����ɾ���ɶ���ָ�룬����¶���ָ��
//	{
//		f->remmsg(m);
//		f->addmsg(this);
//	}
//	m->folders.clear(); //ȷ��m��������
//}
//message& message::operator=(message&& rhs) noexcept
//{
//	if (this != &rhs) //����Ը�ֵ  &������ȡ��ַ��
//	{
//		remove_folders(); //ɾ��folder�е�message
//		text = std::move(rhs.text); //�ƶ���ֵ�����
//		move_folders(&rhs); //����foldersָ��message
//	}
//	return *this;
//}

//void message::save(folder& f)
//{
//	folders.insert(&f); //��������folder��ӵ�folders�б���
//	f.addmsg(this);   //����message��ӵ�f�ļ�����
//}
//
//void message::remove(folder& f)
//{
//	folders.erase(&f); //��������folder��folders�б���ɾ��
//	f.remmsg(this);  //����message��f��ɾ��
//}
//
//void message::add_to_folders(const message& m)
//{
//	for (auto f : m.folders) //��ÿ������m��folder�����µ�message
//		f->addmsg(this);
//}
//
//message::message(const message& m) : text(m.text), folders(m.folders) //�������캯��
//{
//	add_to_folders(m); //����message��ӵ�ָ��ԭm��folder��
//}
//
//void message::remove_folders()
//{
//	for (auto f : folders)  //��folders��ÿ��ָ��ָ���folder��ɾ����message
//		f->remmsg(this);
//}
//
//message::~message() //�������� ���ò����ᱻ�������Զ��ص�����������������������
//{
//	remove_folders();
//}
//
//message& message::operator=(const message& rhs)  //������ֵ�����
//{
//	remove_folders(); //ɾ����������������folder�еĴ��λ��
//	text = rhs.text;  //�������󿽱�text����
//	folders = rhs.folders;  //����ָ���б�folders
//	add_to_folders(rhs);  //����message��ӵ���Щfolder��
//	return *this; //����������
//}
//
//void message::swap(message& lhs, message& rhs)
//{
//	//��ɾ�����Ҷ����ڸ��Ե�folder��ָ�룬Ȼ�󽻻����ݽṹ������ͨ��set��������ӵ�folder��
//	using std::swap;
//	for (auto f : lhs.folders)
//		f->remmsg(&lhs); //ʹ�����ã����ⷢ����������
//	for (auto f : rhs.folders)
//		f->remmsg(&rhs);
//	swap(lhs.folders, rhs.folders); //����folderָ��set
//	swap(lhs.text, rhs.text);  //�����ı�
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
//	foo sorted()&&;  //������ֵ
//	foo sorted() const&;  //�����κ�����
//private:
//	vector<int> data;
//};
//
//foo foo::sorted()&&
//{
//	cout << "right" << endl;
//	std::sort(data.begin(), data.end()); //����Ϊ��ֵ��������������ã���ֱ������
//	return *this;
//}
//
//foo foo::sorted() const&
//{
//	cout << "left" << endl;
//	foo ret(*this); //����������
//	return ret.sorted(); //�Ը�����������
//	// return foo(*this).sorted(); foo(*this)���ص���ֵ��������ֵ���ð汾
//}

