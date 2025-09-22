#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <windows.h>
#include<vector>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <SDL2/SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
const int screen_width = 1520;
//const int screen_width = 1500 ;
//const int screen_height = 1200 ;
const int screen_height = 800;

SDL_Window *window;
SDL_Renderer *renderer;
//SDL_Surface * window_surface;

int XMouse;
int YMouse;
bool main_while = true;

struct point {
    float x;
    float y;
};
struct Color {
    int r;
    int g;
    int b;
};

Color black = Color{0, 0, 0};
Color white = Color{255, 255, 255};
Color grey = Color{128, 128, 128};
Color red = Color{255, 0, 0};
Color blue = Color{0, 0, 255};
Color green = Color{0, 255, 0};
Color Base = Color{235, 234, 216};
Color yellow = Color{255, 255, 00};
Color color1 = black;
UINT32 codeColor1 = ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) + (color1.r & 0xff);
Color color2 = white;
Color Erase_color;
UINT32 codeColor2 = ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) + (color2.r & 0xff);

void window_color(SDL_Renderer *Renderer, int R, int G, int B);

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian);

int initialize_window();

void add_background(string);

void DestroyEvrytings();

void texture(SDL_Renderer *renderer, int x, int y, string addres, int width, int height);

bool check_quit();

void get_frame_events();

void main2();

void
DrawDottedLine(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 thick, Uint32 Color, int e);

void tringlee (SDL_Renderer * renderer , int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int size ) ;

void rect2(SDL_Renderer *renderer , int x1 , int y1 , int x2 , int y2 , int R , int g , int b , int size);

//myvec = new vector<SDL_Event> ;
vector<SDL_Event> frame_Event;
vector<vector<int>> Mouse_Couredinate(2) ;
vector<SDL_Event> Not_delete;
SDL_Point mouse_point;
SDL_Point mouse_point_First;

float size_of_pen = 8;
bool circle = false, filled_circle = false, rectt = false, filled_rect = false , tringle = false , filled_tringle = false ,
        ellip = false , filled_ellip = false ,arect = false , filled_aarect = false;
bool line1 = false, line1over = false, line2 = false, line2over = false, color = false, Dotted = false, over = false,
        pen = false, pen2 = false, pen3 = false, penDop = false, Erase = false, pen4 = false, rotate_rect = false,
        first_point1 = false, secend_point = false, third_point = false, fourth_point = false, get_point = false;


