#ifndef THREADSERVER_H
#define THREADSERVER_H

#include "TestServer.h"

#include <thread>

class ThreadServer : public std::thread
{
public:
    ThreadServer(TestServer server);
};

#endif // THREADSERVER_H
