#include<stdio.h>
struct node
{
int coeff;
int exp;
struct node *next;
}*head=NULL,*newnode=NULL;

void create()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Coefficient in the Node:");
    scanf("%d",&newnode->coeff);
    printf("\nEnter the Power in the Node:");
    scanf("%d",&newnode->exp);
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
	printf("\nRepresentation of polynomial in the form of Linked list : ");
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%dx^%d-->",temp->coeff,temp->exp);
		temp=temp->next;
	}
	printf("NULL");
}
int main()
{
printf("Insertion");
create();
int i=0;
for(i=0;i<5;i++)
insert_at_end();
print();
return 0;
}
