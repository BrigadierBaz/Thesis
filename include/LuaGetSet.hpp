#ifndef LUA_GET_SET_H
#define LUA_GET_SET_H

#include <string>

#include "RVO.h"

class LuaGetSet
{
  public:
    LuaGetSet() : boolean(), integer(), uinteger(), cstring(""), cppstring(""), number(), floatnumber(), ptr(), vec() {}

    bool boolean;
    int integer;
    unsigned int uinteger;
    const char* cstring;
    std::string cppstring;
    double number;
    float floatnumber;
    LuaGetSet* ptr;
    RVO::Vector3 vec;

    bool GetBoolean() const;
    int GetInteger() const;
    unsigned int GetUInteger() const;
    const char* GetCString() const;
    const std::string& GetCPPString() const;
    double GetNumber() const;
    float GetFloatNumber() const;
    LuaGetSet* GetPtr() const;
    const RVO::Vector3& GetVec() const;

    void SetBoolean(bool val);
    void SetInteger(int val);
    void SetUInteger(unsigned int val);
    void SetCString(const char* val);
    void SetCPPString(const std::string& val);
    void SetNumber(double val);
    void SetFloatNumber(float val);
    void SetPtr(LuaGetSet* val);
    void SetVec(const RVO::Vector3& Member);

    int DoSomething(bool b);

    int DoSomethingElse(int i, int j);
    int DoSomethingElse(float f);

};

#endif // LUAGETSET