int main(int argc, char *argv[]) {
    initialize_window();
    window_color(renderer, 255, 0, 0);
    window_color(renderer, 0, 100, 0);

    while (main_while&&check_quit()) {
        get_frame_events();
        window_color(renderer, 155, 155, 155);
        add_background("download (2).jpg");
        textRGBA(renderer, screen_width / 2 - 300, screen_height / 2, "Click to GOOOOOO!", "arial.ttf", 80, color1.r,
                 color1.g, color1.b, 255);
        for (SDL_Event e: frame_Event) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                main_while = false;
            }
        }
    }
    main_while = true;
    add_background("img1.jpg");


    rect(renderer, 80, 22, 30, 30, grey.r, grey.g, grey.b, 1);
    rect(renderer, 75, 75, 40, 40, grey.r, grey.g, grey.b, 0); // paint screen
    rect(renderer, 17, 75, 40, 40, grey.r, grey.g, grey.b, 0); // Erase
    rect(renderer, 20, 200, 40, 40, grey.r, grey.g, grey.b, 0); // pen
    rect(renderer, 75, 197, 40, 40, grey.r, grey.g, grey.b, 0); // Dopped pen
    texture(renderer,75 , 197 , "images (1).jpg" , 40 , 40);

    rect(renderer, 20, 315, 40, 40, grey.r, grey.g, grey.b, 0); // Right Line
    rect(renderer, 75, 315, 40, 40, grey.r, grey.g, grey.b, 0); // Over Line
    rect(renderer, 20, 260, 40, 40, grey.r, grey.g, grey.b, 0); // Right Line Addet
    texture(renderer,20 , 260 , "download (4).jpg" , 40 , 40);

    rect(renderer, 75, 260, 40, 40, grey.r, grey.g, grey.b, 0); // over Line Addet
    texture(renderer,75 , 260 , "download (3).jpg" , 40 , 40);

    rect(renderer, 75, 436, 40, 40, grey.r, grey.g, grey.b, 0); // circle
    texture(renderer,75 , 436 , "images (1)23.jpg" , 40 , 40);

    rect(renderer, 18, 436, 40, 40, grey.r, grey.g, grey.b, 0); // aarect
    texture(renderer,18 , 436 , "download.png" , 40 , 40);

    rect(renderer, 75, 377, 40, 40, grey.r, grey.g, grey.b, 0); // tringle
    texture(renderer,75 , 377 , "rectangle2.jpg" , 40 , 40);

    rect(renderer, 18, 377, 40, 40, grey.r, grey.g, grey.b, 0); // rect
    rect(renderer, 67, 600, 40, 40, grey.r, grey.g, grey.b, 0); // filled circle
    texture(renderer,67 , 600 , "download (1).jpg" , 40 , 40);

    rect(renderer, 29, 540, 40, 40, grey.r, grey.g, grey.b, 0); // filled rect
    texture(renderer,29 , 540 , "filled rect.png" , 40 , 40);

    rect(renderer, 29, 600, 40, 40, grey.r, grey.g, grey.b, 0); // filled aarect
    texture(renderer,29 , 600 , "download.png" , 40 , 40);

    rect(renderer, 67, 540, 40, 40, grey.r, grey.g, grey.b, 0); // filled tringle
    texture(renderer,67 , 540 , "rectangle.jpg" , 40 , 40);

    rect(renderer, 20, 135, 40, 40, grey.r, grey.g, grey.b, 0); // rotate rect
    texture(renderer,20 , 135 , "rotate rect.jpg" , 40 , 40);


    rect(renderer, 130, 0, 1390, 680, 255, 255, 255, 1); //main rect
    Erase_color = white;
    rect(renderer, 5, 690, 600, 100, Base.r, Base.g, Base.b, 1);
    rect(renderer, 1500, 660, 120, 120, Base.r, Base.g, Base.b, 1);
    rect(renderer, 10, 10, 120, 50, Base.r, Base.g, Base.b, 1);
    rect(renderer, 70, 135, 50, 50, Base.r, Base.g, Base.b, 1);

    rect(renderer, 1000, 700, 30, 30, black.r, black.g, black.b, 1);
    rect(renderer, 1040, 700, 30, 30, red.r, red.g, red.b, 1);
    rect(renderer, 1080, 700, 30, 30, blue.r, blue.g, blue.b, 1);
    rect(renderer, 1120, 700, 30, 30, grey.r, grey.g, grey.b, 1);
    rect(renderer, 1160, 700, 30, 30, white.r, white.g, white.b, 1);
    rect(renderer, 1200, 700, 30, 30, green.r, green.g, green.b, 1);
    rect(renderer, 1240, 700, 30, 30, yellow.r, yellow.g, yellow.b, 1);

    SDL_RenderDrawPoint(renderer, 600, 300);
    SDL_RenderPresent(renderer);

    while (main_while && check_quit()) {
        rect(renderer, 30, 720, 30, 30, color2.r, color2.g, color2.b, 1);
        rect(renderer, 10, 700, 30, 30, color1.r, color1.g, color1.b, 1);

        //size
        thickLineRGBA(renderer, 220, 790, 220, 700, 2, color1.r, color1.g, color1.b, 255); // 1
        thickLineRGBA(renderer, 250, 790, 250, 700, 5, color1.r, color1.g, color1.b, 255); // 2
        thickLineRGBA(renderer, 290, 790, 290, 700, 10, color1.r, color1.g, color1.b, 255);//3
        thickLineRGBA(renderer, 335, 790, 335, 700, 15, color1.r, color1.g, color1.b, 255); //4
        thickLineRGBA(renderer, 395, 790, 395, 700, 20, color1.r, color1.g, color1.b, 255); //5
        thickLineRGBA(renderer, 460, 790, 460, 700, 25, color1.r, color1.g, color1.b, 255); //6
        thickLineRGBA(renderer, 535, 790, 535, 700, 30, color1.r, color1.g, color1.b, 255); //7
        //size
        rect(renderer, 210, 690, 20, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 240, 690, 25, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 275, 690, 30, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 320, 690, 35, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 375, 690, 40, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 440, 690, 45, 110, color2.r, color2.g, color2.b, 0);
        rect(renderer, 510, 690, 50, 110, color2.r, color2.g, color2.b, 0);

        SDL_RenderPresent(renderer);
        get_frame_events();
        SDL_GetMouseState(&XMouse, &YMouse);

        for (SDL_Event e: frame_Event) {
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 30 && XMouse <= 60 && YMouse >= 720 && YMouse <= 750)
            {Color temp = color1;color1 = color2 ;color2 = temp; }
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 10 && XMouse <= 40 && YMouse >= 700 && YMouse <= 730)
            {Color temp = color1;color1 = color2 ;color2 = temp; }
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                line2) {
                if (e.button.button == SDL_BUTTON_LEFT) {Not_delete.push_back(e) ;Mouse_Couredinate[0].push_back(XMouse);
                    Mouse_Couredinate[1].push_back(YMouse);
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g,
                                      color1.b, 255);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                    line2 = false;
                    Dotted = false;
                }
            }//draw right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                line2over) {
                if (e.button.button == SDL_BUTTON_LEFT) {Not_delete.push_back(e) ;
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g, color1.b, 255);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                }
            }//draw  over  right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && line2over) {
                if (e.button.button == SDL_BUTTON_RIGHT) {Not_delete.push_back(e) ;
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point_First.x, mouse_point_First.y, XMouse, YMouse, size_of_pen,
                                       codeColor1, 5);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
