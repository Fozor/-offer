/*
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ����
����XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //sort
using namespace std;

//��һ����֪��������ˣ�����
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

//��2����ת�ַ������δﵽЧ��
class Solution2 {
public:
	string LeftRotateString(string str, int n) {
		if (str.size() < 0){   //������С��0  ������С�ڵ���
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