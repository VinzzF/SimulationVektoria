#include "Game.h"

using namespace Vektoria;

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	m_root.Init(psplash);
	m_camera.Init(QUARTERPI);
	m_frame.Init(hwnd, procOS); 
	m_viewport.InitFull(&m_camera);
	m_lightParallel.Init(CHVector(1.0f, 1.0f, 1.0f), CColor(1.0f, 1.0f, 1.0f));
	
	m_root.AddFrame(&m_frame);
	m_frame.AddViewport(&m_viewport);
	m_root.AddScene(&m_defaultScene);
	m_defaultScene.AddPlacement(&m_cameraPlacement);
	m_defaultScene.AddLightParallel(&m_lightParallel);
	m_cameraPlacement.AddCamera(&m_camera);

	// Init materials
	m_sphereMat.Init();
	m_cubeMat.Init();

	m_sphereMat.MakeTextureDiffuse("./../Resources/stone.jpg");
	m_cubeMat.MakeTextureDiffuse("./../Resources/wood.jpg");

	m_root.AddMaterial(&m_sphereMat);
	m_root.AddMaterial(&m_cubeMat);

	// Init geometries
	m_sphereGeo.Init(1.0f, &m_sphereMat, 50, 50);
	m_cubeGeo.Init(1.0f, &m_cubeMat);


	m_cameraPlacement.TranslateZ(8.0f);


	// Init devices
	m_frame.AddDeviceKeyboard(&m_keyboard);
	m_frame.AddDeviceMouse(&m_mouse);

	initScenes();
	//m_gui.init(&m_viewport);
	changeScene(m_fallingBallSim);
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	if(m_activeScene)
	{
		m_activeScene->update(fTimeDelta);
		float timeDelta = 10.0f * fTimeDelta;
		m_keyboard.PlaceWASD(m_cameraPlacement, timeDelta);
	}
	handleSceneChange();

	m_root.Tick(fTimeDelta);
}

void CGame::Fini()
{
	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	m_frame.ReSize(iNewWidth, iNewHeight);
}

Vektoria::CDeviceKeyboard& CGame::getKeyboard()
{
	return m_keyboard;
}

Vektoria::CDeviceMouse& CGame::getMouse()
{
	return m_mouse;
}

void CGame::initScenes()
{
	m_fallingBallSim = new FallingBallSimulation(&m_sphereGeo);
	prepareScene(m_fallingBallSim);

	m_pendulumSim = new PendulumSimulation(&m_sphereGeo, 20);
	prepareScene(m_pendulumSim);
}

void CGame::changeScene(SimulationScene* scene)
{
	if(m_activeScene)
	{
		m_root.SubScene(m_activeScene);
	}
	m_activeScene = scene;
	if(scene)
	{
		scene->SubPlacement(&m_cameraPlacement);
		scene->SubLightParallel(&m_lightParallel);

		scene->AddPlacement(&m_cameraPlacement);
		scene->AddLightParallel(&m_lightParallel);
		m_root.AddScene(scene);
	}
}

void CGame::prepareScene(SimulationScene* scene)
{
	scene->setGame(this);
	m_scenes.emplace_back(scene);
}

void CGame::handleSceneChange()
{
	if(m_keyboard.KeyDown(DIK_1))
	{
		prevScene();
	}
	else if(m_keyboard.KeyDown(DIK_2))
	{
		nextScene();
	}
}

void CGame::nextScene()
{
	int sceneCount = m_scenes.size();
	if(sceneCount <= 1) return;

	m_activeSceneIndex = (m_activeSceneIndex + 1) % sceneCount;
	changeScene(m_scenes[m_activeSceneIndex]);
}

void CGame::prevScene()
{
	int sceneCount = m_scenes.size();
	if(sceneCount <= 1) return;

	--m_activeSceneIndex;
	if(m_activeSceneIndex < 0)
	{
		m_activeSceneIndex = sceneCount - 1;
	}
	changeScene(m_scenes[m_activeSceneIndex]);
}