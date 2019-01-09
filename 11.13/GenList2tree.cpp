#include<iostream>
#include<string>
#include<stack>
#define MAXN 20
using namespace std;

template <class Type > struct BinNode {
    BinNode(){for(int i=0;i<MAXN;i++) child[i]=NULL;}
   Type data;
   BinNode <Type > *child[MAXN];
};

void post_order( BinNode<char> *t){
    int m=MAXN;
    if(t!=NULL){
        for(int i=0;i<m;i++) back_order(t->child[i]);
        cout<<t->data<<endl;
    }
}
void preorder( BinNode<char> *t)  {
    int m = MAXN;
    if(t!=NULL) {
        cout<<t->data<<endl;
        for(int i=0;i<m;i++) preorder(t->child[i]);
    }
}


void CreateTree(istream &in, BinNode <char> *&BT){
    char GenList[100];
    in.getline(GenList,100);
    stack<BinNode<char> *> s;
    if(65<=GenList[0]<=90)  BT->data=GenList[0];
    else cout<<"error input 1"<<endl;
    s.push(BT);
    int i=1;
    while(GenList[i]!='\0'){
        if(GenList[i]== '(' )    i++;
        else if( GenList[i] == ',' ||GenList[i]==')')  {
                        s.pop(); 
						i++;
        }
        else if(65<=GenList[i]<=90){
                BinNode<char> *p=s.top();
                BinNode<char> *node=new BinNode<char>;
                    int j=0;
                    while(p->child[j]!=NULL){
                        j++;
                    }
                    node->data=GenList[i];
                    p->child[j]=node;
                    s.push(node);
                    i++;
                    //preorder(BT);
                    //cout<<endl;
        }
    }
}

int main(){
    cout<<"请输入用广义表表示的树（串的长度不超过20）："<<endl;
    BinNode<char> *BT=new BinNode<char>;
    CreateTree(cin,BT);
    post_order( BT );
    return 0;
}
