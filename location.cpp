#include <iostream>
#include <string>

using namespace std;

bool checkConnectionToLaarlaServer(const string &server);
void getLocation();

int main() {
  // Проверка соединения через проводную сеть
  if (checkConnectionToLaarlaServer("laarl.com")) {
    cout << "Есть подключение через проводную сеть." << endl;
    getLocation();
  }
  // Проверка соединения через беспроводную сеть, если проводная сеть недоступна
  else if (checkConnectionToLaarlaServer("google.com")) {
    cout << "Подключение осуществляется через беспроводную сеть." << endl;
    getLocation();
  }
  // Нет соединения
  else {
    cout << "Соединение с сетью недоступно." << endl;
  }

  return 0;
}

// Функция для проверки подключения к серверу Laarla
bool checkConnectionToLaarlaServer(const string &server) {
  string command = "ping -c 1 " + server;
  int result = system(command.c_str());
  return result == 0;
}

// Функция для получения расположения
void getLocation() {
  cout << "Ваша страна и город:\n";
  system("curl -s ipinfo.io | jq -r '.country, .city'");
}
