# Quo

**A single-header, zero dependency game library written in C**

This library is standalone, meaning it doesn't depend on anything that doesn't come with the operating system.

## Current Features
 - Window management for Windows and X11
 - 2D rendering
 - Basic maths

## Planned Features
 - Input
 - 3D rendering pipeline
 - Wayland and Android support
 - Audio
 - MacOS support (This is going to take a while, as it will mean adding support for Metal as well as OpenGL, since MacOS's OpenGL support is pretty shaky).

## Example Usage
See a more complete example in the `sbox` folder.

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
