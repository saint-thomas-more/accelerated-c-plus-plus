#include <algorithm>
#include <array>
#include <iostream>
#include <string>
 
int main()
{
  std::array<std::string, 4> arr{ "apple", "banana", "walnut", "lemon" };

  std::string search;
  std::cin >> search;
 // Lambdas are of the form [capture clause] (params) -> return Type {}
  auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string str)
  {
      return (str.find(search) != std::string::npos);
  }
  
  ) };
 
  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  bool is_even{
      [](int i) {
          return ((i%2) == 0);
      }
  };


 
  return 0;
}