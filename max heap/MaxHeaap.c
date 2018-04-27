#include<stdio.h>
#include<conio.h>

void createmaxheap(int,int []);
int parent(int);
int leftchild(int);
int rightchild(int);
void swap(int,int,int[]);
void printarray(int[],int);
int main(){
	int heap_array[10]={7,9,2,16,18,15};
	printf("before heaping");
	printarray(heap_array,heap_array[0]);
	createmaxheap(sizeof(heap_array),heap_array);
	printf("after heaping");
	printarray(heap_array,heap_array[0]);
	return 0;
}

void printarray(int array[],int sz){
	int i;
	for(i=0;i<sz;i++){
		printf("%d ",array[i]);
	}
}
void createmaxheap(int sz,int array[]){
	int i;
	array[0]=sz;
	for(i=1;i<array[0];i+=3){
		if(leftchild(array[i])<rightchild(array[i])){
			swap(i,rightchild(array[i]),array);
		}else{
			swap(i,leftchild(array[i]),array);
		}
	}

}
int leftchild(int p){
	return(2*p);
}
int rightchild(int p){
	return(2*p+1);
}
int parent(int child){
	return(child/2);
}
void swap(int a,int b,int array[]){
	 int temp=array[a];
	 array[a]=array[b];
	 array[b]=temp;
}
