//
//  graphics.h
//  2048
//
//  Created by Truong Nguyen on 5/13/18.
//  Copyright © 2018 Truong Nguyen. All rights reserved.
//

#ifndef graphics_h
#define graphics_h
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
using namespace  std;

/* dohoa_hpp */

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, int screenWidth, int screenHeight, const char* windowTitle);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
//**************************************************************

// Hai hàm về texture, lấy nguyên về từtutorial tại:
// http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-2-dont-put-everything-in-main

// Hàm nạp texture từ file ảnh, để vẽ lên renderer tương ứng
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

// Hàm đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và giữ nguyên kích cỡ ban đầu của ảnh
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

// Hàm (cùng trên nhưng khác tham số với hàm ngay trên)
// đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và
// với kích cỡ rộng (w) và cao (h) cho trước.
// Ảnh sẽ được co dãn (phóng to thu nhỏ) cho khớp kích cỡ này.
// Đây là hàm không có trong tutorial ban đầu, được sửa từ hàm trong tutorial.
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void dohoa( SDL_Window* window,  SDL_Renderer* renderer, int screenWidth, int screenHeight,  vector<SDL_Texture *> ogiatri, int vtx, int vty, int vtnumber, int vt1x, int vt1y, int vt1number );


#endif /* graphics_h */
