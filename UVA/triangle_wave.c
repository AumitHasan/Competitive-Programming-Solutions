#include <stdio.h>

int main()
{
    int lenth, height, a, i, j, k, test;
    scanf("%d", &test);
        for(a=1; a<=test; a++)
        {
            scanf(" %d %d", &height, &lenth);
            {
                for(i=1; i<=lenth; i++)
                {
                    for(j=1; j<height; j++)
                    {
                        for(k=1; k<=j; k++)
                            printf("%d", j);
                        printf("\n");
                    }
                    for(k=height-1; j>=1; j--)
                    {
                        for(k=1; k<=j; k++)
                            printf("%d", j);
                        printf("\n");
                    }
                    if(i!=lenth)
                      printf("\n");
                }
                if(a!=test)
                  printf("\n");
            }
        }
}
