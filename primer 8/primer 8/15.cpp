#include"biao.h"
#include<set>


class quote {
public:
	quote() = default;
	quote(const std::string &book,double sales_price) : bookno(book), price(sales_price){}
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug()
	{
		cout << bookno << price << endl;
	}
	std::string isbn() const { return bookno; }
	virtual ~quote() = default;
	friend ostream& operator<<(ostream&, quote&);
private:
	std::string bookno;
protected:
	double price = 0.0; //代表普通状态下不打折的价格
};

ostream& operator<<(ostream& os, quote& e)
{
	os << "operator" << endl;
	return os;
}

class disc_quote :public quote { //抽象基类
public:
	disc_quote(const string& book = "",double sales_price = 0.0,size_t qty = 0,double disc = 0.0):
		quote(book,sales_price),quantitiy(qty),discount(disc){}
	double net_price(size_t cnt) const = 0; //纯虚函数
protected:
	size_t quantitiy = 0;
	double discount = 0.0;
};

class bulk_quote :public disc_quote {
public:
	/*bulk_quote(const string& book = "",double sales_price =0.0,size_t qty = 0,double disc_rate = 0):
		disc_quote(book,sales_price,qty,disc_rate){}*/
	using disc_quote::disc_quote; //直接使用disc_quote的构造函数
	double net_price(size_t cnt) const
	{
		if (cnt > quantitiy)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	~bulk_quote()
	{
		cout << "destructor" << endl;
	}
};

//class bulk_quote : public quote
//{
//public:
//	double net_price(size_t cnt) const override
//	{
//		if (cnt >= min_qty)
//			return cnt * (1 - discount) * price;
//		else
//			return cnt * price;
//	}
//	virtual void debug()
//	{
//		quote::debug(); //bookno是private，需要调用quote才能访问 
//		cout << min_qty << discount << endl;
//	}
//private:
//	size_t min_qty;
//	double discount;
//};

class limited_quote : public quote
{
public:
	double net_price(size_t cnt) const override
	{
		if (cnt <= min_qty)
			return cnt * (1 - discount) * price;
		else
			return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
	}
private:
	size_t min_qty;
	double discount;
};

double print_total(ostream& os, const quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << item.isbn() << n << ret << endl;
	return ret;
}

class basket {
public:
	double total_receipt(std::ostream&) const;
	void add_item(const std::shared_ptr<quote>& sale) { items.insert(sale); }
private:
	static bool compare(const std::shared_ptr<quote>& lhs, const std::shared_ptr<quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<quote>, decltype(compare)* > items;
};

double basket::total_receipt(ostream& os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << sum << endl;
	return sum;
}
int main()
{
	vector<std::shared_ptr<quote>> itemvec;
	for (size_t i = 0; i != 10; i++)
	{
		bulk_quote item("c++", 6, 5, 0.5);
		itemvec.push_back(std::make_shared<bulk_quote>(item));
	}
	double sum = 0;
	for (vector<std::shared_ptr<quote>>::iterator iter = itemvec.begin(); iter != itemvec.end(); ++iter)
	{
		sum += (*iter)->net_price(10);
	}
	cout << sum << endl;
}
class figure {
public:
	figure(double a, double b):xsize(a),ysize(b){}
protected:
	double xsize, ysize;
};

class figure_2D :public figure {
public:
	figure_2D(double a, double b): figure(a,b){}
	virtual double area() = 0;  //求面积，纯虚函数
	virtual double perimeter() = 0; //求周长，纯虚函数
};

class figure_3D :public figure {
public:
	figure_3D(double a,double b,double c):figure(a,b),zsize(c){}
	virtual double cubage() = 0;
protected:
	double zsize;
};

class rectangle : public figure_2D {   //矩形  
public:
	rectangle(double, double);
	virtual double area() override;
	virtual double perimeter() override;
};

class circle :public figure_2D {   //圆
public:
	circle(double, double);
	virtual double area() override;
	virtual double perimeter() override;
};

class sphere : public figure_3D {  //球形
public:
	sphere(double, double,double);
	virtual double cubage() override;
};

class cone : public figure_3D {  //锥形
public:
	cone(double, double, double);
	virtual double cubage() override;
};