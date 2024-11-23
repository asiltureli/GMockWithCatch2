#pragma once

#include <gmock/gmock.h>


class ClassToTest{
public:
    virtual void some_call(){};
};


class MockClass : public ClassToTest{
public:
    MOCK_METHOD(void, some_call, (), (override));
};

class SimpleWrapper{
public:
    SimpleWrapper() = delete;
    SimpleWrapper(ClassToTest& sc) : m_obj { sc }{};
    void call(){m_obj.some_call();};
private:
    ClassToTest& m_obj;
};