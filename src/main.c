#include "client/client.h" // This include every other files needed

int main(){
    App app;

    init(&app);

    Client client = { NULL, NULL, 10, 10, 300, 200};
    // Create window
    createWindow(&client, &app);
    
    run(&app);

    return 0;
}
