namespace rain {
template <typename T>
class share_ptr {
 public:
  share_ptr() : ptr(nullptr), count(nullptr) {}
  share_ptr(T* resource) : ptr(resource), count(new int(1)) { printf("share_ptr construct\n"); }
  share_ptr(const share_ptr<T>& sp) : ptr(sp.ptr), count(sp.count) {
    ++(*count);
    printf("share_ptr copy construct\n");
  }
  share_ptr<T>& operator=(const share_ptr<T>& sp) {
    if (this == &sp) {
      return *this;
    }
    ++(*sp.count);
    if (this->ptr && (--(*this->count)) == 0) {
      delete this->ptr;
      delete this->count;
      printf("share_ptr count==0 delete ptr and count\n");
    }
    this->ptr   = sp.ptr;
    this->count = sp.count;
    printf("share_ptr operator= \n");
    return *this;
  }
  ~share_ptr() {
    if (this->ptr && (--*(this->count) == 0)) {
      delete this->ptr;
      delete this->count;
      printf("~share_ptr delete ptr and count\n");
    }
  }
  T& operator*() { return *(this->ptr); }
  T* operator->() { return this->ptr; }
  int& use_count() const { return *(this->count); }

 private:
  T* ptr;
  int* count;
};
}  // namespace rain