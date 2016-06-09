#include "graph.h"
void print_vector(vector<int> A)
{
    for(int w=0;w<A.size();w++)
    {
        cout<<A[w]<<"-";
    }
    cout<<endl;
}
void print_V(vector<vector<int> > B)
{
    for(int w=0;w<B.size();w++)
    {
        print_vector(B[w]);
    }
}
int main()
{
    int tam,peso,a,b,t;
    cin>>tam;
    graph A(tam);

    while(t!=0)
    {
        cin>>a;
        cin>>b;
        cout<<"ingrese peso"<<endl;
        cin>>peso;
        A.add_arista(a,b,peso);
        cout<<"continuar 1:si 0:no"<<endl;
        cin>>t;
    }
    print_V(A.m_matrix);

    return 0;
}
