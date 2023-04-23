//#include <SDL.h>
//#include <vector>
//#include <algorithm>
//
//// Particle class
//class Particle
//{
//public:
//    Particle(int x, int y, int lifetime, Uint32 color)
//        : x(x), y(y), lifetime(lifetime), color(color)
//    {
//    }
//
//    void update()
//    {
//        lifetime--;
//    }
//
//    void render(SDL_Renderer* renderer)
//    {
//        SDL_SetRenderDrawColor(renderer, (color >> 24) & 0xFF, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
//        SDL_RenderDrawPoint(renderer, x, y);
//    }
//
//    bool isAlive() const
//    {
//        return lifetime > 0;
//    }
//
//private:
//    int x;
//    int y;
//    int lifetime;
//    Uint32 color;
//};
//
//int main(int argc, char* argv[])
//{
//    // Initialize SDL
//    if (SDL_Init(SDL_INIT_VIDEO) != 0)
//    {
//        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
//        return 1;
//    }
//
//    // Create window
//    SDL_Window* window = SDL_CreateWindow("Particle System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
//    if (!window)
//    {
//        SDL_Log("Failed to create window: %s", SDL_GetError());
//        SDL_Quit();
//        return 1;
//    }
//
//    // Create renderer
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (!renderer)
//    {
//        SDL_Log("Failed to create renderer: %s", SDL_GetError());
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//
//    // Particle variables
//    std::vector<Particle> particles;
//    int particleLifetime = 100;
//    Uint32 particleColor = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 255, 255);
//
//    // Main loop
//    bool quit = false;
//    SDL_Event event;
//    while (!quit)
//    {
//        while (SDL_PollEvent(&event))
//        {
//            if (event.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
//            {
//                // Generate particles in a single burst
//                int x = event.button.x;
//                int y = event.button.y;
//                for (int i = 0; i < 100; i++)
//                {
//                    int lifetime = particleLifetime + rand() % 100;
//                    Uint32 color = particleColor;
//                    particles.emplace_back(x, y, lifetime, color);
//                }
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a)
//            {
//                // Decrease particle lifetime
//                particleLifetime -= 10;
//                if (particleLifetime < 0)
//                {
//                    particleLifetime = 0;
//                }
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d)
//            {
//                // Increase particle lifetime
//                particleLifetime += 10;
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
//            {
//                // Set particle color to red
//                particleColor = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 255, 0, 0);
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_g)
//            {
//                // Set particle color to green
//                particleColor = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 0, 255, 0);
//            }
//            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_b)
//            {
//                // Set particle color to blue
//                particleColor = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), 0, 0, 255);
//            }
//        }
//
//        // Clear the renderer
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//
//        // Update and render particles
//        for (auto it = particles.begin(); it != particles.end();)
//        {
//            it->update();
//            it->render(renderer);
//            if (!it->isAlive())
//            {
//                it = particles.erase(it);
//            }
//            else
//            {
//                ++it;
//            }
//        }
//
//        // Update the screen
//        SDL_RenderPresent(renderer);
//    }
//
//    // Cleanup
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <SDL.h>



