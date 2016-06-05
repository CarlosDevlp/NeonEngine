/*Desarrollador: Carlos Chavez Laguna
  Código-Alumno: 362490
  Curso: Computación gráfica y visual
  Universidad Privada del Norte
*/
#include <iostream>
#include <string.h>
#include <string>
#include <GL/glut.h>
#include "physics.h"
#include "engine.h"

using namespace std;
/*Paisaje en Opengl*/
int main(int argc, char *argv[])
{


        Scene *psj= new Physics("Paisaje en opengl, Carlos Chavez Laguna");
        psj->setBackgroundColor(ColorRGB(241,158,30));

        Engine::setScene(psj);
        Engine::startScene(&argc, argv, Engine::MODE2D);

        //Engine::setCanvasMode(RENDER::MODE3D);
    return EXIT_SUCCESS; // fin del programa
}
