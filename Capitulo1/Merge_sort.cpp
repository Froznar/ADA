#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void Merge(vector<int> &A, int p, int q, int r)
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    vector<int> L,R;
    for(int i=1;i<=n1;i++)
    {
        L.push_back(A[p+i-1]);
    }
    for(int j=1;j<=n2;j++)
    {
        R.push_back(A[q+j]);
    }
    R.push_back(10000);
    L.push_back(10000);
    int i,j;
    i=j=0;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }

}

void Merge_sort(vector<int> &A,int p,int r)
{
    if(p<r)
    {
        int q=floor(p+r)/2;
        Merge_sort(A,p,q);
        Merge_sort(A,q+1,r);
        Merge(A,p,q,r);
    }


}
int main()
{
    vector<int> li;
    int a,tam,val;
    cout<<"size  --> ";
    cin>>tam;
    for(int a=0;a<tam;a++)
    {
        cin>>val;
        li.push_back(val);
    }
    for(int w=0;w<li.size();w++)
    {
        cout<<li[w]<<"-";
    }
    cout<<endl;

    Merge_sort(li,0,li.size()-1);
    for(int w=0;w<li.size();w++)
    {
        cout<<li[w]<<"-";
    }

}
