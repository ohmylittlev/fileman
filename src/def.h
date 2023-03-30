#ifndef _DEF_H_
#define _DEF_H_

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>

//~ #define INHIBIT(X) X
#define INHIBIT(X) /* X */

#define APP_NAME "fileman"

// Parameters for rk3566
#if defined(DEVICE_RK3566)
   #define SCREEN_WIDTH             640
   #define SCREEN_HEIGHT            480
   #define HARDWARE_ACCELERATION    0
   #define FULLSCREEN               1
   #define FONT_NAME                "NotoSans-Regular.ttf"
   #define FONT_NAME_MONO           "NotoSansMono-Regular.ttf"
   #define FONT_SIZE                20
   #define LINE_HEIGHT              32
   #define ICON_SIZE                24
   #define MARGIN_X                 10
   #define KEYBOARD_MARGIN          8
   #define KEYBOARD_KEY_SPACING     4
   #define KEYBOARD_SYMBOL_SIZE     24

// Parameters for rk3588
#elif defined(DEVICE_RK3588)
   #define SCREEN_WIDTH             1280
   #define SCREEN_HEIGHT            720
   #define HARDWARE_ACCELERATION    0
   #define FULLSCREEN               1
   #define FONT_NAME                "NotoSans-Regular.ttf"
   #define FONT_NAME_MONO           "NotoSansMono-Regular.ttf"
   #define FONT_SIZE                48
   #define LINE_HEIGHT              72
   #define ICON_SIZE                58
   #define MARGIN_X                 24
   #define KEYBOARD_MARGIN          19
   #define KEYBOARD_KEY_SPACING     10
   #define KEYBOARD_SYMBOL_SIZE     58

// Parameters for handheld
#elif defined(DEVICE_HANDHELD)
   #define SCREEN_WIDTH             1280
   #define SCREEN_HEIGHT            720
   #define HARDWARE_ACCELERATION    0
   #define FULLSCREEN               1
   #define FONT_NAME                "NotoSans-Regular.ttf"
   #define FONT_NAME_MONO           "NotoSansMono-Regular.ttf"
   #define FONT_SIZE                48
   #define LINE_HEIGHT              72
   #define ICON_SIZE                58
   #define MARGIN_X                 24
   #define KEYBOARD_MARGIN          19
   #define KEYBOARD_KEY_SPACING     10
   #define KEYBOARD_SYMBOL_SIZE     58

// Parameters for OGU
#elif defined(DEVICE_OGU)
   #define SCREEN_WIDTH             854
   #define SCREEN_HEIGHT            480
   #define HARDWARE_ACCELERATION    0
   #define FULLSCREEN               1
   #define FONT_NAME                "NotoSans-Regular.ttf"
   #define FONT_NAME_MONO           "NotoSansMono-Regular.ttf"
   #define FONT_SIZE                20
   #define LINE_HEIGHT              32
   #define ICON_SIZE                24
   #define MARGIN_X                 10
   #define KEYBOARD_MARGIN          8
   #define KEYBOARD_KEY_SPACING     4
   #define KEYBOARD_SYMBOL_SIZE     24

// Paramaters for desktop PC
#else
   #define SCREEN_WIDTH             640
   #define SCREEN_HEIGHT            480
   #define HARDWARE_ACCELERATION    1
   #define FULLSCREEN               0
   #define FONT_NAME                "NotoSans-Regular.ttf"
   #define FONT_NAME_MONO           "NotoSansMono-Regular.ttf"
   #define FONT_SIZE                20
   #define LINE_HEIGHT              32
   #define ICON_SIZE                24
   #define MARGIN_X                 10
   #define KEYBOARD_MARGIN          8
   #define KEYBOARD_KEY_SPACING     4
   #define KEYBOARD_SYMBOL_SIZE     24
#endif

// Colors
#define COLOR_TITLE_BG           68,  68,  68
#define COLOR_TEXT_NORMAL        255, 255, 255
#define COLOR_TEXT_SELECTED      255, 0, 0
#define COLOR_BODY_BG            45,  45,  45
#define COLOR_KEYBOARD_DARK      35,  35,  35
#define COLOR_CURSOR_FOCUS       21,  83,  158
#define COLOR_CURSOR_NO_FOCUS    80,  80,  80

// Framerate = 60fps
#define MS_PER_FRAME          16

