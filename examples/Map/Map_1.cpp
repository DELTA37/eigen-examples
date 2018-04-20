#include <iostream>
#include <Eigen/Core>

// without copy of buffer

int main(void) {
  double data[9];
  for (size_t i = 0; i < 9; ++i) {
    data[i] = i;
  }
  Eigen::Map<Eigen::VectorXd> a(data, 9);
  std::cout << a;
  data[0] = 100;
  std::cout << a;
  return 0;
}
