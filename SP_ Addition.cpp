#include<stdio.h>
#include <stdlib.h>
#define MAX 10
int main()
{
int mat1[MAX][MAX],mat2[MAX][MAX];
int sp1[MAX][MAX],sp2[MAX][MAX];
int sp3[MAX][3],res;
int i,j,r,c,k;
printf("Enter the dimension of the matrix>>");
scanf("%d %d",&r,&c);
printf("************\n");
printf("Enter the elements of the matrix\n");
for(i=0;i<r;i++)
for(j=0;j<c;j++)
{
printf("\n\nEnter the element [%d][%d]>>",i,j);
scanf("%d",&mat1[i][j]);
}
printf("Elements of the matix (which contains maximum number of 0's:\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",mat1[i][j]);
printf("\n");
}
//*/Logic for representation of Sparse Matrix in (k+1)X3 form/
k=1;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
if(mat1[i][j]!=0)
{
sp1[k][0]=i;
sp1[k][1]=j;
sp1[k][2]=mat1[i][j];
k++;
}
sp1[0][0]=r;
sp1[0][1]=c;
sp1[0][2]=k-1;
///Display the matrix/
printf("Elements of the sparse matix:\n");
for(i=0;i<=sp1[0][2];i++)
{
for(j=0;j<3;j++)
printf("%d\t",sp1[i][j]);
printf("\n");
}
printf("************\n");
printf("Enter the elements of the matrix\n");
for(i=0;i<r;i++)
for(j=0;j<c;j++)
{
printf("\n\nEnter the element [%d][%d]>>",i,j);
scanf("%d",&mat2[i][j]);
}
printf("Elements of the matix (which contains maximum number of 0's:\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",mat2[i][j]);
printf("\n");
}
///Logic for representation of Sparse Matrix in (k+1)X3 form/
k=1;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
if(mat2[i][j]!=0)
{
sp2[k][0]=i;
sp2[k][1]=j;
sp2[k][2]=mat2[i][j];
k++;
}
sp2[0][0]=r;
sp2[0][1]=c;
sp2[0][2]=k-1;
///Display the matrix/
printf("Elements of the sparse matix:\n");
for(i=0;i<=sp2[0][2];i++)
{
for(j=0;j<3;j++)
printf("%d\t",sp2[i][j]);
printf("\n");
}
//sparse_Add(int sp1[MAX][3],int sp2[MAX][3])
{
if(sp1[0][0]!=sp2[0][0] || sp1[0][1]!=sp2[0][1])
printf("\a\aMatrix addition is impossible.\n");
else
{
i=1;j=1;k=1;int m=sp1[0][2];int n=sp2[0][2];
while(i<=m && j<=n)
{
if(sp1[i][0]==sp2[j][0] && sp1[i][1]==sp2[j][1])
{
res=sp1[i][2]+sp2[j][2];
if(res!=0)
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=res;
k++;
}
i++;j++;
}
else if(sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;k++;
}
else if(sp1[i][0]==sp2[j][0] && sp1[i][1]>sp2[j][1])
{
sp3[k][0]=sp2[j][0];
sp3[k][1]=sp2[j][1];
sp3[k][2]=sp2[j][2];
j++;k++;
}
else if(sp1[i][0]<sp2[j][0])
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;k++;
}
else
{
sp3[k][0]=sp2[j][0];
sp3[k][1]=sp2[j][1];
sp3[k][2]=sp2[j][2];
j++;k++;
}
}
while(i<=m)
{
sp3[k][0]=sp1[i][0];
sp3[k][1]=sp1[i][1];
sp3[k][2]=sp1[i][2];
i++;k++;
}
while(j<=n)
{
sp3[k][0]=sp2[j][0];
sp3[k][1]=sp2[j][1];
sp3[k][2]=sp2[j][2];
j++;k++;
}
sp3[0][0]=sp1[0][0];
sp3[0][1]=sp2[0][1];
sp3[0][2]=k-1;
}
printf("Elements of the resultant sparse matix:\n");
for(i=0;i<k;i++)
{
for(j=0;j<3;j++)
printf("%d\t",sp3[i][j]);
printf("\n");
}}}