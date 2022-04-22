#include <GL/glew.h>
#include <iostream>
#include <GL/freeglut.h>
#include <glm/vector_relational.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

GLuint VBO;

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);//индексация атрибутов каждой вершины
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//говорит конвейеру как воспринимать данные внутри буфера
						//1 параметр указывает на индекс атрибута, 2-количество компонентов в атрибуте, 3-тип данных для каждого компонента
	glDrawArrays(GL_POINTS, 0, 1);//функция отрисовки
	glDisableVertexAttribArray(0);//отключение каждого атрибут вершины

	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 02");
	glutDisplayFunc(RenderSceneCB);
	glClearColor(0, 0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();

	//инициализация GLEW и проверка на ошибки
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	//создание точки в середине экрана
	glm::vec3 Vertices[1];//массив из одного экземпляра структуры Vector3f
	Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);//задаём XYZ по нулям

	////назначение GLuint в качестве глобальной переменной для хранения указателя на буфер вершин
	glGenBuffers(1, &VBO);//генерация объектов переменных типов
						//2 параметра: 1 - определяет количество объектов, которые будут созданы, 2 - ссылка на массив
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//ограничение изменения значения по указателю
						//параметр GL_ARRAY_BUFFER означает, что буфер будет хранить массив вершин
	//размер данных в байтах, адрес массива вершин, и флаг, который обозначает использование паттернов для этих данных
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glutMainLoop();
	return 0;
}
