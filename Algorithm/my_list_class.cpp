#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(NULL){}
	ListNode(int x):val(x),next(NULL){}
};

class mylist
{
public:
	mylist():head(NULL){}

	void insert(ListNode *tmp)
	{
		if(!head) {head = tmp; head->next = NULL; return;}

		ListNode *p = head;

		while(p && p->next)
			p = p->next;

		p->next = tmp;
		tmp->next = NULL;
	}

	void reverse()
	{
		if(!head || !head->next) return;
		ListNode *p = head , *q = head->next, *r = head->next->next;
		p->next = NULL;
		
		while(r!=NULL)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;

		head = q;
	}

	void disp()
	{
		ListNode *p = head;
		while(p)
		{
			cout<<p->val<<"->";
			p=p->next;
		}
		cout<<"NULL"<<endl;
	}

private:
	ListNode *head;
};

int main()
{
	mylist *p = new mylist();
	int n = 5;
	while(n--)
	{
		p->insert(new ListNode(n));
		p->reverse();
		p->disp();
		cout<<endl;
	}

	

	return 0;
}