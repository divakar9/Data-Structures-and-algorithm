//Divakar Mer
// CPE-593
// Homework-5

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class Node{
public:
    Node* next[26];
    bool isword;

};
class Trie{
    Node root;
public:
    Trie(){
        for( int i = 0;i < 26;i++)
            root.next[i]=nullptr;
    }
    void insert(const string& word){
        Node* p = &root;
        for(int i = 0; i < word.length();i++){
            if(p->next[word[i]-'a']==nullptr){
                p->next[word[i]-'a']=new Node();
            }
            p = p->next[word[i]-'a'];
        }
        p->isword = true;

    }

    bool contain(const string& word){
        Node* p = &root;
        for(int i = 0;i < word.length();i++)
        {
            if(p->next[word[i]-'a']==nullptr)
                return false;
            p=p->next[word[i]-'a'];
        }
        return p->isword;
    }
    bool prefix(const string& word){
        Node* p = &root;
        for(int i = 0;i < word.length();i++)
        {
            if(p->next[word[i]-'a']==nullptr)
                return false;
            p=p->next[word[i]-'a'];
        }
        return true;
    }



};

int main(int argc, char *argv[])
{   ifstream text;
    //text.open("C:\\Users\\aashu\\CLionProjects\\trie\\dict.txt");
    text.open("dict.txt");
    if(!text)
        cout<<"failed"<<endl;
    string word;
    Trie t1;
    while(!text.eof()){
        text>>word;
        t1.insert(word);

    }

    ifstream infile;
    //infile.open("C:\\Users\\aashu\\CLionProjects\\trie\\HW-5.txt");
    infile.open("HW-5.txt");
    string inword;
    while(infile.peek()!=EOF){
        infile>>inword;
        if(inword.length()!=0){
            if(t1.contain(inword))
            { cout<<inword<<" can be found"<<endl;}
            else {
                cout<<inword<<" can not be found"<<endl;
            }
            if(t1.prefix(inword))
            { cout<<"The prefix "<<inword<<" can be found"<<endl;}
            else {
                cout<<"The prefix "<<inword<<" can not be found"<<endl;
            }}


    }

}
