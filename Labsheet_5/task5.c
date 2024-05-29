#include <stdio.h>
#include <sys/time.h>

// Function to add two matrices row by row
void add(int *a, int *b, int *c, int n) 
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i * n + j] = a[i * n + j] + b[i * n + j];
    }
  }
}

// Function to add two matrices column by column
void add2(int *a, int *b, int *c, int n) 
{
  int i, j;
  for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
      c[i * n + j] = a[i * n + j] + b[i * n + j];
    }
  }
}

// Driver code to run the above methods on sample matrices of size 100 and measure time
int main() 
{
    int n = 200;
    int a[n][n], b[n][n], c[n][n];
    int i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            a[i][j] = i + j;
            b[i][j] = i - j;
        }
    }
    struct timeval start, end;
    gettimeofday(&start, NULL);
    add((int *)a, (int *)b, (int *)c, n);
    gettimeofday(&end, NULL);
    printf("Time taken by row by row addition: %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

    gettimeofday(&start, NULL);
    add2((int *)a, (int *)b, (int *)c, n);
    gettimeofday(&end, NULL);
    printf("Time taken by column by column addition: %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
    return 0;
}