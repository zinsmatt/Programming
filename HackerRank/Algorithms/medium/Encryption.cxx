#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
  std::cerr << "after erase" << std::endl;
  
  int rows = std::floor(std::sqrt(s.size()));
  int cols = std::ceil(std::sqrt(s.size()));
  if (rows * cols < s.size())
    rows++;

  std::cerr << "rows = " << rows << std::endl;
  std::cerr << "cols = " << cols << std::endl;
  std::vector<std::vector<char>> grid(rows, std::vector<char>(cols, ' '));
  for (int i = 0; i < s.size(); ++i)
  {
    std::cerr << i / cols << " " << i % cols << " " << s[i] << std::endl;
    grid[i / cols][i % cols] = s[i];
  }
  std::cerr << "after grid" << std::endl;

  std::stringstream ss;

  for (int i = 0; i < cols; ++i)
  {
    for (int j = 0; j < rows; ++j)
    {
        if (grid[j][i] != ' ')
            ss << grid[j][i];
    }
    ss << ' ';
  }
return ss.str();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
