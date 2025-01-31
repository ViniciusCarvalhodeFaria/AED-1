#include <stdio.h>

int main()
{
    int num1, num2, carry, carry_count;

    while (scanf("%d %d", &num1, &num2))
    {
        if (!num1 && !num2)
            break;

        carry = 0;
        carry_count = 0;
        while (num1 && num2)
        {
            if (num1 % 10 + num2 % 10 + carry > 9)
            {
                carry = 1;
                ++carry_count;
            }
            else
            {
                carry = 0;
            }

            num1 /= 10;
            num2 /= 10;
        }

        while (num1)
        {
            if (num1 % 10 + carry > 9)
            {
                carry = 1;
                ++carry_count;
            }
            else
            {
                carry = 0;
            }

            num1 /= 10;
        }

        while (num2)
        {
            if (num2 % 10 + carry > 9)
            {
                carry = 1;
                ++carry_count;
            }
            else
            {
                carry = 0;
            }

            num2 /= 10;
        }

        if (carry_count == 0)
            printf("No carry operation.\n");
        else if (carry_count == 1)
            printf("%d carry operation.\n", carry_count);
        else
            printf("%d carry operations.\n", carry_count);
    }

    return 0;
}
