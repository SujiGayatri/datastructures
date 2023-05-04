#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*res,*NN;
NODE * newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->prev=NULL;
	NN->next=NULL;
	return NN;
}
void insert_at_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		NN->next=head;
		head->prev=NN;
		head=NN;
	}
}
void insert_at_end(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		NN->prev=tail;
		tail->next=NN;
		tail=NN;
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
		}
		temp=temp->next;
	}
	NN->next=temp->next;
	NN->prev=temp;
	temp->next=NN;
	NN->next->prev=NN;
}
void display_from_head()
{
	if(head==NULL && tail==NULL)
	{
		printf("NO Nodes\n");
	}
	else
	{
		temp=head;
		while(temp)
		{
			printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
void display_from_tail()
{
	if(head==NULL && tail==NULL)
	{
		printf("NO Nodes\n");
	}
	else
	{
		temp=tail;
		while(temp)
		{
			printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
			temp=temp->prev;
		}
	}
}
NODE * delet_at_head()
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
		return res;
	}
	else
	{
		res=head;
		head=head->next;
		head->prev=NULL;
		res->next=NULL;
		return res;
	}
}
NODE *delet_at_end()
{
	if(head==NULL && tail==NULL)
	{
		return res;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	else
	{
		res=tail;
		tail=tail->prev;
		tail->next=NULL;
		res->prev=NULL;
		return res;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert at head 2.insert at end 3.insert by pos 4.display from head to tail 5.display from tail to head 6.delete at head 7.delete at end 8.delete by pos 9.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert at head
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_head(NN);
		}
		else if(ch==2)
		{
			//insert at end
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_end(NN);
		}
		else if(ch==3)
		{
			//insert by pos
			scanf("%d",&pos);
			scanf("%d",&val);
			NN=newnode(val);
			insert_by_pos(NN,pos);
		}
		else if(ch==4)
		{
			//display from head to tail
			display_from_head();
		}
		else if(ch==5)
		{
			//display from tail to head
			display_from_tail();
		}
		else if(ch==6)
		{
			res=delet_at_head();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==7)
		{
			res=delet_at_end();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if()
		else
		{
			break;
		}
	}
}
