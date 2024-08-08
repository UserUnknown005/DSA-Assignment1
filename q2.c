#include<stdio.h>
int main(){
	printf("Enter size of matrix (n) \n");
	int n;
	scanf("%d",&n);
	int arr1[n][n];
	int arr2[n][n];
	printf("Enter values of array 1 : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("Enter values of array 2 : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &arr2[i][j]);
		}
	}
	//showing the input
	printf("Array 1 : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("Array 2 : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	int add[n][n];
	int sub[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			add[i][j]=arr1[i][j]+arr2[i][j];
			sub[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	//sparse conversion
	int lenA=0,lenS=0;
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(add[i][j]!=0)
				lenA++;
			if(sub[i][j]!=0)
				lenS++;
		}
	}
	int sp_add[3][lenA];
	int sp_sub[3][lenS];
	int inS=0,inA=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(add[i][j]!=0){
				sp_add[inA][0]=i;
				sp_add[inA][1]=j;
				sp_add[inA][2]=add[i][j];
				inA++;
			}
			if(sub[i][j]!=0){
				sp_sub[inS][0]=i;
				sp_sub[inS][1]=j;
				sp_sub[inS][2]=sub[i][j];
				inS++;
			}
	    }
		
	}
	//output 
	printf("Addition Sparce Matrix : \n");
	for(int i=0;i<lenA;i++){
		for(int j=0;j<3;j++){
			printf("%d  ",sp_add[i][j]);
		}
		printf("\n");
	}
	printf("Subtraction Sparce Matrix : \n");
	for(int i=0;i<lenS;i++){
		for(int j=0;j<3;j++){
			printf("%d  ",sp_sub[i][j]);
		}
		printf("\n");
	}
	return 0;
}

