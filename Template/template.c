#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <limits.h>
#define ll long long
#define ull unsigned ll

char inputname[] = "testdata.in";
char outputname[] = "testdata.out";
FILE *output;
FILE *input;

ll max(ll a, ll b);
ll min(ll a, ll b);
ll abso(ll a);
ll power(int a, int b);
int Slen(char x[]);
int Scompare(char x[], char y[]);
void Scopy(char from[], char dest[]);
void openread();
void openwrite();

void mergesort(int arr[], int low, int high);

void solve()
{
    int arr[] = {5, 3, 234, 23941, 13};
    mergesort(arr, 0, 4);
    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main()
{
    int t = 1;
    /* scanf("%d", &t); */
    for (int tc = 1; tc <= t; ++tc)
    {
        /* printf("Case #%d: ", tc); */
        solve();
    }
}

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

ll min(ll a, ll b)
{
    return a > b ? b : a;
}

ll abso(ll a)
{
    return a < 0 ? -a : a;
}

ll power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if ((b & 1) == 0)
    {
        ll res = power(a, b / 2);
        return res * res;
    }

    return power(a, b - 1) * a;
}

int Slen(char x[])
{
    int i;
    for (i = 0; x[i]; ++i)
        ;
    return i;
}

int Scompare(char x[], char y[])
{
    int i = 0, j = 0;
    while (x[i] && y[j])
    {
        if (x[i] > y[j])
            return 1;
        if (x[i] < y[j])
            return -1;

        ++i, ++j;
    }

    if (x[i] && !y[j])
        return 1;
    if (!x[i] && y[j])
        return -1;
    return 0;
}

void Scopy(char from[], char dest[])
{
    int i = 0;
    for (i = 0; from[i]; ++i)
    {
        dest[i] = from[i];
    }
    dest[i] = '\0';
}

void openread()
{
    input = fopen(inputname, "r");
}

void openwrite()
{
    output = fopen(outputname, "w");
}

void mergesort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    int p1 = low, p2 = mid + 1;
    int len = high - low + 1;
    int temp[len];
    int indx = 0;

    while (p1 <= mid && p2 <= high)
    {
        if (arr[p1] < arr[p2])
        {
            temp[indx++] = arr[p1++];
        }
        else
        {
            temp[indx++] = arr[p2++];
        }
    }

    while (p1 <= mid)
    {

        temp[indx++] = arr[p1++];
    }

    while (p2 <= high)
    {
        temp[indx++] = arr[p2++];
    }

    p1 = low;
    for (int i = 0; i < len; ++i)
    {
        arr[p1++] = temp[i];
    }
}
