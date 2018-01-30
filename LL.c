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
void insert_at_beg()
{
	create();
	newnode->next=head;
	head=newnode;
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
void insert_at_pos()
{
	int pos;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(pos==1)
	insert_at_beg();
	else
	{
	int count=1;
	struct node*temp=head;
	while(count<pos-1)
	{
		count++;
		temp=temp->next;
	}
	printf("%d",temp->data);
	create();
	newnode->next=temp->next;
	temp->next=newnode;
    }
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
void length()
{
	int count=1;
	struct node*temp=head;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("\nLength of linked list is: %d ",count);
	
}


int main()
{
printf("Creation of first node");
create();
print();
printf("\n\nInsertion at beginning");
insert_at_beg();
print();
printf("\n\nInsertion at end");
insert_at_end();
print();
printf("\n\nInsertion at any given position");
insert_at_pos();
print();
length();
return 0;
}
