/*
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
*/

#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

class Solution {
public:
	bool isnum(char buf){
		return ((buf >= '0') && (buf <= '9'));
	}
	bool isop(char buf){
		return ((buf == '-') || (buf == '+'));
	}
	int StrToInt(string str) {
		int length;
		long long result=0;  //�����ܴ�ķ�Χ
		if ((length=str.size()) == 0){
			return 0;
		}
		for (int i = length - 1; i > 0; i--){
			if (isnum(str[i])){
				result += (str[i] - '0')*pow(10, (length -1- i));
			}
			else{
				return 0;
			}

		}
		if (isop(str[0])){  //�жϵ�һλ�Ƿ�Ϊ����
			if (str[0] == '-'){
				result = 0 -result;
			}
		}
		else if (isnum(str[0])){
			result += (str[0] - '0')*pow(10, length - 1);
		}
		else{
			return 0;
		}
		//�߽������ж�
		if (result> 2147483647){
			return 0;
		}
		else if (abs(result) > 2147483648){
			return 0;
		}
		else{
			return result;
		}
	}

};



class Solution2 {
public:
	enum Status{ kValid = 0, kInValid };
	int g_nStatus = kValid;
	int StrToInt(string str) {
		g_nStatus = kInValid;
		long long num = 0;
		const char* cstr = str.c_str();
		// �ж��Ƿ�Ϊָ����Ƿ�Ϊ���ַ���
		if (cstr != NULL && *cstr != '\0'){
			// �����ű�־λ��Ĭ���ǼӺ�
			bool minus = false;
			if (*cstr == '+'){
				cstr++;
			}
			else if (*cstr == '-'){
				minus = true;
				cstr++;
			}
			if (*cstr != '\0'){
				num = StrToIntCore(cstr, minus);
			}
		}
		return (int)num;
	}
private:
	long long StrToIntCore(const char* cstr, bool minus){
		long long num = 0;
		while (*cstr != '\0'){
			// �ж��Ƿ��ǷǷ�ֵ
			if (*cstr >= '0' && *cstr <= '9'){
				int flag = minus ? -1 : 1;
				num = num * 10 + flag * (*cstr - '0');
				// �ж��Ƿ����,32λ
				if ((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
					num = 0;
					break;
				}
				cstr++;
			}
			else{
				num = 0;
				break;
			}
		}
		// �ж��Ƿ���������
		if (*cstr == '\0'){
			g_nStatus = kValid;
		}
		return num;
	}
};
/*
int main(){
	string str = "-2147483649";
	string srr2 = "-2147483648";
	Solution S;
	cout << S.StrToInt(str) << endl;
	cout << S.StrToInt(srr2) << endl;
	system("pause");
	return 0;
}
*/