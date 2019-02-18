/*
Programer: Yc
Name: Matrix
Time: 2019.2.18
Remark:
1-
Change log:
1-
*/
#include <iostream>

using namespace std;
/*void Matrix_determinant(float **matrix,int m,int n){

}
void Matrix_inverse(float **matrix,int m,int n){

}*/
void Matrix_display(float **matrix,int n,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Matrix_plus(float **matrix1,float **matrix2,int &n1,int &m1,int &n2,int &m2){
    int i,j;
    if(n1==n2&&m1==m2){
        float **matrix3;
        matrix3=new float *[n1];
        for(i=0;i<n1;i++){
            matrix3[i]=new float [m1];
        }
        for(i=0;i<n1;i++)
            for(j=0;j<m1;j++)
                matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
        cout << "Matrix1+Matrix2:" << endl;
        Matrix_display(matrix3,n1,m1);
        delete []matrix3;
    }
    else{
        //Please make sure the sizes of the two matrixs are the same.
        cout << "Plus error!" << endl;
    }
}
void Matrix_multiplication(float **matrix1,float **matrix2,int &n1,int &m1,int &n2,int &m2){
    int i,j,k;
    if(m1==n2){
        float **matrix4;
        matrix4=new float *[n1];
        for(i=0;i<n1;i++){
            matrix4[i]=new float [m2];
        }
        for(i=0;i<n1;i++)
            for(j=0;j<m1;j++)
                matrix4[i][j]=0;   //Every element in the matrix must be 0, otherwise a nan error will occur.
        for(i=0;i<n1;i++){
            for(j=0;j<m2;j++){
                //Culcalate everyone in matrix4
                for(k=0;k<m1;k++){
                    matrix4[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        cout << "Matrix1*Matrix2:" << endl;
        Matrix_display(matrix4,n1,m2);
        delete []matrix4;
    }
    else{
        cout << "Multiplication error!" << endl;
    }
}
int main(){
    int m1,n1,m2,n2,i,j;
    float **matrix1,**matrix2;
    cout << "Please enter the size of Matrix1:";
    cin >> n1 >> m1;
    matrix1=new float *[n1];
    cout << "Please enter Matrix1:" << endl;
    for(i=0;i<n1;i++){
        matrix1[i]=new float [m1];
    }
    for(i=0;i<n1;i++)
        for(j=0;j<m1;j++)
            cin >> matrix1[i][j];
    cout << "Please enter the size of Matrix2:";
    cin >> n2 >> m2;
    matrix2=new float *[n2];
    cout << "Please enter Matrix2:" << endl;
    for(i=0;i<n2;i++){
        matrix2[i]=new float [m2];
    }
    for(i=0;i<n2;i++)
        for(j=0;j<m2;j++)
            cin >> matrix2[i][j];

    Matrix_plus(matrix1,matrix2,n1,m1,n2,m2);
    Matrix_multiplication(matrix1,matrix2,n1,m1,n2,m2);
    delete []matrix1;
    delete []matrix2;
    return 0;
}
