#include <cstdlib>
#include <vector>
#pragma once

struct Chunk {
private:
  int next;
  int prev;
  int ptr;
  int size;
  int requested_size;
  int bin_num = 0;
  int allocation_id = 0;
  void *pool;

public:
  Chunk(int size) : size(size), pool(malloc(256 * size)){}

  int get_size() { return size; }
  int get_bin_num() { return bin_num; }
  int get_allocation_id() { return allocation_id; }
  int get_next() { return next; }
  int get_prev() { return prev; }

  void set_next(Chunk *ptr) { this->next = ptr->next; }
  void set_prev(Chunk *ptr) { this->prev = ptr->prev; }
  void set_size(int size) { this->size = size; }
  void set_bin_num(int bin_num) { this->bin_num = bin_num; }
  void set_allocation_id(int allocation_id) {
    this->allocation_id = allocation_id;
  }
  void set_pool() { pool = malloc(256 * size); }
};
