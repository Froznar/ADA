#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long rasmus;

vector<rasmus> F_M_C_S(vector<rasmus> &A, rasmus low, rasmus mid, rasmus high)
{
  vector<rasmus> Respuesta;
  rasmus left_sum=0-10000000;
  rasmus sum=0;
  rasmus max_left;
  rasmus max_right;

  for(int i=mid;i>=low;i--)
    {
      sum=sum+A[i];
      if(sum> left_sum)
        {
          left_sum=sum;
          max_left=i;
        }
    }
  rasmus right_sum=0-10000000;
  sum=0;
  for(int j=mid+1;j<=high;j++)
    {
      sum=sum+A[j];
      if(sum>right_sum)
        {
          right_sum = sum;
          max_right = j;
        }
    }
  Respuesta.push_back(max_left);
  Respuesta.push_back(max_right);
  Respuesta.push_back(left_sum+right_sum);
  return Respuesta;
}

vector<rasmus> FMS(vector<rasmus> &A, rasmus low , rasmus high)
{
  vector<rasmus> Respuesta;
  vector<rasmus> thigs_left;
  vector<rasmus> thigs_right;
  vector<rasmus> thigs_cross;

  Respuesta.push_back(low);
  Respuesta.push_back(high);
  Respuesta.push_back(A[low]);
  if(high==low)
    {
      return Respuesta;
    }
  else
    {
      rasmus mid=floor((low+high)/2);

      thigs_left=FMS(A,low,mid);

      thigs_right=FMS(A,mid+1,high);

      thigs_cross= F_M_C_S(A,low,mid,high);

      if(thigs_left[2]>=thigs_right[2] and thigs_left[2]>=thigs_cross[2])
        {
          return thigs_left;
        }
      else if(thigs_right[2]>=thigs_left[2] and thigs_right[2]>=thigs_cross[2])
        {
          return thigs_right;
        }
      else
        {
          return thigs_cross;
        }

    }

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
        cout<<A[w]<<"-";
    }
    cout<<endl;

    respest= FMS(A,0,A.size()-1);

    cout<<"Menor"<<respest[0]<<endl;
    cout<<"Mayor"<<respest[1]<<endl;
    cout<<"Suma"<<respest[2]<<endl;

}
