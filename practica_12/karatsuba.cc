#include "karatsuba.h"

BigInt Karatsuba::Metodo( BigInt& n1,  BigInt& n2) {
  int len1 = Length(n1);
  int len2 = Length(n2);
	std::cout << "len1: " << len1/2 << " len2: " << len2/2 << std::endl; 
	if (len1 == 1 && len2 == 1)
		return ((n1 * n2));

  std::string a = n1.GetDigit().substr(0, len1 / 2), b = n1.GetDigit().substr(len1 / 2);
	std::cout << "digits: " << n1.GetDigit() << std::endl;
	//std::string c = num2.substr(0, len1 / 2), d = num2.substr(len1 / 2);
	std::cout << "a: " << a << " b: " << b << " "; 
	
	//BigInt ac = Karatsuba(BigInt(a), BigInt(c));
	std::cout << "5 ";
  //BigInt bd = Karatsuba(BigInt(b), BigInt(d));
	////std::cout << "6 ";
	//BigInt ab = a - b;
	//BigInt cd = c - d;
	std::cout << "7 ";
	//BigInt a_b_c_d = Karatsuba(BigInt(a)-BigInt(b), BigInt(c)-BigInt(d));
  
	//return ten_2m * ac + ten_m * (ac + bd - a_b_c_d) + bd;
	return BigInt(1);
}
