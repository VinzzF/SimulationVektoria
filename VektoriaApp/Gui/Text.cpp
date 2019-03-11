#include "Text.h"
#include "Vektoria/WritingFont.h"
#include "Vektoria/Writing.h"

Text::Text()
{
	m_height = 0.5f;
	m_width = 1.0f;

	m_floatrect.Init(0.0f, 0.0f, m_width, m_height);
	m_writing.Init(m_rect, 0, nullptr);

	this->AddOverlay(&m_writing);
}

Text::~Text()
= default;

void Text::setFont(Vektoria::CWritingFont* font)
{
	m_font = font;
	m_writing.SetFont(m_font);
}

Vektoria::CWritingFont* Text::getFont() const
{
	return m_font;
}

void Text::setPosition(float x, float y)
{
	__super::setPosition(x, y);
	//m_floatrect.Init(x, y, 
	//				 m_floatrect.GetXSize(), m_floatrect.GetYSize());
	//m_writing.Init(m_floatrect, m_text.size(), m_font);
	m_writing.PrintString(const_cast<char*>(m_text.c_str()));
}

void Text::setSize(float sx, float sy)
{
	//__super::setSize(sx, sy);

	//m_floatrect.Init(0.0f, 0.0f, m_width, m_height);
	//m_writing.Init(m_floatrect, m_text.size(), m_font);
}

void Text::setCharacterHeight(const float height)
{
	m_height = height;
}

void Text::setCharacterWidth(const float width)
{
	m_width = width;
}

void Text::setText(const std::string& text)
{
	m_text = text;

	auto rect = m_floatrect;
	m_writing.Init(rect, m_text.size(), m_font);

	m_writing.PrintString(const_cast<char*>(m_text.c_str()));
}

const std::string& Text::getText() const
{
	return m_text;
}
