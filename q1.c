#include<stdio.h>
int main(){
	FILE *pt;
	char str[100];
	pt=fopen("file.txt","r");
	if(!pt){
		printf("Unable to open! \n");
	        return 0;	
	}
	fgets(str,100,pt);
	int n;
	printf("Enter the value of N (it can be 2,3 or 4) \n");
	scanf("%d",&n);
	char sub[100][100];
	int row=0,col=0;
	int count0=0, count1=0, count=0;
	int index=0;
	char c=str[index];
	while(c!='\0'){
		sub[row][col]=c;
                count++;
		if(c=='0')
		count0++;
		else
		count1++;
		col++;
		if(c=='1' || count0==n || count1==n){
			sub[row][col]='\0';
			row++;
			count0=0;
			count1=0;
		}
		index++;
		c=str[index];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%c",sub[i][j]);
		}
		printf("\n");
	}
	return 0;
}
