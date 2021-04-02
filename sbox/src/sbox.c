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

	/* Load the image from a .bmp file */
	quo_BitmapImage image;
	quo_load_bitmap_from_file("res/smiley.bmp", &image, 3);

	/* Convert the bitmap into a texture that lives on the GPU */
	quo_Texture texture;
	quo_init_texture_from_bmp(&texture, &image, QUO_TEXTUREFLAGS_ALIASED);

	/* The bitmap has been sent to the GPU, we don't need it anymore */
	quo_free_bitmap(&image);

	/* Game loop */
	while (window.is_open) {
		/* Update window events */
		quo_update_window_events(&window);

		/* Clear the screen to black */
		quo_clear_renderer(0x000000);

		/* Draw the texture */
		quo_draw_texture(&renderer, &texture, (quo_Rect){0, 0, texture.width, texture.height}, (quo_Rect){100, 100, 50, 50}, 0xffffff);

		/* Update the window & renderer */
		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	/* Free the texture */
	quo_free_texture(&texture);

	/* Free the window & renderer */
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
