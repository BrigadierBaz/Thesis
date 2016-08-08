#ifndef LUAVECTOR3
#define LUAVECTOR3

struct LuaVector3
{
    LuaVector3(float x_ = 0.f, float y_ = 0.f, float z_ = 0.f)
        : x(x_)
        , y(y_)
        , z(z_)
    {
    }

    float x;
    float y;
    float z;
};

#endif // LUAVECTOR3

