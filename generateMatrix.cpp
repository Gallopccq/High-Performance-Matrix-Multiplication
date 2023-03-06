/*
Author: gallop
time: 2023.03.04




*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int * generateMatrix(int row,int col, int lo,int hi){
    int * p = new int [row*col];
    srand(time(NULL));
    
    for (int i=0;i<row*col;i++){
        p[i] = rand() % (hi-lo) + lo;
    }
    return p;
}

/*
int main(){
	int *mtx = generateMatrix(5,3,4,90);
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			cout<<mtx[i*3+j]<<" ";
		}
		cout<<endl;
	}
    return 0;
}*/
