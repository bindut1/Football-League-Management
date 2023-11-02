#include <bits/stdc++.h>
using namespace std;

void push_val(int a[], int n)
{
    int tmp = a[1];
    for (int i = 1; i < n; i++)
    {
        if (i < n - 1)
        {
            a[i] = a[i + 1];
        }
        else
        {
            a[i] = tmp;
        }
    }
}
void Doi_Chan(int a[], int size)
{
    for (int i = 1; i <= size - 1; i++)
    {
        cout << "Vong " << i << ":" << endl;
        int j = 0;
        if (a[0] == 0)
            j = 1;
        for (j; j < size / 2; j++)
        {
            cout << "Doi " << a[j] << " - "
                 << "Doi " << a[size - 1 - j] << endl;
        }
        cout << endl;
        push_val(a, size);
    }
}
void Doi_Le(int a[], int size)
{
    int b[size + 1];
    for (int i = size - 1; i >= 0; i--)
    {
        b[i + 1] = a[i];
    }
    b[0] = 0;
    Doi_Chan(b, size + 1);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(a) / sizeof(int);
    if (size % 2 == 0)
    {
        for (int i = 1; i <= size - 1; i++)
        {
            cout << "Vong " << i << ":" << endl;
            for (int i = 0; i < size / 2; i++)
            {
                cout << "Doi " << a[i] << " - "
                     << "Doi " << a[size - 1 - i] << endl;
                this_thread::sleep_for(chrono::milliseconds(100));
            }
            cout << endl;
            push_val(a, size);
        }
    }
    else
    {
        Doi_Le(a, size);
    }
}
