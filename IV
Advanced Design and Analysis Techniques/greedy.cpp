#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;
typedef int rasmus;


void print_vector(vector<rasmus> A)
{
    for(int w=0;w<A.size();w++)
    {
        cout<<A[w]<<"-";
    }
    cout<<endl;
}

void ReAS(vector<rasmus> s, vector<rasmus> f, int k, int n,vector<rasmus> &res)
{
    int m=0;

    m=k+1;
    while(m<n and s[m]<f[k])
    {
        m++;
    }
    if(m<n)
    {
        res.push_back(m+1);
        ReAS(s,f,m,n,res);
    }
    else
    {
        return;
    }

}

vector<rasmus> IeAS(vector<rasmus> s, vector<rasmus> f)
{
    vector<rasmus> res;
    res.push_back(1);
    int n,k,a ;
    n=s.size();
    a=0;
    k=1;
    for(int m=2;m<n;m++)
    {
        if(s[m]>=f[k])
        {
            res.push_back(m+1);
            k=m;
        }
    }
    return res;


}
int main()
{

    rasmus a[] = {1,3,0,5,3,5,6,8,8,2,12};
    rasmus b[] = {4,5,6,7,9,9,10,11,12,14,16};
    vector<rasmus> s(a, a+sizeof(a)/sizeof(a[0]));
    vector<rasmus> f(b, b+sizeof(b)/sizeof(b[0]));

    vector<rasmus> res;
    res.push_back(1);
    ReAS(s,f,0,s.size(),res);
    print_vector(res);
    print_vector(IeAS(s,f));
    return 0;
}
