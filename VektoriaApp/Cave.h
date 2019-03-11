#pragma once
#include "Vektoria/Placement.h"
#include "Vektoria/Geo.h"

#include <memory>


class Cave : public Vektoria::CPlacement
{
public:
	using Node_Ptr = std::unique_ptr<Vektoria::CPlacement>;
	
	explicit Cave(float length, 
				  float height, 
				  float depth,
				  Vektoria::CGeo* geoSides,
				  Vektoria::CGeo* geoBack,
				  Vektoria::CGeo* geoBot,
				  float wallWidth = 0.1f);
	~Cave();

	float getLength() const;
	float getHeight() const;
	float getDepth() const;
	float getWallWidth() const;

private:
	Node_Ptr m_left;
	Node_Ptr m_right;
	Node_Ptr m_back;
	Node_Ptr m_bot;

	float m_length;
	float m_height;
	float m_depth;
	float m_wallWidth;
};