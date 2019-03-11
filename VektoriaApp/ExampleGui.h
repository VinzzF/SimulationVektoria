#pragma once
#include "Gui/Gui.h"
#include "Gui/Button.h"
#include "Gui/Screen.h"
#include "Gui/Text.h"

#include "Vektoria/WritingFont.h"



class ExampleGui : public Gui
{
public:
	explicit ExampleGui();
	~ExampleGui();

	void init(Vektoria::CViewport* viewport) override;

private:
	void initGuiElements();

private:
	Button* m_button{};
	Text* m_text{};

	std::string m_fontPath;
	Vektoria::CWritingFont* m_writingFont{};
};