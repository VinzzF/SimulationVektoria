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

	/** Reset the scene to its initial state. */
	virtual void reset();

	virtual void activate();

	static void setGame(CGame* game);

	Vektoria::CCamera& getCamera();
	Vektoria::CPlacement& getCameraPlacement();

	void setWASDCam(bool wasdCam);
	bool getWASDCam() const;

protected:
	explicit SimulationScene();

	/**
	 * Materialien die nicht im ersten Tick() referenziert werden,
	 * müssen der Engine extra bekanntgemacht werden,
	 * damit diese geladen werden!
	 * Hierzu diese Funktion zusätzlich zu Vektoria::CMaterial::Init() aufrufen!
	 */
	void regMaterial(Vektoria::CMaterial* pzm);

	static CGame* ms_game;
	Vektoria::CCamera m_zc;
	Vektoria::CPlacement m_zpCamera;

	PhysicsEngineWrapper m_physicsEngine;

private:
	bool m_bWASDCam;
	std::set<Vektoria::CMaterial*> m_materials;
};
