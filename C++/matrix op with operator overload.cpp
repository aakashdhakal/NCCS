#include<iostream>
using namespace std;
class matrix{
	int mat[50][50];
	int row,col;
	public:
		matrix(){
		}
		matrix(int r, int c){
			row=r;
			col=c;
		}
		void read(){
 			cout<<"Enter the contents of matrix:";
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){

					cin>>mat[i][j];
										cout<<"\t\t\t";
				}
			}
			cout<<endl;
		}
		void show(){
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					cout<<mat[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		matrix operator+(matrix& m2){
			matrix m3(row,col);
			for(int i=0;i<row;i++){
				for (int j=0;j<col;j++){
					m3.mat[i][j]=mat[i][j]+m2.mat[i][j];
				}
			}
			return m3;
		}
		matrix operator*(matrix& m2){
			matrix m3(row,m2.col);
			for(int i=0;i<row;i++){
					for (int j=0;j<m2.col;j++){
					m3.mat[i][j]=0;
					for (int k=0;k<col;k++){
						m3.mat[i][j]+=mat[i][k]*m2.mat[k][j];
					}
				}
 
			}
			return m3;
		}
	};
	int main(){
		matrix m1(2,2), m2(2,2),m3;
		matrix m4=m1*m2;
		m1.read();
		m2.read();
		m3 = m1 + m2;
		cout<<"Addition"<<endl;
		m3.show();
		m3 = m1 * m2;
		cout<<"Multiplication"<<endl;
		m3.show();
		return 0;
 
	}