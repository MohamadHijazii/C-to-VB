#include<stdio.h>
#include<string.h>
#include "tools.h"
#include "soundoukouwa.h"

int main(){
char s[200];
int a=2;
sprintf(s,"%d ",a);
strcat(s,"hello world!");
printf("%s\n",s);

return 0;
}
