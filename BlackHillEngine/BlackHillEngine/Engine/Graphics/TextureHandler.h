#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
//always put sdl before glew
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <glew.h>
#include "../Core/Debug.h"


struct Texture {
	GLuint textureID = 0;
	float width = 0.0f;
	float height = 0.0f;
};
class TextureHandler
{

public:
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler(TextureHandler&&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
	TextureHandler& operator=(TextureHandler&&) = delete;
	static TextureHandler* GetInstance();

	void CreateTexture(const std::string& textureName_, const std::string& textureFilePath_);
	static const GLuint GetTexture(const std::string& textureName_);
	static const Texture* GetTextureData(const std::string& textureName_);
private:
	TextureHandler();
	~TextureHandler();

	static std::unique_ptr<TextureHandler> textureInstance;
	friend std::default_delete<TextureHandler>;

	static std::map<std::string, Texture*> textures;
};


#endif //!TEXTUREHANDLER_H
 