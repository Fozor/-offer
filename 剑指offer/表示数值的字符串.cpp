/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
class Solution {
public:
	bool is0to9(char buf){
		return (buf >= '0') && (buf <= '9');
	}
	bool isop(char buf){
		return (buf == '+') || (buf == '-');
	}
	bool isNumeric(char* string)
	{
		int i = 0;
		bool hasdot = false;
		bool hase = false;
		if (is0to9(string[0]) || isop(string[i])){
			// 非法输入处理
			if (string == NULL || *string == '\0'){
				return false;
			}
			i++;
			while (string[i] != '\0'){
				if (!is0to9(string[i])){
					if (((string[i] == 'e') || (string[i] == 'E'))){
						if (string[i + 1] != '\0'){
							if (!hase){
								hase = true;
							}
							else {
								return false;
							}
						}
						else{
							return false;
						}
					}
					else if(string[i]== '.'){
						if ((!hasdot)&&(!hase)){
							hasdot = true;
						}
						else{
							return false;
						}
					}
					else if (isop(string[i])){
						if ((string[i - 1] != 'e') && (string[i - 1] != 'E')){
							return false;
						}
					}
					else{
						return false;
					}
				}
				i++;
			}
		}
		else{
			return false;
		}
		return true;
	}

};



class Solution2 {
public:
	// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
	// 其中A和C都是整数（可以有正负号，也可以没有）
	// 而B是一个无符号整数
	bool isNumeric(char* string)
	{
		// 非法输入处理
		if (string == NULL || *string == '\0'){
			return false;
		}
		// 正负号判断
		if (*string == '+' || *string == '-'){
			++string;
		}
		bool numeric = true;
		scanDigits(&string);
		if (*string != '\0'){
			// 小数判断
			if (*string == '.'){
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E'){
					numeric = isExponential(&string);
				}
			}
			// 整数判断
			else if (*string == 'e' || *string == 'E'){
				numeric = isExponential(&string);
			}
			else{
				numeric = false;
			}
		}
		return numeric && *string == '\0';
	}
private:
	// 扫描数字，对于合法数字，直接跳过
	void scanDigits(char** string){
		while (**string != '\0' && **string >= '0' && **string <= '9'){
			++(*string);
		}
	}
	// 用来潘达un科学计数法表示的数值的结尾部分是否合法
	bool isExponential(char** string){
		++(*string);
		if (**string == '+' || **string == '-'){
			++(*string);
		}
		if (**string == '\0'){
			return false;
		}
		scanDigits(string);
		// 判断是否结尾，如果没有结尾，说明还有其他非法字符串
		return (**string == '\0') ? true : false;
	}
};
/*

int main(){
	Solution S;
	char* str = "1a3.14";
		cout << S.isNumeric(str) << endl;
	system("pause");
	return  0;
}
*/