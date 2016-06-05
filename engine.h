#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
    /*valores que identifican el número de dimensiones, del canvas, a trabajar*/

    /*Clase Engine, configura el renderizador para mostrar escenarios en diferentes dimensiones*/

    class Engine{
        public:
            static const unsigned short int MODE3D=1,MODE2D=0;
            static void setScene(Scene *s){

                scn=s;
            }



            static void startScene(int *argc, char *argv[], int canvasMode){

                glutInit(argc, argv); // inicia la libreria GLUT
                glutInitWindowSize(640,480); // Tamaño de la Ventana
                glutInitWindowPosition(100,100); // Incializacion de la Posicion de la ventana
                glutCreateWindow(scn->getTitle()); // Crea la ventana con parametros de un "Nombre"

                switch(canvasMode){
                    case 0: //2d
                        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // configura el modo de video inicial -- single = Simple Buffer | RGB = sistema de colores RGB  --- buffer= calculos en memoria
                    break;
                    case 1: //3d
                        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
                        glutReshapeFunc(Engine::canvas3dConfig);
                    break;
                }
                glutKeyboardFunc(Engine::keyBoardInput);
                init(); //Metodo Inicializa
                glutDisplayFunc(Engine::draw); // se manda a pantalla todo lo que contenga el metodo 'Dibujo'
                glutMainLoop(); //permite iniciar un ciclo constante del programa
            }




            static void  draw(){
                 glClear(GL_COLOR_BUFFER_BIT); // limpia la pantalla
                /*---------------------Dibujando--------------------*/
                        scn->draw();
                /*-------------------------------------------------*/
                glFlush(); // Dibuja a pantalla las funciones de dibujo

            }




        private:

            //configuración del canvas en 3d
            static void canvas3dConfig(int w, int h){
                   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
                   glMatrixMode (GL_PROJECTION);
                   glLoadIdentity ();
                   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
                   glMatrixMode(GL_MODELVIEW);
                   glLoadIdentity();
                   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            }
            //input
            static void keyBoardInput(unsigned char key, int x, int y){
                    scn->input(key);
            }
            static void init(){

                canvas_dimensions[0]= -10;
                canvas_dimensions[1]= 10;
                canvas_dimensions[2]= -10;
                canvas_dimensions[3]= 10;

                ColorRGB c=scn->getBackgroundColor();
                glClearColorRGB(c.r, c.g, c.b); // color de fondo de la pantalla <negro>
                glMatrixMode(GL_PROJECTION); // funcion de uso de pantalla
                gluOrtho2D(canvas_dimensions[0],canvas_dimensions[1],canvas_dimensions[2],canvas_dimensions[3]); //intervalo del plano a manejar

            }
            static Scene *scn;
            static int canvas_dimensions[4];




    };

    Scene *Engine::scn;
    int Engine::canvas_dimensions[4];

#endif // ENGINE_H_INCLUDED
