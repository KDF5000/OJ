#include <stdio.h>
#include <conio.h>
#include <string.h>
//A+B
/*
#define N 10

long double power(long double num,long double n)
{
	int i=0;
	long double sum=1;
	for(;i<n;i++)
	{
		sum *=num;
	}
	return sum;
}
void main()
{
	int a=0,b=0;
	while(scanf("%d %d",&a,&b) != EOF)
	{
		printf("%d\n",a+b);
	}
}*/

//求高精度幂

int multi(int a[],int b[],int c[],int aLen,int bLen)
{
	int i,j;
	for(i=0;i<aLen;i++)
	{
		for(j=0;j<bLen;j++)
		{
			c[i+j] +=a[i]*b[j];
			if(c[i+j] > 9)
			{
				c[i+j+1] +=  c[i+j]/10;
				c[i+j] %=10;
			}
		}
	}
	return aLen + bLen;
}

int main()
{
	char numStr[150]={0}; //字符串存储数字
	int n;         //指数
	int a[150]={0};
	int b[150]={0};
	int c[150]={0}; //存放结果
	char temp;
	int floatLen;
	int i,j,zeroFlag,aLen,bLen,cLen,numLen;
	while(scanf("%s%d",numStr,&n)==2)
	{
		zeroFlag = 1;
		for(i=0;i<strlen(numStr);i++)
		{
			if(numStr[i]!=0 && numStr[i]!='.')
			{
				zeroFlag = 0;
			}
		}
		if(zeroFlag == 1)
		{
			printf("0\n");
		}
		else if(n==0)
		{
			printf("1\n");
		}
		else
		{
			//去掉小数点
			numLen = strlen(numStr);
			floatLen = 0;
			i=0;
			while(i<numLen)
			{
				if(numStr[i] == '.')
				{
					floatLen = numLen - i - 1;
					for(;i<numLen-1;i++)
						numStr[i] = numStr[i+1];
					numStr[i] = '\0';
					numLen--;
					break;
				}
				i++;
			}
			//反转
			for(i=0;i<numLen/2;i++)
			{
				numStr[i] = numStr[i] ^ numStr[numLen-i-1];
				numStr[numLen-i-1] = numStr[i] ^ numStr[numLen-i-1];
				numStr[i] = numStr[i] ^ numStr[numLen-i-1];
			}
			//换成int型
			for(i=0;i<numLen;i++)
			{
				a[i]= numStr[i] - '0';
				b[i] = a[i];
			}
			aLen = numLen;
			bLen = numLen;
			//做乘法
			for(i=1;i<n;i++)
			{
				cLen = multi(a,b,c,aLen,bLen);
				aLen = cLen;
				for(j=0;j<cLen;j++)
				{
					a[j]=c[j];
					c[j] = 0;
				}
			}
			//输出
			floatLen *=n;//小数部分位数
			j=aLen-1;
			//去掉前导0 
			while(a[j]==0 && j>=floatLen)
				j--;
			for(i=j;i>=floatLen;i--)
				printf("%d",a[i]);
			//去掉后置0
			if(floatLen > 0)
			{
				j=0;
				while(a[j]==0 && j<floatLen)
					j++;
				if(i>j)
					printf(".");
				for(;i>=j;i--)
					printf("%d",a[i]);		
			}
			printf("\n");
		}

		
	}
	return 0;
}