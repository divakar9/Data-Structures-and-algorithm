#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int  L[1000][1000];
int subproblem(int i, int j);

int lcs( string X, string Y, int n, int m )
{
    int i;
    int j;
    for (i = 0; i <= m; i++)
        for ( j = 0; j <= n; j++)
            L[i][j] = -1;
    return subproblem(0, 0);
}
int subproblem(int i, int j)
{
    string X;
    string Y;
if (L[i][j] < 0)
{
if (X[i] == '\0' || Y[j] == '\0')
L[i][j] = 0;
else if (X[i] == Y[j])
    L[i][j] = 1 + subproblem(i+1, j+1);
else
    L[i][j] = max(subproblem(i+1, j), subproblem(i, j+1));
}
return L[i][j];
}

/* Driver program to test above function */
int main(int argc, char *argv[])
{
    int m,n;
    ifstream file_A;
    file_A.open(argv[1]);
    string M;
    if(file_A.is_open())
    {
        while(!file_A.eof())
        {
            getline(file_A, M);
        }
        cout<<M;
        file_A.close();

    }

    ifstream file_B;
    file_B.open(argv[2]);
    //file_B.open("C:\\Users\\aashu\\CLionProjects\\untitled2\\b.txt");
    string N;
    if(file_B.is_open())
    {
        while(!file_B.eof())
        {
            getline(file_B, N);
        }
        cout<<"\n"<<N;

        file_B.close();

    }
    m = M.length();
    n = N.length();
    cout<<"\nLength of LCS is:  "<<lcs(M, N, m, n);

    return 0;
}