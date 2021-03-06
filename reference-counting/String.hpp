#ifndef __STRING_HPP__
#define __STRING_HPP__

#include "RCObject.hpp"
#include "RCPtr.hpp"

class String {
public:
    String(const char *value = "");
    ~String();

    const char& operator[](int index) const;
    char& operator[](int index);

    void printStringValue();
private:
    /* The purpose of StringValue is to give us place
     * to associate particular value with a reference count
     * which is the number of String objects sharing that value */
    struct StringValue : public RCObject
    {
        int refCount;
        bool shareable;
        char *data;

        StringValue(const char* initValue);
        StringValue(const StringValue& rhs);
        ~StringValue();
    };
    RCPtr<StringValue> value;
};

#endif //__STRING_HPP__
