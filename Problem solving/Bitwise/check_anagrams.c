#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100], res=0;
    printf("Enter string 1 : ");
    scanf("%s",s1);
    printf("Enter string 2 : ");
    scanf("%s",s2);
    
    
    if (strlen(s1)==strlen(s2))
    {
        for(int i=0; s1[i]!='\0'; i++)
        {
            res = res ^ s1[i] ^ s2[i];
        }
        if(res=='\0')
            printf("anagram");
        else
            printf("not anagram");
    }
    else
        printf("not anagram");

    return 0;
}
