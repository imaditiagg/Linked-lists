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
/* Function to swap two integers */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(node *head)
{
    node *temp = head;
 
    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL)
    {
        /* Swap data of node with its next node's data */
        swap(&temp->data, &temp->next->data);
 
        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	pairWiseSwap(head);
	cout<<"\n";
	print(head);
	return 0;
}
 


