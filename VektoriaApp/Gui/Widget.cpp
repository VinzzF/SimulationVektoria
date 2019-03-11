#include "Widget.h"
#include "Screen.h"

#include "Vektoria/Viewport.h"

#include <algorithm>


Widget::~Widget()
{
	for(auto& it : m_children)
	{
		this->SubOverlay(it);
	}
	this->SetInnerOn();
}

void Widget::addChild(Widget* widget)
{
	widget->setParent(this);
	m_children.emplace_back(widget);
	this->AddOverlay(widget);
}

bool Widget::removeChild(Widget* widget)
{
	const auto removedEntry = std::remove(m_children.begin(),
	                                      m_children.end(),
	                                      widget);

	if(removedEntry != m_children.end())
	{
		this->SubOverlay(*removedEntry);
		(*removedEntry)->setParent(nullptr);
		return true;
	}

	return false;
}

void Widget::removeChildren()
{
	for (const auto& it : m_children)
	{
		this->SubOverlay(it);
		it->setParent(nullptr);
	}
	m_children.clear();
}

Widget* Widget::getParent() const
{
	return m_parent;
}

void Widget::setPosition(const float x, const float y)
{
	this->m_floatrect.SetXPos(x);
	this->m_floatrect.SetYPos(y);
}

void Widget::setSize(const float sx, const float sy)
{
	this->m_floatrect.SetXSize(sx);
	this->m_floatrect.SetYSize(sy);
}

Screen* Widget::getScreen()
{
	Widget* widget = this;
	while(widget->getParent() != nullptr)
	{
		widget = widget->getParent();
	}
	return dynamic_cast<Screen*>(widget);
}

void Widget::setParent(Widget* widget)
{
	m_parent = widget;
}

bool Widget::onMouseDown(const Vektoria::CHVector& pos)
{
	if(intersect(pos))
	{
		bool childIntersection = false;
		for(auto& it : m_children)
		{
			if(it->onMouseDown(pos))
			{
				childIntersection = true;
				break;
			}
		}

		if(!childIntersection)
		{
			onMouseDownImpl(pos);
		}

		return true;
	}
	return false;
}

bool Widget::onMouseUp(const Vektoria::CHVector& pos)
{
	if(intersect(pos))
	{
		bool childIntersection = false;
		for(auto& it : m_children)
		{
			if(it->onMouseUp(pos))
			{
				childIntersection = true;
				break;
			}
		}

		if(!childIntersection)
		{
			onMouseUpImpl(pos);
		}

		return true;
	}
	return false;
}

bool Widget::onMouseMove(const Vektoria::CHVector& pos, const Vektoria::CHVector& deltaPos)
{
	if(intersect(pos))
	{
		bool childIntersection = false;
		for(auto& it : m_children)
		{
			if(it->onMouseMove(pos, deltaPos))
			{
				childIntersection = true;
				break;
			}
		}

		if(!childIntersection)
		{
			onMouseMoveImpl(pos, deltaPos);
		}

		return true;
	}
	return false;
}

void Widget::onMouseDownImpl(const Vektoria::CHVector& pos)
{
}

void Widget::onMouseUpImpl(const Vektoria::CHVector& pos)
{
}

void Widget::onMouseMoveImpl(const Vektoria::CHVector& pos, 
							 const Vektoria::CHVector& deltaPos)
{
}

bool Widget::intersect(const Vektoria::CHVector& pos)
{
	return pos.x < m_floatrect.m_fxPos + m_floatrect.m_fxSize && pos.x >= 0 &&
		pos.y < m_floatrect.m_fyPos + m_floatrect.m_fySize && pos.y >= 0;
}

Widget::Widget()
= default;
