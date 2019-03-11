#pragma once
#include "Widget.h"
#include "Vektoria/Writing.h"

#include <string>

namespace Vektoria
{
	class CWritingFont;
}

class Text : public Widget
{
public:
	explicit Text();
	~Text();

	/** Font access */
	void setFont(Vektoria::CWritingFont* font);
	Vektoria::CWritingFont* getFont() const;

	/** */
	void setPosition(float x, float y) override;
	void setSize(float sx, float sy) override;

	/** Character size access */
	void setCharacterHeight(float height);
	void setCharacterWidth(float width);

	/** Text access */
	void setText(const std::string& text);
	const std::string& getText() const;

private:
	Vektoria::CWritingFont* m_font{};
	
	Vektoria::CFloatRect m_rect;
	Vektoria::CWriting m_writing;

	float m_height;
	float m_width;

	std::string m_text;
};