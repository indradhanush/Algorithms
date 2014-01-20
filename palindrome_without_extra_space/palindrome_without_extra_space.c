#include <stdio.h>
#include <math.h>


int isPalindrome(int);


int main(){
    int x, ret;
    scanf("%d", &x);
    ret = isPalindrome(x);
    if (ret == 1)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}


int isPalindrome(int x){
    int mod = 10, left, right;
    if (x < 0)
        return 0;
    if (x < 10)
        return 1;
    else{
        while (x/mod >= 10)
            mod *= 10;
        
        while (x >= 10){
            left = x / mod;
            right = x % 10;
            if (left != right)
                return 0;

            x %= mod;
            x /= 10;
            mod /= 100;
        }
        return 1;
        
    }
        


    
}
