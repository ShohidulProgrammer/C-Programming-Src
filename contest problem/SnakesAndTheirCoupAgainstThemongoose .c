#include <stdio.h>
int main(){

	int T;
	scanf("%d",&T);

	while(T--){
		int n;
		scanf("%d",&n);

		char a[100001]; // can also be written as char a[501];
		char b[100001];
		scanf("%s",a);
		scanf("%s",b);

		int hori = 0;
		int ver = 0;
		int up =0;
		int down =0;
		int i;

		for(i=0;i<n;i++){

			if(a[i] == '.' && b[i] == '.'){

				// do nothing


			}
			else if(a[i] == '*' && b[i] == '.'){
				if( up ==1){
					ver++;
					up =1;
					down =0;
				}
				if( down ==1){
					hori =1;
					up =1;
					down =1;
				}
				up =1;
			}
			else if(a[i] == '.' && b[i] == '*'){
				if( down ==1){
					ver++;
					down =1;
					up =0;
				}
				if( up ==1){
					hori =1;
					up =1;
					down =1;
				}
				down =1;
			}
			else if(a[i] == '*' && b[i] == '*'){
				hori =1;
				if( up == 1 || down == 1){
					ver++;
				}
				up =1;
				down =1;

			}
		}

		int final;
		final = hori + ver;
		printf("%d\n",final);

	}
	return 0;
}
