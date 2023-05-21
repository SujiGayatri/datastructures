#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL,*temp,*NN,*par,*res;
NODE * Newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->right=NULL;
	NN->left=NULL;
	return NN;
}
void insert(int val)
{
	NN=Newnode(val);
	temp=root;
	if(root==NULL)
	{
		root=NN;
		return;
	}
	while(1)
	{
		if(temp->data==NN->data)
		{
			printf("Element is already in BST\n");
			return;
		}
		else if(temp->data>NN->data)
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else
			{
				temp->left=NN;
				break;
			}
		}
		else if(temp->data<NN->data)
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else
			{
				temp->right=NN;
				break;
			}
		}
	}
}
NODE * delet(int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	temp=root;
	par=NULL;
	while(temp && temp->data!=key)
	{
		if(temp->data>key)
		{
			par=temp;
			temp=temp->left;
		}
		else if(temp->data<key)
		{
			par=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		return NULL;
	}
	//zero child
	if(temp->right==NULL && temp->left==NULL)
	{
		res=temp;
		if(par->right!=NULL&& par->right->data==key)
		{
			par->right=NULL;
		}
		else if(par->left!=NULL &&  par->left->data==key)
		{
			par->left=NULL;
		}
		return res;
	}
	//single child  right
	else if(temp->left==NULL)
	{
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->right;
		}
		else if(par->right!=NULL && par->left->data==key)
		{
			par->right=temp->right;
		}
		return res;
	}
	//single child  left
	else if(temp->left==NULL)
	{
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->left;
		}
		else if(par->right!=NULL && par->right->data==key)
		{
			par->right=temp->left;
		}
		return res;
	}
	else if(temp->left!=NULL && temp->right!=NULL)
	{
		//node has two children
		NODE *p,*t;
		int val;
		t=temp->right;
		p=NULL;
		while(t->left)
		{
			p=t;
			t=t->left;
		}
		if(p!=NULL)
		{
			res=t;
			val=t->data;
			t->data=temp->data;
			temp->data=val;
			p->left=t->right;
			return res;
		}
		else
		{
			res=t;
			val=t->data;
			t->data=temp->data;
			temp->data=val;
			temp->right=t->right;
			return res;
		}
	}
}
int search(int val)
{
	temp=root;
	while (1)
	{
		if (temp == NULL) {
			return 0;
		}
		if(temp->data==val)
		{
			return 1;
		}
		else if(temp->data>val)
		{
			temp=temp->left;
		}
		else if(temp->data<val)
		{
			temp=temp->right;
		}
	}
}
void inorder(NODE * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(NODE * root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(NODE * root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	
}
int main()
{
	int ch,val,key,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	while(1)
	{
		printf("1.insert 2.delete 3.search 4.inorder 5.preorder 6.postorder 7.level order 8.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==2)
		{
			//delete
			scanf("%d",&key);
			res=delet(key);
			if(res)
			{
			    printf("%d\n",res->data);
			    free(res);
		    }
		    else
		    {
		    	printf("Element is not found\n");
			}
		}
		else if(ch==3)
		{
			//search
			scanf("%d",&key);
			if(search(key))
			{
				printf("Element found\n");
			}
			else
			{
				printf("Element not found\n");
			}
		}
		else if(ch==4)
		{
			//inorder
			inorder(root);
		}
		else if(ch==5)
		{
			//preorder
			preorder(root);
		}
		else if(ch==6)
		{
			//postorder
			postorder(root);
		}
		else if(ch==7)
		{
			//level order
			//levelorder(root);
		}
		else
		{
			break;
		}
	}
}

/*
13
50 40 80 30 45 70 90 25 35 42 48 65 100
*/
