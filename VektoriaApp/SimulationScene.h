#pragma once
#include "Vektoria/Scene.h"
#include "Vektoria/Camera.h"
#include "PhysicInterfaces/PhysicsEngineWrapper.h"

class CGame;

class SimulationScene : public Vektoria::CScene
{
public:
	virtual ~SimulationScene();

	virtual void update(float timeDelta);
	
	Vektoria::CCamera* getCamera();
	Vektoria::CCamera* getCamera() const;

	void setGame(CGame* game);

protected:
	explicit SimulationScene();

	CGame* m_game;

	Vektoria::CCamera* m_camera;

	PhysicsEngineWrapper m_physicsEngine;
};

