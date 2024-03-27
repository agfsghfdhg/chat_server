#ifndef USERMODEL_HPP
#define USERMODEL_HPP

#include "user.hpp"

// user表的数据操作类
class UserModel
{
public:
    // user表的增加方法
    bool insert(User &user);

    // user表根据id查询用户信息
    User query(int id);

    // user表更改用户状态信息
    bool updateState(User user);

    // 重置用户的状态信息
    void resetState();
};

#endif