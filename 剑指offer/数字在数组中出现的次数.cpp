/*
统计一个数字在排序数组中出现的次数。
*/
#include<iostream>
#include<vector>
using namespace std;

//法一：遍历  O(n)

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len == 0){
			return 0;
		}
		int cnt = 0;
		for (int i = 0; i<len; i++){
			if (data[i] == k)
				cnt += 1;
		}
		return cnt;
	}
};
//法2：遍历 记录下标  O(n)



//法二：加入二分法查找  O(logn)
class Solution2 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len == 0){
			return 0;
		}
	}
private:
};
/*
int main(){
	vector<int> v = { 1, 2, 3, 3, 3, 3 };
	Solution2 S;
	cout << S.GetNumberOfK(v,3) << endl;


	system("pause");
	return 0;
}
*/
