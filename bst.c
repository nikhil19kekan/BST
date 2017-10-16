#include<stdio.h>

struct node{
	int val;
	struct node* left;
	struct node* right;
};
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
int main(){
        int height=0,max,min,size,i;
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
		printf("\nEnter choice\n1)find max\n2)find min\n3)exit\n");
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
				printf("Good Bye !!\n");
			exit(0);
		}
	}
}

