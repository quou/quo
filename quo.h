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

/* Load all OpenGL functions */
void quo_load_gl();

/* -----------------------
 * START WINDOW
 * -----------------------*/

/* Window struct */
typedef struct quo_Window {
	quo_GLDeviceContext device_context;
	quo_GLRenderContext render_context;

	bool is_open;
	int width, height;

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
void quo_init_window(quo_Window* window, int w, int h);
void quo_set_window_title(quo_Window* window, const char* title);
void quo_update_window(quo_Window* window);
void quo_free_window(quo_Window* window);

/* -----------------------
 * END WINDOW
 * -----------------------*/

 /* -----------------------
 * START MATHS
 * -----------------------*/
/* A 4x4 matrix structure, and it's operational functions */
typedef struct quo_Matrix {
	float elements[16];
} quo_Matrix;

quo_Matrix quo_identity();
quo_Matrix quo_translate(quo_Matrix m, float x, float y, float z);
quo_Matrix quo_scale(quo_Matrix m, float x, float y, float z);
quo_Matrix quo_orthographic(float left, float right, float bottom, float top, float near, float far);
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

/* To be used as an index into the renderer's shader array */
typedef unsigned int quo_ShaderHandle;

/* Responsible for drawing things to the screen */
typedef struct quo_Renderer {
	quo_Window* window;
	quo_Matrix projection;

	quo_ShaderHandle sprite_shader;

	unsigned int quad_va;

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
void quo_draw_quad(quo_Renderer* renderer, quo_Rect src, quo_Rect dest, unsigned long color);

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
#include <stdio.h>
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
		case WM_DESTROY: PostQuitMessage(0); DestroyWindow(hwnd); q_window->is_open = false; return 0;
		default:
			break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}
#endif

void quo_init_window(quo_Window* window, int w, int h) {
	assert(window != NULL);

	window->is_open = true;

	/* Open X11 window */
#if defined(QUO_PLATFORM_X11)
	window->display = XOpenDisplay(NULL);
	window->window_root = DefaultRootWindow(window->display);

	/* Configure window */
	int gl_attribs[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	window->visual_info = glXChooseVisual(window->display, 0, gl_attribs);
	window->color_map = XCreateColormap(window->display, window->window_root, window->visual_info->visual, AllocNone);
	window->set_window_attribs.colormap = window->color_map;

	/* Let X11 know which events we are interested in */
	window->set_window_attribs.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | FocusChangeMask | StructureNotifyMask;

	/* Create the window */
	window->window = XCreateWindow(window->display, window->window_root, 0, 0, w, h, 0, window->visual_info->depth, InputOutput, window->visual_info->visual, CWColormap | CWEventMask, &window->set_window_attribs);

	/* Remap close event */
	Atom atomWmDeleteWindow = XInternAtom(window->display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(window->display, window->window, &atomWmDeleteWindow, 1);

	/* Display the window */
	XClearWindow(window->display, window->window);
	XMapRaised(window->display, window->window);

	/* Create OpenGL context */
	window->device_context = glXCreateContext(window->display, window->visual_info, NULL, GL_TRUE);
	glXMakeCurrent(window->display, window->window, window->device_context);

	XWindowAttributes gwa;
	XGetWindowAttributes(window->display, window->window, &gwa);
	glViewport(0, 0, gwa.width, gwa.height);

	window->width = gwa.width;
	window->height = gwa.height;
#endif

#if defined(QUO_PLATFORM_WINDOWS)
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
	DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_THICKFRAME;

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
#endif

	quo_load_gl();
}

void quo_set_window_title(quo_Window* window, const char* title) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_WINDOWS)
	SetWindowText(window->hwnd, title);
#endif

#if defined(QUO_PLATFORM_X11)
	XStoreName(window->display, window->window, title);
#endif
}

void quo_update_window(quo_Window* window) {
	assert(window != NULL);

#if defined(QUO_PLATFORM_X11)
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
#endif

#if defined(QUO_PLATFORM_WINDOWS)
	SwapBuffers(window->device_context);

	/* Poll for events, handled in quo_win32_event_callback */
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
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
	wglDeleteContext(window->render_context);
#endif
}
/* -----------------------
 * END WINDOW
 * -----------------------*/

 /* -----------------------
 * START MATHS
 * -----------------------*/
quo_Matrix quo_identity() {
	quo_Matrix result;

	memset(result.elements, 0, 16 * sizeof(float));

	result.elements[0 + 0 * 4] = 1.0f;
	result.elements[1 + 1 * 4] = 1.0f;
	result.elements[2 + 2 * 4] = 1.0f;
	result.elements[3 + 3 * 4] = 1.0f;

	return result;
}

quo_Matrix quo_translate(quo_Matrix m, float x, float y, float z) {
	m.elements[3 + 0 * 4] = x;
	m.elements[3 + 1 * 4] = y;
	m.elements[3 + 2 * 4] = z;

	return m;
}

quo_Matrix quo_scale(quo_Matrix m, float x, float y, float z) {
	m.elements[0 + 0 * 4] = x;
	m.elements[1 + 1 * 4] = y;
	m.elements[2 + 2 * 4] = z;

	return m;
}

quo_Matrix quo_orthographic(float left, float right, float bottom, float top, float near, float far) {
	quo_Matrix result = quo_identity();

	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = 2.0f / (near - far);

	result.elements[3 + 0 * 4] = (left + right) / (left - right);
	result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.elements[3 + 2 * 4] = (far + near) / (far - near);

	return result;
}
 /* -----------------------
 * END MATHS
 * -----------------------*/

 /* -----------------------
 * START RENDERER
 * -----------------------*/

static const char* g_quad_shader_vertex = "#version 330 core\n"
"layout (location = 0) in vec4 vertex;\n"
"uniform mat4 projection = mat4(1.0);\n"
"uniform mat4 model = mat4(1.0);\n"
"uniform mat4 view = mat4(1.0);\n"
"void main() {\n"
"gl_Position = projection * view * model * vec4(vertex.xy, 0.0, 1.0);\n"
"}\n";

static const char* g_quad_shader_fragment = "#version 330 core\n"
"out vec4 out_color;\n"
"uniform vec3 color = vec3(1.0);\n"
"void main() {\n"
"out_color = vec4(color, 1.0);\n"
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

	unsigned int quad_vb;
	float vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &renderer->quad_va);
	glGenBuffers(1, &quad_vb);

	glBindBuffer(GL_ARRAY_BUFFER, quad_vb);
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

void quo_draw_quad(quo_Renderer* renderer, quo_Rect src, quo_Rect dest, unsigned long color) {
	assert(renderer != NULL);

	quo_Matrix model = quo_identity();
	model = quo_translate(model, dest.x, dest.y, 0);
	model = quo_scale(model, dest.w, dest.h, 1);

	quo_bind_shader(renderer, renderer->sprite_shader);

	quo_shader_set_matrix(renderer, renderer->sprite_shader, "model", model);
	quo_shader_set_matrix(renderer, renderer->sprite_shader, "projection", renderer->projection);
	quo_shader_set_color(renderer, renderer->sprite_shader, "color", color);

	glBindVertexArray(renderer->quad_va);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void quo_free_renderer(quo_Renderer* renderer) {
	assert(renderer != NULL);

	for (unsigned int i = 0; i < renderer->shader_count; i++) {
		glDeleteProgram(&renderer->shaders[i]);
	}
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

#endif
