template <typename T>
UniquePtr<T>::UniquePtr()
{
    _p = nullptr;
}

template <typename T>
UniquePtr<T>::UniquePtr(T* p)
{
    _p = p;
}

template <typename T>
T* UniquePtr<T>::get(){
    return _p;

}
template <typename T>
T& UniquePtr<T>::operator*()
{
    return (*_p);
}
template <typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}
template <typename T>
void UniquePtr<T>::reset(){
    delete _p;
    _p = NULL;
}
template <typename T>
void UniquePtr<T>::reset(T* ptr){
    delete _p;
    _p = ptr;

}
template <typename T>
T* UniquePtr<T>::release()
{
    T* rawPtr = _p;
    _p = NULL;
    return rawPtr;
}
template <typename T>
UniquePtr<T>::~UniquePtr()
{
    if(_p)
        delete _p;
    _p = NULL;
}

template <typename T>
UniquePtr<T>::operator bool(){
    if(_p == nullptr) return false;
    else
    return true;
}
