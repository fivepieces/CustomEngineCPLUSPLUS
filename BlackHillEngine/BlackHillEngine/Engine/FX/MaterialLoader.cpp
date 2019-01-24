#include "MaterialLoader.h"



void MaterialLoader::LoadMaterial(std::string file_)
{
	std::ifstream in(file_.c_str(), std::ios::in);
	if (!in) {
		Debug::Error("Cannot open MTL file: " + file_, __FILE__, __LINE__);
		return;
	}
	Material m = Material();
	std::string matName = "";
	std::string line;

	while (std::getline(in, line)) {
		if (line.substr(0, 7) == "newmtl ") {
			if (m.diffuseMap != 0) {
				MaterialHandler::GetInstance()->AddMaterial(matName, m);
				m = Material();
			}

			matName = line.substr(7);
			m.diffuseMap = LoadTexture(matName);
		}

		//ns - shininess
		else if (line.substr(0, 4) == "\tNs ") {
			std::istringstream v(line.substr(4));
			v >> m.shininess;
		}

		//d - transparency
		else if (line.substr(0, 3) == "\td ") {
			std::istringstream v(line.substr(3));
			v >> m.transparency;
		}
		//KA -ambient
		else if (line.substr(0, 4) == "\tKA ") {
			std::istringstream v(line.substr(4));
			v >> m.ambient.x >> m.ambient.y >> m.ambient.z;
		}
		//kd- diffuse
		else if (line.substr(0, 4) == "\tkd ") {
			std::istringstream v(line.substr(4));
			v >> m.diffuse.x >> m.diffuse.y >> m.diffuse.z;
		}
		//ks - specular
		else if (line.substr(0, 4) == "\tks ") {
			std::istringstream v(line.substr(4));
			v >> m.specular.x >> m.specular.y >> m.specular.z;
		}
	}
	if (m.diffuseMap != 0) {
		MaterialHandler::GetInstance()->AddMaterial(matName, m);
	}
}

GLuint MaterialLoader::LoadTexture(std::string fileName_)
{
	GLuint currentTexture = TextureHandler::GetInstance()
		->GetTexture(fileName_);
	if (currentTexture == 0) {
		TextureHandler::GetInstance()
			->CreateTexture(fileName_, "Ressources/Textures/" + fileName_ + ".jpg");
		currentTexture = TextureHandler::GetInstance()
			->GetTexture(fileName_);
	}
	return currentTexture;
}

