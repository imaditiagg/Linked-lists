#include<iostream>
using namespace std;
class node
{
		public:
	int data;
	node *next;

	node(int d)
	{
		next=NULL;
		data=d;
	}
};
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
}
void insertAtHead(node*&head,int d){
	node* n = new node(d);
	n->next = head;
	head = n;
}
void takeInput(node*&head){
	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
}
node *getTail(node*head){

	while(head->next!=NULL){
		head = head->next;
	}
	return head;
}
bool detect(node*head)
{
	node*slow=head;
	node*fast=head;
	while(fast!=NULL || fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) //pt. where both the pointers meet
		{
			slow=head;
			node*prev=NULL;
			while(slow!=fast) //start moving them again
			{
				prev=fast;
				slow=slow->next;
				fast=fast->next;
				
			}
			//break the cycle
			if(prev==NULL) //means list is circular singly
			{
				node*tail=head;
				while(tail->next!=head){
					tail = tail->next;
				}
				tail->next = NULL;
			}
			else{
				prev->next = NULL;
			}
			return true;
		}
	}
}

int main()
{
	node *head=NULL;
	takeInput(head);
//	print(head);
	node *tail=getTail(head);
	tail->next=head; //making a cycle in LL
	if(detect(head))
	{
		cout<<"\nCycle was present and hence removed";
		print(head);
		
	}
	else
	{
		cout<<"\nCycle was not present";
	}
	return 0;
}
