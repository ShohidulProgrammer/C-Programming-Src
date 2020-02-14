// Josephus problem using Recursion to finding save position.
#include <stdio.h>

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    {
        /* The position returned by josephus(n - 1, k) is adjusted because the
        recursive call josephus(n - 1, k) considers the original position
        k%n + 1 as position 1 */

        return  (josephus(n - 1, k) + k-1) % n + 1;
    }
}

int main()
{
    int n,k=2;

    while(1)
    {
        printf("\nEnter the Total Number of People: ");
        scanf(" %d",&n);

        printf("The Josephus Position is: %d", josephus(n, k));
    }
    return 0;
}
