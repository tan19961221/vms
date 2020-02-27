#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 8

int main()
{
    srand(time(NULL));

    int i, a[n], t, w;
    for (i = 0; i < n; i++)

        a[i] = i + 1;

    for (i = n; i >0; i--)

    {
        w = rand() % i +1;

        t = a[i-1];

        a[i-1] = a[w-1];

        a[w-1] = t;
    }
    for (i=0;i<n;i++)
    printf("%d\n", a[i]);
    return 0;
}