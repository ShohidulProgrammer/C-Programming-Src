#include<stdio.h>
#include<stdlib.h>
#include<string>
integer maxLength = 10; // maximum number of bytes in your integer
unsigend short addend1[maxLength]; // byte order will be LSB on the first index position
unsigend short addend2[maxLength]; // to MSB on the highest index position
unsigned short sum[maxLength];     // ditto for the final sum

unsigned integer carry = 0;
string M[100],N[100];


//string someBigIntInStringForm    = "199999999999999999999999999923423412312123123123";
//string anotherBigIntInStringForm = "000000000000000000000022323288423412312123123123";

addend1 = convertStringToUnsignedShortArray(someBigIntInStringForm);
addend2 = convertStringToUnsignedShortArray(anotherBigIntInStringForm);

for(integer idx = 0; idx < maxLength; idx++)
{
    sum[idx] = (addend1[idx] + addend2[idx] + carry) % 256;
    carry    = (addend1[idx] + addend2[idx] + carry) / 256;
}

if(carry <> 0)
{
    // signal that an overflow error has occurred
}
else
{
    // array sum now contains the sum of addend1 and addend2
}

