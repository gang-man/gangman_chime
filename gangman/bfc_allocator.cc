
#include "bfc_allocator.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
// Chunk *SplitChunk(Chunk *chunk, size_t size) {

// }

void BFCAllocator::Extend(size_t handle_size) {

  void *ptr = aligned_alloc(8, handle_size * 256);
  if (ptr != nullptr) {

    IndexChunk.push_back(chunks.size());

    chunks.push_back(Chunk(handle_size, ptr, IndexChunk.size() - 1));

    std::fill_n(std::back_inserter(IndexChunk), handle_size - 1, -1);

    for (int i = bins.size(); i < floor(log2(handle_size)) + 1; i++) {
      bins.push_back(Bin(i));
    }
    PushInBin(&chunks.back());
  }
};
BFCAllocator::Chunk *BFCAllocator::SplitChunk(Chunk *chunk, size_t size) {

  chunks.push_back(Chunk(size - chunk->_size,
                         (void *)((char *)(chunk->_ptr) + size * 256),
                         chunk->_ptr_position + chunk->_size));
  chunk->_size = size;

  IndexChunk[chunk->_ptr_position + chunk->_size] = chunks.size() - 1;

  // set _prev and _next

  chunk->_next = chunks.size() - 1;

  chunks.back()._prev = IndexChunk[chunk->_ptr_position];

  return chunk;
};

void *BFCAllocator::FinkChunk(int bin_num, size_t upper_memory_size) {
  Chunk *temp = nullptr;
  for (std::vector<Bin>::iterator iter = bins.begin() + bin_num;
       iter != bins.end(); ++iter) {
    if (iter->ReturnChunkInBin(upper_memory_size) != nullptr) {
      temp = iter->ReturnChunkInBin(upper_memory_size);
      break;
    }
  }

  if (temp->_size > 2 * upper_memory_size - 1) {
    temp = SplitChunk(temp, upper_memory_size);
  }

  return temp;
};

void *BFCAllocator::Allocate(size_t raw_size) {

  // 0. Preliminary work
  void *return_ptr = nullptr;
  size_t upper_memory_size = (raw_size + 256 - 1) / 256;
  int bin_num = floor(log2(upper_memory_size));

  // 1.Find Chunk
  return_ptr = FinkChunk(bin_num, upper_memory_size);

  // 2.Extend
  if (return_ptr != nullptr) {
    return return_ptr;
  }

  Extend(upper_memory_size);
  return_ptr = FinkChunk(bin_num, upper_memory_size);

  // 3.Merge Chunk
  if (return_ptr != nullptr) {
    return return_ptr;
  }

  throw "Error: No enough memory";
  // return nullptr;

  //   if(return_ptr != nullptr){
  //     return return_ptr;
  // }else {

  // }
  // 4.Merge Region
};

void BFCAllocator::Deallocate(void *ptr) { free(ptr); };

void BFCAllocator::PushInBin(Chunk *chunk) {

  int i = floor(log2(chunk->_size));
  bins[i].chunks_in_bin.push_back(chunk);

  std::sort(bins[i].chunks_in_bin.begin(), bins[i].chunks_in_bin.end(),
            [](Chunk *a, Chunk *b) {
              if (a->_size != b->_size) {
                return a->_size < b->_size;
              }

              return a->_ptr < b->_ptr;
            });
}
