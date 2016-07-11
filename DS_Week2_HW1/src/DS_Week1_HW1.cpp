//============================================================================
// Name        : DS_Week1_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week2
// Description : Build heap in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void BuildHeap(){
       //swaps_.clear();
       int size = data_.size();
       for(int i=(size-1)/2; i>=0; --i )
          SiftDown(i);
  }

  void SiftDown(int i) {
       int maxIndex = i;
       int left = (2*i)+1;
       if( (left <= (data_.size()-1) && data_[left] < data_[maxIndex]))
           maxIndex = left;
       int right = (2*i)+2;
       if( (right <= (data_.size()-1)) && data_[right] < data_[maxIndex])
           maxIndex = right;
       if(i!=maxIndex) {
           swap(data_[i],data_[maxIndex]);
           swaps_.push_back(make_pair(i,maxIndex));
           SiftDown(maxIndex);
       }
  }

  void GenerateSwaps() {
    swaps_.clear();
    BuildHeap();
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
     std::ios_base::sync_with_stdio(false);
     HeapBuilder heap_builder;
     heap_builder.Solve();
	return 0;
}
