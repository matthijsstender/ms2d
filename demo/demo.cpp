// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>
#include <common/entity.h>

int main( void )
{
	Renderer renderer(1280, 720);

	Camera* camera = new Camera();

	camera->computeMatricesFromInputs(renderer.window());

	Entity* pencils = new Entity();
	Entity* kingkong = new Entity();
	Entity* rgba = new Entity();

	pencils->addSprite("assets/pencils.tga");
	kingkong->addSprite("assets/kingkong.tga");
	rgba->addSprite("assets/rgba.tga");

	do {
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		renderer.renderSprite(camera, pencils->sprite_1(), 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(camera, kingkong->sprite_1(), 900, 400, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(camera, rgba->sprite_1(), renderer.width()/2, renderer.height()/2, 3.0f, 3.0f, 0.0f);
		pencils->rotation.z += 0.3f;

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete pencils;
	delete kingkong;
	delete rgba;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
