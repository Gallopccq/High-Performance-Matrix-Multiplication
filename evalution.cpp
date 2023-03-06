#include<iostream>
#include<time.h> 
#include<windows.h>
#include<psapi.h>
#pragma comment(lib,'psapi.lib')

#include"generateMatrix.cpp"
#include"matrix_Multiplication_v0.cpp"

using namespace std;

/*void ShowMemInfo(void){
	HANDLE handle=GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle,&pmc,sizeof(pmc));
	cout<<"memory used: " << pmc.WorkingSetSize/1000<<"K/"<<
	pmc.PeakWorkingSetSize/1000<<"K "<<pmc.PagefileUsage/1000<<"K/"<<
	pmc.PeakPagefileUsage/1000<<"K"<<endl;
	
}*/

int main(){
	const int num = 40;
	clock_t start_time,end_time;
	
	start_time=clock();
    int *mtx[num];
    
    for(int i=0;i<num;i++){
    	mtx[i]=generateMatrix(1024,1024,1,100);
    }
    int * test=generateMatrix(100,100,1,100);
    
    end_time=clock();
    cout<<"alloc time = "<<double(end_time-start_time)<<"ms"<<endl;
    
    start_time=clock();
    
    int cnt=0;
    //for(int i=0;i<1;i++){
    	//for (int j=0;j<1;j++){
    		cout<<"task "<<cnt++<<":"<<endl;
    		MatrixMultiply mm(mtx[6],1024,1024,mtx[6],1024,1024);
    		//MatrixMultiply mm(test,100,100,test,100,100);
    		//cout<<"hello?"<<endl;
    	//}
    	//cout<<"hello?"<<endl;
    //} 
    cout<<"hello?"<<endl;
    end_time=clock();
    cout<<"run time = "<<double(end_time-start_time)<<"ms"<<endl;
	
    return 0;
}
