![q](https://github.com/georgelam6/quo/blob/master/q.png)

**A single-header, zero dependency game library written in C99**

This library is standalone, meaning it doesn't depend on anything that doesn't come with the operating system. It is designed to be easy to use and beginner friendly, and can be used as a base for simple 2D game projects

Inspired by MrFrenik's [Gunslinger](https://github.com/MrFrenik/gunslinger/) library, but smaller,
simpler and easier to integrate into projects, though not nearly as powerful.

## Documentation
You can view the Doxygen generated documentation here: https://georgelamb.net/quo/html/quo_8h.html

## Current Features
 - Window management for Windows and Linux (X11)
 - 2D rendering
 - Basic maths
 - Input
 - Binary serialisation
 - 3D rendering API
 - Offscreen rendering

## Planned Features
 - Wayland, Emscripten and Android support
 - Audio API

## Compiling
You must `#define QUO_IMPL` in **one** c/cpp file before including the header, to provide an implementation.

On Linux you must link with `libX11`, `libGL`, and `libm` to avoid linking errors.

On Windows with MSVC, linking is done automatically via `#pragma comment`s. On none-MSVC Windows compilers, you must link with `user32.lib`, `gdi32.lib` and `opengl32.lib`.

## Configuration
For older computers, you can enable the use of GLSL version 1.3 in the default sprite shader, by `#defining QUO_LEGACY_SHADERS` before including the library.

By default, Quo includes a bitmap loader, but if you want to load other formats such as PNG and JPEG images, you may enable the use of STB image by Sean Barret through the `#define QUO_USE_STB_IMAGE` macro. You must download [`stb_image.h`](https://github.com/nothings/stb/blob/master/stb_image.h) and place it next to `quo.h` first, though. The library's usage does not change, only the internal method of loading images.

## Example Usage
See more complete examples in the [`examples`](https://github.com/georgelam6/quo/tree/master/examples) folder.

```c
#define QUO_IMPL
#include <quo.h>

int main() {
	/* Create window */
	quo_Window window;
	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	/* Create renderer */
	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	/* Game loop */
	while (window.is_open) {
		/* Update window event */
		quo_update_window_events(&window);

		/* Clear to a solid black colour */
		quo_clear_renderer(0x000000);

		/* Draw a red rectangle */
		quo_draw_rect(&renderer, (quo_Rect){100, 100, 50, 50}, 0xff1100);

		/* Print the FPS when the space key is pressed */
		if (quo_key_pressed(QUO_KEY_SPACE)) {
			printf("FPS: %g\n", window.fps);
		}

		/* Update window and renderer */
		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	/* Clean up */
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
```
