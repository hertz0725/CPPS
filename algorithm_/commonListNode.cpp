#include <iostream>
#include <vector>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *creatList(vector<int> vi)
{
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for(int i=0; i!=vi.size(); i++)
    {
        ListNode *tmp = new ListNode(vi[i]);
        p->next = tmp;
        p=p->next;
    }

    return head->next;
}

void dispList(ListNode *head )
{
    ListNode *p = head;
    while(p!=NULL)
    {
        cout<<p->val<<"->";
        p=p->next;
    }

    cout<<endl;
}

void offsetList(ListNode *&head, int offset)
{
    while(offset-- && head!=NULL)
    {
        cout<<"yyy"<<endl;
        head = head->next;
    }

    cout<<"zzz"<<endl;
    dispList(head);
}

int getListLen(ListNode *head)
{
    int cnt=0;
    
    ListNode *p = head;
    
    while( p != NULL )
    {
        cnt++;
        p=p->next;
    }
    
    return cnt;
    
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int lenA= getListLen(headA);
    cout<<lenA<<endl;
    int lenB= getListLen(headB);
    cout<<lenB<<endl;
    
    int offset = abs(lenA-lenB);

    cout<<"off:"<<offset<<endl;
    
    if(lenA > lenB)
        offsetList(headA, offset);
    else
        offsetList(headB, offset);

    cout<<"hhh"<<endl;
    dispList(headA);
    dispList(headB);
    
    while(headA && headB && headA != headB)
    {
        cout<<"xxx"<<endl;
        headA = headA->next;
        headB = headB->next;
    }
    
    if(headA != headB)
        return NULL;
    
    return headA;
}


int main()
{
    vector<int> v1= {3};
    vector<int> v2={2,3};

    ListNode *headA = creatList(v1);
    ListNode *headB = creatList(v2);

    dispList(getIntersectionNode(headA,headB));


    return 0;
}