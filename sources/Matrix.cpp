#include "Matrix.hpp"
using namespace std;
namespace zich{
    //constructor
    Matrix:: Matrix(const vector<double> &mat, const int row, const int column){
        int size=mat.size();
        if(column<=0||row<=0){
            throw std::out_of_range{"not good"};
        }

        if(size%column!=0||size/column!=row){
            throw std::out_of_range{"not good"};
        }
        this->v=mat;
        this->r=row;
        this->c=column;
    }
    // empty constructor
    Matrix::Matrix(){
        this->r=0;
        this->c=0;
    }
    //delete constructor
    Matrix::~Matrix(){}

    // copy Constructor
    Matrix::Matrix(const Matrix &mat){
        this->v=mat.v;
        this-> r=mat.r;
        this-> c=mat.c;
    }
    //+
    Matrix Matrix::operator+(const Matrix& mat) {
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        vector<double> vec;
        for (unsigned long i = 0; i <(r*c); i++) {
           vec.push_back((this->v[i] + mat.v[i]));
        }
        return  Matrix(vec, this->r, this->c);
    }
    //+=
    Matrix& Matrix::operator+=(const Matrix& mat){
        if (r!=mat.r||c!=mat.c){
            throw std::out_of_range{"not good"};
        }
        for (unsigned long i = 0; i <(mat.r*mat.c); i++) {
            v[i]=v[i]+mat.v[i];

        }
        return *this;
    }

    //+a
    Matrix& Matrix::operator+(){
        return *this;
    }
    //-=
    Matrix& Matrix::operator-=(const Matrix& mat){
        if (r!=mat.r||c!=mat.c){
            throw std::out_of_range{"not good"};
        }
        for (unsigned long i = 0; i <(mat.r*mat.c); i++) {
            v[i]=v[i]-mat.v[i];

        }
        return *this;
    }
    //-
    Matrix Matrix::operator-(const Matrix &mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        vector<double> vec;
        for (unsigned long i = 0; i <(r*c); i++) {
            vec.push_back((this->v[i] - mat.v[i]));
        }
        return  Matrix(vec, this->r, this->c);

    }
//-a
    Matrix Matrix::operator-(){
        vector<double> vec;
        for (unsigned long i = 0; i <r*c ; i++) {
            if(v[i]==0){
                vec.push_back(0);
            } else{
                vec.push_back((v[i]*-1));
            }
        }
        return  Matrix(vec, this->r, this->c);

    }

    //*
    Matrix operator*( double n, Matrix& mat){
        return mat*n;
    }
    //*
    Matrix  Matrix::operator*(const Matrix& mat){
        if (this->c!=mat.r){
            throw std::out_of_range{"not good"};
        }
        vector<double> vec;
        double sum=0;
        unsigned long k = 0;
        unsigned long k1=0;
        while (k1<r) {
            for (unsigned long j = 0; j < mat.c; j++) {
                for (unsigned long i =k, t =j; t < (mat.c*mat.r) && i < ((unsigned long)c + k); t =(t+(unsigned long)mat.c), i++) {
                    double d = (double )(v[i] * mat.v[t]);
                    sum = sum + d;
                }
                vec.push_back(sum);
                sum=0;
            }
            k=k+(unsigned long)c;
            k1++;
        }

        Matrix ans=Matrix(vec,r,mat.c);
        return ans;
    }

    //*=
    Matrix& Matrix::operator*=(const Matrix& mat){
        Matrix matrix=*this*mat;
        v=matrix.v;
        r=matrix.r;
        c=matrix.c;
        return *this;
    }
    //*
    Matrix Matrix::operator*(const double  n){
        vector<double> vec;
        for (unsigned long i = 0; i <r*c ; i++) {
                vec.push_back((v[i]*n));
            }
        return  Matrix(vec, this->r, this->c);
    }
//*=
    Matrix& Matrix::operator*=(const double  n){
        for (unsigned long i = 0; i <(r*c); ++i) {
            this->v[i]= (this->v[i]*n);
        }
        return *this;
    }

//>
    bool Matrix::operator>(const  Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        double sum1=0;
        double sum2=0;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            sum1=(double)(sum1+v[i]);
        }
        for (unsigned long i = 0; i <(mat.r*mat.c) ; ++i) {
            sum2=(double)(sum2+mat.v[i]);
        }

