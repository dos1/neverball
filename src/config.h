#ifndef CONFIG_H
#define CONFIG_H

#include <SDL.h>

#include "audio.h"

/*---------------------------------------------------------------------------*/

/*
 * Changing the  working directory to CONFIG_PATH must  place the game
 * at  the root of  the game  asset hierarchy.   By default,  the game
 * expects to be run within its build tree, so it simply chdirs to the
 * local data directory.
 *
 * If the game is to be installed globally, change this value.
 */
#define CONFIG_PATH "./data"

/*
 * Global settings are stored in  CONFIG_FILE.  This file is placed in
 * the user's home directory as given by the HOME environment var.  If
 * this file is deleted, it will be recreated using the defaults.
 */
#define CONFIG_FILE ".neverballrc"

#define CONFIG_DEF_WIDTH         1024
#define CONFIG_DEF_HEIGHT        768
#define CONFIG_DEF_TEXTURES      1
#define CONFIG_DEF_GEOMETRY      1
#define CONFIG_DEF_AUDIO_RATE    44100
#define CONFIG_DEF_AUDIO_BUFF    AUD_BUFF_HI
#define CONFIG_DEF_MOUSE_SENSE   300
#define CONFIG_DEF_NICE          1
#define CONFIG_DEF_FPS           0
#define CONFIG_DEF_JOY           0

#define CONFIG_DEF_AXIS_X        0
#define CONFIG_DEF_AXIS_Y        1
#define CONFIG_DEF_BUTTON_A      0
#define CONFIG_DEF_BUTTON_B      1
#define CONFIG_DEF_BUTTON_R      2
#define CONFIG_DEF_BUTTON_L      3
#define CONFIG_DEF_BUTTON_PAUSE  4

/*---------------------------------------------------------------------------*/

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define RMASK 0xFF000000
#define GMASK 0x00FF0000
#define BMASK 0x0000FF00
#define AMASK 0x000000FF
#else
#define RMASK 0x000000FF
#define GMASK 0x0000FF00
#define BMASK 0x00FF0000
#define AMASK 0xFF000000
#endif

#define JOY_MAX 32767
#define JOY_MID 16383

#define STRMAX 256

/*---------------------------------------------------------------------------*/

int  config_path(void);
void config_load(void);
void config_store(void);

/*---------------------------------------------------------------------------*/

int config_mode(void);
int config_w   (void);
int config_h   (void);
int config_text(void);
int config_geom(void);
int config_rate(void);
int config_buff(void);
int config_sens(void);
int config_nice(void);
int config_fps (void);

int config_axis_x(int);
int config_axis_y(int);
int config_button_a(int);
int config_button_b(int);
int config_button_r(int);
int config_button_l(int);
int config_button_P(int);

int config_set_mode(int, int, int);
int config_set_text(int);
int config_set_geom(int);
int config_set_audio(int, int);

void config_tog_nice(void);
void config_tog_fps(void);

/*---------------------------------------------------------------------------*/

void config_push_persp(double, double, double);
void config_push_ortho(void);
void config_pop_matrix(void);

/*---------------------------------------------------------------------------*/

#endif
