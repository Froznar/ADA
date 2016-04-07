#include <iostream>
#include <vector>
using namespace std;



void insert_sort(vector<int> li)
{

    int key=0,i=0;
    for(int j=1;j<li.size();j++)
    {
        key=li[j];
        i=j-1;
        while(i>-1 and li[i]>key)
        {
            li[i+1]=li[i];
            i=i-1;
        }
        li[i+1]=key;
    }



    for(int w=0;w<li.size();w++)
    {
        cout<<li[w]<<"-";
    }
}
int main()
{
    vector<int> li;
    int a,tam,val;
    cout<<"size";
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
    insert_sort(li);
    
}
