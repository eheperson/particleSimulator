#include<ehe-lib/ehelib.h>


void speak(){
    cout<<"ello motherfucker"<<endl;
};

void stay(){
    system("Pause");
}

// void glfwTest(){
//     if (!glfwInit()){
//         cout<<"GLFW initialization is sucked"<<endl;
//     }else{
//         cout<<"GLFW initialization is not sucked"<<endl;
//     }
// }

void sdlTest(){
    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}
