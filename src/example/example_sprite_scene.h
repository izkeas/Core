#include "../core/system/scene.h"
#include "../core/system/transform.h"
#include "../core/system/events.h"

#include "../core/graphics/sprite.h"
#include "../core/graphics/view.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "../core/system/data.h"

namespace scenes{
    class ExampleScene : public core::Scene{
        public:
        core::graphics::Sprite example_sprite;
        core::graphics::Texture sprite_texture;

        core::graphics::View2D view_2d;
        core::graphics::View3D view_3d;

        bool is_2d = false;

        ExampleScene(core::graphics::Window& window):
            Scene (window, "Example Scene"),
            view_2d(-(1600.0f/ 2.0), (1600.0f / 2.0f), -(900.0f / 2.0f), (900.0f / 2.0f), 0.1f, 1000.0f),
            view_3d(glm::radians(120.0f), 1600.0f / 900.0f, 0.1f, 1000.0f)
        {

        }

        // Executed on start
        void init(){
            // load a image from ./build/
            core::graphics::Image sprite_image("data/images/coqueiro.jpg");

            if (!sprite_image.is_valid()){
                std::cout << "Failed to load image" << std::endl;
            }

            // create a texture from the image
            sprite_texture.load(sprite_image);
            // set the texture on sprite
            example_sprite.set_texture(sprite_texture);
    
            example_sprite.m_color = core::graphics::Color(235, 177, 70, 255);
            example_sprite.m_position = core::Vector3f(0,0,0);
            
            view_2d.m_position = core::Vector3f(0,0,-100);
            view_3d.m_position = core::Vector3f(0,0,-1000);

            // Enable blending
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

        // Executed on client handle event
        void handle_event(core::Event event){

            if (event.type == GLEQ_KEY_PRESSED){

                if ( event.keyboard.key == GLFW_KEY_A){
                    fmt::print("You Pressed The A Key!!");
                    endl();
                }

                if (event.keyboard.key == GLFW_KEY_SPACE){
                    // toggle 2D or 3D
                    is_2d = !is_2d;
                }
            }
        }

        // Executed on logic update
        void update(float delta){
            // rotate the sprite
            example_sprite.rotate( glm::radians(90.0f) * delta,core::Vector3f(1.0,0.0,0.0));

            //example_sprite.rotate(4.0f * delta, core::Vector3f(1,0,0));
            if (is_2d){

                if (view_2d.distance_to(example_sprite) > 2.0f ){
                    // move forward
                    view_2d.translate(core::Vector3f(0,0,1) * delta * 2.0f);
                }

                view_2d.set_active();
            }
            else{
                if (view_3d.distance_to(example_sprite) > 2.0f ){
                    // move forward
                    view_3d.translate(core::Vector3f(0,0,1) * delta * 100.0f);
                }

                view_3d.set_active();
            }
        }

        // Executed on client update draw
        void draw(core::graphics::Window& window){
            window.clear(core::graphics::Color(255,255,255,255));
            // Draw Sprite
            example_sprite.draw();
        }

    };
}