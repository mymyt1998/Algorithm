/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL||head->next==NULL)
           return head;
        ListNode* p=head;
        ListNode* q=head->next;
        ListNode* r=head->next->next;
        p->next=NULL;
        while(r!=NULL)
        {
            q->next=p;
            p=q;
            q=r;
            r=r->next;
        }
        q->next=p;
        return q;
    }
};

// 采用递归的方法，就是使用反转函数反转子链表，直接当做已经反转了。
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)){
            return head;
        }
        else{
            ListNode* son_list = reverseList(head->next);
            // 子链表的尾节点指向前一个节点
            head->next->next = head;
            head->next = NULL;
            return son_list;
        }
    }
};
