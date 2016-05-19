#include <iostream>
#include <vector>
using namespace std;


void longest_increasing_subsequence(vector<int> &A, vector<int> &b)
{
    vector<int> p(A.size());
    int u, v;

    b.push_back(0);
    for (int i = 1; i < A.size(); i++)
        {

        if (A[b.back()] < A[i])
                {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }


        for (u = 0, v = b.size()-1; u < v;)
                {
            int c = (u + v) / 2;
            if (A[b[c]] < A[i]) u=c+1; else v=c;
        }


        if (A[i] < A[b[u]])
        {
            if (u > 0) p[i] = b[u-1];
            b[u] = i;
        }
    }

    for (u = b.size(), v = b.back(); u--!=0; v = p[v])
    {
        b[u] = v;
    }
}




int main()
{
    int a[] = { 0, 8, 13, 3, 11, 7, 15};
    vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> lis;
    longest_increasing_subsequence(seq, lis);


    for (int i = 0; i < lis.size(); i++)
        cout<<lis[i];

    return 0;
}
