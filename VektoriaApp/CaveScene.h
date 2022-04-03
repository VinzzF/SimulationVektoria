#pragma once

#include "SimulationScene.h"

class CaveScene : public SimulationScene
{
public:
	explicit CaveScene();
	~CaveScene();

private:
	Vektoria::CMaterial m_zmSides[4];
	Vektoria::CGeoQuad m_zgSides[4];
	Vektoria::CPlacement m_zpSides[4];
};