        return (sum1>sum2);
    }

    //>=
    bool Matrix::operator>=(const Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        double sum1=0;
        double sum2=0;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            sum1=(double)(sum1+v[i]);
        }
        for (unsigned long i = 0; i <(mat.r*mat.c) ; ++i) {
            sum2=(double)(sum2+mat.v[i]);
        }
        return (sum1>=sum2);
    }
    //<
    bool Matrix::operator<(const Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        double sum1=0;
        double sum2=0;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            sum1=(double)(sum1+v[i]);
        }
        for (unsigned long i = 0; i <(mat.r*mat.c) ; ++i) {
            sum2=(double)(sum2+mat.v[i]);
        }
        return (sum1<sum2);
    }

    //<=
    bool Matrix::operator<=(const Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        double sum1=0;
        double sum2=0;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            sum1=(double )(sum1+v[i]);
        }
        for (unsigned long i = 0; i <(mat.r*mat.c) ; ++i) {
            sum2=(double)(sum2+mat.v[i]);
        }
        return sum1<=sum2;
    }

    //==
     bool operator==(const Matrix& mat1,const Matrix& mat2 ){
        if (mat2.r!=mat1.r||mat2.c!=mat1.c){throw std::out_of_range{"not good"};}
        bool ans=false;
        for (unsigned long i = 0; i <(mat1.r*mat1.c) ; ++i) {
             if (mat2.v[i] == mat1.v[i]) {
                ans = true;
             } else {
                return false;
             }
         }
         return ans;
       }

   //==
    bool Matrix::operator==(const Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        bool ans=false;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            if (v[i] == mat.v[i]) {
                ans = true;
            } else {
                return false;
            }
        }
        return ans;
    }

    // !=
    bool Matrix::operator!=(const Matrix& mat){
        if (this->r!=mat.r||this->c!=mat.c){throw std::out_of_range{"not good"};}
        bool ans=false;
        for (unsigned long i = 0; i <(r*c) ; ++i) {
            if (v[i] != mat.v[i]) {
                return true;
            }
        }
        return ans;
    }
//++a
    Matrix& Matrix::operator++(){

        for (unsigned long i = 0; i <r*c ; ++i) {
            v[i]=v[i]+1;
        }
        return *this;
    }
    //a++
    Matrix Matrix::operator++(int) { //n++
        Matrix copy=*this;
        for (unsigned long i = 0; i <r*c ; ++i) {
            v[i]=v[i]+1;
        }
        return copy;
    }
    //--a
    Matrix& Matrix::operator--(){
        for (unsigned long i = 0; i <r*c ; ++i) {
            v[i]=v[i]-1;
        }
        return *this;
    }
    //a--
    Matrix Matrix::operator--(int){
        Matrix copy=*this;
        for (unsigned long i = 0; i <r*c ; ++i) {
            v[i]=v[i]-1;
        }
        return copy;
    }
//<<
    std::ostream &operator<<(std::ostream &output, const Matrix &mat) {
        int j = 0;
        int j1 = 0;
        int t = 0;
        int t1 = 0;
        for (unsigned long i = 0; i < mat.c * mat.r; ++i) {
            if (j1 == t) {
                t = t + mat.c;
                output << "[";
            }
            j1++;
            if (t1 < (mat.c - 1)) {
                output << mat.v[i] << " ";
                t1++;

            } else {
                t1 = 0;
                output << mat.v[i];
            }
            j++;
            if (j == mat.c) {
                output << "]";
                j = 0;
                if(i<(mat.r*mat.c)-1){
                    output << "\n";

                }
            }

        }
        return output;
    }
//>>
    std::istream &operator>>(std::istream &input, Matrix &mat) {
        string ans;
        int j=1;
        int row=0;
        int col=0;
        unsigned long i=0;
        vector<double> vec;
        getline(input, ans);
        ans+='\n';
        while (ans[i]!='\n'){
            if (ans[i]!='['){
                throw std::out_of_range{"not good ([)"};
            }
            row++;
            i++;
            col=0;
            string a;
            while (ans[i]!=']'&&ans[i]!='\n') {
                if (ans[i]!=' ') {
                    a += ans[i];
                    i++;
                }
                else{
                    double num = stod(a);
                    vec.push_back(num);
                    i++;
                    col++;
                    a="";
                }
            }
            double num = stod(a);
            vec.push_back(num);
            col++;
            i++;
            if(ans[i]!='\n'){
                if (ans[i]!=','){
                    throw std::out_of_range{"not good (,)"};
                }
                i++;
                if((ans[i]!='\n')&&(ans[i]!=' ')){
                    throw std::out_of_range{"not good ( )"};
                }
                i++;
            }
            j++;
        }

        if (vec.size() != row * col) {
            throw std::out_of_range{"not good"};
        }
        mat.r=row;
        mat.c=col;
        mat.v=vec;
        return input;
    }
};