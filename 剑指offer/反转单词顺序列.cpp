/*
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/


#include<iostream>
#include<stack>
#include<string>
#include<algorithm>   //sort
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() < 0){   //������С��0  ������С�ڵ���
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
		// ׷��һ���ո���Ϊ��ת��־λ
		result += ' ';
		int mark = 0;
		// ���ݿո񣬷�ת���е���
		for (int i = 0; i < length + 1; i++){
			if (result[i] == ' '){
				Reverse(result, mark, i - 1);
				mark = i + 1;
			}
		}
		// ȥ����ӵĿո�
		result = result.substr(0, length);
		// ���巴ת
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