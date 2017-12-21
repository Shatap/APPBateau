#include "ThreadServer.h"

ThreadServer::ThreadServer(TestServer server)
{
    server.listen();
}
