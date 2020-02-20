/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //sort
using namespace std;

//法一：不知道哪里错了！！！
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.length() <= 0){
			return NULL;
		}
		result = &str[0] + (n % (str.length()));
		for (int i = 0; i<(n % (str.length())); i++){
			result = result + str[i];
		}
		return result;
	}
	void show(){
		cout << result << endl;
	}
private:
	string result;
};

//法2：反转字符串三次达到效果
class Solution2 {
public:
	string LeftRotateString(string str, int n) {
		if (str.size() < 0){   //必须是小于0  不能是小于等于
			return NULL;
		}
		result = str;
		if ((n >= 0) && (n <= str.size())){
			int pFirstpartBegin = 0;
			int pFirstpartend = n - 1;
			int pSecondPartBegin = n;
			int pSecondPartEnd = str.size() - 1;
			reverseStr(result, pFirstpartBegin, pFirstpartend);
			reverseStr(result, pSecondPartBegin, pSecondPartEnd);
			reverseStr(result, pFirstpartBegin, pSecondPartEnd);
			
		}
		return result;
		
	}
	void show(){
		cout << result << endl;
	}
private:
	string result;
	void reverseStr(string& str, int begin ,int end){
		while (begin < end){
			swap(str[begin++],str[end--]);
		}

	}
};
/*
int main(){
	Solution2 S;
	string str = "helloabcsefg";
	S.LeftRotateString(str,5);
	S.show();
	system("pause");
	return 0;
}
*/