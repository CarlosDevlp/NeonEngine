#include <windows.h>
#include <c:\GLUT\include\GL\glut.h>

void inicio() // metodo de inicializacion de la pantalla
{
    glClearColor(0.0,0.0,0.0,0.0); // color de fondo de la pantalla <negro>
    glMatrixMode(GL_PROJECTION); // funcion de uso de pantalla
    gluOrtho2D(-5,5,-5,5); //intervalo del plano a manejar
}

void pantalla() //Metodo de dibujo en el entorno de trabajo
{
    glClear(GL_COLOR_BUFFER_BIT); // limpia la pantalla
    glFlush(); // Dibuja a pantalla las funciones de dibujo
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // inicia la libreria GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // configura el modo de video inicial -- single = Simple Buffer | RGB = sistema de colores RGB  --- buffer= calculos en memoria
    glutInitWindowSize(640,480); // Tamaño de la Ventana
    glutInitWindowPosition(100,100); // Incializacion de la Posicion de la ventana
    glutCreateWindow("primer programa"); // Crea la ventana con parametros de un "Nombre"
    inicio(); //Metodo Inicializa
    glutDisplayFunc(pantalla); // se manda a pantalla todo lo que contenga el metodo 'Dibujo'
    glutMainLoop(); //permite iniciar un ciclo constante del programa
    return EXIT_SUCCESS; // fin del programa
}
