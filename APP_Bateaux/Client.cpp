#include "Client.h"

Client::Client(char* hostname, char* service) : m_hostname{hostname}, m_service{service}
{
}

void Client::makeRequestToServer()
{
    auto server_adress = remote_socket_address(m_hostname, SOCK_STREAM, m_service);
    int socket_reception = socket(AF_INET, SOCK_STREAM, 0);

    std::string data;
    while(true)
    {
        if (connect(socket_reception,(sockaddr *) &server_adress, sizeof server_adress) == 0) // Vérifie si la connexion c'est effectuée sans erreur
        {
            while(true)
            {
                if(recv(socket_reception, &data, sizeof data, 0)) // recv Permet de recevoir un message de la socket socket_reception
                {
                    std::cout << "Client :" << data << std::endl;

                }
                else
                {
                    std::cout << "Problème" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Problème de connexion" << std::endl;
        }

        std::this_thread::sleep_for((std::chrono::seconds)5);
    }

    close(socket_reception);
}
