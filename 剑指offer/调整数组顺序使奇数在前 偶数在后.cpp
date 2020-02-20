/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

*/


#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//法一：双vector实现  3ms
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		vector<int>buf1;  //存偶数
		vector<int>buf2;  //存奇数
		for (int i = 0; i<array.size(); i++){
			array[i] % 2 == 0 ? buf1.push_back(array[i]):buf2.push_back(array[i]);
			
		}
		array.clear();
		array = buf2;
		array.insert(array.end(), buf1.begin(), buf1.end());
	}
	void show(vector<int> &array){
		vector<int>::iterator it ;
		for (it = array.begin(); it != array.end(); it++){
			cout << *it<<" " << endl;
		}
	}
};

class Solution2 {
public:
	void reOrderArray(vector<int> &array) {
		deque<int>dq;
		int num = array.size();
		for (int i = 0; i < num; i++){
			if (array[i] % 2 == 0) dq.push_back(array[i]); 
			if (array[num - i - 1] % 2 != 0) dq.push_front(array[num - i - 1]);
		}
		array.clear();
		array.assign(dq.begin(), dq.end());
		//array.insert(array.begin(), dq.begin(),dq.end());  //两种方法都可以
	}
	void show(vector<int> &array){
		vector<int>::iterator it;
		for (it = array.begin(); it != array.end(); it++){
			cout << *it << " " << endl;
		}
	}
};


/*
int main(){
	 Solution2 S;
	 vector<int>arr = { 1, 2,3,4,5,6 };
	 S.reOrderArray(arr);
	 S.show(arr);
	 system("pause");
	 return 0;

}
*/