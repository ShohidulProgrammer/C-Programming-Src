#include<stdio.h>

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int n;
		scanf("%d", &n);

		char house[2][n+1];

		scanf("%s", house[0]);
		scanf("%s", house[1]);

		int v_line = 0, build_up = 0, build_down = 0, avail_0 = 0, avail_1 = 0;
		int i;

		for(i = 0; i < n; i++){

			if(house[0][i] == '*' && house[1][i] == '*' && (build_up == 1 || build_down == 1)){

				v_line++;
				avail_0 = 0;
				avail_1 = 0;

				if(build_up == 0)
					build_up++;

				if(build_down == 0)
					build_down++;

				continue;
			}

			if(house[0][i] == '*' && build_up == 1){

				if(avail_1 == 0){

					v_line++;
					avail_0 = 1;
				}

				else
					avail_1 = 0;
			}

			if(house[1][i] == '*' && build_down == 1){

				if(avail_0 == 0){

					v_line++;
					avail_1 = 1;
				}

				else
					avail_0 = 0;
			}

			if(house[0][i] == '*' && build_up == 0){

				build_up++;
				avail_1 = 0;
			}

			if(house[1][i] == '*' && build_down == 0){

				build_down++;
				avail_0 = 0;
			}
		}

		if(build_up == 1 && build_down == 1)
			v_line++;

		printf("%d\n", v_line);
	}

	return 0;
}
Comments
