/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //sort
using namespace std;


class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.length() == 0){
			return result;
		}
		PermutationSwap(str,0);  //全排列 递归实现
		sort(result.begin(), result.end());   //排序
		return result;
	}

	void Show(){
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << endl;
		}
	}
private: 
	vector<string> result;  //私有变量 保护数据

	void PermutationSwap(string str, int index){  //头部元素依次和后边元素进行调换  返回值为void
		if (index == str.length()){
			result.push_back(str);
			return ;
		}
		for (int i = index; i < str.length(); i++){
			if ((str[i] == str[index]) && (i != index)){
				continue;
			}
			//swap str[i] str[index]
			swap(str[i], str[index]);
			PermutationSwap(str, index+1);  //这里必须为index+1   递归调用
		}
	}

};

/*

int main(){
	Solution S;
	string str = "abc";
	S.Permutation(str);
	S.Show();
	system("pause");
	return 0;
}
*/
