//Divakar Mer
// CPE-523
// Insertion Sort

#include <iostream>
#include<fstream>

using namespace std;

void Insertion_Sort(int arr[], int n) //insertion sort function
{
    if (n <= 1)
        return;

    Insertion_Sort( arr, n-1 );

    int end = arr[n-1];
    int j = n-2;

    while (j >= 0 && arr[j] > end)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = end;
}

void Array(int arr[], int n) //Array printing function
{
    cout<<"After sorting\n";
    for (int i=0; i < n; i++)
        cout << arr[i] <<" ";
}

int main(int argc, char* argv[])  //main function
{
    int arr[11];
    string line;
    int n = sizeof(arr)/sizeof(arr[0]);
    ifstream file;
    file.open(argv[1]);
    //file.open("C:\\Users\\aashu\\CLionProjects\\insertion_sort\\insert.dat");
    if(file.is_open())
    {
         //temp=atoi(line.c_str());
        //int arr[temp];
        while(!file.eof())
        {
            getline(file, line);
            cout<<line;
            cout<<"\nBefore sorting\n";
            for(int i = 0; i < n; i++) {
                file >> arr[i];
                cout << " "<<arr[i];
            }cout<<endl;
        }
        file.close();

    }

    Insertion_Sort(arr, n);
    Array(arr, n);

    return 0;
}