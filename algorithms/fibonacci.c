#include <stdio.h>


int fibonacciNumbers(int a);
int recursivefib(int a, int b, int f);

void fibloopexample(int i);
void fibrecursionexample(int prev1, int prev2);
int findnth(int n);
int main(){
 //fibonacciNumbers(12);
 //recursivefib(0, 1, 5);
 //fibloopexample(10);
 fibrecursionexample(1, 0);
 printf("\n\n%d\n\n",findnth(19));
 return 0;
}

int recursivefib(int a, int b, int f){
 int fib1;
 int fib2;
 static int c = 0;
 c ++;
 fib2 = a + b;
 fib1 = b;
 if(f - 2 > c){recursivefib(fib1, fib2, f);}else{printf("%d",fib2);return fib2;}
}

int fibonacciNumbers(int a){
 int fn[a];
 int i;
 for(i = 0; i < a-1; i++){
  if(i == 0){fn[i] = 0;} else if(i == 1){fn[i] = 1;}
  else{
   fn[i] = fn[i-1] + fn[i-2];
  }
 }
 int j;
 for(j=0; j<a-1;j++){
  printf("%d, ", fn[j]);
 }
 return 0;
}

void fibloopexample(int i){
 int prev2 = 0;
 int prev1 = 1;
 int newfibo;
 printf("%d\n%d\n", prev2, prev1);
 int j;
 for(j = 0; j<=i; j++){
  newfibo = prev1 + prev2;
  printf("%d\n", newfibo);
  prev2 = prev1;
  prev1 = newfibo;
 }
}

void fibrecursionexample(int prev1, int prev2){
 int newfibo;
 static int count = 0;

 if(count <= 19){
  newfibo = prev1 + prev2;
  printf("%d\n", newfibo);
  prev2 = prev1;
  prev1 = newfibo;
  count += 1;
  fibrecursionexample(prev1, prev2);
 }else{return;}
}
//math formula F(n)= F(n-1) + F(n-2)
//uses 0 based index so 20th n is actully 19th n
//
int findnth(int n){
 if(n <= 1){
  return n;
 }else{
  return findnth(n-1) + findnth(n-2);
 }
}
//something like this boom mind blown exponential
//n == 4 f(4) = (f(3) = ((f2) + ((f1) + (f0)) + (f(1)+ f(0) ) +( f(2) = (f(1) + f(0))
