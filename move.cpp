//move last element in front

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
	cout<<"NULL";
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

void move(node*&head)
{
	
	node*temp=head;
	
	if(temp==NULL || temp->next==NULL)
	return;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
    temp->next->next=head;
    head=temp->next;
    temp->next=NULL;
    
}
int main()
{
	node*head=NULL;
	takeInput(head);
	print(head);
	move(head);
	cout<<"\nList after moving: ";
	print(head);
}
