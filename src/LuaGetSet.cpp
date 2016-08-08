#include "LuaGetSet.hpp"
#include <string>
#include <iostream>

bool LuaGetSet::GetBoolean() const
{
    return boolean;
}

int LuaGetSet::GetInteger() const
{
    return integer;
}

unsigned int LuaGetSet::GetUInteger() const
{
    return uinteger;
}

const char* LuaGetSet::GetCString() const
{
    return cstring;
}

const std::string& LuaGetSet::GetCPPString() const
{
    return cppstring;
}

const RVO::Vector3 &LuaGetSet::GetVec() const
{
    return vec;
}

double LuaGetSet::GetNumber() const
{
    return number;
}

float LuaGetSet::GetFloatNumber() const
{
    return floatnumber;
}

LuaGetSet* LuaGetSet::GetPtr() const
{
    return ptr;
}

void LuaGetSet::SetBoolean(bool val)
{
    boolean = val;
}

void LuaGetSet::SetInteger(int val)
{
    integer = val;
}

void LuaGetSet::SetUInteger(unsigned int val)
{
    uinteger = val;
}

void LuaGetSet::SetCString(const char* val)
{
    cstring = val;
}

void LuaGetSet::SetCPPString(const std::string& val)
{
    cppstring = val;
}

void LuaGetSet::SetVec(const RVO::Vector3& val)
{
    vec = val;
}

void LuaGetSet::SetNumber(double val)
{
    number = val;
}

void LuaGetSet::SetFloatNumber(float val)
{
    floatnumber = val;
}

void LuaGetSet::SetPtr(LuaGetSet* val)
{
    ptr = val;
}

int LuaGetSet::DoSomething(bool b)
{
    std::cout << "b = " << b << std::endl;
    return 0;
}

int LuaGetSet::DoSomethingElse(int i, int j)
{
    std::cout << "i = " << i << ", j = " << j << std::endl;
    return 0;
}

int LuaGetSet::DoSomethingElse(float f)
{
    std::cout << "f = " << f << std::endl;
    return 0;
}
