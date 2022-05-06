template <typename T>
    SharedPtr<T>::SharedPtr() :_p(nullptr), refCount(new int(0)){}
    
    
    template <typename T>
    SharedPtr<T>::SharedPtr(T* ptr) : _p(ptr), refCount(new int(1)){}
	
    
    template <typename T>
    SharedPtr<T>::SharedPtr(const SharedPtr& obj) 
	{
		this->_p = obj._p; 
		this->refCount = obj.refCount;
		if (nullptr != obj._p)
		{
			(*this->refCount)++;
		}
	}
    template <typename T>
    SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> & obj)
	{
        if (_p == obj._p)
        return *this;
		_p = obj._p;
		refCount = obj.refCount;
		if (nullptr != obj._p)
		{
			(*refCount)++;
		}
        return *this;
	}
    template <typename T>
    T* SharedPtr<T>::get(){
        return _p;
    
    }
    template <typename T>
    int SharedPtr<T>::use_count() const
	{
		return *refCount;
	}
    template <typename T>
    T& SharedPtr<T>::operator*()
    {
        return (*_p);
    }
    template <typename T>
    T* SharedPtr<T>::operator->()
    {
        return _p;
    }
    template <typename T>
    SharedPtr<T>::~SharedPtr(){
        (*refCount)--;
		if (*refCount == 0)
		{
				delete _p;
                _p = nullptr;
		}
	}
    template <typename T>
    void SharedPtr<T>::reset(){
        delete _p;
        _p = NULL;
        *refCount = 0;
    }

    template <typename T>
    void SharedPtr<T>::reset(T* ptr){
        delete _p;
        _p = ptr;
        *refCount = 1;
        
    }
    template <typename T>
    SharedPtr<T>::operator bool(){
        if(_p == nullptr) return false;
        else
        return true;
    }
