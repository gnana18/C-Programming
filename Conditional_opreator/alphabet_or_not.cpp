#include<stdio.h>
main()
{
	char ch,ah;
	
	printf("Enter the alphabet ");
	scanf("%c",&ch);
	
	ah=(ch>'A'&&ch<'Z'||ch>'a'&&ch<'z')?printf("char is alphabet "):printf("char is not alphabet");
}