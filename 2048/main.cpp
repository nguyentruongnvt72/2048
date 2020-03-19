
#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include <cstdlib>
#include "graphics.h"
#include "xuly.h"
#include <vector>
#include <cmath>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[] = "2048";

void bandau(int a[6][6]){
    srand(time(NULL));
    int  x1, y1, x2, y2;
    x1=rand() % 4 + 1;
    y1=rand() % 4 + 1;
    do {
        x2=rand() % 4 + 1;
        y2=rand() % 4 +1;
    } while (x1==x2||y1==y2);
    a[x1][y1]=2;
    a[x2][y2]=2;
}
void hinh(SDL_Renderer *renderer, int a[6][6], vector<SDL_Texture *> ogiatri, int xi, int yi );
bool gameover(int a[6][6]){
    int g=0;
    int h=0;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            if(a[i][j] != 0){
                g++;
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(a[i][j] == a[i][j+1]){
                h++;
            }
        }
    }
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(a[j][i] == a[j+1][i]){
                h++;
            }
        }
    }
    if( g == 16 && h == 0) return true;
    else return false;
}
bool youWin(int a[6][6]){
    int b=0;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            if(a[i][j] == 2048 ) b++;
        }
    }
    if(b != 0 ){return  true;}
    else return  false;
}
int main(int argc, char* argv[])
{
    const int n=6;
    int a[n][n]={0};
    bandau(a);
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    vector<SDL_Texture *> ogiatri;
    ogiatri.push_back(loadTexture("hai.bmp", renderer));
    ogiatri.push_back(loadTexture("bon.bmp", renderer));
    ogiatri.push_back(loadTexture("tam.bmp", renderer));
    ogiatri.push_back(loadTexture("muoisau.bmp", renderer));
    ogiatri.push_back(loadTexture("bahai.bmp", renderer));
    ogiatri.push_back(loadTexture("sautu.bmp", renderer));
    ogiatri.push_back(loadTexture("mothaitam.bmp", renderer));
    ogiatri.push_back(loadTexture("hainamsau.bmp", renderer));
    ogiatri.push_back(loadTexture("nammothai.bmp", renderer));
    ogiatri.push_back(loadTexture("motohaibon.bmp", renderer));
    ogiatri.push_back(loadTexture("haiobontam.bmp", renderer));
    SDL_Texture *anhkhung = loadTexture("anhkhung.bmp", renderer);
    SDL_Texture *nen = loadTexture("nen.bmp", renderer);
    SDL_Texture *over = loadTexture("game.bmp", renderer);
    SDL_Texture *win = loadTexture("win.bmp", renderer);
    int iW, iH;
    SDL_QueryTexture(nen, NULL, NULL, &iW, &iH);
    int xi = SCREEN_WIDTH / 2 - iW / 2;
    int yi = SCREEN_HEIGHT / 2 - iH / 2;
    SDL_Event e;
    bool running = true;
    SDL_RenderClear(renderer);
    renderTexture(anhkhung, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderTexture(nen, renderer, xi, yi);
    hinh(renderer, a, ogiatri, xi, yi);
    SDL_RenderPresent(renderer);
    while (running)
    {
        SDL_Delay(100);
        renderTexture(anhkhung, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        renderTexture(nen, renderer, xi, yi);
        hinh(renderer, a, ogiatri, xi, yi);
        if(youWin(a) == true){
            renderTexture(win, renderer, xi, 0, 335, SCREEN_HEIGHT - 2*yi-205);
        }
        if(gameover(a) == true){
            renderTexture(over, renderer, xi, 0, 335, SCREEN_HEIGHT - 2*yi -205);
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&e) ) {
            if (e.type == SDL_QUIT) running = false;
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE||e.type == SDL_QUIT) running = false;
                else if (e.key.keysym.sym == SDLK_LEFT) left(a, n);
                else if (e.key.keysym.sym == SDLK_RIGHT) right(a, n);
                else if (e.key.keysym.sym == SDLK_UP) up(a, n);
                else if (e.key.keysym.sym == SDLK_DOWN) down(a, n);
                SDL_RenderClear(renderer);
            }
        }
    }
    waitUntilKeyPressed();
    for (int j = 0; j < 11; j++)
    {
        SDL_DestroyTexture(ogiatri[j]);
    }
    SDL_DestroyTexture(anhkhung);
    SDL_DestroyTexture(nen);
    SDL_DestroyTexture(over);
    SDL_DestroyTexture(win);
    quitSDL(window,renderer);
    return 0;
}
void hinh(SDL_Renderer *renderer, int a[6][6], vector<SDL_Texture *> ogiatri, int xi, int yi ){
    int b;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            if(a[i][j] != 0){
                b = log2(a[i][j]);
                renderTexture(ogiatri[b-1], renderer, xi + (j-1)*81 + 9 , yi + (i-1)*81 + 9) ;
            }
        }
    }
}






