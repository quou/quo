#pragma once

/* Copyright 2021 George Lamb
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/* Make sure it works with C++, too */
#ifdef __cplusplus
extern "C" {
#endif

/* Standard includes */
#include <stdbool.h>

/* Keys */
#define QUO_KEY_UNKNOWN            -1
#define QUO_KEY_SPACE              32
#define QUO_KEY_APOSTROPHE         39  /* ' */
#define QUO_KEY_COMMA              44  /* , */
#define QUO_KEY_MINUS              45  /* - */
#define QUO_KEY_PERIOD             46  /* . */
#define QUO_KEY_SLASH              47  /* / */
#define QUO_KEY_0                  48
#define QUO_KEY_1                  49
#define QUO_KEY_2                  50
#define QUO_KEY_3                  51
#define QUO_KEY_4                  52
#define QUO_KEY_5                  53
#define QUO_KEY_6                  54
#define QUO_KEY_7                  55
#define QUO_KEY_8                  56
#define QUO_KEY_9                  57
#define QUO_KEY_SEMICOLON          59  /* ; */
#define QUO_KEY_EQUAL              61  /* = */
#define QUO_KEY_A                  65
#define QUO_KEY_B                  66
#define QUO_KEY_C                  67
#define QUO_KEY_D                  68
#define QUO_KEY_E                  69
#define QUO_KEY_F                  70
#define QUO_KEY_G                  71
#define QUO_KEY_H                  72
#define QUO_KEY_I                  73
#define QUO_KEY_J                  74
#define QUO_KEY_K                  75
#define QUO_KEY_L                  76
#define QUO_KEY_M                  77
#define QUO_KEY_N                  78
#define QUO_KEY_O                  79
#define QUO_KEY_P                  80
#define QUO_KEY_Q                  81
#define QUO_KEY_R                  82
#define QUO_KEY_S                  83
#define QUO_KEY_T                  84
#define QUO_KEY_U                  85
#define QUO_KEY_V                  86
#define QUO_KEY_W                  87
#define QUO_KEY_X                  88
#define QUO_KEY_Y                  89
#define QUO_KEY_Z                  90
#define QUO_KEY_LEFT_BRACKET       91  /* [ */
#define QUO_KEY_BACKSLASH          92  /* \ */
#define QUO_KEY_RIGHT_BRACKET      93  /* ] */
#define QUO_KEY_GRAVE_ACCENT       96  /* ` */
#define QUO_KEY_WORLD_1            161 /* non-US #1 */
#define QUO_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define QUO_KEY_ESCAPE             256
#define QUO_KEY_ENTER              257
#define QUO_KEY_TAB                258
#define QUO_KEY_BACKSPACE          259
#define QUO_KEY_INSERT             260
#define QUO_KEY_DELETE             261
#define QUO_KEY_RIGHT              262
#define QUO_KEY_LEFT               263
#define QUO_KEY_DOWN               264
#define QUO_KEY_UP                 265
#define QUO_KEY_PAGE_UP            266
#define QUO_KEY_PAGE_DOWN          267
#define QUO_KEY_HOME               268
#define QUO_KEY_END                269
#define QUO_KEY_CAPS_LOCK          280
#define QUO_KEY_SCROLL_LOCK        281
#define QUO_KEY_NUM_LOCK           282
#define QUO_KEY_PRINT_SCREEN       283
#define QUO_KEY_PAUSE              284
#define QUO_KEY_F1                 290
#define QUO_KEY_F2                 291
#define QUO_KEY_F3                 292
#define QUO_KEY_F4                 293
#define QUO_KEY_F5                 294
#define QUO_KEY_F6                 295
#define QUO_KEY_F7                 296
#define QUO_KEY_F8                 297
#define QUO_KEY_F9                 298
#define QUO_KEY_F10                299
#define QUO_KEY_F11                300
#define QUO_KEY_F12                301
#define QUO_KEY_F13                302
#define QUO_KEY_F14                303
#define QUO_KEY_F15                304
#define QUO_KEY_F16                305
#define QUO_KEY_F17                306
#define QUO_KEY_F18                307
#define QUO_KEY_F19                308
#define QUO_KEY_F20                309
#define QUO_KEY_F21                310
#define QUO_KEY_F22                311
#define QUO_KEY_F23                312
#define QUO_KEY_F24                313
#define QUO_KEY_F25                314
#define QUO_KEY_NP_0               320
#define QUO_KEY_NP_1               321
#define QUO_KEY_NP_2               322
#define QUO_KEY_NP_3               323
#define QUO_KEY_NP_4               324
#define QUO_KEY_NP_5               325
#define QUO_KEY_NP_6               326
#define QUO_KEY_NP_7               327
#define QUO_KEY_NP_8               328
#define QUO_KEY_NP_9               329
#define QUO_KEY_NP_DECIMAL         330
#define QUO_KEY_NP_DIVIDE          331
#define QUO_KEY_NP_MULTIPLY        332
#define QUO_KEY_NP_SUBTRACT        333
#define QUO_KEY_NP_ADD             334
#define QUO_KEY_NP_ENTER           335
#define QUO_KEY_NP_EQUAL           336
#define QUO_KEY_LEFT_SHIFT         340
#define QUO_KEY_LEFT_CONTROL       341
#define QUO_KEY_LEFT_ALT           342
#define QUO_KEY_LEFT_SUPER         343
#define QUO_KEY_RIGHT_SHIFT        344
#define QUO_KEY_RIGHT_CONTROL      345
#define QUO_KEY_RIGHT_ALT          346
#define QUO_KEY_RIGHT_SUPER        347
#define QUO_KEY_MENU               348
#define QUO_KEY_COUNT              QUO_KEY_MENU

/* Windows */
#if defined(_WIN32)
#define QUO_PLATFORM_WINDOWS
#endif

/* X11 */
#if defined(__linux__) || defined(__FreeBSD__)
#define QUO_PLATFORM_X11
#endif

/* Platform-specific includes */
#if defined(QUO_PLATFORM_X11)
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#endif

#if defined(QUO_PLATFORM_WINDOWS)
#include <windows.h>
#include <dwmapi.h>
#include <GL/gl.h>

#if _MSC_VER >= 1500
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")
#endif
#endif

/* Platform-specific aliases & macros */
#if defined(QUO_PLATFORM_X11)
typedef GLXContext quo_GLDeviceContext;
typedef GLXContext quo_GLRenderContext;

#define CALLSTYLE
#define QUO_LOAD_GL_FUNC(t, n) (t*)glXGetProcAddress((unsigned char*)n)
#endif

#if defined (QUO_PLATFORM_WINDOWS)
typedef HDC quo_GLDeviceContext;
typedef HGLRC quo_GLRenderContext;

#define CALLSTYLE __stdcall
#define QUO_LOAD_GL_FUNC(t, n) (t*)wglGetProcAddress(n)

/* X11 already defines these, we have to do it manually on Windows */
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#endif

/* GL load types */
typedef int CALLSTYLE quo_gl_get_uniform_location(unsigned int, const char*);
typedef unsigned int CALLSTYLE quo_gl_create_program();
typedef unsigned int CALLSTYLE quo_gl_create_shader(unsigned int);
typedef void CALLSTYLE quo_gl_attach_shader(unsigned int, unsigned int);
typedef void CALLSTYLE quo_gl_bind_buffer(unsigned int, int);
typedef void CALLSTYLE quo_gl_bind_vertex_array(unsigned int);
typedef void CALLSTYLE quo_gl_buffer_data(unsigned int, int, const void*, unsigned int);
typedef void CALLSTYLE quo_gl_compile_shader(unsigned int);
typedef void CALLSTYLE quo_gl_delete_program(unsigned int*);
typedef void CALLSTYLE quo_gl_delete_shader(unsigned int);
typedef void CALLSTYLE quo_gl_enable_vertex_attrib_array(unsigned int);
typedef void CALLSTYLE quo_gl_gen_buffers(unsigned int, unsigned int*);
typedef void CALLSTYLE quo_gl_gen_vertex_arrays(unsigned int, unsigned int*);
typedef void CALLSTYLE quo_gl_get_program_info_log(unsigned int, int, int, char*);
typedef void CALLSTYLE quo_gl_get_program_iv(unsigned int, unsigned int, int*);
typedef void CALLSTYLE quo_gl_get_shader_info_log(unsigned int, int, int, char*);
typedef void CALLSTYLE quo_gl_get_shader_iv(unsigned int, unsigned int, int*);
typedef void CALLSTYLE quo_gl_link_program(unsigned int);
typedef void CALLSTYLE quo_gl_shader_source(unsigned int, int, const char**, const int*);
typedef void CALLSTYLE quo_gl_uniform_1_f(int, float);
typedef void CALLSTYLE quo_gl_uniform_1_i(int, int);
typedef void CALLSTYLE quo_gl_uniform_2_f(int, float, float);
typedef void CALLSTYLE quo_gl_uniform_3_f(int, float, float, float);
typedef void CALLSTYLE quo_gl_uniform_4_f(int, float, float, float, float);
typedef void CALLSTYLE quo_gl_uniform_matrix_4_f_v(int, int, bool, float*);
typedef void CALLSTYLE quo_gl_use_program(unsigned int);
typedef void CALLSTYLE quo_gl_vertex_attrib_pointer(unsigned int, int, unsigned int, bool, int, const void*);
typedef void CALLSTYLE quo_gl_delete_vertex_arrays(unsigned int, unsigned int*);
typedef void CALLSTYLE quo_gl_delete_buffers(unsigned int, unsigned int*);

#ifdef QUO_PLATFORM_WINDOWS
/* X11 already defines this, on Windows it has to be done manually */
typedef void CALLSTYLE quo_gl_active_texture(unsigned int);
#endif

/* OpenGL functions */
quo_gl_attach_shader* glAttachShader = NULL;
quo_gl_bind_buffer* glBindBuffer = NULL;
quo_gl_bind_vertex_array* glBindVertexArray = NULL;
quo_gl_buffer_data* glBufferData = NULL;
quo_gl_compile_shader* glCompileShader = NULL;
quo_gl_create_program* glCreateProgram = NULL;
quo_gl_create_shader* glCreateShader = NULL;
quo_gl_delete_program* glDeleteProgram = NULL;
quo_gl_delete_shader* glDeleteShader = NULL;
quo_gl_enable_vertex_attrib_array* glEnableVertexAttribArray = NULL;
quo_gl_gen_buffers* glGenBuffers = NULL;
quo_gl_gen_vertex_arrays* glGenVertexArrays = NULL;
quo_gl_get_program_info_log* glGetProgramInfoLog = NULL;
quo_gl_get_program_iv* glGetProgramiv = NULL;
quo_gl_get_shader_info_log* glGetShaderInfoLog = NULL;
quo_gl_get_shader_iv* glGetShaderiv = NULL;
quo_gl_get_uniform_location* glGetUniformLocation = NULL;
quo_gl_link_program* glLinkProgram = NULL;
quo_gl_shader_source* glShaderSource = NULL;
quo_gl_uniform_1_f* glUniform1f = NULL;
quo_gl_uniform_1_i* glUniform1i = NULL;
quo_gl_uniform_2_f* glUniform2f = NULL;
quo_gl_uniform_3_f* glUniform3f = NULL;
quo_gl_uniform_4_f* glUniform4f = NULL;
quo_gl_uniform_matrix_4_f_v* glUniformMatrix4fv = NULL;
quo_gl_use_program* glUseProgram = NULL;
quo_gl_vertex_attrib_pointer* glVertexAttribPointer = NULL;
quo_gl_delete_buffers* glDeleteBuffers = NULL;
quo_gl_delete_vertex_arrays* glDeleteVertexArrays = NULL;

#ifdef QUO_PLATFORM_WINDOWS
/* X11 already defines this, on Windows it has to be done manually */
quo_gl_active_texture* glActiveTexture = NULL;
#endif

/* Load all OpenGL functions */
void quo_load_gl();

double quo_get_elapsed_time();

/* -----------------------
 * START WINDOW
 * -----------------------*/

/* INPUT HASHTABLE:
 *	For storing system input map items */
typedef struct quo_InputHashTableItem {
	int key;
	int value;
} quo_InputHashTableItem;

typedef struct quo_InputHashTable {
	quo_InputHashTableItem hash_array[QUO_KEY_COUNT];
} quo_InputHashTable;

void quo_init_input_table(quo_InputHashTable* table);
int quo_search_input_table(quo_InputHashTable* table, int key);
void quo_insert_input_table(quo_InputHashTable* table, int key, int value);

/* Window struct */
typedef struct quo_Window {
	quo_GLDeviceContext device_context;
	quo_GLRenderContext render_context;

	bool is_open;
	int width, height;

	double frame_time;
	double now_time;
	double old_time;

	double fps;

	quo_InputHashTable key_map;

#if defined(QUO_PLATFORM_X11)
	Display* display;
	Window window_root;
	Window window;
	XVisualInfo* visual_info;
	Colormap color_map;
	XSetWindowAttributes set_window_attribs;
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	HWND hwnd;
#endif
} quo_Window;

/* Window management */
void quo_init_window(quo_Window* window, int w, int h, bool resizable);
void quo_set_window_title(quo_Window* window, const char* title);
void quo_update_window(quo_Window* window);
void quo_update_window_events(quo_Window* window);
void quo_free_window(quo_Window* window);

/* -----------------------
 * END MATHS
 * -----------------------*/

/* -----------------------
 * START MATHS
 * -----------------------*/

#define QUO_PI 3.14159265358f

typedef struct quo_vec2 {
	float x, y;
} quo_vec2;

quo_vec2 quo_add_vec2(quo_vec2 a, quo_vec2 b);
quo_vec2 quo_subtract_vec2(quo_vec2 a, quo_vec2 b);
quo_vec2 quo_multiply_vec2(quo_vec2 a, quo_vec2 b);
quo_vec2 quo_divide_vec2(quo_vec2 a, quo_vec2 b);

quo_vec2 quo_normalise_vec2(quo_vec2 v);
float quo_vec2_magnitude(quo_vec2 v);
float quo_dot_vec2(quo_vec2 a, quo_vec2 b);

typedef struct quo_vec3 {
	float x, y, z;
} quo_vec3;

quo_vec3 quo_add_vec3(quo_vec3 a, quo_vec3 b);
quo_vec3 quo_subtract_vec3(quo_vec3 a, quo_vec3 b);
quo_vec3 quo_multiply_vec3(quo_vec3 a, quo_vec3 b);
quo_vec3 quo_divide_vec3(quo_vec3 a, quo_vec3 b);

quo_vec3 quo_normalise_vec3(quo_vec3 v);
float quo_vec3_magnitude(quo_vec3 v);
quo_vec3 quo_cross_vec3(quo_vec3 a, quo_vec3 b);
float quo_dot_vec3(quo_vec3 a, quo_vec3 b);

/* A 4x4 matrix structure, and it's operational functions */
typedef struct quo_Matrix {
	float elements[16];
} quo_Matrix;

quo_Matrix quo_identity();
quo_Matrix quo_translate(quo_Matrix m, quo_vec3 translation);
quo_Matrix quo_rotate(quo_Matrix m, float angle, quo_vec3 axis);
quo_Matrix quo_scale(quo_Matrix m, quo_vec3 scale);
quo_Matrix quo_orthographic(float left, float right, float bottom, float top, float near_plane, float far_plane);
quo_Matrix quo_perspective(float fov, float aspect, float near_plane, float far_plane);

inline static float quo_to_radians(float deg) {
	return (float)(deg * (QUO_PI / 180.0f));
}

/* -----------------------
 * END MATHS
 * -----------------------*/

/* Generic rectangle struct */
typedef struct quo_Rect {
	int x, y, w, h;
} quo_Rect;

/* -----------------------
 * START RENDERER
 * -----------------------*/

#define QUO_MAX_SHADERS 10

/* Data for a bitmap file */
typedef struct quo_BitmapImage {
	int width, height;
	unsigned char* pixels;
} quo_BitmapImage;

/* Load a bitmap from a file. Returnes true on success.
 * The file must not have a colour space written to it's header. */
bool quo_load_bitmap_from_file(const char* filename, quo_BitmapImage* image, unsigned int components);
void quo_free_bitmap(quo_BitmapImage* image);

/* A GPU texture */
typedef struct quo_Texture {
	int width, height;
	unsigned int id;
} quo_Texture;

void quo_init_texture_from_bmp(quo_BitmapImage* bitmap, quo_Texture* texture);
void quo_free_texture(quo_Texture* texture);
void quo_bind_texture(quo_Texture* texture, unsigned int unit);
void quo_unbind_texture();

/* To be used as an index into the renderer's shader array */
typedef unsigned int quo_ShaderHandle;

/* Responsible for drawing things to the screen */
typedef struct quo_Renderer {
	quo_Window* window;
	quo_Matrix projection;

	quo_ShaderHandle sprite_shader;

	unsigned int quad_va;
	unsigned int quad_vb;

	unsigned int shaders[QUO_MAX_SHADERS];
	unsigned int shader_count;
} quo_Renderer;

/* Rendering utility */
/* Create a hex colour from red, green, and blue values*/
unsigned long quo_color_from_rgb(int r, int g, int b);

/* Renderer management */
void quo_init_renderer(quo_Renderer* renderer, quo_Window* window);
void quo_free_renderer(quo_Renderer* renderer);
void quo_update_renderer(quo_Renderer* renderer);

/* Draw functions */
void quo_clear_renderer(unsigned long color);
void quo_draw_rect(quo_Renderer* renderer, quo_Rect rect, unsigned long color);
void quo_draw_texture(quo_Renderer* renderer, quo_Texture* texture, quo_Rect src, quo_Rect dest, unsigned long color);

/* Shader management */
quo_ShaderHandle quo_create_shader(quo_Renderer* renderer, const char* vertex_source, const char* fragment_source);
void quo_bind_shader(quo_Renderer* renderer, quo_ShaderHandle shader);
void quo_shader_set_color(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, unsigned long color);
void quo_shader_set_float(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float val);
void quo_shader_set_int(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, int val);
void quo_shader_set_matrix(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, quo_Matrix m);
void quo_shader_set_vec2(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y);
void quo_shader_set_vec3(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y, float z);
void quo_shader_set_vec4(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y, float z, float w);

/* -----------------------
 * END RENDERER
 * -----------------------*/

/* -----------------------
 * START INPUT
 * -----------------------*/

typedef struct quo_InputSystem {
	bool held_keys[QUO_KEY_COUNT];
	bool down_keys[QUO_KEY_COUNT];
	bool up_keys[QUO_KEY_COUNT];
} quo_InputSystem;

void quo_init_input_system();
void quo_update_input_system();

bool quo_key_pressed(int key);
bool quo_key_just_pressed(int key);
bool quo_key_just_released(int key);

/* For internal use only */
void i_quo_set_key_held_state(int key, bool status);
void i_quo_set_key_down_state(int key, bool status);
void i_quo_set_key_up_state(int key, bool status);

/* -----------------------
 * END INPUT
 * -----------------------*/


/*  _____                 _                           _        _   _
 * |_   _|               | |                         | |      | | (_)
 *   | |  _ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_ _  ___  _ __
 *   | | | '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \
 *  _| |_| | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |
 * |_____|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|
 *                 | |
 *                 |_|
 */

#ifdef QUO_IMPL
/* C standard includes */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quo_load_gl() {
	glAttachShader = QUO_LOAD_GL_FUNC(quo_gl_attach_shader, "glAttachShader");
	glBindBuffer = QUO_LOAD_GL_FUNC(quo_gl_bind_buffer, "glBindBuffer");
	glBindVertexArray = QUO_LOAD_GL_FUNC(quo_gl_bind_vertex_array, "glBindVertexArray");
	glBufferData = QUO_LOAD_GL_FUNC(quo_gl_buffer_data, "glBufferData");
	glCompileShader = QUO_LOAD_GL_FUNC(quo_gl_compile_shader, "glCompileShader");
	glCreateProgram = QUO_LOAD_GL_FUNC(quo_gl_create_program, "glCreateProgram");
	glCreateShader = QUO_LOAD_GL_FUNC(quo_gl_create_shader, "glCreateShader");
	glDeleteProgram = QUO_LOAD_GL_FUNC(quo_gl_delete_program, "glDeleteProgram");
	glDeleteShader = QUO_LOAD_GL_FUNC(quo_gl_delete_shader, "glDeleteShader");
	glEnableVertexAttribArray = QUO_LOAD_GL_FUNC(quo_gl_enable_vertex_attrib_array, "glEnableVertexAttribArray");
	glGenBuffers = QUO_LOAD_GL_FUNC(quo_gl_gen_buffers, "glGenBuffers");
	glGenVertexArrays = QUO_LOAD_GL_FUNC(quo_gl_gen_vertex_arrays, "glGenVertexArrays");
	glGetProgramInfoLog = QUO_LOAD_GL_FUNC(quo_gl_get_program_info_log, "glGetProgramInfoLog");
	glGetProgramiv = QUO_LOAD_GL_FUNC(quo_gl_get_program_iv, "glGetProgramiv");
	glGetShaderInfoLog = QUO_LOAD_GL_FUNC(quo_gl_get_shader_info_log, "glGetShaderInfoLog");
	glGetShaderiv = QUO_LOAD_GL_FUNC(quo_gl_get_shader_iv, "glGetShaderiv");
	glGetUniformLocation = QUO_LOAD_GL_FUNC(quo_gl_get_uniform_location, "glGetUniformLocation");
	glLinkProgram = QUO_LOAD_GL_FUNC(quo_gl_link_program, "glLinkProgram");
	glShaderSource = QUO_LOAD_GL_FUNC(quo_gl_shader_source, "glShaderSource");
	glUniform1f = QUO_LOAD_GL_FUNC(quo_gl_uniform_1_f, "glUniform1f");
	glUniform1i = QUO_LOAD_GL_FUNC(quo_gl_uniform_1_i, "glUniform1i");
	glUniform2f = QUO_LOAD_GL_FUNC(quo_gl_uniform_2_f, "glUniform2f");
	glUniform3f = QUO_LOAD_GL_FUNC(quo_gl_uniform_3_f, "glUniform3f");
	glUniform4f = QUO_LOAD_GL_FUNC(quo_gl_uniform_4_f, "glUniform4f");
	glUniformMatrix4fv = QUO_LOAD_GL_FUNC(quo_gl_uniform_matrix_4_f_v, "glUniformMatrix4fv");
	glUseProgram = QUO_LOAD_GL_FUNC(quo_gl_use_program, "glUseProgram");
	glVertexAttribPointer = QUO_LOAD_GL_FUNC(quo_gl_vertex_attrib_pointer, "glVertexAttribPointer");
	glDeleteVertexArrays = QUO_LOAD_GL_FUNC(quo_gl_delete_vertex_arrays, "glDeleteVertexArrays");
	glDeleteBuffers = QUO_LOAD_GL_FUNC(quo_gl_delete_buffers, "glDeleteBuffers");

#ifdef QUO_PLATFORM_WINDOWS
	/* X11 already defines this, on Windows it has to be done manually */
	glActiveTexture = QUO_LOAD_GL_FUNC(quo_gl_active_texture, "glActiveTexture");
#endif
}

double quo_get_elapsed_time() {
	return ((double)clock() / (double)CLOCKS_PER_SEC);
}

/* -----------------------
 * START WINDOW
 * -----------------------*/

static int quo_input_hash_code(int key) {
	return key % QUO_KEY_COUNT;
}

void quo_init_input_table(quo_InputHashTable* table) {
	assert(table != NULL);

	for (unsigned int i = 0; i < QUO_KEY_COUNT; i++) {
		table->hash_array[i] = (quo_InputHashTableItem){-1, 0};
	}
}

int quo_search_input_table(quo_InputHashTable* table, int key) {
	assert(table != NULL);

	int hash_index = quo_input_hash_code(key);

	while (table->hash_array[hash_index].key != -1) {
		if (table->hash_array[hash_index].key == key) {
			return table->hash_array[hash_index].value;
		}

		hash_index++;

		hash_index %= QUO_KEY_COUNT;
	}

	return 0;
}

void quo_insert_input_table(quo_InputHashTable* table, int key, int value) {
	assert(table != NULL);

	quo_InputHashTableItem item = {key, value};

	int hash_index = quo_input_hash_code(key);

	while (table->hash_array[hash_index].key != -1) {
		hash_index++;

		hash_index %= QUO_KEY_COUNT;
	}

	table->hash_array[hash_index] = item;
}

/* Win32 event callback */
#if defined(QUO_PLATFORM_WINDOWS)
static LRESULT CALLBACK quo_win32_event_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	LONG_PTR lpUserData = GetWindowLongPtr(hwnd, GWLP_USERDATA);
	quo_Window* q_window = (quo_Window*)lpUserData;

	switch (msg) {
		case WM_DESTROY:
			q_window->is_open = false;
			return 0;
		case WM_SIZE:
			if (q_window) {
				q_window->width = lparam & 0xFFFF;
				q_window->height = (lparam >> 16) & 0xFFFF;
				return 0;
			}
		case WM_KEYDOWN: {
			if (q_window) {
				int key = quo_search_input_table(&q_window->key_map, wparam);
				i_quo_set_key_held_state(key, true);
				i_quo_set_key_down_state(key, true);
			}
			return 0;
		}
		case WM_KEYUP: {
			if (q_window) {
				int key = quo_search_input_table(&q_window->key_map, wparam);
				i_quo_set_key_held_state(key, false);
				i_quo_set_key_up_state(key, true);
			}
			return 0;
		}
		default:
			break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}
#endif

#ifdef QUO_PLATFORM_WINDOWS
static void quo_init_window_windows(quo_Window* window, int w, int h, bool resizable) {
	WNDCLASS wc;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = quo_win32_event_callback;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpszMenuName = NULL;
	wc.hbrBackground = NULL;
	wc.lpszClassName = "quo";
	RegisterClass(&wc);

	/* Window styling */
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE;

	if (resizable) {
		dwStyle |= WS_THICKFRAME | WS_MAXIMIZEBOX;
	}

	window->width = w;
	window->height = h;

	RECT rWndRect = { 0, 0, w, h };
	AdjustWindowRectEx(&rWndRect, dwStyle, FALSE, dwExStyle);
	int width = rWndRect.right - rWndRect.left;
	int height = rWndRect.bottom - rWndRect.top;

	window->hwnd = CreateWindowEx(dwExStyle, "quo", "", dwStyle, 0, 0, width, height, NULL, NULL, GetModuleHandle(NULL), window);

	SetWindowLongPtr(window->hwnd, GWLP_USERDATA, (LONG_PTR)window);

	/* Set up OpenGL */
	window->device_context = GetDC((HWND)window->hwnd);
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		PFD_MAIN_PLANE, 0, 0, 0, 0
	};

	int pf = 0;
	if (!(pf = ChoosePixelFormat(window->device_context, &pfd))) { return; }
	SetPixelFormat(window->device_context, pf, &pfd);

	if (!(window->render_context = wglCreateContext(window->device_context))) { return; }
	wglMakeCurrent(window->device_context, window->render_context);

	quo_init_input_table(&window->key_map);
	quo_insert_input_table(&window->key_map, 0x00, QUO_KEY_UNKNOWN);
	quo_insert_input_table(&window->key_map, 0x41, QUO_KEY_A);
	quo_insert_input_table(&window->key_map, 0x42, QUO_KEY_B);
	quo_insert_input_table(&window->key_map, 0x43, QUO_KEY_C);
	quo_insert_input_table(&window->key_map, 0x44, QUO_KEY_D);
	quo_insert_input_table(&window->key_map, 0x45, QUO_KEY_E);
	quo_insert_input_table(&window->key_map, 0x46, QUO_KEY_F);
	quo_insert_input_table(&window->key_map, 0x47, QUO_KEY_G);
	quo_insert_input_table(&window->key_map, 0x48, QUO_KEY_H);
	quo_insert_input_table(&window->key_map, 0x49, QUO_KEY_I);
	quo_insert_input_table(&window->key_map, 0x4A, QUO_KEY_J);
	quo_insert_input_table(&window->key_map, 0x4B, QUO_KEY_K);
	quo_insert_input_table(&window->key_map, 0x4C, QUO_KEY_L);
	quo_insert_input_table(&window->key_map, 0x4D, QUO_KEY_M);
	quo_insert_input_table(&window->key_map, 0x4E, QUO_KEY_N);
	quo_insert_input_table(&window->key_map, 0x4F, QUO_KEY_O);
	quo_insert_input_table(&window->key_map, 0x50, QUO_KEY_P);
	quo_insert_input_table(&window->key_map, 0x51, QUO_KEY_Q);
	quo_insert_input_table(&window->key_map, 0x52, QUO_KEY_R);
	quo_insert_input_table(&window->key_map, 0x53, QUO_KEY_S);
	quo_insert_input_table(&window->key_map, 0x54, QUO_KEY_T);
	quo_insert_input_table(&window->key_map, 0x55, QUO_KEY_U);
	quo_insert_input_table(&window->key_map, 0x56, QUO_KEY_V);
	quo_insert_input_table(&window->key_map, 0x57, QUO_KEY_W);
	quo_insert_input_table(&window->key_map, 0x58, QUO_KEY_X);
	quo_insert_input_table(&window->key_map, 0x59, QUO_KEY_Y);
	quo_insert_input_table(&window->key_map, 0x5A, QUO_KEY_Z);

	/* Function keys */
	quo_insert_input_table(&window->key_map, VK_F1, QUO_KEY_F1);
	quo_insert_input_table(&window->key_map, VK_F2, QUO_KEY_F2);
	quo_insert_input_table(&window->key_map, VK_F3, QUO_KEY_F3);
	quo_insert_input_table(&window->key_map, VK_F4, QUO_KEY_F4);
	quo_insert_input_table(&window->key_map, VK_F5, QUO_KEY_F5);
	quo_insert_input_table(&window->key_map, VK_F6, QUO_KEY_F6);
	quo_insert_input_table(&window->key_map, VK_F7, QUO_KEY_F7);
	quo_insert_input_table(&window->key_map, VK_F8, QUO_KEY_F8);
	quo_insert_input_table(&window->key_map, VK_F9, QUO_KEY_F9);
	quo_insert_input_table(&window->key_map, VK_F10, QUO_KEY_F10);
	quo_insert_input_table(&window->key_map, VK_F11, QUO_KEY_F11);
	quo_insert_input_table(&window->key_map, VK_F12, QUO_KEY_F12);

	/* Navigation */
	quo_insert_input_table(&window->key_map, VK_DOWN, QUO_KEY_DOWN);
	quo_insert_input_table(&window->key_map, VK_LEFT, QUO_KEY_LEFT);
	quo_insert_input_table(&window->key_map, VK_RIGHT, QUO_KEY_RIGHT);
	quo_insert_input_table(&window->key_map, VK_UP, QUO_KEY_UP);
	quo_insert_input_table(&window->key_map, VK_ESCAPE, QUO_KEY_ESCAPE);

	/* General navigation & editing */
	quo_insert_input_table(&window->key_map, VK_ESCAPE, QUO_KEY_ESCAPE);
	quo_insert_input_table(&window->key_map, VK_RETURN, QUO_KEY_ENTER);
	quo_insert_input_table(&window->key_map, VK_BACK, QUO_KEY_BACKSPACE);
	quo_insert_input_table(&window->key_map, VK_PAUSE, QUO_KEY_PAUSE);
	quo_insert_input_table(&window->key_map, VK_SCROLL, QUO_KEY_SCROLL_LOCK);
	quo_insert_input_table(&window->key_map, VK_TAB, QUO_KEY_TAB);
	quo_insert_input_table(&window->key_map, VK_DELETE, QUO_KEY_DELETE);
	quo_insert_input_table(&window->key_map, VK_HOME, QUO_KEY_HOME);
	quo_insert_input_table(&window->key_map, VK_END, QUO_KEY_END);
	quo_insert_input_table(&window->key_map, VK_PRIOR, QUO_KEY_PAGE_UP);
	quo_insert_input_table(&window->key_map, VK_NEXT, QUO_KEY_PAGE_DOWN);
	quo_insert_input_table(&window->key_map, VK_INSERT, QUO_KEY_INSERT);
	quo_insert_input_table(&window->key_map, VK_SHIFT, QUO_KEY_LEFT_SHIFT);
	quo_insert_input_table(&window->key_map, VK_CONTROL, QUO_KEY_LEFT_CONTROL);
	quo_insert_input_table(&window->key_map, VK_SPACE, QUO_KEY_SPACE);
	quo_insert_input_table(&window->key_map, VK_OEM_PERIOD, QUO_KEY_PERIOD);
	quo_insert_input_table(&window->key_map, VK_OEM_COMMA, QUO_KEY_COMMA);
	quo_insert_input_table(&window->key_map, VK_OEM_3, QUO_KEY_GRAVE_ACCENT);

	/* Number keys */
	quo_insert_input_table(&window->key_map, 0x30, QUO_KEY_0);
	quo_insert_input_table(&window->key_map, 0x31, QUO_KEY_1);
	quo_insert_input_table(&window->key_map, 0x32, QUO_KEY_2);
	quo_insert_input_table(&window->key_map, 0x33, QUO_KEY_3);
	quo_insert_input_table(&window->key_map, 0x34, QUO_KEY_4);
	quo_insert_input_table(&window->key_map, 0x35, QUO_KEY_5);
	quo_insert_input_table(&window->key_map, 0x36, QUO_KEY_6);
	quo_insert_input_table(&window->key_map, 0x37, QUO_KEY_7);
	quo_insert_input_table(&window->key_map, 0x38, QUO_KEY_8);
	quo_insert_input_table(&window->key_map, 0x39, QUO_KEY_9);

	/* Numpad keys */
	quo_insert_input_table(&window->key_map, VK_NUMPAD0, QUO_KEY_NP_0);
	quo_insert_input_table(&window->key_map, VK_NUMPAD1, QUO_KEY_NP_1);
	quo_insert_input_table(&window->key_map, VK_NUMPAD2, QUO_KEY_NP_2);
	quo_insert_input_table(&window->key_map, VK_NUMPAD3, QUO_KEY_NP_3);
	quo_insert_input_table(&window->key_map, VK_NUMPAD4, QUO_KEY_NP_4);
	quo_insert_input_table(&window->key_map, VK_NUMPAD5, QUO_KEY_NP_5);
	quo_insert_input_table(&window->key_map, VK_NUMPAD6, QUO_KEY_NP_6);
	quo_insert_input_table(&window->key_map, VK_NUMPAD7, QUO_KEY_NP_7);
	quo_insert_input_table(&window->key_map, VK_NUMPAD8, QUO_KEY_NP_8);
	quo_insert_input_table(&window->key_map, VK_NUMPAD9, QUO_KEY_NP_9);
	quo_insert_input_table(&window->key_map, VK_MULTIPLY, QUO_KEY_NP_MULTIPLY);
	quo_insert_input_table(&window->key_map, VK_ADD, QUO_KEY_NP_ADD);
	quo_insert_input_table(&window->key_map, VK_DIVIDE, QUO_KEY_NP_DIVIDE);
	quo_insert_input_table(&window->key_map, VK_SUBTRACT, QUO_KEY_NP_SUBTRACT);
	quo_insert_input_table(&window->key_map, VK_DECIMAL, QUO_KEY_NP_DECIMAL);

	quo_insert_input_table(&window->key_map, VK_CAPITAL, QUO_KEY_CAPS_LOCK);
}

