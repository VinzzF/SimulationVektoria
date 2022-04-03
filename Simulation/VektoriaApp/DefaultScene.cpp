#include "pch.h"
#include "DefaultScene.h"

DefaultScene::DefaultScene()
{
	m_zl.Init(Vektoria::CHVector(1.0f, 1.0f, 1.0f), Vektoria::CColor(1.0f, 1.0f, 1.0f));
	this->AddLightParallel(&m_zl);
}

DefaultScene::~DefaultScene()
{

}