//// Particle class
//class Particle
//{
//public:
//    Particle(int x, int y, int velX, int velY, Uint32 color, int size, int sizeGrowth)
//        : m_x(x), m_y(y), m_velX(velX), m_velY(velY), m_color(color), m_size(size), m_sizeGrowth(sizeGrowth) {}
//
//    void update()
//    {
//        m_x += m_velX;
//        m_y += m_velY;
//        m_size += m_sizeGrowth;  // Update size based on size growth rate
//    }
//
//    void render(SDL_Renderer* renderer)
//    {
//        SDL_SetRenderDrawColor(renderer, (m_color >> 16) & 0xFF, (m_color >> 8) & 0xFF, m_color & 0xFF, 0xFF);
//        SDL_Rect rect = { m_x, m_y, m_size, m_size };
//        SDL_RenderFillRect(renderer, &rect);
//    }
//
//private:
//    int m_x;
//    int m_y;
//    int m_velX;
//    int m_velY;
//    Uint32 m_color;
//    int m_size;
//    int m_sizeGrowth;
//};
//
//int main(int argc, char* argv[])
//{
//    // Initialize SDL2
//    if (SDL_Init(SDL_INIT_VIDEO) != 0)
//    {
//        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    // Create window and renderer
//    SDL_Window* window = SDL_CreateWindow("SDL2 Particle Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
//    if (window == nullptr)
//    {
//        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
//        SDL_Quit();
//        return 1;
//    }
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if (renderer == nullptr)
//    {
//        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
//        SDL_DestroyWindow(window);
//        SDL_Quit();
//        return 1;
//    }
//    // Create particles
//    std::vector<Particle> particles;
//    for (int i = 0; i < 1000; ++i)
//    {
//        int x = rand() % 800;
//        int y = rand() % 600;
//        int velX = rand() % 3 - 1;
//        int velY = (rand() % 3 - 1) - 10;
//        Uint32 color = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), rand() % 256, rand() % 256, rand() % 256);
//        int size = rand() % 5 + 1;  // Initial size of particle
//        int sizeGrowth = rand() % 3 + 1;  // Size growth rate of particle
//        particles.emplace_back(x, y, velX, velY, color, size, sizeGrowth);
//    }
//
//    // Main loop
//    bool isMousePressed = false;
//    bool quit = false;
//    while (!quit)
//    {
//
//        SDL_Event event;
//        while (SDL_PollEvent(&event))
//        {
//            if (event.type == SDL_QUIT)
//            {
//                quit = true;
//                break;
//            }
//            else if (event.type == SDL_MOUSEBUTTONDOWN)
//            {
//                if (event.button.button == SDL_BUTTON_LEFT)
//                {
//                    isMousePressed = true;
//                }
//            }
//            else if (event.type == SDL_MOUSEBUTTONUP)
//            {
//                if (event.button.button == SDL_BUTTON_LEFT)
//                {
//                    isMousePressed = false;
//                }
//            }
//        }
//        if (isMousePressed)
//        {
//            int x = event.button.x;
//            int y = event.button.y;
//            int velX = rand() % 3 - 1;
//            int velY = (rand() % 3 - 1) - 10;
//            Uint32 color = SDL_MapRGB(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), rand() % 256, rand() % 256, rand() % 256);
//            int size = rand() % 5 + 1;
//            int sizeGrowth = rand() % 3 + 1;
//            particles.emplace_back(x, y, velX, velY, color, size, sizeGrowth);
//        }
//
//
//        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//        SDL_RenderClear(renderer);
//
//        for (auto& particle : particles)
//        {
//            particle.update();
//            particle.render(renderer);
//        }
//
//        SDL_RenderPresent(renderer);
//        SDL_Delay(10);
//    }
//
//    // Cleanup
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <SDL.h>
//
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
//class Particle
//{
//public:
//    Particle(int x, int y)
//        : x_(x), y_(y), vel_x_(0), vel_y_(0), size_(2), alpha_(255)
//    {
//        // Randomize initial velocity
//        std::mt19937 rng(std::time(0));
//        std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
//        vel_x_ = 0;
//        vel_y_ = -dist(rng) * 6;
//    }
//
//    void update();
//    void render(SDL_Renderer* renderer);
//
//    bool is_faded() const
//    {
//        return alpha_ <= 0;
//    }
//
//private:
//    int x_;
//    int y_;
//    float vel_x_;
//    float vel_y_;
//    float size_;
//    int alpha_;
//};
//
//void Particle::update()
//{
//    x_ += vel_x_;
//    y_ += vel_y_;
//    alpha_ -= 2;
//    size_ += 0.1;
//}
//
//void Particle::render(SDL_Renderer* renderer)
//{
//    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
//    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, alpha_);
//    SDL_Rect rect = { x_ - size_ / 2, y_ - size_ / 2, size_, size_ };
//    SDL_RenderFillRect(renderer, &rect);
//}
//
//int main(int argc, char* args[])
//{
//    SDL_Init(SDL_INIT_VIDEO);
//
//    SDL_Window* window = SDL_CreateWindow("Fire Particle System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//    std::vector<Particle> particles;
//
//    bool quit = false;
//    SDL_Event event;
//
//    while (!quit)
//    {
//        while (SDL_PollEvent(&event) != 0)
//        {
//            if (event.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//        }
//
//        int mouse_x, mouse_y;
//        SDL_GetMouseState(&mouse_x, &mouse_y);
//
//        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
//        {
//            particles.push_back(Particle(mouse_x, mouse_y));
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//        SDL_RenderClear(renderer);
//
//        for (auto it = particles.begin(); it != particles.end();)
//        {
//            it->update();
//            if (it->is_faded())
//            {
//                it = particles.erase(it);
//            }
//            else
//            {
//                it->render(renderer);
//                ++it;
//            }
//        }
//
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <SDL.h>
//
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
//class Particle
//{
//public:
//    Particle(int x, int y)
//        : x_(x), y_(y), vel_x_(0), vel_y_(0), size_(2), alpha_(255)
//    {
//        // Randomize initial velocity
//        std::mt19937 rng(std::time(0));
//        std::uniform_real_distribution<float> dist(-2.0f, 2.0f);
//        vel_x_ = dist(rng);
//        vel_y_ = dist(rng);
//    }
//
//    void update();
//    void render(SDL_Renderer* renderer);
//
//    bool is_faded() const
//    {
//        return alpha_ <= 0;
//    }
//
//private:
//    int x_;
//    int y_;
//    float vel_x_;
//    float vel_y_;
//    float size_;
//    int alpha_;
//};
//
//void Particle::update()
//{
//    x_ += vel_x_;
//    y_ += vel_y_;
//    vel_x_ *= 0.98;
//    vel_y_ *= 0.98;
//    alpha_ -= 2;
//    size_ += 0.1;
//}
//
//void Particle::render(SDL_Renderer* renderer)
//{
//    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
//    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, alpha_);
//    SDL_Rect rect = { x_ - size_ / 2, y_ - size_ / 2, size_, size_ };
//    SDL_RenderFillRect(renderer, &rect);
//}
//
//int main(int argc, char* args[])
//{
//    SDL_Init(SDL_INIT_VIDEO);
//
//    SDL_Window* window = SDL_CreateWindow("Explosion Particle System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//    std::vector<Particle> particles;
//
//    bool quit = false;
//    SDL_Event event;
//
//    while (!quit)
//    {
//        while (SDL_PollEvent(&event) != 0)
//        {
//            if (event.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
//            {
//                int mouse_x, mouse_y;
//                SDL_GetMouseState(&mouse_x, &mouse_y);
//                for (int i = 0; i < 100; ++i)
//                {
//                    particles.push_back(Particle(mouse_x, mouse_y));
//                }
//            }
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//        SDL_RenderClear(renderer);
//
//        for (auto it = particles.begin(); it != particles.end();)
//        {
//            it->update();
//            if (it->is_faded())
//            {
//                it = particles.erase(it);
//            }
//            else
//            {
//                it->render(renderer);
//                ++it;
//            }
//        }
//
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}




