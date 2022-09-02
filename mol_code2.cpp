/***********************************************
设计并实现一个二维平面离散点集的抛物线拟合算法。
令抛物线方程为：y = a*x^2 + b*x + c， 其中系数 a,b,c 均为float类型。
为了算法实现方便，提供Mat类供使用。
输入描述:
二维平面上的离散点集M[m*2]，样点的个数为m，行优先存储，数据之间以空格分隔，即数据的输入序列为：
m
x1 y1...xi yi ... xm yn
输出描述:
输出为抛物线方程的系数a b c, 精确至小数点后2位，printf("%.2f %.2f %.2f", a, b, c)：
a b c
示例1
输入
200
8.0705 232.315 59.2836 12846.6 62.4818 14271.7 52.0783 9910.69 26.3811 2546.97 -51.4325 9701.39 83.208 25322.4 25.2129 2315.84 -26.5116 2579.57 17.4702 1108.25 -1.88251 10.1862 -88.8574 28941.2 -42.0254 6478.65 72.3685 19150.6 5.48503 104.856 93.8992 32570.8 60.8897 13552.9 -1.53912 5.76565 88.3527 28552.9 40.9881 6134.82 25.0208 2281.84 -81.3907 24283.5 92.498 31296.8 84.8789 26350.4 -35.7363 4685.54 -70.6217 18285 -8.16909 243.747 68.4713 17141.9 75.714 20963.6 8.44659 254.934 -96.3087 33996.3 -76.7812 21611.9 -95.0835 33137.2 66.0866 15925.4 69.7402 17783.7 -89.3929 29290.9 -46.9154 8073.02 9.59605 328.303 15.2751 845.788 -30.1829 3343.07 66.6673 16339.3 89.3845 29224.1 -4.59858 75.5808 76.8398 21592.2 53.3681 10408.3 -39.1259 5615.96 93.8196 32198.1 -58.5733 12580.5 8.57752 263.052 -15.7639 911.989 -57.567 12152.1 -24.5472 2211.6 85.8041 26928.4 31.8409 3698.37 -3.94501 54.9084 22.2359 1799.57 -74.0865 20122.2 -9.16676 307.426 37.101 5024.57 49.017 8778.42 34.0657 4234.58 -88.7969 28901.8 70.7332 18294.2 58.9762 12713.6 -24.0494 2095.56 59.7755 13174.5 35.5147 4603.29 -75.6165 20961.5 -73.3819 19741.5 -89.6069 29431.3 77.7193 22089.7 54.8044 10869.6 -92.9339 31656.4 6.59442 153.55 -69.6262 17773.3 -74.2762 20225.4 -89.6009 29427.4 3.08098 30.2678 -94.4867 32722.7 81.4837 24283.1 33.057 3986.97 -97.4517 34807.8 -14.7545 798.83 -57.1018 11956.6 -43.7957 7035.62 57.9771 12286.1 41.4971 6288.4 7.21391 182.554 -29.1964 3141.83 47.6643 8299.94 35.84 4688.19 -37.1873 5073.53 -57.8699 12280.3 -50.943 9517.71 89.2736 29151.6 -52.454 10090.4 -86.5445 27454.7 58.0707 12325.8 -23.1278 1963.3 49.4193 8923.29 7.31316 189.909 77.6236 22035.3 14.8893 803.3 96.5647 34111 52.6293 10121.8 28.1198 2882.58 -34.5166 4371.35 -6.17004 138.091 -20.4145 1529.72 12.4058 555.91 37.8311 5224.66 -34.3588 4331.5 51.1145 9546.81 -67.5867 16747.8 56.887 11827.9 78.0892 22300.6 -74.6502 20429.4 9.17509 301.695 -23.6939 2060.56 -69.0536 17482.3 70.6398 18245.9 80.8864 23928.1 -92.5191 31070.7 44.572 7173.67 -44.2516 7182.77 54.4481 10834.3 -31.9298 3741 -76.8209 21634.2 52.6855 10143.4 45.1833 7457.24 -85.5808 26846.9 50.2302 9218.94 -37.1476 5062.7 75.3594 20767.6 38.1241 5306.06 -88.4814 28696.9 56.3904 11622 27.3543 2691.52 -63.2606 14673.4 -41.756 6395.87 88.306 28522.7 76.9028 21394.9 -56.4103 11669 -13.2087 640.006 0.630997 -2.19554 28.8303 3030.51 -80.9165 24134.4 -72.2801 19153.4 -60.7668 13539.9 18.9293 1302.25 -53.5139 10502.1 -71.7702 18884.2 0.581146 -2.39972 95.3199 33236.7 71.8276 18689.3 26.3199 2524.37 87.0928 28145.7 98.8195 35723.6 63.7243 14845.5 49.4686 8941.14 -76.0229 21187.3 54.2492 10755.3 -2.81444 26.5353 78.4736 22520.9 92.0964 31025.5 41.8727 6402.95 -76.9024 21680.2 60.6131 13429.9 -3.32503 38.1899 -46.3873 7892.38 -52.3492 10050.1 -43.826 7045.34 54.0991 10695.8 65.4632 15667.5 -78.1681 22399.4 27.6144 2779.61 -29.2628 3142.44 -25.9555 2472.55 -26.1809 2573.59 65.098 15493.1 27.6821 2793.29 -54.8218 11021.4 88.9304 28927.8 76.598 21456.4 19.6702 1406.72 97.5786 34831.6 93.4205 31924.6 -18.5447 1262.31 -6.91029 173.803 40.2604 5918.55 -46.6394 7978.34 27.4472 2745.95 28.5451 2970.69 76.9291 21642.5 -28.562 2993.81 7.25648 186.905 69.7302 17778.6 86.5001 27367.3 -79.7039 23342.2 23.5674 2022.46
输出
3.66 -0.28 -6.25
************************************************/
#include <memory>
#include <atomic>
#include <cassert>
#include <random>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>