// Timer for key holds
#define KEYHOLD_TIMER_FIRST   16
#define KEYHOLD_TIMER         4

// Timer for long file name scrolling
#define LONG_NAME_TIMER_FIRST   16
#define LONG_NAME_TIMER         1

// Size of dialog border
#define DIALOG_BORDER         4

// Scroll speed in image viewer
#define VIEWER_SCROLL_SPEED      20

// Button events
#if defined(DEVICE_HANDHELD)
   #define BUTTON_PRESSED_UP              event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_UP
   #define BUTTON_PRESSED_DOWN            event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_DOWN
   #define BUTTON_PRESSED_LEFT            event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_LEFT
   #define BUTTON_PRESSED_RIGHT           event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_RIGHT
   #define BUTTON_PRESSED_PAGEUP          event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 4 || event.jbutton.button == 6)
   #define BUTTON_PRESSED_PAGEDOWN        event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 5 || event.jbutton.button == 7)
   #define BUTTON_PRESSED_VALIDATE        event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 1
   #define BUTTON_PRESSED_BACK            event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 0
   #define BUTTON_PRESSED_MENU_CONTEXT    event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 3
   #define BUTTON_PRESSED_SELECT          event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 2
   #define BUTTON_HELD_UP                 SDL_JoystickGetButton(g_joystick, 13)
   #define BUTTON_HELD_DOWN               SDL_JoystickGetButton(g_joystick, 14)
   #define BUTTON_HELD_LEFT               SDL_JoystickGetButton(g_joystick, 15)
   #define BUTTON_HELD_RIGHT              SDL_JoystickGetButton(g_joystick, 16)
   #define BUTTON_HELD_PAGEUP             SDL_JoystickGetButton(g_joystick, 4) || SDL_JoystickGetButton(g_joystick, 6)
   #define BUTTON_HELD_PAGEDOWN           SDL_JoystickGetButton(g_joystick, 5) || SDL_JoystickGetButton(g_joystick, 7)
   #define BUTTON_HELD_SELECT             SDL_JoystickGetButton(g_joystick, 3)
   #define BUTTON_HELD_VALIDATE           SDL_JoystickGetButton(g_joystick, 1)
#elif defined(DEVICE_RK3566)
   #define BUTTON_PRESSED_UP              event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 13
   #define BUTTON_PRESSED_DOWN            event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 14
   #define BUTTON_PRESSED_LEFT            event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 15
   #define BUTTON_PRESSED_RIGHT           event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 16
   #define BUTTON_PRESSED_PAGEUP          event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 4 || event.jbutton.button == 6)
   #define BUTTON_PRESSED_PAGEDOWN        event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 5 || event.jbutton.button == 7)
   #define BUTTON_PRESSED_VALIDATE        event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 1
   #define BUTTON_PRESSED_BACK            event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 0
   #define BUTTON_PRESSED_MENU_CONTEXT    event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 2
   #define BUTTON_PRESSED_SELECT          event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 3
   #define BUTTON_HELD_UP                 SDL_JoystickGetButton(g_joystick, 13)
   #define BUTTON_HELD_DOWN               SDL_JoystickGetButton(g_joystick, 14)
   #define BUTTON_HELD_LEFT               SDL_JoystickGetButton(g_joystick, 15)
   #define BUTTON_HELD_RIGHT              SDL_JoystickGetButton(g_joystick, 16)
   #define BUTTON_HELD_PAGEUP             SDL_JoystickGetButton(g_joystick, 4) || SDL_JoystickGetButton(g_joystick, 6)
   #define BUTTON_HELD_PAGEDOWN           SDL_JoystickGetButton(g_joystick, 5) || SDL_JoystickGetButton(g_joystick, 7)
   #define BUTTON_HELD_SELECT             SDL_JoystickGetButton(g_joystick, 3)
   #define BUTTON_HELD_VALIDATE           SDL_JoystickGetButton(g_joystick, 1)
