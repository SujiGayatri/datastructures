#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;
void insert_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		head->next=head;
	}
	else
	{
		NN->next=head;
		head=NN;
		tail->next=head;
	}
}
void insert_by_pos(NODE *NN,int pos)
{
	int i;
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		if(temp->next==head)
		{
			printf("Insertion is not possible\n");
			return;
		}
		temp=temp->next;
	}
	NN->next=temp->next;
	temp->next=NN;
}
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("NO NODES\n");
	}
	temp=head;
	while(temp->next!=head)
	{
	    printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;	
	}
	printf("%d %d %d\n",temp,temp->data,temp->next);
}
void insert_end(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		head->next=head;
	}
	else
	{
		tail->next=NN;
		tail=NN;
		tail->next=head;
	}
}
NODE* delet_at_head()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return NULL;
	}
	else
	{
		res=head;
		head=head->next;
		tail->next=head;
		res->next=NULL;
		return res;
	}
}
NODE * delet_at_end()
{
	if(head==NULL&&tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return NULL;
	}
	else
	{
		temp=head;
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		res=tail;
		temp->next=head;
		tail=temp;
		res->next=NULL;
		return res;
	}
}
NODE* delet_by_pos(int pos)
{
	int i;
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		if(temp->next==head)
		{
			printf("deletion is not possible\n");
			return NULL;
		}
		temp=temp->next;
	}
	res=temp->next;
	temp->next=res->next;
	res->next=NULL;
	return res;
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert at head 2.insert by pos 3.insert at end 4.display 5.delete at head 6.delete at end 7.delete by pos 8.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_head(NN);
		}
		else if(ch==2)
		{
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_by_pos(NN,pos);
		}
		else if(ch==3)
		{
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_end(NN);
		}
		else if(ch==4)
		{
			display();
		}
		else if(ch==5)
		{
			res=delet_at_head();
			if(res==NULL)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==6)
		{
			res=delet_at_end();
			if(res==NULL)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==7)
		{
			scanf("%d",&pos);
			res=delet_by_pos(pos);
			if(res==NULL)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else
		{
			break;
		}
	}
}
