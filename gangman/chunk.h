#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <vector>
#pragma once

struct Chunk {
private:
  int next;
  int prev;
  Chunk *ptr = this;
  int size;
  int requested_size;
  int bin_num = 0;
  int allocation_id = 0;
  void *region;

public:
  Chunk(int size) : size(size) {}

  int get_size() { return size; }
  int get_bin_num() { return bin_num; }
  int get_allocation_id() { return allocation_id; }
  int get_next() { return next; }
  int get_prev() { return prev; }
  void *get_region() { return region; }

  void set_next(Chunk *ptr) { this->next = ptr->next; }
  void set_prev(Chunk *ptr) { this->prev = ptr->prev; }
  void set_size(int size) { this->size = size; }
  void set_bin_num(int bin_num) { this->bin_num = bin_num; }
  void set_allocation_id(int allocation_id) {
    this->allocation_id = allocation_id;
  }
  void set_region(void *another_region) { region = another_region; }
};

struct Bin {
private:
  int bin_size;

public:
  Bin(int bin_size) : bin_size(bin_size) {}

  std::vector<Chunk *> chunk_in_bin;

  void SetBinSize(int bin_size) { this->bin_size = bin_size; }

  int GetBinSize() { return bin_size; }

  Chunk *ReturnChunk(size_t size) {
    for (int i = 0; i < chunk_in_bin.size(); i++) {
      if (chunk_in_bin[i]->get_size() >= size) {
        Chunk *temp = chunk_in_bin[i];
        chunk_in_bin.erase(chunk_in_bin.begin() + i);
        return temp;
      }
    }
    return nullptr;
  };
};

extern std::vector<Bin> bins;
extern std::vector<Chunk> chunks;

Chunk *SplitChunk(Chunk *chunk, size_t size);

class Allocator {};
class BFCAllocator : public Allocator {
public:
  BFCAllocator();

  Chunk *allocate(size_t size) {
    size_t normalized_chunk_size = ((size / 256) + ((size % 256) != 0));
    int bin_num = floor(log2(normalized_chunk_size));

    for (int i = bin_num; i < bins.size(); i++) {
      if (bins[i].ReturnChunk(normalized_chunk_size) != nullptr) {

        break;
      } else {
        // Extend;
      }
    }
    return nullptr;
  };
};
void Extend(size_t size);

void* Allocate(size_t size, size_t alignment);
