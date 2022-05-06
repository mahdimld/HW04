#ifndef SHARED_PTR
#define SHARED_PTR

 template <typename T>
class SharedPtr
{

private:
T* _p = nullptr;
int* refCount = nullptr;
public:
 SharedPtr();
 SharedPtr(T*);
 SharedPtr(const SharedPtr&);
 SharedPtr& operator=(const SharedPtr<T>&);
 T* get();
 int use_count() const;
 T& operator*();
 T* operator->();
 void reset();
 void reset(T*);
 ~SharedPtr();
 explicit operator bool();
};
 template <typename T>
SharedPtr<T> make_shared(T ptr)
{
    return SharedPtr<T>{new T{ptr}};
}

#include "shared_ptr.hpp"
#endif //SHARED_PTR