#include <stdio.h>
int swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
// swap function

int partition(int array[], int l, int h)
{
    int pivot = array[l];
    // pivot choose garna paiyoo, based on circumstances
    int i = l;
    int j = h;
    // i, j starting from the ends.
    do
    {
        do
        {
            i++;
        } while (array[i] <= pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        // limiting haina chalu condition halne ho, i will move to right as long as it doesnot get an element greter than pivot,
        // it will certainly bcz we have kept infinity there.
        if (i < j)
        {
            swap(&array[j], &array[i]);
            // i, j paepachi yadi i<j then swap garne ho.
        }
    } while (i < j);            // taba samma i, j swap garirakhne jaba samma i le j exceed gardaina, chalu condition is till i<j.
    swap(&array[l], &array[j]); // once mathi ko condition fails and do while ends, now swap pivot and jth.
    return j;
}
// partitioning fn

void quicksort(int array[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(array, l, h);
        quicksort(array, l, j);     // partition index paechi left array ma quick sort lagaune, actually j-1 element bacheko cha sort garna but
                                    // jth acts as infinity.
        quicksort(array, j + 1, h); // similarly right ma ni lagaune, here h is itself the infinity as earlier
    }
}

void printarray(int array[])
{
    for (int i = 0; i < 14; i++)
    {
        printf("%d\n", array[i]);
    }
}
// array printing fn ho

int main()
{
    int array[] = {2, 1, 0, 3, 1, 2, 3, 11, 3, 1, 6, 4, 8, 3, __INT32_MAX__};
    int n = (14 + 1);
    // +1 for including the infinity value. yaadi kunai greter than pivot value bhetena bhane, while loop stop garna.
    quicksort(array, 0, 14);
    printarray(array);

    return 0;
}