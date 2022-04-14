#include "pch.h"
#include "Game.h"

#include "Examples/FallingCubeScene.h"
#include "Examples/CaveScene.h"
#include "Examples/EmptyScene.h"

// singleton
CGame& CGame::GetInstance()
{
	static CGame instance;
	return instance;
}

CGame::CGame()
	: m_activeScene(nullptr)
	, m_activeSceneIndex(0)
{
}

CGame::~CGame()
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), Vektoria::CSplash* psplash)
{
	// Hier die Initialisierung Deiner Vektoria-Objekte einfügen:
	m_root.Init(psplash);
	//m_zf.SetApiRender(Vektoria::eApiRender_DirectX11_Shadermodel50_Monolight);
	//m_zf.SetApiRender(Vektoria::eApiRender_DirectX12); // use for DirectX12 rendering
	m_frame.Init(hwnd, procOS); 
	//m_zr.SetFrameRateMax(144.0f); // doesn't seem to be working at this time :(
	m_root.AddFrame(&m_frame);
	m_frame.AddViewport(&m_viewport);

	// Init background (comment out if black background is desired)
	m_background.InitFull(const_cast<char*>("textures\\blue_image.jpg"));
	m_viewport.AddBackground(&m_background);

	// Init devices
	m_frame.AddDeviceKeyboard(&m_keyboard);
	m_frame.AddDeviceMouse(&m_mouse);

	// Init camera & viewport
	m_camera.Init(QUARTERPI);
	m_viewport.InitFull(&m_camera);

	// Init scenes
	initScenes();
	changeScene(0); // initial scene
}

void CGame::Tick(float fTime, float fTimeDelta)
{
	// Root must tick first! (initializes game on first tick)
	m_root.Tick(fTimeDelta);

	if (m_activeScene)
	{
		m_activeScene->update(fTimeDelta);
		if (m_activeScene->getWASDCam()) m_keyboard.PlaceWASD(m_activeScene->getCameraPlacement(), fTimeDelta);
	}
	handleUserInput();

	// Prevent very high framerates, that can cause hardware damage
	// Comment out, if you have low FPS / reliable hardware
	// Can be removed, once Vektoria::CRoot::SetFrameRateMax() starts working properly
	Sleep(1u);
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

Vektoria::CRoot& CGame::getRoot()
{
	return m_root;
}

Vektoria::CCamera& CGame::getCamera()
{
	return m_camera;
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
	// Example scene
	addScene(new FallingCubeScene);

	// ADD NEW SCENES HERE
	// ...
	addScene(new CaveScene);
}

void CGame::addScene(SimulationScene* scene)
{
	scene->SwitchOff();
	m_root.AddScene(scene);
	m_scenes.push_back(scene);
}

void CGame::changeScene(int sceneIdx)
{
	assert(sceneIdx >= 0 && sceneIdx < m_scenes.size());
	m_activeSceneIndex = sceneIdx;
	changeScene(m_scenes[sceneIdx]);
}

void CGame::changeScene(SimulationScene* scene)
{
	if (m_activeScene)
	{
		m_activeScene->getCameraPlacement().SubCamera(&m_camera);
		m_activeScene->deactivate();
		m_activeScene->SwitchOff();
	}

	m_activeScene = scene;

	if (scene)
	{
		scene->getCameraPlacement().AddCamera(&m_camera);
		scene->activate();
		scene->SwitchOn();
	}
}

void CGame::handleUserInput()
{
	if (m_keyboard.KeyDown(DIK_1))
	{
		prevScene();
	}
	else if (m_keyboard.KeyDown(DIK_2))
	{
		nextScene();
	}

	if (m_keyboard.KeyDown(DIK_T))
	{
		m_activeScene->reset();
	}
}

void CGame::nextScene()
{
	const auto sceneCount = int(m_scenes.size());
	if (sceneCount <= 1) return;

	changeScene((m_activeSceneIndex + 1) % sceneCount);
}

void CGame::prevScene()
{
	const auto sceneCount = int(m_scenes.size());
	if (sceneCount <= 1) return;

	if (--m_activeSceneIndex < 0) m_activeSceneIndex = sceneCount - 1;
	changeScene(m_activeSceneIndex);
}
