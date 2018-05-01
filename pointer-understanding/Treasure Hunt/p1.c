#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAPSIZE 10

struct PlayerInfo{
	char PlayerName[50];
	int row;
	int col;
};
//dclared two golbal character arrays empty
char DirectionsFilename[20]={};
char MapFilename[20]={};
char PlayerPath[MAPSIZE][MAPSIZE];
char MapList[500];
char Map[MAPSIZE][MAPSIZE];
int moveeast(struct PlayerInfo *ptr){
	if(ptr->col < (MAPSIZE-1)){
		ptr->col=(ptr->col)+1;
		return 1;
	}
return 0;
}
int movewest(struct PlayerInfo *ptr){
	if(ptr->col > 0){
		ptr->col=(ptr->col)-1;
		return 1;
	}
return 0;
}
int movesouth(struct PlayerInfo *ptr){
	if(ptr->row < 9){
		ptr->row=(ptr->row)+1;
		return 1;
	}
return 0;
}
int movenorth(struct PlayerInfo *ptr){
	if(ptr->row >0){
		ptr->row=(ptr->row)-1;
		return 1;
	}
return 0;
}
void print_PlayerPath(char arr[MAPSIZE][MAPSIZE]){
	int i,j;
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			printf("%c",arr[i][j]);
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
		//get_direction(argv[i]);
		get_map(argv[i]);
	}
}
int main(int argc,char *argv[]){
	int i,j,k,makemove;
	char ch,PlayerMove;
	FILE *TreasureMap;
	//reading paramters	
	get_command_line_parameters(argc,argv);
	printf("opening file:%s\n",MapFilename);
	TreasureMap=fopen(MapFilename,"r");
	if(TreasureMap==NULL){
		perror("TreasureMap did not open");
		exit(0);
	}
	system("clear");	
	printf("Enter the Player Name\n");
	//initialised rows and columns for structure
	struct PlayerInfo *Player=(struct PlayerInfo *)malloc(1*sizeof(struct PlayerInfo));
	Player->row=0;
	Player->col=0;
	scanf("%s",&Player->PlayerName);
	//reading from TraesureMap into MapList
	fgets(MapList,110,TreasureMap);
	printf("MapList is :%s\n",MapList);
	i=0;
	for(j=0;j<MAPSIZE;j++){
		for(k=0;k<MAPSIZE;k++){
			Map[j][k]=MapList[i];
			printf("%c",Map[j][k]);
			i++;
			PlayerPath[j][k]='-';
		}
	printf("\n");
	}
	scanf("%c",&ch);
	system("clear");
	//printing contents of both character arrays DirectionsFilename and MapFilename
	//initialise PlayerPath with 0
	/*
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			PlayerPath[i][j]=0;
		}
	}
	PlayerPath[0][0]=1;
	*/
	PlayerPath[0][0]=Map[0][0];
	//open fil to read input
	i=0;
	/*
	while((ch=DirectionsFilename[i])=='S'||(ch=DirectionsFilename[i])=='N'||(ch=DirectionsFilename[i])=='E'||(ch=DirectionsFilename[i])=='W'||(ch=DirectionsFilename[i])=='X'){
	switch(ch){
		case 'S':
			movesouth(Player);
			PlayerPath[Player->row][Player->col]=1;
			break;

		case 'N':
			movenorth(Player);
			PlayerPath[Player->row][Player->col]=1;
			break;

		case 'E':
			moveeast(Player);
			PlayerPath[Player->row][Player->col]=1;
			break;
				
		case 'W':
			movewest(Player);
			PlayerPath[Player->row][Player->col]=1;
			break;
				
		case 'X':
			printf("found tresure at location:\n");
			PlayerPath[Player->row][Player->col]=1;
			printf("%d\t%d\n",Player->row,Player->col);
			print_PlayerPath(PlayerPath);
		}	
	i++;
	}
	*/
	do{
		system("clear");
		printf("-------------------------MAP---------------------\n");
		print_PlayerPath(Map);
		printf("------------------------YOUR PROGRESS-------------------\n");
		print_PlayerPath(PlayerPath);
		printf("Enter Direction(NSEW) or 'Q' to quit\n");
		scanf("%c",&PlayerMove);
		PlayerMove=toupper(PlayerMove);
		printf("Player move is :%c\n",PlayerMove);
		if(PlayerMove=='N'){
			printf("moving north:%d\t%d\n",Player->row,Player->col);
			makemove=movenorth(Player);
			//PlayerPath[Player->row][Player->col]='X';
		}else{
			if(PlayerMove=='S'){
				printf("moving south:%d\t%d\n",Player->row,Player->col);
				makemove=movesouth(Player);
				//PlayerPath[Player->row][Player->col]='X';
			}else{
				if(PlayerMove=='E'){
					printf("moving east:%d\t%d\n",Player->row,Player->col);
					makemove=moveeast(Player);
					//PlayerPath[Player->row][Player->col]='X';
				}else{
					if(PlayerMove=='W'){
						printf("moving east:%d\t%d\n",Player->row,Player->col);
						makemove=movewest(Player);
						//PlayerPath[Player->row][Player->col]='X';
					}
				}
			}
		}
		if(makemove==1){
			if(Map[Player->row][Player->col]=='S'){
				printf("Player x is back at the start\n");
			}
			if(Map[Player->row][Player->col]=='X'){
				PlayerPath[Player->row][Player->col]='X';
			}
			if(Map[Player->row][Player->col]=='E'){
				printf("Player x has made it to the end\nWinner !!!!!!\n");
				PlayerPath[Player->row][Player->col]='E';
				PlayerMove='Q';
			}
		}	
	}while(PlayerMove!='Q');
	print_PlayerPath(PlayerPath);
	fclose(TreasureMap);
return 0;
}
