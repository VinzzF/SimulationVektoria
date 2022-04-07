#include "pch.h"
#include "CaveScene.h"

CaveScene::CaveScene(float fWidth /*= 8.0f*/, float fDepth /*= 6.0f*/, float fHeight /*= 5.0f*/, float fThickness /*= 0.1f*/)
	: m_fWidth(fWidth)
	, m_fDepth(fDepth)
	, m_fHeight(fHeight)
	, m_fThickness(fThickness)
{
	m_zpCamera.RotateX(UM_DEG2RAD(-20.0f));
	m_zpCamera.TranslateDelta(fWidth * 0.5f, 12.0f, 25.0f);

	// Boden
	m_zmSides[0].LoadPreset("EarthCracked");
	m_zgSides[0].Init(fWidth, fDepth, fThickness, &m_zmSides[0]);
	m_zpSides[0].RotateX(-HALFPI);

	// Seitenwand links
	m_zmSides[1].LoadPreset("Rock");
	m_zgSides[1].Init(fDepth, fHeight, fThickness, &m_zmSides[1]);
	m_zpSides[1].RotateY(HALFPI);

	// Seitenwand rechts
	m_zmSides[2].LoadPreset("Rock");
	m_zgSides[2].Init(fDepth, fHeight, fThickness, &m_zmSides[2]);
	m_zpSides[2].RotateY(HALFPI);
	m_zpSides[2].TranslateXDelta(fWidth);

	// Rückwand
	m_zmSides[3].LoadPreset("CobblestoneMarble");
	m_zgSides[3].Init(fWidth, fHeight, fThickness, &m_zmSides[3]);
	m_zpSides[3].TranslateZ(-fDepth);

	for (size_t i = 0u; i < 4u; ++i)
	{
		regMaterial(&m_zmSides[i]);
		m_zpSides[i].AddGeo(&m_zgSides[i]);
		this->AddPlacement(&m_zpSides[i]);
	}

	this->SetLightAmbient(0.8f);
}

CaveScene::~CaveScene() = default;
