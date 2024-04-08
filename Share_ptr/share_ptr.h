namespace rain {
template <typename T>
class share_ptr {
 public:
  share_ptr(T* ptr = nullptr) : ptr_(ptr), count_((ptr != nullptr) ? (new int(1)) : nullptr) {
    printf("share_ptr construct\n");
  }

  share_ptr(const share_ptr<T>& sp) : ptr_(sp.ptr_), count_(sp.count_) {
    if (ptr_ != nullptr) {
      ++(*count_);
      printf("share_ptr copy construct\n");
    }
  }

  share_ptr<T>& operator=(const share_ptr<T>& sp) {
    if (this->ptr_ == sp.ptr_) {
      printf("operator=: this==&sp \n");
      return *this;
    }
    if (ptr_ != nullptr && ((--*(count_)) == 0)) {
      delete ptr_;
      ptr_ = nullptr;
      delete count_;
      count_ = nullptr;
      printf("share_ptr count==0 delete ptr and count\n");
    }
    if (sp.ptr_ != nullptr) {
      ++(*sp.count_);
      ptr_   = sp.ptr_;
      count_ = sp.count_;
      printf("share_ptr operator= \n");
    }
    return *this;
  }

  ~share_ptr() {
    if (ptr_ && (--*(count_) == 0)) {
      delete ptr_;
      ptr_ = nullptr;
      delete count_;
      count_ = nullptr;
      printf("~share_ptr delete ptr and count\n");
    }
  }

  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  int& use_count() const { return *count_; }
  T* get() const { return ptr_; }

 private:
  T* ptr_;
  int* count_;
};
}  // namespace rain