//                        mouse_point.x = XMouse;
//                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point_First.x, mouse_point_First.y, XMouse, YMouse, size_of_pen,
                                      color1.r, color1.g, color1.b, 255);
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g, color1.b, 255);
//                        mouse_point.x = XMouse;
//                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                    line2over = false;
                    Dotted = false;
                }
            }//End draw  over  right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && line1) {Not_delete.push_back(e) ;
                Mouse_Couredinate[0].push_back(XMouse);
                Mouse_Couredinate[1].push_back(YMouse);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                line2 = true;
                line1 = false;
            }//get first point for right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && line1over) {Not_delete.push_back(e) ;
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                mouse_point_First.x = XMouse;
                mouse_point_First.y = YMouse;
                line2over = true;
                line1over = false;
            }//get first point for over
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 315 && YMouse <= 355) {
                Not_delete.push_back(e) ;
                Mouse_Couredinate[0].push_back(XMouse);
                Mouse_Couredinate[1].push_back(YMouse);
                line1 = true;
                line2 = false;
            } //!Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 260 && YMouse <= 300) {
                Not_delete.push_back(e) ;
                line1 = true;
                line2 = false;
                Dotted = true;
            } //Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 260 && YMouse <= 300) {
                Not_delete.push_back(e) ;
                line1over = true;
                Dotted = true;
            } //over Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 315 && YMouse <= 355) {
                Not_delete.push_back(e) ;
                line1over = true;
            } //over !Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 75 && YMouse <= 115) {
                rect(renderer, 150, 0, 1390, 660, color2.r, color2.g, color2.b, 1);
                Erase_color = color2;
                main2() ;
            }// change color screen
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 200 && YMouse <= 240) {
                Not_delete.push_back(e) ;
                pen = true;
            }//true Pen drawing
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 197 && YMouse <= 237) {
                Not_delete.push_back(e) ;
                penDop = true;
                pen = true;
            }//true Pen Dop drawing
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen) {Not_delete.push_back(e) ;
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                pen = false;
                if (penDop) pen3 = true;
                else if (Erase) pen4 = true;
                else pen2 = true;
            } // get first loc
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen2) {
                Not_delete.push_back(e) ;
                thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r, color1.g,
                              color1.b, 255);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // draw pen
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen4) {
                Not_delete.push_back(e) ;
                thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, Erase_color.r,
                              Erase_color.g, Erase_color.b, 255);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // ERAse pen
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen3) {
                Not_delete.push_back(e) ;
                UINT32 codeColor1 =
                        ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                        (color1.r & 0xff);
                DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1, 2);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // draw dotted pen
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660) {
                Not_delete.push_back(e) ;
                \
            pen = false;
                pen2 = false;
                pen3 = false;
                penDop = false;
                pen4 = false;
            } // End pen
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 17 && XMouse <= 57 && YMouse >= 75 && YMouse <= 115) {
                Not_delete.push_back(e) ;
                pen = true;
                Erase = true;
            } //true start erasing
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 18 && XMouse <= 58 && YMouse >= 377 && YMouse <= 417) {
                Not_delete.push_back(e) ;
                get_point = true;
                first_point1 = false;
                rectt = true;
                continue;
            } //rect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 18 && XMouse <= 58 && YMouse >= 436 && YMouse <= 476) {
                Not_delete.push_back(e) ;
                get_point = true;
                first_point1 = false;
                arect = true;
                continue;
            } //aarect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 29 && XMouse <= 69 && YMouse >= 600 && YMouse <= 640) {
                Not_delete.push_back(e) ;
                get_point = true;
                first_point1 = false;
                filled_aarect = true;
                continue;
            } //filled_aarect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 67 && XMouse <= 107 && YMouse >= 540 && YMouse <= 580) {
                Not_delete.push_back(e) ;
                get_point = true;
                first_point1 = false;
                filled_tringle = true;
                continue;
            } //filled tringle
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 377 && YMouse <= 417) {
                Not_delete.push_back(e) ;
                get_point = true;
                first_point1 = false;
                tringle = true;
                continue;
            } //tringle
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 436 && YMouse <= 476) {
                Not_delete.push_back(e) ;
                get_point = true;
                circle = true;
                continue;
            } //circle
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 29 && XMouse <= 69 && YMouse >= 540 && YMouse <= 580) {
                Not_delete.push_back(e) ;
                get_point = true;
                filled_rect = true;
                continue;
            } //filled_rect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 135 && YMouse <= 175) {
                Not_delete.push_back(e) ;
                get_point = true;
                rotate_rect = true;
                continue;
            } //rotate_rect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 67 && XMouse <= 107 && YMouse >= 600 && YMouse <= 640) {
                Not_delete.push_back(e) ;
                get_point = true;
                filled_circle = true;
                continue;
            } //filled_circle
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && get_point) {
                Not_delete.push_back(e) ;
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                first_point1 = true;
                get_point = false;
                continue;
            } // one point for rect or circle or aarect
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && first_point1) {
                Not_delete.push_back(e) ;
                first_point1 = false;
                get_point = false;
                mouse_point_First.x = XMouse ;
                mouse_point_First.y = YMouse ;
                if (rectt) {
                    rect(renderer , mouse_point.x , mouse_point.y , XMouse - mouse_point.x  , YMouse - mouse_point.y  , color1.r , color1.g , color1.b , 0);
                    SDL_RenderPresent(renderer) ;
                    rectt = false ;}
                float r =  sqrt((XMouse - mouse_point.x)*(XMouse - mouse_point.x) + (YMouse - mouse_point.y)*(YMouse - mouse_point.y));
                if (circle) {
                    if ( mouse_point.x + r <=1520 && mouse_point.x-r>=130 && mouse_point.y -r >= 0&& mouse_point.y + r <=680){
                        ellipseRGBA(renderer , mouse_point.x , mouse_point.y , sqrt((XMouse - mouse_point.x)*(XMouse - mouse_point.x) + (YMouse - mouse_point.y)*(YMouse - mouse_point.y)) ,
                                    r , color1.r , color1.g , color1.b ,255 ) ;}
                    circle = false ;
                }
                else if (filled_rect){

                    rect(renderer , mouse_point.x , mouse_point.y , XMouse - mouse_point.x , YMouse - mouse_point.y , color1.r , color1.g , color1.b , 1) ;
                    filled_rect = false ;
                }
                else if (filled_circle) {
                    if (mouse_point.x + r <= 1500 && mouse_point.x - r >= 150 && mouse_point.y - r >= 20 &&mouse_point.y + r <= 660) {
                        filledCircleRGBA(renderer, mouse_point.x, mouse_point.y,sqrt((XMouse - mouse_point.x) * (XMouse - mouse_point.x) +(YMouse - mouse_point.y) * (YMouse - mouse_point.y)), color1.r, color1.g, color1.b, 255);
                    }filled_circle = false;
                } else if (arect){
                    roundedRectangleRGBA(renderer , mouse_point.x , mouse_point.y , XMouse  , YMouse  , 5 , color1.r , color1.g , color1.b , 255 ) ;
                    arect = false;
                } else if (filled_aarect){
                    roundedRectangleRGBA(renderer , mouse_point.x , mouse_point.y , XMouse , YMouse, 15 , color1.r , color1.g , color1.b , 255 ) ;
                    filled_aarect = false;
                }
                else {secend_point = true  ;
                    continue;
                }
            } // next point for rect or circle
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && secend_point) {
                Not_delete.push_back(e) ;
                if (filled_tringle) {
                    filledTrigonRGBA(renderer , mouse_point.x , mouse_point.y , mouse_point_First.x , mouse_point_First.y , XMouse , YMouse , color1.r , color1.g , color1.b , 255) ;
                    SDL_RenderPresent(renderer) ;
                    filled_tringle = false ;}
                if (tringle) {
                    tringlee(renderer , mouse_point.x , mouse_point.y , mouse_point_First.x , mouse_point_First.y , XMouse , YMouse , size_of_pen) ;
                    tringle = false ;
                    SDL_RenderPresent(renderer) ;
                }
                if (rotate_rect){
                    float m = (mouse_point_First.y - mouse_point.y)/(float)(mouse_point_First.x - mouse_point.x);
                    float d = (m*(XMouse-mouse_point.x)-YMouse+mouse_point.y)/(float) sqrt(1+m*m);
                    int y1 = mouse_point.y - d*1/sqrt(1+m*m);int x1 =  mouse_point.x + d*m/ sqrt(1+m*m);
                    int y2 = mouse_point_First.y - d*1/ sqrt(1+m*m);int x2 =  mouse_point_First.x + d*m/ sqrt(1+m*m);

                    thickLineRGBA(renderer , mouse_point.x , mouse_point.y , mouse_point_First.x , mouse_point_First.y ,size_of_pen , color1.r ,color1.g,color1.b, 255 );
                    if (x2<130)x2=150;
                    if (x1<130)x1=150;
                    if (y1>680)y1=660;
                    if (y2>680)y2=660;
                    thickLineRGBA(renderer , x2 , y2 , mouse_point_First.x , mouse_point_First.y ,size_of_pen , color1.r ,color1.g,color1.b, 255 );
                    thickLineRGBA(renderer , x1 , y1 , mouse_point.x , mouse_point.y ,size_of_pen , color1.r ,color1.g,color1.b, 255 );
                    thickLineRGBA(renderer , x1 , y1 , x2 , y2 ,size_of_pen , color1.r ,color1.g,color1.b, 255 );
                    rotate_rect = false;
                }
                if (filled_rect){
                    rect(renderer , mouse_point.x , mouse_point.y , XMouse - mouse_point.x , YMouse - mouse_point.y , color1.r , color1.g , color1.b , 1) ;
                    filled_rect = false ;
                }
                if (filled_circle){
                    filledCircleRGBA(renderer , mouse_point.x , mouse_point.y , sqrt((XMouse - mouse_point.x)*(XMouse - mouse_point.x) + (YMouse - mouse_point.y)*(YMouse - mouse_point.y)) ,color1.r ,color1.g , color1.b , 255 ) ;
                    filled_circle = false ;
                }

            } // finally point for tringle or ellip

            if (e.type == SDL_MOUSEBUTTONDOWN && YMouse >= 700 && YMouse <= 790) {Not_delete.push_back(e) ;
                if (XMouse >= 210 && XMouse <= 230) {
                    size_of_pen = 2;
                }
                if (XMouse >= 240 && XMouse <= 265) {
                    size_of_pen = 5;
                }
                if (XMouse >= 275 && XMouse <= 305) {
                    size_of_pen = 10;
                }
                if (XMouse >= 320 && XMouse <= 355) {
                    size_of_pen = 15;
                }
                if (XMouse >= 375 && XMouse <= 415) {
                    size_of_pen = 20;
                }
                if (XMouse >= 440 && XMouse <= 485) {
                    size_of_pen = 25;
                }
                if (XMouse >= 510 && XMouse <= 560) {
                    size_of_pen = 30;
                }
            }// change size
            if (!color) {Not_delete.push_back(e) ;
                if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 1000 && XMouse <= 1030 && YMouse >= 700 &&
                    YMouse <= 730) {
                    color2 = color1;
                    color1 = black ;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, black.r , black.g , black.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1040 && XMouse <= 1070 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = red ;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, red.r , red.g , red.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1080 && XMouse <= 1110 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = blue ;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, color.r , color.g , color.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1120 && XMouse <= 1150 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = grey ;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, grey.r , grey.g , grey.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1160 && XMouse <= 1190 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = white ;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, white.r , white.g , white.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1200 && XMouse <= 1230 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = green ;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1240 && XMouse <= 1270 && YMouse >= 700 && YMouse <= 730) {
                    color2 = color1;
                    color1 = yellow ;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                UINT32 codeColor1 =
                        ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) + (color1.r & 0xff);
                UINT32 codeColor2 =
                        ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) + (color2.r & 0xff);
            }
        }


    }
