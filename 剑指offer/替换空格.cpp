/*
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spacenum=0;
		int i = 0;
		while (str[i] != '\0'){
			
			if (str[i] == ' ')
				spacenum++;  //�ո����
			++i;         //���鳤��
		}
		int relength = spacenum * 2 + i;  //������鳤��
		for (int j = i; j >= 0, relength >= 0;j--){  //��ԭ����β��ʼ�����ж� ��ֹԭ�������ݱ�����
			if (str[j] == ' '){
				str[relength--] = '0';
				str[relength--] = '2';
				str[relength--] = '%';
			}
			else{
				str[relength--] = str[j];
			}
		}
	}
};

/*
int main(){
	Solution S;
	char str[255] = "hello world!";
	cout << str << "  " << strlen(str) << endl;
	S.replaceSpace(str, strlen(str));
	cout << str << "  " << strlen(str) << endl;
system("pause");
return 1;
}
*/