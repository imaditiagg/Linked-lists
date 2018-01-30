#include<stdio.h>
struct node
{
int data;
struct node *next;
}*head=NULL,*newnode=NULL;

void create()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data in the Node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        
    }
}
void insert_at_end()
{
	create();
	struct node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void print()
{
	printf("Linked list : ");
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}
void delete_end()
{
	if(head==NULL)
	printf("\nUnderflow");
	if(head->next==NULL)
	{
		free(head);
	}
	else
	{
	struct node*temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	struct node*n=temp->next;
	temp->next=NULL;
	free(n);
    }
}
void delete_beg()
{
	if(head==NULL)
	printf("\nUnderflow");
	struct node*n=head;
	head=head->next;
	free(n);
}
void delete_pos()
{
	int pos,count=1;
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	if(pos==1)
	delete_beg();
	else
	{
	struct node*temp=head;
	while(count<pos-1)
	{
		count++;
		temp=temp->next;
	}
	struct node*n=temp->next;
	temp->next=n->next;
	free(n);
}}
int main()
{
	int i;
	create();
	for( i=0;i<4;i++)
	{
		
		insert_at_end();
		//print();
	}
	print();
	printf("\nAfter deletion from end ");
	delete_end();
	print();
	printf("\nAfter deletion from beginning ");
	delete_beg();
	print();
	printf("\nAfter deletion from a specific position ");
	delete_pos();
	print();
}
