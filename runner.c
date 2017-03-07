/*
Felix Rieg-Baumhauer, pd 5, 10/3/16
Work 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


char * mystrcpy(char *des, char *src){
  int n = mystrlen(src);
  int pos = 0;
  while(pos < n){//doing the src to new array transfer
    *(des+pos)=src[pos];
    pos+=1;
  }
  des[n]=0;
  return des;
}

/*
Plan for mystrncpy, use n the num of elements we want to copy,
Use a while, going n values into the destination string, switching out the 
appropriate values. The loop breaks if we hit a null, 
*/

char * mystrncpy(char *des, char *src, int n){
  int pos = 0;
  while(pos < n && src[pos] != 0){//doing the src to new array transfer
    *(des+pos)=src[pos];
    pos+=1;
  }
  
  return des;
}

/*
puts src at end of des, returns des, and modifies it
*/
char * mystrcat(char * des, char * src){
  int nS = mystrlen(src);
  int nD = mystrlen(des);
  int i=0;
  for(i=0; i<nS; i++){
    *(des+(nD+i)) = * (src+i);//n+i, as n is size of des
  }
  *(des+(nS+nD)) = 0;//close it 
  return des;
}

/*
strncat
*/
char * mystrncat(char * des, char * src, int n){
  int nD = mystrlen(des);
  int i=0;
  for(i=0; i<n; i++){
    *(des+(nD+i)) = * (src+i);//n+i, as n is size of des
  }
  *(des+(n+nD)) = 0;//close it 
  return des;
}


/*
compares the values in s1 to s2, using a loop,
as soon as one set of the values are not equal, 
we return the difference
*/
int mystrcmp(char *s1, char *s2){
  int n1 = mystrlen(s1);
  int n2 = mystrlen(s2);
  int n = 0;
  if(n1<n2)
    n=n1;
  else
    n=n2;
  
  int i=0;
  for(i=0; i<n; i++){
    int val = s1[i]-s2[i];
    if(val != 0)
      return val;
  }
  if(n1==n2)
    return 0;
  if(n1>n2)
    return 1;
  if(n2<n1)
    return -1;
}

/*
char * strchr(char * s, char c)
Go through, at first accournce return adress
*/
char * mystrchr(char * s, char c){
  int n = mystrlen(s);
  int i=0;
  for(i = 0; i<n; i++){
    if(*(s+i) == c)
      return s+i;
  }
  return s+n;
}


char * mystrstr(char * s1, char * s2){
  int n = mystrlen(s1);
  int h = mystrlen(s2);
  int i=0;
  int j=0;
  for(i = 0; i<n; i++){
    while(*(s1+i+j) == *(s2+j)){
      h-=1;
      if(h == 0)
	return (s1+i);
      j++;
    }
  }
  return s1+n;
}

