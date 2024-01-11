#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void replace(char *str,char *pat,char *rep){
	int i,j,k=0,l,found=0;
	char ans[200];
	for(i=0;str[i]!='\0';i++){
		for(j=0;pat[j]!='\0';j++){
			if(str[i+j]!=pat[j]){	
			break;
		}
		}
		if(pat[j]=='\0'){
			found=1;
			for(l=0;rep[l]!='\0';l++){
			ans[k++]=rep[l];
		}
		i=i+j-1;
	}
	else
	{
		ans[k++]=str[i];
	}
	}
	ans[k]='\0';
	if(found==0)
	printf("Pattern not found\n");
	else
	printf("The resultant string is %s\n",ans);
}
int main(){
	char str[100],pat[20],rep[20];
	printf("Enter the string\n");
	gets(str);
	printf("Enter the pat\n");
	gets(pat);
	printf("Enter the repl\n");
	gets(rep);
	replace(str,pat,rep);
}