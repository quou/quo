#define QUO_IMPL
#include <quo.h>

static void char_callback(char* characters) {
	printf("%s\n", characters);
}

int main() {
	quo_Window window;
	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	quo_set_character_callback(char_callback);

	while (window.is_open) {
		quo_update_window_events(&window);

		quo_clear_renderer(0x000000);

		quo_draw_rect(&renderer, (quo_Rect){100, 100, 50, 50}, 0xff1100);

		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
