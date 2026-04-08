#include <iostream>
using  namespace std;
struct  LLNode {
    int data;
    LLNode *next;
};


void insert(LLNode* &list ,string bigInt) {
    for(int i=0;i<bigInt.length();i++) {
        LLNode *temp = new LLNode();
        temp->data=bigInt[i] - '0';
        if(list==NULL) {
            list=temp;
            temp->next = NULL;
        }
        else {
            LLNode *cur = list;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
            temp->next = NULL;
        }
    }
}

void reverse(LLNode* &list) {
    LLNode *cur = list;
    LLNode *prev = NULL;
    LLNode *next= NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list = prev;
}
void display(LLNode* &list) {
    LLNode *temp = list;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void addition(LLNode* &list1, LLNode* &list2, LLNode* &list3) {
    LLNode *cur1 = list1;
    LLNode *cur2 = list2;
    int sum = 0;
    int data=0;
    int carry = 0;
    while(cur1 != NULL || cur2 != NULL) {
        LLNode *temp = new LLNode();
        int val1= (cur1!=NULL) ? cur1->data : 0;
        int val2 = (cur2!=NULL) ? cur2->data : 0;
        sum=val1+ val2+ carry;
        data=sum%10;
        carry=sum/10;
        temp->data = data;
        if (list3==NULL) {
            list3 = temp;
            temp->next = NULL;
        }else {
            LLNode *cur = list3;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
            temp->next = NULL;
        }
        if (cur1 != NULL) cur1 = cur1->next;
        if (cur2 != NULL) cur2 = cur2->next;
    }
    if (carry>0) {
        LLNode *temp = new LLNode();
        temp->data = carry;
        temp->next = NULL;
        if (list3 == NULL) {
            list3 = temp;
        } else {
            LLNode *cur = list3;
            while(cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
        }
    }
}
void subtraction(LLNode* &list1, LLNode* &list2, LLNode* &list3) {
    LLNode *cur1 = list1;
    LLNode *cur2 = list2;
    LLNode *cur3 = NULL;
    int borrow=0;
    while(cur1 != NULL || cur2 != NULL) {

        int val1= (cur1!=NULL) ? cur1->data : 0;
        int val2 = (cur2!=NULL) ? cur2->data : 0;

        val1=val1-borrow;
        if (val1<val2) {
            val1=val1+10;
            borrow=1;
        }else {
            borrow=0;
        }
        LLNode* temp = new LLNode();
        temp->data = val1-val2;
        temp->next = NULL;

        // insert into result list
        if (list3 == NULL) {
            list3 = temp;
            cur3 = temp;
        } else {
            cur3->next = temp;
            cur3 = temp;
        }

        // move input pointers
        if (cur1 != NULL) cur1 = cur1->next;
        if (cur2 != NULL) cur2 = cur2->next;
    }
}

int main() {
    LLNode *list1 = NULL;
    LLNode *list2 = NULL;
    LLNode *list3 = NULL;
    LLNode *list4 = NULL;

    string bigInt;
    string secondInteger;
    cout << "Enter the big integer: ";
    cin>>bigInt;
    insert(list1,bigInt);
    reverse(list1);
    display(list1);
    cout << "Enter the second integer: ";
    cin>>secondInteger;
    insert(list2,secondInteger);
    reverse(list2);
    display(list2);
    addition(list1,list2,list3);
    reverse(list3);
    display(list3);
    subtraction(list1,list2,list4);
    reverse(list4);
    display(list4);
    return 0;
}
