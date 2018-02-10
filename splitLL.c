#include<stdio.h>

#include<stdbool.h>

struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*temp ;
temp=(struct node*)malloc(sizeof(struct node));
temp->data = data;
temp->next = NULL;
return temp;
}

void pushFront(struct node**head,int data){
struct node* first = newNode(data);

if(*head==NULL){
 *head = first;
}
else{
    first->next = (*head);
    *head = first;
    }
}

void print(struct node*head)
{
	printf("\nLinked list : ");
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

void split(struct node*head1,struct node**head2)
{
	if(head1==NULL || head1->next==NULL)
	return;
	struct node*fast=head1;
	struct node*slow=head1;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	*head2 = slow->next;
	slow->next=NULL;

	
}
int main()
{
	struct node*head1=NULL;
struct node*head2=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,4);
pushFront(&head1,3);
pushFront(&head1,5);
pushFront(&head1,7);
print(head1);
split(head1,&head2);
print(head1);
print(head2);
}
