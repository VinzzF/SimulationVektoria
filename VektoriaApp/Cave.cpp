#include "Cave.h"
#include "Vektoria/Geo.h"

Cave::Cave(float length, 
		   float height,
		   float depth, 
		   Vektoria::CGeo* geoSides, 
		   Vektoria::CGeo* geoBack,
		   Vektoria::CGeo* geoBot, 
		   float wallWidth)
	: m_length(length),
	m_height(height),
	m_depth(depth),
	m_wallWidth(wallWidth)
{
	//// Allocate memory for nodes
	//m_left = std::make_unique<Node>();
	//m_right = std::make_unique<Node>();
	//m_back = std::make_unique<Node>();
	//m_bot = std::make_unique<Node>();

	//// Add drawables to nodes
	//m_left->addDrawable(drawableSides);
	//m_right->addDrawable(drawableSides);
	//m_back->addDrawable(drawableBack);
	//m_bot->addDrawable(drawableBot);

	//// Scale nodes and move them into position
	//const auto lengthHalf = 0.5f * length;
	//const auto heightHalf = 0.5f * height;
	//const auto depthHalf = 0.5f * depth;
	//const auto wallWidthHalf = 0.5f * wallWidth;

	//const auto x = lengthHalf + wallWidthHalf;
	//const auto y = heightHalf + wallWidthHalf;
	//const auto z = depthHalf + wallWidthHalf;

	//m_left->setScale(wallWidth, height, depth);
	//m_right->setScale(wallWidth, height, depth);
	//m_bot->setScale(length, wallWidth, depth);
	//m_back->setScale(length, height, wallWidth);

	//m_left->translateX(-x);
	//m_right->translateX(x);
	//m_bot->translateY(-y);
	//m_back->translateZ(-z);

	//// Add nodes as childs to this one
	//this->addChild(m_left.get());
	//this->addChild(m_right.get());
	//this->addChild(m_bot.get());
	//this->addChild(m_back.get());
}

Cave::~Cave()
= default;

float Cave::getLength() const
{
	return m_length;
}

float Cave::getHeight() const
{
	return m_height;
}

float Cave::getDepth() const
{
	return m_depth;
}

float Cave::getWallWidth() const
{
	return m_wallWidth;
}
