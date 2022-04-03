#pragma once

#include "SimulationScene.h"

/**
 * Common scene to inherit from, that includes:
 * - A camera
 * - A parallel light
 */
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
