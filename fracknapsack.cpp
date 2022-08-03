#include<stdio.h>
int k=0;
void swap(float *a,float *b)
{
	float temp= *a;
	*a=*b;
	*b=temp;
}
void printarray(float arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%f\t",arr[i]);
	}
}
void sort(float w[],float p[],float p_w[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p_w[j]>p_w[i])
			{
				swap(&p_w[i],&p_w[j]);
				swap(&w[i],&w[j]);
				swap(&p[i],&p[j]);
				
			}
		}
	}
}
void GreedyKnapsack(float p[],float w[],float p_w[],float x[],int n,int m)
{
	
	int U=m;
	int i=0;
		while(i<n)
		{
		
	

		if(w[i]>U)
		{
			
			break;
		}
		x[i]=1.0;
		U=U-w[i];
		i++;
		
		
}
	if(i<n)
	{
		x[i]=U/w[i];
		printf("%f",x[i]);
	}
}


void maxprofit(float p[],float x[],int n )
{
	float sum=0;
	for(int i=0;i<n;i++)
	{
	sum=sum +x[i]*p[i];
	}
	printf("maxm profit is %f\n",sum);
}
int main()
{
	int n;
	float m;
	printf("enter the number of items\n");
	scanf("%d",&n);
	printf("enter the inputs\n");
	float  w[n];
	float  p[n];
	for(int i=0;i<n;i++)
	{
		printf("enter the object %d weight\n",i+1);
		scanf("%f",&w[i]);
		printf("enter the ith %d profit \n",i+1);
		scanf("%f",&p[i]);
		
	}
	printf("enter the size of knapsack\n");
	scanf("%f",&m);
	float p_w[n];
	float x[n];
	for(int i=0;i<n;i++)
	{
		x[i]=0.0;
	}
	for(int i=0;i<n;i++)
	{
		p_w[i]=p[i]/w[i];
	}
	sort(w,p,p_w,n);
	GreedyKnapsack(p,w,p_w,x,n,m);
	maxprofit(p,x,n);                   
	return 0;
}