//    SDL_Delay(4000) ;
    DestroyEvrytings();
    return 0;
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B) {
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian) {
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian == 1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

int initialize_window() {
    window = SDL_CreateWindow("BP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//SDL_Window *window1 = NULL ; SDL_Renderer *renderer1 = nullptr ;
//    SDL_CreateWindowAndRenderer(screen_width, screen_hight , SDL_WINDOW_SHOWN , &window1 , &renderer1) ;
    SDL_RaiseWindow(window);
//    window_surface = SDL_GetWindowSurface(window);
//    SDL_FillRect(window_surface, NULL, SDL_MapRGB(window_surface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);
    SDL_RaiseWindow(window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
}

void add_background(string address) {
    SDL_Surface *s = IMG_Load(address.c_str());
    SDL_Rect dest{0, 0, screen_width, screen_height};

    SDL_Texture *t = SDL_CreateTextureFromSurface(renderer, s);
    SDL_RenderCopy(renderer, t, NULL, &dest);

    SDL_FreeSurface(s);
    SDL_DestroyTexture(t);
}

void DestroyEvrytings() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
//    SDL_FreeSurface(window_surface);
    IMG_Quit();
    SDL_Quit();
}

void texture(SDL_Renderer *renderer, int x, int y, string addres, int width, int height) {
    int n = addres.length();
    char addr[n + 1];
//    char *addr ;
    strcpy(addr, addres.c_str());
    SDL_Texture *texture = IMG_LoadTexture(renderer, addr);
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect texr = {x, y, width, height};
//SDL_Rect rect1 = {rect1.x = x ; ,rect1.y = y ;,rect1.w = width ;,rect1.h = height ;};
    SDL_RenderCopy(renderer, texture, NULL, &texr);
    SDL_DestroyTexture(texture);
}

bool check_quit() {
    for (SDL_Event e: frame_Event) {
        if (e.type == SDL_QUIT) {
            return false;
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                return false;
            }
        }
    }
    return true;
}

void get_frame_events() {
    frame_Event.clear();
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        frame_Event.push_back(event);
//        Not_delete.push_back(event) ;
    }
}

