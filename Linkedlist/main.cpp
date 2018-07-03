//Divakar Mer
// CPE-553
// Homework - 4b

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Linkedlist
{ class Node{
    public:
        int value;
        Node * next;
        Node * prev;
        Node(const int& v,Node* next, Node* prev):value(v),next(next),prev(prev){ }

    };
    Node* head;
    Node* tail;
public:
    Linkedlist() {
        tail=head = nullptr;
    }
    ~Linkedlist(){
        Node* q;
        for(Node* p = head;p != nullptr;p = q){
            q = p->next;
            delete p;

        }}

    void addStart(const int& v){
        if(head == nullptr){

            head = tail = new Node(v,head,nullptr);
            return ;}
        Node* temp = head;
        head = new Node(v,head,nullptr);
        temp->prev = head;
    }
    void addEnd(const int& v){
        if(head == nullptr){
            head = tail = new Node(v,nullptr,head);
            return;
        }

        tail->next = new Node(v,nullptr,tail);
        tail=tail->next;
    }


    void insert(const int& v,int pos){

        if(head == nullptr)
        {  if(pos == 0){
                head = new Node(v,nullptr,head);
                return;}
            else
            {std::cout<<"Nothing at the position"<<pos;}
        }

        Node* p = head;
        for(int i = 0; i < pos-1; i++){
            p = p -> next;
        }

        if(p->next == nullptr){
            Node* temp = new Node(v,nullptr,p);
            p->next = temp;
        }
        else{
            Node* temp = new Node(v,p->next,p);
            p->next->prev = temp;
            p->next = temp;}
    }
    void removeStart(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            head = nullptr;
            return;
        }
        head = head ->next;
        head ->prev = nullptr;
    }
    void removeEnd(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            head = tail = nullptr;
            return;
        }
        tail = tail->prev;
        tail->next = nullptr;

    }
    void Add_Front(int start, int step,int end){
        for(int i = start;i <= end;i += step)
            addStart(i);
    }
    void Add_Back(int start,int step,int end){
        for(int i = start;i <= end; i += step)
            addEnd(i);
    }
    void Remove_Front(int n){
        for(int i = 0; i < n;i++)
            removeStart();
    }
    void Remove_Back(int n){
        for(int i = 0; i < n;i++)
            removeEnd();
    }

    friend ostream& operator <<(ostream&s, const Linkedlist& l){
        Node* p = l.head;
        for(;p!=nullptr;p=p->next){
            s<<p->value<<" ";
        }
        return s;
    }

    void reverse(){
        Node* temp = head;
        Node* pnext ;
        Node* pprev = nullptr;
        while(temp != nullptr) {
            pnext = temp->next;
            temp->next = pprev;
            pprev = temp;
            temp = pnext;
        }
        head=pprev;

    }

    class Iterator{
        Node* p;
    public:
        Iterator(Node* p):p(p){}
        Iterator(const Linkedlist& list){
            p=list.head;
        }
        bool notEnd()const{
            return p != nullptr;
        }

        void operator ++(){
            p = p ->next;
        }
        void operator --(){
            p = p ->prev;
        }
        int val()const {
            return p ->value;
        }
    };
    Iterator end()const{
        if(head == nullptr){
            return Iterator(nullptr);
        }
        Node* p = head;
        for(;p->next!=nullptr;p = p->next)
            ;
        return Iterator(p);

    }


};
class file{
    int len;
    int start;
    int step;
    int end;
public:
    file(const char*str):len(0),start(0),step(0),end(0){
        int pos = 0;
        if(str[pos]=='\0'){
            len = 2;}
        else
        {for( pos = 0;str[pos]!=' '&&str[pos]!='\0';pos++)
                ;
            len = pos;
            if(str[pos]==' '&&str[pos+1]==' '){
                pos++;}
            if(str[pos]==' '){
                pos++;
                for(;str[pos]!=':'&&str[pos]!='\0';pos++)
                    start = start*10+(str[pos]-'0');
                if(str[pos]==':')
                {
                    pos++;
                    for(;str[pos]!=':';pos++)
                        step = step*10+(str[pos]-'0');
                    pos++;
                    for(;str[pos]!='\0';pos++)
                        end = end*10+(str[pos]-'0');
                }
            }
        }
    }

    int getlen(){
        return len;

    }
    int getstart(){
        return start;
    }
    int getstep(){
        return step;
    }
    int getend(){
        return end;
    }
};
int main(int argc, char* argv[])
{   char a[16];
    Linkedlist a1;
    ifstream file_A;
    file_A.open(argv[1]);
    //ifstream ("HW4b.txt");
    int len;
    do{
        file_A.getline(a,16);
        file f(a);
        len=f.getlen();
        switch(len){
            case 9:
                a1.Add_Front(f.getstart(),f.getstep(),f.getend());
                break;
            case 8:
                a1.Add_Back(f.getstart(),f.getstep(),f.getend());
                break;
            case 6:
                cout<<a1<<endl;
                break;
            case 12:
                a1.Remove_Front(f.getstart());
                break;
            case 11:
                a1.Remove_Back(f.getstart());
                break;
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
        }
    }while(len!=0);

    return 0;
}
