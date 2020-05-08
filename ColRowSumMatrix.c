
#include <stdio.h>
    void main ()
    {

        int array[10][10];
        int i, j, sum = 0;

        printf("Enter the values of the matrix\n");
        for (i = 0; i < 6; ++i)
        {
            for (j = 0; j < 6; ++j)
            {
                scanf("%d", &array[i][j]);
            }
        }

        for (i = 0; i < 6; ++i)
        {
            for (j = 0; j < 6; ++j)
            {
                sum = sum + array[i][j] ;
            }

            printf("Sum of the %d row is = %d\n", i, sum);
            sum = 0;

        }
        sum = 0;
        for (j = 0; j < 6; ++j)
        {
            for (i = 0; i < 6; ++i)
            {
                sum = sum + array[i][j];
            }

            printf("Sum of the %d column is = %d\n", j, sum);
            sum = 0;

        }

    }
