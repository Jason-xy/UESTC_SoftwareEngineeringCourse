#include<stdio.h>
#include<string.h>
int main(void){
	char input[20]="0", max[20]="A", min[20]="z";
	while (1){
		printf("Enter a word:");
		gets_s(input);
		if (strcmp(input, max) >= 0)strcpy_s(max, input);
		if (strcmp(input, min) <= 0)strcpy_s(min, input);
		if (strlen(input) == 4)break;
	}
	printf("Smallest word:%s\n",min);
	printf("Largest word:%s",max);
}
