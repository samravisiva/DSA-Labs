#include <stdio.h>
#include <time.h>

// Function to generate the n'th Fibonacci number recursively
int FibR(int n)
{
    if (n <= 1)
        return n;
    return FibR(n-1) + FibR(n-2);
}

// Function to generate the n'th Fibonacci number iteratively
int FibI(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Measure time taken by recursive function
    start = clock();
    int fib_recursive_result = FibR(10);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Fibonacci(10000) = %d\n", fib_recursive_result);
    printf("Time taken by recursive function: %f seconds\n", cpu_time_used);

    // Measure time taken by iterative function
    start = clock();
    int fib_iterative_result = FibI(10);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iterative Fibonacci(10000) = %d\n", fib_iterative_result);
    printf("Time taken by iterative function: %f seconds\n", cpu_time_used);

    return 0;
}