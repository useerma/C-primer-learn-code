#include<iostream>

//int main()
//{
//	std::cout << "����ɵ��\n" << std::endl;
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
	std::string bookNO;  //���
	unsigned units_sold = 0;  //��������
	double revenue = 0.0;   //���۶�
}; Sales_data data1,data2;

//int main()
//{
//	double price = 0.0; //�۸�
//	std::cout << "����������š������������ۣ�" << std::endl;
//	std::cin >> data1.bookNO >> data1.units_sold >> price;
//	data1.revenue = data1.units_sold * price;
//	std::cout << "����������š������������ۣ�" << std::endl;
//	std::cin >> data2.bookNO >> data2.units_sold >> price;
//	data2.revenue = data2.units_sold * price;
//	if (data1.bookNO == data2.bookNO)
//	{
//		unsigned totalcnt = data1.units_sold + data2.units_sold;  //��������
//		double totalrevenue = data1.revenue + data2.revenue; //�����۶�
//		std::cout << data1.bookNO << " " << totalcnt << " " << totalrevenue << " ";
//		if (totalcnt != 0)
//		{
//			std::cout << totalrevenue / totalcnt << std::endl; //ƽ���۸�
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