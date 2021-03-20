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

	/* Initialise the IMGUI */
	quo_init_imgui(&renderer);
	quo_imgui_use_default_settings();

	/* Game loop */
	while (window.is_open) {
		/* Update window event */
		quo_update_window_events(&window);

		/* Clear to a solid black colour */
		quo_clear_renderer(0x000000);

		/* Display some text using the IMGUI */
		quo_imgui_text("Hello, world!");

		/* An IMGUI button */
		if (quo_imgui_button("Click me!")) {
			printf("The button has been clicked!\n");
		}

		/* Reset the IMGUI and prepare it for the next frame */
		quo_imgui_end_frame();

		/* Update window and renderer */
		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	/* Clean up */
	quo_free_imgui();
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
