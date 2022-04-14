﻿#include "pch.h"
#include "SimulationScene.h"
#include "Game.h"

SimulationScene::SimulationScene()
	: m_bWASDCam(true)
{
	m_cameraPlacement.SetTranslationSensitivity(10.0f);
	m_cameraPlacement.SetRotationSensitivity(1.0f);
	m_cameraPlacement.TranslateZ(8.0f);
	this->AddPlacement(&m_cameraPlacement);
}

void SimulationScene::regMaterial(Vektoria::CMaterial* pzm)
{
	CGame::GetInstance().getRoot().AddMaterial(pzm);
	m_materials.emplace(pzm);
}

SimulationScene::~SimulationScene()
{
	// unload additionally-registered Materials from the root node
	for (auto& pzm : m_materials)
		CGame::GetInstance().getRoot().SubMaterial(pzm);
}

void SimulationScene::update(float timeDelta)
{
	m_physicsEngine.tick(timeDelta);
}

void SimulationScene::reset()
{
}

void SimulationScene::activate()
{
}

void SimulationScene::deactivate()
{
}

Vektoria::CPlacement& SimulationScene::getCameraPlacement()
{
	return m_cameraPlacement;
}

void SimulationScene::setWASDCam(bool wasdCam)
{
	m_bWASDCam = wasdCam;
}

bool SimulationScene::getWASDCam() const
{
	return m_bWASDCam;
}
