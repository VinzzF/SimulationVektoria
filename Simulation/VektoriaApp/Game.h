#pragma once

class SimulationScene;
class CGame
{
// singleton
private:
	CGame();
public:
	CGame(const CGame&) = delete;
	CGame(CGame&&) = delete;
	~CGame();
	CGame& operator=(const CGame&) = delete;
	CGame& operator=(CGame&&) = delete;
	static CGame& GetInstance();

public:
	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), Vektoria::CSplash* psplash);
	void Tick(float fTime, float fTimeDelta);
	void Fini();

	void WindowReSize(int iNewWidth, int iNewHeight);

	/** Get the root node */
	Vektoria::CRoot& getRoot();
	/** Get the camera */
	Vektoria::CCamera& getCamera();
	/** Get the keyboard */
	Vektoria::CDeviceKeyboard& getKeyboard();
	/** Get the mouse */
	Vektoria::CDeviceMouse& getMouse();

private:
	void initScenes();
	void addScene(SimulationScene* scene);
	void changeScene(int sceneIdx);
	void changeScene(SimulationScene* scene);

	/** Handle user input for scene changing. */
	void handleUserInput();

	/** Change the active scene to the next one. */
	void nextScene();
	/** Change the active scene to the previous one. */
	void prevScene();

private:
    // Hier ist Platz für Deine Vektoriaobjekte:
	Vektoria::CRoot m_root;
	Vektoria::CFrame m_frame;
	Vektoria::CCamera m_camera;
	Vektoria::CViewport m_viewport;
	Vektoria::CBackground m_background;

	/* Input */
	Vektoria::CDeviceKeyboard m_keyboard;
	Vektoria::CDeviceMouse m_mouse;

	/* Scenes */
	SimulationScene* m_activeScene;
	std::vector<SimulationScene*> m_scenes;
	int m_activeSceneIndex;
};


