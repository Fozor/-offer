/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/


#include<iostream>
#include<stack>
#include<string>
#include<algorithm>   //sort
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() < 0){   //必须是小于0  不能是小于等于
			return NULL;
		}
		stack<string>stk;

		int i = 0;
		
		string buf;
		while (str[i] != '\0'){
			if (str[i] != ' '){
				buf += str[i];
			}
			else if(str[i]==' '){
				stk.push(buf);
				stk.push(" ");
				buf = "";
			}
			i++;
		}
		stk.push(buf);
		while (!(stk.empty())){
			result = result + stk.top();
			stk.pop();
		}
		return result;

	}
	void show(){
		cout << result << endl;
	}
private:
	string result;

};


class Solution2 {
public:
	string ReverseSentence(string str) {
	     result = str;
		int length = result.size();
		if (length == 0){
			return "";
		}
		// 追加一个空格，作为反转标志位
		result += ' ';
		int mark = 0;
		// 根据空格，反转所有单词
		for (int i = 0; i < length + 1; i++){
			if (result[i] == ' '){
				Reverse(result, mark, i - 1);
				mark = i + 1;
			}
		}
		// 去掉添加的空格
		result = result.substr(0, length);
		// 整体反转
		Reverse(result, 0, length - 1);

		return result;
	}
	void show(){
		cout << result << endl;
	}
private:
	string result;
	void Reverse(string &str, int begin, int end){
		while (begin < end){
			swap(str[begin++], str[end--]);
		}
	}
};

/*
int main(){
	Solution2 S;
	string str = "student. a am I";
	S.ReverseSentence(str);
	S.show();
	system("pause");
	return 0;
}

*/