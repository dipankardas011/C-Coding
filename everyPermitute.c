#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t) = (x) , (x) = (y), (y) = (t))

#define MAX_CHAR 256
void perm(char *list, int i, int n)
{
	int j,temp;
	if(i==n){
		for(j=0;j<=n;j++)
			printf("%c",list[j]);
		printf("\n");
	}else{
		for(j=i;j<=n;j++){
			SWAP(list[i],list[j],temp);
			perm(list,i+1, n);
			SWAP(list[i],list[j],temp);
		}
	}
}
int main(int argc, char const *argv[])
{
	printf("enter the string.. ");
	char str[MAX_CHAR];
	scanf("%s",str);
	perm(str,0,strlen(str)-1);
	remove(argv[0]);
	return 0;
}
