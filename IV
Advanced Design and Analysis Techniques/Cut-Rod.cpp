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


int CUT_ROD(vector<rasmus> A, int n)
{
    if(n==0) {return 0;}
    int q=-1;
    for(int i=0;i<n;i++)
    {
        q=max(q, A[i]+CUT_ROD(A,n-i-1));
    }
    return q;

}

int Memoized_cut_rod_aux(vector<rasmus> A, int n,vector<rasmus> &r)
{
    int q;
    if(r[n]>=0){return r[n];}
    if(n==0){q=0;}
    else
    {
        q=-1;
        for(int i=0;i<n;i++)
        {
            q=max(q, A[i]+Memoized_cut_rod_aux(A,n-i-1,r));
        }
    }
    r[n]=q;
    return q;
}
int Memoized_cut_rod(vector<rasmus> A, int n)
{
    vector<rasmus> r;

    for(int i=0;i<n+1;i++)
    {
        r.push_back(-1);
    }
    return Memoized_cut_rod_aux(A,n,r);
}


int Bottom_to_Up_cut_rod(vector<rasmus> A, int n)
{
    vector<rasmus> p;
    p.push_back(0);
    for(int i=0;i<A.size();i++)
    {
        p.push_back(A[i]);
    }

    vector<rasmus> r;
    for(int i=0;i<n+1;i++)
    {
        r.push_back(0);
    }

    int q;
    for(int j=1;j<=n;j++)
    {
        q=-1;
        for(int i=1;i<=j;i++)
        {
            q=max(q,p[i]+r[j-i]);
        }
        r[j]=q;
    }

    return r[n];
}




int main()
{
    rasmus a[] = {1,2,3,4,5,6,7,8,9,10};
    rasmus b[] = {1,5,8,9,10,17,17,20,24,30};
    vector<rasmus> tam(a, a+sizeof(a)/sizeof(a[0]));
    vector<rasmus> precio(b, b+sizeof(b)/sizeof(b[0]));


    /*vector<rasmus> A;
        vector<rasmus> respest;
        int a,tam,val;
        cout<<"size  --> ";
        cin>>tam;
        for(int a=0;a<tam;a++)
        {
            cin>>val;
            A.push_back(val);
        }
        for(int w=0;w<A.size();w++)
        {
            cout<<A[w]<<"-";
        }
        cout<<endl;*/
    int tampice;
    cout<<"ingrese el tamaño de la pieza"<<endl;
    cin>>tampice;
    cout<<"lista de precios"<<endl;
    print_vector(precio);

    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Recursive top-down implementation"<<endl;

    struct timespec start, finish;
    double tiempo;
    clock_gettime(CLOCK_MONOTONIC, &start);

    cout<<"RESULTADO:"<<CUT_ROD(precio,tampice)<<endl;

    clock_gettime(CLOCK_MONOTONIC, &finish);
    tiempo = (finish.tv_sec - start.tv_sec);
    tiempo += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    cout<<"Demoro: "<<tiempo<<"s"<<endl;

    cout<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"Memoized Cut Rad"<<endl;

    clock_gettime(CLOCK_MONOTONIC, &start);

    cout<<"RESULTADO:"<<Memoized_cut_rod(precio,tampice)<<endl;

    clock_gettime(CLOCK_MONOTONIC, &finish);
    tiempo = (finish.tv_sec - start.tv_sec);
    tiempo += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    cout<<"Demoro: "<<tiempo<<"s"<<endl;

    cout<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"Bottom-up cut road"<<endl;

    clock_gettime(CLOCK_MONOTONIC, &start);

    cout<<"RESULTADO:"<<Bottom_to_Up_cut_rod(precio,tampice)<<endl;

    clock_gettime(CLOCK_MONOTONIC, &finish);
    tiempo = (finish.tv_sec - start.tv_sec);
    tiempo += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    cout<<"Demoro: "<<tiempo<<"s"<<endl;

    cout<<endl;
    return 0;
}
