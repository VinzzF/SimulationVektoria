#pragma once


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#endif
#endif

#include "Examples/FallingCubeScene.h"

#include "Vektoria\Root.h"

class CGame
{
public:
	CGame(void);
	~CGame(void);

	// Wird zu Begin einmal aufgerufen
	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), Vektoria::CSplash * psplash);
	// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen
	void Tick(float fTime, float fTimeDelta);
	// Wird am Ende einmal aufgerufen
	void Fini();

	// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat
	void WindowReSize(int iNewWidth, int iNewHeight);

	/** Get the keyboard */
	Vektoria::CDeviceKeyboard& getKeyboard();
	/** Get the mouse */
	Vektoria::CDeviceMouse& getMouse();

private:
	void initScenes();
	void changeScene(SimulationScene* scene);

	// Vektoria base
	Vektoria::CRoot m_root;
	Vektoria::CScene m_defaultScene;
	Vektoria::CPlacement m_cameraPlacement;
	Vektoria::CPlacement m_spherePlacement;
	
	Vektoria::CFrame m_frame;
	Vektoria::CViewport m_viewport;
	Vektoria::CCamera m_camera;
	Vektoria::CLightParallel m_lightParallel;

	/* Geometries */
	Vektoria::CGeoSphere m_sphereGeo;
	Vektoria::CGeoCube m_cubeGeo;

	/* Material */
	Vektoria::CMaterial m_sphereMat;
	Vektoria::CMaterial m_cubeMat;

	/* Input */
	Vektoria::CDeviceKeyboard m_keyboard;
	Vektoria::CDeviceMouse m_mouse;

	/* Scenes */
	SimulationScene* m_activeScene;

	FallingCubeScene* m_fallingCubeScene;

	void prepareScene(SimulationScene* scene);

	/** Handle user input for scene changing. */
	void handleSceneChange();

	/** Change the active scene to the next one. */
	void nextScene();
	/** Change the active scene to the previous one. */
	void prevScene();

	std::vector<SimulationScene*> m_scenes;
	int m_activeSceneIndex{};
};


