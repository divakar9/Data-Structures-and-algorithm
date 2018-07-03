//Divakar Mer
// CPE-593
// GrowArray

#include<iostream>
#include<fstream>
#include<string>


using namespace std;

class GrowArray{
    int used;
    int size;
    int *data;
    void grow(){
        int* temp = data;
        size = 2*size + 1;
        data = new int[size];
        for(int i = 0;i < used;i++)
            data[i] = temp[i];
        delete []temp;
    }
public:
    GrowArray():used(0),size(0),data(nullptr){}
    GrowArray(int size):used(0),size(size),data(new int[size]){}
    ~GrowArray(){delete []data;}


    friend ostream& operator <<(ostream& s,const GrowArray& a){
        for( int i = 0;i < a.used; i++)
            s<<a.data[i]<<" ";
        return s;
    }

    void capacity(int newsize){
        if(used > newsize){
            cout<<"cannot accept the size";
        }
        else {
            int * temp = data;
            data = new int[newsize];
            for( int i = 0; i < used; i++ )
                data[i]=temp[i];
            delete[] temp;
        }
    }
    void addEnd(int v){
        if(used >= size )
            grow();
        data[used++]=v;
        used++;

    }

    void addStart(int v){
        if(used >= size)
            grow();
        int* temp = data;
        data = new int[size];
        for(int i = 0;i < used;i++){
            data[i+1] = temp[i];}
        data[0] = v;
        used++;
    }
    void removeStart(){
        used--;
        //size--;
        int *temp=data;
        data=new int[size];
        for(int i = 0; i < used; i++)
            data[i] = temp[i+1];
        delete [] temp;
    }
    void removeEnd(){
        used--;
    }

    void Out_put(){
        for(int i = 0;i <= used;i++)
            cout<<data[i]<<"";
    }
};


int main(int argc, char *argv[])
{
    GrowArray a1;
    a1.addEnd(10);
    a1.addEnd(5);
    a1.addStart(10);
    a1.capacity(10);
    a1.removeStart();
    a1.removeEnd();
    a1.Out_put();
}
