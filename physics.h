#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
    #include "scene.h"
        class Physics: public Scene{
            public:
                Physics (char *name){
                    this->title=name;
                    this->setWireframeMode(false);
                }
                void draw(){

                    this->sphere(Position(0,0,5), 5, ColorRGB::green());
                    this->sphere(Position(-1,-1,4), 3.5, ColorRGB::white());
                    this->cube(Position(-1,2,3), 5, ColorRGB::brown());

                    this->torus(Position(0,-1,4),4, 6, ColorRGB::green());

                    Scene::draw();
                }


                void input(unsigned char keyName){

                    Scene::input(keyName);
                }


        };

#endif // PHYSICS_H_INCLUDED
