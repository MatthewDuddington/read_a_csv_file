//
// How to read a CSV file.
// 
// (C) Andy Thomason 2015
//
// Note CSV files may contain quotes and other complexity, so this
// is not completely general, but it is very simple.

#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::vector<std::string> names;
  std::vector<int> score;

  std::ifstream is("../test.csv");

  if (is.bad()) return 1;

  // store the line here
  char buffer[2048];

  // loop over lines
  while (!is.eof()) {
    is.getline(buffer, sizeof(buffer));

    // loop over columns
    char *b = buffer;
    for (int col = 0; ; ++col) {
      char *e = b;
      while (*e != 0 && *e != ',') ++e;

      // now b -> e contains the chars in a column
      if (col == 0) {
        names.emplace_back(b, e);
      } else if (col == 1) {
        score.push_back(std::atoi(b));
      }

      if (*e != ',') break;
      b = e + 1;
    }
  }
}
