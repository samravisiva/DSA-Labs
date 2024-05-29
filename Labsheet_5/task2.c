#include <stdio.h>
#include <time.h>

#include <stdio.h>
// recursive insertion sort
void insertionSortR(int *arr, int n)
{
    if (n <= 1) return;
    insertionSortR(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
// iterative insertion sort
void insertionSortI(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int last = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
    }
}

int main(void)
{
    // Reads the numbers stored in numbers1000.txt and stores them into an integer array
    FILE *fp = fopen("numbers1000.txt", "r");
    int numbers[1000];
    int i = 0;
    while (fscanf(fp, "%d", &numbers[i]) != EOF)
    {
        i++;
    }
    fclose(fp);

    // Perform some operation on the numbers
    // ...

    // Example operation: Print the numbers stored in the array
    for (int i = 0; i < 1000; i++)
    {
        printf("%d ", numbers[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    // Measure time taken by recursive function
    start = clock();
    insertionSortR(numbers, 1000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by recursive function: %f seconds\n", cpu_time_used);

    // Measure time taken by iterative function
    start = clock();
    insertionSortI(numbers, 1000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by iterative function: %f seconds\n", cpu_time_used);

    return 0;
}


