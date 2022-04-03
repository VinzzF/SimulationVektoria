#include "pch.h"
#include "CaveScene.h"

CaveScene::CaveScene()
{
	m_zpCamera.RotateX(UM_DEG2RAD(-20.0f));
	m_zpCamera.TranslateDelta(0.0f, 12.0f, 35.0f);

	// Boden
	m_zmSides[0].LoadPreset("EarthCracked");
	m_zgSides[0].Init(4.0f, 6.0f, &m_zmSides[0]);
	m_zpSides[0].RotateX(-HALFPI);
	m_zpSides[0].TranslateYDelta(-5.0f);

	// Seitenwand links
	m_zmSides[1].LoadPreset("Rock");
	m_zgSides[1].Init(6.0f, 5.0f, &m_zmSides[1]);
	m_zpSides[1].RotateY(HALFPI);
	m_zpSides[1].TranslateXDelta(-4.0f);

	// Seitenwand rechts
	m_zmSides[2].LoadPreset("Rock");
	m_zgSides[2].Init(6.0f, 5.0f, &m_zmSides[2]);
	m_zpSides[2].RotateY(-HALFPI);
	m_zpSides[2].TranslateXDelta(4.0f);

	// Rückwand
	m_zmSides[3].LoadPreset("CobblestoneMarble");
	m_zgSides[3].Init(4.0f, 5.0f, &m_zmSides[3]);
	m_zpSides[3].TranslateZ(-6.0f);

	for (size_t i = 0u; i < 4u; ++i)
	{
		regMaterial(&m_zmSides[i]);
		m_zpSides[i].AddGeo(&m_zgSides[i]);
		this->AddPlacement(&m_zpSides[i]);
	}

	this->SetLightAmbient(0.8f);
}

CaveScene::~CaveScene() = default;