//SMOKE PARTICLE



//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <cmath>
//#include <SDL.h>
//
//const int SCREEN_WIDTH = 800;
//const int SCREEN_HEIGHT = 600;
//
//class Particle
//{
//public:
//    Particle(int x, int y)
//        : x_(x), y_(y), vel_x_(0), vel_y_(-1), size_(5), angle_(0), alpha_(255), max_lifetime_(255)
//    {
//        // Randomize initial angular velocity
//        std::mt19937 rng(std::time(0));
//        std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
//        ang_vel_ = dist(rng) * 0.1;
//    }
//
//    void update();
//    void render(SDL_Renderer* renderer);
//
//    bool is_faded() const
//    {
//        return alpha_ <= 0;
//    }
//
//private:
//    int x_;
//    int y_;
//    float vel_x_;
//    float vel_y_;
//    float size_;
//    float angle_;
//    float ang_vel_;
//    int alpha_;
//    int max_lifetime_;
//};
//
//void Particle::update()
//{
//    x_ += vel_x_;
//    y_ += vel_y_;
//    angle_ += ang_vel_;
//    vel_x_ *= 0.98;
//    vel_y_ *= 0.98;
//    alpha_ -= 1;
//    max_lifetime_ -= 1;
//
//    // Spread particles slightly
//    std::mt19937 rng(std::time(0));
//    std::uniform_real_distribution<float> dist(-0.1f, 0.1f);
//    vel_x_ += dist(rng);
//    x_ += dist(rng);
//}
//
//void Particle::render(SDL_Renderer* renderer)
//{
//    int r = 255;
//    int g = 255;
//    int b = 255;
//
//    // Change colors from white to transparent
//    r = static_cast<int>(static_cast<float>(max_lifetime_) / 255.0f * 255.0f);
//    g = static_cast<int>(static_cast<float>(max_lifetime_) / 255.0f * 255.0f);
//    b = static_cast<int>(static_cast<float>(max_lifetime_) / 255.0f * 255.0f);
//    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
//    SDL_SetRenderDrawColor(renderer, r, g, b, alpha_);
//    SDL_Rect rect = { x_ - size_ / 2, y_ - size_ / 2, size_, size_ };
//    SDL_RenderDrawRect(renderer, &rect);
//}
//
//int main(int argc, char* args[])
//{
//    SDL_Init(SDL_INIT_VIDEO);
//
//    SDL_Window* window = SDL_CreateWindow("Sparkle Particle System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//    std::vector<Particle> particles;
//
//    bool quit = false;
//    SDL_Event event;
//
//    while (!quit)
//    {
//        while (SDL_PollEvent(&event) != 0)
//        {
//            if (event.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
//            {
//                int mouse_x, mouse_y;
//                SDL_GetMouseState(&mouse_x, &mouse_y);
//
//                // Create particles at mouse position
//                for (int i = 0; i < 100; ++i)
//                {
//                    particles.push_back(Particle(mouse_x, mouse_y));
//                }
//            }
//        }
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//
//        for (auto& particle : particles)
//        {
//            particle.update();
//            particle.render(renderer);
//        }
//
//        // Remove faded particles
//        particles.erase(std::remove_if(particles.begin(), particles.end(), [](const Particle& p) {
//            return p.is_faded();
//            }), particles.end());
//
//        SDL_RenderPresent(renderer);
//    }
//
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <SDL.h>

