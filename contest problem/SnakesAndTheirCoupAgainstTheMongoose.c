#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int n,s_row,s_col,e_row,e_col;

void fxn(int row,int col,char arr[][n],char vis[][n]){
	int i,j;
	vis[row][col] = '1';
	if((row == e_row)&&(col==e_col)){
			for(i=0;i<n;i++)
				for(j=0;j<2;j++){
					if(arr[j][i]=='#' && vis[j][i]=='0'){
						printf("no\n");
						return;
					}
				}
			printf("yes\n");
			return;
	}

	if(arr[(row+1)%2][col]=='#'){

		if(vis[(row+1)%2][col]!='1'){
			fxn((row+1)%2,col,arr,vis);
			return;
		}
	}

	if(col+1<n && arr[row][col+1]=='#'){
		fxn(row,col+1,arr,vis);
		return;
	}

	printf("no\n");
	return;

}

int main() {

	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		char str[2][n];
		char f[2][n];
		int i,j,flag1=0,fences=0,flag2=0;
		for(i=0;i<2;i++)
			scanf("%s",str[i]);

		for(i=0;i<2;i++)
			for(j=0;j<n;j++)
				f[i][j]==0;

		for(i=0;i<n;i++)
			if(str[0][i]=='*'){
				for(i=0;i<n;i++)
					if(str[1][i]=='*'){
						fences++;
						break;
					}
				break;
			}
	//printf("fencs=%d",fences);
		if(fences==0){
			for(i=0;i<n-1;i++)
				if(str[0][i]=='*'||str[1][i]=='*')
					for(j=i+1;j<n;j++)
						if(str[0][j]=='*'||str[1][j]=='*'){
							fences++;
							i=j-1;
						}
		}

		else{
			for(i=0,j=0;i<n,j<n;i++,j++){
				//printf("fencs=%d",fences);
				if(str[0][i]=='*' && flag1!=0){
					fences++;
					if(str[1][j]=='*')
						flag2=1;
					else
						flag2=0;
					continue;
				}
				else if(str[1][j]=='*' && flag2!=0){
					fences++;
					if(str[0][i]=='*')
						flag1=1;
					else
						flag1=0;
					continue;
				}
				if(str[0][i]=='*' && flag1==0)
					flag1=1;
				if(str[1][j]=='*' && flag2==0)
					flag2=1;
			}
		}
		printf("%d\n",fences);

	}
}
