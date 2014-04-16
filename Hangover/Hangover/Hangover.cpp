#include <stdio.h>
#include <conio.h>
#define N 300  //因为maxNum 范围为0.0-5.2 Hangover(300)>5.2故最多为300

float Hangover(int n)
{
	int i;
	float maxNum=0;
	for(i=2;i<=n+1;i++)
	{
		maxNum +=1.0/i;
	}
	return maxNum;
}
int searchMinN(float maxNum)
{
	float midNum;
	int left = 0;
	int right = N;
	int mid = (left+right)/2;
	while(left<right)
	{
		midNum = Hangover(mid);
		if(midNum >maxNum)
			right = mid-1;
		else if(midNum<maxNum)
			left = mid +1;
		else
			return mid;
		mid = (left+right)/2;
	}
	if(Hangover(mid)-maxNum < 0)
		return mid+1;
	else
		return mid;
}
int main()
{
	//通过二分法查找绝对值最小的
	float testCases[20]={0.0};
	int i=0,j=0;
	scanf("%f",&testCases[i++]);
	while(testCases[i-1]!=0.00)
	{
		scanf("%f",&testCases[i++]);
	}
	i--;
	//输出
	while(j<i)
	{
		printf("%d card(s)\n",searchMinN(testCases[j++]));
	}
  	//printf("%d card(s)\n",searchMinN(0.04));
	getch();
}
