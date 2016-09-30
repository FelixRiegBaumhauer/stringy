#include <stdio.h>
#include <stdlib.h>

//Fxns that are in this file:
//
//strlen
//strcpy/strncpy (choose one)
//strcat/strncat (choose one)
//strcmp
//strchr

//Plan for strlen
//Interate through, have a counter, at every byte add 1 to count
//Once you find the null expection, ie 0 or '' return count
int mystrlen(char * arr){
  int i = 0;
  while(*arr){
    i++;
    arr+=1;
  }
  return i;
}

int main(){
  
  char a [10]; //means char * arr = "fsdnf"
  a[0]='b';  
  a[1]='i';
  a[2]='g';
  a[3]=' ';
  a[4]='r';
  a[5]='e';
  a[6]='d';
  a[7]=0;
  
  int ans1 = mystrlen(a);

  printf("length of str is %d\n", ans1);
  
  return 0;
}
