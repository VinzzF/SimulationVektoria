#include "Screen.h"


Screen::Screen()
{
	this->m_floatrect.Init(0.0f, 0.0f, 1.0f, 1.0f);
	this->SetInnerOff();
}

Screen::~Screen()
= default;