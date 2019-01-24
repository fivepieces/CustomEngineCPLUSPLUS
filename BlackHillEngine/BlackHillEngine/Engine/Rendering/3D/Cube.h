#ifndef CUBE_H
#define CUBE_H

#include "Model.h"

class Cube : public Model
{
public:
	Cube(GLuint shaderProgram_, GLuint textureID_);
	virtual ~Cube();
};

#endif //!CUBE_H