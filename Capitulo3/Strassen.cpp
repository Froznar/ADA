#include <iostream>
#include<vector>

using namespace std;
typedef int rasmus;
typedef vector< vector<rasmus> > matrix;

void llenado_matriz(matrix &Matriz)
{
  int m,n;
  cout<<"Ingrese Tamaños  m x n"<<endl;
  cout<<"m: ";
  cin>>m;
  cout<<"n: ";
  cin>>n;
  for(int i=0;i<m;i++)
  {
      vector<rasmus> nuevo;
      rasmus x;
      for(int j=0;j<n;j++)
        {
          cin>>x;
          nuevo.push_back(x);
        }
      Matriz.push_back(nuevo);
  }

}

void print_matriz(matrix Matriz)
{
  for(int i=0;i<Matriz.size();i++)
  {
      for(int j=0;j<Matriz[0].size();j++)
        {
          cout<<Matriz[i][j]<<" ";
        }
      cout<<endl;
  }
}

void matrix_dar_tam(matrix &A, int tam)
{
  A.resize(tam);
  for(int i=0;i<tam;i++)
    {
      A[i].resize(tam);
    }
}

matrix matrix_sum(matrix A, matrix B)
{
  matrix Result;
  for(int i=0;i<A.size();i++)
  {
      vector<rasmus> nuevo;
      for(int j=0;j<A[0].size();j++)
        {
          nuevo.push_back(A[i][j]+B[i][j]);
        }
      Result.push_back(nuevo);
  }
  return Result;
}
matrix matrix_rest(matrix A, matrix B)
{
  matrix Result;
  for(int i=0;i<A.size();i++)
  {
      vector<rasmus> nuevo;
      for(int j=0;j<A[0].size();j++)
        {
          nuevo.push_back(A[i][j]-B[i][j]);
        }
      Result.push_back(nuevo);
  }
  return Result;
}

matrix Strassen(matrix A, matrix B, int tam)
{
  matrix Resultado;
  matrix_dar_tam(Resultado,A.size());
  if(tam==1)
    {
      Resultado[0][0]=A[0][0]*B[0][0];
      return Resultado;
    }
  else
    {
      int new_tam=tam/2;
      matrix a11,a12,a21,a22;
      matrix b11,b12,b21,b22;
      matrix c11,c12,c21,c22;
      matrix p1,p2,p3,p4,p5,p6,p7;

      matrix_dar_tam(a11,new_tam);
      matrix_dar_tam(a12,new_tam);
      matrix_dar_tam(a21,new_tam);
      matrix_dar_tam(a22,new_tam);
      matrix_dar_tam(b11,new_tam);
      matrix_dar_tam(b12,new_tam);
      matrix_dar_tam(b21,new_tam);
      matrix_dar_tam(b22,new_tam);
      matrix_dar_tam(c11,new_tam);
      matrix_dar_tam(c12,new_tam);
      matrix_dar_tam(c21,new_tam);
      matrix_dar_tam(c22,new_tam);
      matrix_dar_tam(p1,new_tam);
      matrix_dar_tam(p2,new_tam);
      matrix_dar_tam(p3,new_tam);
      matrix_dar_tam(p4,new_tam);
      matrix_dar_tam(p5,new_tam);
      matrix_dar_tam(p6,new_tam);
      matrix_dar_tam(p7,new_tam);

      matrix resA,resB;
      matrix_dar_tam(resA,new_tam);
      matrix_dar_tam(resB,new_tam);

      for (int i = 0; i < new_tam; i++)
      {
        for (int j = 0; j < new_tam; j++)
        {
          a11[i][j] = A[i][j];
          a12[i][j] = A[i][j + new_tam];
          a21[i][j] = A[i + new_tam][j];
          a22[i][j] = A[i + new_tam][j + new_tam];

          b11[i][j] = B[i][j];
          b12[i][j] = B[i][j + new_tam];
          b21[i][j] = B[i + new_tam][j];
          b22[i][j] = B[i + new_tam][j + new_tam];
        }
      }

      resA=matrix_sum(a11, a22);
      resB=matrix_sum(b11, b22);
      p1=Strassen(resA, resB, new_tam);

      resA=matrix_sum(a21, a22);
      p2=Strassen(resA, b11, new_tam);

      resB=matrix_rest(b12, b22);
      p3=Strassen(a11, resB, new_tam);

      resB=matrix_rest(b21, b11);
      p4=Strassen(a22, resB, new_tam);

      resA=matrix_sum(a11, a12);
      p5=Strassen(resA, b22, new_tam);

      resA=matrix_rest(a21, a11);
      resB=matrix_sum(b11, b12);
      p6=Strassen(resA, resB, new_tam);

      resA=matrix_rest(a12, a22);
      resB=matrix_sum(b21, b22);
      p7=Strassen(resA, resB, new_tam);

      c12=matrix_sum(p3,p5);
      c21=matrix_sum(p2,p4);

      resA=matrix_sum(p1,p4);
      resB=matrix_sum(resA,p7);
      c11=matrix_rest(resA,p5);

      resA=matrix_sum(p1,p3);
      resB=matrix_sum(resA,p6);
      c22=matrix_rest(resA,p2);

      for (int i = 0; i < new_tam ; i++)
      {
        for (int j = 0 ; j < new_tam ; j++)
          {
            Resultado[i][j] = c11[i][j];
            Resultado[i][j + new_tam] = c12[i][j];
            Resultado[i + new_tam][j] = c21[i][j];
            Resultado[i + new_tam][j + new_tam] = c22[i][j];
          }
      }
      return Resultado;
    }
}

int main()
{


  matrix A,B,C;
  llenado_matriz(A);
  llenado_matriz(B);
  C=Strassen(A,B,A.size());
  print_matriz(C);
  

  return 0;
}
