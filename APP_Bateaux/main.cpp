#include "Beacon.h"
#include "Client.h"
#include "TestServer.h"

#include <vector>
#include <thread>

using namespace std;

void threadServerListenBeacon(TestServer server)
{
    server.listenBeacon();
}

void threadServerListenClient(TestServer server)
{
    server.listenClient();
}

void threadConnectionClient(Client client)
{
    client.makeRequestToServer();
}

void threadBeaconUpdate(Beacon beacon)
{
    while(true)
    {
        beacon.update();
        beacon.sendToServer();
        this_thread::sleep_for((chrono::seconds)5);
    }
}


int main()
{
    char* serviceBeacon = (char*)"1998";
    char* serviceClient = (char*)"1997";

    vector<thread> m_vectorThreads;

    Beacon beacon("Marcelino", 0, 10, 10, 50, NORTH, (char*)"localhost", serviceBeacon);


    TestServer server(serviceBeacon, serviceClient);
    m_vectorThreads.push_back(thread(threadServerListenBeacon, server));


    Client client((char*)"localhost", serviceClient);
    m_vectorThreads.push_back(thread(threadConnectionClient, client));

    m_vectorThreads.push_back(thread(threadServerListenClient, server));

    m_vectorThreads.push_back(thread(threadBeaconUpdate, beacon));


    for(unsigned int i = 0; i < m_vectorThreads.size(); ++i)
    {
        if(m_vectorThreads[i].joinable())
        {
            m_vectorThreads[i].join();

        }
    }
}
