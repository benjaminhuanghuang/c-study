#include <string.h>
#include <stdio.h>
 
int main () {
   char str[80] = "This is - www.google.com - website";
   const char s[2] = "-";
   char *token;
   
   /* 获取第一个子字符串 */
   token = strtok(str, s);
   
   /* 继续获取其他的子字符串 */
   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);       // use NULL 
   }
   printf("\n%s\n",str);
   return(0);
}