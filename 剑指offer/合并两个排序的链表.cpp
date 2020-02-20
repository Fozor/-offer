/*
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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
		//�ж�ָ���Ƿ�Ϊ��
		if (pHead1 == NULL){
			return pHead2;
		}
		else if (pHead2 == NULL){
			return pHead1;
		}
		ListNode* pMergedHead = NULL;
		if (pHead1->val < pHead2->val){
			pMergedHead = pHead1;
			pMergedHead->next = Merge(pHead1->next, pHead2);  //�ݹ�
		}
		else{
			pMergedHead = pHead2;
			pMergedHead->next = Merge(pHead1, pHead2->next);//�ݹ�
		}
		return pMergedHead;
	}
};