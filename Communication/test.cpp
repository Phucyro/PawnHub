#include "Socket.hpp"
#include "BindSocket.hpp"

#include <string>

int main() {
  std::string message = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  try {
    BindSocket binding_socket;
    binding_socket.activate();
    Socket* client_socket = binding_socket.createSocket();
    client_socket->sendMessage(message);
    std::cout << "Done sending" << std::endl;
    sleep(50);
  }
  catch (std::runtime_error& error) {
    std::cout << error.what() << std::endl;
  }
}
