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
void alternate(node *&head)
{
	node*current=head;
	node*temp=head->next;
	while(current!=NULL && temp!=NULL) //to check for the last node
	{

		
		current->next=current->next->next; //change next pointer
		delete temp;//delete the node
		current=current->next; //update current
		//update temp for next iteration
		if(current!=NULL)
		temp=current->next;
	    

	} 

	
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	alternate(head);
	cout<<"\nAter deletion of alternate nodes: ";
	print(head);
	return 0;
	
}
