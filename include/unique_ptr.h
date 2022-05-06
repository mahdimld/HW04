#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template<typename T>
class UniquePtr
{
    private :  T* _p;

public:
 UniquePtr();
 UniquePtr(T*);
 UniquePtr(const UniquePtr&) = delete;
 T* get();
 T& operator=(UniquePtr&) = delete;
 T& operator*();
 T* operator->();
 void reset();
 void reset(T*);
 T* release();
 ~UniquePtr();
 explicit operator bool();
};
template<typename T>
UniquePtr<T> make_unique(T ptr)
{
    return UniquePtr<T>{new T{ptr}};
}

#include "unique_ptr.hpp"
#endif //UNIQUE_PTR
