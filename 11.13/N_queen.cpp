// N_queue.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<iostream>
#include<time.h>

using namespace std;

class N_queen_solver{
private:
	time_t start,stop; // time to start and stop
	int *board; // keep record of current board using an array, all elements will be updated in a new placement
	int check(int); // check whether the queen placement is legal or not
	void traceBack(int); // solve the n-queen problem recursively
	void showBoard(void); // print the board

public:
	int N; // queen number
	long long count; // total placement number
	long long time_elapsed;
	N_queen_solver(int n){ //constructor
		if(n<1 || n>20){
			cout<<"n is illegal!"<<endl;
			throw ;
		}
		N=n; 
		count=0; 
		board=(int *)malloc(sizeof(int)*n); // one placement(column) per row
	} 
	void solve(void); // entrance method
	void details(void);
};

void N_queen_solver::traceBack(int r){
    if(r>=N){ // a feasible palcement is obtained
        showBoard(); // show the board
        count++;
    }else{
        for(int c=0;c<N;c++){
            board[r]=c; // place a queen in (r,c) of the board
            if(check(r)) 
				traceBack(r+1); // solve recursively
        }
    }
}

int N_queen_solver::check(int r){
    for(int pr=0;pr<r;pr++){ // check previous rows
        if(board[r]==board[pr] || abs(r-pr)==abs(board[r]-board[pr]))
            return 0;
    }
    return 1;
}

void N_queen_solver::showBoard(void){
    cout<<"placement:"<<(count+1)<<endl;
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
			if(col==board[row]) 
				cout<<"1"<<" "; // place the queen here
            else 
				cout<<"0"<<" ";
        }
        cout<<endl;
    }
	cout<<endl;
}

void N_queen_solver::solve(void){
	time(&start); //time to start
    traceBack(0); // from the first row
	time(&stop); //time to stop
	time_elapsed = (stop-start);
}

void N_queen_solver::details(void){
	cout<<"Queen number is: "<<N<<endl;
	cout<<"Total placement number is: "<<count<<endl;
	cout<<time_elapsed<<"s elapsed."<<endl;
	cout<<endl;
}


int main(){

	int n;
    cout<<"please input the queen number n (1<=n<=20):";
	cin>>n;
	
	N_queen_solver solver(n);
	solver.solve();
	solver.details();

	return 0;
}

