#include<stdio.h>
int main() {
	int n;
	printf("Enter the terms you want:\n");
	scanf("%d", &n);
	for(int i = 1; i <= (2*n)-1; i++){
			for(int j = 1; j <= (2*n)-1; j++){
				if(i == 1|| i == n || j == 1|| j == n){
						printf("%d ", n);}
					else {printf("  ");}
					}
				printf("\n");
			} 
}