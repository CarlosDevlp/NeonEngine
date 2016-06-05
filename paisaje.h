#ifndef ___PAISAJE___
#define ___PAISAJE___ 0
    #include <stdio.h>
    #include <math.h>
    #include "scene.h"

    /*Objetos para dibujar el paisaje*/

    class Paisaje: public Scene{
        public:
            /*constructor*/
            Paisaje(char *name){
                this->title=name;

            }

            /*método para dibujar todos los elementos*/
            void draw(){

                /*dibujando el sol*/
                sun(Position(-8,9),4.5,ColorRGB(228, 68, 37));
                /*dibujando las nubes*/

                cloud(Position(-6,8),4,5,ColorRGB::white());
                cloud(Position(3,8),4,5,ColorRGB::white());


                /*dibujando las montañas*/

                mountain(Position(0,4),6,12,ColorRGB(54,67,73),ColorRGB::white());
                mountain(Position(-3,2),4,8,ColorRGB(54,67,73),ColorRGB::white());
                mountain(Position(3,2),4,8,ColorRGB(54,67,73),ColorRGB::white());

                /*dibujando las pampas*/

                land(Position(1.5,-4),10, ColorRGB(155, 159, 37));
                land(Position(-3,-5),8, ColorRGB(181, 185, 46));

                /*dibujando un camino de tierra*/

                landPath(Position(-5,-4),2.7,2.8, 1.6,ColorRGB(116, 78, 41));
                landPath(Position(-4.7,-4),0.25,2.4, 1.6,ColorRGB(126, 88, 51));
                landPath(Position(-4,-4),0.25,2.4, 1.6,ColorRGB(126, 88, 51));
                landPath(Position(-3.3,-4),0.25,2.4, 1.6,ColorRGB(126, 88, 51));


                /*dibujando un canal de rio*/

                landPath(Position(2,-4),0.4,3.4, 2,ColorRGB(47, 140, 148));


                /*dibujando los árboles*/

                tree(Position(-1.8,-1),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));
                tree(Position(-1,-0.3),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));
                tree(Position(2,-1),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));
                tree(Position(0.8,-0.5),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));
                tree(Position(0,2),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));
                tree(Position(2,2),0.8,2,ColorRGB(140, 146, 15),ColorRGB(57, 44, 1));

                /*dibujando el océano*/
                const float oceanHeight=4;
                const float waveHeight=0.2;

                ocean(Position(0,-3.5),20,oceanHeight,waveHeight,ColorRGB(56, 151, 155)); //capa 1 de océano
                ocean(Position(0,-4.5),20,oceanHeight,waveHeight,ColorRGB(59, 158, 163)); //capa 2 de océano
                ocean(Position(0,-6.5),20,oceanHeight,waveHeight,ColorRGB(59, 162, 167)); //capa 3 de océano
                    /*dibujando un bote entre el océano*/
                    boat(Position(-4,-8),6,2,ColorRGB(1, 52, 71),ColorRGB::white(),ColorRGB::white());
                ocean(Position(0,-8.5),20,oceanHeight,waveHeight,ColorRGB(64, 173, 178)); //capa 4 de océano



                Scene::draw();
            }

        private:
            //árbol
            void tree(Position pos,float width,float height,ColorRGB colorPlants,ColorRGB colorWood){

                glColorRGB(colorPlants.r,colorPlants.g,colorPlants.b);

                glBegin(GL_TRIANGLES);
                    glVertex2f(pos.x+(width/2),pos.y-(height/2));
                    glVertex2f(pos.x-(width/2),pos.y-(height/2));
                    glVertex2f(pos.x,pos.y+(height/2));
                glEnd();

                //tronco
                glColorRGB(colorWood.r,colorWood.g,colorWood.b);

                glBegin(GL_TRIANGLES);
                    glVertex2f(pos.x,pos.y+(height*0.05));
                    glVertex2f(pos.x-(width/8),pos.y-height);
                    glVertex2f(pos.x+(width/8),pos.y-height);
                glEnd();

            }

            //montaña
            void mountain(Position pos,float width,float height,ColorRGB colorGround,ColorRGB colorIce){


                glColorRGB(colorGround.r,colorGround.g,colorGround.b);
                /*base rocosa de la montaña*/
                glBegin(GL_TRIANGLES);
                    glVertex2f(pos.x+(width/2),pos.y-(height/2));
                    glVertex2f(pos.x-(width/2),pos.y-(height/2));
                    glVertex2f(pos.x,pos.y+(height/2));
                glEnd();

                /*parte gélida*/
                glColorRGB(colorIce.r,colorIce.g,colorIce.b);
                glBegin(GL_TRIANGLE_FAN);
                    glVertex2f(pos.x,pos.y+(height/2));
                    glVertex2f(pos.x-(width/6),pos.y+(height/6));
                    glVertex2f(pos.x-(width/8),pos.y+(height/8));
                    glVertex2f(pos.x,pos.y+(height/6));
                    glVertex2f(pos.x+(width/8),pos.y+(height/8));
                    glVertex2f(pos.x+(width/6),pos.y+(height/6));
                glEnd();

            }

            //pampas
            void land(Position pos,float diameter,ColorRGB colorGround){
                float radio=diameter/2;
                glColorRGB(colorGround.r,colorGround.g,colorGround.b);
                glBegin(GL_LINES);
                    for(float x=-radio;x<=radio;x+=0.001){
                        glVertex2f(pos.x,pos.y);
                        glVertex2f(x+pos.x,sqrt(radio*radio-x*x)+pos.y);
                    }
                glEnd();
            }

            //caminos
            void landPath(Position pos,float width,float cornerLeftHeight,float cornerRightHeight,ColorRGB colorLand){
                glColorRGB(colorLand.r,colorLand.g,colorLand.b);
                glBegin(GL_LINES);
                    float x2;

                    for(float x=0;x<=cornerLeftHeight;x+=0.01){

                        glVertex2f(x+pos.x,sqrt(cornerLeftHeight*x)+pos.y);

                        if(x<cornerRightHeight)
                            x2=x;
                        glVertex2f(x2+pos.x+width,sqrt(cornerLeftHeight*x2)+pos.y);

                    }
                glEnd();
            }

            //oceáno
            void ocean(Position pos,float width,float height,float waveHeight,ColorRGB colorWater){
                glColorRGB(colorWater.r,colorWater.g,colorWater.b);

                float widthHalf=width/2;
                float heightEight=height/8;
                float heightSevenEight=7*height/8;


                glBegin(GL_LINES);
                    for(float x=-widthHalf;x<=widthHalf;x+=0.01){
                        glVertex2f(x+pos.x,waveHeight*sin(height*x)+pos.y);
                        glVertex2f(x+pos.x,pos.y-height);
                    }
                glEnd();
            }

            //nubes
            void cloud(Position pos,float width,float height,ColorRGB colorCloud){
                float diameter=width/4;
                float radio=sqrt(diameter);
                glColorRGB(colorCloud.r,colorCloud.g,colorCloud.b);


                glLineWidth(1.5);
                glBegin(GL_LINES);

                    for(float x=-radio;x<=radio;x+=0.001){

                        //número de círculos de la nube
                        for(int c=0;c<4;c++){
                            glVertex2f(pos.x+(radio*c),pos.y);
                            glVertex2f(x+pos.x+(radio*c),sqrt(diameter-x*x)+pos.y);
                            glVertex2f(pos.x+(radio*c),pos.y);
                            glVertex2f(x+pos.x+(radio*c),-1*sqrt(diameter-x*x)+pos.y);
                        }

                    }
                glEnd();
            }
            //bote
            void boat(Position pos,float width,float height ,ColorRGB colorBase,ColorRGB colorBaseDecoration,ColorRGB colorSailBoat){

                float halfWidth=width/2;
                float widthThree=width/3;
                float widthFour=width/4;
                float widthEight=width/8;

                float halfHeight=height/2;
                float heightThree=height/3;
                float heightFour=height/4;
                float heightEight=height/8;

                /*base del bote*/
                glColorRGB(colorBase.r,colorBase.g,colorBase.b);
                glBegin(GL_QUADS);
                    glVertex2f(pos.x-halfWidth,pos.y+halfHeight);
                    glVertex2f(pos.x-widthFour,pos.y-halfHeight);
                    glVertex2f(pos.x+widthFour,pos.y-halfHeight);
                    glVertex2f(pos.x+halfWidth,pos.y+halfHeight);
                glEnd();
                /*decoración de la base*/
                glColorRGB(colorBaseDecoration.r,colorBaseDecoration.g,colorBaseDecoration.b);
                glBegin(GL_QUADS);
                    glVertex2f(pos.x-width/2.2,pos.y+heightThree);
                    glVertex2f(pos.x-width/2.3,pos.y+heightFour);
                    glVertex2f(pos.x+width/2.3,pos.y+heightFour);
                    glVertex2f(pos.x+width/2.2,pos.y+heightThree);
                glEnd();

                /*velas del bote*/
                glColorRGB(colorSailBoat.r,colorSailBoat.g,colorSailBoat.b);
                glBegin(GL_TRIANGLES);
                    //vela1
                    glVertex2f(pos.x-width/24,pos.y+halfHeight*1.1);
                    glVertex2f(pos.x-halfWidth*0.7,pos.y+halfHeight*1.1);
                    glVertex2f(pos.x-width/24,pos.y+height*2);
                    //vela2
                    glVertex2f(pos.x,pos.y+halfHeight*1.1);
                    glVertex2f(pos.x+halfWidth*0.7,pos.y+halfHeight*1.1);
                    glVertex2f(pos.x,pos.y+height*2.3);
                glEnd();
            }
        //sol
        void sun(Position pos,float diameter,ColorRGB colorSun){
                float radio=diameter/2;
                glColorRGB(colorSun.r,colorSun.g,colorSun.b);

                glLineWidth(1.5);
                glBegin(GL_LINES);
                    for(float x=-radio;x<=radio;x+=0.001){
                        glVertex2f(pos.x,pos.y);
                        glVertex2f(x+pos.x,sqrt(radio*radio-x*x)+pos.y);
                        glVertex2f(x+pos.x,-1*sqrt(radio*radio-x*x)+pos.y);
                    }
                glEnd();
        }


    };


#endif
