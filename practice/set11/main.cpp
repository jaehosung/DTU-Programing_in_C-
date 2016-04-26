#include<iostream>
using namespace std;

class Tree{
    public:
        Tree();
        void insert(int n);
        int height(void);
        void setFiboVal(void);
        void printPreOrder(void);
        int treeSize(void);
        int treeDepth(void);
        int treeLeafs(void);
    private:
        bool empty;
        int content;
        int fiboVal;
        Tree *left;
        Tree *right;
};

int main(){
    Tree fibo;
    int num;

    cin>>num;
    fibo.insert(num);

    fibo.setFiboVal();
    cout<<"Call tree in pre-order: ";
    fibo.printPreOrder();
    cout<<endl<<"Call tree size: "<<fibo.treeSize()<<endl;
    cout<<"Call tree depth: "<<fibo.treeDepth()<<endl;
    cout<<"Call tree leafs: "<<fibo.treeLeafs()<<endl;

    return 0;
}

Tree::Tree(){
    empty = true;
    fiboVal = 0;
    left = nullptr;
    right = nullptr;
}

void Tree::insert(int n){
    if(empty){
        content = n;
        empty = false;
        left = new Tree;
        right = new Tree;
        if(n>=2){
            left->insert(n-1);
            right->insert(n-2);
        }
    }
}

void Tree::setFiboVal(void){
    if(content==0||content==1){
        fiboVal = 1;
        return;
    }
    if(fiboVal==0&&left!=nullptr&&right!=nullptr){
        left->setFiboVal();
        right->setFiboVal();
        fiboVal = left->fiboVal+right->fiboVal;
    }
}

void Tree::printPreOrder(void){
    if(empty==false)
        cout<<fiboVal<<" ";
    if(left!=nullptr&&right!=nullptr){
        left->printPreOrder();
        right->printPreOrder();
    }
}
int Tree::treeSize(){
    if(empty) return 0;
    return 1 + left->treeSize() + right->treeSize();
}
int Tree::treeDepth(){
    if(empty) return 0;
    return 1+left->treeDepth();
}
int Tree::treeLeafs(){
    if(empty) return 0;
    else if(content==0||content==1) return 1;

    return left->treeLeafs()+right->treeLeafs();
}
