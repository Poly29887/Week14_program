#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void checkScore(char);
void saveScore();
void minOut();
void arrangeScore();

int score[8],check[8] = { 0,0,0,0,0,0,0 },week = 1,sc;
char vote[8], letter[8] = {'A','B','C','D','E','F','G'};
int main()
{
	int *p_score,n,stop = 0;
	char *p_m,*p_vote,message[10000];
	while(1) 
	{
		scanf("%s", message);
		p_m = message;
		while (*p_m != '\0')
		{
			if (*p_m == '!')
			{
				stop = 1;
				break;
			}
			checkScore(*p_m);
			saveScore();
			p_m++;
		}
		if (stop == 1)
		{
			break;
		}
		minOut();
		
	}
	arrangeScore();
	p_vote = vote;
	p_score = score;
	n = strlen(vote);
	printf("%d\n",n);
	while (*p_vote != '\0')
	{
		printf("%c %d\n",*p_vote,*p_score);
		p_vote++;
		p_score++;
	}
}

void checkScore(char ch)
{
	int x,a;
	x = ch-65;
	if (x>=0&& x<=6)
	{
		if (check[x] != -1)
		{
			check[x] += 1;
		}
		
	}
}
void saveScore()
{
	int a;
	sc = 0;
	for (a = 0; a < 6; a++)
	{
		if (check[a] != -1)
		{
			score[a] = check[a];
			sc++;
		}
	}
}
void minOut() 
{
	int min = check[0],a,c,x,s=1;
	for (a = 1; a < 7; a++)
	{

		if (min > check[a]&& check[a]>=0)
		{
			min = check[a];
			x = a;
		}		
	}
	c = 0;
	for(a = 0; a < 7; a++)
	{
		if (min == check[a])
		{
			c++;
		}
		if (c > 1)
		{
			s = 0;
			break;
		}
	}
	if (s == 1)
	{
		if (min == check[0]) x = 0;
		check[x] = -1;
	}
}
void arrangeScore()
{
	int a, b,temp;
	int *p1, *p2;
	for (a = 0; a < sc ; a++)
	{
		for (b = 0; b < sc; b++)
		{
          if (score[b] < score[b+1])
		{
			temp = score[b+1]; 
			score[b+1] = score[b];
			score[b] = temp;
		}
	    }
		
	}
	for (a = 0; a < sc ; a++)
	{
		for (b = 0; b < 7; b++)
		{
			if (score[a] == check[b])
			{
				vote[a] = letter[b];
				check[b] = 0;
				break;
			}
		}
	}
	
}