void
DrawDottedLine(SDL_Renderer *renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 thick, Uint32 Color, int e) {
    float l = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float dl = l / e;
    float dy = (y2 - y1) / e;
    float dx = (x2 - x1) / e;
    int count = 0;
    for (int i = 1; i <= e; ++i) {
        if (i % 2 == 1) {
            thickLineColor(renderer, x1 + (i - 1) * dx, y1 + (i - 1) * dy, x1 + i * dx, y1 + i * dy, thick, Color);
        }
    }
}
void tringlee (SDL_Renderer * renderer , int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int size ){
    thickLineRGBA(renderer , x1 , y1 ,x2 , y2 , size , color1.r , color1.g , color1.b , 255) ;
    thickLineRGBA(renderer , x3 , y3 ,x2 , y2 , size , color1.r , color1.g , color1.b , 255) ;
    thickLineRGBA(renderer , x3 , y3 ,x1 , y1 , size , color1.r , color1.g , color1.b , 255) ;
}
void main2() {
    for (SDL_Event e: Not_delete) {
        for (int i: Mouse_Couredinate[0]) {
            if (e.type == SDL_MOUSEBUTTONDOWN && Mouse_Couredinate[0][i] >= 150 && Mouse_Couredinate[0][i] <= 1500 && Mouse_Couredinate[1][i] >= 0 && Mouse_Couredinate[1][i] <= 660 &&
                line2) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g,
                                      color1.b, 255);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                    line2 = false;
                    Dotted = false;
                }
            }//draw right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                line2over) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g, color1.b, 255);
                        mouse_point.x = XMouse;
                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                }
            }//draw  over  right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                line2over) {
                if (e.button.button == SDL_BUTTON_RIGHT) {
                    if (Dotted) {
                        UINT32 codeColor1 =
                                ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                                (color1.r & 0xff);
                        UINT32 codeColor2 =
                                ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) +
                                (color2.r & 0xff);
                        DrawDottedLine(renderer, mouse_point_First.x, mouse_point_First.y, XMouse, YMouse, size_of_pen,
                                       codeColor1, 5);
                        DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1,
                                       5);
