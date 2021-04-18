#define QUO_IMPL
#include <quo.h>

/* GLSL vertex shader source. In a real program this should be loaded from disk */
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

/* GLSL fragment shader source. In a real program this should be loaded from disk */
static const char* fshader = "#version 330 core\n"
"out vec4 color;\n"

"in vec2 uv;\n"

"uniform sampler2D albedo;\n"

"void main() {\n"
	"color = texture2D(albedo, uv);\n"
"}\n";


int main() {
	/* Create the window */
	quo_Window window;
	quo_init_window(&window, 640, 480, false);
	quo_set_window_title(&window, "quo example program");

	/* Initialise the renderer */
	quo_Renderer renderer;
	quo_init_renderer(&renderer, &window);

	/* Optional: Enable 3D features such as depth-testing,
	 * will slow down the program if 3D features are not
	 * needed. */
	quo_enable_3d();

	/* Create the cube shader */
	quo_ShaderHandle cube_shader = quo_create_shader(&renderer, vshader, fshader);
	quo_bind_shader(&renderer, cube_shader);

	/* Vertex array */
	float vertices[] = {
		/* Vertex positions		Vertex UV coordinates*/
		 1.0f,  1.0f, -1.0f, 	0.625, 0.500,
		-1.0f,  1.0f, -1.0f, 	0.875, 0.500,
		-1.0f,  1.0f,  1.0f, 	0.875, 0.750,
		 1.0f,  1.0f, -1.0f, 	0.625, 0.500,
		-1.0f,  1.0f,  1.0f, 	0.875, 0.750,
		 1.0f,  1.0f,  1.0f, 	0.625, 0.750,
		 1.0f, -1.0f,  1.0f, 	0.375, 0.750,
		 1.0f,  1.0f,  1.0f, 	0.625, 0.750,
		-1.0f,  1.0f,  1.0f, 	0.625, 1.0f,
		 1.0f, -1.0f,  1.0f, 	0.375, 0.750,
		-1.0f,  1.0f,  1.0f, 	0.625, 1.0f,
		-1.0f, -1.0f,  1.0f, 	0.375, 1.0f,
		-1.0f, -1.0f,  1.0f, 	0.375, 0.0f,
		-1.0f,  1.0f,  1.0f, 	0.625, 0.0f,
		-1.0f,  1.0f, -1.0f, 	0.625, 0.250,
		-1.0f, -1.0f,  1.0f, 	0.375, 0.0f,
		-1.0f,  1.0f, -1.0f, 	0.625, 0.250,
		-1.0f, -1.0f, -1.0f, 	0.375, 0.250,
		-1.0f, -1.0f, -1.0f, 	0.125, 0.500,
		 1.0f, -1.0f, -1.0f, 	0.375, 0.500,
		 1.0f, -1.0f,  1.0f, 	0.375, 0.750,
		-1.0f, -1.0f, -1.0f, 	0.125, 0.500,
		 1.0f, -1.0f,  1.0f, 	0.375, 0.750,
		-1.0f, -1.0f,  1.0f, 	0.125, 0.750,
		 1.0f, -1.0f, -1.0f, 	0.375, 0.500,
		 1.0f,  1.0f, -1.0f, 	0.625, 0.500,
		 1.0f,  1.0f,  1.0f, 	0.625, 0.750,
		 1.0f, -1.0f, -1.0f, 	0.375, 0.500,
		 1.0f,  1.0f,  1.0f, 	0.625, 0.750,
		 1.0f, -1.0f,  1.0f, 	0.375, 0.750,
		-1.0f, -1.0f, -1.0f, 	0.375, 0.250,
		-1.0f,  1.0f, -1.0f, 	0.625, 0.250,
		 1.0f,  1.0f, -1.0f, 	0.625, 0.500,
		-1.0f, -1.0f, -1.0f, 	0.375, 0.250,
		 1.0f,  1.0f, -1.0f, 	0.625, 0.500,
	 	1.0f, -1.0f, -1.0f, 	0.375, 0.500,
	};

	/* Indices to avoid drawing double vertices */
	unsigned int indices[] = {
		0, 1, 2, 3, 4, 5, 6, 7,
		8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25,
		26, 27, 28, 29, 30, 31,
		32, 33, 34, 35,
	};

	/* Create the vertex buffer */
	quo_VertexBuffer cube_vb;
	quo_begin_vertex_buffer(&cube_vb,
		QUO_VERTEXBUFFERFLAGS_DRAW_TRIANGLES | QUO_VERTEXBUFFERFLAGS_STATIC_DRAW);

	/* NOTE: You can use QUO_VERTEXBUFFERFLAGS_DRAW_LINES to draw a wireframe model.
	 * Use QUO_VERTEXBUFFERFLAGS_DYNAMIC_DRAW instead of QUO_VERTEXBUFFERFLAGS_STATIC_DRAW
	 * if you plan to call quo_update_vertices *or* quo_update_indices */

	/* Add the vertices and indices */
	quo_push_vertices(&cube_vb, vertices, sizeof(vertices));
	quo_push_indices(&cube_vb, indices, sizeof(indices)/sizeof(indices[0]));

	/* Configure the location of the positions and UVs */
	quo_configure_vertices(&cube_vb, 0, 3, 5, 0);
	quo_configure_vertices(&cube_vb, 1, 2, 5, sizeof(float)*3);

	/* Finish the vertex buffer configuration */
	quo_finalise_vertex_buffer(&cube_vb);

	/* Load the texture */
	quo_BitmapImage image;
	quo_load_bitmap_from_file("res/frog.bmp", &image, 3);

	/* Send the bitmap to the GPU and delete it from memory */
	quo_Texture texture;
	quo_init_texture_from_bmp(&texture, &image, QUO_TEXTUREFLAGS_ANTIALIASED);
	quo_free_bitmap(&image);

	/* Setup the projection matrix */
	quo_Matrix projection = quo_perspective(45.0f, (float)window.width / (float)window.height, 0.1f, 100.0f);

	/* Setup the model matrix */
	quo_Matrix cube_model = quo_translate(quo_identity(), (quo_vec3){0.0f, 0.0f, -10.0f});

	/* Rotation float, to be incremented every frame */
	float rotation = 0.0f;

	/* Game loop */
	while (window.is_open) {
		/* Update the window events */
		quo_update_window_events(&window);

		/* Increment the rotation and update the model matrix accordingly */
		rotation += window.frame_time * 10000;
		cube_model = quo_rotate(cube_model, rotation, (quo_vec3){0.0f, 1.0f, 0.0f});

		/* Clear the screen to black */
		quo_clear_renderer(0x000000);

		/* Bind the cube shader */
		quo_bind_shader(&renderer, cube_shader);

		/* Bind and set the texture */
		quo_bind_texture(&texture, 0);
		quo_shader_set_int(&renderer, cube_shader, "albedo", 0);

		/* Set the projection and model matrices */
		quo_shader_set_matrix(&renderer, cube_shader, "projection", projection);
		quo_shader_set_matrix(&renderer, cube_shader, "model", cube_model);

		/* Draw the cube */
		quo_draw_vertex_buffer(&cube_vb);

		/* Bind the renderer's default sprite shader */
		quo_bind_shader(&renderer, renderer.sprite_shader);

		/* Finish the frame */
		quo_update_renderer(&renderer);
		quo_update_window(&window);
	}

	/* Clean up */
	quo_free_texture(&texture);
	quo_free_vertex_buffer(&cube_vb);
	quo_free_renderer(&renderer);
	quo_free_window(&window);
}
