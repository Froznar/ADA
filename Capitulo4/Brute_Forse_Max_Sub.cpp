#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long rasmus;

vector<rasmus> Brute_Force_MS(vector<rasmus> A)
{
  rasmus max_sum=A[0];
  rasmus pos1=0,pos2=0;
  int tam=1;
  for(int i=0;i<A.size();i++)
  {
    for(int j=0;j<A.size();j++)
      {
        rasmus new_max=0;
        int k=0;
        while(k<tam and (j+k)<=A.size()-1)
          {
            new_max+=A[j+k];

            k++;
          }
        if(max_sum<new_max)
          {
            max_sum=new_max;
            pos1=j;
            pos2=j+tam-1;
          }
      }
    tam++;
  }
  vector<rasmus> resp;
  resp.push_back(pos1);
  resp.push_back(pos2);
  resp.push_back(max_sum);
  return resp;
}

int main()
{
    vector<rasmus> A;
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
        cout<<A[w]<<" ";
    }
    cout<<endl;

    //respest= FMS(A,0,A.size()-1);
    respest=Brute_Force_MS(A);

    cout<<"Menor"<<respest[0]<<endl;
    cout<<"Mayor"<<respest[1]<<endl;
    cout<<"Suma"<<respest[2]<<endl;

}
