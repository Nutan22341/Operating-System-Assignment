#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = vfork();

    if (pid < 0)
    {
        printf("Fork failed");
        return (1);
    }
    else if (pid != 0)
    {
        int num = 4;
        int factorial = 1;
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("Child: Factorial of 4 is %d\n", factorial);
    }
    else
    {
        int n = 16;
        int first = 0, second = 1, next;

        printf("Parent: Fibonacci Series up to %d: ", n);
        printf("%d, %d, ", first, second);

        for (int i = 2; i < n; i++)
        {
            next = first + second;
            printf("%d, ", next);
            first = second;
            second = next;
        }
        printf("\n");

        printf("Parent: Child is waiting for parent proccess to get completed\n");

    }
}
