#define QUO_IMPL
#include <quo.h>

static const char* vshader = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec2 tex_coord;\n"

"uniform mat4 model;\n"
"uniform mat4 projection;\n"

"out vec2 uv;\n"

"void main() {\n"
	"uv = tex_coord;\n"

	"gl_Position = projection * model * vec4(position, 1.0);\n"
"}\n";

static const char* fshader = "#version 330 core\n"
"out vec4 color;\n"

"in vec2 uv;\n"

"uniform sampler2D albedo;\n"

"void main() {\n"
	"color = texture2D(albedo, uv);\n"
"}\n";


int main() {
	quo_Window window;
	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);
	quo_enable_3d();

	quo_init_imgui(&renderer);
	quo_imgui_use_default_settings();

	quo_ShaderHandle cube_shader = quo_create_shader(&renderer, vshader, fshader);
	quo_bind_shader(&renderer, cube_shader);

	float vertices[] = {
		1.0f, 1.0f, -1.0f, 0.625, 0.500,
		-1.0f, 1.0f, -1.0f, 0.875, 0.500,
		-1.0f, 1.0f, 1.0f, 0.875, 0.750,
		1.0f, 1.0f, -1.0f, 0.625, 0.500,
		-1.0f, 1.0f, 1.0f, 0.875, 0.750,
		1.0f, 1.0f, 1.0f, 0.625, 0.750,
		1.0f, -1.0f, 1.0f, 0.375, 0.750,
		1.0f, 1.0f, 1.0f, 0.625, 0.750,
		-1.0f, 1.0f, 1.0f, 0.625, 1.0f,
		1.0f, -1.0f, 1.0f, 0.375, 0.750,
		-1.0f, 1.0f, 1.0f, 0.625, 1.0f,
		-1.0f, -1.0f, 1.0f, 0.375, 1.0f,
		-1.0f, -1.0f, 1.0f, 0.375, 0.0f,
		-1.0f, 1.0f, 1.0f, 0.625, 0.0f,
		-1.0f, 1.0f, -1.0f, 0.625, 0.250,
		-1.0f, -1.0f, 1.0f, 0.375, 0.0f,
		-1.0f, 1.0f, -1.0f, 0.625, 0.250,
		-1.0f, -1.0f, -1.0f, 0.375, 0.250,
		-1.0f, -1.0f, -1.0f, 0.125, 0.500,
		1.0f, -1.0f, -1.0f, 0.375, 0.500,
		1.0f, -1.0f, 1.0f, 0.375, 0.750,
		-1.0f, -1.0f, -1.0f, 0.125, 0.500,
		1.0f, -1.0f, 1.0f, 0.375, 0.750,
		-1.0f, -1.0f, 1.0f, 0.125, 0.750,
		1.0f, -1.0f, -1.0f, 0.375, 0.500,
		1.0f, 1.0f, -1.0f, 0.625, 0.500,
		1.0f, 1.0f, 1.0f, 0.625, 0.750,
		1.0f, -1.0f, -1.0f, 0.375, 0.500,
		1.0f, 1.0f, 1.0f, 0.625, 0.750,
		1.0f, -1.0f, 1.0f, 0.375, 0.750,
		-1.0f, -1.0f, -1.0f, 0.375, 0.250,
		-1.0f, 1.0f, -1.0f, 0.625, 0.250,
		1.0f, 1.0f, -1.0f, 0.625, 0.500,
		-1.0f, -1.0f, -1.0f, 0.375, 0.250,
		1.0f, 1.0f, -1.0f, 0.625, 0.500,
		1.0f, -1.0f, -1.0f, 0.375, 0.500,
	};

	unsigned int indices[] = {
		0, 1, 2, 3, 4, 5, 6, 7,
		8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31,
		32, 33, 34, 35,
	};

	quo_VertexBuffer cube_vb;
	quo_begin_vertex_buffer(&cube_vb);
	quo_push_vertices(&cube_vb, vertices, sizeof(vertices));
	quo_push_indices(&cube_vb, indices, sizeof(indices)/sizeof(indices[0]));
	quo_configure_vertices(&cube_vb, 0, 3, 5, 0);
	quo_configure_vertices(&cube_vb, 1, 2, 5, sizeof(float)*3);
	quo_finalise_vertex_buffer(&cube_vb);

	quo_BitmapImage image;
	quo_load_bitmap_from_file("res/unnamed.bmp", &image, 3);

	quo_Texture texture;
	quo_init_texture_from_bmp(&texture, &image, QUO_TEXTUREFLAGS_ANTIALIASED);

	quo_Matrix projection = quo_perspective(45.0f, (float)100.0f / (float)100.0f, 0.1f, 100.0f);

	quo_Matrix cube_model = quo_translate(quo_identity(), (quo_vec3){0.0f, 0.0f, -10.0f});

	quo_RenderTarget render_target;
	quo_init_render_target(&render_target, 100, 100);

	float rotation = 0.0f;
	while (window.is_open) {
		quo_update_window_events(&window);

		rotation += window.frame_time * 10000;
		cube_model = quo_rotate(cube_model, rotation, (quo_vec3){0.0f, 1.0f, 0.0f});

		quo_bind_render_target(&render_target);
		quo_clear_renderer(0xff0000);

		quo_bind_shader(&renderer, cube_shader);

		quo_bind_texture(&texture, 0);
		quo_shader_set_int(&renderer, cube_shader, "albedo", 0);

		quo_shader_set_matrix(&renderer, cube_shader, "projection", projection);
		quo_shader_set_matrix(&renderer, cube_shader, "model", cube_model);
		quo_draw_vertex_buffer(&cube_vb);

		quo_bind_default_render_target();
		quo_clear_renderer(0x000000);

		quo_bind_default_shader(&renderer);
		quo_draw_texture(&renderer, &render_target.output, (quo_Rect){0, 0, 100, 100}, (quo_Rect){100, 100, 100, 100}, 0xffffff);
		quo_draw_texture(&renderer, &render_target.output, (quo_Rect){0, 0, 100, 100}, (quo_Rect){100, 240, 100, 100}, 0xffffff);
		quo_draw_texture(&renderer, &render_target.output, (quo_Rect){0, 0, 100, 100}, (quo_Rect){300, 100, 100, 100}, 0xffffff);
		quo_draw_texture(&renderer, &render_target.output, (quo_Rect){0, 0, 100, 100}, (quo_Rect){300, 300, 200, 200}, 0xffffff);
		quo_imgui_text("Hello, welcome the offscreen-rendering demo!\nHere's a simple, textured cube,\nrendered once offscreen onto a quo_Texture\nand then drawn on the screen multiple times.");

		quo_imgui_end_frame();

		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	quo_free_vertex_buffer(&cube_vb);

	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
