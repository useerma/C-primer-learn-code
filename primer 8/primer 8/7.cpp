//#include"biao.h"


//int main()
//{
//	cout << "please entering data of trade:" << endl;
//	Sales_data total;
//	if (cin >> total)
//	{
//		Sales_data trans;
//		while (cin >> trans)
//		{
//			if (total.isbn() == trans.isbn())
//				total += trans;
//			else
//			{
//				cout << total << endl;
//				total = trans;
//			}
//		}
//		cout << total << endl;
//	}
//	else
//	{
//		std::cerr << "No data?" << endl;
//		return -1;
//	}
//	return 0;
//}



//class Sales_data
//{
//private:
//	string bookNo;
//	unsigned units_sold = 0;
//	double sellingprice = 0.0;
//	double saleprice = 0.0;
//	double discount = 0.0;
//	double revenue = 0.0;
//	friend Sales_data add(const Sales_data& lift, const Sales_data& right); //��������ʹ�����г�Ա����������
//public:
//	//���캯��������
//	Sales_data() = default; //��һ��Ĭ�Ϲ��캯��
//	Sales_data(const std::string &book): bookNo(book){ } //�ڶ��ֹ��캯��ֻ�����鼮��isbn��ţ�ʣ�µĳ�Ա�����ɱ�����Ĭ�ϸ���
//	Sales_data(const std::string& book, const unsigned num, const double sellp, const double salep);
//	//�����ֹ��캯��������������Ϣ.�����ľ��庯��������������������ֱ�Ӷ���
//	Sales_data(std::istream &is); //�����ֹ��캯�����Ǵ�cin�ж�ȡ�鼮����Ϣ��Ҫ�����ж������������>>�����غ���
////��ʽ�س�ʼ����Ա
////Sales_data (const std::string &book):bookNo(book),units_sold(0),sellingprice(0),saleprice(0),discount(0){ }
//
////ί�й��캯�����÷�
//public:
//	//����һЩί�й��캯��
//	//Sales_data() :Sales_data(" ", 0, 0, 0){ } //��Ҫ��ʼ���Ĳ��������ʼ��ֵ�����ô����캯��
//	//Sales_data(const string &book): Sales_data(book,0,0,0){ }
//	//Sales_data(std::istream& is) :Sales_data() { read(is, *this); }
//	////����һ�������캯�����������г�ʼ������
//	//Sales_data(const string& book, unsigned num, double sellp, double salep) :bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
//	//{
//	//	if (sellingprice)
//	//		discount = saleprice / sellingprice;
//	//}
//
//	string isbn() const { return bookNo; }
//	double avg_price() const
//	{
//		if (units_sold)
//			return revenue / units_sold;
//		else
//			return 0;
//	}
//	Sales_data& combine(const Sales_data& rhs)
//	{
//		units_sold += rhs.units_sold;
//		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
//		if (sellingprice != 0)
//			discount = saleprice / sellingprice;
//		return *this;
//	}
//	std::istream& read(std::istream& is, Sales_data& item)
//	{
//		is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
//		return is;
//	}
//	Sales_data add(const Sales_data& lift, const Sales_data& right)
//	{
//		Sales_data sum = lift;
//		sum.combine(right);
//		return sum;	
//	}
//	std::ostream& print(std::ostream& os, const Sales_data& item)
//	{
//		os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
//		return os;
//	}
//	//���������>>�����غ���
//	friend std::istream& operator>>(std::istream& is, Sales_data& data) {
//		is >> data.bookNo >> data.units_sold >> data.sellingprice >> data.saleprice;
//		data.discount = data.saleprice / data.sellingprice;
//		return is;
//	}
//};
//
//Sales_data::Sales_data(const std::string& book, const unsigned num, const double sellp, const double salep) //���캯��
//{
//	bookNo = book;
//	units_sold = num;
//	sellingprice = sellp;
//	saleprice = salep;
//	if (sellingprice != 0)
//		discount = saleprice / sellingprice;
//}
//
//Sales_data::Sales_data(std::istream& is)
//{
//	is >> *this;
//}

//int main()
//{
//	//���ֹ��캯���Ĳ���
//	Sales_data data1;
//	Sales_data data2("97812344235455");
//	Sales_data data3("12343845233444", 100, 128, 109);
//	Sales_data data4(cin);
//	return 0;
//}


//int main()
//{
//	Screen myScreen(5, 5, 'X');
//	myScreen.move(4, 0).set('$').display();
//	cout << "\n";
//	return 0;
//}


