#include <bits/stdc++.h>
using namespace std;
int processArray(std::vector<int> &arr) {
  vector<pair<int,int>> v;
  int i = 0;
  int count = 0;
  int s = arr[0];
  for(int p = 1; p<arr.size(); p++)
  {
      if(arr[p] <= arr[p-1])
      {
        count++;
      }else{
        v.push_back({count,abs(arr[p]-s)});
      }
  }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    cout<<v[0].second<<endl;

  return 0;
}

int main(void) {
  std::vector<int> array;
  int val;
  while (std::cin >> val) {
    if (val < 0) break;
    array.push_back(val);
  }
  std::cout << processArray(array) << std::endl;
  return 0;
}