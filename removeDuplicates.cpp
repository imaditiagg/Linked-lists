//remove duplicates in an unsorted LL
// O(n^2) time complexity
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


void remove (node*&head)
{
	node*temp1=head;
	node*temp2;
	node*dup;
	while(temp1!=NULL && temp1->next!=NULL )
	{
		temp2=temp1;
		while(temp2->next!=NULL)
		{
			if(temp1->data == temp2->next->data)
			{
				dup=temp2->next; //store the duplicate one
				temp2->next=temp2->next->next; //change pointer
				delete(dup); //delete
			}
			else
			temp2=temp2->next; 
		}
		temp1=temp1->next;
	}
}
int main()
{
	node*head=NULL;
	takeInput(head);
	print(head);
	remove(head);
	cout<<"\nList after removing duplicates: ";
	print(head);
}
