#pragma once
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <vector>

class Allocator {
  virtual void *Allocate() = 0;
  virtual void Deallocate() = 0;
};
class BFCAllocator : public Allocator {
private:
  struct Chunk {
    size_t _ptr_position;
    size_t _next = -1;
    size_t _prev = -1;
    void *_ptr;
    size_t _size;
    size_t _requested_size;
    size_t _bin_num = 0;
    int _allocation_id = 0;

    Chunk(size_t size) : _size(size) {}
    Chunk(size_t size, void *ptr) : _size(size), _ptr(ptr) {}
    Chunk(size_t size, void *ptr, size_t ptr_position)
        : _size(size), _ptr(ptr), _ptr_position(ptr_position) {}
  };

  struct Bin {

    size_t _bin_size;

    Bin(int bin_size) : _bin_size(bin_size) {}

    std::vector<Chunk *> chunks_in_bin;

    Chunk *ReturnChunkInBin(size_t size) {
      Chunk *temp = nullptr;
      for (std::vector<Chunk *>::iterator iter = chunks_in_bin.begin();
           iter != chunks_in_bin.end(); ++iter) {
        if ((*iter)->_size >= size) {
          temp = *iter;
          chunks_in_bin.erase(iter);
        }
      }
      return temp;
    }
  };

  std::vector<size_t> IndexChunk;
  std::vector<Chunk> chunks;
  std::vector<Bin> bins;

  Chunk *SplitChunk(Chunk *chunk, size_t size);

  void Extend(size_t size);

  // void *Allocate(size_t size, size_t alignment);

  void Deallocate(void *ptr);

  void PushInBin(Chunk *chunk);

  void *FinkChunk(int size, size_t upper_memory_size);

public:
  BFCAllocator();
  ~BFCAllocator();

  void *Allocate(size_t size);
};
