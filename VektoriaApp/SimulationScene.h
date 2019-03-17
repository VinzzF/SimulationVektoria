#pragma once
#include "Vektoria/Scene.h"
#include "Vektoria/Camera.h"
#include "PhysicInterfaces/PhysicsEngineWrapper.h"

class CGame;

class SimulationScene : public Vektoria::CScene
{
public:
	virtual ~SimulationScene();

	/** 
	 * Update this scene
	 * It is called update() instead of tick(), since there is
	 * already a Tick() method defined in Vektora::Scene 
	 */
	virtual void update(float timeDelta);

	/** Get the camera of this scene. */
	Vektoria::CCamera* getCamera() const;

	void setGame(CGame* game);

protected:
	explicit SimulationScene();

	CGame* m_game;

	Vektoria::CCamera* m_camera;

	PhysicsEngineWrapper m_physicsEngine;
};

