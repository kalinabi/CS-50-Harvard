#include<stdio.h>
#include<cs50.h>
/* This programme is designed to check the validity of the
   card whether it is master card or credit card or vissa card by using Luhn's algoritham */

int count;

long long reverseNumber (long long credit)
{
  count = 0;
  long long tmp = 0;
  
  while (credit > 0)
    {
      tmp = tmp * 10;
      tmp = tmp + credit % 10;
      credit = credit / 10;
      count++;

    }
  return tmp;
}
// write code for more corner cases
int numberTotal(int number) {
    int total=0;
    
    while(number>0) {
        total=total+number%10;
        number=number/10;
    }
    
    return total;
}

int getCreditCompany(long long credit){
    long long tmp= reverseNumber (credit);
    
    const int AMEX=tmp%100;
    const int MASTERCARD=tmp%100;
    const int VISA=tmp%10;
    
    if(AMEX==43||AMEX==73)
        return 1;
    else if(MASTERCARD==15||MASTERCARD==25||MASTERCARD==35||MASTERCARD==45||MASTERCARD==55)
        return 2;
    else if(VISA==4)
        return 3;
    else
        return 4;
}

int main(void){
    printf("Number:- ");
    long long credit = GetLongLong();
    
    int company = getCreditCompany(credit);
    
    if(company==4)
        printf("INVALID\n");
    else
        int total=0;
        
        for( int i=1;i<=count;i++)
        {
            int tmp = credit%10;
            credit=credit/10;
            
            if(i%2!=0)
                total=total+tmp;
            else
                total=total+numberTotal(tmp*2);
        }
        
        if(total%10==0)
            switch(company){
                case 1:
                    printf("AMEX\n");
                    break;
                case 2:
                    printf("MASTERCARD\n");
                    break;
                case 3:
                    printf("VISA\n");
                    break;
            }
        
        else
            printf("INVALID\n");
    return 0;        
}