const int SCREEN_WIDTH = 1920;  // Screen width
const int SCREEN_HEIGHT = 1080; // Screen height
const int PARTICLE_SIZE = 5;   // Particle size
const float MAX_VELOCITY = 0.05f;    // Maximum particle velocity
const int FADE_DELAY = 1000;   // Fade delay in milliseconds
const int SPREAD_FACTOR = 55;


class Particle
{
public:
    Particle(int x, int y) : x(x), y(y)
    {

        float angle = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2.0f * M_PI; // Random angle between 0 and 2 * pi
        float speed = static_cast<float>(rand()) / RAND_MAX; // Random speed
        float spread = static_cast<float>(rand()) / RAND_MAX * SPREAD_FACTOR; // Random spread factor between 0 and spreadFactor

        // Calculate velocity components based on angle, speed, and spread factor
        velocity_x = cos(angle) * (speed + spread);
        velocity_y = sin(angle) * (speed + spread);
        velocity_x *= 0.99; // 1% reduction in x-velocity per update
        velocity_y *= 0.99; // 1% reduction in y-velocity per update


        age = 0;
        r = 255;
        g = 255;
        b = 255;
    }

    void update()
    {

        x += MAX_VELOCITY * velocity_x;
        y += MAX_VELOCITY * velocity_y;
        ++age;
    }

    void render(SDL_Renderer* renderer)
    {
        SDL_Rect rect = { x, y, PARTICLE_SIZE, PARTICLE_SIZE };
        int alpha = 255 - (age * 255) / FADE_DELAY;
        SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
        SDL_RenderFillRect(renderer, &rect);
    }

    bool isFaded()
    {
        return age >= FADE_DELAY;
    }

private:
    float x;
    float y;
    int velocity_x;
    int velocity_y;
    int age;
    int r;
    int g;
    int b;
};

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    std::vector<Particle> particles;
    int num_particles = 1000; // Number of particles

    bool quit = false;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouse_x = event.button.x;
                int mouse_y = event.button.y;
                for (int i = 0; i < num_particles; ++i)
                {
                    Particle particle(mouse_x, mouse_y);
                    particles.push_back(particle);
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < particles.size(); ++i)
        {
            particles[i].update();
            particles[i].render(renderer);
            if (particles[i].isFaded())
            {
                particles.erase(particles.begin() + i);
                --i;
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


