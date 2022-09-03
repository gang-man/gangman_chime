#include "bin.h"
#include "chunk.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

std::vector<Chunk> chunks;
std::vector<Bin> bins;

int main() {
  for (int i = 7; i < 10; i++) {
    Chunk chunk(i);
    chunks.push_back(chunk);
  }

  chunks.push_back(Chunk(5));
  chunks.push_back(Chunk(4));
  chunks.push_back(Chunk(16));


  std::sort(chunks.begin(), chunks.end(),
            [](Chunk &a, Chunk &b) { return a.get_size() < b.get_size(); });

  for (int i = 0; i < chunks.size(); i++) {
    int bin_size = floor((log(chunks[i].get_size())/log(2)));
    Bin temp = Bin(bin_size);
    temp.SetInitChunkIndex(i);

    while(i < chunks.size() && chunks[i+1].get_size() < pow(2, bin_size +
    1)){
        i++;

    }
    temp.SetEndChunkIndex(i);
    bins.push_back(temp);
    // j++;
  }
  
  std::cout << bins.size() << std::endl;
  std::cout << bins[0].GetBinSize() << std::endl;
  std::cout << bins[1].GetBinSize() << std::endl;
  std::cout << bins[2].GetBinSize() << std::endl;
  std::cout << chunks.size() << std::endl;

}
