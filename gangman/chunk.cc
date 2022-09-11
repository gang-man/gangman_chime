
#include "gangman/chunk.h"
#include <cstddef>
#include <cstdlib>
Chunk *SplitChunk(Chunk *chunk, size_t size) {
  if (chunk->get_size() > 2 * size - 1) {
    Chunk temp = Chunk(chunk->get_size() - size);
    chunk->set_size(size);
    temp.set_region((char *)(chunk->get_region()) + (256 * size));
    chunks.insert(chunks.begin() + chunk->get_allocation_id() + 1, temp);
  } else {

    return chunk;
  }
}

void Extend(size_t size){



}

void* Allocate(size_t size, size_t alignment){
    return aligned_alloc(8, 256 * size);

}
