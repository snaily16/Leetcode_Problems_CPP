// LeetCode problem 2
//https://leetcode.com/problems/add-two-numbers/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *NumToList(int num);
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
void printList(ListNode* head);
int Addition(int n1, int n2, int &carry);

int main(){
    int n1, n2;
    cin>>n1>>n2;
    ListNode *l1 = NumToList(n1);
    ListNode *l2 = NumToList(n2);
    printList(l1);
    printList(l2);
    ListNode *lsum = addTwoNumbers(l1, l2);
    printList(lsum);
}


ListNode *NumToList(int num){
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int digit;
    while(num){
        digit = num % 10;
        num = num / 10;
        temp->val = digit;
        if(num){
            ListNode* newNode = new ListNode();
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;    
}

int Addition(int n1, int n2, int *carry){
    int sum = n1 + n2 + *carry;
    *carry = sum/10;
    sum = sum%10;
    return sum;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    ListNode *head = new ListNode();
    ListNode *temp = head;
    int sum, carry=0;

    while(l1 != NULL && l2 != NULL){
        temp->val = Addition(l1->val, l2->val, &carry);
        l1 = l1->next;
        l2 = l2->next;
        if(l1 !=NULL && l2!=NULL){
            temp->next = new ListNode();
            temp = temp->next;
        }
    }
    while(l1!=NULL){
        temp->next = new ListNode();
        temp = temp->next;
        temp->val = Addition(l1->val, 0, &carry);
        l1 = l1->next;
    }

    while(l2!=NULL){
        temp->next = new ListNode();
        temp = temp->next;
        temp->val = Addition(0, l2->val, &carry);
        l2 = l2->next;
    }

    if(carry>0){
        temp->next = new ListNode();
        temp = temp->next;
        temp->val = Addition(0,0,&carry);
    }
    return head;
}

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
    cout<<temp->val<<"->";
    temp = temp->next;
    }
    cout<<endl;
}
