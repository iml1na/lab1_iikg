#include <iostream>
#include <GL/freeglut.h>
static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768); //размер окна
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 01");//название
	glutDisplayFunc(RenderSceneCB);//функция обратного вызова
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//цвет, который будет использован во время очистки буфера кадра
	glutMainLoop();//передача контроль GLUT'у
	glClear(GL_COLOR_BUFFER_BIT);//очистка буфера кадра
	glutSwapBuffers();//фоновый буфер и буфер кадра меняются местами
	return 0;
}
