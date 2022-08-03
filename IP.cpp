#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int o1,o2,o3,o4,c=0;
	char*p1,*p2,*p3,*p4;
	char ip[20];
	printf("\nEnter IP Address ::");
	scanf("%s",ip);
	for(int i=0;ip[i]!='\0';i++)
	{
		if(ip[i]=='.')
		{ c++;}
	}
	if(c!=3)
	{ printf("ERROR-Invalid IP Address!\n");
	exit(0);}
	p1=strtok(ip,".");
	o1=atoi(p1);
	p2=strtok(NULL,".");
	o2=atoi(p2);
	p3=strtok(NULL,".");
	o3=atoi(p3);	
	p4=strtok(NULL,".");
	o4=atoi(p4);
	if((o1>=0 && o1<=255 )&&(o2>=0 && o2<=255)&&(o3>=0 && o3<=255)&&(o4>=0 && o4<=255))
	{
		if(o1>=0 && o1 <=127)
		{
		int k=pow(2,24);
		printf("\nClass::A\nSubnet mask::255.0.0.0\nStarting IP ::0.0.0.0\nEnd IP::127.255.255.255\nNumber of host::%d\nBoardcast add::%d.%d.255.255\nNetwork ID::%d.%d.0.0\nHost ID::%d.%d\n",k,o1,o2,o1,o2,o3,o4);
		}
		else if(o1>=128 && o1 <=191)
		{
		int k=pow(2,16);
		printf("\nClass::B\nSubnet mask::255.255.0.0\nStarting IP ::128.0.0.0\nEnd IP::191.255.255.255\nNumber of host::%d\nBoardcast add::%d.%d.255.255\nNetwork ID::%d.%d.0.0\nHost ID::%d.%d\n",k,o1,o2,o1,o2,o3,o4);
		}
		else if(o1>=192 && o1 <=223)
		{
		int k=pow(2,8);
		printf("\nClass::C\nSubnet mask::255.255.255.0\nStarting IP ::192.0.0.0\nEnd IP::223.255.255.255\nNumber of host::%d\nBoardcast add::%d.%d.255.255\nNetwork ID::%d.%d.0.0\nHost ID::%d.%d\n",k,o1,o2,o1,o2,o3,o4);
		}
		else if(o1>=224 && o1 <=239)
		{
		int k=0;
		printf("\nClass::D\nSubnet mask::NOT DEFIND\nStarting IP ::224.0.0.0\nEnd IP::239.255.255.255\nNumber of host::%d\nBoardcast add::%d.%d.255.255\nNetwork ID::%d.%d.0.0\nhost id::%d.%d",k,o1,o2,o1,o2,o3,o4);
		}
		else if(o1>=240 && o1 <=255)
		{
		int k=0;
		printf("\nClass::E\nSubnet mask::NOT DEFINED\nStarting IP ::240.0.0.0\nEnd IP::255.255.255.255\nNumber of host::%d\nBoardcast add::%d.%d.255.255\nNetwork ID::%d.%d.0.0\nhost id::%d.%d",k,o1,o2,o1,o2,o3,o4);
		}
		}
		else
		{
		printf("\tERROR-Invalid IP Address!\n");
		exit(0);
		}
		return 0;
		}