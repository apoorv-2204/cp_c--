/*AIM:  WAP to implement BST*/

#include<stdio.h>
#include<stdlib.h>

struct BinaryTree{
	struct BinaryTree *left;
	int data;
	struct BinaryTree *right;

};
typedef struct BinaryTree node;

node *fnode=NULL,*parent=NULL;

node *create(node*,int);
void preorder(node*);
void inorder(node*);
void postorder(node*);
void search(node*,int);
void delnode(node**,int);

void main(){
	int ch;
	node *root=NULL;
	int data;
	do{
		
		printf("\n 1. Insertion");
		printf("\n 2. Preorder");
		printf("\n 3. Inorder");
		printf("\n 4. Postorder");
		printf("\n 5. Searching");
		printf("\n 6. Deletion");
		printf("\n 0. Exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);

		switch(ch){
			case 1:	printf("\n Enter Data");
				scanf("%d",&data);
				root=create(root,data);
				break;
			case 2: preorder(root);
				break;
			case 3: inorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: printf("\n Enter data to be search");
				scanf("%d",&data);
				search(root,data);

				if(fnode==NULL){
					printf("\n No suitable data found");
				}
				else{
					printf("\n Data %d found",data);
				}
				 break;
			case 6:
				printf("\n Enter data to be deleted");
				scanf("%d",&data);
				delnode(&root,data);
				break;
			case 0: exit(0);
			default: printf("\n Wrong choice");
		}
	}while(1);
}

node* create(node *p,int data){

	if(p==NULL){
		p=(node*)malloc(sizeof(node));
		p->data=data;
		p->left=p->right=NULL;
		return p;
	}
	if(p->data>data){
		p->left=create(p->left,data);
	}
	else{
		p->right=create(p->right,data);
	}
	return p;
}

void search(node *r,int key){
	node *q=r;
	fnode=NULL;
	while(q!=NULL)
	{
		if(q->data==key){
			fnode=q;
			return;
		}
		parent=q;
		if(q->data>key)
			q=q->left;
		else
		       q=q->right;
	}
}

void delnode(node **myroot,int key){
	node *succ,*temp;

	if(*myroot==NULL){
		 printf("\n List is empty");
		 return;
	}
	fnode=parent=NULL;

	search(*myroot,key);
	if(fnode==NULL){
		printf("\n No suitable data found");
		return;
	}
	if(fnode->left==NULL && fnode->right==NULL){
		if(parent==NULL){
			*myroot=NULL;
		}
		else if(parent->left==fnode){
			parent->left=NULL;
		}
		else
		{
			parent->right=NULL;
		}
		free(fnode);
		return;
	}
	if(fnode->left!=NULL && fnode->right==NULL){
		if(parent==NULL){
			*myroot=fnode->left;
		}
		else if(parent->left==fnode){
			parent->left=fnode->left;
		}
		else
		{
			parent->right=fnode->left;
		}
		free(fnode);
		return;
	}
	if(fnode->left==NULL && fnode->right!=NULL){
		if(parent==NULL){
			*myroot=fnode->right;
		}
		else if(parent->left==fnode){
			parent->left=fnode->right;
		}
		else
		{
			parent->right=fnode->right;
		}
		free(fnode);
		return;
	}
	if(fnode->left!=NULL && fnode->right!=NULL){
		parent=fnode;
		temp=fnode;
		succ=fnode->left;

		while(succ->right!=NULL){
			parent=succ;
			succ=succ->right;
		}
		fnode->data=succ->data;

		if(parent==temp){
			parent->left=succ->left;
		}
		else{
			parent->right=succ->left;
		}
		free(succ);
		return;
	}
}


void preorder(node *temp){
	if(temp!=NULL){
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
void postorder(node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}
