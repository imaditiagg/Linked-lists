
#include<stdio.h>


struct node{
int data;
struct node*next;
};
struct node_occur
{
    int num;
    int times;
    struct node_occur *next;
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
void occur(struct node*head,struct node_occur **result)
{
	struct node*p=head;
	struct node_occur *temp,*prev;
	while(p!=NULL)
	{
		
		temp=*result;
		while(temp!=NULL &&p->data!=temp->num)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL) //create new node_occur
		{
			temp = (struct node_occur *)malloc(sizeof(struct node_occur));
            temp->num = p->data;
            temp->times = 1;
            temp->next = NULL;
            if (*result != NULL) //new node is not added at beginning
            {
                prev->next = temp;
            }
            else //new node is added at beginning
            {
                *result = temp;
            }
		}
		else //change occurence in already create node_occur
		{
			temp->times += 1;
		}
		
		
		p=p->next;
	}
}
void disp_occur(struct node_occur *p)
{
    printf("\n***************************\n  Number\tOccurence\n***************************\n");
    while (p != NULL)
    {
        printf("    %d\t\t%d\n", p->num, p->times);
        p = p->next;
    }
}


int main(){
struct node*head1=NULL;
struct node_occur *result=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,1);
pushFront(&head1,3);
pushFront(&head1,5);
pushFront(&head1,1);
pushFront(&head1,3);
pushFront(&head1,8);
print(head1);
occur(head1,&result);
disp_occur(result);
return 0;
}
