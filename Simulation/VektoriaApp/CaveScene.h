#pragma once

#include "SimulationScene.h"

/**
 * Example scene for a simplistic cave with 4 sides
 */
class CaveScene : public SimulationScene
{
public:
	explicit CaveScene();
	~CaveScene();

protected:
	Vektoria::CMaterial m_zmSides[4];
	Vektoria::CGeoQuad m_zgSides[4];
	Vektoria::CPlacement m_zpSides[4];
};