int main(){
  
  char a [10]; 
  a[0]='b';  
  a[1]='i';
  a[2]='g';
  a[3]=' ';
  a[4]='r';
  a[5]='e';
  a[6]='d';
  a[7]=0;
  
  char b [9]; 
  b[0]='m';  
  b[1]='i';
  b[2]='d';
  b[3]=' ';
  b[4]='b';
  b[5]='l';
  b[6]='u';
  b[7]='e';
  b[8]=0;


  char c [20]; 
  c[0]='s';  
  c[1]='m';
  c[2]='a';
  c[3]='l';
  c[4]='l';
  c[5]=' ';
  c[6]='g';
  c[7]='r';
  c[8]='e';
  c[9]='e';
  c[10]='n';
  c[11]=0;


  char d [2];
  d[0]=0;



  //Testing fxn 1, mystrlen(char * a)-----------------------------------
  int lenA = mystrlen(a);
  int lenB = mystrlen(b);
  int lenD = mystrlen(d);
  printf("----------FXN #1, strlen-------------\n");
  printf("mystrlen of string [%s] is: %d\n", a, mystrlen(a));
  printf("Real version - strlen of string [%s] is: %lu\n", a, strlen(a));
  printf("mystrlen of string [%s] is: %d\n", b, mystrlen(b));
  printf("Real version - strlen of string [%s] is: %lu\n", b, strlen(b));
  printf("mystrlen of string [%s] is: %d\n", d, mystrlen(d));
  printf("Real version - strlen of string [%s] is: %lu\n", d, strlen(d));
  printf("-------------------------------------\n\n");

  //Testing fxn 2, mystrcpy(char * a, char * b)----------------------------------
  printf("----------FXN #2, strcpy-------------\n");
  printf("String a before: [%s]\n", a);
  printf("String b before: [%s]\n", b);
  printf("Returned value of mystrcpy(a, b) is: [%s]\n",mystrcpy(a,b));
  printf("The value of Array a after going through the fxn: [%s]\n", a);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("--------Reseting A+Compare against accepted fxn--------------\n");
  //reseting a//
  a[0]='b';  
  a[1]='i';
  a[2]='g';
  a[3]=' ';
  a[4]='r';
  a[5]='e';
  a[6]='d';
  a[7]=0;
  printf("String a after being reset: [%s]\n", a);
  printf("String b before: [%s]\n", b);
  printf("Returned value of strcpy(a, b) is: [%s]\n",strcpy(a,b));
  printf("The value of Array a after going through the fxn: [%s]\n", a);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("-------------------------------------\n\n");
  
  //Testing fxn 2.1, mystrncpy(char * a, char * b, int n)----------------------------------
  printf("----------FXN #2.1, strncpy-------------\n");

  a[0]='b';  
  a[1]='i';
  a[2]='g';
  a[3]=' ';
  a[4]='r';
  a[5]='e';
  a[6]='d';
  a[7]=0;
  printf("String a after being reset: [%s]\n", a);
  printf("String b before: [%s]\n", b);
  int n = 3;
  printf("value of n = %d\n",n);
  printf("Returned value of mystrncpy(a, b, n) is: [%s]\n",mystrncpy(a,b,n));
  printf("The value of Array a after going through the fxn: [%s]\n", a);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("-------------------------------------\n");

  printf("--------Reseting A+Compare against accepted fxn--------------\n");
  //reseting a//
  a[0]='b';  
  a[1]='i';
  a[2]='g';
  a[3]=' ';
  a[4]='r';
  a[5]='e';
  a[6]='d';
  a[7]=0;
  printf("String a after being reset: [%s]\n", a);
  printf("String b before: [%s]\n", b);
  printf("value of n = %d\n",n);
  printf("Returned value of strncpy(a, b, n) is: [%s]\n",strncpy(a,b,n));
  printf("The value of Array a after going through the fxn: [%s]\n", a);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("-------------------------------------\n\n");
  

  //Testing fxn 3, mystrcat(char * a, char * b)------------------------------
  printf("----------FXN #3, strcat-------------\n");
  printf("String c before: [%s]\n", c);
  printf("String b before: [%s]\n", b);
  printf("Returned value of mystrcat(c, b), is: [%s]\n",mystrcat(c, b));
  printf("The value of Array c after going through the fxn: [%s]\n", c);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("-------------------------------------\n");
  //reseting c
  c[0]='s';  
  c[1]='m';
  c[2]='a';
  c[3]='l';
  c[4]='l';
  c[5]=' ';
  c[6]='g';
  c[7]='r';
  c[8]='e';
  c[9]='e';
  c[10]='n';
  c[11]=0;
  printf("---------Reset C, compare against accepted----------\n");
  printf("String c after being reset: [%s]\n", c);
  printf("String b before: [%s]\n", b);
  printf("Returned value of strcat(b,c), is: [%s]\n",strcat(c,b));
  printf("The value of Array c after going through the fxn: [%s]\n", c);
  printf("The value of Array b after going through the fxn: [%s]\n", b);
  printf("-------------------------------------\n\n");

  //reseting c
  c[0]='s';  
  c[1]='m';
  c[2]='a';
  c[3]='l';
  c[4]='l';
  c[5]=' ';
  c[6]='g';
  c[7]='r';
  c[8]='e';
  c[9]='e';
  c[10]='n';
  c[11]=0;
  
  //Testing fxn 3.1, mystrncat(char * a, char * b, int n)---------------------
  printf("----------FXN #3.1, mystrncat-------------\n");
  printf("String c before: [%s]\n", c);
  printf("String b before: [%s]\n", b);
  printf("The val of n = %d\n", n);
  printf("Returned value of mystrncat(c, b, n), is: [%s]\n",mystrncat(c, b, n));
  printf("The value of Array c after going through the fxn: [%s]\n", c);
  printf("-------------------------------------\n");
  //reseting c
  c[0]='s';  
  c[1]='m';
  c[2]='a';
  c[3]='l';
  c[4]='l';
  c[5]=' ';
  c[6]='g';
  c[7]='r';
  c[8]='e';
  c[9]='e';
  c[10]='n';
  c[11]=0;
  
  //Testing fxn 3.1, strncat(char * a, char * b, int n)---------------------
  printf("----------reset C, compare againts accepted fxn----------\n");
  printf("String c before: [%s]\n", c);
  printf("String b before: [%s]\n", b);
  printf("The val of n = %d\n", n);
  printf("Returned value of strncat(c, b, n), is: [%s]\n",strncat(c, b, n));
  printf("The value of Array c after going through the fxn: [%s]\n", c);
  printf("-------------------------------------\n\n");


  //Testing fxn 4, mystrcmp(char * s1, char * s2)------------------------------
  printf("----------FXN #4, strcmp-------------\n");
  printf("String a before: [%s]\n", a);
  printf("String b before: [%s]\n", b);
  printf("Returned value of mystrcmp(a, b), is: %d\n", mystrcmp(a, b));
  printf("Returned value of strcmp(a, b), is: %d\n", strcmp(a, b));
  printf("Returned value of mystrcmp([%s], [%s]), is: %d\n", "abcd", "abcd", mystrcmp("abcd","abcd"));
    printf("Returned value of strcmp([%s], [%s]), is: %d\n", "abcd", "abcd", strcmp("abcd","abcd"));
    printf("Returned value of mystrcmp([%s], [%s]), is: %d\n", "dcba", "abcd", mystrcmp("dcba","abcd"));
    printf("Returned value of strcmp([%s], [%s]), is: %d\n", "dcba", "abcd", strcmp("dcba","abcd"));
  printf("-------------------------------------\n\n");  
  
  //Testing fxn 5, mystrchr(char * s, char c)------------------------------
  printf("----------FXN #5, strchr-------------\n");
  printf("String a before: [%s]\n", a);
  printf("We are finding  'i'\n");
  char * arr5 = mystrchr(a, 'i');
  //printf("Value of mystrchr(a, 'i'), in adress form is: %d\n", arr5);
  printf("Value of mystrchr(a, 'i'), in string form is: [%s]\n", arr5);
  printf("Value of mystrchr(a, 'i'), in chr form is: %c\n", *arr5);
  printf("-------------------------------------\n");
  printf("String a before: [%s]\n", a);
  printf("We are finding  'q'\n");
  arr5 = mystrchr(a, 'q');
  //printf("Value of mystrchr(a, 'i'), in adress form is: %d\n", arr5);
  printf("Value of mystrchr(a, 'i'), in string form is: [%s]\n", arr5);
  printf("Value of mystrchr(a, 'i'), in chr form is: %c\n", *arr5);
  printf("-------------------------------------\n");
  printf("----------Comparing agaist accepted values-------------\n");
  printf("String a before: [%s]\n", a);
  printf("We are finding  'i'\n");
  arr5 = strchr(a, 'i');
  printf("Value of strchr(a, 'i'), in string form is: [%s]\n", arr5);
  printf("Value of strchr(a, 'i'), in chr form is: %c\n", *arr5);
  printf("-------------------------------------\n");
  printf("String a before: [%s]\n", a);
  printf("We are finding  'q'\n");
  arr5 = strchr(a, 'q');
  printf("Value of strchr(a, 'i'), in string form is: [%s]\n", arr5);
  //cat find the string of null
  //printf("Value of strchr(a, 'i'), in chr form is: %c\n", *arr5);
  printf("-------------------------------------\n\n");

  //Testing fxn 6, mystrstr(char * s1, char * s2)------------------------------
  printf("----------FXN #6,strstr-------------\n");
  printf("String a before: [%s]\n", a);
  char * e = "id";
  printf("We are seraching for [%s]\n",e);
  char * arr6 = mystrstr(a, e);
  printf("Value of mystrchr(a, 'i'), in string form is: [%s]\n", arr6);
  printf("Value of mystrchr(a, 'i'), in chr form is: %c\n", *arr6);
  printf("------------------------------------\n");
  printf("String a before: [%s]\n", a);
  e = " rqsgh";
  printf("We are seraching for [%s]\n",e);
  arr6 = mystrstr(a, e);
  printf("Value of mystrchr(a, 'i'), in string form is: [%s]\n", arr6);
  printf("Value of mystrchr(a, 'i'), in chr form is: %c\n", *arr6);
  printf("---------Compared against accepted fxn------------\n");
  printf("String a before: [%s]\n", a);
  e = "id";
  printf("We are seraching for [%s]\n",e);
  arr6 = strstr(a, e);
  printf("Value of strchr(a, 'i'), in string form is: [%s]\n", arr6);
  printf("Value of strchr(a, 'i'), in chr form is: %c\n", *arr6);
  printf("------------------------------------\n");
  printf("String a before: [%s]\n", a);
  e = " rqsgh";
  printf("We are seraching for [%s]\n",e);
  arr6 = strstr(a, e);
  printf("Value of strchr(a, 'i'), in string form is: [%s]\n", arr6);
  //Will give errorprintf("Value of strchr(a, 'i'), in chr form is: %c\n", *arr6);
  printf("------------------------------------\n");
  return 0;
}
