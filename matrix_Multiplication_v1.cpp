#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


/*
some thoughts in myself:
to solve the input problem, I spent: 30 min
write multiplyMatrix start at 16:48 end at 17:26   time cost: 38min
it's new int[row*col] !!! not new int(row*col) !!!
I didn't init the matrix!!!
what??? My coding ability is poor;

some thoughts in Algorithm:
most time wasted in memory allocate;
*/


class MatrixMultiply{
	public:
		MatrixMultiply(const char * filepath){
            this->filepath = new char(200);
            strcpy(this->filepath,filepath);
            matrix=matrix_first=matrix_second=NULL;
            //cout<<(this->filepath);
            readMatrix();
            multiplyMatrix();
            printMatrix();
            delete filepath;
        }
        
        MatrixMultiply(int * m1, int r1, int c1, int *m2,int r2,int c2){
        	readMatrix(m1,r1,c1,m2,r2,c2); 
        	multiplyMatrix();
            //cout<<"hello?"<<endl;
        	printMatrix();
            
        }
        
        int index(int i,int j,int col){
            return i*col+j;
        }
        
        void readMatrix(int * m1, int r1, int c1, int *m2,int r2,int c2){
        	matrix_first = m1;
        	row_first=r1;
        	col_first=c1;
        	matrix_second = m2;
        	row_second=r2;
        	col_second=c2;
        }
        
        void readMatrix(){
            ifstream ifstrm(filepath);
            int row,col;
            ifstrm>>row>>col;
            this->row_first=row;
            this->col_first=col;
            matrix_first = new int[row*col];
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    ifstrm>>matrix_first[index(i,j,col)];
                    //cout<<matrix_first[index(i,j,col)]<<" "; 
                }
                //cout<<endl;
            }
            //cout<<"test"<<endl;
            ifstrm>>row>>col;
            this->row_second=row;
            this->col_second=col;
            //cout<<row<<" "<<col<<endl;
            //new int[row*col];
            //cout<<"test "<<"addr: "<<matrix_second<<endl;
            matrix_second = new int[row*col];
            if (!matrix_second) {cout<<"new error."<<endl<<"addr: "<<matrix_second ;return;}
            //cout<<"test "<<"addr: "<<matrix_second<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    ifstrm>>matrix_second[index(i,j,col)];
                    //cout<<matrix_second[index(i,j,col)]<<" "; 
                }
                //cout<<endl;
            }
            //cout<<"test"<<endl;
            ifstrm.close();
            //cout<<"test"<<endl;
        }
        
        void multiplyMatrix(){
            row = row_first;
            col = col_second;
            //matrix = new int[row*col];
            for (int i=0;i<row*col;i++){
            	matrix[i]=0;
            }
            	
            		
            
            cout<<"row: "<<row<<" col: "<<col<<endl;
            cout<<"col_first: "<<col_first<<" row_second: "<<row_second<<endl;
            int cnt=0,N=row*col*col_first,proc=0;
            
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    for(int k=0;k<col_first;k++){
                        matrix[index(i,j,col)]+=
                        matrix_first[index(i,k,col_first)]*
                        matrix_second[index(k,j,col_second)];
                    }
                } 
                if(i/(row/10)>proc){
                    proc++;
                    cout<<proc;
                }
            }
            cout<<endl;
            return;
        }
        
        void printMatrix(){
            
            /*for(int i=0;i<row_first;i++){
                for(int j=0;j<col_first;j++){
                    cout<<matrix_first[index(i,j,col_first)]<<" ";
                }
                cout<<endl;
            }
            for(int i=0;i<row_second;i++){
                for(int j=0;j<col_second;j++){
                    cout<<matrix_second[index(i,j,col_second)]<<" ";
                }
                cout<<endl;
            }*/
            
            /*
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<matrix[index(i,j,col)]<<" ";
                }
                cout<<endl;
            }*/
            
        }
        
        ~MatrixMultiply(){
            //cout<<"hello?"<<endl;
        	//delete matrix;
        	//delete matrix_first;
            //if(matrix_first!=matrix_second)
            //    delete matrix_second;
        	// cout<<"delete success"<<endl;
        }
	
	
	
	private:
        static int * matrix;
        int * matrix_first;
        int * matrix_second;
        int row_first;
        int col_first;
        int row_second;
        int col_second;
		int row;	// row_end
		int col;	// col_end
        char * filepath;
};

int * MatrixMultiply::matrix = new int [1024*1024];

/*
int main(){
	MatrixMultiply mm("dataset.txt");
	return 0;
}*/