static void quo_update_window_windows(quo_Window* window) {
	SwapBuffers(window->device_context);
}

static void quo_update_window_events_windows(quo_Window* window) {
	/* Poll for events, handled in quo_win32_event_callback */
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

#endif /* QUO_PLATFORM_WINDOWS */

#ifdef QUO_PLATFORM_X11
static void quo_init_window_x11(quo_Window* window, int w, int h, bool resizable) {
	window->display = XOpenDisplay(NULL);
	window->window_root = DefaultRootWindow(window->display);

	/* Configure window */
	int gl_attribs[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	window->visual_info = glXChooseVisual(window->display, 0, gl_attribs);
	window->color_map = XCreateColormap(window->display, window->window_root, window->visual_info->visual, AllocNone);
	window->set_window_attribs.colormap = window->color_map;

	window->set_window_attribs.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | FocusChangeMask | StructureNotifyMask;

	/* Create the window */
	window->window = XCreateWindow(window->display, window->window_root, 0, 0, w, h, 0, window->visual_info->depth, InputOutput, window->visual_info->visual, CWColormap | CWEventMask, &window->set_window_attribs);

	if (!resizable) {
		/* This works by setting the miniumum and maximum heights of the window
		 * to the input width and height. I'm not sure if this is the correct
		 * way to do it, but it works, and even removes the maximise button */
		XSizeHints* hints = XAllocSizeHints();
		hints->flags = PMinSize | PMaxSize;
		hints->min_width = w;
		hints->min_height = h;
		hints->max_width = w;
		hints->max_height = h;

		XSetWMNormalHints(window->display, window->window, hints);

		XFree(hints);
	}

	/* Remap close event */
	Atom atomWmDeleteWindow = XInternAtom(window->display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(window->display, window->window, &atomWmDeleteWindow, 1);

	/* Display the window */
	XClearWindow(window->display, window->window);
	XMapRaised(window->display, window->window);

	/* Create OpenGL context */
	window->device_context = glXCreateContext(window->display, window->visual_info, NULL, GL_TRUE);
	glXMakeCurrent(window->display, window->window, window->device_context);

	/* Set width and height */
	XWindowAttributes gwa;
	XGetWindowAttributes(window->display, window->window, &gwa);
	glViewport(0, 0, gwa.width, gwa.height);
	window->width = gwa.width;
	window->height = gwa.height;

	quo_init_input_table(&window->key_map);

	/* Key mapping */
	quo_insert_input_table(&window->key_map, 0x00, QUO_KEY_UNKNOWN);
	quo_insert_input_table(&window->key_map, 0x61, QUO_KEY_A);
	quo_insert_input_table(&window->key_map, 0x62, QUO_KEY_B);
	quo_insert_input_table(&window->key_map, 0x63, QUO_KEY_C);
	quo_insert_input_table(&window->key_map, 0x64, QUO_KEY_D);
	quo_insert_input_table(&window->key_map, 0x65, QUO_KEY_E);
	quo_insert_input_table(&window->key_map, 0x66, QUO_KEY_F);
	quo_insert_input_table(&window->key_map, 0x67, QUO_KEY_G);
	quo_insert_input_table(&window->key_map, 0x68, QUO_KEY_H);
	quo_insert_input_table(&window->key_map, 0x69, QUO_KEY_I);
	quo_insert_input_table(&window->key_map, 0x6A, QUO_KEY_J);
	quo_insert_input_table(&window->key_map, 0x6B, QUO_KEY_K);
	quo_insert_input_table(&window->key_map, 0x6C, QUO_KEY_L);
	quo_insert_input_table(&window->key_map, 0x6D, QUO_KEY_M);
	quo_insert_input_table(&window->key_map, 0x6E, QUO_KEY_N);
	quo_insert_input_table(&window->key_map, 0x6F, QUO_KEY_O);
	quo_insert_input_table(&window->key_map, 0x70, QUO_KEY_P);
	quo_insert_input_table(&window->key_map, 0x71, QUO_KEY_Q);
	quo_insert_input_table(&window->key_map, 0x72, QUO_KEY_R);
	quo_insert_input_table(&window->key_map, 0x73, QUO_KEY_S);
	quo_insert_input_table(&window->key_map, 0x74, QUO_KEY_T);
	quo_insert_input_table(&window->key_map, 0x75, QUO_KEY_U);
	quo_insert_input_table(&window->key_map, 0x76, QUO_KEY_V);
	quo_insert_input_table(&window->key_map, 0x77, QUO_KEY_W);
	quo_insert_input_table(&window->key_map, 0x78, QUO_KEY_X);
	quo_insert_input_table(&window->key_map, 0x79, QUO_KEY_Y);
	quo_insert_input_table(&window->key_map, 0x7A, QUO_KEY_Z);

	/* Function keys */
	quo_insert_input_table(&window->key_map, XK_F1, QUO_KEY_F1);
	quo_insert_input_table(&window->key_map, XK_F2, QUO_KEY_F2);
	quo_insert_input_table(&window->key_map, XK_F3, QUO_KEY_F3);
	quo_insert_input_table(&window->key_map, XK_F4, QUO_KEY_F4);
	quo_insert_input_table(&window->key_map, XK_F5, QUO_KEY_F5);
	quo_insert_input_table(&window->key_map, XK_F6, QUO_KEY_F6);
	quo_insert_input_table(&window->key_map, XK_F7, QUO_KEY_F7);
	quo_insert_input_table(&window->key_map, XK_F8, QUO_KEY_F8);
	quo_insert_input_table(&window->key_map, XK_F9, QUO_KEY_F9);
	quo_insert_input_table(&window->key_map, XK_F10, QUO_KEY_F10);
	quo_insert_input_table(&window->key_map, XK_F11, QUO_KEY_F11);
	quo_insert_input_table(&window->key_map, XK_F12, QUO_KEY_F12);

	/* Navigation */
	quo_insert_input_table(&window->key_map, XK_Down, QUO_KEY_DOWN);
	quo_insert_input_table(&window->key_map, XK_Left, QUO_KEY_LEFT);
	quo_insert_input_table(&window->key_map, XK_Right, QUO_KEY_RIGHT);
	quo_insert_input_table(&window->key_map, XK_Up, QUO_KEY_UP);
	quo_insert_input_table(&window->key_map, XK_Escape, QUO_KEY_ESCAPE);

	/* General navigation & editing */
	quo_insert_input_table(&window->key_map, XK_Escape, QUO_KEY_ESCAPE);
	quo_insert_input_table(&window->key_map, XK_Return, QUO_KEY_ENTER);
	quo_insert_input_table(&window->key_map, XK_BackSpace, QUO_KEY_BACKSPACE);
	quo_insert_input_table(&window->key_map, XK_Linefeed, QUO_KEY_ENTER);
	quo_insert_input_table(&window->key_map, XK_Pause, QUO_KEY_PAUSE);
	quo_insert_input_table(&window->key_map, XK_Scroll_Lock, QUO_KEY_SCROLL_LOCK);
	quo_insert_input_table(&window->key_map, XK_Tab, QUO_KEY_TAB);
	quo_insert_input_table(&window->key_map, XK_Delete, QUO_KEY_DELETE);
	quo_insert_input_table(&window->key_map, XK_Home, QUO_KEY_HOME);
	quo_insert_input_table(&window->key_map, XK_End, QUO_KEY_END);
	quo_insert_input_table(&window->key_map, XK_Page_Up, QUO_KEY_PAGE_UP);
	quo_insert_input_table(&window->key_map, XK_Page_Down, QUO_KEY_PAGE_DOWN);
	quo_insert_input_table(&window->key_map, XK_Insert, QUO_KEY_INSERT);
	quo_insert_input_table(&window->key_map, XK_Shift_L, QUO_KEY_LEFT_SHIFT);
	quo_insert_input_table(&window->key_map, XK_Shift_R, QUO_KEY_RIGHT_SHIFT);
	quo_insert_input_table(&window->key_map, XK_Control_L, QUO_KEY_LEFT_CONTROL);
	quo_insert_input_table(&window->key_map, XK_Control_R, QUO_KEY_RIGHT_CONTROL);
	quo_insert_input_table(&window->key_map, XK_space, QUO_KEY_SPACE);
	quo_insert_input_table(&window->key_map, XK_period, QUO_KEY_PERIOD);

	/* Number keys */
	quo_insert_input_table(&window->key_map, XK_0, QUO_KEY_0);
	quo_insert_input_table(&window->key_map, XK_1, QUO_KEY_1);
	quo_insert_input_table(&window->key_map, XK_2, QUO_KEY_2);
	quo_insert_input_table(&window->key_map, XK_3, QUO_KEY_3);
	quo_insert_input_table(&window->key_map, XK_4, QUO_KEY_4);
	quo_insert_input_table(&window->key_map, XK_5, QUO_KEY_5);
	quo_insert_input_table(&window->key_map, XK_6, QUO_KEY_6);
	quo_insert_input_table(&window->key_map, XK_7, QUO_KEY_7);
	quo_insert_input_table(&window->key_map, XK_8, QUO_KEY_8);
	quo_insert_input_table(&window->key_map, XK_9, QUO_KEY_9);

	/* Numpad keys */
	quo_insert_input_table(&window->key_map, XK_KP_0, QUO_KEY_NP_0);
	quo_insert_input_table(&window->key_map, XK_KP_1, QUO_KEY_NP_1);
	quo_insert_input_table(&window->key_map, XK_KP_2, QUO_KEY_NP_2);
	quo_insert_input_table(&window->key_map, XK_KP_3, QUO_KEY_NP_3);
	quo_insert_input_table(&window->key_map, XK_KP_4, QUO_KEY_NP_4);
	quo_insert_input_table(&window->key_map, XK_KP_5, QUO_KEY_NP_5);
	quo_insert_input_table(&window->key_map, XK_KP_6, QUO_KEY_NP_6);
	quo_insert_input_table(&window->key_map, XK_KP_7, QUO_KEY_NP_7);
	quo_insert_input_table(&window->key_map, XK_KP_8, QUO_KEY_NP_8);
	quo_insert_input_table(&window->key_map, XK_KP_9, QUO_KEY_NP_9);
	quo_insert_input_table(&window->key_map, XK_KP_Multiply, QUO_KEY_NP_MULTIPLY);
	quo_insert_input_table(&window->key_map, XK_KP_Add, QUO_KEY_NP_ADD);
	quo_insert_input_table(&window->key_map, XK_KP_Divide, QUO_KEY_NP_DIVIDE);
	quo_insert_input_table(&window->key_map, XK_KP_Subtract, QUO_KEY_NP_SUBTRACT);
	quo_insert_input_table(&window->key_map, XK_KP_Decimal, QUO_KEY_NP_DECIMAL);

	quo_insert_input_table(&window->key_map, XK_Caps_Lock, QUO_KEY_CAPS_LOCK);
}

static void quo_update_window_x11(quo_Window* window) {
	/* Swap window */
	glXSwapBuffers(window->display, window->window);
}

static void quo_update_window_events_x11(quo_Window* window) {
	/* Handle events */
	XEvent e;
	while (XPending(window->display)) {
		XNextEvent(window->display, &e);
		if (e.type == ClientMessage) {
			window->is_open = false;
		} else if (e.type == Expose) {
			XWindowAttributes gwa;
			XGetWindowAttributes(window->display, window->window, &gwa);
			glViewport(0, 0, gwa.width, gwa.height);

			window->width = gwa.width;
			window->height = gwa.height;
		} else if (e.type == KeyPress) {
			KeySym sym = XLookupKeysym(&e.xkey, 0);

			int key = quo_search_input_table(&window->key_map, sym);
			i_quo_set_key_held_state(key, true);
			i_quo_set_key_down_state(key, true);
		} else if (e.type == KeyRelease) {
			KeySym sym = XLookupKeysym(&e.xkey, 0);

			int key = quo_search_input_table(&window->key_map, sym);
			i_quo_set_key_held_state(key, false);
			i_quo_set_key_up_state(key, true);
		}
	}
}

#endif /* QUO_PLATFORM_X11 */

void quo_init_window(quo_Window* window, int w, int h, bool resizable) {
	assert(window != NULL);

	window->is_open = true;
	window->frame_time = 0;
	window->now_time = 0;
	window->old_time = 0;

#if defined(QUO_PLATFORM_X11)
	quo_init_window_x11(window, w, h, resizable);
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	quo_init_window_windows(window, w, h, resizable);
#endif

	quo_load_gl();

	quo_init_input_system();
}

void quo_set_window_title(quo_Window* window, const char* title) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_WINDOWS)
	wchar_t wchar_title[1024];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, title, -1, wchar_title, 1024);

	SetWindowText(window->hwnd, wchar_title);
#endif

#if defined(QUO_PLATFORM_X11)
	XStoreName(window->display, window->window, title);
#endif
}

