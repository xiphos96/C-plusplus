 // 1-2.cpp
  
 #include <iostream.h>
 
 const int ROW = 3;
 const int COL = 3;

 class  Matrix {
 	int		m_row, m_col;		// 행과 열 
 	double *m_data;				// 행렬 데이타
 
 public:
 	Matrix(int  r=ROW, int  c=COL);
	Matrix(const Matrix  &other);
 	Matrix& operator = (const Matrix  &other);
 	~Matrix() { delete [] m_data; };
 	
 	Matrix operator + (const Matrix  &other) const;
 	
 	friend ostream& operator << (ostream& os, const Matrix& M);
 
 	double& operator () (int i, int j) { return m_data[i*m_col+j]; }
 
	double operator () (int i, int j) const { return m_data[i*m_col+j]; }
 };
 
 // 생성자
 Matrix::Matrix(int r, int c)
 {
 	m_row = r;
 	m_col = c;
 	m_data=new double[r*c];
 }
 
 // 복사 생성자
 Matrix::Matrix(const Matrix  &other)
 {
 	m_row = other.m_row;
	m_col = other.m_col;
 	m_data = new double[m_row*m_col];
 	for(int i=0; i<m_row; i++)
 	for(int j=0; j<m_col; j++)
 	m_data[i*m_col+j] = other.m_data[i*m_col+j];
 }
 
 // 대입 연산자
 Matrix&
 Matrix::operator = (const Matrix &other)
 {
 	if ( this == &other )	return *this;
 	delete [] m_data;
 	m_row = other.m_row;
 	m_col = other.m_col;
 	m_data = new double[m_row*m_col];
 	for (int i=0; i<m_row; i++)
 		for (int j=0; j<m_col; j++)
 			m_data[i*m_col+j] = other.m_data[i*m_col+j];
 	return *this;
 }
 
  // 행렬의 덧셈
 Matrix
 Matrix::operator + (const Matrix& other) const
 {
 	Matrix result;
 
 	for (int i=0; i<m_row; i++)
 		for (int j=0; j<m_col; j++)
 		   result(i,j) = m_data[i*m_col+j] + other.m_data[i*m_col+j];
 	
  	return result;
 }
 
 // 출력 연산자
 ostream& operator << (ostream& os, const Matrix& M)
 {
 	for (int i=0; i<M.m_row; i++)
 	{
 		for (int j=0; j<M.m_col; j++)
 			os << M(i,j) << '\t';
 		os << endl;
	}

 	return os;
}
 
 void main()
 {
     Matrix A, B, C;
 	
 	for (int i=0; i<ROW; i++)
 		for (int j=0; j<COL; j++)
 			B(i,j) = A(i,j) = i+j;
 	C = A + B;
 	cout << C;
}