//                        mouse_point.x = XMouse;
//                        mouse_point.y = YMouse;
                    }
                    if (!Dotted) {
                        thickLineRGBA(renderer, mouse_point_First.x, mouse_point_First.y, XMouse, YMouse, size_of_pen,
                                      color1.r, color1.g, color1.b, 255);
                        thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r,
                                      color1.g, color1.b, 255);
//                        mouse_point.x = XMouse;
//                        mouse_point.y = YMouse;
                    }
                    SDL_RenderPresent(renderer);
                    line2over = false;
                    Dotted = false;
                }
            }//End draw  over  right
            if (e.type == SDL_MOUSEBUTTONDOWN && Mouse_Couredinate[0][i] >= 150 && Mouse_Couredinate[0][i] <= 1500 && Mouse_Couredinate[1][i] >= 0 &&
                Mouse_Couredinate[1][i] <= 660 && line1) {
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                line2 = true;
                line1 = false;
            }//get first point for right
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                line1over) {
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                mouse_point_First.x = XMouse;
                mouse_point_First.y = YMouse;
                line2over = true;
                line1over = false;
            }//get first point for over
            if (e.type == SDL_MOUSEBUTTONDOWN && Mouse_Couredinate[0][i] >= 20 && Mouse_Couredinate[0][i] <= 60 && Mouse_Couredinate[1][i] >= 315 &&
                Mouse_Couredinate[1][i] <= 355) {
                line1 = true;
                line2 = false;
            } //!Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 260 && YMouse <= 300) {
                line1 = true;
                line2 = false;
                Dotted = true;
            } //Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 260 && YMouse <= 300) {
                line1over = true;
                Dotted = true;
            } //over Dotted
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 315 && YMouse <= 355) {
                line1over = true;
            } //over !Dotted

            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 20 && XMouse <= 60 && YMouse >= 200 && YMouse <= 240) {
                pen = true;
            }//true Pen drawing
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 75 && XMouse <= 115 && YMouse >= 197 && YMouse <= 237) {
                penDop = true;
                pen = true;
            }//true Pen Dop drawing
            if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                pen) {
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                pen = false;
                if (penDop) pen3 = true;
                else if (Erase) pen4 = true;
                else pen2 = true;
            } // get first loc
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen2) {
                thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, color1.r, color1.g,
                              color1.b, 255);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // draw pen
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen4) {
                thickLineRGBA(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, Erase_color.r,
                              Erase_color.g, Erase_color.b, 255);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // ERAse pen
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 && pen3) {
                UINT32 codeColor1 =
                        ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) +
                        (color1.r & 0xff);
                DrawDottedLine(renderer, mouse_point.x, mouse_point.y, XMouse, YMouse, size_of_pen, codeColor1, 2);
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
            } // draw dotted pen
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660) {
                \
            pen = false;
                pen2 = false;
                pen3 = false;
                penDop = false;
                pen4 = false;
            } // End pen
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 17 && XMouse <= 57 && YMouse >= 75 && YMouse <= 115) {
                pen = true;
                Erase = true;
            } //true start erasing
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 18 && XMouse <= 58 && YMouse >= 377 && YMouse <= 417) {
                get_point = true;
                rectt = true;
            } //rect
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 75 && XMouse <= 115 && YMouse >= 436 && YMouse <= 476) {
                get_point = true;
                circle = true;
            } //circle
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 29 && XMouse <= 69 && YMouse >= 540 && YMouse <= 580) {
                get_point = true;
                filled_rect = true;
            } //filled_rect
            if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 67 && XMouse <= 107 && YMouse >= 600 && YMouse <= 640) {
                get_point = true;
                filled_circle = true;
            } //filled_circle
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                get_point) {
                mouse_point.x = XMouse;
                mouse_point.y = YMouse;
                first_point1 = true;
                get_point = false;
            }
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                first_point1) {
                mouse_point_First.x = XMouse;
                mouse_point_First.y = YMouse;
                first_point1 = false;
                get_point = false;
                if (rectt) {
//                    rect(renderer , mouse_point.x , mouse_point.y ,  , mouse_point_First.y )
                }
            }
            if (e.type == SDL_MOUSEMOTION && XMouse >= 150 && XMouse <= 1500 && YMouse >= 0 && YMouse <= 660 &&
                first_point1) {
                mouse_point_First.x = XMouse;
                mouse_point_First.y = YMouse;
                first_point1 = false;
                get_point = false;
                secend_point = true;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN && YMouse >= 700 && YMouse <= 790) {
                if (XMouse >= 210 && XMouse <= 230) {
                    size_of_pen = 2;
                }
                if (XMouse >= 240 && XMouse <= 265) {
                    size_of_pen = 5;
                }
                if (XMouse >= 275 && XMouse <= 305) {
                    size_of_pen = 10;
                }
                if (XMouse >= 320 && XMouse <= 355) {
                    size_of_pen = 15;
                }
                if (XMouse >= 375 && XMouse <= 415) {
                    size_of_pen = 20;
                }
                if (XMouse >= 440 && XMouse <= 485) {
                    size_of_pen = 25;
                }
                if (XMouse >= 510 && XMouse <= 560) {
                    size_of_pen = 30;
                }
            }// change size

            if (!color) {
                if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 1000 && XMouse <= 1030 && YMouse >= 700 &&
                    YMouse <= 730) {
                    color1 = black;
                    color = true;
                    //                rect(renderer,150 , 0 ,1390 , 660, black.r , black.g , black.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1040 && XMouse <= 1070 && YMouse >= 700 && YMouse <= 730) {
                    color1 = red;
                    color = true;
//                rect(renderer,150 , 0 ,1390 , 660, red.r , red.g , red.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1080 && XMouse <= 1110 && YMouse >= 700 && YMouse <= 730) {
                    color1 = blue;
                    color = true;
//                rect(renderer,150 , 0 ,1390 , 660, color.r , color.g , color.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1120 && XMouse <= 1150 && YMouse >= 700 && YMouse <= 730) {
                    color1 = grey;
                    color = true;
                    //                rect(renderer,150 , 0 ,1390 , 660, grey.r , grey.g , grey.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1160 && XMouse <= 1190 && YMouse >= 700 && YMouse <= 730) {
                    color1 = white;
                    color = true;
                    //                rect(renderer,150 , 0 ,1390 , 660, white.r , white.g , white.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1200 && XMouse <= 1230 && YMouse >= 700 && YMouse <= 730) {
                    color1 = green;
                    color = true;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1240 && XMouse <= 1270 && YMouse >= 700 && YMouse <= 730) {
                    color1 = yellow;
                    color = true;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                UINT32 codeColor1 =
                        ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) + (color1.r & 0xff);
                UINT32 codeColor2 =
                        ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) + (color2.r & 0xff);
            } else if (color) {
                if (e.type == SDL_MOUSEBUTTONDOWN && XMouse >= 1000 && XMouse <= 1030 && YMouse >= 700 &&
                    YMouse <= 730) {
                    color2 = black;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, black.r , black.g , black.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1040 && XMouse <= 1070 && YMouse >= 700 && YMouse <= 730) {
                    color2 = red;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, red.r , red.g , red.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1080 && XMouse <= 1110 && YMouse >= 700 && YMouse <= 730) {
                    color2 = blue;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, color.r , color.g , color.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1120 && XMouse <= 1150 && YMouse >= 700 && YMouse <= 730) {
                    color2 = grey;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, grey.r , grey.g , grey.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1160 && XMouse <= 1190 && YMouse >= 700 && YMouse <= 730) {
                    color2 = white;
                    color = false;
                    //                rect(renderer,150 , 0 ,1390 , 660, white.r , white.g , white.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1200 && XMouse <= 1230 && YMouse >= 700 && YMouse <= 730) {
                    color2 = green;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                if (e.type == SDL_MOUSEBUTTONUP && XMouse >= 1240 && XMouse <= 1270 && YMouse >= 700 && YMouse <= 730) {
                    color1 = yellow;
                    color = false;
//                rect(renderer,150 , 0 ,1390 , 660, green.r , green.g , green.b ,1) ;
//                SDL_RenderPresent(renderer) ;
                }
                UINT32 codeColor1 =
                        ((255 & 0xff) << 24) + ((color1.b & 0xff) << 16) + ((color1.g & 0xff) << 8) + (color1.r & 0xff);
                UINT32 codeColor2 =
                        ((255 & 0xff) << 24) + ((color2.b & 0xff) << 16) + ((color2.g & 0xff) << 8) + (color2.r & 0xff);
            }
        }
    }
}
void rect2(SDL_Renderer *renderer , int x1 , int y1 , int x2 , int y2 , int x3 , int y3, int R , int g , int b , int size){
//    int x4 =
}
