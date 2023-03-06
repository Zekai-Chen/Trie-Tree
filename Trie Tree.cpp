#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Node{
public:
    Node* Next_Letter[26];   //All strings only contain lowercase letters.
                             //Only 26 lowercase letters
    int count;               //To count the prefix number
    //Initialize
    Node(){
        memset(Next_Letter,0,sizeof(Node*)*26);
        count = 0;
    }
};
 
class Trie{
private:
    Node *Root;
public:
    Trie(){Root = new Node();}
    
    void String_Storage(string Word){

        if (Word.size()==0)
            return;

        Node* Letter = Root;

        int Letter_Index = 0;

        for(int i=0;i<Word.size();i++)
        {
            Letter_Index = int(Word[i]) - 97;    //Ascii number of 'a' is 97
            if(Letter->Next_Letter[Letter_Index] == nullptr)    //nullptr==The constant value of the null pointer
                Letter->Next_Letter[Letter_Index] = new Node(); //Then create new node in the correspoding index 

            Letter = Letter->Next_Letter[Letter_Index];         //Go to the sub-tree 
            Letter->count++;                                    //And add the prefix number
        }
    }

    int Prefix_Count(string Word){ //Actually, similar to Storage part

        if (Word.size()==0)
            return 0;

        Node* Letter = Root;

        int Letter_Index = 0;
        
        for(int i=0;i<Word.size();i++)
        {
            Letter_Index = int(Word[i]) - 97;
            if(Letter->Next_Letter[Letter_Index] == nullptr) //If we meet the the null pointer
                return 0;          // No word use the word as the prefix

            Letter = Letter->Next_Letter[Letter_Index];  //Go to the subtree
        }
        return Letter->count;  //return the counted prefix number
    }
};
 
int main(int argc,char *argv[]){
    Trie Trie_Tree;
    int n;            //According to Constraints n<=10^6 for all ten cases
                      //The first line is an integer n. The number of the strings
    scanf("%d",&n);  //Then int is enough for the n
    string temp;
    for (int i=0;i<n;i++){                //Each of the next n lines contains a string, respectively.
        cin>>temp;                        //The (i + 1)th line of input is si.
        Trie_Tree.String_Storage(temp);
    }

    int q;                                //The (n + 2)th line of input is an integer q.
    scanf("%d",&q); 

    int TEMP;
    for (int i=0;i<q;i++){                //Each of the next q lines contains a string, respectively.
        cin>>temp;                        //The (n + 2 + i)th line of input is ti.
        TEMP = Trie_Tree.Prefix_Count(temp);
        cout<<TEMP<<endl;
    }
    
    return 0;
}
