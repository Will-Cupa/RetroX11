#include "app/app.h" // This include every other files needed

int main(){
    App *app = malloc(sizeof(App));
    
    init(app);
    printf("Connected to display: %s\n", DisplayString(app->display));

    run(app);

    return 0;
}
