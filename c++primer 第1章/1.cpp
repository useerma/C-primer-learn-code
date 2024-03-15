#include<iostream>
#include"标头.h"

//int main()
//{
//	std::cout << "enter tow number:" << std::endl;
//	int v1 = 0;
//	int v2 = 0;
//	std::cin >> v1 >> v2;
//	std::cout << "the sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
//	return 0;
//}


//练习
//int main()
//{
//	std::cout << "hello" << " world!" << std::endl;
//	return 0;
// }


//int main()
//{
//	std::cout << "enter two number:" << std::endl;
//	int v1 = 0;
//	int v2 = 0;
//	std::cin >> v1 >> v2;
//	std::cout << "The number is "<< v1 * v2 << std::endl;
//	return 0;
//}

//int main()
//{
//	/*
//	*  注释对/**/不能嵌套 // 出现错误 （不能同时出现两个 /**/，否则第二个后面的东西会被认为是源码）
//	* 
//	* 
//	*/
//	return 0;
//}


//int main()
//{
//	//std::cout << "/*";
//	//std::cout << /* "*/" */;
//	std::cout << /*"*/"/*"/*"*/;
//	return 0;
//}


//int main()
//{
//	int sum = 0;
//	int val = 50;
//	while (val <= 100)
//	{
//		sum += val;
//		val++;
//	}
//	std::cout << "The sum is " << sum << std::endl;
//	return 0;
//}


//int main()
//{
//	int val = 10;
//	while (val >= 0)
//	{
//		if (val == 10)
//			std::cout << "序列为：";
//		std::cout << val;
//		val--;
//	}
//	return 0;
//}


//int main()
//{
//	int v1 = 0;
//	int v2 = 0;
//	std:: cout << "enter two number(last number is max):" << std::endl;
//	std::cin >> v1 >> v2;
//	while (v2 >= v1)
//	{
//		std::cout << v2 << std::endl;
//		v2--;
//	}
//	return 0;
//}



//int main()
//{
//	int sum = 0;
//	int value = 0;
//	while (std::cin >> value) //当遇到输入不是整数时，条件将变为无效；
//	{
//		sum += value;
//	}
//	std::cout << "The sum is " << sum << std::endl;
//	return 0;
//}



//int main()
//{
//	int currval = 0;
//	int val = 0;
//	if (std::cin >> currval)
//	{
//		int cnt = 1;
//		while (std::cin >> val)
//		{
//			if (val == currval)
//			{
//				cnt++;
//			}
//			else if (currval == '*')
//			{
//				break;
//			}
//			else
//			{
//				std::cout << currval << " occurs " << cnt << " time" << std::endl;
//				currval = val;
//				cnt = 1;
//			}
//		}
//		std::cout << currval << " occurs " << cnt << " time" << std::endl;
//	}
//	return 0;
//}


//int main()
//{
//	int v1 = 0;
//	int v2 = 0;
//	std:: cout << "enter two number:" << std::endl;
//	std::cin >> v1 >> v2;
//	if (v1 > v2)
//	{
//		while (v2 <= v1)
//		{
//			std::cout << v1 << std::endl;
//			v1--;
//		}
//	}
//	else
//	{
//		while (v1 <= v2)
//		{
//			std::cout << v1 << std::endl;
//			v1++; 
//		}
//	}
//	return 0;
//}


//int main()
//{
//	Sales_item book;
//	std::cin >> book;
//	std::cout << book << std::endl;
//	return 0;
//}


//int main()
//{
//	Sales_item book1,book2;
//	std::cin >> book1 >> book2;
//	std::cout << book1 + book2 << std::endl;
//	return 0;
//}




//int main()
//{
//	Sales_item item1;
//	Sales_item item2;
//	std::cin >> item1 >> item2;
//	if (item1.isbn == item2.isbn)
//	{
//		std::cout << item1 + item2 << std::endl;
//		return 0;
//	}
//	else
//	{
//		std::cout << "data must refer to same ISBN" << std::endl;
//		return -1;
//	}
//	return 0;
//}



//int main()
//{
//	Sales_item book1;
//	Sales_item book2;
//	if (std::cin >> book1)
//	{
//		int net = 1;
//		while (std::cin >> book2)
//		{
//			if (book1.isbn == book2.isbn)
//			{
//				net++;
//			}
//			else
//			{
//				std::cout << book1.isbn << " have " << net << " time " << std::endl;
//				book1 = book2;
//				net = 1;
//			}
//		}
//		std::cout << book1.isbn << " have " << net << " time " << std::endl;
//	}
//	else
//	{
//		std::cout << "wrong input!" << std::endl;
//	}
//	return 0;
//}