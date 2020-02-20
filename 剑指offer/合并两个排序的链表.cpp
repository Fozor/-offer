/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//判断指针是否为空
		if (pHead1 == NULL){
			return pHead2;
		}
		else if (pHead2 == NULL){
			return pHead1;
		}
		ListNode* pMergedHead = NULL;
		if (pHead1->val < pHead2->val){
			pMergedHead = pHead1;
			pMergedHead->next = Merge(pHead1->next, pHead2);  //递归
		}
		else{
			pMergedHead = pHead2;
			pMergedHead->next = Merge(pHead1, pHead2->next);//递归
		}
		return pMergedHead;
	}
};