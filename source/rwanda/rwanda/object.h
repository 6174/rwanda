#pragma once
namespace litehtml
{
class Object
{
protected:
    int m_refCount;
public:
    Object()
    {
        m_refCount = 0;
    }
    virtual ~Object()
    {

    }

    void addRef()
    {
        m_refCount++;
    }

    void release()
    {
        if (!(--m_refCount)) delete this;
    }
};

template<class T>
class ObjectPtr
{
    T  *m_ptr;
public:
    ObjectPtr()
    {
        m_ptr = 0;
    }

    ObjectPtr(T *ptr)
    {
        m_ptr = ptr;
        if (m_ptr)
        {
            m_ptr->addRef();
        }
    }

    ObjectPtr(const ObjectPtr<T> &val)
    {
        m_ptr = val.m_ptr;
        if (m_ptr)
        {
            m_ptr->addRef();
        }
    }

    ~ObjectPtr()
    {
        if (m_ptr)
        {
            m_ptr->release();
        }
        m_ptr = 0;
    }

    void operator=(const ObjectPtr<T> &val)
    {
        T *oldPtr = m_ptr;
        m_ptr = val.m_ptr;
        if (m_ptr)
        {
            m_ptr->addRef();
        }
        if (oldPtr)
        {
            oldPtr->release();
        }
    }

    void operator=(T *val)
    {
        T *oldPtr = m_ptr;
        m_ptr = val;
        if (m_ptr)
        {
            m_ptr->addRef();
        }
        if (oldPtr)
        {
            oldPtr->release();
        }
    }

    T *operator->()
    {
        return m_ptr;
    }

    const T *operator->() const
    {
        return m_ptr;
    }

    operator T *()
    {
        return m_ptr;
    }

    operator const T *() const
    {
        return m_ptr;
    }
};
}
