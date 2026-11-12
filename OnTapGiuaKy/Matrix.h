#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>

template<class T>
class Matrix{
private:
    int m_rows;
    int m_cols;
    T** m_data;
public:
    Matrix() : m_rows(0), m_cols(0), m_data(nullptr){}
    Matrix(int r, int c){
        if (r < 0 || c < 0){
            throw std::invalid_argument("rows and cols must be a positive integer");
        }
        if (r == 0 || c == 0) Matrix();
        else{
            this -> m_rows = r;
            this -> m_cols = c;
            this -> m_data = new T*[m_rows];
            for (int i = 0; i < this -> m_rows; i++){
                this -> m_data[i] = new T[m_cols];
            }
            for (int i = 0; i < m_rows; i++){
                for (int j = 0; j < m_cols; j++){
                    this -> m_data[i][j] = 0;
                }
            }
        }
    }
    Matrix(const Matrix<T>&other){
        this -> m_rows = other.m_rows;
        this -> m_cols = other.m_cols;
        this -> m_data = new T*[this -> m_rows];
        for (int i = 0; i < m_rows; i++){
            this -> m_data[i] = new T[m_cols];
        }
        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                this -> m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    ~Matrix(){
        for (int i = 0; i < m_rows; i++){
            delete m_data[i];
        }
        delete []m_data;
    }
public:
    Matrix& operator = (const Matrix<T>& other){
        if (*this != &other){
            for (int i = 0; i < this -> m_rows; i++){
                delete m_data[i];
            }
            delete[]m_data;
            this -> m_rows = other.m_rows;
            this -> m_cols = other.m_cols;
            this -> m_data = new T*[this -> m_rows];
            for (int i = 0; i < this -> m_rows; i++){
                this -> m_data[i] = new T[this -> m_cols];
            }
            for (int i = 0; i < this -> m_rows; i++){
                for (int j = 0; j < this -> m_cols; j++){
                    this -> m_data[i][j] = other.m_data[i][j];
                }
            }
        }
        return *this;
    }

    T findMax() const{
        T res = this -> m_data[0][0];
        for (int i = 0; i < m_rows; i++){
            for (int j = 0; j < m_cols; j++){
                res = std::max(res, m_data[i][j]);
            }
        }
        return res;
    }
    T* operator [](int index){
        if (index < 0 || index >= this -> m_rows){
            throw std::out_of_range("Index is unvalid");
        }
        return m_data[index];
    }

    template<class U>
    friend std::istream &operator >> (std::istream &in, Matrix<U>&m){
        in >> m.m_rows >> m.m_cols;
        for (int i = 0; i < m.m_rows; i++){
            for (int j = 0; j < m.m_cols; j++){
                in >> m.m_data[i][j];
            }
        }
        return in;
    }
    template<class U>
    friend std::ostream &operator << (std::ostream &out, const Matrix<U> &m){
        out << "Row: " << m.m_rows << "\n";
        out << "Col: " << m.m_cols << "\n";
        for (int i = 0; i < m.m_rows; i++){
            for (int j = 0; j < m.m_cols; j++){
                out << m_data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }
};

#endif