namespace mt {
template<typename T>
class Mat {
 public:
  explicit Mat() : rows_(0), cols_(0) {
    data_ = nullptr;
    ref_count_ = std::make_shared<std::atomic<int>>(1);
  }
  explicit Mat(int rows, int cols) : rows_(rows), cols_(cols) {
    data_ = new T[rows * cols];
    ref_count_ = std::make_shared<std::atomic<int>>(1);
  }
  Mat(const Mat &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = other.data_;
    ref_count_ = other.ref_count_;
    ref_count_->fetch_add(1);
  }
  void release() {
    if (ref_count_ != nullptr) {
      if ((*ref_count_).fetch_sub(1) == 1) {
        if (data_ != nullptr) {
          delete[]data_;
          data_ = nullptr;
        }
      }
    }
    rows_ = 0;
    cols_ = 0;
    ref_count_.reset();
  }
  ~Mat() {
    release();
  }
  bool empty() const {
    return (rows_ == 0) || (cols_ == 0) || (data_ == nullptr);
  }
  int rows() const {
    return rows_;
  }
  int cols() const {
    return cols_;
  }
  T *data() const {
    return data_;
  }
  T &operator()(int row, int col) {
    assert((rows_ > row) && (cols_ > col));
    assert(data_ != nullptr);
    return data_[row * cols_ + col];
  }
  const T &operator()(int row, int col) const {
    assert((rows_ > row) && (cols_ > col));
    assert(data_ != nullptr);
    return data_[row * cols_ + col];
  }
  Mat &operator=(const Mat &other) {
    if (this == &other) {
      return *this;
    }
    release();
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = other.data_;
    ref_count_ = other.ref_count_;
    ref_count_->fetch_add(1);
    return *this;
  }
  Mat &operator=(Mat &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    release();
    data_ = std::exchange(other.data_, nullptr);
    ref_count_ = std::exchange(other.ref_count_, nullptr);
    rows_ = std::exchange(other.rows_, 0);
    cols_ = std::exchange(other.cols_, 0);
    return *this;
  }
  Mat clone() const {
    Mat tmp;
    tmp.rows_ = rows_;
    tmp.cols_ = cols_;
    tmp.data_ = new T[rows_ * cols_];
    memcpy(tmp.data_, data_, sizeof(T) * rows_ * cols_);
    return tmp;
  }
  Mat t() const {
    Mat result(cols_, rows_);
    for (int i = 0; i < result.rows_; ++i) {
      for (int j = 0; j < result.cols_; ++j) {
        result(i, j) = (*this)(j, i);
      }
    }
    return result;
  }
  static Mat zeros(int rows, int cols) {
    Mat result(rows, cols);
    memset(result.data_, 0, sizeof(T) * rows * cols);
    return result;
  }
  static Mat ones(int rows, int cols) {
    assert(rows == cols);
    Mat result(rows, cols);
    memset(result.data_, 0, sizeof(T) * rows * cols);
    for (int i = 0; i < rows; ++i) {
      result(i, i) = 1;
    }
    return result;
  }
  static Mat random(int rows, int cols,
                    const T &min = std::numeric_limits<T>::min(),
                    const T &max = std::numeric_limits<T>::max()) {
    Mat result(rows, cols);
    memset(result.data_, 0, sizeof(T) * rows * cols);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist_int(min, max);
    std::uniform_real_distribution<float> dist_real(min, max);
    bool is_real = (typeid(T) == typeid(float)) || (typeid(T) == typeid(double));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (is_real) {
          result(i, j) = dist_real(gen);
        } else {
          result(i, j) = dist_int(gen);
        }
      }
    }
    return result;
  }
  Mat &operator+=(const Mat &rhs) noexcept {
    assert((rows_ == rhs.rows()) && (cols_ == rhs.cols_()));
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; ++j) {
        data_[i * cols_ + j] += rhs(i, j);
      }
    }
    return *this;
  }
  friend Mat operator*(const Mat &lhs, const T &scale) {
    Mat result;
    result = lhs.clone();
    for (int i = 0; i < result.rows(); ++i) {
      for (int j = 0; j < result.cols(); ++j) {
        result(i, j) = static_cast<T>(result(i, j) * scale);
      }
    }
    return result;
  }
  friend Mat operator*(const T &scale, const Mat &lhs) {
    return lhs * scale;
  }
  friend Mat operator+(const Mat &lhs, const Mat &rhs) {
    Mat result = lhs;
    result += rhs;
    return result;
  }
  friend Mat operator*(const Mat &lhs, const Mat &rhs) {
    assert(lhs.cols() == rhs.rows());
    Mat result(lhs.rows(), rhs.cols());
    for (int i = 0; i < result.rows(); ++i) {
      for (int j = 0; j < result.cols(); ++j) {
        T Cij = 0;
        for (int k = 0; k < lhs.cols(); ++k) {
          Cij += lhs(i, k) * rhs(k, j);
        }
        result(i, j) = Cij;
      }
    }
    return result;
  }
  Mat getCofactor(int p, int q) const {
    assert(rows_ == cols_);
    int dimN = rows_;
    Mat temp(dimN - 1, dimN - 1);
    int i = 0, j = 0;
    for (int row = 0; row < dimN; row++) {
      for (int col = 0; col < dimN; col++) {
        if (row != p && col != q) {
          temp(i, j++) = (*this)(row, col);
          if (j == dimN - 1) {
            j = 0;
            i++;
          }
        }
      }
    }
    return temp;
  }
  double determinant() const {
    assert(rows_ == cols_);
    int dimN = rows_;
    double D = 0; // Initialize result
    if (dimN == 1)
      return (*this)(0, 0);
    int sign = 1;  // To store sign multiplier
    for (int f = 0; f < dimN; f++) {
      Mat<T> temp = getCofactor(0, f);
      D += sign * (*this)(0, f) * temp.determinant();
      sign = -sign;
    }
    return D;
  }
  Mat adjoint() const {
    assert(rows_ == cols_);
    int dimN = rows_;
    Mat adj(dimN, dimN);
    if (dimN == 1) {
      adj(0, 0) = 1;
      return adj;
    }
    int sign = 1;
    for (int i = 0; i < dimN; i++) {
      for (int j = 0; j < dimN; j++) {
        Mat temp = getCofactor(i, j);
        sign = ((i + j) % 2 == 0) ? 1 : -1;
        adj(j, i) = (sign) * (temp.determinant());
      }
    }
    return adj;
  }
  Mat inv() const {
    assert(!empty() && (rows_ == cols_));
    int dimN = rows_;
    double det = determinant();
    if (det == 0) {
      std::cout << "Singular matrix, can't find its inv";
      return Mat<T>();
    }
    Mat adj = adjoint();
    Mat inv(dimN, dimN);
    for (int i = 0; i < dimN; i++)
      for (int j = 0; j < dimN; j++)
        inv(i, j) = adj(i, j) / det;
    return inv;
  }
  friend std::ostream &operator<<(std::ostream &os, const Mat &obj) {
    // write obj to stream
    for (int i = 0; i < obj.rows(); ++i) {
      for (int j = 0; j < obj.cols(); ++j) {
        os << obj(i, j) << " ";
      }
      os << std::endl;
    }
    return os;
  }
  friend std::istream &operator>>(std::istream &is, Mat &obj) {
    for (int i = 0; i < obj.rows(); ++i) {
      for (int j = 0; j < obj.cols(); ++j) {
        is >> obj(i, j);
      }
    }
    return is;
  }
  void display() const {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if ((typeid(T) == typeid(char)) || (typeid(T) == typeid(unsigned char))) {
          std::cout << static_cast<int>((*this)(i, j)) << " ";
        } else {
          std::cout << (*this)(i, j) << " ";
        }
      }
      std::cout << std::endl;
    }
  }
 private:
  int rows_;
  int cols_;
  T *data_;
  std::shared_ptr<std::atomic<int>> ref_count_;
};
}

