#pragma once

/* Standard includes */
#include <stdbool.h>

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

/* Load a bitmap from a file. Returnes true on success */
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
void quo_draw_texture(quo_Renderer* renderer, quo_Texture* texture, quo_Rect rect, unsigned long color);

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

/* 3D rendering */

/* Represents a 3D mesh */
typedef struct quo_3dMesh {
	unsigned int va, vb, ib;
	unsigned int index_count;
} quo_3dMesh;

typedef struct quo_Vertex {
	quo_vec3 position;
	quo_vec3 normal;
	quo_vec2 uv;
} quo_Vertex;

/* Initialise a 3D mesh from raw data */
void quo_init_3d_mesh(quo_3dMesh* mesh, quo_Vertex* vertices, unsigned int* indices, unsigned int index_count);
void quo_free_3d_mesh(quo_3dMesh* mesh);

/* -----------------------
 * END RENDERER
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

/* Win32 event callback */
#if defined(QUO_PLATFORM_WINDOWS)
static LRESULT CALLBACK quo_win32_event_callback(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	LONG_PTR lpUserData = GetWindowLongPtr(hwnd, GWLP_USERDATA);
	quo_Window* q_window = (quo_Window*)lpUserData;

	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			DestroyWindow(hwnd);
			q_window->is_open = false;
			return 0;
		case WM_SIZE:
			if (q_window) {
				q_window->width = lparam & 0xFFFF;
				q_window->height = (lparam >> 16) & 0xFFFF;
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
	DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE;

	if (resizable) {
		dwStyle |= WS_THICKFRAME;
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
}

static void quo_update_window_windows(quo_Window* window) {
	SwapBuffers(window->device_context);

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
}

static void quo_update_window_x11(quo_Window* window) {
	/* Swap window */
	glXSwapBuffers(window->display, window->window);

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
	sqrt(v.x * v.x + v.y * v.y);
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

"void main() {\n"
	"uv = vertex.zw;\n"
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

	glBindVertexArray(renderer->quad_va);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void quo_draw_texture(quo_Renderer* renderer, quo_Texture* texture, quo_Rect rect, unsigned long color) {
	assert(renderer != NULL);
	assert(texture != NULL);

	quo_Matrix model = quo_identity();
	model = quo_translate(model, (quo_vec3){rect.x, rect.y, 0});
	model = quo_scale(model, (quo_vec3){rect.w, rect.h, 1});

	quo_bind_shader(renderer, renderer->sprite_shader);

	quo_shader_set_matrix(renderer, renderer->sprite_shader, "model", model);
	quo_shader_set_matrix(renderer, renderer->sprite_shader, "projection", renderer->projection);
	quo_shader_set_color(renderer, renderer->sprite_shader, "color", color);
	quo_shader_set_int(renderer, renderer->sprite_shader, "use_tex", 1);

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

void quo_init_3d_mesh(quo_3dMesh* mesh, quo_Vertex* vertices, unsigned int* indices, unsigned int index_count) {
	assert(mesh != NULL);

	mesh->index_count = index_count;

	glGenVertexArrays(1, &mesh->va);
	glGenBuffers(1, &mesh->vb);
	glGenBuffers(1, &mesh->ib);

	glBindVertexArray(mesh->va);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vb);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* Vertex position */
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(quo_Vertex), NULL);

	/* Vertex normal */
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(quo_Vertex), (void*)offsetof(quo_Vertex, normal));

	/* Vertex UV */
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(quo_Vertex), (void*)offsetof(quo_Vertex, uv));
}

void quo_free_3d_mesh(quo_3dMesh* mesh) {
	glDeleteVertexArrays(1, &mesh->va);
	glDeleteBuffers(1, &mesh->vb);
	glDeleteBuffers(1, &mesh->ib);
}

/* -----------------------
 * END RENDERER
 * -----------------------*/

#endif
