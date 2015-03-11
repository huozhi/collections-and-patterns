#ifndef __AUTOPTF__
#define __AUTOPTF__

template<class T>
class AutoPtr {
public:
    explicit AutoPtr(T *p = 0): pointee(p) {}
    template<class U>
    AutoPtr(AutoPtr<U>& rhs):
        pointee(rhs.release()) {}


    ~AutoPtr() { delete pointee; }
    template<class U>
    AutoPtr<T>& operator=(AutoPtr<U>& rhs) {
        if (this != rhs) reset(rhs.release());
        return *this;
    }

    T& operator*() const { return *pointee; }
    T* operator->() const { return pointee; }

    T* get() const { return pointee; }

    T *release() {
        T *old = pointee;
        pointee = NULL;
        return old;
    }

    void reset(T *p = NULL) {
        if (pointee != p) {
            delete pointee;
            pointee = p;
        }
    }

private:
    T *pointee;
    template<class U> friend class AutoPtr;
};

#endif