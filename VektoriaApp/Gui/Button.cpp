#include "Button.h"

Button::Button()
= default;

Button::~Button()
= default;

void Button::setDownCallback(const MouseClick_Callback& callback)
{
	m_downCb = callback;
}

void Button::setUpCallback(const MouseClick_Callback& callback)
{
	m_upCb = callback;
}

void Button::setMouseMoveCallback(const MouseMove_Callback& callback)
{
	m_moveCb = callback;
}

void Button::onMouseDownImpl(const Vektoria::CHVector& pos)
{
	if(m_downCb)
	{
		m_downCb(this, pos);
	}
}

void Button::onMouseUpImpl(const Vektoria::CHVector& pos)
{
	if(m_upCb)
	{
		m_upCb(this, pos);
	}
}

void Button::onMouseMoveImpl(const Vektoria::CHVector& pos, 
							 const Vektoria::CHVector& deltaPos)
{
	if(m_moveCb)
	{
		m_moveCb(this, pos, deltaPos);
	}
}
