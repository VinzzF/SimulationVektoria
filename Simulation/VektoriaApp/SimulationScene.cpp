﻿#include "pch.h"
#include "SimulationScene.h"
#include "Game.h"

CGame* SimulationScene::ms_game;

SimulationScene::SimulationScene()
	: m_bWASDCam(true)
{
	m_zc.Init(QUARTERPI);

	m_zpCamera.AddCamera(&m_zc);
	m_zpCamera.SetTranslationSensitivity(10.0f);
	m_zpCamera.SetRotationSensitivity(1.0f);
	m_zpCamera.TranslateZ(8.0f);
	this->AddPlacement(&m_zpCamera);
}

void SimulationScene::regMaterial(Vektoria::CMaterial* pzm)
{
	CGame::GetInstance().getRoot().AddMaterial(pzm);
	m_materials.emplace(pzm);
}

SimulationScene::~SimulationScene()
{
	// zusätzlich registrierte Materialien wieder vom Root lösen
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

void SimulationScene::setGame(CGame* game)
{
	ms_game = game;
}

Vektoria::CCamera& SimulationScene::getCamera()
{
	return m_zc;
}

Vektoria::CPlacement& SimulationScene::getCameraPlacement()
{
	return m_zpCamera;
}

void SimulationScene::setWASDCam(bool wasdCam)
{
	m_bWASDCam = wasdCam;
}

bool SimulationScene::getWASDCam() const
{
	return m_bWASDCam;
}