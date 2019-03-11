#pragma once
#include "Vektoria/Overlay.h"

#include <vector>

namespace Vektoria
{
	class CViewport;
}

class Screen;

class Widget : public Vektoria::COverlay
{
public:
	virtual ~Widget();

	virtual void addChild(Widget* widget);
	virtual bool removeChild(Widget* widget);
	virtual void removeChildren();

	Widget* getParent() const;

	virtual void setPosition(float x, float y);
	virtual void setSize(float sx, float sy);

	bool onMouseDown(const Vektoria::CHVector& pos);
	bool onMouseUp(const Vektoria::CHVector& pos);
	bool onMouseMove(const Vektoria::CHVector& pos,
					 const Vektoria::CHVector& deltaPos);

	virtual void onMouseDownImpl(const Vektoria::CHVector& pos);
	virtual void onMouseUpImpl(const Vektoria::CHVector& pos);
	virtual void onMouseMoveImpl(const Vektoria::CHVector& pos,
								 const Vektoria::CHVector& deltaPos);

	virtual bool intersect(const Vektoria::CHVector& pos);

protected:
	explicit Widget();

	Widget* m_parent{};
	std::vector<Widget*> m_children;

private:
	Screen* getScreen();

	void setParent(Widget* widget);
};

