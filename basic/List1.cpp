class ListNode {
 public:
    int val;
     ListNode *next;
     ListNode(int val) {
     this->val = val;
     this->next = NULL;
     }
 }
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *del=new ListNode(0);//存删除后的链表
        del->next=head;
        ListNode *temp=del;//新建一个删除结点temp
        for(int i=0;i<n;i++)
            head=head->next;
        while(head!=NULL)
            {
              head=head->next;
              temp=temp->next;
            }
        temp->next=temp->next->next;
        return del->next;
    }
};
