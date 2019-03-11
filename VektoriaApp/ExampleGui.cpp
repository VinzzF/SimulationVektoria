#include "ExampleGui.h"

ExampleGui::ExampleGui()
{
	initGuiElements();
}

ExampleGui::~ExampleGui()
= default;

void ExampleGui::init(Vektoria::CViewport* viewport)
{
	initGuiElements();

	__super::init(viewport);
}

void ExampleGui::initGuiElements()
{
	m_fontPath = "";

	auto root = getRoot();

	m_writingFont = new Vektoria::CWritingFont();
	m_writingFont->LoadPreset("CreatorWhite");
	
	m_button = new Button();
	m_button->setPosition(0.0f, 0.0f);
	m_button->setSize(0.5f, 0.5f);
	//root->addChild(m_button);

	m_text = new Text();
	m_text->setFont(m_writingFont);
	m_text->setPosition(0.5f, 0.0f);
	m_text->setSize(0.25f, 0.25f);
	m_text->setText("GuiText");
	root->addChild(m_text);
}
