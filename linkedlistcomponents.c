/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* nums, int numsSize) { int c[10000]={0};
for(int i=0;i<numsSize;i++)
    c[nums[i]]++;

struct ListNode* next= head;

int z=0;

while(next!=NULL){
    if(next!=NULL && c[next->val]==1){
        while(next!=NULL && c[next->val]==1){
            next=next->next;
        }
        z++;
    }
    else next=next->next;
}

return z;
    
}
