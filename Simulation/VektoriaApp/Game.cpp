#include "pch.h"
#include "Game.h"

#include "Examples/FallingCubeScene.h"
#include "CaveScene.h"
#include "Examples/EmptyScene.h"

// singleton
CGame& CGame::GetInstance()
{
	static CGame instance;
	return instance;
}

CGame::CGame()
{
}

CGame::~CGame()
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), Vektoria::CSplash* psplash)
{
	// Hier die Initialisierung Deiner Vektoria-Objekte einf�gen:
	m_zr.Init(psplash);
	// m_zf.SetApiRender(eApiRender_DirectX11_Shadermodel50_Monolight);
	m_zf.Init(hwnd, procOS); 
	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);

	m_zb.InitFull(const_cast<char*>("textures\\blue_image.jpg"));
	m_zv.AddBackground(&m_zb);

	// Init devices
	m_zf.AddDeviceKeyboard(&m_zdk);
	m_zf.AddDeviceMouse(&m_zdm);

	initScenes();

	// Change the starting scene
	changeScene(0);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Root muss zuerst ticken
	m_zr.Tick(fTimeDelta);

	if (m_activeScene)
	{
		m_activeScene->update(fTimeDelta);
		if (m_activeScene->getWASDCam()) m_zdk.PlaceWASD(m_activeScene->getCameraPlacement(), fTimeDelta);
	}
	handleUserInput();

	Sleep(1u);
}

void CGame::Fini()
{
	// globale Dependency Injection, bester Kompromiss...
	SimulationScene::setGame(nullptr);

	// Hier die Finalisierung Deiner Vektoria-Objekte einf�gen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergr��e ver�ndert wurde.
	// Hier kannst Du dann die Aufl�sung des Viewports neu einstellen:
	m_zf.ReSize(iNewWidth, iNewHeight);
}

Vektoria::CRoot& CGame::getRoot()
{
	return m_zr;
}

Vektoria::CDeviceKeyboard& CGame::getKeyboard()
{
	return m_zdk;
}

Vektoria::CDeviceMouse& CGame::getMouse()
{
	return m_zdm;
}

void CGame::initScenes()
{
	// globale Dependency Injection, bester Kompromiss...
	SimulationScene::setGame(this);

	// Example scene
	addScene(new FallingCubeScene);

	// ADD NEW SCENES HERE
	// ...
	addScene(new CaveScene);
}

void CGame::addScene(SimulationScene* scene)
{
	scene->setGame(this);
	m_scenes.push_back(scene);
}

void CGame::changeScene(int sceneIdx)
{
	assert(sceneIdx >= 0 && sceneIdx < m_scenes.size());
	changeScene(m_scenes[sceneIdx]);
}

void CGame::changeScene(SimulationScene* scene)
{
	if (m_activeScene)
	{
		m_zr.SubScene(m_activeScene);
	}

	m_activeScene = scene;

	if (scene)
	{
		// first time init Viewport full, otherwise just change camera
		if (m_zv.GetCamera())
			m_zv.SetCamera(&scene->getCamera());
		else
			m_zv.InitFull(&scene->getCamera());

		scene->activate();
		
		m_zr.AddScene(scene);
	}
}

void CGame::handleUserInput()
{
	if (m_zdk.KeyDown(DIK_1))
	{
		prevScene();
	}
	else if (m_zdk.KeyDown(DIK_2))
	{
		nextScene();
	}

	if (m_zdk.KeyDown(DIK_T))
	{
		m_activeScene->reset();
	}
}

void CGame::nextScene()
{
	const auto sceneCount = int(m_scenes.size());
	if (sceneCount <= 1) return;

	m_activeSceneIndex = (m_activeSceneIndex + 1) % sceneCount;
	changeScene(m_scenes[m_activeSceneIndex]);
}

void CGame::prevScene()
{
	const auto sceneCount = int(m_scenes.size());
	if (sceneCount <= 1) return;

	if (--m_activeSceneIndex < 0) m_activeSceneIndex = sceneCount - 1;
	changeScene(m_scenes[m_activeSceneIndex]);
}