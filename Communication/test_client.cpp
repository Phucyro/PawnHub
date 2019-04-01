#include "Socket.hpp"

#include <string>

int main() {
  try {
    Socket* socket = new Socket;
    socket->connectToServer("frawni-thinks");
    std::string message = socket->receiveMessage();
    std::cout << message << std::endl;
  }
  catch (std::runtime_error& error) {
    std::cout << error.what() << std::endl;
  }
}
