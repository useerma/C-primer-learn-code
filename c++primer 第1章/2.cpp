#include<iostream>

//int main()
//{
//	std::cout << "我是傻逼\n" << std::endl;
//	std::cout << '\n' << std::endl; 
//	return 0;
//}


//int main()
//{
//	std::cout << "2\115\n";
//	std::cout << "2\v\115\n";
//	int a{ 0 };
//	int b(9);
//	return 0;
//}


//int main()
//{
//	int a = 42;
//	int* p = nullptr;
//			p = &a;
//	std::cout << *p << std::endl;
//	*p = 5;
//	std::cout << *p << std::endl;
//	return 0;
//}


struct Sales_data {
	std::string bookNO;  //书号
	unsigned units_sold = 0;  //销售数量
	double revenue = 0.0;   //销售额
}; Sales_data data1,data2;

//int main()
//{
//	double price = 0.0; //价格
//	std::cout << "依次输入书号、销售量、单价：" << std::endl;
//	std::cin >> data1.bookNO >> data1.units_sold >> price;
//	data1.revenue = data1.units_sold * price;
//	std::cout << "依次输入书号、销售量、单价：" << std::endl;
//	std::cin >> data2.bookNO >> data2.units_sold >> price;
//	data2.revenue = data2.units_sold * price;
//	if (data1.bookNO == data2.bookNO)
//	{
//		unsigned totalcnt = data1.units_sold + data2.units_sold;  //总销售量
//		double totalrevenue = data1.revenue + data2.revenue; //总销售额
//		std::cout << data1.bookNO << " " << totalcnt << " " << totalrevenue << " ";
//		if (totalcnt != 0)
//		{
//			std::cout << totalrevenue / totalcnt << std::endl; //平均价格
//		}
//		else
//		{
//			std::cout << "no sales" << std::endl;
//		}
//	}
//	else
//	{
//		std::cerr << "data must refer to the same ISBN" << std::endl;
//	}
//	return 0;
//}