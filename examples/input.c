#define QUO_IMPL
#include <quo.h>

/* NOTE: A window is required for input to work. A renderer is optional */

/* Print inputted text as characters */
static void char_callback(char* characters) {
	printf("%s\n", characters);
}

int main() {
	/* Create window */
	quo_Window window;
	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	/* Create renderer */
	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	/* Set the character callback */
	quo_set_character_callback(char_callback);

	/* Game loop */
	while (window.is_open) {
		/* Update window event */
		quo_update_window_events(&window);

		/* Clear to a solid black colour */
		quo_clear_renderer(0x000000);

		/* Check if the space key is currently pressed */
		if (quo_key_pressed(QUO_KEY_SPACE)) {
			printf("Space key held\n");
		}

		/* Check if the space key has been pressed in the current frame */
		if (quo_key_just_pressed(QUO_KEY_SPACE)) {
			printf("Space key pressed\n");
		}

		/* Check if the space key has been released in the current frame */
		if (quo_key_just_released(QUO_KEY_SPACE)) {
			printf("Space key released\n");
		}

		/* Check if the left mouse button has been pressed in the current frame */
		if (quo_mouse_button_just_pressed(QUO_MOUSE_BUTTON_LEFT)) {
			/* Print the mouse position */
			printf("%d, %d\n", quo_get_mouse_x(), quo_get_mouse_y());
		}

		/* Update window and renderer */
		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	/* Clean up */
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
