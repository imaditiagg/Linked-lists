#include<iostream>
#include<stack>
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
node* reverse(node*head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node *chotahead=reverse(head->next);
	node*temp=chotahead;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return chotahead;
}
//optimized approach
node* reverse2(node*head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node *chotahead=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return chotahead;
}

int main()
{
	node *head1=NULL,*head2=NULL;
	cout<<"Enter list 1 : ";
	takeInput(head1);
	print(head1);
	head2=reverse(head1);
	cout<<"\n";
	print(head2);
	return 0;
}
