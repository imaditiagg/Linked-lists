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
node * midpoint(node*head) //without computing length of LL
{
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL && fast->next!=NULL) //when fast reaches end of list slow reaches the mid
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

void reverse(node*&head) //without recursion
{
	node *prev=NULL;
	node*current=head;
	node *n;
	while(current!=NULL)
	{
		n=current->next; //contains the add of next node of current
		current->next=prev; //reverse the links
		prev=current;
		current=n;
	}
	head=prev;
	
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	node * m = midpoint(head);
	cout<<"\nData of mid point is : "<<m->data;
	cout<<"\nReverse of LL : ";
	reverse(head);
	print(head);
	return 0;
}
