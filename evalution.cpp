#include<iostream>
#include<time.h> 
#include<windows.h>
#include<psapi.h>
#include<cmath>
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

double mean(clock_t *a,int n){
    double re=0;
    for(int i=0;i<n;i++){
        re = re + (double)a[i]/n;
    }
    return re;
}

double stddev(clock_t *a,int n){
    double re=0;
    double mn = mean(a,n);
    for(int i=0;i<n;i++){
        re+=(a[i]-mn)*(a[i]-mn);
    }
    return sqrt(re/(n-1));
}

int main(){
	const int num = 6;
	clock_t start_time,end_time;
	
	start_time=clock();
    int *mtx[num];
    
    for(int i=0;i<num;i++){
    	mtx[i]=generateMatrix(1024,1024,1,100);
    }
    int * test=generateMatrix(100,100,1,100);
    
    end_time=clock();
    cout<<"alloc time = "<<double(end_time-start_time)<<"ms"<<endl;
    
    clock_t stat[num*num];
    
    ofstream ofstrm("v0.log");
    
    int cnt=0;
    for(int i=0;i<num;i++){
    	for (int j=0;j<num;j++){
    		cout<<"task "<<cnt<<" : "<<"matrix "<<i<<" * matrix "<<j<<endl;
            ofstrm<<"task "<<cnt<<" : "<<"matrix "<<i<<" * matrix "<<j<<endl;
            start_time=clock();
    		MatrixMultiply mm(mtx[i],1024,1024,mtx[j],1024,1024);
            end_time=clock();
            cout<<"run time = "<<double(end_time-start_time)<<"ms"<<endl;
            ofstrm<<"run time = "<<double(end_time-start_time)<<"ms"<<endl;
            stat[cnt++]=(end_time-start_time);
    		// MatrixMultiply mm(test,100,100,test,100,100);
    		// cout<<"hello?"<<endl;
    	}
    	// cout<<"hello?"<<endl;
    } 
    // cout<<"hello?"<<endl;
    
    double avgtime=mean(stat,cnt);
    
    
    cout<<"Include :"<<endl;
    cout<<"avg time: "<<avgtime<<"ms"<<endl;
    cout<<"stddev: "<<stddev(stat,cnt)<<"ms"<<endl;
	ofstrm<<"Include :"<<endl;
    ofstrm<<"avg time: "<<avgtime<<"ms"<<endl;
    ofstrm<<"stddev: "<<stddev(stat,cnt)<<"ms"<<endl;
    return 0;
}
