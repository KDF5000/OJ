#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
	int testNum;
	int n;//ÿһ��������Ԫ�ظ���
	char str[40]={0};
	int pNum[20]={0};
	int visitStatus[40]={0};//1��ʾ�ѱ�ƥ��
	int i,j;
	int temp,count=0;
	scanf("%d",&testNum);
	while(testNum--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pNum[i]);
		}
		//���������pNum���������ַ���
		j=0;
		memset(str,0,sizeof(str));
		for(i=1;i<=n;i++)
		{
			temp = j;
			for(;j<temp+(pNum[i]-pNum[i-1]);j++)
			{
				str[j] = '(';
			}
			str[j++]=')';
		}
		str[j]='\0';
		
		//���������ַ�������W-sequence
		count = 0;
		memset(visitStatus,0,sizeof(int)*40);
		for(i=0;i< strlen(str);i++)
		{
			if(str[i]==')')
			{
				j=i;
				while(str[j] ==')' || visitStatus[j] == 1)
				{
					if(str[j] == '(')
						count++;
					j--;
					if(j<0)
						break;
				}
				if(str[j] == '(')
					count++;
				visitStatus[j] = 1;
				if(i == strlen(str)-1)
					printf("%d",count);
				else
				    printf("%d ",count);
				count = 0;
			}
		}
	}
	getch();
	return 0;
	
}
/*int main()
{
	int testNum;
	int n[10];//ÿһ��������Ԫ�ظ���
	char str[40]={0};
	int pNum[10][20]={{0}};
	int visitStatus[40]={0};//1��ʾ�ѱ�ƥ��
	int i,j,p;
	int temp,count=0;
	scanf("%d",&testNum);
	for(p=0;p<testNum;p++)
	{
		scanf("%d",&n[p]);
		for(i=1;i<=n[p];i++)
		{
			scanf("%d",&pNum[p][i]);
		}
	}
	for(p=0;p<testNum;p++)
	{
		//���������pNum���������ַ���
		j=0;
		memset(str,0,sizeof(str));
		for(i=1;i<=n[p];i++)
		{
			temp = j;
			for(;j<temp+(pNum[p][i]-pNum[p][i-1]);j++)
			{
				str[j] = '(';
			}
			str[j++]=')';
		}
		str[j]='\0';
		
		//���������ַ�������W-sequence
		count = 0;
		memset(visitStatus,0,sizeof(int)*40);
		for(i=0;i< strlen(str);i++)
		{
			if(str[i]==')')
			{
				j=i;
				while(str[j] ==')' || visitStatus[j] == 1)
				{
					if(str[j] == '(')
						count++;
					j--;
					if(j<0)
						break;
				}
				if(str[j] == '(')
					count++;
				visitStatus[j] = 1;
				printf("%d ",count);
				count = 0;
			}
		}
		memset(str,0,strlen(str));
		printf("\n");
	}
	getch();
	return 0;
}*/