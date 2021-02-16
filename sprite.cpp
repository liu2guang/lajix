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
#include "sprite.hpp"
#include <stdio.h>

SDL_Renderer *sprite::renderer = nullptr;

sprite::sprite(const char *path, int f_width, int f_height)
{
    SDL_Surface *surface = IMG_Load(path); 
    this->width = surface->w; 
    this->height = surface->h; 
    this->f_width = f_width; 
    this->f_height = f_height; 
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
    SDL_FreeSurface(surface); 

    frames = (width/f_width) * (height/f_height); 
    crops = (SDL_Rect *)malloc(sizeof(SDL_Rect) * frames); 

    for(int index = 0; index < frames; index++)
    {
        crops[index].x = (index % (width/f_width)) * f_width; 
        crops[index].y = (index / (width/f_width)) * f_height; 
        crops[index].w = f_width; 
        crops[index].h = f_height; 
    }
}

sprite::~sprite()
{
    free(crops); 
    SDL_DestroyTexture(texture); 
}

/* static */ 
void sprite::setRenderer(SDL_Renderer *renderer)
{
    sprite::renderer = renderer; 
}

int sprite::getWidth(void)
{
    return this->width; 
}

int sprite::getHeight(void)
{
    return this->height; 
}

int sprite::getFrameWidth(void)
{
    return this->f_width; 
}

int sprite::getFrameHeight(void)
{
    return this->f_height; 
}

int sprite::render(int index, const SDL_Rect *rect, const double angle, 
    const SDL_Point *center, const SDL_RendererFlip flip)
{
    SDL_Rect _rect = {0, 0, f_width, f_height}; 

    if(index >= frames)
    {
        return -1;
    }

    if(rect)
    {
        _rect.x = rect->x; 
        _rect.y = rect->y;
        _rect.w = rect->w == 0 ? f_width  : rect->w;
        _rect.h = rect->h == 0 ? f_height : rect->h;
    }

    return SDL_RenderCopyEx(renderer, texture, &crops[index], &_rect, angle, center, flip);
}
