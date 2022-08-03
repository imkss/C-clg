#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}



void Knapsack(int w[],int p[],int n,int m){
     int rows = n+1;
     int col = m+1;

    int table[rows][col];

  
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++)
          {
            table[i][j] = 0;
          }
     }


    for(int i = 1;i<rows;i++)
      {
        for(int j = 1;j<col ;j++ )
          {
            if(j>=w[i-1]){
              table[i][j] = max(table[i-1][(j-w[i-1])]+p[i-1],table[i-1][j]);
            }else {
              table[i][j] = table[i-1][j];
            }
          }
      }
  
  printf("\n");
 
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<col;j++)
        printf("%d ",table[i][j]);

      printf("\n");
    }

  rows-=1;
  col-=1;
  printf("Max Profit is %d -:" ,table[rows][col]);
  printf("\n");
 
  int arr[rows];
  int i=0;
  int k= rows;
   while(col>0)
     {
       if(table[rows][col] == table[rows-1][col])
       {
         rows-=1;
         arr[i] = 0;
         i++;
       }else{
         rows-=1;
         col -=1;
         arr[i] =1;
         i++;
       }
     }

  for(int i=k;i>0;i--)
    {
      printf("%d ",arr[i]);
    }
}





int main(){
    int n,m;
    printf("Enter the number of characters :");
    scanf("%d",&n);
    int w[n];
    int p[n];
    printf("Enter the bag capacity :");
    scanf("%d",&m);
    printf("Enter the weight :");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the Price :");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    Knapsack(w,p,n,m);
}
