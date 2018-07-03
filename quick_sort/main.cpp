//Divakar Mer
// CPE-523
// Quick Sort

#include <iostream>
#include <fstream>

using namespace std;

void print(int *a, int n) //print the sorted array
{
    cout << "After sorting\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void swap(int i,int j, int *a){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void quick_sort(int *a, int l, int r){  //quick sorting the array
    int min = (l+r)/2;
    //cout<<"QS:"<<l<<","<<r<<"\n";

    int i = l;
    int j = r;
    int pivot = a[min];

    while(l<j || i<r)
    {
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;

        if(i<=j){
            swap(i,j,a);
            i++;
            j--;
        }
        else{
            if(l<j)
                quick_sort(a, l, j);
            if(i<r)
                quick_sort(a,i,r);
            return;
        }
    }
}


int main(int argc, char* argv[])  //main function
{
    int arr[1000];
    string line;
    int n = sizeof(arr)/sizeof(arr[0]);
    ifstream file;
    file.open(argv[1]);
    //file.open("C:\\Users\\aashu\\CLionProjects\\quick_sort\\quick_sort.dat");
    if(file.is_open())
    {
        //temp=atoi(line.c_str());
        //int arr[temp];
        while(!file.eof())
        {
            getline(file,line);
            cout<< line<<"\n";
            //cout<<"\nBefore sorting\n";
            for(int i = 0; i < n; i++) {
                file >> arr[i];
                cout << " "<<arr[i];
            }cout<<endl;
        }
        file.close();

    }

    quick_sort(arr, 0, n-1);
    print(arr,n);
    return 0;
}