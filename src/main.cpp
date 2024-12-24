// File: main.cpp
#include <iostream>
#include "deribit_api.h"

int main() {
    const std::string client_id = "b9aW1G2c";
    const std::string client_secret = "IwcxPplHfoN-O3wiotPoHzdrCaRaZ8GgnkrXIT8hSq8";

    DeribitAPI api(client_id, client_secret);
    
    if (api.authenticate()) {
        std::cout << "API call successful!" << std::endl;
    } else {
        std::cerr << "API call failed!" << std::endl;
    }

    return 0;
}