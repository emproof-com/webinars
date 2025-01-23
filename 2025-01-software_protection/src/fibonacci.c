// gcc -O0 -o fibonacci fibonacci.c
#include <stdio.h>
#include <stdlib.h>

unsigned int fib_obfuscated_2(unsigned n) {
    int a, b, s, i;
    int state = (n ^ 5) + 2 * (n & 5) - n - 5; // state = 0

    while (1) {
        switch (state) {
            case 0: 
                a = (n ^ 23) + 2 * (n & 23) - n -  23;
                b = (n ^ 1) + 2 * (n & 1) - n;
                s = (n ^ 1337) + 2 * (n & 1337) - n - 1337;
                i = (n ^ 2) + 2 * (n & 2) - n;
                if (n == 0) {
                    state = (n ^ 3) + 2 * (n & 3) - n; 
                } else {
                    s = b;
                    state = (n ^ 1) + 2 * (n & 1) - n;
                }
                break;

            case 1:
                if (i > n) {
                    state = (n ^ 3) + 2 * (n & 3) - n;
                } else {
                    s = (a ^ b) + 2 * (a & b);
                    a = (a ^ b) + 2 * (a & b) -  a; // a = b
                    b = (a ^ s) + 2 * (a & s) - a;
                    i = (i ^ 1) + 2 * (i & 1);
                    state = (a ^ 1) + 2 * (a & 1) - a;
                }
                break;

            case 3:
                return (n ^ s) + 2 * (n & s) - n;

            default:
                return (n ^ 1234) + 2 * (n & 1234) - n;
        }
    }
}


unsigned int fib_obfuscated_1(unsigned n) {
    int a, b, s, i;
    int state = 0;

    while (1) {
        switch (state) {
            case 0: 
                a = 0;
                b = 1;
                s = 0;
                i = 2;
                if (n == 0) {
                    state = 3; 
                } else {
                    s = b;
                    state = 1; 
                }
                break;

            case 1:
                if (i > n) {
                    state = 3;
                } else {
                    s = a + b;
                    a = b;
                    b = s;
                    i++;
                    state = 1;
                }
                break;

            case 3:
                return s;

            default:
                return 0;
        }
    }
}


unsigned int fib(unsigned n) {
  unsigned a=0;
  unsigned b=1;
  unsigned int s = b;
  unsigned i;

  if (n == 0) {
    return 0;
  }


  for (i=2; i<=n; i++) {
    s=a+b;
    a=b;
    b=s;
  }
  return s;
}

int main (int argc, char** argv) {
  if (argc < 2) {
    return -1;
  }
  
  unsigned int n = atoi(argv[1]);
  
  printf("fib result: %u\n", fib(n));
  printf("fib_obfuscated_1 result: %u\n", fib_obfuscated_1(n));
  printf("fib_obfuscated_2 result: %u\n", fib_obfuscated_2(n));
  
  return 0;
}