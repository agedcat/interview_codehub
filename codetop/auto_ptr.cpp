template <typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _reference_count;
public:
	//构造函数
	SmartPointer(T* p=nullptr): _ptr(p), _reference_count(new size_t){
		if(p)
			*_reference_count = 1; 
		else
			*_reference_count = 0; 
	}
	//拷贝构造函数
	SmartPointer(const SmartPointer& src) {
		if(this!=&src) {
			_ptr = src._ptr;
			_reference_count = src._reference_count;
			(*_reference_count)++;
		}
	}
	//重载赋值操作符
	SmartPointer& operator=(const SmartPointer& src) {
		if(_ptr==src._ptr) {
			return *this;
		}
		releaseCount();
		_ptr = src._ptr;
		_reference_count = src._reference_count;
		(*_reference_count)++;
		return *this;
	}
 
	//重载操作符
	T& operator*() {
		if(ptr) {
			return *_ptr;
		}
		//throw exception
	}
	//重载操作符
	T* operator->() {
		if(ptr) {
			return _ptr;
		}
		//throw exception
	}
	//析构函数
	~SmartPointer() {
		if (--(*_reference_count) == 0) {
            delete _ptr;
            delete _reference_count;
        }
	}
private:
    void releaseCount() {
    if(_ptr) {
            if((--*_reference_count)==0) {
                delete _ptr;
                delete _reference_count;
            }
        }
    }
};

