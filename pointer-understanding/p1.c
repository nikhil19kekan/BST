#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAPSIZE 10

struct rowcol{
	int row;
	int col;
};
//dclared two golbal character arrays empty
char DirectionsFilename[100]={};
char MapFilename[100]={};
int matrix[MAPSIZE][MAPSIZE];
void moveeast(struct rowcol *ptr){
	if(ptr->col < (MAPSIZE-1)){
		ptr->col=(ptr->col)+1;
	}
}
void movewest(struct rowcol *ptr){
	if(ptr->col > 0){
		ptr->col=(ptr->col)-1;
	}
}
void movesouth(struct rowcol *ptr){
	if(ptr->row < 9){
		ptr->row=(ptr->row)+1;
	}
}
void movenorth(struct rowcol *ptr){
	if(ptr->row >0){
		ptr->row=(ptr->row)-1;
	}
}
void print_matrix(int arr[MAPSIZE][MAPSIZE]){
	int i,j;
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
void get_direction(char *str){
	int i=0,j=0,k=0,res;
	char dest[11];
	char ch;
	while(i<=strlen(str)){
		strncpy(dest,(str+i),10);
		dest[10]='\0';
		res=strcmp(dest,"DIRECTION=\0");
		if(res==0){
			i=i+10;
			while(i<=strlen(str) && ((ch=(char)str[i])!=' ' || (ch=(char)str[i]!='\n') || (ch=(char)str[i])!=EOF)){
				DirectionsFilename[k]=ch;
				k++;
				i++;
			}
		}else{
			i=i+10;
		}
	}
}
void get_map(char *str){
	int i=0,j=0,k=0,res;
	char dest[5];
	char ch;
	while(i<=strlen(str)){
		strncpy(dest,(str+i),4);
		dest[4]='\0';
		res=strcmp(dest,"MAP=\0");
		if(res==0){
			i=i+4;
			while(i<=strlen(str) && ((ch=(char)str[i])!=' ' || (ch=(char)str[i]!='\n') || (ch=(char)str[i])!=EOF)){
				MapFilename[k]=ch;
				k++;
				i++;
			}
		}else{
			i=i+4;
		}
	}
}
void get_command_line_parameters(int argc,char *argv[]){
	int i,j;
	for(i=1;i<(int)argc;i++){
		get_direction(argv[i]);
		get_map(argv[i]);
	}
}
int main(int argc,char *argv[]){
	int i,j;
	char ch;
	FILE *file;
	//reading paramters
	get_command_line_parameters(argc,argv);
	//printing contents of both character arrays DirectionsFilename and MapFilename
	//initialise matrix with 0
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			matrix[i][j]=0;
		}
	}
	matrix[0][0]=1;
	//initialised rows and columns for structure
	struct rowcol *mylocation=(struct rowcol *)malloc(1*sizeof(struct rowcol));
	mylocation->row=0;
	mylocation->col=0;
	//open fil to read input
		i=0;
		while((ch=DirectionsFilename[i])=='S'||(ch=DirectionsFilename[i])=='N'||(ch=DirectionsFilename[i])=='E'||(ch=DirectionsFilename[i])=='W'||(ch=DirectionsFilename[i])=='X'){
		switch(ch){
			case 'S':
				movesouth(mylocation);
				matrix[mylocation->row][mylocation->col]=1;
			break;

			case 'N':
				movenorth(mylocation);
				matrix[mylocation->row][mylocation->col]=1;
			break;

			case 'E':
				moveeast(mylocation);
				matrix[mylocation->row][mylocation->col]=1;
			break;
				
			case 'W':
				movewest(mylocation);
				matrix[mylocation->row][mylocation->col]=1;
			break;
				
			case 'X':
				printf("found tresure at location:\n");
				matrix[mylocation->row][mylocation->col]=1;
				printf("%d\t%d\n",mylocation->row,mylocation->col);
				print_matrix(matrix);
			}	
		i++;
		}
return 0;
}
