#include <stdio.h>

int mdc(int a, int b)
{
    return (b == 0) ? a : mdc(b, a % b);
}

int pitagorica(int a, int b, int c)
{
    if (a > b) { int temp = a; a = b; b = temp; }
    if (b > c) { int temp = b; b = c; c = temp; }
    if (a > b) { int temp = a; a = b; b = temp; }

    return a * a + b * b == c * c;
}

int primitiva(int a, int b, int c)
{
    return mdc(a, mdc(b, c)) == 1;
}

int main()
{
    int a, b, c;

    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        printf("tripla");

        if (pitagorica(a, b, c))
        {
            printf(" pitagorica");

            if (primitiva(a, b, c))
                printf(" primitiva");
        }
        printf("\n");
    }

    return 0;
}
