#include "SimulationScene.h"
#include "Game.h"

SimulationScene::~SimulationScene()
{
}

void SimulationScene::update(float timeDelta)
{
	
}

void SimulationScene::setGame(CGame* game)
{
	m_game = game;
}

SimulationScene::SimulationScene()
{
	m_camera = new Vektoria::CCamera();
	m_camera->Init(QUARTERPI);
}
