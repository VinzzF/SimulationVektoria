#pragma once
#include "Gui/Widget.h"

#include <functional>

class Button : public Widget
{
public:
	using MouseClick_Callback = std::function<void(Button* button,
												   const Vektoria::CHVector& pos)>;
	using MouseMove_Callback = std::function<void(Button* button,
												  const Vektoria::CHVector& pos,
												  const Vektoria::CHVector& deltaPos)>;

	explicit Button();
	~Button();

	void setDownCallback(const MouseClick_Callback& callback);
	void setUpCallback(const MouseClick_Callback& callback);
	void setMouseMoveCallback(const MouseMove_Callback& callback);

	void onMouseDownImpl(const Vektoria::CHVector& pos) override;
	void onMouseUpImpl(const Vektoria::CHVector& pos) override;
	void onMouseMoveImpl(const Vektoria::CHVector& pos,
						 const Vektoria::CHVector& deltaPos) override;

private:
	MouseClick_Callback m_downCb;
	MouseClick_Callback m_upCb;
	MouseMove_Callback m_moveCb;
};