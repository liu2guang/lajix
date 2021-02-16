/**
 * MIT License Copyright (c) 2017 liu2guang
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 

/* 游戏精灵图片 */ 
class sprite
{
private:
    static SDL_Renderer *renderer; /* 静态成员 */ 
    SDL_Texture *texture; 
    SDL_Rect *crops; 

    int width, height;
    int f_width, f_height; 

public:
    int frames; 

    sprite(const char *path, int f_width, int f_height); 
    ~sprite(); 

    static void setRenderer(SDL_Renderer *renderer); 

    int getWidth(void);
    int getHeight(void);
    int getFrameWidth(void);
    int getFrameHeight(void);

    int render(int index, const SDL_Rect *rect = NULL, const double angle = 0.0, 
        const SDL_Point *center = NULL, const SDL_RendererFlip flip = SDL_FLIP_NONE); 
};

#endif /* __SPRITE_HPP__ */ 
