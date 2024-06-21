#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr) : quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer)
{
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    int screenWidth = 1280;
    int screenHeight = 720;

    /* x, y, theta coordinates */
    // if (state[0] < screenWidth / 2)
    // {
    //     q_x = (screenWidth / 2) + state[0];
    // }
    // else
    // {
    //     q_x = state[0] - (screenWidth / 2);
    // }

    // if (state[1] < screenHeight / 2)
    // {
    //     q_y = (screenHeight / 2) + state[1];
    // }
    // else
    // {
    //     q_y = state[1] - (screenHeight);
    // }
    q_x = screenWidth / 2 + state[0];
    q_y = screenHeight / 2 + state[1];
    // q_x = screenWidth - state[0];
    // q_y = state[1];
    q_theta = state[2];

    filledCircleColor(gRenderer.get(), q_x, q_y, 30, 0xc23499FF);
    SDL_Rect rect;
    rect.w = 50;
    rect.h = 20;
    rect.x = q_x - rect.w / 2;
    rect.y = q_y - rect.h / 2;

    SDL_SetRenderDrawColor(gRenderer.get(), 0xc2, 0x34, 0x99, 0xFF);
    SDL_RenderFillRect(gRenderer.get(), &rect);
    SDL_RenderDrawLine(gRenderer.get(), q_x - cos(q_theta) * 100, q_y - sin(q_theta) * 100, q_x + cos(q_theta) * 100, q_y + sin(q_theta) * 100);
}
