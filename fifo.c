#include <stdio.h>

int main()
{
    int pf = 0, count = 0, rs[25], m[10];
    int n, f, k;
    
    printf("Enter the length of Reference String:\t");
    scanf("%d", &n);
    
    printf("Enter the Reference String:\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }
    
    printf("Enter the number of frames:\t");
    scanf("%d", &f);
    
    for (int i = 0; i < f; i++)
    {
        m[i] = -1;  
    }
    
    printf("\n----FIFO Page Replacement Process----\n");
    
    for (int i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i]) // Page hit
            {
                break;
            }
        }
        
        if (k == f) // Page fault 
        {
            m[count] = rs[i];  
            count = (count + 1) % f;  
            pf++;  
        }
        
       
        for (int j = 0; j < f; j++)
        {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");
        }
        
        if (k == f)
        {
            printf("\tPF No: %d\n", pf);
        }
        else
        {
            printf("\tHIT\n");
        }
    }
    
    printf("\nTotal Page Faults = %d\n", pf);
    printf("\nTotal Page Hits = %d\n", n-pf);
    
    return 0;
}
