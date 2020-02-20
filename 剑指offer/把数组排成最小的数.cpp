#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //sort
using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0){
			return "";
		}
		sort(numbers.begin(), numbers.end(),comp);//comp为参数
		string result;
		for (int i=0; i < len; i++){
			result += to_string(numbers[i]);
		}
		return result;
	}
private:
	static bool comp(int a, int b){  //必须是静态函数 才能被sort作为参数
		string A;
		string B;
		A = to_string(a) + to_string(b);
		B = to_string(b) + to_string(a);
		return A < B;
	}


};
/*
int main(){
	Solution S;
	vector<int> v = { 3, 32, 321 };
	cout << S.PrintMinNumber(v) << endl;

	system("pause");
	return 0;
}
*/