void quo_update_window(quo_Window* window) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_X11)
	quo_update_window_x11(window);
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	quo_update_window_windows(window);
#endif

	window->now_time = quo_get_elapsed_time();
	window->frame_time = window->now_time - window->old_time;
	window->old_time = window->now_time;

	window->fps = 1.0f / window->frame_time;

	quo_update_input_system();
}

void quo_update_window_events(quo_Window* window) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_X11)
	quo_update_window_events_x11(window);
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	quo_update_window_events_windows(window);
#endif
}

void quo_free_window(quo_Window* window) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_X11)
	glXDestroyContext(window->display, window->device_context);

	XFreeColormap(window->display, window->color_map);

	XDestroyWindow(window->display, window->window);
	XCloseDisplay(window->display);
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	PostQuitMessage(0);
	DestroyWindow(window->hwnd);
	wglDeleteContext(window->render_context);
#endif
}
/* -----------------------
 * END WINDOW
 * -----------------------*/

/* -----------------------
 * START MATHS
 * -----------------------*/
quo_vec2 quo_add_vec2(quo_vec2 a, quo_vec2 b) {
	return (quo_vec2){a.x + b.x, a.y + b.y};
}

quo_vec2 quo_subtract_vec2(quo_vec2 a, quo_vec2 b) {
	return (quo_vec2){a.x - b.x, a.y - b.y};
}

