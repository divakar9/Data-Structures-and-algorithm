//Divakar Mer
//CPE-553
//Edit Distance

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int min(int a, int b, int c);

int Edit_distance(string M, string N, int m, int n)
{
    int A[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {

            if (i==0)
                A[i][j] = j;  // If first string is empty

            else if (j==0)
                A[i][j] = i; // If second string is empty

            else if (M[i-1] == N[j-1])
                A[i][j] = A[i-1][j-1]; // If last characters are same

            else
                A[i][j] = 1 + min(A[i][j-1],  // Insert
                                   A[i-1][j],  // Remove
                                   A[i-1][j-1]); // Replace
        }
    }

    return A[m][n];
}

int min(int a, int b, int c)
{   if (a < b)
        return a < c ? a : c;
    else
        return b < c ? b : c;
}

// Driver program
int main(int argc, char* argv[])
{
    int m,n;
    ifstream file_A;
    file_A.open(argv[1]);
    //file_A.open("C:\\Users\\aashu\\CLionProjects\\Edit_distance\\c.txt");
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
    //file_B.open("C:\\Users\\aashu\\CLionProjects\\Edit_distance\\d.txt");
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
    cout<<"\nMinimum edits required to convert string_1 to string_2 i.e. the Edit Distance is:  "<<Edit_distance(M, N, m, n);

    return 0;
}