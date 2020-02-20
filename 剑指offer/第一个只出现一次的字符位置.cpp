/*
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.length() == 0 || str.length() > 10000){
			return -1;
		}
		map<char, int>mmap;
		for (int i = 0; i < str.length(); ++i){    //�״α���ԭ�ַ��� ����ظ�����
			mmap[str[i]] += 1;
		}
		for (int j = 0; j < str.length(); ++j){		//�ڶ��α���Դ�ַ��� ��ȡ��һ������1��λ��
			if (mmap[str[j]] == 1){
				return j;
			}
		}
		return -1;
	}
};

/*
int main(){
	Solution S;

	string str = "asdsaghe";
	cout << S.FirstNotRepeatingChar(str)<<endl;
	system("pause");
	return 0;
}
*/