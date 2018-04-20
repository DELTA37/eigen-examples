#include <Eigen/Core>
#include <iostream>

int main(void) {
  //SizeAtCompileTime	the number of rows/cols, or Dynamic
  //MaxSizeAtCompileTime	the maximum number of rows/cols, or Dynamic. 
  //This optional parameter defaults to SizeAtCompileTime. Most of the time, you should not have to specify it.
  //_StorageIndex	the integer type of the indices

  Eigen::PermutationMatrix<Eigen::Dynamic> sigma(5);
  sigma.setIdentity();
  Eigen::MatrixXd A(5, 5);
  for (size_t i = 0; i < 5; ++i)
  for (size_t j = 0; j < 5; ++j) {
    A(i, j) = i + j;
  }
  for (size_t i = 0; i < 5; ++i) {
    std::cout << "permutation - " << i << std::endl;
    sigma = sigma.applyTranspositionOnTheLeft(i, (i + 1) % 5);
    std::cout << sigma.indices() << std::endl;
  }
  std::cout << "determinant" << std::endl;
  std::cout << sigma.determinant() << std::endl;
  std::cout << "initial matrix" << std::endl;
  std::cout << A << std::endl;
  std::cout << "permutation" << std::endl;
  std::cout << sigma.indices() << std::endl;
  std::cout << "row permutation" << std::endl;
  std::cout << sigma * A << std::endl;
  std::cout << "col permutation" << std::endl;
  std::cout << A * sigma << std::endl;
  return 0;
}
