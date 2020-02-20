/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/
#include<iostream>
#include<vector>
#include<algorithm>   //sort
using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {  //将A分为左上和右下   别计算乘积
		int len = A.size();
		vector<int>B(len);

		if ( len <= 0){
			return B;
		}
		B[0] = 1;
		for (int i = 1; i < len ; ++i){
			B[i] =B[i-1]* A[i-1];
		}
		int tmp=1;
		for (int i = len - 2; i >= 0; --i){
			tmp *= A[i + 1];
			B[i] *= tmp;
		}
		return B;
	}
		
};

