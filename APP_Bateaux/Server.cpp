#include "Server.h"

#include <thread>

using namespace std;

std::vector<std::string> gathered_data;


Server::Server(char* service_beacon, char* service_client)
    : m_serviceBeacon{service_beacon}, m_serviceClient{service_client}
{}

void Server::addData(SendData data)
{
    if(gathered_data.size() > 25)
        gathered_data.clear();

    std::string message  = "Bateau : ";
    message += data.getName() + "\n";
    message += "Coordonnées: (";
    message += to_string(data.getX()) + ",";
    message += to_string(data.getY()) + ")\n";
    message += "Cap :";
    message += data.getStringHeading() + ", Vitesse :";
    message += to_string(data.getSpeed()) + "\n";

    gathered_data.push_back(message);
}

void Server::listenClient()
{
    //Envoie des paquets du Serveur au client via le protocole TCP
    auto local_address = local_socket_address(SOCK_DGRAM, m_serviceClient);
    int socket_to_send;
    int socket_to_listen = socket(AF_INET, SOCK_STREAM, 0);

    bind(socket_to_listen,(sockaddr *)& local_address, sizeof local_address);

    listen(socket_to_listen,100); // La socket est configuré pour accepter les requêtes de connexions

    socket_to_send = accept(socket_to_listen, NULL, NULL); // Fait en sorte que socketToWork prenne la première requête de connection pour pouvoir envoyer les données des balises
    if(socket_to_send != -1)
        while (true)
        {
            if(!gathered_data.empty())
            {
                cout << gathered_data.size() << endl;
                for(std::string data : gathered_data)
                {
                    int verif = send(socket_to_send, &data, sizeof data, 0);
                    if (verif != sizeof &data)
                        std::cout << "Data sending problem" << std::endl;

                }
                std::this_thread::sleep_for((std::chrono::seconds)2);
            }
        }
    else
        cout << "Connection problem" << endl;

    close(socket_to_listen);
    close(socket_to_send);
}

void Server::listenBeacon()
{
    //Ecoute des paquets du Beacon via le protocole UDP.
    auto local_address = local_socket_address(SOCK_DGRAM, m_serviceBeacon);
    int fd = socket(AF_INET, SOCK_DGRAM, 0); //Définition du socket
    bind(fd,(sockaddr *)& local_address, sizeof(local_address));//Bind entre le beacon et le serveur

    SendData data;
    while(true)
        if(read(fd, &data, sizeof data) == sizeof data)
            addData(data);

    close(fd);
}