template<typename T>
mt::Mat<T> Solution(const mt::Mat<T> &samples, int num_params) {
  mt::Mat<T> coeffs = mt::Mat<T>::zeros(num_params, 1);
  // write code here
  //calculate matrix A = [x^2, x, 1; ...]
  // y matric C = [y1, y2, y3, ..., yn]
  int num_samples = samples.rows();
  mt::Mat<double> x_matrix(num_samples, 3);
  mt::Mat<double> y_matrix(num_samples,1);
  for(int i = 0; i < num_samples; i++){
    x_matrix(i,0) = samples(i,0)*samples(i,0);
    x_matrix(i,1) = samples(i,0);
    x_matrix(i,2) = 1;

    y_matrix(i,0) = samples(i,1);
  }
  // for AB = C
  // B = (A^T*A)-1*A^T*C

  // calculate transpose of A
  mt::Mat<double> x_matrix_trans=x_matrix.t();
  //calculate A^T*A
  mt::Mat<double> x_matrix_mult = x_matrix_trans*x_matrix;
  //calculate invese of A^T*A
  mt::Mat<double> x_matrix_mult_inv = x_matrix_mult.inv();
  // calculate result 
  //std::cout<<"rows: "<<x_matrix_trans.rows()<<"cols: "<<x_matrix_trans.cols()<<std::endl;
  //std::cout<<"rows: "<<y_matrix.rows()<<"cols: "<<y_matrix.cols()<<std::endl;
  //std::cout<<"rows: "<<x_matrix_mult_inv.rows()<<"cols: "<<x_matrix_mult_inv.cols()<<std::endl;
  mt::Mat<double> result = x_matrix_mult_inv*(x_matrix_trans*y_matrix);
  for(int i=0; i<num_params; i++){
    coeffs(i,0) = result(i,0);
  }
  return coeffs;
}

int main() {
  int num_samples;
  std::cin >> num_samples;
  int num_params = 3;
  mt::Mat<float> samples(num_samples, 3);
  for (int i = 0; i < num_samples * 2; i++) {
    std::cin >> samples(i / 2, i % 2);
  }
#if 0
  printf("samples:\n");
  for (int i = 0; i < samples.rows(); i++) {
    printf("%f %f ", samples(i, 0), samples(i, 1));
  }
  printf("\n");
#endif
  mt::Mat<float> coeffs = Solution(samples, num_params);
  for (int i = 0; i < coeffs.rows(); i++) {
    printf("%.2f ", coeffs(i, 0));
  }
  return 0;
}