
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int AT[] = {0, 1, 2, 3, 5};
    int P[] = {3, 2, 4, 6, 10};
    int n = sizeof(AT) / sizeof(int);
    int BT[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "enter the burst time: ";
        cin >> BT[i];
    }

    int total = 0;
    int p = 0;
    int t = 0;
    int CT[n];
    // copy of arrival time
    int CAT[n];
    for (i = 0; i < n; i++)
    {
        CAT[i] = AT[i];
    }

    while (p != n)
    {

        int min = CAT[0];

        bool b = false;

        // for storing ready queue processes
        int support[n];
        for (i = 0; i < n; i++)
        {
            support[i] = INT_MAX;
        }

        for (i = 1; i < n; i++)
        {
            if (CAT[i] <= total)
            {
                support[i] = i;
                if (CAT[i] < min)
                {
                    min = i;
                }
                for (int j = 0; j < n; j++)
                {
                    if (P[i] < P[support[j]])
                    {
                        min = i;
                    }
                    else
                    {
                        min = support[j];
                    }
                }
            }
        }

        int min_p = min;
        for (i = 0; i < n; i++)
        {
            if (i != min)
            {
                if (CAT[min] == CAT[i])
                {
                    if (P[min] > P[i])
                    {
                        min_p = i;
                    }
                    else
                    {
                        min_p = min;
                    }
                }

                else
                {
                    b = true;
                }
            }
        }

        int temp;
        if (b == false)
        {
            t = BT[min];
            temp = min;
            CAT[min] = INT_MAX;
        }
        else
        {
            t = BT[min_p];
            CAT[min_p] = INT_MAX;
            temp = min_p;
        }

        total += t;
        CT[temp] = total;

        p++;
    }
    int TAT[n], WT[n];

    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
    }
    for (i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - BT[i];
    }
    cout << "AT"
         << "\t\t"
         << "BT"
         << "\t\t"
         << "CT"
         << "\t\t"
         << "TAT"
         << "\t\t"
         << "WT" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (i = 0; i < n; i++)
    {
        cout << AT[i] << "\t\t" << BT[i] << "\t\t" << CT[i] << "\t\t" << TAT[i] << "\t\t" << WT[i];
        cout << endl;
    }
    float avg_TAT, avg_WT, sum1, sum2;
    for (i = 0; i < n; i++)
    {
        sum1 += TAT[i];
    }
    for (i = 0; i < n; i++)
    {
        sum2 += WT[i];
    }

    avg_TAT = sum1 / n;
    avg_WT = sum2 / n;
    cout << "\nAverage turn around time = " << avg_TAT << " ms" << endl;
    cout << "Average waiting time = " << avg_WT << " ms";

    return 0;
}
