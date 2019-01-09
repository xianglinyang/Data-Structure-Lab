#include<iostream>
#include<string>
#include<stack>
using namespace std;

template <class Type > struct BinNode {
    BinNode(){lchild=NULL;rchild=NULL;}
   Type data;
   BinNode <Type > *lchild,*rchild;
};

void s_preorder(BinNode <char> *t){
    stack <BinNode <char> *> s;
    while(t!=NULL){
        cout<<t->data<<endl;
        if( t->rchild != NULL) s.push(t->rchild);
        if( t->lchild != NULL) t=t->lchild;
        else if(s.empty()) break;
        else {
            t=s.top();
			s.pop();
        }
    }
}

void CreateBinTree(istream &in, BinNode <char> *&BT){
    char GenList[100];
    in.getline(GenList,100);
    stack<BinNode<char> *> s;
    if(65<=GenList[0]<=90)  BT->data=GenList[0];
    else cout<<"error input 1"<<endl;
    s.push(BT);
    int i=1;
    while(GenList[i]!='#'){
        if(GenList[i]== '(' )    i++;
        else if( GenList[i] == ',' )  {
                if(GenList[i-1]== '(' || GenList[i-1]== ')' ) i++;
                   else {
                        s.pop();    i++;
                   }
        }
        else if( GenList[i] == ')' )  {
                s.pop();
                i++;
        }
        else if(65<=GenList[i]<=90){
                BinNode<char> *p=s.top();
                BinNode<char> *node=new BinNode<char>;
                if( GenList[i-1] == '(' ) {
                    p->lchild=node;
                    node->data=GenList[i];
                    s.push(node);
                    i++;
                }
                else if( GenList[i-1] == ',' ) {
                    p->rchild=node;
                    node->data=GenList[i];
                    s.push(node);
                    i++;
                }
                else cout<<"error input 2"<<endl;
        }
    }
}

int main(){
    BinNode<char> *BT=new BinNode<char>;
    CreateBinTree(cin,BT);
    s_preorder( BT );
    return 0;
}
