// swap nodes in a LL without swapping data

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
void swap(node*&head,int x,int y)
{
	if(x==y) //if they are same,no need of swapping
	return;

	node*prevX=NULL;
	node*prevY=NULL;
	node*currentX=head;
	node*currentY=head;
    while(currentX && currentX->data!=x)
    {
    	prevX=currentX;
    	currentX=currentX->next;
	}
	while(currentY && currentY->data!=y)
    {
    	prevY=currentY;
    	currentY=currentY->next;
	}
	// If either x or y is not present, nothing to do
   if (currentX == NULL || currentY == NULL)
   {
   	   cout<<"\nNot present";
       return;
   }
       // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currentY;
   else // Else make y as new head
       head = currentY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currentX;
   else  // Else make x as new head
       head = currentX;
 
   // Swap next pointers
   node *temp = currentY->next;
   currentY->next = currentX->next;
   currentX->next  = temp;
   
       
	
}
int main()
{
	node *head=NULL;
	takeInput(head);
	print(head);
	swap(head,3,6);
	cout<<"\n";
	print(head);
	return 0;
}
