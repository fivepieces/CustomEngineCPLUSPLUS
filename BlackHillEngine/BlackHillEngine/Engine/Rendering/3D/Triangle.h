#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Model.h"

class Triangle : public Model
{
public:
	Triangle(GLuint shaderProgram_, GLuint textureID_);
	virtual ~Triangle();
};

#endif //!TRIANGLE_H
