template<class T>
class Matrix {
    // for homogeneous matrices
};

Matrix<int> m1(1000, 1000); // a 1000 by 1000 matrix
Matrix<int> m2(1000, 1000); // ditto

// ...
Matrix<int> m3 = m1 + m2;   // add m1 and m2