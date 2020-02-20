/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/
#include<iostream>
using namespace std;

struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)

	{
		RandomListNode* pNode = pHead;
		//����һ ����ԭ����ABC  ���ƺ��������AABBCC��randomָ�벻���и��ƣ�
		while (pNode != NULL){
			RandomListNode* tmp = (RandomListNode*)malloc(sizeof(RandomListNode));
			tmp->label = pNode->label;
			tmp->next = pNode->next;
			tmp->random = NULL;
			pNode->next = tmp;
			pNode = tmp->next;

		}
		//�����:����randomָ��
		pNode = pHead;
		while (pNode != NULL){
			RandomListNode* pCloned = pNode->next;
			if (pNode->random != NULL){
				pCloned->random = pNode->random->next;
			}
			pNode = pCloned->next;
		}
		//����������������

		pNode = pHead;
		RandomListNode* pClonedHead = NULL;
		RandomListNode* pClonedNode = NULL;
		if (pNode != NULL){
			pClonedHead = pClonedNode = pNode->next;  //ȷ��ͷ�ڵ�
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}
		while (pNode != NULL){
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}
		return pClonedHead;

	}
};

/*
��һ�������Ƹ���ָ���label��next������������ǰѸ��ƵĽ�����Ԫ�����棬������ֱ�Ӵ����µ�����
�ڶ��������ø��Ƴ����Ľ���random����Ϊ�¾ɽ����ǰ���Ӧ��ϵ������Ҳ��һ�������ҵ�random��
���������������������ԭ����ż���Ǹ��Ƶ�����
*/
class Solution2 {
public:

	//��һ�������Ƹ���ָ���label��next
	void CloneNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		while (pNode != NULL){
			RandomListNode* pCloned = new RandomListNode(0);
			pCloned->label = pNode->label;
			pCloned->next = pNode->next;
			pCloned->random = NULL;

			pNode->next = pCloned;
			pNode = pCloned->next;
		}
	}

	//�ڶ�����������ָ���random
	void ConnectSiblingNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		while (pNode != NULL){
			RandomListNode* pCloned = pNode->next;
			if (pNode->random != NULL){
				pCloned->random = pNode->random->next;
			}
			pNode = pCloned->next;
		}
	}

	//����������ָ���ָ��
	RandomListNode* ReconnectNodes(RandomListNode* pHead){
		RandomListNode* pNode = pHead;
		RandomListNode* pClonedHead = NULL;
		RandomListNode* pClonedNode = NULL;

		if (pNode != NULL){
			pClonedHead = pClonedNode = pNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}

		while (pNode != NULL){
			pClonedNode->next = pNode->next;
			pClonedNode = pClonedNode->next;
			pNode->next = pClonedNode->next;
			pNode = pNode->next;
		}
		return pClonedHead;
	}

	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
};