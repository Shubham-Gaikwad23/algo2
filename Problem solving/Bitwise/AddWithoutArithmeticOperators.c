#include <stdio.h>

int main()
{
    int t;
    unsigned int n1, n2, pos;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        unsigned short carry, cout, sum;
        scanf("%u%u", &n1, &n2);
        for(i=0, pos=1, carry=0; i<sizeof(int)*8; i++, pos=pos<<1)
        {
            sum = (n1 ^ n2 ^ cin)&pos;  //sum = a xor b xor c
            carry =
        }
    }

    return 0;
}