/*
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
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
			// �Ƿ����봦��
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
	// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
	// ����A��C���������������������ţ�Ҳ����û�У�
	// ��B��һ���޷�������
	bool isNumeric(char* string)
	{
		// �Ƿ����봦��
		if (string == NULL || *string == '\0'){
			return false;
		}
		// �������ж�
		if (*string == '+' || *string == '-'){
			++string;
		}
		bool numeric = true;
		scanDigits(&string);
		if (*string != '\0'){
			// С���ж�
			if (*string == '.'){
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E'){
					numeric = isExponential(&string);
				}
			}
			// �����ж�
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
	// ɨ�����֣����ںϷ����֣�ֱ������
	void scanDigits(char** string){
		while (**string != '\0' && **string >= '0' && **string <= '9'){
			++(*string);
		}
	}
	// �����˴�un��ѧ��������ʾ����ֵ�Ľ�β�����Ƿ�Ϸ�
	bool isExponential(char** string){
		++(*string);
		if (**string == '+' || **string == '-'){
			++(*string);
		}
		if (**string == '\0'){
			return false;
		}
		scanDigits(string);
		// �ж��Ƿ��β�����û�н�β��˵�����������Ƿ��ַ���
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