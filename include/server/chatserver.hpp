#ifndef CHATSERVER_HPP
#define CHATSERVER_HPP

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

// 聊天服务器的主类
class ChatServer
{
public:
    // 初始化聊天服务器对象
    ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg);

    // 启动服务
    void start();

private:
    // TcpServer绑定的回调函数，当有新连接或连接中断时调用（背后原理是epoll树）
    void onConnection(const TcpConnectionPtr&);

    // TcpServer绑定的回调函数，当有新数据读写时调用（背后原理是线程池）
    void onMessage(const TcpConnectionPtr&,
                            Buffer*,
                            Timestamp);

    // 组合的muduo库，实现服务器功能的类对象
    TcpServer _server;

    // 指向事件循环对象的指针
    EventLoop *_loop;
};
#endif