#include <Eigen/Core>
#include <iostream>
// alignment and stride

int main(void) {
  double data[10];
  for (size_t i = 0; i < 10; ++i) {
    data[i] = i;
  }
  Eigen::Map<Eigen::VectorXd, Eigen::Unaligned, Eigen::InnerStride<2>> m1(data, 10);
  std::cout << m1 << std::endl;
  Eigen::Map<Eigen::VectorXd, Eigen::Unaligned, Eigen::OuterStride<2>> m2(data, 10);
  std::cout << m2 << std::endl;
  return 0;
}
