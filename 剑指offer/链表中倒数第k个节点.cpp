/*
输入一个链表，输出该链表中倒数第k个结点。
*/
#include<iostream>

using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
//双指针 间隔k-1
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0){
			return NULL;
		}
		ListNode* A = pListHead;
		ListNode* B = pListHead;
		int i = 0;
		while ((A->next) != NULL){
			if (i < k - 1){
				A = A->next;
				i++;
			}else{
				A = A->next;
				B = B->next;
			}
		}
		if (i == k - 1){
			return B;
		}
		else{
			return NULL;
		}
	}
};

class Solution2 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0){
			return NULL;
		}
		ListNode *pAhead = pListHead;
		ListNode *pBehind = pListHead;
		for (unsigned int i = 0; i < k - 1; i++){
			if (pAhead->next != NULL){
				pAhead = pAhead->next;
			}
			else{
				return NULL;
			}
		}
		while (pAhead->next != NULL){
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};