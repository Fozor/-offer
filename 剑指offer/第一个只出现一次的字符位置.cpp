/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
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
		for (int i = 0; i < str.length(); ++i){    //首次遍历原字符串 添加重复次数
			mmap[str[i]] += 1;
		}
		for (int j = 0; j < str.length(); ++j){		//第二次遍历源字符串 获取第一个出现1的位置
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