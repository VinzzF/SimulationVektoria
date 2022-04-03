#pragma once

#include "SimulationScene.h"

class DefaultScene : public SimulationScene
{
public:
	explicit DefaultScene();
	~DefaultScene();

protected:
	Vektoria::CPlacement m_zpCamera;
	Vektoria::CCamera m_zc;
	Vektoria::CLightParallel m_zl;
};
