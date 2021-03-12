#define QUO_IMPL
#include <quo.h>

int main() {
	quo_Window window;

	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	quo_BitmapImage image;
	quo_load_bitmap_from_file("res/smiley.bmp", &image, 3);

	quo_Texture texture;
	quo_init_texture_from_bmp(&texture, &image);

	quo_free_bitmap(&image);

	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	while (window.is_open) {
		quo_update_window_events(&window);

		quo_clear_renderer(0x000000);

		quo_draw_texture(&renderer, &texture, (quo_Rect){0, 0, 13, 13}, (quo_Rect){100, 100, 50, 50}, 0xffffff);

		if (quo_key_just_pressed(QUO_KEY_SPACE)) {
			printf("%d, %d\n", quo_get_mouse_x(), quo_get_mouse_y());
		}

		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	quo_free_texture(&texture);
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
