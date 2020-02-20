/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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
				spacenum++;  //空格个数
			++i;         //数组长度
		}
		int relength = spacenum * 2 + i;  //输出数组长度
		for (int j = i; j >= 0, relength >= 0;j--){  //从原数组尾开始进行判断 防止原数组数据被覆盖
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