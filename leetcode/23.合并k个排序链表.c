/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* merge2lists(struct ListNode* head1,struct ListNode* head2){
    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->val<=head2->val){
        head=tail=head1;
        head1=head1->next;
    }
    else{
        head=tail=head2;
        head2=head2->next;  
    }
    while(1){
        if(head1==NULL&&head2!=NULL){
            tail->next = head2;
            head2 = NULL;
            break;
        }
        if(head2==NULL&&head1!=NULL){
            tail->next = head1;
            head1 = NULL;
            break;
        }
        if(head1->val <= head2->val){
            tail->next = head1;
            tail=head1;
            head1 = head1->next;
            }

        else{
            tail->next = head2;
            tail=head2;
            head2 = head2->next;
            }
        }
        return head;

}
        

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int left,right,count;
    if (listsSize <= 0) {
        return NULL;
    }

    do {
        count = 0;
        left = 0;
        right = listsSize-1;
        while (left < right) {
            lists[count++] = merge2lists(lists[left++], lists[right--]);
        }   
        listsSize = (left == right)? left+1:left;
    } while (listsSize != 1);

    return lists[0];

}


// @lc code=end

