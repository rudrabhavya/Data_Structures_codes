#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
   char txt[80], pattern[80];
   printf ("Enter the text: ");
   gets(txt);
   printf ("Enter the pattern to be searched :");
   gets(pattern);
   int d=10,q=11;
   int m=strlen (pattern);
   int n=strlen (txt);
   int i,j,k,l;
   int p=0;
   int t=0;
   int h=1;
   for (i=0;i<m-1;i++)
      h = (h * d) % q;
   for (i = 0; i < m; i++){
      p = (d * p + pattern[i]) % q;
      t = (d * t + txt[i]) % q;
   }
   for (i = 0; i <= n-m; i++){
      if (p == t){
         for (j = 0; j < m; j++){
            if (txt[i + j] != pattern[j])
            break;
         }
         if (j == m)
         	printf ("pattern found at index %d ", i);
      }
      if (i < n-m){
         t = (d * (t - txt[i] * h) + txt[i + m]) % q;
         if (t < 0)
            t = (t + q);
      }
   }
   return 0;
}
