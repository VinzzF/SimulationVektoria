#pragma once
#include "Vektoria/Node.h"

#include <memory>

namespace Vektoria
{
	class CViewport;
}

class Widget;
class Screen;

class Gui : public Vektoria::CNode
{
public:
	explicit Gui();
	virtual ~Gui();

	/** Call this method after all widgets have been added. */
	virtual void init(Vektoria::CViewport* viewport);

	Widget* getRoot() const;

private:
	Vektoria::CViewport* m_viewport;

	std::shared_ptr<Screen> m_root{};
};