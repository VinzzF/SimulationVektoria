#pragma once

#include "SimulationScene.h"

/**
 * Example scene for a simplistic cave with 4 sides
 */
class CaveScene : public SimulationScene
{
public:
	explicit CaveScene(float fWidth = 8.0f, float fDepth = 6.0f, float fHeight = 5.0f, float fThickness = 0.1f);
	~CaveScene();

protected:
	const float m_fWidth;
	const float m_fDepth;
	const float m_fHeight;
	const float m_fThickness;

	Vektoria::CMaterial m_zmSides[4];
	Vektoria::CGeoWall m_zgSides[4];
	Vektoria::CPlacement m_zpSides[4];
};