#elif defined(DEVICE_RK3588)
   #define BUTTON_PRESSED_UP              event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_UP
   #define BUTTON_PRESSED_DOWN            event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_DOWN
   #define BUTTON_PRESSED_LEFT            event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_LEFT
   #define BUTTON_PRESSED_RIGHT           event.type == SDL_JOYHATMOTION && event.jhat.value == SDL_HAT_RIGHT
   #define BUTTON_PRESSED_PAGEUP          event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 4 || event.jbutton.button == 6)
   #define BUTTON_PRESSED_PAGEDOWN        event.type == SDL_JOYBUTTONDOWN && (event.jbutton.button == 5 || event.jbutton.button == 7)
   #define BUTTON_PRESSED_VALIDATE        event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 1
   #define BUTTON_PRESSED_BACK            event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 0
   #define BUTTON_PRESSED_MENU_CONTEXT    event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 3
   #define BUTTON_PRESSED_SELECT          event.type == SDL_JOYBUTTONDOWN && event.jbutton.button == 2
   #define BUTTON_HELD_UP                 SDL_JoystickGetButton(g_joystick, 13)
   #define BUTTON_HELD_DOWN               SDL_JoystickGetButton(g_joystick, 14)
   #define BUTTON_HELD_LEFT               SDL_JoystickGetButton(g_joystick, 15)
   #define BUTTON_HELD_RIGHT              SDL_JoystickGetButton(g_joystick, 16)
   #define BUTTON_HELD_PAGEUP             SDL_JoystickGetButton(g_joystick, 4) || SDL_JoystickGetButton(g_joystick, 6)
   #define BUTTON_HELD_PAGEDOWN           SDL_JoystickGetButton(g_joystick, 5) || SDL_JoystickGetButton(g_joystick, 7)
   #define BUTTON_HELD_SELECT             SDL_JoystickGetButton(g_joystick, 3)
   #define BUTTON_HELD_VALIDATE           SDL_JoystickGetButton(g_joystick, 1)
#else
   #define BUTTON_PRESSED_UP              event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_UP
   #define BUTTON_PRESSED_DOWN            event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_DOWN
   #define BUTTON_PRESSED_LEFT            event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_LEFT
   #define BUTTON_PRESSED_RIGHT           event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_RIGHT
   #define BUTTON_PRESSED_PAGEUP          event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_PAGEUP
   #define BUTTON_PRESSED_PAGEDOWN        event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_PAGEDOWN
   #define BUTTON_PRESSED_VALIDATE        event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_RETURN
   #define BUTTON_PRESSED_BACK            event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_BACKSPACE
   #define BUTTON_PRESSED_MENU_CONTEXT    event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_x
   #define BUTTON_PRESSED_SELECT          event.type == SDL_KEYDOWN && event.key.repeat == 0 && event.key.keysym.sym == SDLK_INSERT
   #define BUTTON_HELD_UP                 SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP]
   #define BUTTON_HELD_DOWN               SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN]
   #define BUTTON_HELD_LEFT               SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT]
   #define BUTTON_HELD_RIGHT              SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT]
   #define BUTTON_HELD_PAGEUP             SDL_GetKeyboardState(NULL)[SDL_SCANCODE_PAGEUP]
   #define BUTTON_HELD_PAGEDOWN           SDL_GetKeyboardState(NULL)[SDL_SCANCODE_PAGEDOWN]
   #define BUTTON_HELD_SELECT             SDL_GetKeyboardState(NULL)[SDL_SCANCODE_INSERT]
   #define BUTTON_HELD_VALIDATE           SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RETURN]
#endif

// Globals
extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern SDL_Joystick* g_joystick;
extern TTF_Font *g_font;                     // Variable size font
extern TTF_Font *g_fontMono;                 // Mono size font
extern int g_charW;                          // Width of one character in monospace font
class IWindow;
extern std::vector<IWindow *> g_windows;

// Textures for icons
extern SDL_Texture *g_iconFile;
extern SDL_Texture *g_iconDir;
extern SDL_Texture *g_iconUp;
extern SDL_Texture *g_iconCopy;
extern SDL_Texture *g_iconCut;
extern SDL_Texture *g_iconPaste;
extern SDL_Texture *g_iconTrash;
extern SDL_Texture *g_iconDisk;
extern SDL_Texture *g_iconSelect;
extern SDL_Texture *g_iconNone;
extern SDL_Texture *g_iconNewDir;
extern SDL_Texture *g_iconQuit;
extern SDL_Texture *g_iconEdit;
extern SDL_Texture *g_iconCancel;
extern SDL_Texture *g_iconFloppy;
extern SDL_Texture *g_iconImage;
extern SDL_Texture *g_iconFileText;
extern SDL_Texture *g_iconPlus;

#endif
