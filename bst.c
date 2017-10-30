#include<stdio.h>
#include<stdbool.h>
struct node{
	int val;
	struct node* left;
	struct node* right;
};
//function to create a binary search tree
struct node* makeBSTFindHeight(int* array,int size,int* height){
	int i,j,k=0;
	struct node* temp=NULL;
	struct node* root=NULL;
	for(i=0;i<size;i++){
		printf("placing...%d\n",array[i]);
		sleep(0.8);
		if(root == NULL){
			struct node* a=malloc(sizeof(struct node));
			a->val=array[i];
			a->left=NULL;
			a->right=NULL;
			root=a;
			printf("root set:%d\n",root->val);
		}else{
			temp=root;
			int temp_height=0;
			while(temp != NULL){
				if(array[i]<temp->val){
					if(temp->left != NULL){
						temp=temp->left;
						temp_height++;
						printf("moving left\n");
					}else{
						struct node* b=malloc(sizeof(struct node));
						b->left=NULL;
						b->right=NULL;
						b->val=array[i];
						temp->left=b;
						temp=NULL;
						printf("putting on left\n");
					}
				}else{
					if(temp->right != NULL){
						temp=temp->right;
						temp_height++;
						printf("moving right\n");
					}else{
						struct node* c=malloc(sizeof(struct node));
						c->left=NULL;
						c->right=NULL;
						c->val=array[i];
						temp->right=c;
						temp=NULL;
						printf("putting on right\n");
					}
				}	
			}
			if(*height<temp_height){
				*height=temp_height;
			}
		}
	}
*height=*height+1;
return root;
}
//function to find maximum value in the whole BST
int findMax(struct node* root){
	while(root->right!=NULL){	
		root=root->right;
	}
return root->val;
}
//function to find minimum value in the whole BST
int findMin(struct node* root){
	while(root->left!=NULL){
		root=root->left;
	}
return root->val;
}
// function to search an element in BST
bool search_element(int srch,struct node* root){
	struct node* temp=root;
	bool result=false;
	while(temp!=NULL){
		if(temp->val==srch){
			result=true;
			break;
		}else{
			if(srch<temp->val){
				printf("moving left\n");
				temp=temp->left;
			}else{
				printf("moving right\n");
				temp=temp->right;
			}
		}
	}
return result;
}
//function to print bst
void printBST(struct node* root){
	int i;
	static int h=1;
	if(root!=NULL){
		printf("%d",root->val);
		for(i=0;i<h;i++){
			printf("\n");
		}
		printBST(root->left);
		printBST(root->right);
		h++;	
	}
}
struct node* predecessor(struct node* n){
	n=n->left;
	while(n->right != NULL){
		n=n->right;
	}
return n;
}
struct node* successor(struct node* n){
	n=n->right;
	while(n->left != NULL){
		n=n->right;
	}
return n;
}
int main(){
        int height=0,max,min,size,i,srch;
        struct node* root=NULL;
	printf("Enter number of elements to be added into BST:");
	scanf("%d",&size);
	int array[size];
	int choice;
	for(i=0;i<size;i++){
		printf("\nEnter the element %d for BINARY SEARCH TREE:",i);
		scanf("%d",&array[i]);
	}
	printf("\n---------------Building BST--------------\n");
	root=makeBSTFindHeight(array,size,&height);
	printf("Height of the BST built:%d",height);
	while(1){
		printf("\nEnter choice\n1)find max\n2)find min\n3)search\n4)print BST\n5)exit\n");
		scanf("%d",&choice);
		switch(choice)
		{	
			case 1:
				max=findMax(root);
				printf("Maximum value is :%d\n",max);
			break;
			case 2:
				min=findMin(root);
				printf("Minimum element is :%d\n",min);
			break;
			case 3:
				printf("Enter the element to search\n");
				scanf("%d",&srch);
				if(search_element(srch,root)){
					printf("element found");
				}else{
					printf("element not found");
				}
			break;
			case 4:
				printBST(root);
			break;
			case 5:
				printf("Good Bye !!\n");
			exit(0);
		}
	}
}

