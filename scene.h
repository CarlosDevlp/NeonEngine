#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
    #define PI 3.14159265359

    /*encapsulando las funciones para que acepte RGB de 0 a 255*/
    void glColorRGB(int r,int g, int b){
                glColor3f(((float)r)/255,((float)g)/255,((float)b)/255);
    }

    void glClearColorRGB(int r,int g, int b){
                glClearColor(((float)r)/255,((float)g)/255,((float)b)/255,0.0);
    }


    //Estructura de colores RGB
    struct ColorRGB{
        int r;
        int g;
        int b;


        ColorRGB(){
        }
        ColorRGB(int _r,int _g,int _b): r(_r),g(_g),b(_b){
        }

        /*Colores definidos*/
        static ColorRGB green(){
            return ColorRGB(0,255,0);
        }

        static ColorRGB white(){
            return ColorRGB(255,255,255);
        }

        static ColorRGB brown(){
            return ColorRGB(168,112,28);
        }

        void paint(){
            glColorRGB(r,g,b);
        }
    };


    /*Objecto coordenadas*/
    struct Position{
        float x;
        float y;
        float z;
        Position(float _x,float _y): x(_x),y(_y){
        }

        Position(float _x,float _y,float _z): x(_x),y(_y),z(_z){
        }


    };




    /*Clase Escena, servirá de plantilla para cualquier escenario gráfico que quiera graficar*/
    class Scene{
        public:
            Scene(){
                //this->background_color= ColorRGB(0,0,0);
                this->background_color.r=0;
                this->background_color.g=0;
                this->background_color.b=0;
            }

            Scene(char *title){
             this->title=title;
            }

            void setTitle(char *title){
                this->title=title;
            }

            char *getTitle(){
                return this->title;
            }

            virtual void draw(){}


            ColorRGB getBackgroundColor(){
                return this->background_color;
            }

            void setBackgroundColor(ColorRGB back_c){
                this->background_color=back_c;
            }

            void setWireframeMode(bool mode){
                this->wireframeMode=mode;
            }

            virtual void input(unsigned char keyName){}
        protected:
            char *title;
            ColorRGB background_color;

            //dibujo de solidos en 3d
             void sphere(Position pos,double radio,ColorRGB color){
                glPushMatrix();
                       color.paint();
                       glTranslatef (pos.x, pos.y, pos.z);
                       if(this->wireframeMode) glutWireSphere(radio, 20, 16);    // dibuja planeta
                       else glutSolidSphere(radio, 20, 16);   //dibuja sol
                glPopMatrix();       //glutSwapBuffers();
             }

             void cube(Position pos,double size,ColorRGB color){
                glPushMatrix();
                    color.paint();
                    glTranslatef (pos.x, pos.y, pos.z);
                    if(this->wireframeMode) glutWireCube(size);
                    else  glutSolidCube(size);
                glPopMatrix();
             }

            void torus(Position pos,double r,double R,ColorRGB color){
                glPushMatrix();
                    color.paint();
                    glTranslatef (pos.x, pos.y, pos.z);
                    if(this->wireframeMode) glutWireTorus(r,R,20,20);
                    else  glutSolidTorus(r,R,20,20);
                glPopMatrix();
            }
        private:
            bool wireframeMode;


    };

#endif // SCENE_H_INCLUDED
