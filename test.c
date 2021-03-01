#define QUO_IMPL
#include "quo.h"

int main() {
	quo_Window window;

	quo_init_window(&window, 640, 480);
	quo_set_window_title(&window, "quo example program");

	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	while (window.is_open) {
		quo_clear_renderer(0x000000);

		quo_draw_quad(&renderer, (quo_Rect){0, 0, 0, 0}, (quo_Rect){100, 100, 50, 50}, 0xbd4d4d);

		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	quo_free_renderer(&renderer);

	quo_free_window(&window);
}
