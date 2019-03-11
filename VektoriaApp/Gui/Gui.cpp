#include "Gui.h"

#include "Vektoria/Viewport.h"
#include "Screen.h"

Gui::Gui()
{
	m_root = std::make_shared<Screen>();
}

Gui::~Gui()
= default;

void Gui::init(Vektoria::CViewport* viewport)
{
	if(!viewport || m_viewport == viewport)
	{
		return;
	}

	m_viewport = viewport;
	viewport->AddOverlay(m_root.get());
}

Widget* Gui::getRoot() const
{
	return m_root.get();
}
