#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

int main() {
  const int a = 5.0;

  MatrixXd m = MatrixXd::Random(3, 3);
  m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
  cout << "m =" << endl << m << endl;

  VectorXd v(3);
  v << 1, 2, 3;
  cout << "m * v =" << endl << m * v << endl;
}
