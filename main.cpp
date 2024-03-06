#include "main.h"

template <typename SymbolTableType>
void initializeSymbolTable (SymbolTableType& st, std::vector <int>& testVec) {
  for (size_t i = 0; i < testVec.size(); i++) {
    st[testVec[i]];
  }
}

template <typename SymbolTableType>
void testSymbolTable (SymbolTableType& stArr, std::vector <int> testVec) {
  Stopwatch watch;
  std::cout << "Inserted";
  /*for (size_t i = 0; i < testVec.size() - 1; i++) {
    std::cout << " " << testVec[i] << ",";
  }
  std::cout << " " << testVec[testVec.size() - 1] << " into the symbol table :" << std::endl;*/
  watch.start();
  for (size_t i = 0; i < testVec.size(); i++) {
    /*std::cout << std::boolalpha << "Checking if symbol table contains " << testVec[i] << " : " <<*/
    stArr.contains(testVec[i]);
  }
  std::cout << std::boolalpha << "Checking if symbol table contains an element that is not in it : " << stArr.contains(std::numeric_limits<int>::max()) << std::endl;
  double timeElapsed = watch.stop();
  std::cout << "Time elapsed : " << timeElapsed << std::endl;
}

template <typename SymbolTableType>
void testSt(SymbolTableType& st ,std::vector <int>& testVec) {
  initializeSymbolTable(st, testVec);
  testSymbolTable(st, testVec);
}

std::vector <int> initializeTestVec() {
  std::vector <int> testVec;
  const int UPPER_BOUND = 10000;
  for (int i = 0; i < UPPER_BOUND; i++) {
    testVec.push_back(i);
  }
  return testVec;
}

int main () {
  SymbolTable<int, size_t> stArr;
  SymbolTableLL<int, size_t> stLL;
  std::vector <int> testVec = initializeTestVec();
  std::cout << "Testing Symbol Table using Array : " << std::endl;
  testSt(stArr, testVec);
  std::cout << "----------------------------------------------------" << std::endl;
  std::cout << "Testing Symbol Table using Linked List : " << std::endl;
  testSt(stLL, testVec);
  
}
