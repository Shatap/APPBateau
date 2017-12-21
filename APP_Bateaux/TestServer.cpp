#include "TestServer.h"

#include <thread>

using namespace std;

//std::vector<std::string*> gathered_data;
std::vector<std::string> gathered_data;


TestServer::TestServer(char* service_beacon, char* service_client)
    : m_serviceBeacon{service_beacon}, m_serviceClient{service_client}
{

}

void TestServer::addData(SendData data)
{
    if(gathered_data.size() > 25)
    {
       gathered_data.clear();
        cout << "ccoucou chui passé" << endl;
    }

    /*std::string* newString = new std::string();
    *newString = "########## Bateau : ";
    *newString += data.getName() + "###############\n";
    *newString += "Coordonnées: (";
    *newString += to_string(data.getX()) + ",";
    *newString += to_string(data.getY()) + ")\n";
    *newString += "Cap :";
    *newString += data.getStringHeading() + ", Vitesse :";
    *newString += to_string(data.getSpeed()) + "\n";*/

    std::string newString  = "########## Bateau : ";
    newString += data.getName() + "###############\n";
    newString += "Coordonnées: (";
    newString += to_string(data.getX()) + ",";
    newString += to_string(data.getY()) + ")\n";
    newString += "Cap :";
    newString += data.getStringHeading() + ", Vitesse :";
    newString += to_string(data.getSpeed()) + "\n";

    //gathered_data.push_back(newString);
    gathered_data.push_back(newString);
}

void TestServer::listenClient()
{
    auto local_address = local_socket_address(SOCK_DGRAM, m_serviceClient);
    int socket_to_send;
    int socket_to_listen = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_to_listen,(sockaddr *)& local_address, sizeof local_address);

    listen(socket_to_listen,100); // La socket est configurer pour accepter les requêtes de connexions

    socket_to_send = accept(socket_to_listen, NULL, NULL); // Fais en sorte que socketToWork prennent la première requête de connection pour pouvoir envoyer les données des balises
    if(socket_to_send != -1)
    {
        while (true)
        {
            if(!gathered_data.empty())
            {
                cout << gathered_data.size() << endl;
                for(std::string data : gathered_data)
                {
                    int verif = send(socket_to_send, &data, sizeof data, 0);
                    if (verif != sizeof &data)
                    {
                            std::cout << "Problème d'envoi des données" << std::endl;
                    }

                }
                std::this_thread::sleep_for((std::chrono::seconds)2);
            }
        }
    }
    else
    {
        cout << "probleme connexion" << endl;
    }

    close(socket_to_listen);
    close(socket_to_send);
}

void TestServer::listenBeacon()
{
    auto local_address = local_socket_address(SOCK_DGRAM, m_serviceBeacon);
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(fd,(sockaddr *)& local_address, sizeof(local_address));

    SendData data;
    while(true)
    {
        if(read(fd, &data, sizeof data) == sizeof data)
        {
            addData(data);
        }
    }

    close(fd);
}
