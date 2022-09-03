struct Bin {
private:
  int bin_size;
  int init_chunk_index;
  int end_chunk_index;

public:
  Bin(int bin_size) : bin_size(bin_size) {}
  
  void SetBinSize(int bin_size) { this->bin_size = bin_size; }
  void SetInitChunkIndex(int init_chunk_index) {
    this->init_chunk_index = init_chunk_index;
  }
  void SetEndChunkIndex(int chunk_number) { this->end_chunk_index= chunk_number; }
  int GetBinSize() { return bin_size; }
};


