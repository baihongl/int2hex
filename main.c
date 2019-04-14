#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
 
/**************************/
/*功能：实现int类型十进制数转为十六进制字符串，并转为字节数组   
  时间：2019年4月11日
*/

/**************************/
int main(void) 
{
	int num, m,i;
	char s[] = "\0";
	char bytes[4] ;

	printf ("Enter a number: ");
	scanf ("%d",&num);
 	sprintf(s, "%x", num);//int2hex
	printf ("Hexadecimal number: %sH\n", s);

	printf ("字符0: %c\n", s[0]);
	printf ("字符1: %c\n", s[1]);
	printf ("字符2: %c\n", s[2]);
	printf ("字符3: %c\n", s[3]);
	printf ("字符4: %c\n", s[4]);
	printf ("字符5: %c\n", s[5]);
    
    m = strlen(s);
    char bits[m];
    i= Change(s,bits,m);
    printf ("%s\n",s);
    for(i = 0;i <4;i++)
     {
          bytes[i] = bits[i];
        printf ("%x ",0XFF & bytes[i]);
     }
    printf("\n");
    return 0;
}


//字符chuan转为字节数组
int Change(char s[],char bits[], int m) 
{
    int i,n = 0;
    for(i = m-2; i>=-1; i -= 2) 
    {
        if(s[i] >= 'A'&& s[i]<= 'F')
            bits[n] = s[i] - 'A' + 10;
        else if(s[i] >= 'a'&& s[i]<= 'f')
            bits[n] = s[i] - 'a' + 10;
        else bits[n] = s[i] - '0';
           if(s[i + 1] >= 'A' && s[i + 1] <= 'F')
            bits[n] = (bits[n] << 4) | (s[i + 1] - 'A' + 10);
           else if(s[i+1] >= 'a'&& s[i+1]<= 'f')
            bits[n] = (bits[n] << 4) | (s[i + 1] - 'a' + 10);
           else bits[n] = (bits[n] << 4) | (s[i + 1] - '0');
        ++n;
    }
 
}







/*
char * inttohex(int aa, char bits[])
{
     char s[7] ;
    sprintf(s, "%x", aa);
printf ("Hexadecimal number: %sH\n", s);
int m = strlen(s);
printf ("changdu: %d\n", m);
printf ("字符0: %c\n", s[0]);
printf ("字符1: %c\n", s[1]);
printf ("字符2: %c\n", s[2]);
printf ("字符3: %c\n", s[3]);
printf ("字符4: %c\n", s[4]);
printf ("字符5: %c\n", s[5]);
    int i,n = 0;
    for(i = m-2; i>=-1; i -= 2) 
    {
        if(s[i] >= 'A' && s[i]<= 'F')
            bits[n] = s[i] - 'A' + 10;
        else bits[n] = s[i] - '0';
        if(s[i + 1] >= 'A' && s[i + 1] <= 'F')
            bits[n] = (bits[n] << 4) | (s[i + 1] - 'A' + 10);
        else bits[n] = (bits[n] << 4) | (s[i + 1] - '0');
printf ("bits: %x\n", bits[n]);
        ++n;
    }
    //return (buffer);
}


int main ()
{
  int num;
 
  printf ("Enter a number: ");
  scanf ("%d",&num);
 
   //printf ("changdu: %d\n", m);
//  printf ("Hexadecimal number: %sH\n", hex_str);
   char bytes[4] ;
   char bits[4];
 inttohex (num,bits);
 //   Change(hex_str,bits,m);
    for( int i = 0;i <4;i++)
     {
          bytes[i] = bits[i];
        printf ("%X ",0XFF & bytes[i]);
     }
    printf("\n");
  return 0;
}


*/


