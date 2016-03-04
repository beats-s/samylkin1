#include <iostream>
#include <iomanip>
#include <math.h>
#include<fstream>

using namespace std;


int main ()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    float s;
    fin>>n;
    float **a=new float* [n];
    for (int i=0; i<n; i++)
        a[i]=new float [n];

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            fin>>a[i][j];
        }

   //приводим матрицу к треугольному виду
    for(int k=0; k<n; k++)
        for(int i=k+1; i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=a[i][j]-a[k][j]*(a[i][k]/a[k][k]);

 /*   for (int l=0; l<n; l++)
    {
        for (int t=0;t<n;t++)
            cout<<a[l][t]<<" ";
        cout<<endl;
    }*/

//выводим столбец свободных членов
cout<<endl;
    float x[n],b[n];
    for(int i=0; i<n;i++)
        {
            fin>>b[i];
            //cout<<b[i]<<" ";
        }
        cout<<endl<<endl;

s=0;
    x[n-1]=b[n-1]/a[n-1][n-1];
    for(int i=n-1;i>=0;i--)
    {

        for (int j=i+1; j<n;j++)
            s=s+a[i][j]*x[j];
        x[i]=(b[i]-s)/a[i][i];
        s=0;

    }




         for (int l=0; l<n; l++)
    {

            fout<<x[l]<<" ";
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;

}