quo_vec2 quo_multiply_vec2(quo_vec2 a, quo_vec2 b) {
	return (quo_vec2){a.x * b.x, a.y * b.y};
}

quo_vec2 quo_divide_vec2(quo_vec2 a, quo_vec2 b) {
	return (quo_vec2){a.x / b.x, a.y / b.y};
}

float quo_vec2_magnitude(quo_vec2 v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

float quo_dot_vec2(quo_vec2 a, quo_vec2 b) {
	return a.x * b.x + a.y * b.y;
}

quo_vec2 quo_normalise_vec2(quo_vec2 v) {
	float length = quo_vec2_magnitude(v);
	return (quo_vec2){v.x / length, v.y / length};
}

quo_vec3 quo_add_vec3(quo_vec3 a, quo_vec3 b) {
	return (quo_vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

quo_vec3 quo_subtract_vec3(quo_vec3 a, quo_vec3 b) {
	return (quo_vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

quo_vec3 quo_multiply_vec3(quo_vec3 a, quo_vec3 b) {
	return (quo_vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

quo_vec3 quo_divide_vec3(quo_vec3 a, quo_vec3 b) {
	return (quo_vec3){a.x / b.x, a.y / b.y, a.z / b.z};
}

float quo_vec3_magnitude(quo_vec3 v) {
	sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float quo_dot_vec3(quo_vec3 a, quo_vec3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

quo_vec3 quo_normalise_vec3(quo_vec3 v) {
	float length = quo_vec3_magnitude(v);
	return (quo_vec3){v.x / length, v.y / length, v.z / length};
}

quo_vec3 quo_cross_vec3(quo_vec3 a, quo_vec3 b) {
	return (quo_vec3){a.y * b.z - a.z * b.y,
					  a.z * b.x - a.x * b.z,
					  a.x * b.y - a.y * b.x};
}

quo_Matrix quo_identity() {
	quo_Matrix result;

	memset(result.elements, 0, 16 * sizeof(float));

	result.elements[0 + 0 * 4] = 1.0f;
	result.elements[1 + 1 * 4] = 1.0f;
	result.elements[2 + 2 * 4] = 1.0f;
	result.elements[3 + 3 * 4] = 1.0f;

	return result;
}

quo_Matrix quo_translate(quo_Matrix m, quo_vec3 translation) {
	m.elements[3 + 0 * 4] = translation.x;
	m.elements[3 + 1 * 4] = translation.y;
	m.elements[3 + 2 * 4] = translation.z;

	return m;
}

quo_Matrix quo_rotate(quo_Matrix m, float angle, quo_vec3 axis) {
	float r = quo_to_radians(angle);
	float c = cos(r);
	float s = sin(r);
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	m.elements[0 + 0 * 4] = x * x * omc + c;
	m.elements[0 + 1 * 4] = y * x * omc + z * s;
	m.elements[0 + 2 * 4] = x * z * omc - y * s;

	m.elements[1 + 0 * 4] = x * y * omc - z * s;
	m.elements[1 + 1 * 4] = y * y * omc + c;
	m.elements[1 + 2 * 4] = y * z * omc + x * s;

	m.elements[2 + 0 * 4] = x * z * omc + y * s;
	m.elements[2 + 1 * 4] = y * z * omc - x * s;
	m.elements[2 + 2 * 4] = z * z * omc + c;

	return m;
}

quo_Matrix quo_scale(quo_Matrix m, quo_vec3 scale) {
	m.elements[0 + 0 * 4] = scale.x;
	m.elements[1 + 1 * 4] = scale.y;
	m.elements[2 + 2 * 4] = scale.z;

	return m;
}

quo_Matrix quo_orthographic(float left, float right, float bottom, float top, float near_plane, float far_plane) {
	quo_Matrix result = quo_identity();

	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = 2.0f / (near_plane - far_plane);

	result.elements[3 + 0 * 4] = (left + right) / (left - right);
	result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.elements[3 + 2 * 4] = (far_plane + near_plane) / (far_plane - near_plane);

	return result;
}

quo_Matrix quo_perspective(float fov, float aspect, float near_plane, float far_plane) {
	quo_Matrix result = quo_identity();

	float q = 1.0f / tan(quo_to_radians(0.5f * fov));
	float a = q / aspect;

	float b = (near_plane + far_plane) / (near_plane - far_plane);
	float c = (2.0f * near_plane * far_plane) / (near_plane - far_plane);

	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = b;
	result.elements[2 + 3 * 4] = -1.0f;
	result.elements[3 + 2 * 4] = c;

	return result;
}

/* -----------------------
 * END MATHS
 * -----------------------*/

 /* -----------------------
  * START RENDERER
  * -----------------------*/

#define LOADBMP_RGB  3
#define LOADBMP_RGBA 4

bool quo_load_bitmap_from_file(const char* filename, quo_BitmapImage* image, unsigned int components) {
	assert(image != NULL);

	FILE *f = fopen(filename, "rb");

	if (!f) {
		printf("%s not found\n", filename);
		return false;
	}

	unsigned char bmp_file_header[14];
	unsigned char bmp_info_header[40];
	unsigned char bmp_pad[3];

	unsigned int w, h;
	unsigned char *data = NULL;

	unsigned int x, y, i, padding;

	memset(bmp_file_header, 0, sizeof(bmp_file_header));
	memset(bmp_info_header, 0, sizeof(bmp_info_header));

	if (fread(bmp_file_header, sizeof(bmp_file_header), 1, f) == 0) {
		fclose(f);
		printf("%s not a valid bmp file\n", filename);
		return false;
	}

	if (fread(bmp_info_header, sizeof(bmp_info_header), 1, f) == 0) {
		fclose(f);
		printf("%s not a valid bmp file\n", filename);
		return false;
	}

	if ((bmp_file_header[0] != 'B') || (bmp_file_header[1] != 'M')) {
		fclose(f);
		printf("%s has an invalid signature\n", filename);
		return false;
	}

	if ((bmp_info_header[14] != 24) && (bmp_info_header[14] != 32)) {
		fclose(f);
		printf("%s has invalid bits-per-pixel data\n", filename);
		return false;
	}

	w = (bmp_info_header[4] + (bmp_info_header[5] << 8) + (bmp_info_header[6] << 16) + (bmp_info_header[7] << 24));
	h = (bmp_info_header[8] + (bmp_info_header[9] << 8) + (bmp_info_header[10] << 16) + (bmp_info_header[11] << 24));

	if ((w > 0) && (h > 0)) {
		data = (unsigned char*)malloc(w * h * components);

		if (!data) {
			fclose(f);
			printf("Not enough memory to load %s\n", filename);
			return false;
		}

		for (y = (h - 1); y != -1; y--) {
			for (x = 0; x < w; x++) {
				i = (x + y * w) * components;

				if (fread(data + i, 3, 1, f) == 0) {
					free(data);

					fclose(f);
					printf("%s not a valid bmp file\n", filename);
					return false;
				}

				data[i] ^= data[i + 2] ^= data[i] ^= data[i + 2]; // BGR -> RGB

				if (components == LOADBMP_RGBA) {
					data[i + 3] = 255;
				}
			}

			padding = ((4 - (w * 3) % 4) % 4);

			if (fread(bmp_pad, 1, padding, f) != padding) {
				free(data);

				printf("%s not a valid bmp file\n", filename);
				return false;
			}
		}
	}

	image->width = w;
	image->height = h;
	image->pixels = data;

	fclose(f);

	return true;
}

void quo_free_bitmap(quo_BitmapImage* image) {
	assert(image != NULL);

	if (image->pixels) {
		free(image->pixels);
	}

	image->width = 0;
	image->height = 0;
}


void quo_init_texture_from_bmp(quo_BitmapImage* bitmap, quo_Texture* texture) {
	assert(texture != NULL);
	assert(bitmap != NULL);

	texture->width = bitmap->width;
	texture->height = bitmap->height;

	if (bitmap->pixels == NULL) {
		return;
	}

	glGenTextures(1, &texture->id);
	glBindTexture(GL_TEXTURE_2D, texture->id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	int mode = GL_RGB;

	glTexImage2D(GL_TEXTURE_2D, 0, mode, texture->width, texture->height, 0, mode, GL_UNSIGNED_BYTE, bitmap->pixels);
}

void quo_free_texture(quo_Texture* texture) {
	assert(texture != NULL);

	texture->width = 0;
	texture->height = 0;

	glDeleteTextures(1, &texture->id);
}

void quo_bind_texture(quo_Texture* texture, unsigned int unit) {
	assert(texture != NULL);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texture->id);
}

void quo_unbind_texture() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

static const char* g_quad_shader_vertex = "#version 330 core\n"
"layout (location = 0) in vec4 vertex;\n"

"uniform mat4 projection = mat4(1.0);\n"
"uniform mat4 model = mat4(1.0);\n"
"uniform mat4 view = mat4(1.0);\n"
"out vec2 uv;\n"

"uniform vec2 image_size;\n"
"uniform vec4 source_rect;\n"

"void main() {\n"
"vec2 texPos = vertex.zw;\n"
	"float widthPixel = 1.0f / image_size.x;\n"
	"float heightPixel = 1.0f / image_size.y;\n"
	"float startX = source_rect.x, startY = source_rect.y, width = source_rect.z, height = source_rect.w;\n"
	"uv = vec2(widthPixel * startX + width * widthPixel * texPos.x, heightPixel * startY + height * heightPixel * texPos.y);\n"
	"gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);\n"
"}\n";

static const char* g_quad_shader_fragment = "#version 330 core\n"
"out vec4 out_color;\n"

"in vec2 uv;\n"

"uniform vec3 color = vec3(1.0);\n"
"uniform sampler2D tex;\n"
"uniform bool use_tex = false;"

"void main() {\n"
	"vec4 tex_color = vec4(1.0f);"
	"if (use_tex) {\n"
		"tex_color = texture(tex, uv);\n"
	"}\n"

	"out_color = tex_color * vec4(color, 1.0);\n"
"}\n";

static void check_shader_errors(unsigned int shader) {
	int r;
	char info_log[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &r);
	if (!r) {
		glGetShaderInfoLog(shader, 1024, 0, info_log);
		fprintf(stderr, "Shader error %s\n", info_log);
	}
}

unsigned long quo_color_from_rgb(int r, int g, int b) {
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void quo_init_renderer(quo_Renderer* renderer, quo_Window* window) {
	assert(renderer != NULL);
	assert(window != NULL);

	renderer->shader_count = 0;
	renderer->window = window;

	for (unsigned int i = 0; i < QUO_MAX_SHADERS; i++) {
		renderer->shaders[i] = 0;
	}

	renderer->projection = quo_orthographic(0.0f, window->width, window->height, 0.0f, -1.0f, 1.0f);

	renderer->sprite_shader = quo_create_shader(renderer, g_quad_shader_vertex, g_quad_shader_fragment);

	float vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &renderer->quad_va);
	glGenBuffers(1, &renderer->quad_vb);

	glBindBuffer(GL_ARRAY_BUFFER, renderer->quad_vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(renderer->quad_va);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void quo_update_renderer(quo_Renderer* renderer) {
	assert(renderer != NULL);
	assert(renderer->window != NULL);

	renderer->projection = quo_orthographic(0.0f, renderer->window->width, renderer->window->height, 0.0f, -1.0f, 1.0f);
}

void quo_draw_rect(quo_Renderer* renderer, quo_Rect rect, unsigned long color) {
	assert(renderer != NULL);

	quo_Matrix model = quo_identity();
	model = quo_translate(model, (quo_vec3){rect.x, rect.y, 0});
	model = quo_scale(model, (quo_vec3){rect.w, rect.h, 1});

	quo_bind_shader(renderer, renderer->sprite_shader);

	quo_shader_set_matrix(renderer, renderer->sprite_shader, "model", model);
	quo_shader_set_matrix(renderer, renderer->sprite_shader, "projection", renderer->projection);
	quo_shader_set_color(renderer, renderer->sprite_shader, "color", color);
	quo_shader_set_int(renderer, renderer->sprite_shader, "use_tex", 0);

	glBindVertexArray(renderer->quad_va);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void quo_draw_texture(quo_Renderer* renderer, quo_Texture* texture, quo_Rect src, quo_Rect dest, unsigned long color) {
	assert(renderer != NULL);
	assert(texture != NULL);

	quo_Matrix model = quo_identity();
	model = quo_translate(model, (quo_vec3){dest.x, dest.y, 0});
	model = quo_scale(model, (quo_vec3){dest.w, dest.h, 1});

	quo_bind_shader(renderer, renderer->sprite_shader);

	quo_shader_set_matrix(renderer, renderer->sprite_shader, "model", model);
	quo_shader_set_matrix(renderer, renderer->sprite_shader, "projection", renderer->projection);
	quo_shader_set_color(renderer, renderer->sprite_shader, "color", color);
	quo_shader_set_int(renderer, renderer->sprite_shader, "use_tex", 1);
	quo_shader_set_vec2(renderer, renderer->sprite_shader, "image_size", texture->width, texture->height);
	quo_shader_set_vec4(renderer, renderer->sprite_shader, "source_rect", src.x, src.y, src.w, src.h);

	quo_bind_texture(texture, 0);
	quo_shader_set_int(renderer, renderer->sprite_shader, "tex", 0);

	glBindVertexArray(renderer->quad_va);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void quo_free_renderer(quo_Renderer* renderer) {
	assert(renderer != NULL);

	for (unsigned int i = 0; i < renderer->shader_count; i++) {
		glDeleteProgram(&renderer->shaders[i]);
	}

	glDeleteVertexArrays(1, &renderer->quad_va);
	glDeleteBuffers(1, &renderer->quad_vb);
}

void quo_clear_renderer(unsigned long color) {
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	float rf = (float)r / 255.0f;
	float gf = (float)g / 255.0f;
	float bf = (float)b / 255.0f;

	glClearColor(rf, gf, bf, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

quo_ShaderHandle quo_create_shader(quo_Renderer* renderer, const char* vertex_source, const char* fragment_source) {
	assert(renderer != NULL);

	if (renderer->shader_count > QUO_MAX_SHADERS) {
		fprintf(stderr, "Failed to create shader: Shader count too high (max %d)\n", QUO_MAX_SHADERS);
		return 0;
	}

	unsigned int program = glCreateProgram();

	unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(vertex_shader);
	check_shader_errors(vertex_shader);

	unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(fragment_shader);
	check_shader_errors(fragment_shader);

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	unsigned int index = renderer->shader_count++;

	renderer->shaders[index] = program;

	return index;
}

void quo_bind_shader(quo_Renderer* renderer, quo_ShaderHandle shader) {
	assert(renderer != NULL);

	glUseProgram(renderer->shaders[shader]);
}

void quo_shader_set_color(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, unsigned long color) {
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = color & 0xFF;

	float rf = (float)r / 255.0f;
	float gf = (float)g / 255.0f;
	float bf = (float)b / 255.0f;

	quo_shader_set_vec3(renderer, shader, uniform_name, rf, gf, bf);
}

void quo_shader_set_float(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float val) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniform1f(location, val);
}

void quo_shader_set_int(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, int val) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniform1i(location, val);
}

void quo_shader_set_matrix(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, quo_Matrix m) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniformMatrix4fv(location, 1, true, m.elements);
}

void quo_shader_set_vec2(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniform2f(location, x, y);
}

void quo_shader_set_vec3(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y, float z) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniform3f(location, x, y, z);
}

void quo_shader_set_vec4(quo_Renderer* renderer, quo_ShaderHandle shader, const char* uniform_name, float x, float y, float z, float w) {
	assert(renderer != NULL);
	assert(shader < renderer->shader_count);

	unsigned int shader_id = renderer->shaders[shader];
	unsigned int location = glGetUniformLocation(shader_id, uniform_name);

	glUniform4f(location, x, y, z, w);
}

/* -----------------------
 * END RENDERER
 * -----------------------*/

/* -----------------------
 * START INPUT
 * -----------------------*/

/* Static quo_InputSystem */
static quo_InputSystem input_system;

void quo_init_input_system() {
	memset(input_system.held_keys, 0, QUO_KEY_COUNT * sizeof(bool));
}

void quo_update_input_system() {
	memset(input_system.down_keys, 0, QUO_KEY_COUNT * sizeof(bool));
	memset(input_system.up_keys, 0, QUO_KEY_COUNT * sizeof(bool));
}

bool quo_key_pressed(int key) {
	return input_system.held_keys[key];
}

bool quo_key_just_pressed(int key) {
	return input_system.down_keys[key];
}

bool quo_key_just_released(int key) {
	return input_system.up_keys[key];
}

void i_quo_set_key_held_state(int key, bool status) {
	input_system.held_keys[key] = status;
}

void i_quo_set_key_down_state(int key, bool status) {
	input_system.down_keys[key] = status;
}

void i_quo_set_key_up_state(int key, bool status) {
	input_system.up_keys[key] = status;
}

/* -----------------------
 * END INPUT
 * -----------------------*/

#endif

#ifdef __cplusplus
}
#endif

